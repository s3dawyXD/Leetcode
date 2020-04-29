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
    int maxPathSum(TreeNode* root) {
        int temp = maxsum(root);
        return max(ans,temp);
    }
    int maxsum(TreeNode* root){
        if(root == NULL) return 0;
        int left = maxsum(root->left);
        int right = maxsum(root->right);
        int value = root->val;
        ans = max({left+value,right+value,left+right+value,ans});
        //cout<<left<<", "<<right<<endl;
        return max({left+value,right+value,value}); 
        
    }
};