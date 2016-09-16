#pragma once
#ifndef H_DOUBLENODE
#define H_DOUBLENODE

#include <iostream>;
#include "Node.h";

class doubleNode : public node {
public:
	doubleNode();
	void setPrevious(doubleNode *previousNode);
	doubleNode *getPrevious();
	doubleNode *getNextDouble();
	void setNextDouble(doubleNode *nextNode);
private:
	doubleNode *previous;
	doubleNode *next;
};

doubleNode::doubleNode() {
	//protected members of node
	data = 0;
	next = nullptr;
	//
	previous = nullptr;
}

void doubleNode::setPrevious(doubleNode *previousNode) {
	previous = previousNode;
}

void doubleNode::setNextDouble(doubleNode *nextDouble) {
	next = nextDouble;
}

doubleNode* doubleNode::getPrevious() {
	return previous;
}

doubleNode* doubleNode::getNextDouble() {
	return next;
}
#endif