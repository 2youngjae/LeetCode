/**
 * @file bruteforce.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-07
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 120 ms, faster than 37.77% of C++ online submissions for Largest Rectangle in Histogram.
 * Memory Usage: 61.6 MB, less than 38.37% of C++ online submissions for Largest Rectangle in Histogram.
 * 
 * Time complexity : O(n^2)
 * Space complexity : O(n)
 */

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<bool> check;
    int search(vector<int>& heights, int idx) {
        int cnt = 0;
        for (int i = idx + 1; i < heights.size(); i++) {
            if (heights[idx] == heights[i]) {
                check[i] = true;
            }
            if (heights[idx] <= heights[i]) {
                cnt++;
            } else {
                break;
            }
        }
        for (int i = idx - 1; i >= 0; i--) {
            if (heights[idx] == heights[i]) {
                check[i] = true;
            }
            if (heights[idx] <= heights[i]) {
                cnt++;
            } else {
                break;
            }
        }
        return cnt + 1;
    }

   public:
    int largestRectangleArea(vector<int>& heights) {
        int answer = 0;
        check.resize(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            if (!check[i]) {
                answer = max(answer, search(heights, i) * heights[i]);
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    vector<int> heights = {1,1,1,1,1};
    printf("%d\n", s.largestRectangleArea(heights));
    return 0;
}