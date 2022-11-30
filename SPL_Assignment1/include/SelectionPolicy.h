#pragma once
class Simulation;
class Graph;

    class SelectionPolicy {
        public:
        SelectionPolicy(){}
        SelectionPolicy(const SelectionPolicy& other){};
        virtual ~SelectionPolicy() = default;
        virtual SelectionPolicy* copySame() =0;
        virtual int select(int partyId,Simulation &s) = 0;
        virtual char typeOfSelection() = 0;

    };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        ~MandatesSelectionPolicy();
        SelectionPolicy* copySame() override;
        int select(int partyId,Simulation &s)override;
        char typeOfSelection()override;

 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        EdgeWeightSelectionPolicy();
        ~EdgeWeightSelectionPolicy();
        SelectionPolicy* copySame() override;
        int select(int partyId,Simulation &s)override;
        char typeOfSelection()override;
};