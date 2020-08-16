class CombinationIterator {
    int n;
    int sz;
    vector<string> res; 
    int cnt;
public:
    CombinationIterator(string characters, int combinationLength) {
            n = characters.length();
            sz = combinationLength;
            for(int i = 0 ; i < (1 << n) ; i++)
            {
                string tmp ="";
                for(int j = 0 ;  j < n ; j++)
                {
                    if(i & (1 << j))
                    {
                        tmp += characters[j];
                    }
                }
                if(tmp.length() == sz) res.push_back(tmp);
            }
            sort(res.begin(),res.end());
            cnt = 0;
    }
    
    string next() {
         
        return res[cnt++];
    }
    
    bool hasNext() {
       if(cnt >= res.size()) return false;
        else return true;
        
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
