#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int getMaximalRectangle(vector<vector<char>> &matrix, int r, int c)
    {
        int answer = 0;
        int cMax = -1;
        printf("r = %d, c = %d matrix[r][c] = %d\n", r, c, matrix[r][c]-'0');
        for (int i = r; i < matrix.size(); i++)
        {
            if (matrix[i][c] == '0')
                break;
            int j = c;
            for (; j < matrix[0].size(); j++)
            {
                if (cMax != -1 && j >= cMax)
                    break;
                if (matrix[i][j] == '0'){
                    cMax = min(cMax, j);
                    break;
                }
                int rect = (i - r + 1) * (j - c + 1);
                answer = max(answer, rect);
                printf("i = %d, j = %d, rect = %d, cMax = %d\n", i, j, rect, cMax);
            }
            if (cMax == -1)
                cMax = j;
        }
        return answer;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int answer = 0;
        if (matrix.size() != 0)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    answer = max(answer, getMaximalRectangle(matrix, i, j));
                }
            }
        }
        return answer;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix = {{'1', '0', '1', '1', '1'},
                                   {'0', '1', '0', '1', '0'},
                                   {'1', '1', '0', '1', '1'},
                                   {'1', '1', '0', '1', '1'},
                                   {'0', '1', '1', '1', '1'}};

    printf("maximal rect = %d\n", s.maximalRectangle(matrix));
    return 0;
}