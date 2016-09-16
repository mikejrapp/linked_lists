#ifndef H_NODE
#define H_NODE

using namespace std;

class node{

protected:
	int data;
private:
	node *next;
public:
	node();
	void setNode(int newData);
	void setNext(node *nextNode);
	int getNode();
	node *getNext();
};

node::node() {
	data = 0;
	next = nullptr;
}

void node::setNode(int newData) {
	data = newData;
}

void node::setNext(node *nextNode){
	next = nextNode;
}

int node::getNode() {
	return data;
}

node* node::getNext() {
	return next;
}
#endif
