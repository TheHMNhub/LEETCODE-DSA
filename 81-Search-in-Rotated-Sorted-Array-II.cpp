class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int s =0, e= nums.size() - 1, mid;
        //Base condition
        if(nums.size() == 1)
        return nums[0]==t;
        if(nums.size()==2)
        return (nums[0]==t || nums[1]==t);
        //Binary Search Approach
        while(s<=e)
        {
            mid = s + (e-s)/2;
            if(nums[mid]==t)
            return true;
            if (nums[s] == nums[mid] && nums[mid] == nums[e])
            {
                s++;
                e--;
                continue;
            }
            if(nums[s] <= nums[mid])
            {
                // Is target in the sorted left half?
                if(t >= nums[s] && t < nums[mid])
                    e = mid - 1;
                 else 
                    s = mid + 1;
                
            }
            // Otherwise, RIGHT half is sorted
            else
            {
                // Is target in the sorted right half?
                if(t > nums[mid] && t <= nums[e])
                    s = mid + 1;
                else 
                    e = mid - 1;
            }
        }
        return false;
    }
};