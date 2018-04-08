// Sqrt(x)
// Implement int sqrt(int x).
// Compute and return the square root of x.
// x is guaranteed to be a non-negative integer.



// Solution approach: 二分查找
// Note: 注意溢出问题
class Solution {
public:
    int mySqrt(int x) {
       if(x <= 1) {
           return x;
       } else if(x >= 2147395600) {
           return 46340;
       } else {
           int low = 1;
           int high = (x < 46339)? x: 46339;
           int half = (high + low) / 2;
           int square1 = half * half;
           int square2 = (half + 1) * (half + 1);
           while(low < high && !((square1 <= x) && (x < square2))) {
               if(x < square1) {
                   high = half - 1;
               } else {
                   low = half + 1;
               }
               half = (high + low) / 2;
               square1 = half * half;
               square2 = (half + 1) * (half + 1);
           }
           return half;
       }
    }
};
