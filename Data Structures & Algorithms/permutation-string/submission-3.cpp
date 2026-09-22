class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) {
            return false;
        }
        vector<int> present(26, 0);
        for (auto it : s1) {
            present[it - 'a']++;
        }
        int l = s1.length();
        int left = 0;
        int right = l - 1;
        vector<int> is_present(26, 0);
        for (int i = left; i <= right; i++) {
            is_present[s2[i] - 'a']++;
        }
        while (right < s2.length()) {
            if (present == is_present) {
                return true;
            }
            is_present[s2[left]-'a']--;
            left++;
            right++;
            if (right < s2.length()) {
                is_present[s2[right]-'a']++;
            }
        }
        if (present == is_present) {
            return true;
        }
        return false;
    }
};
