// LeetCode:647 回文子串
// 暴力搜索+动态规划优化
// [l, r] 区间是否为回文串可以由 [l+1, r-1]区间推导出来，只需要s[l] == s[r] 并且 [l+1, r-1] 为回文串
// 那么[l, r] 区间也必定为回文串

class Solution {
public:
    int countSubstrings(string s) 
    {
        const int N = 1005;
        int F[N][N];
        memset(f, 0, sizeof(f));

        int ret = 0;
        for(int i = 0; i < n; i++) f[i][i] = 1;

        for(int len = 2; len <= n; len++)
        {
            for(int l = 0; l + len - 1 < n; len++)
            {
                int r = l + len - 1;
                if(s[l] != s[r]) continue;
                if(len == 2 || f[l+1][r-1]) f[l][r] = 1, ret++;
            }
        }

        return ret;
    }
};