#pragma once
#include <iostream>
#include "Child.h"
class Group
{
	int groupNumber;
	std::string fio;
	int childCount;
	struct Node {
		Child data;
		Node* next;
	};
	Node* head;
public:
	friend std::ostream& operator<<(std::ostream& os, const Group& gr);
	Group(int _groupNumber, std::string _fio);
	~Group();
	void setFio(std::string fio);
	int getGroupNumber();
	std::string getFio();
	int getChildCount();
	Node* getGroupList();
	void clearGroup();
	void addToHead(Child& ch);
	void addAfterNode(Node* n, Child& ch);
	void insertChild(Child& ch);
	void deleteChild(Child& ch);
};

