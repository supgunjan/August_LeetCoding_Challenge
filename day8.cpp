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
    int ans = 0;
     void solve(TreeNode* r,int sm, int cnt)
    {
        if(cnt == sm)
        {
            ans++;
        }
        if(r == NULL) return ;
         
         if(r->left)
         {
             solve(r->left,sm,cnt + r->left->val);
         }
        if(r->right)
         {
             solve(r->right,sm,cnt + r->right->val);
         }
        
    }
    
    void bfs(TreeNode *root, int sm)
    {
        if(root == NULL) return ;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            
            solve(tmp,sm,tmp->val);
            
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
    }
        
    
    int pathSum(TreeNode* root, int sum) {
        bfs(root,sum);
        return ans;
    }
};
