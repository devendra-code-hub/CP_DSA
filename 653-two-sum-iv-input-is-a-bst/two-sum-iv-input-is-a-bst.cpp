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
    void inorder(TreeNode* root, vector<int>&v){
        if(root== NULL) return ;
        if(root){
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        
        vector<int>v;
        inorder(root, v);
        if(v.size() == 1 && root->val != k) return false;
        for(auto it: v){
            if(find(v.begin(), v.end(), (k-it)) != v.end() && it != (k-it)) return true;
        }

        return false;
    }
};