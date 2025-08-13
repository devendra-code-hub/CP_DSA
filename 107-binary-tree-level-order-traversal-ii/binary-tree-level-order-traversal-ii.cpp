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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>result;
        if(root == NULL) return result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
         int level_size =q.size(); 
         vector<int>ans;

         for(int i=0; i<level_size; i++)  { 
            TreeNode* frontNode = q.front();
            q.pop();
            ans.push_back(frontNode->val);
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
         }
         result.push_back(ans);
        }

        reverse(result.begin(), result.end());
        
        return result;
    }
};