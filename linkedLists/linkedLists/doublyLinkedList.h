#pragma once
#ifndef H_DOUBLYLINKEDLIST
#define H_DOUBLYLINKEDLIST

#include "linkedList.h";
#include "doubleNode.h";

class doublyLinkedList : public linkedList {

public:
	doublyLinkedList();
	void addNode(int newData);
	void printFromHead();
	void printFromTail();
	void traverseFromHead();
	void traverseFromTail();
	void printDoubleNode();
	void copyList(linkedList list);
	void deleteList();
	bool isEmpty();
private:
	doubleNode *head;
	doubleNode *tail;
	doubleNode *current;
	doubleNode *newNode;
	bool isStart;
};

doublyLinkedList::doublyLinkedList() {
	newNode = new doubleNode;
	current = newNode;
	head = newNode;
	tail = newNode;
	isStart = true;
}

void doublyLinkedList::addNode(int newData) {
	if (isStart) {
		head->setNode(newData);
		isStart = false;
	}
	else {
		newNode = new doubleNode;
		newNode->setNode(newData);
		newNode->setPrevious(current);	
		current->setNextDouble(newNode);
		current = newNode;
		current->setNext(nullptr);
		tail = current;
	}
}

void doublyLinkedList::printFromHead() {
	current = head;
	while (current != nullptr) {
		cout << current->getNode() << " ";
		current = current->getNextDouble();
	}
}

void doublyLinkedList::printFromTail() {
	current = tail;
	while(current != nullptr){
		cout << current->getNode() << " ";
		current = current->getPrevious();
	}
}

void doublyLinkedList::traverseFromHead() {
	current = head;
	while (current != nullptr) {
		printDoubleNode();
		current = current->getNextDouble();
	}
}

void doublyLinkedList::traverseFromTail() {
	current = tail;
	while (current != nullptr) {
		printDoubleNode();
		current = current->getPrevious();
	}
}

void doublyLinkedList::printDoubleNode() {
	cout << current->getNode() << " ";
}

void doublyLinkedList::copyList(linkedList list) {
	if (head->getNextDouble() == nullptr) {
		list.traverse();
	}
}

void doublyLinkedList::deleteList() {
	while (head != nullptr) {
		current = head;
		head = head->getNextDouble();
		delete current;
	}
}

bool doublyLinkedList::isEmpty() {
	if (head->getNextDouble() == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
#endif