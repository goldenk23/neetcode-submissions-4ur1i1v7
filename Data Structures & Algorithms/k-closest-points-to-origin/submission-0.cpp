class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<double,pair<int,int>>>max_heap;
    for(auto it:points){
        int x=it[0];
        int y=it[1];
        double distance =sqrt((x*x)+(y*y));
        max_heap.push({distance,{x,y}});
        if(max_heap.size()>k){
            max_heap.pop();
        }
    } 
    vector<vector<int>>ans;
    while(!max_heap.empty()){
        int x=max_heap.top().second.first;
        int y=max_heap.top().second.second;
        max_heap.pop();
        ans.push_back({x,y});
    }  
    return ans; 
    }
};
