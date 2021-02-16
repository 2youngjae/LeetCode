#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> answer;
        vector<int> check(nums.size() + 1);

        for (int i = 0; i < nums.size(); ++i)
        {
            check[nums[i]] = 1;
        }

        for(int i = 1 ; i <= nums.size(); ++i){
            if(!check[i]) answer.push_back(i);
        }

        return answer;
    }
};

int main()
{
    vector<int> v = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution s;
    s.findDisappearedNumbers(v);

    return 0;
}