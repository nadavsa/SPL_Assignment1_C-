#pragma once
#include <vector>
#include <algorithm>
#include "Party.h"

using std::vector;

class Graph
{
    public:
        Graph(vector<Party> vertices, vector<vector<int>> edges);
        int getMandates(int partyId) const;
        int getEdgeWeight(int v1, int v2) const;
        int getNumVertices() const;
        const Party &getParty(int partyId) const;
        const vector<Party> getVertices() const;
        vector<vector<int>> &getfastNeighbors(int partyId);
        int getNext(int partyId);
        bool isSorted(int partyId);
        bool sortNeighborsbyE(int partyId);
        bool sortNeighborsbyM(int partyId);
        Party& getCParty(int i);
    
    private:
        vector<Party> mVertices;
        vector<vector<int>> mEdges;
    
        vector<bool> sorted; // vector that saves for each party if the neighbors are sorted (depends on the policy)
        vector<vector<vector<int>>> fastNeighbors; //vector that saves the neighbors (id, edge weight, and mandates) for each party by order
    
};
