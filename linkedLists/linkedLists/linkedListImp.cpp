#include<iostream>
#include<fstream>
#include<string>
//#include"Node.h"
#include"linkedList.h"

using namespace std;

bool openFile(ifstream &inFile);
void loadList(ifstream &inFile, linkedList &list1);
void printList(linkedList list1);

int main() {
	linkedList list1;
	ifstream inFile;
	int testNum;

	loadList(inFile, list1);
	printList(list1);

	cout << "\nplease enter a number to search for: ";
	cin >> testNum;

	if (list1.searchList(testNum)) {
		cout << "\n" << testNum << " is found!" << endl;
		cout << testNum << "'s first position is " << list1.findPosition(testNum);
	}
	else {
		cout << "\n" << testNum << " is not found!" << endl;
	}


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

void loadList(ifstream &inFile, linkedList &list1) {
	int data;

	if (openFile(inFile)) {
		cout << "\nFile found. Loading list." << endl;
		while (!inFile.eof()) {
			inFile >> data;
			list1.addNode(data);
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