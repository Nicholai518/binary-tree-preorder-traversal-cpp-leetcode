#include <iostream>
#include <vector>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  class Solution 
  {
  public:
      vector<int> answer;
      vector<int> preorderTraversal(TreeNode* root) 
      {

          // if there is a val
          if (root != NULL)
          {
              // add value to answer vector
              answer.push_back(root->val);

              // traverse left
              preorderTraversal(root->left);

              // traverse right
              preorderTraversal(root->right);
          }

          return answer;
      }
  };

int main()
{
    Solution solution;

    TreeNode nine(9);
    TreeNode eight(8);
    TreeNode seven(7, &eight, &nine);

    TreeNode four(4, NULL, &seven);
    TreeNode two(2, &four, NULL);

    TreeNode six(6);
    TreeNode five(5);
    TreeNode three(3, &five, &six);

    TreeNode root(1, &two, &three);

    vector<int> answer = solution.preorderTraversal(&root);

    cout << "Example One : ";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

	return 0;
}