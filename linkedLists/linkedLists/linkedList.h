#pragma once
#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#include "Node.h"
#include <iostream>

using namespace std;

class linkedList{

public:
	linkedList();
	linkedList(int newData);
	void addNode(int newData);//add node to end of list
	void traverse();
	void printNode();
	void passOrderedList();
protected:
	node *head;
	node *current;
	node *newNode;

private:
	bool isStart = true;
};

linkedList::linkedList() {
	newNode = new node;
	head = newNode;
	current = newNode;
}

linkedList::linkedList(int newData) {
	newNode = new node;
	newNode->setNode(newData);
	head = newNode;
	current = newNode;
}

void linkedList::addNode(int newData){
	if (isStart) { 
		head->setNode(newData);
		isStart = false;
	}
	else {
		newNode = new node;
		newNode->setNode(newData);
		current->setNext(newNode);
		current = newNode;
	}
}

void linkedList::traverse() {
	current = head;

	while (current != nullptr) {
		printNode();
		current = current->getNext();
	}
}

void linkedList::printNode() {
	cout << current->getNode() << " ";
}

void linkedList::passOrderedList() {

}
#endif