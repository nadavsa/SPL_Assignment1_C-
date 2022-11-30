#pragma once
//#include "Agent.h"
#include "SelectionPolicy.h"
#include <string>
#include <vector>

class Graph;
using std::string;
using std::vector;
class JoinPolicy;
class Simulation;
class Agent;
enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    Party(const Party& other); //copy constructor
    ~Party(); //destructor
   Party& operator=(const Party& other); // = operator
    Party(Party&& other); // mpve constructor
    Party& operator=(Party&& other); /// move operator


    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    vector<int> &getOffers();
    void joinCoalition(int theCoalitionNumber,Agent agent,int clonedAgentId, 
    int numOfCoalition,Simulation &s);
    int getCoalitionNumber();
    void setCoalitionNumber(int coal);
    void setOffers(int partyId);
    int getAgentId();
    void setAgentId(int agentId);
    int getPartyId();

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int countDown; //the clock of the party
    vector<int> offers; //vector that saves the suggetstion to join a coalition of this party
    int coalitionNumber; // saves the number of the coalition which this party belongs to (if there is)
    int agentId; // the agent id of this party (if there is)

};
