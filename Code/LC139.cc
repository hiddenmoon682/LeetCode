
// 记忆化搜索// dfs

class Solution {
public:
    vector<int> f;

    bool dfs(string& s, vector<string>& d, int cur)
    {
        if(cur >= s.length()) return true;
        if(f[cur] != -1) return f[cur];

        f[cur] = 0;
        for(auto& w : d)
        {
            if(s.find(w, cur) == cur)
            {
                f[cur] = dfs(s, d, cur + w.length());
                if(f[cur]) return f[cur];
            }
        }

        return f[cur];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        f.assign(s.length(), -1);
        return dfs(s, wordDict, 0);
    }
};