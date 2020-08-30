class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> yr(366,0);
        vector<int> dp(366,0);
        for(auto i : days){
            yr[i] = 1;
        }
        for(int i = 1 ; i <= 365 ; i++){
            if(yr[i] == 1){
             
                dp[i] = min({dp[i-1]+costs[0] , dp[max(0,i-7)] + costs[1] , dp[max(0,i-30)] + costs[2]});
            }
            else{
                dp[i] = min({dp[i-1] , dp[max(0,i-7)]+costs[1] , dp[max(0,i-30)] + costs[2]});
            }
        }
        return dp[365];
    }
};
