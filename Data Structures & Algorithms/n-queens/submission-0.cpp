class Solution {
    vector<vector<string>>ans;
    vector<int> col,diagl,diagr;
public:
    vector<vector<string>> solveNQueens(int n) {
     vector<string>v(n,string(n,'.'));
     col.assign(n,0);
     diagl.assign((2*n),0);
     diagr.assign((2*n),0);
     find_ways(n,0,v);
     return ans; 
    }
    void find_ways(int n,int row,vector<string>v){
        if(row==n){
            ans.push_back(v);
            return;
        }
        for(int c=0;c<n;c++){
            int i=row;
            int j=c;
            if(col[j]||diagl[i+j]||diagr[j-i+n-1]){
                continue;
            }
            v[i][j]='Q';
            col[j]=1;
            diagl[i+j]=1;
            diagr[j-i+n-1]=1;
            find_ways(n,row+1,v);
            v[i][j]='.';
            col[j]=0;
            diagl[i+j]=0;
            diagr[j-i+n-1]=0;
        }
    }

};
