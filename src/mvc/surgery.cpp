#include "surgery.h"

Surgery::Surgery() {

}

Surgery::Surgery(QString surgeryname) : name(surgeryname) {

}

Surgery::Surgery(QString surgeryname, std::vector<int> seq) : name(surgeryname), buttonSequence(seq) {

}

Surgery::Surgery(const Surgery & rhs) {
	*this = rhs;
}

Surgery & Surgery::operator=(const Surgery & rhs) {
	if (this != &rhs) {
		name = rhs.name;
		buttonSequence = rhs.buttonSequence;
	}

	return *this;
}

Surgery::~Surgery() {

}

const QString & Surgery::getName() const {
	return name;
}

const std::vector<int> & Surgery::getSequence() const {
	return buttonSequence;
}

void Surgery::setName(QString surgeryname) {
	name = surgeryname;
}

void Surgery::setSequence(std::vector<int> seq) {
	buttonSequence = seq;
}