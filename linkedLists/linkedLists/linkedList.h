#pragma once
#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#include "Node.h"
#include <iostream>

using namespace std;

class linkedList{

public:
	linkedList();
	//~linkedList();
	void addNode(int newData);//add node to end of list
	void updateNode(int newData);//update specific node
	void removeNode();
	void traverse();
	void printNode();
	void printList();
	void searchList(int searchData);

private:
	node *head;
	node *current;
	node *newNode;

	const int HEAD = NULL;
};

linkedList::linkedList() {
	newNode = new node;
	head = newNode;
	current = newNode;
	head->setNode(HEAD, nullptr);
}

void linkedList::addNode(int newData){

	newNode = new node;
	newNode->setNode(newData, nullptr);
	current->setNext(newNode);
	current = newNode;
}

void linkedList::traverse() {
	current = head;

	while (current != nullptr) {
		printNode();
		current = current->getNext();
	}
}

void linkedList::printNode() {
	cout << current->getNode();
}

void linkedList::printList() {
	current = head;

	while (current != nullptr) {
		cout << current->getNode();
		current = current->getNext();
	}
}

void linkedList::searchList(int searchData) {
	current = head;

	while (current != nullptr) {
		if (current->getNode() == searchData) {
			cout << searchData << " is found!" << endl;
			break;
		}
		else {
			current = current->getNext();
			if (current == nullptr) {
				cout << searchData << " is not found!" << endl;
			}
		}
	}
}
#endif