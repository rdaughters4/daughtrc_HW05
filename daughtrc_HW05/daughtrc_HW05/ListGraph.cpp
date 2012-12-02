#include "ListGraph.h"

ListGraph::ListGraph(int numOfNodes) {
	edgeList.resize(numOfNodes);
	num_edges = 0;
}

ListGraph::~ListGraph(){
}

// Modifier

// Add a weighted, undirected edge between nodes u and v.
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	//taken from Cary Willard
	EList::const_iterator iter;
	for (iter = edgeList[u].begin(); iter != edgeList[u].end(); iter++) {
		NWPair myPair = (*iter);
		if (myPair.first == v) {
			myPair.second = weight;
			for (iter = edgeList[v].begin(); iter != edgeList[v].end(); iter++) {
				myPair = (*iter);
				if (myPair.first == u) {
					myPair.second = weight;
					return;
				}
			}
		}
	}
	edgeList[u].push_back(std::make_pair(v, weight));
	edgeList[v].push_back(std::make_pair(u, weight));
	num_edges++;
}

//Inspectors

// Get the weight between nodes u and v; return 0 if there is no edge.
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
	//taken from Cary Willard
	EList::const_iterator iter;
	for (iter = edgeList[u].begin(); iter != edgeList[u].end(); iter++) {
		NWPair myPair = (*iter);
		if (myPair.first == v)
			return myPair.second;
	}
	return NULL;
}

// Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
std::list<NWPair> ListGraph::getAdj(NodeID u) const {
	return edgeList[u];
}

// Return the degree (i.e. the number of neighorbs) of node u.
unsigned ListGraph::degree(NodeID u) const {
	return edgeList[u].size();
}

// Return the number of nodes in the graph.
unsigned ListGraph::size() const {
	return edgeList.size();
}

unsigned ListGraph::numEdges() const {
	return num_edges;
}