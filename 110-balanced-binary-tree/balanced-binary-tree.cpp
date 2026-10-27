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
  int ch(TreeNode* root){
    if(root == NULL) return 0;
    int lh= ch(root->left);
    if(lh==-1) return -1;
    int rh = ch(root->right);
    if(rh == -1) return -1;
    if(abs(lh-rh)>1) return -1;

    return 1+max(lh,rh);
  }
//   int h(TreeNode* root){
//     if(root == NULL) return 0;
//     int l=h(root->left);
//     int r=h(root->right);

//     return 1+max(l,r);
//   }
    bool isBalanced(TreeNode* root) {

        return ch(root) !=-1;
        // if(root==NULL) return true;
        // int lh= h(root->left);
        // int rh= h(root->right);
        // if(abs(lh-rh)>1) return false;

        // return isBalanced(root->left) && isBalanced(root->right);
    }
};