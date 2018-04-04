// Evaluate Reverse Polish Notation
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
// Some examples:
// ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
// ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6



// 利用栈数据结构
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int sz = tokens.size();
        for(int i = 0; i < sz; i++) {
            if(tokens[i] == "+") {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                int num3 = num1 + num2;
                nums.push(num3);
            } else if(tokens[i] == "-") {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                int num3 = num1 - num2;
                nums.push(num3);
            } else if(tokens[i] == "*") {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                int num3 = num1 * num2;
                nums.push(num3);
            } else if(tokens[i] == "/") {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                int num3 = num1 / num2;
                nums.push(num3);
            } else {
                int num = 0;
                int flag = 0;
                if(tokens[i][0] == '-') {
                    flag = 1;
                }
                for(int j = flag; j < tokens[i].size(); j++) {
                    num = num * 10 + (tokens[i][j] - '0');
                }
                if(tokens[i][0] == '-') {
                    num = -num;
                }
                nums.push(num);
            }
        }
        return nums.top();
    }
};
