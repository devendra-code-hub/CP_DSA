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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        // level,node->val
        map<int,int>mp;
        //Node,level
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*, int> it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int level = it.second;
            if(node->left == NULL && node->right == NULL){
               // mp[level] = node->val;
               return level+1;
            }
            if(node->left){
                q.push({node->left, level+1});
            }
            if(node->right){
                q.push({node->right, level+1});
            }
        }
        int ans = mp.begin()->first;

       // return ans+1;
       return 0;
    }
};