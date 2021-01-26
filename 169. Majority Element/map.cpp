/**
 * @file map.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-26
 * 
 * Runtime: 20 ms, faster than 91.20% of C++ online submissions for Majority Element.
 * Memory Usage: 19.6 MB, less than 95.14% of C++ online submissions for Majority Element.
 * 
 */



#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0 ; i < nums.size();i++){
            if(m.count(nums[i])){
                m[nums[i]] += 1;
            } else {
                m[nums[i]] =1;
            }
        }

        int max_val = 0;
        int max_count = 0;
        for(map<int, int>::iterator iter = m.begin(); iter != m.end() ; iter++){
            if(iter->second > max_count){
                max_count = iter->second;
                max_val = iter->first;
            }
        }

        return max_val;
    }
};

int main(){

    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    printf("%d\n", s.majorityElement(nums));

    return 0;
}