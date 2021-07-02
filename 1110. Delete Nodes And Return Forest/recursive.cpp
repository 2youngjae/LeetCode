/**
 * @file recursive.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-07-02
 * @copyright Copyright (c) 2021
 *
 * Runtime: 12 ms, faster than 99.23% of C++ online submissions for Delete Nodes
 * And Return Forest. Memory Usage: 25.2 MB, less than 76.88% of C++ online
 * submissions for Delete Nodes And Return Forest.
 *
 */

#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  void delNodes(TreeNode *&root, const set<int> &s,
                vector<TreeNode *> &answer) {
    if (!root) return;

    if (root->left) delNodes(root->left, s, answer);
    if (root->right) delNodes(root->right, s, answer);
    if (s.count(root->val)) {
      if (root->left) answer.push_back(root->left);
      if (root->right) answer.push_back(root->right);
      root = nullptr;
    }
  }

  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    vector<TreeNode *> answer;
    if (root) {
      set<int> s;
      for (auto &num : to_delete) {
        s.insert(num);
      }
      delNodes(root, s, answer);
      if (root) answer.push_back(root);
    }
    return answer;
  }
};

int main() { return 0; }