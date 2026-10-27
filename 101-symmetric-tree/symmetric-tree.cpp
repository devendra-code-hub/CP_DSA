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
    bool f(TreeNode* a, TreeNode* b){
        if(a==NULL && b==NULL) return true;
        if((a==NULL && b!=NULL) || (a!=NULL && b==NULL) || (a->val != b->val)) return false;
        bool l=f(a->left, b->right);
        bool r=f(a->right, b->left);
        return l&&r;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return f(root->left, root->right);
    }
};