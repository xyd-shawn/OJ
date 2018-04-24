// 2 Keys Keyboard
// Initially on a notepad only one character 'A' is present.
// You can perform two operations on this notepad for each step:
// Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
// Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted.
// Output the minimum number of steps to get n 'A'.



// Solution Approach: res[n] = min(res[i] + n / i) n / i is interger
class Solution {
public:
    int minSteps(int n) {
        vector<int> res(1001, 0);
        for(int i = 2; i <= n; i++) {
            res[i] = i;
        }
        for(int i = 2; i < n; i++) {
            for(int k = 2; k * i <= n; k++) {
                if(res[i] + k < res[k * i]) {
                    res[k * i] = res[i] + k;
                }
            }
        }
        return res[n];
    }
};


class Solution {
public:
    int minSteps(int n) {
        vector<int> res(1001, 0);
        for(int i = 2; i <= n; i++) {
            res[i] = i;
        }
        for(int i = 2; i <= n / 2; i++) {
            if(n % i == 0) {
                for(int k = 2; k * i <= n; k++) {
                    if(res[i] + k < res[k * i]) {
                        res[k * i] = res[i] + k;
                    }
                }
            }
        }
        return res[n];
    }
};
