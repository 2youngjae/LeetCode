/**
 * @brief 
 * Runtime: 16 ms, faster than 98.81% of C++ online submissions for Single Number.
 * Memory Usage: 16.7 MB, less than 99.74% of C++ online submissions for Single Number.
 * 
 * XOR 연산의 성질을 이용하여 간단하게 답을 구할수 있다.
 */

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int answer = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            answer ^= nums[i];
        }
        return answer;
    }
};
