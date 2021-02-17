/**
 * @file dp.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-17
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 132 ms, faster than 81.93% of C++ online submissions for Best Time to Buy and Sell Stock III.
 * Memory Usage: 81.5 MB, less than 33.17% of C++ online submissions for Best Time to Buy and Sell Stock III.
 * 
 * Time complexity : O(n)
 * Space complexity : O(2*n)
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
        int answer = 0;
        const int size = prices.size();
        vector<int> dlr(size);
        vector<int> drl(size);

        dlr[0] = 0;
        drl[size - 1] = 0;
        int min_val = prices[0];
        int max_val = prices[size - 1];
        for (int i = 1; i < size; i++)
        {
            dlr[i] = max(dlr[i - 1], (prices[i] - min_val));
            min_val = min(min_val, prices[i]);

            drl[size - i - 1] = max(drl[size - i], (max_val - prices[size - i]));
            max_val = max(max_val, prices[size - i]);
        }

        for (int i = 0; i < size; i++)
        {
            answer = max(answer, drl[i] + dlr[i]);
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