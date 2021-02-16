#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> answer;

    bool contains(vector<int> &v, int data)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == data)
                return true;
        }
        return false;
    }

    void dfs(vector<int> &nums, vector<int> &v)
    {
        for(int i = 0 ; i < v.size();i++){
            printf("%d ", v[i]);
        }
        printf("\n");

        if (v.size() == nums.size())
        {
            answer.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!contains(v, nums[i]))
            {
                v.push_back(nums[i]);
                dfs(nums, v);
                v.erase(v.end());
            }
        }

        for(int i = 0 ; i < answer.size();i++){
            printf("[");
            for(int j = 0 ; j < answer[i].size(); j++){
                printf("%d, ", answer[i][j]);
            }
            printf("]\n");
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        printf("permute()\n");
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            printf("permute %d\n", nums[i]);
            dfs(nums, v);
        }

        return answer;
    }
};

int main()
{
    printf("start\n");
    Solution s;
    vector<int> v = {1, 2, 3};
    s.permute(v);
    return 0;
}