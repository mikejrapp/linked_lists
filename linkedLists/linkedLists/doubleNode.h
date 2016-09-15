#pragma once
#ifndef H_DOUBLENODE;
#define H_DOUBLENODE;

#include<iostream>;
#include"Node.h";

class DoubleNode : public node {
public:
	void setPrevious(DoubleNode *previousNode);
	DoubleNode *getPrevious();
private:
	DoubleNode *previous;
};

void DoubleNode::setPrevious(DoubleNode *previousNode) {
	previous = previousNode;
}

DoubleNode* DoubleNode::getPrevious() {
	return previous;
}

#endif