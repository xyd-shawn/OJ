// Median of Two Sorted Arrays

// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

// Solution approach: https://leetcode.com/problems/median-of-two-sorted-arrays/solution/



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(n < m) {
            nums1.swap(nums2);
            m = n;
            n = nums2.size();
        }
        if(m == 0) {
            if(n % 2 == 1) {
                return nums2[(n / 2)];
            } else {
                return double(nums2[(n / 2) - 1] + nums2[(n / 2)]) / 2.0;
            }
        }
        int imin = 0;
        int imax = m;
        int half = (m + n + 1) / 2;
        int i, j;
        while(imin <= imax) {
            i = (imin + imax) / 2;
            j = half - i;
            if(i < m) {    // j > 0
                if(nums2[j - 1] > nums1[i]) {
                    imin = i + 1;    // increase i
                } else {
                    if(i > 0) {    // j < n
                        if(nums1[i - 1] > nums2[j]) {
                            imax = i - 1;    // decrease i
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
            } else {
                if(i > 0) {
                    if(nums1[i - 1] > nums2[j]) {
                        imax = i - 1;    // decrease i
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        double res;
        if((m + n) % 2 == 1) {
            if(i == 0) {
                res = (double)(nums2[j - 1]);
            } else {
                res = (double)(nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1]);
            }
        } else {
            int maxleft, minright;
            if(i == 0) {
                maxleft = nums2[j - 1];
                if(j < n) {
                    minright = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
                } else {
                    minright = nums1[i];
                }
            } else {
                if(j == 0) {
                    maxleft = nums1[i - 1];
                    minright = nums2[j];
                } else {
                    maxleft = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
                    if(i == m) {
                        minright = nums2[j];
                    } else {
                        minright = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
                    }
                }
            }
            res = double(maxleft + minright) / 2.0;
        }
        return res;
    }
};
