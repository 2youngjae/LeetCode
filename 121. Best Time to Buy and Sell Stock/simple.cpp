/**
 * @file simple.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-02
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 168 ms, faster than 9.69% of C++ online submissions for Best Time to Buy and Sell Stock.
 * Memory Usage: 93.2 MB, less than 31.61% of C++ online submissions for Best Time to Buy and Sell Stock.
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int answer = 0;
        if (prices.size() >= 2)
        {
            int m = prices[0];
            for (int i = 1; i < prices.size(); ++i)
            {
                if(prices[i] > m){
                    answer = max(answer, prices[i] - m);
                } else {
                    m = prices[i];
                }
            }
        }
        return answer;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2};
    printf("%d\n", s.maxProfit(v));
    return 0;
}