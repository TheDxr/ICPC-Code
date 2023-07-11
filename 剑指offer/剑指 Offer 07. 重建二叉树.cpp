//浪费空间写法
class Solution {
public:
    TreeNode* buildTree(const vector<int>& preorder,const vector<int>& inorder) {
        if(preorder.size() == 0)return nullptr;
        int idx1 = 0;
        int idx2 = 0;
        TreeNode* root = new TreeNode(preorder[idx1]);
        for(int i = 0;i < inorder.size();i++) {
            if(root->val == inorder[i]) {
                idx2 = i;
            }
        }
        root->left = buildTree(vector<int>(preorder.begin() + 1,preorder.begin() + 1 + idx2),
                            vector<int>(inorder.begin(),inorder.begin() + idx2));
        root->right = buildTree(vector<int>(preorder.begin() + idx2 + 1,preorder.end()),
                                vector<int>(inorder.begin()+idx2+1,inorder.end()));
        return root;
    }   
};
// TODO: 优化空间写法