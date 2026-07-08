class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int l = 0, r = n.size() - 1;
        vector<int>ans(2,0);
        while(l<r)
        {
            if(n[l] + n[r] == t)
            {
                ans[0]=l+1;
                ans[1]=r+1;
                return ans;
            }
            else if(n[l] + n[r] < t)
            l++;
            else
            r--;
        }
        return ans;
    }
};