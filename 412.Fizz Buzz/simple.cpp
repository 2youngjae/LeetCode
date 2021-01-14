#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> answer;
        for (int i = 1; i <= n; ++i)
        {
            if (i % 3 == 0)
            {
                if (i % 5 == 0)
                {
                    answer.push_back("FizzBuzz");
                }
                else
                {
                    answer.push_back("Fizz");
                }
            }
            else if (i % 5 == 0)
            {
                answer.push_back("Buzz");
            }
            else
            {
                answer.push_back(to_string(i));
            }
        }
        return answer;
    }
};

int main()
{
    int n = 15;
    vector<string> v = Solution().fizzBuzz(n);
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i];
    }
    return 0;
}
