class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       // we will use two pointer technique to solve this problem
       int left=0;int right=numbers.size()-1;
       while(left<=right){
        if(numbers[left]+numbers[right]<target){left++;}
        else if(numbers[left]+numbers[right]>target){right--;}
        else{return {left+1,right+1};}
       }
       return {};
    }
};
