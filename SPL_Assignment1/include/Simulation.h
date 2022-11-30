#pragma once

#include <vector>
#include <string>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;

class Agent;
class Party;
class Graph;
class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

        void step();
        bool shouldTerminate() const;
        const Graph &getGraph() const;
        const vector<Agent> &getAgents() const;
        const Party &getParty(int partyId) const;
        const vector<vector<int>> getPartiesByCoalitions() const;
        const int getCoalitionSize(vector<int> vec) const;
        void addAgent(Agent a);
        Agent getAgent(int agentId);
        int newClonedAgentId();
        void joinCoalition(int joining,int tojoin);
        int getC(int a);
        bool sameC(int a,int b);
        int getCSize(int i);

        Agent& getAgentbyPartyId(int partyId);
        Graph &getCGraph();
        Party& getCParty(int id);

    private:
        Graph mGraph;
        vector<Agent> mAgents;
        vector<vector<int>> coalitions; //vector of coalitions (the [0] of every coalition is the head of it)
        vector<int> coalPlace; // disjoints sets implementation (using array/vector)
        vector<int> coalSizes; // sizes of each coalition by mandates
        
        int getCloc(int a);
};
