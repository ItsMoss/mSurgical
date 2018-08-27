#include "mSurgical.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mSurgical w;
	w.show();
	// Testing
	if (argc > 1) {
		QStringList args;
		for (int i = 1; i < argc; ++i) {
			args << argv[i];
		}
		if (args[0] == "test") {
			w.turnOnTesting();
		}
	}
	return a.exec();
}
