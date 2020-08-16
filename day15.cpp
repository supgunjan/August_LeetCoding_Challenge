class Solution {
public:
    static bool cmp(vector<int> v1,vector<int> v2)
    {
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        int cnt = 0;
    
        
        int end = intervals[0][0];
        
        for(int i = 0 ; i < n ; i++)
        {
            if(intervals[i][0] < end)
            {
                cnt++;
            }
            else
            {
                end = intervals[i][1];
            }
        }
        return cnt;
    }
};
