/**
 * @file swap.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-28
 * 
 * Runtime: 80 ms, faster than 80.25% of C++ online submissions for Find All Numbers Disappeared in an Array.
 * Memory Usage: 33.6 MB, less than 97.28% of C++ online submissions for Find All Numbers Disappeared in an Array.
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    void swap(vector<int> &nums, int a, int b)
    {
        int tmp = nums[b];
        nums[b] = nums[a];
        nums[a] = tmp;
    }

    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> answer;
        for (int i = 0; i < nums.size(); ++i)
        {
            swap(nums, i, nums[i] - 1);
            int next = nums[i] - 1;
            while(true){
                if(nums[i] == i + 1 || nums[i] == nums[next]) break;
                swap(nums, i, next);
                next = nums[i] - 1;
            }
        }

        for(int i = 0 ; i < nums.size(); ++i){
            if(nums[i] != i + 1) answer.push_back(i + 1);
        }

        return answer;
    }
};

int main()
{
    vector<int> v = {2,3,4,5,6,7,8,1};

    Solution s;
    s.findDisappearedNumbers(v);

    return 0;
}