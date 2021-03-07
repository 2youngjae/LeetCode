/**
 * @file stack.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-07
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 100 ms, faster than 49.62% of C++ online submissions for Largest Rectangle in Histogram.
 * Memory Usage: 61.6 MB, less than 42.13% of C++ online submissions for Largest Rectangle in Histogram.
 * 
 * Time complexity : O(n)
 * Space complexity : O(n)
 */

#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    int largestRectangleArea(vector<int> &heights) {
        if (heights.size() == 0) {
            return 0;
        } else if (heights.size() == 1) {
            return heights[0];
        }

        int answer = 0;
        stack<int> s;

        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int top = s.top();
                s.pop();
                if (s.empty()) {
                    answer = max(answer, heights[top] * i);
                } else {
                    answer = max(answer, heights[top] * (i - s.top() - 1));
                }
            }
            s.push(i);
        }

        while (!s.empty()) {
            int top = s.top();
            s.pop();
            int val;
            if (s.empty()) {
                val = heights[top] * heights.size();
            } else {
                val = heights[top] * (heights.size() - s.top() - 1);
            }
            answer = max(answer, val);
        }

        return answer;
    }
};

int main() {
    vector<int> heights = {4, 2};
    Solution s;
    printf("answer = %d\n", s.largestRectangleArea(heights));
    return 0;
}