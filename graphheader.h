#pragma once
#include <iostream>
#include <set>
#include "nodeheader.h"
using namespace std;

typedef std::set<Node*>::const_iterator
node_iterator;
class Graph {
	std::set<Node*> nodes;
public:
	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	void removeEdge(Node* begin, Node* end);
	node_iterator begin() const {
		return nodes.begin();
	}
	node_iterator end() const { return nodes.end(); }
};




