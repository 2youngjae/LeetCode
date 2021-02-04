#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        else {
            int answer = nums[0];
            if(nums[0] < 0) nums[0] = 0;
            for (int i = 1; i < nums.size(); ++i)
            {
                answer = max(answer, nums[i]);
                if (nums[i - 1] + nums[i] > 0)
                {
                    nums[i] = nums[i - 1] + nums[i];
                    answer = max(answer, nums[i]);
                }
                else
                {
                    nums[i] = 0;
                }
            }
            return answer;
        }
    }
};

int main()
{
    vector<int> nums = {-1,1,2,1};
    Solution s;
    printf("%d\n", s.maxSubArray(nums));
    return 0;
}