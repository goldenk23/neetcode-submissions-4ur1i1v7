class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        sort(triplets.begin(),triplets.end());
        vector<int>relevant_rows;
        bool a_found=false,b_found=false,c_found=false;
   for(int i=0;i<triplets.size();i++){
    if(triplets[i][0]==target[0] && triplets[i][1]==target[1] && triplets[i][2]==
    target[2]){
        return true;
    }
    if(!a_found &&triplets[i][0]==target[0]){
        relevant_rows.push_back(i);
        a_found=true;
    }
    if(!b_found &&triplets[i][1]==target[1]){
        relevant_rows.push_back(i);
        b_found=true;
    }
    if(!c_found &&triplets[i][2]==target[2]){
        relevant_rows.push_back(i);
        c_found=true;
    }
   
   }
    int max_a=-1,max_b=-1,max_c=-1;
    for(auto i:relevant_rows){
        max_a=max(max_a,triplets[i][0]);
        max_b=max(max_b,triplets[i][1]);
        max_c=max(max_c,triplets[i][2]);
    }
    if(max_a==target[0]&&max_b==target[1]&&max_c==target[2]){
        return true;
    }
   return false;
    }
};
