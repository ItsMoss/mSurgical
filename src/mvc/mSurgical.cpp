#include "mSurgical.h"

mSurgical::mSurgical(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QFile stylesheet("mStyle.qss");
	stylesheet.open(QFile::ReadOnly);
	QString sheet2set = QLatin1String(stylesheet.readAll());
	this->setStyleSheet(sheet2set);
	// image setup
	ui.nextPatient->setPixmap(QPixmap(":/mSurgical/Resources/patient.png"));
	ui.tablePatient->setPixmap(QPixmap(":/mSurgical/Resources/patient.png"));
	ui.monaLaser->setPixmap(QPixmap(":/mSurgical/Resources/monalaser.png"));

	// start logging
	INFO("Log file for mSurgical v1\n");

	// create meta folder (if does not exist)
	if (!QDir(MSURGICAL_DIRECTORY).exists()) {
		QDir().mkdir(MSURGICAL_DIRECTORY);
	}
	movePythonFile();

	// setup all signal-slot connections for changing screen
	mapper = std::make_unique<QSignalMapper>();
	connect(ui.startBackButton, SIGNAL(clicked()), mapper.get(), SLOT(map()));
	mapper->setMapping(ui.startBackButton, (int)mScreen::Menu);
	connect(ui.goToORButton, SIGNAL(clicked()), mapper.get(), SLOT(map()));
	mapper->setMapping(ui.goToORButton, (int)mScreen::OR);
	connect(ui.learnButton, SIGNAL(clicked()), mapper.get(), SLOT(map()));
	mapper->setMapping(ui.learnButton, (int)mScreen::Learn);
	connect(ui.hiscoresButton, SIGNAL(clicked()), mapper.get(), SLOT(map()));
	mapper->setMapping(ui.hiscoresButton, (int)mScreen::HiScore);
	connect(ui.changeSurgeonButton, SIGNAL(clicked()), mapper.get(), SLOT(map()));
	mapper->setMapping(ui.changeSurgeonButton, (int)mScreen::Login);
	connect(mapper.get(), SIGNAL(mapped(int)), this, SLOT(changeDisplayedScreen(int)));

	// setup all signal-slot connections for learning new surgery
	connect(ui.surgeryPushButton1, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton2, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton3, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton4, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton5, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton6, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton7, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton8, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton9, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton10, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton11, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton12, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton13, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton14, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton15, SIGNAL(clicked()), this, SLOT(learnSurgery()));
	connect(ui.surgeryPushButton16, SIGNAL(clicked()), this, SLOT(learnSurgery()));

	// setup learn method option
	connect(ui.actionLearn_Method, SIGNAL(triggered()), this, SLOT(toggleLearnMethod()));

	// init db and gameplay related variables
	dbAvailable = initDB();
	operating = false;
	basePointsAwarded = 0;
	learnViaPython = false;
	initSurgeryList();
	testing = false;

	// init maps
	ijklOn = true;
	INFO("Using I, J, K, L for tools");
	button2ToolMap[Qt::Key_I] = 1;
	button2ToolMap[Qt::Key_J] = 0;
	button2ToolMap[Qt::Key_K] = 3;
	button2ToolMap[Qt::Key_L] = 2;

	tool2ButtonMap[0] = "J";
	tool2ButtonMap[1] = "I";
	tool2ButtonMap[2] = "L";
	tool2ButtonMap[3] = "K";
	
	connect(ui.actionButtons, SIGNAL(triggered()), this, SLOT(reinitButtonToolMaps()));

	// do not show start label until login complete
	ui.pressStartLabel->hide();

	// setup timer for login pop up to display after app displays
	t1 = std::make_unique<QTimer>();
	t1->setSingleShot(true);
	t1->setInterval(1000);
	connect(t1.get(), SIGNAL(timeout()), ui.changeSurgeonButton, SIGNAL(clicked()));
	t1->start();
	DEBUG("Construction :)");
}

mSurgical::~mSurgical() {
	DEBUG("Destruction :(");
	db.reset();
	mapper.reset();
	while (!patients.empty()) {
		patients.pop();
	}
	surgeon.reset();
	t1.reset();
	t2.reset();
	t3.reset();
}

void mSurgical::awardPoints(int points2add) {
	if (operating) {
		surgeon->setCurrentScore(surgeon->getCurrentScore() + points2add);
		// look to update high score
		if (surgeon->getHighScore() < surgeon->getCurrentScore()) {
			surgeon->setHighScore(surgeon->getCurrentScore());
		}
		// update UI
		ui.scoreBox->setValue(surgeon->getCurrentScore());

		logString = "Surgeon scored ";
		logString += std::to_string(points2add).c_str();
		logString += " points";
		INFO(logString);
	}
	else {
		ERROR("Tried to award points while NOT operating");
	}
	
	if (testing) {
		runAssertions();
	}
}

bool mSurgical::displayMessage(const QString & msg) {
	QMessageBox msgBox;
	msgBox.setText(msg);
	return msgBox.exec();
}

