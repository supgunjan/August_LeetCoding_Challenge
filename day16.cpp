class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        
        int pmin = prices[0];
        int pmx = prices[n-1];
        vector<int> p1(n,0);
        vector<int> p2(n,0);
        for(int i = 1 ; i < n ; i++ )
        {
            p1[i] = max(p1[i-1],prices[i]-pmin);
            pmin = min(pmin,prices[i]);
            
            int j = n-i-1;
            p2[j] = max(p2[j+1],pmx - prices[j]);
            pmx = max(pmx,prices[j]);;
        }
        int res = 0;
        for(int i = 0 ; i < n ; i++)
        {
            res = max(res,p1[i]+p2[i]);
        }
        return res;
    }
};
