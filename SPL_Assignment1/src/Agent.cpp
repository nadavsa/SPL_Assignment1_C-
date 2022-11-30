#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"
#include  <iostream>

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) :
 mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
 ,agentState(0){}

//copy constructor
Agent::Agent(const Agent& other):
    mAgentId(other.mAgentId),
    mPartyId(other.mPartyId),
    mSelectionPolicy((other.mSelectionPolicy)->copySame()),
    agentState(other.agentState){}

// destructor
Agent::~Agent(){
    if(mSelectionPolicy){
        delete mSelectionPolicy;
    }
    mSelectionPolicy=nullptr;
}

// = operator
Agent& Agent::operator=(const Agent& other){
    if(this!=&other){
        if(mSelectionPolicy){
        delete(mSelectionPolicy);
        }
    }
    mAgentId=other.mAgentId;
    mPartyId=other.mPartyId;
    mSelectionPolicy=other.mSelectionPolicy;
    agentState=other.agentState;
    return *this;
}

// move constructor
Agent::Agent(Agent&& other):
    mAgentId(other.mAgentId),
    mPartyId(other.mPartyId),
    mSelectionPolicy(other.mSelectionPolicy),
    agentState(other.agentState){
    other.mSelectionPolicy=nullptr;
    }
    
//move = operator
Agent& Agent::operator=(Agent&& other){
    if(this!=&other){
        if(mSelectionPolicy){
        delete mSelectionPolicy;
        }
    }
     mAgentId=other.mAgentId;
    mPartyId=other.mPartyId;
    mSelectionPolicy=other.mSelectionPolicy;
    agentState=other.agentState;
    other.mSelectionPolicy=nullptr;
    return *this;

}

int Agent::getId() const
{
    return mAgentId;
}
int Agent::getPartyId() const
{
    return mPartyId;
}

// method that return the type of the selection policy
char Agent::selectionPolicyType(){
    return mSelectionPolicy->typeOfSelection();
}

//method that returns agent state
int Agent:: getAgentState(){
    return agentState;
}

// step of the agent
void Agent::step(Simulation &sim){
    // as long as there are active agents
    while(agentState==0){
        Graph &g = sim.getCGraph();
        //selects the party wich we will make offer to
        int partySelected=mSelectionPolicy->select(mPartyId,sim);
        // checks if there are available parties
        if(partySelected == -1){
            agentState=-1;
            break;
        }else{
            Party &partyAgentSelected= g.getCParty(partySelected);
            //makes offer to the party
            if(this->makeOffer(partyAgentSelected,sim))
                {break;}
        }   
    }
}

// method that makes offer from this agent to party p
bool Agent:: makeOffer(Party &p,Simulation &sim){
    if(p.getState()==Joined){return false;}
    for(int o:p.getOffers()){
        if(sim.sameC(mPartyId,o)) {return false;}
    }
    p.setOffers(mPartyId);
    if(p.getState()==Waiting){
        p.setState(CollectingOffers);
    }
    return true;
}