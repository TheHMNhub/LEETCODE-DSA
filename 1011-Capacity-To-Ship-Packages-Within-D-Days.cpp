class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        //Binary Search Approach
        int s = 0, e = 0, mid, ans = -1;
        //Minimum capacity that a ship can have is Max of all weights[], it can not be 1, cause its it's 1, there may a condition in which ship wont be able to carry any load (ex weight ={2,3,5,4})
        //Maximum Capacity of a ship could be the sum of all Weights.
        for(int i = 0; i< w.size(); i++)
        {
            s = max(s,w[i]);
            e+=w[i];
        }       

        while(s<=e)
        {
            mid = s + (e-s)/2;
            int c_l = 0;//Current Load
            int d = 1;
            for(int i =0; i<w.size(); i++)
            {
                //we check if we add w[i], in our c_l then, will it overload or not, if it does, we need to increase our day and load that w[i] for the next day.
                if(c_l + w[i] > mid)
                {
                    d++;
                    c_l = w[i];
                }
                else
                c_l+=w[i];
            }
            //if d is less than or equal to days then, we will store it in a answer, cause there may exist another minimum answer. so in this case we need to reduce our capacity of ship.
            if(d<=days)
            {
                ans = mid;
                e = mid - 1;
            }
            else
            s = mid + 1;
        }
        // Returning final answer.
        return ans;
        //T.C = O(nlog(n))
    }
};