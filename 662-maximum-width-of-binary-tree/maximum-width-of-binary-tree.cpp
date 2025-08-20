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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        long long res = 0;
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});
        while(!q.empty()){
            long long n = q.size();
            long long start_idx = q.front().second;
            long long end_idx = 0;

            for(int i=0; i<n; i++){
               pair<TreeNode*,long long> it = q.front();
                q.pop(); 
                TreeNode* node = it.first;
              long long idx = it.second;
              long long normalized_idx = idx -  start_idx;
                if( i == n-1 ) end_idx = idx;
                if(node->left) q.push({node->left, 2*normalized_idx + 1});
                if(node->right) q.push({node->right, 2*normalized_idx + 2});
            }
            res = max(res, end_idx - start_idx +1);
            
             
        }
        return res;
    }
};