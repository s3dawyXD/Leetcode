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
    int n ;
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        n = arr.size();
        return dfs(root,0,arr);
    }
    bool dfs(TreeNode* root,int depth,vector<int>& arr){
        if(root == NULL|| depth>=n ) return false;
        if(root->val != arr[depth]) return false;
        if(root->left == NULL && root->right == NULL)return depth==n-1;
        return dfs(root->left,depth+1,arr)||dfs(root->right,depth+1,arr);
    }
};