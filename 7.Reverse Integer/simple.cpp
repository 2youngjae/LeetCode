/*
Runtime: 4 ms, faster than 45.59% of C++ online submissions for Reverse Integer.
Memory Usage: 5.9 MB, less than 99.99% of C++ online submissions for Reverse Integer.

(-2^31) ~ (2^31-1) 범위만 잘 지켜주면 된다.
*/

#include <iostream>
using namespace std;

#define MAX 214748364
#define MIN -214748364

class Solution
{
public:
    int reverse(int x)
    {
        int answer = 0;
        while (x != 0)
        {
            if(answer > MAX || answer < MIN) return 0;
            answer *= 10;
            answer += (x % 10);
            x /= 10;
        }
        return answer;
    }
};
