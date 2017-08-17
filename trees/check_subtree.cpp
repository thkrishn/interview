class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL)
            return false;

        if (tree_match(s,t))
            return true;

        else
            return isSubtree(s->left,t) || isSubtree(s->right,t);
    }

    bool tree_match(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL)
            return true;

        if (s == NULL || t == NULL)
            return false;

        else
            return (s->val == t->val) &&
                tree_match(s->left, t->left) &&
                tree_match(s->right, t->right);
    }
};
