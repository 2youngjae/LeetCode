/**
 * @file bruteforce.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-01
 * @copyright Copyright (c) 2021
 * Runtime: 88 ms, faster than 13.51% of C++ online submissions for Maximal Rectangle.
 * Memory Usage: 10.8 MB, less than 98.71% of C++ online submissions for Maximal Rectangle.
 * 
 * Constraints:
 * rows == matrix.length
 * cols == matrix.length
 * 0 <= rows, cols <= 200
 * matrix[i][j] is '0' or '1'.
 * 
 * Time complexity : O(rows^2 * cols^2) - 2차원 배열의 모든 원소에서 각각 rows*cols번 계산 하므로 시간복잡도는 O((rows*cols) * (rows*cols))
 * Space complexity : O(rows * cols) - 주어진 matrix의 공간만 사용하므로 O(rows * cols)
 * 
 */

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