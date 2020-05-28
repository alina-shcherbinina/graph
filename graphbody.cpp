#include "graphheader.h"
#include "bfs.h"

void Graph::addNode(Node* node) {
	nodes.insert(node);
}
void Graph::removeNode(Node* node) {
	nodes.erase(node);
	// Remove also from all neighbours list
	for (std::set<Node*>::iterator it = nodes.begin();
		it != nodes.end(); it++) {
		(*it)->removeNeighbour(node);
	}
}
void Graph::addEdge(Node* begin, Node* end) {
	if (nodes.find(begin) == nodes.end())
		return;
	if (nodes.find(end) == nodes.end())
		return;
	begin->addNeighbour(end);
	end->addNeighbour(begin);
}
void Graph::removeEdge(Node* begin, Node* end) {
	if (nodes.find(begin) == nodes.end())
		return;
	if (nodes.find(end) == nodes.end())
		return;
	begin->removeNeighbour(end);
	end->removeNeighbour(begin);
}
void Node::addNeighbour(Node* neighbour) {
	neighbours.insert(neighbour);
}
void Node::removeNeighbour(Node* neighbour){
	neighbours.erase(neighbour);
	for (std::set<Node*>::iterator it = neighbours.begin();
		it != neighbours.end(); it++) {
		(*it)->removeNeighbour(neighbour);
	}
}
bool BFS::connected(Node* begin, Node* end) {
	std::queue<Node*> nodes; nodes.push(begin);
	std::set<Node*> visited;
	while (!nodes.empty()) {
		Node* next = nodes.front(); nodes.pop();
		if (end == next) return true;
		visited.insert(next);
		for (node_iterator it = next->nb_begin();
			it != next->nb_end(); it++)
			if (visited.find(*it) == visited.end())
				nodes.push(*it);
	}
	return false;
}



