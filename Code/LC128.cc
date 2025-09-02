// 哈希表

class Solution {
public:
    int longestConsecutive(vector<int>& a) 
    {
        unordered_map<int, int> data;
        for(int x : a) 
            data[x] = 1;
        
        int ret = 0;

        for(auto& e : data)
        {
            if(e.second)
            {
                int len = 1;
                for(int val = e.first + 1; ;val++)
                {
                    if(!data.count(val) || data[val] == 0) break;
                    data[val] = 0;
                    len++;
                }

                for(int val = e.first - 1; ;val--)
                {
                    if(!data.count(val) || data[val] == 0) break;
                    data[val] = 0;
                    len++;
                }

                ret = max(ret, len);
            }
        }
        return ret;
    }
};