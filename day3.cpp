class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        bool ans = true;
        while(l < r)
        {
            while(l < r && !isalnum(s[l])) l++;
            while(l < r && !isalnum(s[r])) r--;

             if(tolower(s[l]) != tolower(s[r]))
             {
                 ans = false;
                 break;
             }


           
            l++;
            r--;
        }
        
        return ans;
    }
};
//"race a car"
