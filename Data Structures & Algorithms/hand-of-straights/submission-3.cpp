class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (!(hand.size() % groupSize == 0)) {
            return false;
        }
        unordered_map<int, int> occurrence;
        set<int> smallest;
        for (auto it : hand) {
            occurrence[it]++;
            smallest.insert(it);
        }
        int chunk_required = hand.size() / groupSize;
        while (chunk_required) {
            if(smallest.empty()){
                return false;
            }
            int curr = *smallest.begin();
            int size = 0;
            while (size != groupSize) {
                if (!occurrence.count(curr) || occurrence[curr] == 0) {
                    return false;
                }
                occurrence[curr]--;
                if (occurrence[curr] == 0) {
                    smallest.erase(smallest.find(curr));
                }
                curr++;
                size++;
            }
            chunk_required--;
        }
        return true;
    }
};