void mSurgical::generateRandomSurgery(Surgery & s) {
	srand(time(0));
	// generate
	QString name = surgeryList[rand() % surgeryList.size()];
	tool_id t1 = rand() % MAX_NUM_TOOLS;
	tool_id t2 = rand() % MAX_NUM_TOOLS;

	// set
	s.setName(name);
	std::vector<tool_id> tools(1, t1);
	tools.push_back(t2);
	s.setSequence(tools);

	if (testing) {
		runAssertions();
	}
}

void mSurgical::getSurgeryFromFile(Surgery & s) {
	std::vector<int> buttons;	// corresponding button seq for surgery
	QFile f;
	QDirIterator dirIt(MSURGICAL_DIRECTORY);
	while (dirIt.hasNext()) {
		dirIt.next();
		if (dirIt.fileName().endsWith(".surgery")) {
			f.setFileName(dirIt.filePath());
			if (f.open(QIODevice::ReadOnly)) {
				QString line;
				while (!f.atEnd()) {
					line = f.readLine();
					line.remove("\n");
					bool ok;
					int button = line.toInt(&ok);
					if (ok && buttons.size() < MAX_NUM_BUTTONS) {
						buttons.push_back(button);
					}
				}
				f.close();
				QString surgeryname(dirIt.fileName());
				surgeryname.remove(".surgery");
				s.setName(surgeryname);
				s.setSequence(buttons);

				if (testing) {
					runAssertions();
				}

				return;
			}
		}
	}
}

void mSurgical::getLoginInfo() {
	QDialog loginBox;
	loginBox.setWindowTitle("Surgeon Login");

	QLabel instructions("Enter Your Name:");
	QLabel firstName("First Name:");
	QLineEdit firstNameEdit;
	QLabel lastName("Last Name:");
	QLineEdit lastNameEdit;

	QPushButton doneButton("Done");
	connect(&doneButton, SIGNAL(clicked()), &loginBox, SLOT(close()));

	QGridLayout glayout;
	glayout.addWidget(&instructions, 0, 0, 1, 4, Qt::AlignHCenter);
	glayout.addWidget(&firstName, 1, 0);
	glayout.addWidget(&firstNameEdit, 1, 1);
	glayout.addWidget(&lastName, 1, 2);
	glayout.addWidget(&lastNameEdit, 1, 3);
	glayout.addWidget(&doneButton, 2, 0, 1, 4, Qt::AlignHCenter);
	loginBox.setLayout(&glayout);

	loginBox.exec();

	// ensure that first and last name were entered
	if (firstNameEdit.text().isEmpty() || lastNameEdit.text().isEmpty()) {
		displayMessage("YOU MUST ENTER A FIRST AND LAST NAME!");
		if (testing) {
			runAssertions();
		}
		return getLoginInfo();
	}
	else {
		initSurgeon(firstNameEdit.text(), lastNameEdit.text());
		ui.pressStartLabel->show();
	}

	if (testing) {
		runAssertions();
	}
}

bool mSurgical::initDB() {
	INFO("Initializing database");

	db = std::make_unique<QSqlDatabase>(QSqlDatabase::addDatabase("QSQLITE"));

	// Check that db is valid o/w use whatever driver(s) are available
	if (!db->isValid()) {
		QStringList driversList = db->drivers();
		for (auto d : driversList) {
			if (d == "QOCI" || d == "QODBC") {
				// do not want to use Oracle drivers b/c they require specific db name
				continue;
			}
			db = std::make_unique<QSqlDatabase>(QSqlDatabase::addDatabase(d));
			if (db->isValid()) {
				break;
			}
		}
		if (!db->isValid()) {
			WARN("unable to find suitable driver to establish db connection");
			displayMessage("Unable to establish database connection due to no suitable drivers");
			return false;
		}
	}
	logString = "Using db driver: ";
	logString += db->driverName();
	DEBUG(logString);

	// connect
	db->setHostName("localhost");		// does not matter for sqlite
	QString dbName(MSURGICAL_DIRECTORY);
	dbName += DATABASE_FILE_NAME;
	db->setDatabaseName(dbName);
	if (db->open()) {
		DEBUG("Successfully connected to database");
	}
	else {
		// WARN("Unable to open database");
		displayMessage("Unable to open database");
		return false;
	}

	// create tables if they do not exist
	// 1. surgery table
	if (db->record("SURGERY").isEmpty()) {
		QSqlQuery query;
		query.exec("CREATE TABLE SURGERY (\
					ID			INTEGER	PRIMARY KEY		AUTOINCREMENT, \
					NAME		TEXT	NOT NULL, \
					BUTTON1		INTEGER	NOT NULL, \
					BUTTON2		INTEGER	NOT NULL, \
					UNIQUE(NAME, BUTTON1, BUTTON2) \
					);");
		if (!query.isActive()) {
			errorString = "Unable to create db table SURGERY due to: ";
			errorString += query.lastError().text();
			ERROR(errorString);
			return false;
		}
		INFO("Created db table SURGERY");
	}
	else {
		INFO("db table SURGERY already exists");
	}
	// 2. surgeon table
	if (db->record("SURGEON").isEmpty()) {
		QSqlQuery query;
		query.exec("CREATE TABLE SURGEON (\
					ID			INTEGER	PRIMARY KEY		AUTOINCREMENT, \
					FIRSTNAME	TEXT	NOT NULL, \
					LASTNAME	TEXT	NOT NULL, \
					SURGERY_ID	INTEGER	NOT NULL, \
					FOREIGN KEY (SURGERY_ID) REFERENCES SURGERY(ID) ON DELETE CASCADE, \
					UNIQUE(FIRSTNAME, LASTNAME, SURGERY_ID) \
					);");
		if (!query.isActive()) {
			errorString = "Unable to create db table SURGEON due to: ";
			errorString += query.lastError().text();
			ERROR(errorString);			return false;
		}
		INFO("Created db table SURGEON");
	}
	else {
		INFO("db table SURGEON already exists");
	}
	// 3. player scores table
	if (db->record("SCORES").isEmpty()) {
		QSqlQuery query;
		query.exec("CREATE TABLE SCORES (\
					ID			INTEGER	PRIMARY KEY		AUTOINCREMENT, \
					SURGEON_ID	INTEGER	NOT NULL, \
					SCORE		INTEGER	NOT NULL, \
					FOREIGN KEY (SURGEON_ID) REFERENCES SURGEON(ID) ON DELETE CASCADE, \
					UNIQUE(SURGEON_ID, SCORE) \
					);");
		if (!query.isActive()) {
			errorString = "Unable to create db table SCORES due to: ";
			errorString += query.lastError().text();
			ERROR(errorString);
			return false;
		}
		INFO("Created db table SCORES");
	}
	else {
		INFO("db table SCORES already exists");
	}

	DEBUG("Successful db initialization!");
	return true;
}

