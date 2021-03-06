#include"TreeNode.h"
using namespace std;

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n) return generate(1, n);
        else return vector<TreeNode *>{};
    }
    
    vector<TreeNode *> generate(int left, int right) {
        vector<TreeNode *> ans;
        if (left > right) {
            ans.push_back(nullptr);
            return ans;
        }
        for (int i = left; i <= right; i++) {
            vector<TreeNode *> left_nodes = generate(left, i - 1);
            vector<TreeNode *> right_nodes = generate(i + 1, right);
            for (TreeNode *left_node : left_nodes) {
                for (TreeNode *right_node : right_nodes) {
                    TreeNode *t = new TreeNode(i);
                    t->left = left_node;
                    t->right = right_node;
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};

int main(void){
    Solution solution;
}