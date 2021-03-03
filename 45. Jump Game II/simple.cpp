/**
 * @file simple.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 16 ms, faster than 66.64% of C++ online submissions for Jump Game II.
 * Memory Usage: 15.5 MB, less than 74.78% of C++ online submissions for Jump Game II.
 * 
 * Time complexity : O(n)
 * Space complexity : O(1)
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;

        int cnt = 1;
        int i = 0;
        while (true)
        {
            if (i + nums[i] >= nums.size() - 1)
                return cnt;
            int max_idx = 0;
            int max_val = 0;
            for (int j = 1; j <= nums[i]; j++)
            {
                int next = i + j;
                if (j + nums[next] >= max_val)
                {
                    max_val = j + nums[next];
                    max_idx = next;
                }
            }
            i = max_idx;
            cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0};
    printf("answer = %d\n", s.jump(nums));
    return 0;
}