void mSurgical::initPatients() {
	// populate queue
	int nSurgeries = surgeon->getKnownSurgeries().size();
	srand(time(0));
	int surgeryID = rand() % nSurgeries;
	std::shared_ptr<Patient> p0(new Patient(surgeryID));
	patients.push(p0);
	surgeryID = rand() % nSurgeries;
	std::shared_ptr<Patient> p1(new Patient(surgeryID));
	patients.push(p1);

	// update UI
	ui.tableSurgeryNeededEdit->setText(surgeon->getKnownSurgery(patients.front()->getSurgeryNeeded()).getName());
	ui.nextSurgeryNeededEdit->setText(surgeon->getKnownSurgery(patients.back()->getSurgeryNeeded()).getName());

	if (testing) {
		runAssertions();
	}
}

void mSurgical::initSurgeon(QString fName, QString lName) {
	surgeon = std::make_unique<Surgeon>(fName, lName);

	// fetch db for any known surgeries for this surgeon
	if (dbAvailable) {
		QSqlQuery query;
		QString selectSurgeries("SELECT NAME, BUTTON1, BUTTON2 FROM SURGERY WHERE ID IN (SELECT SURGERY_ID FROM SURGEON WHERE FIRSTNAME = '");
		selectSurgeries += fName + "' AND LASTNAME = '" + lName + "');";

		query.exec(selectSurgeries);
		if (query.isActive() && query.isSelect()) {
			QString currSurgery;
			while (query.next()) {
				Surgery knownSurgery;
				std::vector<int> seq;
				bool ok;
				currSurgery = query.value(0).toString();
				seq.push_back(query.value(1).toInt(&ok));
				if (ok) {
					seq.push_back(query.value(2).toInt(&ok));
				}
				if (!ok) {
					errorString = "Unable to retrieve known surgery: " + currSurgery;
					ERROR(errorString);
				}
				else {
					knownSurgery.setName(currSurgery);
					knownSurgery.setSequence(seq);
					surgeon->addSurgery(knownSurgery);
					logString = "Added known surgery: ";
					logString += currSurgery + seq[0] + seq[1];
					INFO(logString);
				}
			}
		}
		else {
			errorString = "query [";
			errorString += selectSurgeries + "] failed due to: " + query.lastError().text();
			ERROR(errorString);
			return;
		}
	}

	logString = "Successfully initialized surgeon: ";
	logString += fName + lName;
	INFO(logString);

	if (testing) {
		runAssertions();
	}
}

