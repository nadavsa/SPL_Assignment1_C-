#include "Graph.h"
#include <iostream>
Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
,sorted(0),fastNeighbors(0)
{
    vector<vector<vector<int>>> build;
    vector<bool> sort;

    int size = mEdges.size();
    for(int i=0;i<size;i++){

        sort.push_back(false);

        vector<vector<int>> row;

        for(int j=size-1;j>=0;j--){
            if(mEdges[i][j]!=0){

                vector<int> tup;

                tup.push_back(j);
                tup.push_back(mEdges[i][j]);
                tup.push_back(mVertices[j].getMandates());

                row.push_back(tup);
            }
        }
        build.push_back(row);
    }
    sorted = sort;
    fastNeighbors = build; 
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

// get the neighbors for the party
vector<vector<int>>& Graph::getfastNeighbors(int partyId){
    return fastNeighbors[partyId];
}

//method that returns the vector of the parties
const vector<Party> Graph::getVertices() const{
    return mVertices;
}

//checks if the neighbors are sorted fot the party
bool Graph::isSorted(int partyId){
    if(sorted[partyId]==false){
        sorted[partyId] = true;
        return false;
    }
    return true;
}

//method that sorts the neighbors by edge weight
bool Graph::sortNeighborsbyE(int partyId){
    std::stable_sort(fastNeighbors[partyId].begin(), fastNeighbors[partyId].end(),
                [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];});
    return true;
}

//method that sorts the neighbors by mandates
bool Graph::sortNeighborsbyM(int partyId){
    std::stable_sort(fastNeighbors[partyId].begin(), fastNeighbors[partyId].end(),
                [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[2] < b[2];});
    return true;
}

// method that gets the next neighbor to make offer to (by the agent selection policy sort)
int Graph::getNext(int partyId){
    if(fastNeighbors[partyId].empty()){
        return -1;
    }
    int ret = fastNeighbors[partyId].back()[0];
    fastNeighbors[partyId].pop_back();
    return ret;
}

// method that returns a reference to a party
Party& Graph::getCParty(int i){
    return mVertices[i];
}