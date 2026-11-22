class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites){
            int u = it[0];
            int v=  it[1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        /* sort all courses in order they should be finishes so that it possible
        to finish all courses
        **/ 
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr_course=q.front();
            q.pop();
            topo.push_back(curr_course);
            for(auto next_course:graph[curr_course]){
                indegree[next_course]--;
                if(indegree[next_course]==0){
                    q.push(next_course);
                }
            }
        }
        if(topo.size()==numCourses){
            return true;
        }
        return false;
    }
};
