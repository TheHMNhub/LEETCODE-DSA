class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0, e = arr.size() - 1, mid, ans = arr.size();
        while(s<=e)
        {
            mid = s + (e - s)/2;
            if(arr[mid]-mid-1 >= k)
            {
                ans = mid;
                e = mid - 1;
            }
            else
            s = mid + 1;
        }
        return ans+k;
    }
};