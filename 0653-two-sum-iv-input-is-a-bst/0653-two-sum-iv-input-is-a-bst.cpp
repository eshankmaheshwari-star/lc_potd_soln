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
vector<int> st;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        st.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode*curr= root;
        inorder(root);
        int l=0,r=st.size()-1;
        while(l<r){
            if(st[l]+st[r]==k) return true;
            else if(st[l]+st[r]<k) l++;
            else r--;
        }
        return false;
    }
};