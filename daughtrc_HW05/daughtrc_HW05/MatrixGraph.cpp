#pragma once
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned numOfNodes) {
	M.resize(numOfNodes);
	num_edges = 0;
}

MatrixGraph::~MatrixGraph(){
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	return;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	return 0;
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const {
	std::list<NWPair>* myList = new std::list<NWPair>();
	return *myList;
}

unsigned MatrixGraph::degree(NodeID u) const {
	return 0;
}

unsigned MatrixGraph::size() const {
	return 0;
}
unsigned MatrixGraph::numEdges() const {
	return 0;
}
