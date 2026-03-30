class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>graph(numCourses);
    vector<int>indegree(numCourses);
    for(auto it:prerequisites){
        graph[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }
    queue<int>q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    if(q.empty()){
        return false;
    }
    int count_courses=0;
    while(!q.empty()){
        int curr_course=q.front();
        q.pop();
        count_courses++;
        for(auto it:graph[curr_course]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(count_courses==numCourses){
        return true;
    }
    return false;
    }
};