void mSurgical::initSurgeryList() {
	surgeryList = { "Ablation",
					"Angioplasty",
					"Appendectomy",
					"Bone repair",
					"Breast biopsy",
					"Bronchoscopy",
					"Carotid endarterectomy",
					"Carpal tunnel release",
					"Cataract surgery",
					"C section",
					"Cholecystectomy",
					"Colonoscopy",
					"Coronary artery bypass",
					"Debridement",
					"D&C",
					"Endoscopy of intestines",
					"ERCP",
					"Feducia marking",
					"Free skin graft",
					"Heart Valve Removal",
					"Hemorrhoidectomy",
					"Hip replacement",
					"Hysterectomy",
					"Hysteroscopy",
					"Inguinal hernia repair",
					"Knee replacement",
					"Liposuction",
					"Low back pain surgery",
					"Lumbar puncture",
					"Mastectomy",
					"Partial colectomy",
					"Polysomnogram",
					"Prostatectomy",
					"Rhinoplasty",
					"Shoulder replacement",
					"Small bowel resection",
					"Soft tissue repair",
					"Spinal fusion",
					"Thoracentesis",
					"Tonsillectomy" };
	
	INFO("Initialized surgery list");
}

bool mSurgical::isMonaLaserCorrect() {
	if (testing) {
		runAssertions();
	}
	DEBUG("Checking Mona Laser button sequence...");
	// getting correct operation (i.e. button sequence) for patient on table
	auto operation = surgeon->getKnownSurgery(patients.front()->getSurgeryNeeded()).getSequence();
	if (monaLaser.front() == operation.front() && monaLaser.back() == operation.back()) {
		INFO("Correct operation performed!");
		return true;
	}
	else {
		INFO("Failed operation attempted");
		return false;
	}
}

void mSurgical::movePythonFile() {
	if (QFile("generateSurgery.py").exists() && !QFile("./surgicalfiles/generateSurgery.py").exists()) {
		QFile f("generateSurgery.py");
		QString newRelativePath(MSURGICAL_DIRECTORY);
		newRelativePath += "generateSurgery.py";
		if (f.rename(newRelativePath)) {
			DEBUG("Successfully moved generateSurgery.py file");
		}
		else {
			errorString = "Failed to move generateSurgery.py file";
			ERROR(errorString);
			displayMessage("Was unable to move generateSurgery.py. You should do that now manually if "
						   "you plan to use Python to learn new surgeries!");
		}
	}
}

void mSurgical::populateBestDoctors() {
	// fetch db for highest scores
	if (dbAvailable) {
		QSqlQuery query;
		// get top 3 scores first
		std::vector<std::pair<QString, QString> > top3;		// surgeon id and score for top 3
		QString selectScores("SELECT SURGEON_ID, SCORE FROM SCORES ORDER BY SCORE DESC;");

		query.exec(selectScores);
		if (query.isActive() && query.isSelect()) {
			int numIDs = 0;		// counter for scores (no more than 3)
			while (query.next() && numIDs < 3) {
				top3.push_back(std::make_pair<QString, QString>(query.value(0).toString(), query.value(1).toString()));
				++numIDs;
			}
		}
		else {
			errorString = "query [";
			errorString += selectScores + "] failed due to: " + query.lastError().text();
			ERROR(errorString);
			return;
		}
		query.clear();

		// get names for top 3
		QLineEdit* top3names[3] = { ui.firstNameLineEdit, ui.secondNameLineEdit, ui.thirdNameLineEdit };
		QLineEdit* top3scores[3] = { ui.firstScoreLineEdit, ui.secondScoreLineEdit, ui.thirdScoreLineEdit };
		QString selectNames("SELECT FIRSTNAME, LASTNAME FROM SURGEON WHERE ID = ");
		QString selectNamesWithID;

		int nplayer = 0;
		for (auto & player : top3) {
			selectNamesWithID = selectNames + player.first + ";";
			query.exec(selectNamesWithID);
			if (query.isActive() && query.isSelect()) {
				if (query.next()) {
					// populate a top 3 entry
					top3names[nplayer]->setText(query.value(0).toString() + " " + query.value(1).toString());
					top3scores[nplayer]->setText(player.second);
				}
			}
			else {
				errorString = "query [";
				errorString += selectNamesWithID + "] failed due to: " + query.lastError().text();
				ERROR(errorString);
				return;
			}
			query.clear();
			++nplayer;
		}
	}
	else {
		// just display current surgeon's score (if non-zero) if no db available
		ui.firstNameLineEdit->setText(surgeon->getFirstName() + " " + surgeon->getLastName());
		ui.firstScoreLineEdit->setText(std::to_string(surgeon->getCurrentScore()).c_str());
	}

	if (testing) {
		runAssertions();
	}
}

void mSurgical::populateKnownSurgeries() {
	static QPushButton* surgeries[MAX_NUM_SURGERIES] = { ui.surgeryPushButton1,
										ui.surgeryPushButton2,
										ui.surgeryPushButton3,
										ui.surgeryPushButton4,
										ui.surgeryPushButton5,
										ui.surgeryPushButton6,
										ui.surgeryPushButton7,
										ui.surgeryPushButton8,
										ui.surgeryPushButton9,
										ui.surgeryPushButton10,
										ui.surgeryPushButton11,
										ui.surgeryPushButton12,
										ui.surgeryPushButton13,
										ui.surgeryPushButton14,
										ui.surgeryPushButton15,
										ui.surgeryPushButton16 };

	int nKnown = surgeon->getKnownSurgeries().size();
	for (int s = 0; s < nKnown; ++s) {
		surgeries[s]->setText(surgeon->getKnownSurgery(s).getName());
	}
	for (int s = nKnown; s < MAX_NUM_SURGERIES; ++s) {
		surgeries[s]->setText("?");
	}

	if (testing) {
		runAssertions();
	}
}

