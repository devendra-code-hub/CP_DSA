/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void findNodes(TreeNode *root, int dis, vector<int> &ans) {

    // base case
    if (root == nullptr)
        return;

    if (dis == 0) {
        ans.push_back(root->val);
        return;
    }

    findNodes(root->left, dis - 1, ans);
    findNodes(root->right, dis - 1, ans);
}

// Function which returns the distance of a node
// target node. Returns -1 if target is not found.
int kDistanceRecur(TreeNode *root, TreeNode* target, int k, vector<int> &ans) {

    // base case
    if (root == nullptr)
        return -1;

    // If current node is target
    if (root == target) {

        // Find nodes at distance k from
        // target node in subtree.
        findNodes(root, k, ans);

        return 1;
    }

    int left = kDistanceRecur(root->left, target, k, ans);

    // If target node is found in left
    // subtree, find all nodes at distance
    // k-left in right subtree.
    if (left != -1) {
        if (k - left == 0)
            ans.push_back(root->val);
        else
            findNodes(root->right, k - left - 1, ans);
        return left + 1;
    }

    int right = kDistanceRecur(root->right, target, k, ans);

    // If target node is found in right
    // subtree, find all nodes at distance
    // k-right in left subtree.
    if (right != -1) {
        if (k - right == 0)
            ans.push_back(root->val);
        else
            findNodes(root->left, k - right - 1, ans);
        return right + 1;
    }

    // If target node is not found
    // return -1
    return -1;
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        kDistanceRecur(root, target, k, ans);

    // sort the result
    sort(ans.begin(), ans.end());

    return ans;
    }
};