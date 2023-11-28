#include "IntList.h"

IntList::IntList()
{
	dummyHead = new IntNode(0);
	dummyTail = new IntNode(0);
	dummyHead->next = dummyTail;
	dummyTail->prev = dummyHead;
}

IntList::~IntList()
{
	while (!empty()) {
		pop_front();
	}
	delete dummyHead;
	delete dummyTail;
}

void IntList::push_front(int value)
{
	IntNode *newNode = new IntNode(value);
	if (dummyHead->next) {
		IntNode *temp = dummyHead->next;
		dummyHead->next = newNode;
		newNode->next = temp;
		newNode->prev = dummyHead;
		temp->prev = newNode;
	}
	else {
		dummyHead->next = newNode;
		newNode->next = dummyTail;
		dummyTail->prev = newNode;
		newNode->prev = dummyHead;
	}

}

void IntList::pop_front()
{
	if (!empty()) {
		IntNode *temp = dummyHead->next;
		dummyHead->next = temp->next;
		temp->next->prev = dummyHead;
		delete temp;
	}
}

void IntList::push_back(int value)
{
	IntNode *newNode = new IntNode(value);
	if (dummyTail->prev) {
		IntNode *temp = dummyTail->prev;
		dummyTail->prev = newNode;
		newNode->prev = temp;
		newNode->next = dummyTail;
		temp->next = newNode;
	}
	else {
		dummyHead->next = newNode;
		newNode->next = dummyTail;
		dummyTail->prev = newNode;
		newNode->prev = dummyHead;
	}
}

void IntList::pop_back()
{
	if (!empty()) {
		IntNode *temp = dummyTail->prev;
		dummyTail->prev = temp->prev;
		temp->prev->next = dummyTail;
		delete temp;
	}
}

bool IntList::empty() const
{
	return (dummyHead->next == dummyTail);
}

void IntList::printReverse() const
{
	if (!empty()) {
		for (IntNode *currNode = dummyTail->prev; currNode != dummyHead; currNode = currNode->prev) {
			cout << currNode->data;
			if (currNode != dummyHead->next) {
				cout << ' ';
			}
		}
	}
}

ostream & operator<<(ostream & out, const IntList & rhs)
{
	if (!rhs.empty()) {
		for (IntNode *currNode = rhs.dummyHead->next; currNode != rhs.dummyTail; currNode = currNode->next) {
			out << currNode->data;
			if (currNode != rhs.dummyTail->prev) {
				out << ' ';
			}
		}
	}
	return out;
}
