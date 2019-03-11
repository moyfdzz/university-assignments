/**
 * Definition for a binary search tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int heightHelper(TreeNode* r) {
    if (r == nullptr) {
        return 0;
    }

    int leftSubtreeHeight = heightHelper(r->left);
    int rightSubtreeHeight = heightHelper(r->right);

    return (leftSubtreeHeight > rightSubtreeHeight ? leftSubtreeHeight: rightSubtreeHeight) + 1;
}

int diameterOfBST(TreeNode* r) {
    if (r == nullptr) {
        return 0;
    }
        
    int diameter = heightHelper(r->left) + heightHelper(r->right);

    int leftDiameter = diameterOfBST(r->left);
    int rightDiameter = diameterOfBST(r->right);

    if (diameter > leftDiameter) {
        return (diameter > rightDiameter) ? diameter : rightDiameter; 
    } 
    else {
        return (leftDiameter > rightDiameter) ? leftDiameter : rightDiameter;
    }
}