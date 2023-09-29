#include <iostream>
#include <string>
#include <stack>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
	  TreeNode* tmp;
      if (root != nullptr) {
          tmp = root->right;
          root->right = invertTree(root->left);
          root->left = invertTree(tmp);
      }
      return root; 
    }
};

int main() {
  Solution sol;
  sol.invertTree();
  return 0;
}
