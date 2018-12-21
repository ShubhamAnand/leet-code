/*
Link - https://leetcode.com/problems/search-insert-position/
*/

int searchInsert(vector<int>& nums, int target) {
    int i = 0, j = nums.size()-1;
    while(i <= j){
        int mid = (i+j) >> 1;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            j = mid-1;
        else
            i = mid+1;
    }
    return i;
}