class Solution {
public:
    int specialArray(vector<int>& nums) {
    //     int count = 0, x, ans = -1;;
    //     //Brute Force Approach

    //     for(int i = 0; i< nums.size(); i++)
    //     {
    //         x = i + 1;
    //         count = 0;
    //         for(int j = 0; j< nums.size(); j++)
    //         {
    //             if(x<= nums[j])
    //                 count++;
    //         }

    //         if(count==x)
    //         ans = x;
    //     }
    //     return ans;
    // }

    // Binary Search Approach
    int s = 0, e = nums.size(), mid, count = 0;
    while(s<=e)
    {
        mid = s + (e-s)/2;
        count = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(mid <= nums[i])
            count++;
        }
        //If count of element x(i.e mid in this case) is exactly x then , it's our answer
        if(count==mid)
        return mid;
        //if count is greater then x(i.e mid) then increase value of x(mid)
        else if(count>mid)
        s = mid + 1;
        //else decrease the value of x(mid)
        else
        e = mid - 1;
    }
    //if we dont find any such x the return -1
    return -1;
    }
};