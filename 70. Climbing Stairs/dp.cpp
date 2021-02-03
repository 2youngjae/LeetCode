/**
 * @file dp.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-03
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
 * Memory Usage: 6.2 MB, less than 65.60% of C++ online submissions for Climbing Stairs.
 * 
 * Time complexity : O(n)
 * Space complexity: O(n)
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> d(n + 1);
        d[1] = 1;
        if (n > 1)
        {
            d[2] = 2;
            for (int i = 3; i <= n; ++i)
            {
                d[i] = d[i - 1] + d[i - 2];
            }
        }
        return d[n];
    }
};

int main()
{
    Solution s;
    printf("%d\n", s.climbStairs(1));
    return 0;
}