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
// search in inorder
int search(vector<int>&inorder, int rootVal, int left, int right){
    for(int i=left; i<=right; i++){
        if(inorder[i] == rootVal) return i;
    }
    return -1;
}
 // BuildRecur
 TreeNode* buildRecur(vector<int>&inorder, vector<int>&postorder, int & postidx, int left, int right){
    if(left>right) return NULL;
    int rootVal = postorder[postidx];
    postidx--;
    TreeNode* root = new TreeNode(rootVal);
    if(left == right) return root;
    int index = search(inorder, rootVal, left, right);

    root->right = buildRecur(inorder, postorder, postidx, index+1, right);
    root->left = buildRecur(inorder, postorder, postidx, left, index-1);

    return root;
 }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int n = inorder.size();
         int postidx = n-1;
         TreeNode* root = buildRecur(inorder, postorder, postidx, 0, n-1);
         return root;
    }
};