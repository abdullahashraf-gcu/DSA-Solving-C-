#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {1},
        {2},
        {3}
    };

    int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns
    
    int row = 0, col = 0;
    
    // Direction flags matching your state machine concept:
    // rowCol = true  --> Row fixed, Column moving
    // rowCol = false --> Column fixed, Row moving
    // incDec = true  --> Moving Forward (Incrementing index)
    // incDec = false --> Moving Backward (Decrementing index)
    bool rowCol = true, incDec = true;
    
    // arr[0 ... m-1] tracks visited rows
    // arr[m ... m+n-1] tracks visited columns (accessed via arr[m + col])
    vector<int> arr(m + n, 0);
    vector<int> spiral;

    int totalElements = m * n;

    while (spiral.size() < totalElements) {

      // Moving right
        if (rowCol && incDec) {
            while (col < n && arr[m + col] == 0) {
                spiral.push_back(matrix[row][col]);
                col++;
            }
            // Mark current row as visited
            arr[row] = 1;
            
            // Adjust pointers back into valid bounds for next direction
            col--; 
            row++; 
            
            // Switch direction state -> Move DOWN
            rowCol = false;
            incDec = true;
        }
        
        // Break early if all elements collected
        if (spiral.size() == totalElements) break;

// Moving down
        if (!rowCol && incDec) {
            while (row < m && arr[row] == 0) {
                spiral.push_back(matrix[row][col]);
                row++;
            }
            // Mark current column as visited
            arr[m + col] = 1;
            
            // Adjust pointers back into valid bounds for next direction
            row--; 
            col--; 
            
            // Switch direction state -> Move LEFT
            rowCol = true;
            incDec = false;
        }

        if (spiral.size() == totalElements) break;

       // Moving Left
        if (rowCol && !incDec) {
            while (col >= 0 && arr[m + col] == 0) {
                spiral.push_back(matrix[row][col]);
                col--;
            }
            // Mark current row as visited
            arr[row] = 1;
            
            // Adjust pointers back into valid bounds for next direction
            col++; 
            row--; 
            
            // Switch direction state -> Move UP
            rowCol = false;
            incDec = false;
        }

        if (spiral.size() == totalElements) break;

       // Moving up
        if (!rowCol && !incDec) {
            while (row >= 0 && arr[row] == 0) {
                spiral.push_back(matrix[row][col]);
                row--;
            }
            // Mark current column as visited
            arr[m + col] = 1;
            
            // Adjust pointers back into valid bounds for next direction
            row++; 
            col++; 
            
            // Switch direction state -> Move RIGHT
            rowCol = true;
            incDec = true;
        }
    }

    cout << "Spiral Traversal Output:" << endl;
    for (int val : spiral) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}