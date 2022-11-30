#pragma once

class Graph;
class Simulation;
class JoinPolicy {
    public:
        JoinPolicy(){}
        virtual ~JoinPolicy() = default;
        virtual int join(int partyId,Simulation &s) = 0;
        virtual JoinPolicy* copySame() = 0;
        virtual char typeOfJoin() = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        MandatesJoinPolicy();
        ~MandatesJoinPolicy();
        JoinPolicy* copySame() override;
        int join(int partyId,Simulation &s) override;
        char typeOfJoin() override;
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        LastOfferJoinPolicy();
        ~LastOfferJoinPolicy();
        JoinPolicy* copySame() override;
        int join(int partyId,Simulation &s) override;
        char typeOfJoin() override;
};