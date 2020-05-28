#pragma once
#include "graphheader.h"
using namespace std;

class BFS {
	const Graph& graph;
public:
	BFS(const Graph& agraph) : graph(agraph) {}
	bool connected(Node* begin, Node* end);
};