#include<iostream>
#include<string>
//#include"Node.h"
#include"linkedList.h"

using namespace std;

int main() {
	linkedList list1;

	for (int i = 0; i < 10; i++) {
		list1.addNode(i);
	}

	list1.traverse();

	cin.get();
	return 0;
}