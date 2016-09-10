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
	//void updateNode(int newData);//update specific node
	//void removeNode();
	void traverse();
	void printNode();
	bool searchList(int searchData);
	int findPosition(int searchData);
	void deleteList();

private:
	node *head;
	node *current;
	node *newNode;
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
	//this leaves the head of the list blank...need to figure out how to use
	//the head and advance the list.
	if (isStart) { //maybe not best but functioning
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

bool linkedList::searchList(int searchData) {//set to return a bool value to make this more generic...it works for now to test
	bool isFound = false;
	current = head;

	while (current != nullptr) {
		if (current->getNode() == searchData) {
			return true;
		}
		else {
			current = current->getNext();
			if (current == nullptr && !isFound) {
				return false;
			}//end if
		}//end else
	}//end while
}

void linkedList::deleteList() {
	current = head;
	head = head->getNext();
	delete current;
}

int linkedList::findPosition(int searchData) {
	//possibly get rid of this. Kind of not needed.

	int position = -1;//if searchData return -1

	current = head;

	while (current != nullptr) {
		if (current->getNode() == searchData) {
			position++;
			return position;
		}
		else {
			current = current->getNext();
		}
		position++;
	}

	return position;
}
#endif