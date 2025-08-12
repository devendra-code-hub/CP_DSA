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
vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return ans;
         stack<TreeNode*>node;
         stack<int>value;
         node.push(root);
         value.push(root->val);
         while(!node.empty()){
            TreeNode* top = node.top();
            node.pop();
            ans.push_back(value.top());
            value.pop();

            if(top->right){
                node.push(top->right);
                value.push(top->right->val);
            }
            if(top->left){
                node.push(top->left);
                value.push(top->left->val);
            }
         }
        return ans;
    }
};