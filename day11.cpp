class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;    
        sort(citations.begin(),citations.end());
        int cnt = 1;
        for(int i = n-1 ; i >= 0 ; i-- )
        {
            
            if(citations[i] < cnt) break;
            cnt++;
           
        }
        return cnt-1;
    }
};
