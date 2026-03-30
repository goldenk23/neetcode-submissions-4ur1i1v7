class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp1;
        vector<vector<int>> freq(nums.size()+10);
        for(int i=0;i<nums.size();i++){
            mp1[nums[i]]++;
        }
       for(auto &entry:mp1)
       {
        freq[entry.second].push_back(entry.first);
       }
       // using frequency based indexing we have already sorted the frequency
       vector<int>res;
       for(int i=freq.size()-1;i>=0;i--){
        for(auto it1:freq[i]){
            res.push_back(it1);
            if(res.size()==k){
                return res;
            }
        }
       }
       return res;
    }
};
