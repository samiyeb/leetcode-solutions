struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <queue>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {return {};}

        queue<TreeNode*> q;
        vector<int> result;
        q.push(root);

        while (q.size() > 0) {
            int size = q.size();
            int curr_max = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                curr_max = max(curr_max, node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            result.push_back(curr_max);
        }

        return result;
        
    }
};