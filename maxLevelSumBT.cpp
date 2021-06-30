static int sum;
class Solution {
public:
    int height(TreeNode* node) {
        if(node==NULL)
            return 0;
        int lheight = height(node->left);
        int rheight = height(node->right);
        if(lheight>rheight)
            return lheight+1;
        else
            return rheight+1;
    }
    void sumCurrentLevel(TreeNode* root, int level) {
        if(root==NULL)
            return ;
        if(level==1) {
            sum += root->val;
            cout<< root->val << " ";
        }

        else if(level>1) {
            sumCurrentLevel(root->left, level-1);
            sumCurrentLevel(root->right, level-1);
        }
    }
    int maxLevelSum(TreeNode* root) {
        int h = height(root);
        cout<< "height: "<<h<<endl;
        int i, max = INT_MIN, currSum=0, pos;
        for (i=1;i<=h;i++) {
            sum = 0;
            cout<<endl<< "level "<<i<< " sum = "<<sum<<endl;
            sumCurrentLevel(root, i);
            cout<<endl<< "sum = "<<sum<<endl;
            cout<<endl<< "max = "<<max<<endl;
            if (sum>max){
                max = sum;
                pos = i;
            }

        }
        return pos;
    }
};
