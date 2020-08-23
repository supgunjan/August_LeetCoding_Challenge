class Solution {
    vector<int> points_pre;
    vector<vector<int>> rects;
    int no_pts;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        no_pts = 0;
        for(auto r : rects){
            no_pts += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            points_pre.push_back(no_pts);
        }
    }
 
    vector<int> pick() {
        int picked_pt = rand() % no_pts;
        int idx = upper_bound(points_pre.begin(), points_pre.end(), picked_pt) - points_pre.begin();
 
        vector<int> rect = rects[idx];
        int width = rect[2] - rect[0] + 1;
        int height = rect[3] - rect[1] + 1;
        int points_rect = width * height;
        int st_point = points_pre[idx] - points_rect;
 
        return {rect[0] + (picked_pt - st_point) % width, rect[1] + (picked_pt - st_point) / width};
    }
};
