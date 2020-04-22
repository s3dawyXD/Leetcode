/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// [8,5,1,7,10,12]

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty())return NULL;
        vector<int> greater, smaller;
        int value = preorder[0];
        for(int i = 1; i<preorder.size();i++)
        {
            if(value < preorder[i])
                greater.push_back(preorder[i]);
            else
                smaller.push_back(preorder[i]);
        }
        TreeNode* root = new TreeNode(value);
        root->left = bstFromPreorder(smaller);
        root->right = bstFromPreorder(greater);
        return root;
        
    }
    
};