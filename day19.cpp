class Solution {
public:
    string toGoatLatin(string S) {
        vector<string> v;
        int n = S.length();
        int i = -1;
        int cnt = 0;
        int j = 0;
        while( i < n )
        {
            i++;
            cnt++;

            if(S[i] == ' ')
            {
                v.push_back(S.substr(j,cnt-1));
                cnt = 0;
                j = i+1;
            }
        }
        v.push_back(S.substr(j,cnt));
               
        for(int i = 0 ; i < v.size() ; i++)
        {
            string tmp = v[i];
            if(tmp[0] != 'a' && tmp[0] != 'e' && tmp[0] != 'i' && tmp[0] != 'o' && tmp[0] != 'u' && tmp[0] != 'A'  && tmp[0] != 'E' && tmp[0] != 'I'  && tmp[0] != 'O' && tmp[0] != 'U')
            {
                tmp += tmp[0];
                tmp = tmp.substr(1,tmp.length()-1);
            }
            tmp += "ma";
            int sz = i+1;
            while(sz)
            {
                tmp += "a";
                sz--;
            }
            v[i] = tmp;
            
        }
        
        
        string res;
        for(int i = 0 ; i < v.size() ; i++)
        {
            res += v[i];
            res += ' ';
        }
        return res.substr(0,res.length()-1);
    }
};
