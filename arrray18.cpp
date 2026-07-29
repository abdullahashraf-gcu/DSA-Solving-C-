#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {

     vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    
    int m = matrix.size();    // Number of rows 
    int n = matrix[0].size(); // Number of columns

    for (int i = 0; i < m; i++) {
        int toSkip=i;
        for (int j = 0; j < n; j++) {
            if(toSkip>0){
                toSkip--;
                continue;
            }

            int copy = matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=copy;
           ;
        }
    }

    for (auto &row : matrix){

        reverse(row.begin(), row.end());
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