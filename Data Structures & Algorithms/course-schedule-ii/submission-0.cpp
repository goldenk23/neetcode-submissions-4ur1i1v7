class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>indegree(numCourses);
        for(auto it:prerequisites){
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        if(q.empty()){
            return {};
        }
        vector<int>order;
        int count_course=0;
        while(!q.empty()){
            int curr_course=q.front();
            q.pop();
            count_course++;
            order.push_back(curr_course);
            for(auto it:graph[curr_course]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(count_course==numCourses){
            return order;
        }
        return {};
    }
};
