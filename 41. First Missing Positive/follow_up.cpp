/**
 * @file follow_up.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-04
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 4 ms, faster than 67.26% of C++ online submissions for First Missing Positive.
 * Memory Usage: 9.7 MB, less than 74.51% of C++ online submissions for First Missing Positive.
 * 
 * Time complexity : O(n)
 * Space complexity : O(n)
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int firstMissingPositive(vector<int> &nums) {
        int size = nums.size();
        vector<bool> check(size + 1);

        for (int i = 0; i < size; i++) {
            if (0 < nums[i] && nums[i] <= size) {
                check[nums[i]] = true;
            }
        }

        int i;
        for (i = 1; i < check.size(); i++) {
            if (!check[i]) break;
        }
        return i;
    }
};

int main() {
    Solution s;
    vector<int> nums = {};
    printf("answer = %d\n", s.firstMissingPositive(nums));

    return 0;
}