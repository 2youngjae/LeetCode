/**
 * @file multiset.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-19
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 556 ms, faster than 21.92% of C++ online submissions for Sliding Window Maximum.
 * Memory Usage: 185.6 MB, less than 8.52% of C++ online submissions for Sliding Window Maximum.
 * 
 * Time complexity : O(nlogk)
 * Space complexity : O(k)
 * 
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> answer;
        multiset<int> ms;

        for (int i = 0; i < nums.size(); i++)
        {
            ms.insert(nums[i]);
            if (ms.size() == k)
            {
                answer.push_back(*(--ms.end()));
                ms.erase(ms.lower_bound(nums[i - k + 1]));
            }
        }
        return answer;
    }
};

int main()
{

    multiset<int> ms;

    return 0;
}