bool mSurgical::removeSurgeryFiles() {
	QDirIterator dirIt(MSURGICAL_DIRECTORY);
	bool success = true;
	while (dirIt.hasNext()) {
		dirIt.next();
		if (dirIt.fileName().endsWith(".surgery")) {
			QFile f(dirIt.filePath());
			if (f.remove()) {
				logString = "Removed surgery file: ";
				logString += f.fileName();
				INFO(logString);
			}
			else {
				errorString = "Unable to remove surgery file: ";
				errorString += f.fileName();
				WARN(errorString);
				success = false;
			}
		}
	}

	if (testing) {
		runAssertions();
	}

	return success;
}

void mSurgical::resetTimers() {
	// 10 second timer that ends game
	t1.reset(new QTimer);
	t1->setInterval(10500);		// extra 500 microseconds allows for user to see second button (corresponds to sleep in keyPressEvent)
	t1->setSingleShot(false);
	connect(t1.get(), SIGNAL(timeout()), this, SLOT(endGame()));
	// 1 second timer that updates progressBar
	t2.reset(new QTimer);
	t2->setInterval(1000);
	t2->setSingleShot(false);
	connect(t2.get(), SIGNAL(timeout()), this, SLOT(decrementProgressBar()));
	// make sure progressBar is at 10 seconds
	ui.tableProgressBar->setValue(10);

	t1->start();
	t2->start();

	if (testing) {
		runAssertions();
	}
}

void mSurgical::runAssertions() {
	DEBUG("Running assertions:");
	assert(errorString.isEmpty());
	if (surgeon.get()) {
		assert(surgeon->getHighScore() >= surgeon->getCurrentScore());
		assert(surgeon->getCurrentScore() >= 0);
		assert(!surgeon->getFirstName().isEmpty());
		assert(!surgeon->getLastName().isEmpty());
		assert(surgeon->getKnownSurgeries().size() >= 0);
		assert(surgeon->getKnownSurgeries().size() <= MAX_NUM_SURGERIES);
		for (auto & s : surgeon->getKnownSurgeries()) {
			assert(!s.getName().isEmpty());
			assert(s.getSequence().size() == MAX_NUM_BUTTONS);
			for (auto & b : s.getSequence()) {
				assert(b >= 0);
				assert(b < MAX_NUM_TOOLS);
			}
		}
		if (operating) {
			assert(ui.scoreBox->value() == surgeon->getCurrentScore());
			assert(monaLaser.size() >= 0);
			assert(monaLaser.size() <= 2);
			assert(patients.size() == 2);
			assert(basePointsAwarded == surgeon->getKnownSurgeries().size());
		}
		else {
			assert(ui.scoreBox->value() == 0);
			assert(monaLaser.size() == 0);
			assert(patients.size() == 0);
		}
		assert(tool2ButtonMap.size() == MAX_NUM_TOOLS);
		assert(button2ToolMap.size() == MAX_NUM_TOOLS);
		if (ijklOn) {
			assert(button2ToolMap.find(Qt::Key_I) != button2ToolMap.end());
			assert(button2ToolMap.find(Qt::Key_J) != button2ToolMap.end());
			assert(button2ToolMap.find(Qt::Key_K) != button2ToolMap.end());
			assert(button2ToolMap.find(Qt::Key_L) != button2ToolMap.end());
			assert(tool2ButtonMap[0] == "J");
			assert(tool2ButtonMap[1] == "I");
			assert(tool2ButtonMap[2] == "L");
			assert(tool2ButtonMap[3] == "K");
		}
		else {
			assert(button2ToolMap.find(Qt::Key_W) != button2ToolMap.end());
			assert(button2ToolMap.find(Qt::Key_A) != button2ToolMap.end());
			assert(button2ToolMap.find(Qt::Key_S) != button2ToolMap.end());
			assert(button2ToolMap.find(Qt::Key_D) != button2ToolMap.end());
			assert(tool2ButtonMap[0] == "A");
			assert(tool2ButtonMap[1] == "W");
			assert(tool2ButtonMap[2] == "D");
			assert(tool2ButtonMap[3] == "S");
		}
	}
	DEBUG("SUCCESS");
}

bool mSurgical::saveAllSurgeonData() {
	if (dbAvailable) {
		INFO("Saving all surgeon data...");
		if (!saveSurgeonSurgeries()) {
			return false;
		}
		if (!saveSurgeonInfo()) {
			return false;
		}
		DEBUG("Successfully saved all surgeon data");
	}

	if (testing) {
		runAssertions();
	}
	return true;
}

