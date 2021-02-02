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