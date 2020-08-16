class Solution {
public:
    int titleToNumber(string s) {
        int cnt = 0;
        int n = s.length();
        int i;
        for(i = 0 ; i < n-1 ; i++)
        {
           cnt += (s[i]-'A'+1);
           cnt *= 26;
            cout<<cnt<<endl;
        }
        cnt += s[i]-'A'+1;
        return cnt;
      
    }
};
