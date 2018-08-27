#include "mSurgical.h"

mSurgical::mSurgical(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.startBackButton, SIGNAL(clicked()), this, SLOT(changeDisplayedScreen()));
}

void mSurgical::changeDisplayedScreen() {
	// if "Start" pressed go to menu screen
	if (ui.startBackButton->text() == "Start") {
		ui.screensStackWidget->setCurrentIndex(1);
	}
}