bool mSurgical::saveSurgeonHighScore() {
	if (surgeon.get() && dbAvailable) {
		INFO("Saving surgeon high score...");
		QSqlQuery query;
		// first create subquery SURGEON::ID for foreign key SCORE::SURGEON_ID
		QString subQuerySelectID("(SELECT ID FROM SURGEON WHERE");
		subQuerySelectID += " FIRSTNAME = '" + surgeon->getFirstName() + "'";
		subQuerySelectID += " AND LASTNAME = '" + surgeon->getLastName() + "'";
		subQuerySelectID += " LIMIT 1)";

		// now create insert query
		QString insertScore("INSERT OR IGNORE INTO SCORES (SURGEON_ID, SCORE) ");
		insertScore += "VALUES (" + subQuerySelectID + ", " + std::to_string(surgeon->getHighScore()).c_str() + ");";
		query.exec(insertScore);
		if (query.isActive()) {
			logString = "Successfully inserted score: ";
			logString += std::to_string(surgeon->getHighScore()).c_str();
			DEBUG(logString);
		}
		else {
			errorString = "query [";
			errorString += insertScore + "] failed due to: " + query.lastError().text();
			ERROR(errorString);
			return false;
		}
	}
	else {
		WARN("No surgeon available to save surgeon high score");
	}

	if (testing) {
		runAssertions();
	}

	return true;
}

bool mSurgical::saveSurgeonInfo() {
	if (surgeon.get() && dbAvailable) {
		INFO("Saving surgeon info...");
		// 1. save into SURGEON table
		for (auto & s : surgeon->getKnownSurgeries()) {
			QSqlQuery query;
			// first create subquery SURGERY::ID for foreign key SURGEON::SURGERY_ID
			QString subQuerySelectID("(SELECT ID FROM SURGERY WHERE ");
			subQuerySelectID += "NAME = '" + s.getName() + "'";
			int n = 1;	// button number for correct column in SURGERY table
			for (auto & b : s.getSequence()) {
				subQuerySelectID += QStringLiteral(" AND BUTTON%1 = %2").arg(n).arg(b);
				++n;
			}
			subQuerySelectID += ")";

			// now create insert query
			QString insertSurgeon("INSERT OR IGNORE INTO SURGEON (FIRSTNAME, LASTNAME, SURGERY_ID) ");
			insertSurgeon += "VALUES ('" + surgeon->getFirstName() + "', '" + surgeon->getLastName() + "', " + subQuerySelectID + ");";
			query.exec(insertSurgeon);
			if (query.isActive()) {
				logString = "Successfully inserted surgeon: ";
				logString += surgeon->getFirstName() + surgeon->getLastName();
				DEBUG(logString);
			}
			else {
				errorString = "query [";
				errorString += insertSurgeon + "] failed due to: " + query.lastError().text();
				ERROR(errorString);
				return false;
			}
		}
		// 2. save into SCORES table
		if (!saveSurgeonHighScore()) {
			return false;
		}

		DEBUG("Successfully saved surgeon info");
	}
	else {
		WARN("No surgeon available to save surgeon info");
	}

	if (testing) {
		runAssertions();
	}

	return true;
}

bool mSurgical::saveSurgeonSurgeries() {
	if (surgeon.get() && dbAvailable) {
		INFO("Saving surgeon surgeries...");
		// iterate over surgeon's known surgeries and insert each into SURGERY db table
		for (auto & s : surgeon->getKnownSurgeries()) {
			QSqlQuery query;
			QString insertSurgery("INSERT OR IGNORE INTO SURGERY (NAME, BUTTON1, BUTTON2) ");
			insertSurgery += "VALUES ('" + s.getName() + "'";
			for (auto & b : s.getSequence()) {
				insertSurgery += QStringLiteral(", %1").arg(b);
			}
			insertSurgery += ");";
			query.exec(insertSurgery);
			if (query.isActive()) {
				logString = "Successfully inserted surgery: ";
				logString += s.getName();
				DEBUG(logString);
			}
			else {
				errorString = "Failed to insert record due to: ";
				errorString += query.lastError().text();
				WARN(errorString);
			}
		}
		DEBUG("Successfully saved surgeon surgeries");
	}
	else {
		WARN("No surgeon available to save surgeries");
	}

	if (testing) {
		runAssertions();
	}

	return true;
}

