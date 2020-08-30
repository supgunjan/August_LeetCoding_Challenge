class Solution {
    vector<int> left;
    map<int, int> mp;
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {        
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            vector<int> interval = intervals[i];
            left.push_back(interval[0]);
            mp[interval[0]] = i;
        }        
 
        sort(left.begin(), left.end());
 
        vector<int> res;
 
        for(int i = 0; i < n; i++){
            vector<int> interval = intervals[i];
            int l = interval[0];
            int r = interval[1];
            int idx = lower_bound(left.begin(), left.end(), r) - left.begin();
            if(idx != n){
                res.push_back(mp[left[idx]]);
            }else{
                res.push_back(-1);
            }
        }
 
        return res;
    }
};
