// Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/?envType=problem-list-v2&envId=dynamic-programming



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

    int solve(TreeNode* root, int &res){
        if(root == NULL) return 0;

        int l = solve(root->left,res);
        int r = solve(root->right,res);

        int tempAns = max(max(r,l)+root->val,root->val);
        int ans = max(tempAns,l+r+root->val);

        res = max(ans,res);

        return tempAns;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};