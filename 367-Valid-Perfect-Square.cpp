class Solution {
public:
    bool isPerfectSquare(int num) {
    
        // for(double i = 1; i*i<=num ; i++)
        // {
        //     if(i*i == num)
        //     return true;
        // }
        // return false;

        int s = 0 , e = num;
        double mid;
        //Binary Search Approach 
        while(s<=e)
        {
            mid = s +(e-s)/2;
            if(mid*mid==num)
            return true;
            else if(mid*mid>num)
            e = mid -1;
            else
            s = mid+1;
        }
        return false;
    }
};