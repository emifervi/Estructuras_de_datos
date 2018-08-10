#include <iostream>
#include <set>
using namespace std;

bool check3by3(int mat[9][9], bool flag);
bool checkRows(int mat[9][9], bool flag);
bool checkCols(int mat[9][9], bool flag);

int main (){
    int matrix[9][9];
    bool matFlag;
    bool rowFlag;
    bool colFlag;

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> matrix[i][j];
        }
    }

    matFlag = check3by3(matrix, matFlag);
    rowFlag = checkRows(matrix, rowFlag);
    colFlag = checkCols(matrix, colFlag);

    if (colFlag && matFlag && rowFlag){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

}

//
// Funciton receives a matrix and a bool, scans a 9x9 matrix in small matrixes of 3x3 if every small matrix has 9 unique values
// returns true if not it returns false.
//
bool check3by3(int mat[9][9], bool flag){
    // Set to store unique values of each matrix
    set<int>matSet;

    for (int x = 0; x < 9; x += 3){
        for(int y = 0; y < 9; y += 3){
            
            // Erases objects on the set.
            matSet.clear();
            
            for (int i = 0 + x; i < 3 + x; i++){
                for(int j = 0 + y; j < 3 + y; j++){
                    // Push every value to the set and gets stored if unique.
                    matSet.insert(mat[i][j]);
                }
            }
            // if the size of the set is 9 it has 9 unique values and therfore it was right.
            (matSet.size() == 9) ? flag = true : flag = false;

            if(!flag)
                break;
        }

        if(!flag)
            break;
    }

    return flag;
}

//
// Funciton receives a matrix and a bool, scans a 9x9 matrx row by row checking if it has 9 unique values
// returns true if yes, and if not it returns false.
//
bool checkRows(int mat[9][9], bool flag){
    // Set to store unique values in each row
    set<int> rowSet;

    for(int i = 0; i < 9; i++){
        
        // Clear set for each row
        rowSet.clear();

        for(int j = 0; j < 9; j++){
            // Push every element to the set and store unique values.
            rowSet.insert(mat[i][j]);
        }
        // Check if every row has 9 unique elements breakes if one doesnt.
        (rowSet.size() == 9) ? flag = true : flag = false;

        if (!flag)
            break;
    }

    return flag;
}


//
// Funciton receives a matrix and a bool, scans a 9x9 matrx column by column checking if it has 9 unique values
// returns true if yes, and if not it returns false.
//
bool checkCols(int mat[9][9], bool flag){
    // Set to store unique values in each row
    set<int> colSet;

    for(int i = 0; i < 9; i++){
        
        // Clear set for each column
        colSet.clear();

        for(int j = 0; j < 9; j++){
            // Push every element to the set and store unique values.
            colSet.insert(mat[j][i]);
        }

        // Check if every column has 9 unique elements.
        (colSet.size() == 9) ? flag = true : flag = false;
        
        if(!flag)
            break;
    }

    return flag;
}