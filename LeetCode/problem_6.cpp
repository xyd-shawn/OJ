// ZigZag Conversion



class Solution {
public:
    string convert(string s, int numRows) {
        int sz = s.size();
        if(sz == 0) {
            return s;
        }
        if(numRows == 1) {
            return s;
        } else if(numRows == 2) {
            string ss;
            for(int i = 0; i < sz; i += 2) {
                ss += s[i];
            }
            for(int i = 1; i < sz; i += 2) {
                ss += s[i];
            }
            return ss;
        } else {
            string ss;
            for(int i = 0; i < numRows; i++) {
                for(int j = i; j < sz; j += (2 * numRows - 2)) {
                    ss += s[j];
                    if((i != 0) && (i != numRows - 1)) {
                        if((j + 2 * numRows - 2 * i - 2) < sz) {
                            ss += s[j + 2 * numRows - 2 * i - 2];
                        }
                    }
                }
            }
            return ss;
        }

    }
};
