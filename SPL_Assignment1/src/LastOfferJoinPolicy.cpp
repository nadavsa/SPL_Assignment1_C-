#include "JoinPolicy.h"
#include "Graph.h"
#include "Simulation.h"
LastOfferJoinPolicy::LastOfferJoinPolicy(){}
LastOfferJoinPolicy::~LastOfferJoinPolicy(){}


// copies the join policy
JoinPolicy* LastOfferJoinPolicy::copySame(){
    return new LastOfferJoinPolicy(*this);
}

int LastOfferJoinPolicy::join(int partyId,Simulation &s){
    return s.getCParty(partyId).getOffers().back();
}

//returns the kind of the join
char LastOfferJoinPolicy::typeOfJoin(){
    return 'L';
}