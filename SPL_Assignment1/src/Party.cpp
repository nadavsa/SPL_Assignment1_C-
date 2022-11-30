#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"

#include <iostream>
using std::vector;

Party::Party(int id, string name, int mandates, JoinPolicy *jp) :
 mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp),
  mState(Waiting), countDown(0), offers(0), coalitionNumber(-1),
  agentId(-1)
{
    vector<int> offer;
    offers = offer;
}

//copy constructor
Party::Party(const Party& other):
    mId(other.mId),
    mName(other.mName),
    mMandates(other.mMandates),
    mJoinPolicy((other.mJoinPolicy->copySame())),
    mState(other.mState),
    countDown(other.countDown),
    offers(other.offers),
    coalitionNumber(other.coalitionNumber),
    agentId(other.agentId)
{}

// destructor
Party::~Party(){
    offers.clear();
    if(mJoinPolicy) {
        delete(mJoinPolicy);
    }
        offers.clear();
    mJoinPolicy = nullptr;
}
// = operator
Party& Party::operator=(const Party& other){
    //return (mId==other.getPartyId());
    if(this!=&other){
        if(mJoinPolicy){
            delete (mJoinPolicy);
            offers.clear();
        }
    }
    mId=other.mId;
    mName=other.mName;
    mMandates=other.mMandates;
    mJoinPolicy=other.mJoinPolicy;
    mState=other.mState;
    countDown=other.countDown;
    offers=other.offers;
    coalitionNumber=other.coalitionNumber;
    agentId=other.agentId;
    
    return *this;
}
// move constructor
Party::Party(Party&& other):
    mId(other.mId),
    mName(other.mName),
    mMandates(other.mMandates),
    mJoinPolicy(other.mJoinPolicy),
    mState(other.mState),
    countDown(other.countDown),
    offers(other.offers),
    coalitionNumber(other.coalitionNumber),
    agentId(other.agentId)
    {
    other.mJoinPolicy=nullptr;
    other.offers.clear();
}

//move = operator
Party& Party::operator=(Party&& other){
    if(this!=&other){
        if(mJoinPolicy){
            delete (mJoinPolicy);
            offers.clear();
        }
    }
    mId=other.mId;
    mName=other.mName;
    mMandates=other.mMandates;
    mJoinPolicy=other.mJoinPolicy;
    mState=other.mState;
    countDown=other.countDown;
    offers=other.offers;
    coalitionNumber=other.coalitionNumber;
    agentId=other.agentId;
    other.mJoinPolicy=nullptr;
    other.offers.clear();
    
    return *this;
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

//method that return the offers vector
 vector<int>& Party::getOffers(){
    return offers;
}

// adds an offer to offers vector
void Party::setOffers(int partyIdToAdd){
    offers.push_back(partyIdToAdd);
}

// method that joines the party to a coalition
void Party:: joinCoalition(int theCoalitionNumber,Agent agent,int clonedAgentId, int numOfCoalition, Simulation &s){
    // joins disjoints sets of the coalition and updates coalition size
    s.joinCoalition(mId,theCoalitionNumber);
    SelectionPolicy *selection;
    // creates a selection policy for the copy agent
    if(agent.selectionPolicyType()=='M'){
         selection= new MandatesSelectionPolicy();
    }
    else{
        selection = new EdgeWeightSelectionPolicy();
    }
    // creates the copy agent with new id
    Agent cloned(clonedAgentId, mId, selection);
    s.addAgent(cloned);
    // update the state of this party
    mState= Joined;
    this->setCoalitionNumber(theCoalitionNumber);

 }

// returns the id number of the coalition
int Party:: getCoalitionNumber(){
    return coalitionNumber;
}

// changes the coalition number after its joined.
void Party:: setCoalitionNumber(int newCoaliotionNumber){
    coalitionNumber=newCoaliotionNumber;
}

// returns the agent id of the party if thereis
 int Party::getAgentId(){
return agentId;

 }
    
// sets the agent id of the party
void Party::setAgentId(int newAgentId){
    agentId=newAgentId;
}

//method that returns the party id
int Party::getPartyId(){
    return mId;
}

//the step of the party
void Party::step(Simulation &s)
{
    if((mState) == CollectingOffers){
        // updates the countdown
        countDown = countDown + 1;
        Graph g = s.getGraph();
        // if it is time for the party to make a decision
        if((countDown) == 3){
            // chooses the offer to accept
            int accepted = mJoinPolicy->join(mId, s );
            Agent &agent = s.getAgentbyPartyId(accepted);
            int theCoalitionNumber = s.getC(accepted);
            // the id of the new cloned agent
            int clonedAgentId = s.newClonedAgentId();
            // joins the coalition
            this->joinCoalition(theCoalitionNumber,agent, clonedAgentId 
            ,coalitionNumber,s);
    }
}
}

