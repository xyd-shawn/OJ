// Search a 2D Matrix
// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.



// Solution approach: 行列各做一次二分查找O(log(m)+log(n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nrows = matrix.size();
        if(nrows == 0) {
            return false;
        }
        int ncols = matrix[0].size();
        if(ncols == 0) {
            return false;
        }
        int row_begin, row_end, row_half;
        row_begin = 0;
        row_end = nrows - 1;
        row_half = (row_begin + row_end) / 2;
        while((row_begin < row_end) && !(matrix[row_half][0] <= target && matrix[row_half][ncols - 1] >= target)) {
            if(target < matrix[row_half][0]) {
                row_end = row_half - 1;
                row_half = (row_begin + row_end) / 2;
            } else {
                row_begin = row_half + 1;
                row_half = (row_begin + row_end) / 2;
            }
        }
        if(target < matrix[row_half][0]) {
            return false;
        } else {
            int col_begin, col_end, col_half;
            col_begin = 0;
            col_end = ncols - 1;
            col_half = (col_begin + col_end) / 2;
            while((col_begin < col_end) && !(matrix[row_half][col_half] == target)) {
                if(matrix[row_half][col_half] > target) {
                    col_end = col_half - 1;
                    col_half = (col_begin + col_end) / 2;
                } else {
                    col_begin = col_half + 1;
                    col_half = (col_begin + col_end) / 2;
                }
            }
            if(target == matrix[row_half][col_half]) {
                return true;
            } else {
                return false;
            }
        }
    }
};
