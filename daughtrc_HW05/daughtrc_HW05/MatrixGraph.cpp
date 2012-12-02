#pragma once
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned numOfNodes) {
	num_edges = 0;
	M.resize(numOfNodes);
	for (int u = 0; u < M.size(); u++) {
		M[u].resize(numOfNodes);
		for (int v = 0; v < M.size(); v++)
			M[u][v] = 0;
	}
}

MatrixGraph::~MatrixGraph(){
}

// Modifier

// Add a weighted, undirected edge between nodes u and v.
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	M[v][u] = weight;
	M[u][v] = weight;
	num_edges++;
}

// Inspectors

// returns the weight between (u,v); return 0 if there is no edge.
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	if (M[v][u] != 0)
		return M[v][u];
	else
		return 0;
}

// Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const {
	std::list<NWPair>* myList = new std::list<NWPair>();
	for (int v = 0; v < M.size(); v++) {
		if (M[u][v] != 0)
			myList->push_back(std::make_pair(v, M[u][v]));
	}

	return *myList;
}

// Return the degree (i.e. the number of neighorbs) of node u.
unsigned MatrixGraph::degree(NodeID u) const {
	int degree = 0;
	for (int v = 0; v < M.size(); v++) {
		if (M[u][v] != 0)
			degree++;
	}

	return degree;
}

// Return the number of nodes in the graph.
unsigned MatrixGraph::size() const {
	return M.size();
}

// Return the number of edges in the graph.
unsigned MatrixGraph::numEdges() const {
	return num_edges;
}
