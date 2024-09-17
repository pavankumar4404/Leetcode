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
    int solve(TreeNode* root, int &ans){
        if(!root) return 0;

        int l = solve(root->left, ans);
        int r = solve(root->right, ans);

        ans = max(ans, l + r + root->val); // 1. if ans is found in the subtree, no need to send upwards
        
        int sum = root->val + max(l, r); //2. any one from left or right is best
        ans = max(ans, max(sum, root->val));// 3. both l and r are -ve
        return max(root->val, sum);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};