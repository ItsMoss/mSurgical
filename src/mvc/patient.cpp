#include "patient.h"

Patient::Patient() : surgeryNeeded(-1), sick(true) {

}

Patient::Patient(int surgeryID) : surgeryNeeded(surgeryID), sick(true) {

}

Patient::Patient(const Patient & rhs) {
	*this = rhs;
}

Patient & Patient::operator=(const Patient & rhs) {
	if (this != &rhs) {
		surgeryNeeded = rhs.surgeryNeeded;
		sick = rhs.sick;
	}
	return *this;
}

Patient::~Patient() {

}

const int & Patient::getSurgeryNeeded() const {
	return surgeryNeeded;
}

const bool & Patient::isSick() const {
	return sick;
}

const bool Patient::isCured() const {
	return !sick;
}

void Patient::setSurgeryNeeded(int surgeryID) {
	surgeryNeeded = surgeryID;
}

void Patient::setSick(bool s) {
	sick = s;
}
