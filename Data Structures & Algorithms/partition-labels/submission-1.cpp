class Solution {
   public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> pos;
        for (int i = 0; i < s.length(); i++) {
            pos[s[i]] = i;
        }
        vector<int> ans;
        int left, right;
        int indx = 0;
        while (indx < s.length()) {
            left = indx;
            right = pos[s[indx]];
            int i = left;
            while (i < s.length() && i <= right) {
                right = max(right, pos[s[i]]);
                i++;
            }
            ans.push_back(right - left + 1);
            indx = right + 1;
        }
        return ans;
    }
};
