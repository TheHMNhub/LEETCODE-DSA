class Solution {
public:
    int trap(vector<int>& h) {
        //Find Max on the right and it's index.
        int max_height = h[0], index = 0;
        for(int i = 1; i< h.size() ; i++)
        {
            if(h[i]>max_height)
            {
                max_height = h[i];
                index = i;
            }
        }
        int max_left = 0, max_right = 0, water = 0;
        for(int i = 0; i<index; i++)
        {
            if(max_left > h[i])
            {
                water += max_left - h[i];
            }
            else
            {
                max_left = h[i];
            }
        }

        for(int i = h.size() - 1; i>index ; i--)
        {
            if(max_right > h[i])
            {
                water += max_right - h[i];
            }
            else
            {
                max_right = h[i];
            }
        }

        return water;
    }
};