class Solution {
    vector<vector<int>> ans;
    void solve(vector<int>& v, int indx, vector<int>& comb, int sum, int target) {
        if (sum == target) {
            ans.push_back(comb);
            return;
        }
        if (sum > target || indx >= v.size()) {
            return;
        }
        comb.push_back(v[indx]);
        solve(v, indx + 1, comb, sum + v[indx], target);
        comb.pop_back();
        int temp = indx;
        while (temp < v.size() && v[temp] == v[indx]) {
            temp++;
        }
        solve(v, temp, comb, sum, target);
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        solve(candidates, 0, comb, 0, target);
        return ans;
    }
};
