#include "SelectionPolicy.h"
#include "Simulation.h"
#include "Graph.h"
#include <iostream>
MandatesSelectionPolicy::MandatesSelectionPolicy(){}
MandatesSelectionPolicy::~MandatesSelectionPolicy(){}

// copies the selection policy
SelectionPolicy* MandatesSelectionPolicy::copySame(){
    return new MandatesSelectionPolicy(*this);
}

int MandatesSelectionPolicy::select(int partyId,Simulation &s){
    Graph &g = s.getCGraph();
    if(!g.isSorted(partyId)){
        g.sortNeighborsbyM(partyId);
    }
    int output = g.getNext(partyId);
    return output;
}

//returns the kind of the selection
char MandatesSelectionPolicy::typeOfSelection(){
    return 'M';
}
