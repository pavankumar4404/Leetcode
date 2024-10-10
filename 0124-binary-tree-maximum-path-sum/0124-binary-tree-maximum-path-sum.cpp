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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        int sum1 = root->val + leftSum + rightSum;
        int sum2 = root->val + max(leftSum, rightSum);
        int sum3 = root->val;
        int bestSum = max({sum1, sum2, sum3});

        ans = max(ans, bestSum);
        return max(sum2, sum3);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};