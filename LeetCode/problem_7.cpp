// Reverse Integer
// Given a 32-bit signed integer, reverse digits of an integer.
// Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range.
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.



class Solution {
public:
    int reverse(int x) {
        long long y = 0;
        int xx;
        if(x >= 0) {
            while(x != 0) {
                xx = x % 10;
                x /= 10;
                y = y * 10 + xx;
            }
        } else {
            x = -x;
            while(x != 0) {
                xx = x % 10;
                x /= 10;
                y = y * 10 + xx;
            }
            y = -y;
        }
        long long maxint32 = 2147483647;
        long long minint32 = -2147483648;
        if((y > maxint32) || (y < minint32)) {
            return 0;
        } else {
            return int(y);
        }
    }
};
