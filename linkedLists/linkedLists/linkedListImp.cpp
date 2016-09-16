#include<iostream>
#include<fstream>
#include<string>

#include "doublyLinkedList.h";

using namespace std;

bool openFile(ifstream &inFile);
void loadList(ifstream &inFile, linkedList &list1,doublyLinkedList &list2);
void printList(linkedList list1);
void testPrint(doublyLinkedList &list2);

int main() {
	linkedList list1;
	doublyLinkedList list2;
	ifstream inFile;
	//int testNum;

	loadList(inFile, list1, list2);
	printList(list1);
	testPrint(list2);

	cin.ignore();
	cin.get();
	return 0;
}

bool openFile(ifstream &inFile) {
	string filepath = "p2datafile.txt"; //Entered now to speed up testing. Add option for user to enter.

	/*cout << "Please enter the filepath for the input file: ";
	cin >> filepath;*/

	inFile.open(filepath);

	if (inFile) {
		return true;
	}
	else {
		return false;
	}
}

void loadList(ifstream &inFile, linkedList &list1, doublyLinkedList &list2) {
	int data;

	if (openFile(inFile)) {
		cout << "\nFile found. Loading list." << endl;
		while (!inFile.eof()) {
			inFile >> data;
			list1.addNode(data);
			list2.addNode(data);
		}
	}
	else {
		cout << "\nFile not found. Program terminates." << endl;
		cin.ignore();
		cin.get();
	}
}

void printList(linkedList list1) {
	list1.traverse();
}

void testPrint(doublyLinkedList &list2) {
	cout << "checking if list is empty" << endl;
	if (list2.isEmpty()) {
		cout << "the list is empty. Cannot print." << endl;
	}
	else {
		cout << "\nprinting from head " << endl;
		list2.traverseFromHead();
		cout << "\nPrinting from tail " << endl;
		list2.traverseFromTail();
	}
}