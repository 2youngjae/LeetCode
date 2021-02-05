/**
 * @file simple.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-05
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 4 ms, faster than 98.85% of C++ online submissions for Find the Duplicate Number.
 * Memory Usage: 11.1 MB, less than 74.16% of C++ online submissions for Find the Duplicate Number.
 * 
 * Time complexity : O(n)
 * Space complexity : O(n)
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int answer = 0;
        vector<bool> check(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (check[nums[i]])
            {
                answer = nums[i];
                break;
            }
            check[nums[i]] = true;
        }
        return answer;
    }
};

int main()
{
    Solution s;
    vector<int> v = {3, 1, 3, 4, 2};
    printf("%d\n", s.findDuplicate(v));
    return 0;
}