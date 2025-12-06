// Diameter of Tree
// Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

#include <bits/stdc++.h>
using namespace std;

int solve(Node* root , int &res){
    if(root->val == NULL) return 0;

    int l = solve(root->left,res);
    int r = solve(root->right, res);

    int tempAns = 1 + max(l,r);
    int ans = max(tempAns,1+r+l);

    res = max(res, ans);

    return tempAns;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //Need To declare Tree and the pass the root

    int res = INT_MIN;
    solve(root,res);
    cout << res;

    return 0;
}
