#include "logger.h"

void log(const QString & message, int level) {
	// create log folder (if does not exist)
	if (!QDir(LOGS_DIRECTORY).exists()) {
		QDir().mkdir(LOGS_DIRECTORY);
	}
	static bool firstCall = true;
	QString fname(LOGS_DIRECTORY);
	if (firstCall) {
		// get timestamp for log file name
		firstCall = false;
		time_t t;
		time(&t);
		fname += ctime(&t);
		fname.replace("\n", ".txt");
		fname.replace(QRegExp("[: ]"), "_");
	}
	static logger loggerFile(fname.toStdString());
	loggerFile.log(message.toStdString(), static_cast<LogLevel>(level));
}

logger::logger() : initialized(false), fileName("log.txt") {
	stream.open(fileName.c_str());
	initialized = stream.is_open();
	levelMap[LogLevel::Info] = "INFO";
	levelMap[LogLevel::Debug] = "DEBG";
	levelMap[LogLevel::Warn] = "WARN";
	levelMap[LogLevel::Error] = "EROR";
	levelMap[LogLevel::Severe] = "SEVR";
}

logger::logger(std::string fname) : initialized(false), fileName(fname) {
	stream.open(fileName.c_str());
	initialized = stream.is_open();
	levelMap[LogLevel::Info] = "INFO";
	levelMap[LogLevel::Debug] = "DEBG";
	levelMap[LogLevel::Warn] = "WARN";
	levelMap[LogLevel::Error] = "EROR";
	levelMap[LogLevel::Severe] = "SEVR";
}

logger::~logger() {
	if (stream.is_open()) {
		stream.close();
	}
}

void logger::log(std::string message, LogLevel level) {
	if (initialized && stream.is_open() && stream.good()) {
		stream << levelMap[level] << ":" << message << std::endl;
	}
}