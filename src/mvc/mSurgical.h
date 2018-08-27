#pragma once

#include <QtWidgets/QMainWindow>
#include <QDialog>
#include <QDir>
#include <QDirIterator>
#include <QKeyEvent>
#include <QFile>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QProcess>
#include <QPushButton>
#include <QSignalMapper>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QTimer>
#include <assert.h>
#include <memory>
#include <queue>
#include <utility>
#include "ui_mSurgical.h"
#include "logger.h"
#include "patient.h"
#include "screens.h"
#include "surgeon.h"

#define MSURGICAL_DIRECTORY		"./surgicalfiles/"
#define DATABASE_FILE_NAME		"topsecret.db"

// a tool or tool_id is for the Mona Laser and is used for mapping of certain keyboard buttons being pressed by user
#define MAX_NUM_TOOLS			4		
typedef int tool_id;	

class mSurgical : public QMainWindow
{
	Q_OBJECT

public:
	mSurgical(QWidget *parent = Q_NULLPTR);				// constructor
	~mSurgical();										// destructor
	void turnOnTesting();								// sets variable testing = true

private:
	Ui::mSurgicalClass ui;								// ui

	int basePointsAwarded;								// minimum points awarded for correct operation by player (equals half the number of known surgeries)
	std::unique_ptr<QTimer> t1, t2, t3;					// arbitrary timers (used for login pop up on software startup and OR gameplay)
	std::unique_ptr<QSqlDatabase> db;					// database connection
	bool dbAvailable;									// is database available?
	QString errorString;								// holds current error description
	QString logString;									// holds current non-error log description
	bool learnViaPython;								// should Python script be ran to generate new surgery or not?
	std::unique_ptr<QSignalMapper> mapper;				// maps various buttons to changeDisplayedScreen slot
	std::unique_ptr<Surgeon> surgeon;					// player's surgeon
	bool ijklOn;										// buttons used for Mona Laser tools "I J K L" or "W A S D"
	std::map<int, tool_id> button2ToolMap;				// maps keyboard buttons to tool_id (i.e. Qt::Key_J -> 0)
	std::map<tool_id, QString> tool2ButtonMap;			// maps tool_id to keyboard character (i.e. 0 -> "J")
	std::queue<std::shared_ptr<Patient> > patients;		// queue of patients to be treated in OR
	std::queue<int> monaLaser;							// holds button sequence while operating
	bool operating;										// is player playing in the OR right now
	std::vector<QString> surgeryList;					// list of all available surgeries for surgeon to know
	bool testing;										// is user testing mode on?

// private methods
	void awardPoints(int points2add);					// awards points to surgeon's currentScore
	bool displayMessage(const QString & msg);			// displays a pop-up message to player
	void getLoginInfo();								// gets username of player
	void generateRandomSurgery(Surgery & s);			// populates random surgery into s
	void getSurgeryFromFile(Surgery & s);				// populates surgery from generated *.surgery file
	bool initDB();										// initializes database connection
	void initPatients();								// initializes patient queue for OR gameplay
	void initSurgeon(QString fName, QString lName);		// initializes player's surgeon
	void initSurgeryList();								// initializes surgeryList
	bool isMonaLaserCorrect();							// checks whether current button sequence is correct for surgery needed by patient on table
	void movePythonFile();								// looks to move Python file (for generating surgery) to surgicalfiles/ folder
	void populateBestDoctors();							// fetches db to populate top 3 scores
	void populateKnownSurgeries();						// updates surgery buttons' text based on known surgeries of surgeon
	bool removeSurgeryFiles();							// attempts to remove *.surgery files
	void resetTimers();									// sets up and starts timers t1 and t2 for while operating
	void runAssertions();								// runs many assert statements after all methods while testing
	bool saveAllSurgeonData();							// saves all surgeon data to db
	bool saveSurgeonHighScore();						// saves high score of surgeon into SCORES db table
	bool saveSurgeonInfo();								// saves info relevant to Surgeon class in SURGEON and SCORES db tables
	bool saveSurgeonSurgeries();						// saves known surgeries of current surgeon in SURGERY db table
	void startOperating(bool start);					// start/stop the main gameplay
	void updatePatients();								// udpates patient queue upon successful operations

protected:
	void closeEvent(QCloseEvent * qce);					// overrides close event
	void keyPressEvent(QKeyEvent * qke);				// overrides key press event while operating

public slots:
	void changeDisplayedScreen(int screenNumber);		// updates stack widget page being shown
	void clearButtonSequence();							// clears button sequence labels
	void decrementProgressBar();						// decreases progress bar timer value by 1 (once a second while operating)
	void endGame();										// ends current operating session (either after 10 seconds has passed w/o correct button seq or incorrect seq entered)
	void learnSurgery();								// randomly generates new surgery if clicked by "?" button or displays sequence if clicked by known surgery button
	void reinitButtonToolMaps();						// reinitializes button2ToolMap and tool2ButtonMap based on variable ijklOn value
	void toggleLearnMethod();							// toggles value of learnViaPython

signals:

};
