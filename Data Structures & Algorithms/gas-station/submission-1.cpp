class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;// stores total fuel gain till now from 1'st gas station
        int curr=0; //stores total gain from starting station
        int start=0;// index of starting gas station
        for(int i=0;i<gas.size();i++){
            int gain=gas[i]-cost[i];
            total+=gain;
            curr+=gain;
            if(curr<0){// we are stuck so try starting from next station
            start=i+1;
            curr=0;
            }
        }
        return (total>=0)?start:-1;
    }
};
