/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static bool comp(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.first == p2.first)
        {
             return p1.second < p2.second;
        }
        return p1.first < p2.first;
        
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};
        map<int,vector<pair<int,int>>> m;
        
        int pos = 0;
        int lvl = 0;
        queue<pair<int,pair<int,TreeNode*>>> q;
        q.push(make_pair(lvl,make_pair(pos,root)));
        
        while(!q.empty())
        {
            pair<int,pair<int,TreeNode*>> p = q.front();
            q.pop();
            pos = p.second.first;
            lvl = p.first;
            m[pos].push_back(make_pair(lvl,(p.second.second)->val));
            
            if((p.second.second)->left) q.push(make_pair(lvl+1,make_pair(pos-1,(p.second.second)->left)));
            if((p.second.second)->right) q.push(make_pair(lvl+1,make_pair(pos+1,(p.second.second)->right)));
        }
   
        vector<vector<int>> res;
        for(auto i : m)
        {
            sort(i.second.begin(),i.second.end(),comp);
            vector<int> tmp;
            for(auto j: i.second)
            {
                tmp.push_back(j.second);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
