class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        int i = 0;
        vector<int> v(n,0);
            int cnt = 1;
        while(candies > 0)
        {
           
            if(candies - cnt >= 0)
            v[i] += cnt;
           
            else v[i] += candies;
            
            i++;
            i %= n;
            
            candies -= cnt;
            cnt++;
        }
      
        return v;
    }
};


