#ifndef __SURGEON_H__
#define __SURGEON_H__

#include "surgery.h"

class Surgeon {
public:
	Surgeon();																	// default constructor 0
	Surgeon(QString fname, QString lname);										// constructor 1
	Surgeon(QString fname, QString lname, std::vector<Surgery> surgeries);		// constructor 2
	Surgeon(const Surgeon & rhs);												// copy constructor
	Surgeon & operator=(const Surgeon & rhs);									// assignment op
	~Surgeon();																	// destructor

	// get and set
	const QString & getFirstName() const;										// returns variable firstName
	const QString & getLastName() const;										// returns variable lastName
	const std::vector<Surgery> & getKnownSurgeries() const;						// returns variable knownSurgeries
	const Surgery getKnownSurgery(int n) const;									// returns knownSurgeries[n]
	const Surgery getKnownSurgery(QString n) const;								// returns surgery from knownSurgeries with name n
	const int getCurrentScore() const;											// returns variable currentScore
	const int getHighScore() const;												// returns variable highScore
	void setFirstName(QString fname);											// sets variable firstName
	void setLastName(QString lname);											// sets variable lastName
	void setKnownSurgeries(std::vector<Surgery> surgeries);						// sets variable knownSurgeries
	void setCurrentScore(int score);											// sets variable currentScore
	void setHighScore(int score);												// sets variable highScore

	// other
	void addSurgery(Surgery s);													// adds a surgery to known surgeries

protected:
	QString firstName;							// first name of player's surgeon
	QString lastName;							// last name of player's surgeon
	std::vector<Surgery> knownSurgeries;		// known surgeries (should not exceed size of 16)
	int currentScore;							// current score player's surgeon has
	int highScore;								// highest score player's surgeon has

};

#endif // !__SURGEON_H__
