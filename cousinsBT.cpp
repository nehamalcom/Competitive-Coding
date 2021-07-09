```
// note: these static variables were declared outside the class Solution
static bool found_x;
static bool found_y;
static int parent_x;
static int parent_y;

// START
    // we calculate the height of the tree so that we can perform breadth first search (BFS)
int height(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    if(lheight>rheight)
        return lheight+1;
    else
        return rheight+1;
}
// here we are simultaneously checking each node we encounter and also tracking the current node's parent
void bfs(TreeNode* node, int level, int target1, int target2, int parent) {
    if(node == NULL) {
        return;
    }
    if(level==1){
        cout<<node->val<<endl;
        if(node->val == target1) {
            found_x = true;
            parent_x = parent;
        }
        if(node->val == target2) {
            found_y = true;
            parent_y = parent;
        }
    }
    bfs(node->left, level-1, target1, target2, node->val);
    bfs(node->right, level-1, target1, target2, node->val);
}
bool isCousins(TreeNode* root, int x, int y) {
    int ht, x_height, y_height;
    ht = height(root);
	// for each level we are checking whether the two conditions are true
    for(int i=0; i<=ht; i++) {
        found_x = false;
        found_y = false;
        bfs(root, i, x, y, -1);
        if( (found_x) && (found_y) ) {
            if(parent_x!=parent_y)
                return true;
            else
                return false;
        }
		// if one is found at a certain level and the other is not, we automatically return false
        if(found_x)
            return false;
        if(found_y)
            return false;
    }
    return false;

}
