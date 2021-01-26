#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    stack<char> stack;
    bool isValid(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            }
            else {
                if (stack.empty()) return false;
                if (s[i] == ')') {
                    if (stack.top() != '(') return false;
                    stack.pop();
                }
                else if (s[i] == ']') {
                    if (stack.top() != '[') return false;
                    stack.pop();
                }
                else {
                    if (stack.top() != '{') return false;
                    stack.pop();
                }
            }
        }
        return stack.empty();
    }
};

int main() {
    string s = "()";
    printf("%d\n", Solution().isValid(s));
}
