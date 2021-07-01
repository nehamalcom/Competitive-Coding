/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
class Solution {
public:
    bool found;
    void Inorder(TreeNode* node, TreeNode* p, vector<TreeNode*> &anc, TreeNode* root)
    {
        if (node == NULL)
            return;
        if (found == true)
            return;
        Inorder(node->left,p,anc,root);
        if(node->val == p->val){
            found = true;
        }
        Inorder(node->right,p,anc,root);
        if(found == true) {
            anc.push_back(node);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_ancestors;
        vector<TreeNode*> q_ancestors;
        // traverse till p is found and log all nodes into p_ancestors
        found = false;
        Inorder(root, p, p_ancestors, root);
        found = false;
        Inorder(root, q, q_ancestors, root);
        for (int i=0; i<p_ancestors.size(); i++)
            for(int j=0; j<q_ancestors.size(); j++)
                if(p_ancestors[i]->val == q_ancestors[j]->val){
                    return p_ancestors[i];
                }
        return root;
    }
};
