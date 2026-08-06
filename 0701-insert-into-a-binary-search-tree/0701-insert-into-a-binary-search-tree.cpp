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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        TreeNode* curr=root;
        TreeNode* prev=root;
        while(curr){
            if(curr->val<val){
                prev=curr;
                curr=prev->right;
            }
            else{
                prev=curr;
                curr=prev->left;
            }
        }
        TreeNode* node = new TreeNode(val);
        if(prev->val<val) prev->right=node;
        else prev->left=node;
        return root;
    }
};