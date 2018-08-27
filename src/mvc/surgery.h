#ifndef __SURGERY_H__
#define __SURGERY_H__

#include <QString>
#include <vector>

#define MAX_NUM_SURGERIES	16		// maximum number of surgeries a Surgeon can know
#define MAX_NUM_BUTTONS		2		// maximum number of buttons a Surgery::buttonSequence can have

class Surgery {
public:
	Surgery();													// default constructor 0
	Surgery(QString surgeryname);								// constructor 1
	Surgery(QString surgeryname, std::vector<int> seq);			// constructor 2
	Surgery(const Surgery & rhs);								// copy constructor
	Surgery & operator=(const Surgery & rhs);					// assignment op
	~Surgery();													// destructor

	// get and set
	const QString & getName() const;							// returns variable name
	const std::vector<int> & getSequence() const;				// returns variable buttonSequence
	void setName(QString surgeryname);							// sets variable name
	void setSequence(std::vector<int> seq);						// sets variable buttonSequence

protected:
	QString name;												// name of surgery
	std::vector<int> buttonSequence;							// sequence of buttons associated with this surgery (should not exceed size 2 for now)

};

#endif // !__SURGERY_H__
