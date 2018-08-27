#ifndef __PATIENT_H__
#define __PATIENT_H__

class Patient {
public:
	Patient();													// default constructor 0
	Patient(int surgeryID);										// constructor 1
	Patient(const Patient & rhs);								// copy constructor
	Patient & operator=(const Patient & rhs);					// assignment op
	~Patient();													// destructor

	// get and set
	const int & getSurgeryNeeded() const;						// returns variable surgeryNeeded
	const bool & isSick() const;								// returns variable sick
	const bool isCured() const;									// returns variable !sick
	void setSurgeryNeeded(int surgeryID);						// sets variable surgeryNeeded
	void setSick(bool s);										// sets variable sick

protected:
	int surgeryNeeded;											// an ID for surgery needed (should map to index in a Surgeon::knownSurgeries)
	bool sick;													// is patient sick (i.e. still in need of surgery)

};

#endif // !__PATIENT_H__
