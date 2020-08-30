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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*,char>> q;
        int cnt = 0;
        q.push(make_pair(root,'m'));
        while(!q.empty()){
            pair<TreeNode*,char> p = q.front();
            q.pop();
            if(p.first->left){
                q.push(make_pair(p.first->left,'l'));
            }
            if(p.first->right){
                q.push(make_pair(p.first->right,'r'));
            }
            if(p.second == 'l' && p.first->left == NULL && p.first->right == NULL)
                cnt += p.first->val;
        }
        return cnt;
    }
};
