struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        res.clear();
        dfs(root);
        return res;
    }
private:
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }


        if (node->left != nullptr) {
            dfs(node->left);
        }

        res.push_back(node->val);

        if (node->right != nullptr) {
            dfs(node->right);
        }
    }
};