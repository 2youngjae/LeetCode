/**
 * @file set.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-04
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Missing Positive.
 * Memory Usage: 10 MB, less than 34.42% of C++ online submissions for First Missing Positive.
 * 
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
   public:
    int firstMissingPositive(vector<int> &nums) {
        set<int> s;

        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > 0) s.insert(nums[i]);
        }

        int num = 1;
        for(set<int>::iterator iter = s.begin(); iter != s.end() ; iter++){
            if (num != *iter) break;
            ++num;
        }
        return num;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1};
    printf("answer = %d\n", s.firstMissingPositive(nums));

    return 0;
}