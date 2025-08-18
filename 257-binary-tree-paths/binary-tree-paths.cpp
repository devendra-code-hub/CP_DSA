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
void allpaths(TreeNode* root, string s,  vector<string>&paths){
       if(root == NULL) return ;
       
       s+=to_string(root->val);
       
       if(root->left == NULL && root->right == NULL) paths.push_back(s);
       else{
        s+= "->";
           allpaths(root->left, s, paths);
           allpaths(root->right, s, paths);
       }
       
       s.pop_back();
       
   }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;
         string s;
        allpaths(root,"", paths);
        
        return paths;
    }
};