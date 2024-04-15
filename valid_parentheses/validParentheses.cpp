#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    char temp;
    int i;
    stack<char> stack;

public:
    bool validParentheses(string s) {
        if (s.size() <= 1) {
            return false;
        }

        if (s.size() % 2 == 1) {
            return false;
        }

        for (int i =0; i < s.size(); i++) {
            if(stack.empty()) {
                stack.push(s[i]);
            }
            else {
                if ((stack.top() == '(' && s[i] == ')') || (stack.top() == '{' && s[i] == '}') || (stack.top() == '[' && s[i] == ']')) {
                    stack.pop();
                }
                else {
                    stack.push(s[i]);
                }
            }
        }

        if(stack.empty()) {
            return true;
        } 
        else {
            return false;
        }
    }
};