/**
 * @file simple.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-16
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 4 ms, faster than 94.34% of C++ online submissions for Counting Bits.
 * Memory Usage: 7.7 MB, less than 96.52% of C++ online submissions for Counting Bits.
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
    vector<int> countBits(int num)
    {
        vector<int> answer(num + 1);
        answer[0] = 0;
        int x = 0;
        for (int i = 1; i <= num; i++)
        {
            answer[i] = answer[i - (1 << x)] + 1;
            if (i == (1 << (x + 1)) - 1)
            {
                x += 1;
            }
        }
        return answer;
    }
};

int main()
{
    Solution s;
    s.countBits(16);
    return 0;
}