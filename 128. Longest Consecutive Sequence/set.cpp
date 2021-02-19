/**
 * @file set.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-19
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 8 ms, faster than 91.17% of C++ online submissions for Longest Consecutive Sequence.
 * Memory Usage: 11 MB, less than 44.58% of C++ online submissions for Longest Consecutive Sequence.
 * 
 * Time complexity : O(nlogn)
 * Space complexity : O(n)
 * 
 */

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        else if (nums.size() == 1)
        {
            return 1;
        }

        int answer = 1;
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int cnt = 1;
        for (set<int>::iterator iter = next(s.begin()); iter != s.end(); iter++)
        {
            if (*iter == *prev(iter) + 1)
            {
                cnt++;
                answer = max(answer, cnt);
            }
            else
            {
                cnt = 1;
            }
        }
        return answer;
    }
};

int main()
{
    vector<int> nums = {0, 0};
    Solution s;
    printf("answer = %d\n", s.longestConsecutive(nums));
    return 0;
}