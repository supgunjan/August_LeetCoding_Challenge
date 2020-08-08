class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() <= 1) return true;
        bool res;
        int flag = 0;
        if(isupper(word[0]))
        {
            if(isupper(word[1]))
            {
                for(int i = 2 ; i < word.length() ; i++)
                {
                    if(islower(word[i]))
                    {
                        res = false;
                        flag = 1;
                        break;
                    }
                }
                if(!flag) res = true;
                
            }
            if(islower(word[1]))
            {
                for(int i = 2 ; i < word.length() ; i++)
                {
                    if(isupper(word[i]))
                    {
                        res = false;
                        flag = 1;
                        break;
                    }
                }
                if(!flag) res = true;
            }
        }
        else if(islower(word[0]))
        {
            for(int i = 1 ; i < word.length() ; i++)
            {
                if(isupper(word[i]))
                {
                    res = false;
                    flag = 1;
                    break;
                }
            }
            if(!flag) res = true;
        }
        return res;
    }
};
