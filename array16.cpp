#include<iostream>
#include<vector>

using namespace std;

int main() {
    // Sample 2D Vector (m x n matrix)
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns

    // rowHash of size m (0 = no zero in row, 1 = row contains zero)
    // colHash of size n (0 = no zero in col, 1 = col contains zero)
    vector<int> rowHash(m, 0);
    vector<int> colHash(n, 0);

    // 1st Pass: Identify where 0s exist and mark corresponding hash index as 1
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                rowHash[i] = 1; // Mark row i
                colHash[j] = 1; // Mark col j
            }
        }
    }

    // 2nd Pass: Modify matrix using recorded hash values
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // If either row i or column j was marked as 1 in our hash tables
            if (rowHash[i] == 1 || colHash[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }

    for(auto row : matrix)
{
    for(auto num : row)
    {
        cout << num << " ";
    }
    cout << endl;
}
    

    return 0;
}


// optimal solution 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Check first row
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check first column
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Use first row and first column as markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero rows based on markers
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero columns based on markers
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle first row
        if (firstRowZero) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        // Handle first column
        if (firstColZero) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};