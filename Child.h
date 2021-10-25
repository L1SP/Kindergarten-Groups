#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Child
{
public:
	enum class Gender {
		MALE,
		FEMALE
	};
private:
	std::string name;
	Gender gender;
	unsigned int year;
public:
	friend std::ostream& operator<<(std::ostream& os, const Child& ch);
	bool operator<(Child& ch2);
	bool operator>(Child& ch2);
	bool operator==(Child& ch2);
	bool operator!=(Child& ch2);
	Child();
	Child(std::string _name, Gender _gender, unsigned int _year);
	~Child() {};
	void setName(std::string _name);
	void setGender(Gender _gender);
	void setYear(unsigned int _year);
	std::string getName();
	Gender getGender();
	unsigned int getYear();
};

