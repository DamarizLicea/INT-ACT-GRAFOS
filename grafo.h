#ifndef grafo_h
#define grafo_h
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
using namespace std;
template <class T>
class Graph {
    private:
    vector<vector<bool> > gphMatrix;
    vector<T> gphNodes;
    public:
    Graph();
    ~Graph();
    void addNode(T);
    void addEdge(T, T); // add an edge between two nodes
    set<T> getNeighbors(T); // return the neighbors of a node
    string toString();
    int nNodes();
};
template <class T>
Graph<T>::Graph() {
}
template <class T>
Graph<T>::~Graph() {
}

template <class T>
void Graph<T>::addNode(T node) {
    gphNodes.push_back(node);
    for (int i = 0; i < gphMatrix.size(); i++) {
        gphMatrix[i].push_back(false);
    }
    vector<bool>newRow;
    for (int i=0;i<gphMatrix.size()+1;i++){
        newRow.push_back(false);
    }
    gphMatrix.push_back(newRow);
}
template <class T>
void Graph<T>::addEdge(T from, T to) {
    int fromIndex = -1;
    int toIndex = -1;
    for (int i = 0; i < gphNodes.size(); i++) {
        if (gphNodes[i] == from) {
            fromIndex = i;
        }
        if (gphNodes[i] == to) {
            toIndex = i;
        }
    }
    if (fromIndex == -1) {
        addNode(from);
        fromIndex=gphMatrix.size()-1;
    }
    if (toIndex == -1) {
        addNode(to);
        toIndex=gphNodes.size()-1;
        
    }
    gphMatrix[fromIndex][toIndex] = true;
    gphMatrix[toIndex][fromIndex] = true;
}
template <class T>
set<T> Graph<T>::getNeighbors(T node) {
    set<T> neighbors;
    int nodeIndex = -1;
    for (int i = 0; i < gphNodes.size(); i++) {
        if (gphNodes[i] == node) {
            nodeIndex = i;
        }
    }
    if (nodeIndex == -1) {
        return neighbors;
    }
    for (int i = 0; i < gphMatrix[nodeIndex].size(); i++) {
        if (gphMatrix[nodeIndex][i]) {
            neighbors.insert(gphNodes[i]);
        }
    }
    return neighbors;
}
template <class T>
string Graph<T>::toString() {
    stringstream ss;
    for (int i = 0; i < gphMatrix.size(); i++) {
        ss << gphNodes[i] << ": ";
        for (int j = 0; j < gphMatrix[i].size(); j++) {
            if (gphMatrix[i][j]) {
                ss << gphNodes[j] << " ";
            }
        }
        ss << endl;
    }
    return ss.str();
}
template <class T>
int Graph<T>::nNodes() {
    return gphNodes.size();
}

#endif /* grafo_h */