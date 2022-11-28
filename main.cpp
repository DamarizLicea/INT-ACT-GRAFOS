// =================================================================
//
// File: main.cpp
// Author: damariz licea
// Date:24/11/2022
//
// =================================================================
#include <iostream>
using namespace std;
#include "grafo.h"
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
	ifstream inFile (argv[1]);
	ofstream outFile (argv[2]);
	int nEdge = 0;
	string from;
	string to;
	inFile>>nEdge;

	Graph<string> g;
	for (int i = 0; i < nEdge; i++) {
		inFile>>from>>to;
		g.addEdge(from,to);
	}

	int nque,depth;
	string startcty;
	inFile>>nque;
	for (int i = 0; i < nque; i++) {
		inFile>>startcty>>depth;
		set<string> neighbors = g.getNeighbors(startcty);
		neighbors.insert(startcty);
		int dp=1;
		while (dp<depth) {
			set<string> newNeighbors;
			for (string neighbor : neighbors) {
				set<string> temp = g.getNeighbors(neighbor);
				newNeighbors.insert(temp.begin(), temp.end());
			}
			neighbors.insert(newNeighbors.begin(), newNeighbors.end());
			dp++;
		}

		outFile << "Case " << i + 1 << ": " << g.nNodes() - neighbors.size()
						<< " ports not reachable from port " << startcty << " with MNP = "
						<< depth << "." << endl;
		}

	



}
