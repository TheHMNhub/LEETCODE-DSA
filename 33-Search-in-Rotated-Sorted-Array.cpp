class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1, mid;
        while(s<=e)
        {
            mid = e + (s - e)/2;
            // If Target found in Mid
            if(nums[mid]==target)
            return mid;
            // Left Sorted
            else if(nums[0]<=nums[mid])
            {
                if(nums[0]<=target && nums[mid]>target)
                e = mid - 1;
                else
                s = mid + 1;
            }
            //Right Sorted
            else
            {
                if(nums[mid]<target && nums[e]>=target)
                s = mid + 1;
                else
                e = mid - 1;
            }
        }
        return -1;
    }
};