void mSurgical::startOperating(bool start) {
	if (start) {
		INFO("Surgeon has started operating");
		displayMessage("Press the correct Button Sequence for the surgery needed "
						"by the patient on the Table before 10 seconds runs out to "
						"be the Best Doctor! Good luck.");
		// 1. initialize patients
		initPatients();

		// 2. start timers
		resetTimers();

		// 3. clear Mona Laser button seq
		ui.buttonSeqLabel0->setText("");
		ui.buttonSeqLabel1->setText("");

		// 4. set base points to be awarded
		surgeon->setCurrentScore(0);
		basePointsAwarded = surgeon->getKnownSurgeries().size();
		logString = "Base points to be awarded is ";
		logString += std::to_string(basePointsAwarded).c_str();
		DEBUG(logString);

		operating = true;
	}
	else {
		INFO("Operating session complete");
		operating = false;
		// 1. clear patients
		while (!patients.empty()) {
			patients.pop();
		}
		ui.tableSurgeryNeededEdit->setText("");
		ui.nextSurgeryNeededEdit->setText("");

		// 2. stop timers
		t1.reset();
		t2.reset();
		ui.tableProgressBar->setValue(10);

		// 3. clear Mona Laser
		while (!monaLaser.empty()) {
			monaLaser.pop();
		}

		// 4. reset score
		ui.scoreBox->setValue(0);

		// 5. check if user would like to replay
		QString gameOverMsg("Whoops! Operating complete. You scored ");
		gameOverMsg += std::to_string(surgeon->getCurrentScore()).c_str();
		gameOverMsg += " points!";
		displayMessage(gameOverMsg);
		QMessageBox replayMessage;
		replayMessage.setText("Would you like to replay?");
		replayMessage.addButton(QMessageBox::Yes);
		replayMessage.addButton(QMessageBox::No);
		int resp = replayMessage.exec();
		if (resp == QMessageBox::Yes) {
			startOperating(true);
		}
		else {
			saveSurgeonHighScore();
			changeDisplayedScreen((int)mScreen::Menu);
		}
	}

	if (testing) {
		runAssertions();
	}
}

void mSurgical::turnOnTesting() {
	testing = true;
	DEBUG("Testing is ON");
}

void mSurgical::updatePatients() {
	INFO("Updating patient queue");
	patients.pop();
	int nSurgeries = surgeon->getKnownSurgeries().size();
	int surgeryID = rand() % nSurgeries;
	std::shared_ptr<Patient> p(new Patient(surgeryID));
	patients.push(p);
	if (patients.size() >MAX_NUM_BUTTONS) {
		WARN("More than 2 patients are in the queue");
	}
	
	// update UI
	ui.tableSurgeryNeededEdit->setText(surgeon->getKnownSurgery(patients.front()->getSurgeryNeeded()).getName());
	ui.nextSurgeryNeededEdit->setText(surgeon->getKnownSurgery(patients.back()->getSurgeryNeeded()).getName());

	if (testing) {
		runAssertions();
	}
}

void mSurgical::closeEvent(QCloseEvent * qce) {
	if (!saveAllSurgeonData()) {
		WARN("Unable to save surgeon data");
	}
}

void mSurgical::keyPressEvent(QKeyEvent * qke) {
	if (operating) {
		if (button2ToolMap.find(qke->key()) != button2ToolMap.end()) {
			tool_id tool = button2ToolMap[qke->key()];
			monaLaser.push(tool);
			// update display
			switch (monaLaser.size()) {
			case 1:
				ui.buttonSeqLabel0->setText(tool2ButtonMap[tool]);
				break;
			case 2:
				ui.buttonSeqLabel1->setText(tool2ButtonMap[tool]);
				// set timer to clear button sequence so that user can actually see it
				t3.reset(new QTimer);
				t3->setSingleShot(true);
				t3->setInterval(500);
				connect(t3.get(), SIGNAL(timeout()), this, SLOT(clearButtonSequence()));
				t3->start();
				// confirm that sequence is correct or not
				if (isMonaLaserCorrect()) {
					awardPoints(ui.tableProgressBar->value() + basePointsAwarded);
					resetTimers();
					updatePatients();
					// clear button sequence
					while (!monaLaser.empty()) {
						monaLaser.pop();
					}
				}
				else {
					endGame();
				}
				break;
			default:
				ERROR("Mona Laser size is greater than 2");
				break;
			}
		}
	}
}

void mSurgical::changeDisplayedScreen(int screenNumber) {
	ui.screensStackWidget->setCurrentIndex(screenNumber);
	
	switch ((mScreen)screenNumber) {
	case mScreen::Login:
		INFO("Changed to Login screen");
		ui.pressStartLabel->hide();
		// Login screen must have "Start" button
		ui.startBackButton->setText("Start");
		ui.startBackButton->show();
		// save surgeon data before switching
		if (!saveAllSurgeonData()) {
			WARN("Unable to save surgeon data");
		}
		getLoginInfo();
		break;
	case mScreen::Menu:
		INFO("Changed to Menu screen");
		// Menu and OR screens have no "Start"/"Back" button
		ui.startBackButton->hide();
		break;
	case mScreen::OR:
		INFO("Changed to OR screen");
		ui.startBackButton->hide();
		if (surgeon->getKnownSurgeries().size() > 1) {
			startOperating(true);
		}
		else {
			// do not allow player to operate if surgeon only knows 1 surgery (TOO EASY...)
			displayMessage("In order to operate you need to learn at least TWO surgeries");
			emit ui.startBackButton->clicked();
		}
		break;
	case mScreen::HiScore:
		INFO("Changed to HiScore screen");
		// rest of screens have "Back" button
		ui.startBackButton->setText("Back");
		ui.startBackButton->show();
		populateBestDoctors();
		break;
	case mScreen::Learn:
		INFO("Changed to Learn screen");
		ui.startBackButton->setText("Back");
		ui.startBackButton->show();
		populateKnownSurgeries();
		break;
	default:
		ERROR("Unknown screen tried to display");
	}

	if (testing) {
		runAssertions();
	}
}

