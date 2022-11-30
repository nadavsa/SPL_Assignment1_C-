#pragma once

#include <vector>
#include "Graph.h"
//#include "Simulation.h"

class SelectionPolicy;
class Simulation;
class Graph;
class Party;
using std::vector;

class Agent
{
    public:
        Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
        Agent(const Agent& other); //copy constructor
        ~Agent(); //destructor
        Agent& operator=(const Agent& other); // = operator
        Agent(Agent&& other); // mpve constructor
        Agent& operator=(Agent&& other); /// move operator

        int getPartyId() const;
        int getId() const;
        void step(Simulation &);
        bool makeOffer( Party &p,Simulation &sim);
        char selectionPolicyType();
        int getAgentState();;

    private:
        int mAgentId;
        int mPartyId;
        SelectionPolicy *mSelectionPolicy;
        int agentState; // idle=-1, live=0
};
