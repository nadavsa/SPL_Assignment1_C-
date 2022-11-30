#include "SelectionPolicy.h"
#include "Graph.h"
#include "Simulation.h"
#include <iostream>

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){}
EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy(){}

// copies the selection policy
SelectionPolicy* EdgeWeightSelectionPolicy::copySame(){
    return new EdgeWeightSelectionPolicy(*this);
}

int EdgeWeightSelectionPolicy:: select( int partyId, Simulation &s){
    Graph &g = s.getCGraph();
    if(!g.isSorted(partyId)){
        g.sortNeighborsbyE(partyId);
    }
    int output = g.getNext(partyId);
    return output;
}

//returns the kind of the selection
char EdgeWeightSelectionPolicy::typeOfSelection(){
    return 'E';
}