/**
 * @file recursive.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief resolve with solution...
 * @version 0.1
 * @date 2021-10-10
 * @copyright Copyright (c) 2021
 *
 * Runtime: 40 ms, faster than 30.11% of C++ online submissions for Construct
 * Binary Tree from Preorder and Inorder Traversal. Memory Usage: 25.8 MB, less
 * than 92.76% of C++ online submissions for Construct Binary Tree from Preorder
 * and Inorder Traversal.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int rootIdx = 0;
    return build(preorder, inorder, rootIdx, 0, inorder.size() - 1);
  }

  TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx,
                  int left, int right) {
    if (left > right) return {};
    int pivot = left;  // find the root from inorder
    while (inorder[pivot] != preorder[rootIdx]) pivot++;

    rootIdx++;
    TreeNode* newNode = new TreeNode(inorder[pivot]);
    newNode->left = build(preorder, inorder, rootIdx, left, pivot - 1);
    newNode->right = build(preorder, inorder, rootIdx, pivot + 1, right);
    return newNode;
  }
};