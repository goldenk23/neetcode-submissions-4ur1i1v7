class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=binary_search_rows(matrix,target);
        if(row==-1){return false;}
        int left=0,right=m-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[row][mid]>target){
                right=mid-1;
            }else if(matrix[row][mid]<target){
                left=mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
    int binary_search_rows(vector<vector<int>>&m1,int& target){
        int n=m1.size();
        int m=m1[0].size();
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(target<m1[mid][0]){
                right=mid-1;
            }else if(target>m1[mid][m-1]){
                left=mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
