/**
 * @file simple.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-27
 * 
 * Runtime: 8 ms, faster than 57.86% of C++ online submissions for Move Zeroes.
 * Memory Usage: 9.1 MB, less than 77.26% of C++ online submissions for Move Zeroes.
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void printAll(vector<int> &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
    }

    void moveZeroes(vector<int> &nums)
    {
        int num_idx = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != 0){
                nums[num_idx] = nums[i];
                if(num_idx != i) nums[i] = 0;
                ++num_idx;
            }
        }
    }
};

int main()
{
    vector<int> v = {0,1,0,1,1};
    Solution s;
    s.moveZeroes(v);
    s.printAll(v);
    return 0;
}