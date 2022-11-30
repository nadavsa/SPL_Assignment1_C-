#include "Simulation.h"
#include "Graph.h"
#include <vector>
#include <iostream>
Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph),
 mAgents(agents), coalitions(0),coalPlace(0),coalSizes(0)
{
    vector<vector<int>> coal;
    vector<int> copl;
    vector<int> colsi;
    for(int i=0;i<mGraph.getNumVertices();i++){
        copl.push_back(-1);
    }
    int i=0;
    for(Agent a:mAgents){
        int partyIdOfTheAgent = a.getPartyId();
        copl[partyIdOfTheAgent] = partyIdOfTheAgent;
        colsi.push_back(mGraph.getParty(a.getPartyId()).getMandates());
        vector<int> insideVec;
        insideVec.push_back(partyIdOfTheAgent);
        coal.push_back(insideVec);
        i++;
    }
    coalPlace = copl;
    coalitions = coal;
    coalSizes = colsi;
}

// the step of the simulation
void Simulation::step()
{
    Simulation &simulation=*this;
    for(int i=0;i<mGraph.getNumVertices();i++){
        mGraph.getCParty(i).step(simulation);
    }
    for(Agent& a:mAgents){
        a.step(simulation);
    }
}

bool Simulation::shouldTerminate() const
{
    for(int i: coalSizes){
        if(i>60){
            return true;
        }
    }
    vector<Party> parties = this->getGraph().getVertices();
    for(Party p:parties){
        if(p.getState()!=Joined){
            return false;
        }
    }
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    return coalitions;
}

// method that return the num of mandates of the coalition.
const int Simulation::getCoalitionSize(vector<int> vec)const{
    int output=0;
    int numberOfParties=vec.size();
    for(int i=0;i<numberOfParties;i++){
        output+=this->getParty(vec[i]).getMandates();    
    }
    return output;
}

// method that adds a clone agents to the vector
void Simulation::addAgent(Agent a){
    mAgents.push_back(a);
}

// method that returns agent by id
Agent Simulation::getAgent(int agentId){
    Agent output=mAgents[agentId];
    return output;
}

// method that returns the agent of the relevant perty
Agent& Simulation:: getAgentbyPartyId(int partyId){
    int ind =0;
    for(Agent& a:mAgents){
        if(a.getPartyId()==partyId)
        {return mAgents[ind];}
        ind+=1;
    }
    return mAgents[0];
}
//method that returns the next agent id
int Simulation:: newClonedAgentId(){
    Agent agent= mAgents[mAgents.size()-1];
    return (agent.getId()+1);
}

// method that returns the graph
Graph& Simulation::getCGraph(){
    return mGraph;
}

// method that returns the party by ID
Party& Simulation::getCParty(int id){
    return mGraph.getCParty(id);
}

// method that joins the party (joining) to coalition of party (tojoin)
void Simulation::joinCoalition(int joining,int tojoin){
    coalPlace[joining] = getC(tojoin);
    int colspot = getCloc(tojoin);
    coalSizes[colspot] = coalSizes[colspot] + mGraph.getMandates(joining);
    coalitions[colspot].push_back(joining);
}

// implementation of disjoints sets
int Simulation::getC(int a){
    if(coalPlace[a]==a){
        return a;
    }
    return getC(coalPlace[a]);
}

// method that checks if the variables are in the same set
bool Simulation::sameC(int a,int b){
    return (getC(a)==getC(b));
}

// method that returns the size of coalition by coalition head (partyId = i)
int Simulation::getCSize(int i){
    return coalSizes[getCloc(getC(i))];
}

// method that returns the place of the coalition in the coalition vector by the head of the coalition
int Simulation::getCloc(int a){
    int loc = getC(a);
    int ind = 0;
    for(vector<int>& vec:coalitions){
        if(vec[0]==loc)
        {
            return ind;}
        ind+=1;
    }
    return -1;
}
