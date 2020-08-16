class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        int n = s.length();
        int od = 0;
        int flag = 0;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++)
        {
            m[s[i]]++;
        }
        if(m.size() == 1) return s.length();
        for(auto i : m)
        {
            if(i.second % 2)
            {
                od++;
            }
            if(i.second == 1)   flag = 1;
        }
        for(auto i : m)
        {
            if(od == 1 && i.second != 1)
            {
                cnt += i.second;
            }
            else
            {
                if(i.second % 2)
                {
                    cnt += i.second-1;
                }
                else
                {
                    cnt += i.second;
                }
            }
        }
        if(od == 1)
        return cnt+flag;
        if(od == 0) return cnt;
        
        return cnt+1;
    }
};
