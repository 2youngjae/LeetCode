/**
 * @file multiset.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-08
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 24 ms, faster than 82.27% of C++ online submissions for Min Stack.
 * Memory Usage: 16.9 MB, less than 5.77% of C++ online submissions for Min Stack.
 * 
 * Time complexity : O(nlogn)
 * -stack의 push, pop, top : O(1)
 * -multiset의 push, pop(erase) : O(logn)
 * Space complexity : O(2*n)
 * -stack : O(n)
 * -multiset : O(n) 
 * 
 */

#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s;
    multiset<int> ms;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        ms.insert(x);
    }
    
    void pop() {
        ms.erase(ms.lower_bound(s.top()));
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return *ms.begin();
    }
};

int main(){
    MinStack ms;
    ms.push(0);
    ms.push(1);
    ms.push(0);
    printf("%d\n", ms.getMin());
    ms.pop();
    printf("%d\n", ms.getMin());

    return 0;
}