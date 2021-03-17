/**
 * @file sort.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-17
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 8 ms, faster than 83.62% of C++ online submissions for Kth Largest Element in an Array.
 * Memory Usage: 9.9 MB, less than 97.31% of C++ online submissions for Kth Largest Element in an Array.
 * 
 * Time complexity : O(nlogn)
 * Space complexity : O(n)
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[k - 1];
    }
};

int main() {
    return 0;
}