class Solution {
public:
    int specialArray(vector<int>& nums) {
        int count = 0, x, ans = -1;;
        //Brute Force Approach

        for(int i = 0; i< nums.size(); i++)
        {
            x = i + 1;
            count = 0;
            for(int j = 0; j< nums.size(); j++)
            {
                if(x<= nums[j])
                    count++;
            }

            if(count==x)
            ans = x;
        }
        return ans;
    }

    
};