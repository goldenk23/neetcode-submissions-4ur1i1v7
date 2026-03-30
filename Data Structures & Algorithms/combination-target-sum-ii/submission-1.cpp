class Solution {
    vector<vector<int>>ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        find_combinations(candidates,target,0,{});
        return ans;
    }
    void find_combinations(vector<int>&candidates,int target,int indx,vector<int>combination){
        if(target==0){
            ans.push_back(combination);
            return;
        }
        if(target<0||indx>=candidates.size()){
            return;
        }
        int i=indx;
        int prev=candidates[i];
        for(i;i<candidates.size();i++){
            if(candidates[i]!=prev){break;}
        }
        find_combinations(candidates,target,i,combination);
        combination.push_back(candidates[indx]);
        find_combinations(candidates,target-candidates[indx],indx+1,combination);
    }
};
