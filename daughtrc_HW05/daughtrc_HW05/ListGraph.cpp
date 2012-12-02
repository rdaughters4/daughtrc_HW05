#include "ListGraph.h"

ListGraph::ListGraph(int numOfNodes) {
	edgeList.resize(numOfNodes);
	num_edges = 0;
}

ListGraph::~ListGraph(){
}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	return;
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const {
	std::list<NWPair>* myList = new std::list<NWPair>();
	return *myList;
}

unsigned ListGraph::degree(NodeID u) const {
	return -1;
}

unsigned ListGraph::size() const {
	return -1;
}

unsigned ListGraph::numEdges() const {
	return -1;
}