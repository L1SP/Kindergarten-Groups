#include "Group.h"
#include "Child.h"
Group::Group(int _groupNumber, std::string _fio) {
	groupNumber = _groupNumber;
	fio = _fio;
	childCount = 0;
	head = nullptr;
}
Group::~Group() {
	clearGroup();
}
void Group::setFio(std::string _fio) {
	fio = _fio;
}
int Group::getGroupNumber() {
	return groupNumber;
}
std::string Group::getFio() {
	return fio;
}
int Group::getChildCount() {
	return childCount;
}
Group::Node* Group::getGroupList() {
	return head;
}
void Group::clearGroup() {
	Node* p=head;
	while (p) {
		head = head->next;
		p->next = nullptr;
		delete p;
		p = head;
	}
}
void Group::addToHead(Child& ch) {
	Node* p = new Node;
	p->data = ch;
	p->next = head;
	head = p;
}
void Group::addAfterNode(Node* n, Child& ch) {
	Node* p = new Node;
	p->data = ch;
	p->next = n->next;
	n->next = p;
}
void Group::insertChild(Child& ch) {
	childCount++;
	if (!head || ch<head->data)
		addToHead(ch);
	else {
		Node* p = head;
		while (p->next && ch<p->next->data) {
			p = p->next;
		}
		addAfterNode(p, ch);
	}
}
void Group::deleteChild(Child& ch) {
	Node* p = head;
	Node* q;
	if (p->data == ch) {
		p = head->next;
		delete head;
		head = p;
	}
	else {
		while (p->next->data != ch) {
			p = p->next;
		}
		q = p->next->next;
		delete p->next;
		p = q;
	}
}
std::ostream& operator<<(std::ostream& os, const Group& gr) {
	Group::Node* p = gr.head;
	os << "ФИО воспитателя: "<<gr.fio << '\n';
	os << "Номер группы: "<<gr.groupNumber << '\n';
	os <<"Детей в группе: "<< gr.childCount << '\n';
	if (p == nullptr)
		os << "Группа пустая.\n";
	else {
		os << "Список детей:\n";
		while (p) {
			os << p->data;
			p = p->next;
		}
	}
	return os;
}