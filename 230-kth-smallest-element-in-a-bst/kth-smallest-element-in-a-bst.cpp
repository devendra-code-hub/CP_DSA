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
    vector<int>  inorder(TreeNode* root, vector<int>& v){
        
        queue<TreeNode*>q;
        q.push(root);
         while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();
            if(frontNode){
            v.push_back(frontNode->val);
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
            }
         }
        return v;
    }
public:
   int kthSmallest(TreeNode* root, int k) {
         if(root== NULL ) return 0;
         vector<int>v;
         inorder(root, v);
         sort(v.begin(), v.end());

        return v[k-1];
    }
};