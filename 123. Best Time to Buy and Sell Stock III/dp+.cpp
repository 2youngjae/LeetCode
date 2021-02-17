/**
 * @file dp+.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-17
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 132 ms, faster than 81.93% of C++ online submissions for Best Time to Buy and Sell Stock III.
 * Memory Usage: 78.3 MB, less than 49.83% of C++ online submissions for Best Time to Buy and Sell Stock III.
 * 
 * * Time complexity : O(n)
 * Space complexity : O(n)
 * Idea : 
 * 최대 두번 사고 팔수 있다는 말은 특정지점 k 를 기준으로 구간 a(0 ~ k), b(k+1 ~ n)로 나눈후 a구간과 b구간의 합이 최대가 되도록 하면 된다.
 * ->a(0~k구간)의 최대값들을 dlr에 저장하고 b구간(k+1~n)의 최대값들을drl에 저장하여 dlr[i] + drl[i]의 최대값이 정답이 된다.
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
        const int size = prices.size();
        vector<int> d(size);

        d[0] = 0;
        int val = prices[0];
        for (int i = 1; i < size; ++i)
        {
            d[i] = max(d[i - 1], prices[i] - val);
            val = min(val, prices[i]);
        }

        val = prices[size - 1];
        int answer = d[size - 1];
        for (int i = size - 2; i >= 0; --i)
        {
            answer = max(answer, d[i] + val - prices[i]);
            val = max(val, prices[i]);
        }

        return answer;
    }
};

int main()
{
    vector<int> prices = {2, 1};
    Solution s;
    printf("maxProfit = %d\n", s.maxProfit(prices));

    return 0;
}