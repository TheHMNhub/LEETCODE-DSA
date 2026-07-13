class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // Edge case: if the array has fewer than 3 elements, return empty
        if (nums.size() < 3)
        return ans; 
        
        sort(nums.begin(), nums.end());
        
        // Use int to safely handle sizes
        int n = nums.size();
        
        for(int i = 0; i < n - 2; i++)
        {
            //Skip duplicate elements for 'i' to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1])
            continue;
            
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    //Move both pointers after finding a match to prevent an infinite loop
                    l++;
                    r--;
                    //Skip duplicate elements for 'l' and 'r'
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                } 
                else if(sum > 0)
                r--; 
                else
                l++;
            }
        }
        return ans;
    }
};