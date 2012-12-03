#include "GraphAlgs.h"

void setUp(Graph* g) {
	G = g;
	shortestWeight = 0.0;
	tourArr = new int[G->size()];
	for (int i = 0; i < G->size(); i++) {
		tourArr[i] = i;
		shortestWeight += G->weight(tourArr[i], tourArr[i+1]);
		bestTour.push_back(tourArr[i]);
	}
	// add the final location
	shortestWeight += G->weight(tourArr[G->size()-1], 0);
	bestTour.push_back(tourArr[G->size()-1]);

	std::pair<std::vector<NodeID>, EdgeWeight> bestPair;
	bestPair.first = bestTour;
	bestPair.second = shortestWeight;
}

bool getTourWeight(int* arr, int arrLength) {
	int currentWeight = 0;
	for (int i = 0; i < arrLength; i++) {
		currentWeight += G->weight(arr[i], 0);
		if (currentWeight >= shortestWeight)
			return false;
	}
	shortestWeight = currentWeight;
	for (int i = 0; i < arrLength; i++) {
		bestTour[i] = i;
	}
}

void findBestTour(int* arr, int startPos, int arrLength) {
	if (startPos >= arrLength) {
		return;
	}
	else {
		for (int i = startPos+1; i < arrLength; i++) {
			swap(arr, arr[startPos], i);
			getTourWeight(arr, arrLength);
			findBestTour(arr, startPos+1, arrLength);
			swap(arr, arr[startPos], i);
		}
	}
}

void swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[b] = arr[a];
	arr[a] = temp;
}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G) {
	setUp(G);
	findBestTour(tourArr, 1, G->size()-1);
	return std::make_pair(bestTour, bestTotalWeight);
}

