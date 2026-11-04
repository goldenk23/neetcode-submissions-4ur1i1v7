class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m=matrix[0].size();
        int firstColumn=false;
        for (int i = 0; i < (int)matrix.size(); i++) {
            if(matrix[i][0]==0){
                firstColumn=true;
            }
            for (int j = 1; j < (int)matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=1;j--){
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
            if(firstColumn){
                matrix[i][0]=0;
            }
        }
    }
};
