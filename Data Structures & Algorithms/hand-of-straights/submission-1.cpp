class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;// map each number to it's count
        for(auto it:hand){
            mp[it]++;
        }
        for(auto it:mp){
            int key=it.first;
            int val=it.second;
            int count=val;
            // chack if key is available or not
            if(mp[key]){
            // start count number of group with initial number  as key
            mp[key]-=count;//take first number
            // need gropSize-1 more numbers
            for(int i=2;i<=groupSize;i++){
                key++;
                if(mp[key]>=count){
                    mp[key]-=count;//take next number if available
                }else{
                    return false;
                }
            }
            }
        }
        return true;
    }
};
