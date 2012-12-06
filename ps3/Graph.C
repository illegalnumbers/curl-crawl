#include "Graph.h"

Graph::Graph(void)
{
}


Graph::~Graph(void)
{
}

void Graph::resetVisitSession() {
	for(int i = 0; i < links.size(); i++) {
		links.at(i).visited = false;
	}
}

Link Graph::operator[] (int i) {
	return this->links.at(i);
}

void Graph::addLink(Link link) {
	this->links.push_back(link);
}

int Graph::getSize() {
	return this->size;
}
