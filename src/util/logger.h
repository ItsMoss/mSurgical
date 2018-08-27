#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <QDir>
#include <QString>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <ctime>

#define LOGS_DIRECTORY	"./logs/"

// severity levels
#define INFO(x)		log(x, 0)
#define DEBUG(x)	log(x, 1)
#define WARN(x)		log(x, 2)
#define ERROR(x)	log(x, 3)
#define SEVERE(x)	log(x, 4)

void log(const QString & message, int level);	// method that creates a logger and logs to text file

// levels are in increasing order of severity going down
enum class LogLevel {
	Info,
	Debug,
	Warn,
	Error,
	Severe
};

struct logger {
	bool initialized;								// has log file been created
	std::string fileName;							// name of log file
	std::ofstream stream;							// output file stream for log file
	std::map<LogLevel, std::string> levelMap;		// severity map
public:
	logger();										// default constructr 0
	logger(std::string fname);						// constructor 1
	~logger();										// destructor
	void log(std::string message, LogLevel level);	// logs message to output file stream
};

#endif // __LOGGER_H__