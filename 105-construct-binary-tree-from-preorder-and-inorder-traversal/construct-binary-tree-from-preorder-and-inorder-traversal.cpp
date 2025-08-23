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
// search idx in inorder
int search(vector<int>&inorder, int rootVal, int left, int right){
    for(int i=left; i<=right; i++){
        if(inorder[i] == rootVal) return i;
    }
    return -1;
}
// buildTree
TreeNode* buildTree(vector<int>&inorder, vector<int>&preorder, int & preIdx, int left, int right){
    if(left>right) return NULL;
    int rootVal = preorder[preIdx];
    preIdx++;
    TreeNode* root = new TreeNode(rootVal);
    int index = search(inorder, rootVal, left, right);
    root->left = buildTree(inorder, preorder, preIdx, left, index-1);
    root->right = buildTree(inorder, preorder, preIdx, index+1, right);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // create fuction calll
        int preIdx = 0;
        TreeNode* root = buildTree(inorder, preorder, preIdx, 0, preorder.size()-1);
        return root;
    }
};