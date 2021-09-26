/**
 * @file bfs.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-09-26
 * @copyright Copyright (c) 2021
 *
 * Runtime: 20 ms, faster than 77.06% of C++ online submissions for Course
 * Schedule II. Memory Usage: 13.3 MB, less than 91.36% of C++ online
 * submissions for Course Schedule II.
 *
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> answer;
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> graph(numCourses);

    for (auto& pre : prerequisites) {
      graph[pre[1]].push_back(pre[0]);
      ++indegree[pre[0]];
    }

    queue<int> queue;
    for (int i = 0; i < indegree.size(); ++i) {
      if (indegree[i] == 0) queue.push(i);
    }

    while (!queue.empty()) {
      int cur = queue.front();
      queue.pop();
      answer.push_back(cur);

      for (auto& next : graph[cur]) {
        indegree[next]--;
        if (indegree[next] == 0) queue.push(next);
      }
    }

    if (answer.size() == numCourses) {
      return answer;
    } else {
      return {};
    }
  }
};

int main() {
  vector<vector<int>> prerequisites = {};
  int numCourses = 2;
  Solution s;
  s.findOrder(numCourses, prerequisites);
  return 0;
}