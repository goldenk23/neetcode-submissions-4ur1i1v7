class Solution {
    int find_max(vector<int>&nums,int start, int end){
      int prev2=0;// maximum profit till (i-2)'th house
      int prev1=nums[start];// maximum profit till (i-1)'th house
      for(int i=start+1;i<=end;i++){
        int curr=max(prev1,prev2+nums[i]);
        prev2=prev1;
        prev1=curr;
      }
      return prev1;
    }
public:
    int rob(vector<int>& nums) {
      int n=nums.size();
      if(n==0){return 0;}
      if(n==1){return nums[0];}
  return max(find_max(nums,0,n-2),find_max(nums,1,n-1));
    }
};
