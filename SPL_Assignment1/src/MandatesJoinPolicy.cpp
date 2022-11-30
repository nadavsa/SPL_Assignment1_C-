#include "JoinPolicy.h"
#include "Graph.h"
#include "Simulation.h"

MandatesJoinPolicy::MandatesJoinPolicy(){}
MandatesJoinPolicy::~MandatesJoinPolicy(){}

// copies the join policy
JoinPolicy* MandatesJoinPolicy::copySame(){
    return new MandatesJoinPolicy(*this);
}

int MandatesJoinPolicy::join(int partyId,Simulation &s){
    int max=-1;
    int output=-1;
    for(int o: s.getCParty(partyId).getOffers()){
        if (s.getCSize(o)>max){
            max = s.getCSize(o);
            output = o;}
    }
    return output;
}

//returns the kind of the join
char MandatesJoinPolicy::typeOfJoin(){
    return 'M';
}