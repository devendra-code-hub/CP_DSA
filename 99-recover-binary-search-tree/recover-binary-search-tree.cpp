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
    void inorder(TreeNode* root, vector<TreeNode*>&v){
        if(root == NULL) return ;
        if(root){
            inorder(root->left, v);
            v.push_back(root);
            inorder(root->right, v);
        }
    }
    // TreeNode* build(TreeNode* nroot, int key){
    //     if(nroot == NULL) return new TreeNode(key);
    //     if(nroot->val < key){
    //         nroot->right = build(nroot->right, key);
    //     }
    //     if(nroot->val > key){
    //         nroot->left = build(nroot->left, key);
    //     }
        
    //     return nroot;
    // }

public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>v;
        inorder(root, v);
        // TreeNode* nroot = NULL;
        // for(auto it : v)
        // nroot = build(nroot, it);


        vector<int>value;
       for(auto it : v) value.push_back(it->val);
      sort(value.begin(), value.end());

      for(int i=0; i<v.size(); i++){
        v[i]->val = value[i];
      }

    }
};