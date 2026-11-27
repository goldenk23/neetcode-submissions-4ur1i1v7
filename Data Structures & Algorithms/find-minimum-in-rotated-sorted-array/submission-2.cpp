class Solution {
public:
    int findMin(vector<int> &nums) {
     int global_min=INT_MAX;
     int left=0;
     int right=(int)nums.size()-1;
     while(left<=right){
        int mid= left+(right-left)/2;
        // mid is pivot point
        if(nums[left]<=nums[mid]){
            // left half is sorted
            global_min=min(global_min,nums[left]);
            left=mid+1;
        }else{
            global_min=min(global_min,nums[mid]);
            right=mid-1;
        }
     }
     return global_min;
    }
};
