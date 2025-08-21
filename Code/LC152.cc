// LeetCode 152：分情况讨论
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ret = INT_MIN, sum = 1;
        for(int l = 0, r = 0; l < nums.size();)
        {
            if(r == nums.size() || nums[r] == 0)
            {
                if(r < nums.size()) ret = max(ret, 0);
                while(l < r) ret = max(ret, sum), sum /= nums[l++];
                l++, r++;
            }
            else
            {
                sum *= nums[r++];
                ret = max(ret, sum);
            }
        }
        return ret;
    }
};