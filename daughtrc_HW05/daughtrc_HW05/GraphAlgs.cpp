#include "GraphAlgs.h"

// logic and code heavily influenced by Lucy Youxuan. 

void setUp(Graph* g) {
	G = g;
	shortestWeight = 0.0;
	int* tourArr = new int[G->size()];
	for (int i = 0; i < G->size(); i++) {
		tourArr[i] = i;
	}
	for (int i = 0; i < G->size()-1; i++) {
		shortestWeight += G->weight(tourArr[i], tourArr[i+1]);
		bestTour.push_back(tourArr[i]);
	}
	// add the final location
	shortestWeight += G->weight(tourArr[G->size()-1], tourArr[0]);
	bestTour.push_back(tourArr[G->size()-1]);

	bestPair.first = bestTour;
	bestPair.second = shortestWeight;

	findBestTour(tourArr, 1, G->size());
}

bool getTourWeight(int* arr, int arrLength) {
	std::pair<std::vector<NodeID>, EdgeWeight> currentPair;
	std::vector<NodeID> currentVector;
	double currentWeight = 0;
	currentPair.first = currentVector;
	currentPair.second = currentWeight;

	for (int i = 0; i < arrLength; i++) {
		if (i != arrLength-1) {
			currentPair.second += G->weight(arr[i], arr[i+1]);
			currentPair.first.push_back(arr[i]);
			if (currentPair.second >= bestPair.second)
				return false;
		}
		else {
			currentPair.second += G->weight(arr[i], arr[0]);
			currentPair.first.push_back(arr[i]);
			if (currentPair.second < bestPair.second)
				bestPair = currentPair;
		}
	}
}

// influence by class notes
void findBestTour(int* arr, int startPos, int arrLength) {
	if (arrLength-startPos == 1) {
		getTourWeight(arr, arrLength);
	}
	else {
		for (int i = startPos; i < arrLength; i++) {
			swap(arr, arr[startPos], i);
			findBestTour(arr, startPos+1, arrLength);
			swap(arr, arr[startPos], i);
		}
	}
}

void swap(int* arr, int a, int b) {
	int temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G) {
	setUp(G);
	return bestPair;
}

