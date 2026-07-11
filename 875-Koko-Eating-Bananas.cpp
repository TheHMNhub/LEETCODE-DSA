class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //Binary Search Approach

        int s = 1, mid, ans = 0; 
        long long th = 0; //th = total hour
        int e = *max_element(piles.begin(), piles.end());
        while(s<=e)
        {
            mid = s + (e-s)/2;
            th = 0;
            for(int i =0 ; i<piles.size(); i++)
            {
                th+=ceil((double)piles[i]/mid);//calculating total hour to eat bananas 
            }
            //If th is less than or equal to h, we need to save our answer, and look for even lesser answer.
            if(th<=h)
            {
                ans = mid;
                e = mid - 1;
            }
            //If th is greater than t then we need to increase our k (i.e mid)
            else
            s = mid + 1;
        }
        return ans;
    }
};