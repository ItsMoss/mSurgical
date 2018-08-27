#include "surgeon.h"

Surgeon::Surgeon() {
	currentScore = 0;
	highScore = 0;
}

Surgeon::Surgeon(QString fname, QString lname) : firstName(fname), lastName(lname) {
	currentScore = 0;
	highScore = 0;
}

Surgeon::Surgeon(QString fname, QString lname, std::vector<Surgery> surgeries) : firstName(fname), lastName(lname), knownSurgeries(surgeries) {
	currentScore = 0;
	highScore = 0;
}

Surgeon::Surgeon(const Surgeon & rhs) {
	*this = rhs;
}

Surgeon & Surgeon::operator=(const Surgeon & rhs) {
	if (this != &rhs) {
		firstName = rhs.firstName;
		lastName = rhs.lastName;
		knownSurgeries = rhs.knownSurgeries;
		currentScore = rhs.currentScore;
		highScore = rhs.highScore;
	}
	return *this;
}

Surgeon::~Surgeon() {

}

const QString & Surgeon::getFirstName() const {
	return firstName;
}

const QString & Surgeon::getLastName() const {
	return lastName;
}

const std::vector<Surgery> & Surgeon::getKnownSurgeries() const {
	return knownSurgeries;
}

const Surgery Surgeon::getKnownSurgery(int n) const {
	int nSurgeries = knownSurgeries.size();
	if (n < nSurgeries) {
		return knownSurgeries[n];
	}
	else {
		return Surgery();
	}
}

const Surgery Surgeon::getKnownSurgery(QString n) const {
	for (auto & s : knownSurgeries) {
		if (s.getName() == n) {
			return s;
		}
	}
	return Surgery();
}

const int Surgeon::getCurrentScore() const {
	return currentScore;
}

const int Surgeon::getHighScore() const {
	return highScore;
}

void Surgeon::setFirstName(QString fname) {
	firstName = fname;
}

void Surgeon::setLastName(QString lname) {
	lastName = lname;
}

void Surgeon::setKnownSurgeries(std::vector<Surgery> surgeries) {
	knownSurgeries = surgeries;
}

void Surgeon::setCurrentScore(int score) {
	currentScore = score;
}

void Surgeon::setHighScore(int score) {
	highScore = score;
}

void Surgeon::addSurgery(Surgery s) {
	if (knownSurgeries.size() < MAX_NUM_SURGERIES) {
		knownSurgeries.push_back(s);
	}
}
