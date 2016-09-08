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
	//void printList();
	//void searchList(int searchData);

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

//void linkedList::printList() {
//	current = head;
//
//	while (current != nullptr) {
//		cout << current->getNode();
//		current = current->getNext();
//	}
//}

//void linkedList::searchList(int searchData) {
//	current = head;
//
//	while (current != nullptr) {
//		if (current->getNode() == searchData) {
//			cout << searchData << " is found!" << endl;
//			break;
//		}
//		else {
//			current = current->getNext();
//			if (current == nullptr) {
//				cout << searchData << " is not found!" << endl;
//			}
//		}
//	}
//}
#endif