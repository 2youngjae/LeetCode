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
                printAll(nums);
            }
        }

        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] != i + 1) answer.push_back(i + 1);
        }

        printAll(answer);

        return answer;
    }

    void printAll(vector<int>& v){
        for(int i = 0 ; i < v.size();i++){
            printf("%d ", v[i]);
        }
        printf("\n");
    }
};

int main()
{
    vector<int> v = {2,3,4,5,6,7,8,1};

    Solution s;
    s.findDisappearedNumbers(v);

    return 0;
}