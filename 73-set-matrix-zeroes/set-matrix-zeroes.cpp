class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
           int rows = matrix.size();
           int columns = matrix[0].size();

        vector<int> row(rows, 0);
        vector<int> column(columns, 0);

    // Step 1: Mark rows and columns containing zero
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    column[j] = 1;
                }
            }
        }

    // Step 2: Make marked rows and columns zero
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (row[i] == 1 || column[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};