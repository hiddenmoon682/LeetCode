// LeetCode 283：除自身以外的乘积
class Solution {
public:
    // 前缀和（前缀积和后缀积向乘）
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> answer(n, 1);
        int s = 1;
        for(int i = 0; i < n; i++)
        {
            answer[i] = nums[i] * s;
            s = answer[i];
        }

        s = 1;
        for(int i = n-1; i > 0 ; i--)
        {
            answer[i] = answer[i-1] * s;
            s = s * nums[i];
        }
        answer[0] = s;
        return answer;
    }
};