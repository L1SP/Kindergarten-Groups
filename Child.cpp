#include "Child.h"
Child::Child() {
	name = "";
	gender = Gender::MALE;
	year = 1970;
}
Child::Child(std::string _name, Gender _gender, unsigned int _year) {
	name = _name;
	gender = _gender;
	year = _year;
}
void Child::setName(std::string _name) {
	name = _name;
}
void Child::setGender(Gender _gender) {
	gender = _gender;
}
void Child::setYear(unsigned int _year) {
	year = year;
}
std::string Child::getName() {
	return name;
}
Child::Gender Child::getGender() {
	return gender;
}
unsigned int Child::getYear() {
	return year;
}
std::ostream& operator<<(std::ostream& os, const Child& ch) {
	os << ch.name<<" "<<ch.year<<'\n';
	return os;
}
bool Child::operator<(Child& ch2) {
	return name < ch2.name;
}
bool Child::operator>(Child& ch2) {
	return name > ch2.name;
}
bool Child::operator==(Child& ch2) {
	return name == ch2.name && year == ch2.year && gender == ch2.gender;
}
bool Child::operator!=(Child& ch2) {
	return !(*this == ch2);
}
