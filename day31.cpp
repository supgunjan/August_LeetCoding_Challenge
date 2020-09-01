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
    TreeNode* findmin(TreeNode* r){
        while(r && r->left){
            r = r->left;
        }
        return r;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            if( !root->right ){
                TreeNode* tmp = root->left;
                delete(root);
                return tmp;
            }
            else if( !root->left ){
                TreeNode* tmp = root->right;
                delete(root);
                return tmp;
            }
            
            TreeNode *tmp = findmin(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right,tmp->val);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        return root;
        
    }
};
