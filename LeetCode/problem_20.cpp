// Valid Parentheses
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.
// The brackets must close in the correct order,
// "()" and "()[]{}" are all valid but "(]" and "([)]" are not.



class Solution {
public:
    bool isValid(string s) {
        int sz = s.size();
        if(sz == 0) {
            return true;
        }
        if(sz % 2 == 1) {
            return false;
        }
        stack<char> brac;
        bool flag = true;
        for(int i = 0; i < sz; i++) {
            if((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
                brac.push(s[i]);
            } else {
                if(brac.empty()) {
                    flag = false;
                    break;
                } else {
                    if(s[i] == ')') {
                        if(brac.top() == '(') {
                            brac.pop();
                        } else {
                            flag = false;
                            break;
                        }
                    } else if(s[i] == ']') {
                        if(brac.top() == '[') {
                            brac.pop();
                        } else {
                            flag = false;
                            break;
                        }
                    } else {
                        if(brac.top() == '{') {
                            brac.pop();
                        } else {
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }
        if(!brac.empty()) {
            flag = false;
        }
        return flag;
    }
};
