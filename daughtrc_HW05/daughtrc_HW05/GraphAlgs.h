// GraphAlgs.h
#include "Graph.h"
#include <vector>

#pragma once

// public variables
static Graph* G;
static double shortestWeight;
static std::vector<NodeID> bestTour;
static int* tourArr;
static std::pair<std::vector<NodeID>, EdgeWeight> bestPair;

/* recursive method call that runs through all possible permutations. During each
 * permutation, call getTourWeight to check if the current permutation tour is
 * the best tour. */
void findBestTour(int* arr, int startPos, int arrLength);

/* adds up all the weights between the locations. If the total weight is less then
 * the current best weight, change bestTour. */
bool getTourWeight(int* arr, int arrLength);

/* initializes bestTotalWeight, bestTour, and TourArr */
void setUp(Graph* g);

/* general swap method */
void swap(int* arr, int a, int b);


/*
 * Solves the Traveling Salesperson Problem: finding the shortest cycle through a graph that 
 * vists every node exactly once (with exception of the first node, which is repeated as the 
 * last node in the cycle.)
 * 
 * Return value: Return a pair, with the first element being a vector of length n listing the 
 *  order of the nodes in the cycle (do NOT list the start node twice), and the second element
 *  being the length of that path (do NOT forget to include the edge from the last node back to
 *  the start node in the total length.
 *
 * Preconditions: 
 *     G is undirected.
 *     Every pair of nodes u,v  (u != v) has an edge connecting the of weight > 0.
 */

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G);
