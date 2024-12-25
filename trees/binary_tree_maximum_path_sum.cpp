#include <climits>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    int final_sum;
public:
    int maxPathSum(TreeNode* root) {
        final_sum = INT_MIN;
        dfs(root);
        return final_sum;
    }

private:
    int dfs(TreeNode* node) {
        if (node == nullptr) {return 0;}

        int result = INT_MIN;
        int went_left = node->val;
        int went_right = node->val;

        if (node->left != nullptr) {
            went_left += dfs(node->left);
        }

        if (node->right != nullptr) {
            went_right += dfs(node->right);
        }

        result = max(went_left, result);
        result = max(went_right, result);
        result = max(node->val, result);

        final_sum = max(final_sum, result);
        final_sum = max(final_sum, went_left + went_right - node->val);

        return result;
    }
};