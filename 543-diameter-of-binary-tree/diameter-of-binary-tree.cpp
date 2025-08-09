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
    private:
    
    pair<int,int> diameter(TreeNode* root){
        if(root == NULL){
        pair<int,int>p =make_pair(0,0);
        return p;
        }
       // <diameter,height>
        pair<int,int> left = diameter(root->left);
        pair<int,int> right = diameter(root->right);
        int mx_left = left.first;
        int mx_right = right.first;
        int h = left.second + right.second;

        pair<int,int> ans;
        ans.first = max({mx_left, mx_right, h}); 
        ans.second =  max(left.second, right.second)+1; 
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};