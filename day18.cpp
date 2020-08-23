class Solution {
public:
    
    void dfs(int N , int K, int curr, int i , int prev, vector<int> &res)
    {
        if(i >= N-1)
        {
            res.push_back(curr);
            return;
        }
        int next = prev+K;
        if(next < 10)
        {
            dfs( N , K , (curr*10) + next , i+1, next, res);
        }
        next = prev-K;
        if( K != 0 && next >= 0){
            dfs( N , K , (curr*10) + next , i+1 , next , res);
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
      vector<int> res;
      if(N  == 1) return {0,1,2,3,4,5,6,7,8,9};
        
      for(int i = 1 ; i <= 9 ; i++)
      {
          dfs(N,K,i,0,i,res);
      }
        return res;
    }
};