void mSurgical::clearButtonSequence() {
	ui.buttonSeqLabel0->setText("");
	ui.buttonSeqLabel1->setText("");
}

void mSurgical::decrementProgressBar() {
	ui.tableProgressBar->setValue(ui.tableProgressBar->value() - 1);
}

void mSurgical::endGame() {
	startOperating(false);
}

void mSurgical::learnSurgery() {
	QPushButton * senderButton = qobject_cast<QPushButton*>(QObject::sender());
	if (!senderButton) {
		ERROR("learnSurgery called by unknown object");
		return;
	}

	INFO("User clicked to learn a new surgery");
	QString surgeryName2Display;

	if (senderButton->text() == "?") {
		// generate new surgery
		Surgery learnedSurgery;
		do {
			// runniny Python script to generate temporary *.surgery file
			// *.surgery file has surgery name as filename and button sequence as first 2 lines
			if (!removeSurgeryFiles()) {
				errorString = "Unable to remove surgery file(s)";
				ERROR(errorString);
				displayMessage("Unfortunately a surgery cannot be learned at this time");
				return;
			}

			if (learnViaPython) {
				QProcess p;
				std::string cmd = "python ";
				cmd += MSURGICAL_DIRECTORY;
				cmd += "generateSurgery.py";
				int err = p.execute(cmd.c_str());		// run python script to generate new *.surgery file
				if (err) {
					errorString = "Unable to generate *.surgery file due to: ";
					errorString += std::to_string(err).c_str();
					ERROR(errorString);
					return;
				}
				getSurgeryFromFile(learnedSurgery);
			}
			else {
				generateRandomSurgery(learnedSurgery);
			}
		} while (!surgeon->getKnownSurgery(learnedSurgery.getName()).getName().isEmpty());	// make sure this surgery name is unique

		// add learned surgery
		surgeon->addSurgery(learnedSurgery);

		// display learned surgery
		surgeryName2Display = learnedSurgery.getName();
		displayMessage("Congrats!\nYou just learned the following surgery: " + surgeryName2Display);
		senderButton->setText(surgeryName2Display);
		logString = "User learned new surgery: ";
		logString += surgeryName2Display;
		INFO(logString);
	}
	else {
		surgeryName2Display = senderButton->text();
	}

	// display sequence for known surgery
	std::vector<int> seq2learn = surgeon->getKnownSurgery(surgeryName2Display).getSequence();
	QString learnString("Operation for " + senderButton->text() + " is:\n");
	for (auto & button : seq2learn) {
		learnString += tool2ButtonMap[button] + " + ";
	}
	learnString.remove(learnString.size() - 3, 3);		// remove extra " + "
	displayMessage(learnString);
	logString = "Surgery ";
	logString += surgeryName2Display + " done being learned";
	INFO(logString);

	if (testing) {
		runAssertions();
	}
}

void mSurgical::reinitButtonToolMaps() {
	button2ToolMap.clear();
	tool2ButtonMap.clear();
	INFO("Reinitialized button maps...");
	ijklOn = !ijklOn;

	if (ijklOn) {
		INFO("Using I, J, K, L for tools");
		button2ToolMap[Qt::Key_I] = 1;
		button2ToolMap[Qt::Key_J] = 0;
		button2ToolMap[Qt::Key_K] = 3;
		button2ToolMap[Qt::Key_L] = 2;

		tool2ButtonMap[0] = "J";
		tool2ButtonMap[1] = "I";
		tool2ButtonMap[2] = "L";
		tool2ButtonMap[3] = "K";

		displayMessage("Now using keyboard buttons I, J, K, L for Mona Laser button sequence");
	}
	else {
		INFO("Using W, A, S, D for tools");
		button2ToolMap[Qt::Key_W] = 1;
		button2ToolMap[Qt::Key_A] = 0;
		button2ToolMap[Qt::Key_S] = 3;
		button2ToolMap[Qt::Key_D] = 2;

		tool2ButtonMap[0] = "A";
		tool2ButtonMap[1] = "W";
		tool2ButtonMap[2] = "D";
		tool2ButtonMap[3] = "S";

		displayMessage("Now using keyboard buttons W, A, S, D for Mona Laser button sequence");
	}

	if (testing) {
		runAssertions();
	}
}

void mSurgical::toggleLearnMethod() {
	logString = "User toggled learn method via Python ";
	if (learnViaPython) {
		logString += "off";
		displayMessage("Learn via Python script turned off");
	}
	else {
		logString += "on";
		displayMessage("Learn via Python script turned on");
		movePythonFile();
	}
	DEBUG(logString);
	learnViaPython = !learnViaPython;

	if (testing) {
		runAssertions();
	}
}
