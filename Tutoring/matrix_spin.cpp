#include <iostream>
using namespace std;

void print(int mat[4][4]);
void spin1(int mat[4][4]);
void spin2(int mat[4][4]);
void spin3(int mat[4][4]);

int main (){
  // Variables to receive the number of spins and the matrix
  int spins;
  int matrix[4][4], spinMat[4][4];

  cin >> spins;
  // If matrix mod 4 is less than 0 it makes mode and adds 4
  // Else just makes mod
  (spins % 4 < 0) ? spins = spins % 4 + 4 : spins = spins % 4;

  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      cin >> matrix[i][j];
    }
  }

  // Switch for each case of spin
  switch (spins){
    case 0:
      print(matrix);
      break;
    case 1:
      spin1(matrix);
      break;
    case 2:
      spin2(matrix);
      break;
    case 3:
      spin3(matrix);
      break;
  }

  return 0;
}

//
// Spins the matrix once to the right
//
void spin1(int mat[4][4]){
  int spinMat[4][4];

  // Uses a auxiliary matrix to receive the spun version of the original
  for (int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      spinMat[i][j] = mat[3 - j][i];
    }
  }

  print(spinMat);
}

//
// Spins the matrix twice to the right
//
void spin2(int mat[4][4]){
  int spinMat[4][4];

  // Uses a auxiliary matrix to receive the spun version of the original
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      spinMat[i][j] = mat[3-i][3-j];
    }
  }

  print(spinMat);
}

//
// Spins the matrix three times to the right
//
void spin3(int mat[4][4]){
  int spinMat[4][4];

  // Uses a auxiliary matrix to receive the spun version of the original
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      spinMat[i][j] = mat[j][3-i];
    }
  }

  print(spinMat);  
}

//
// Prints matrix
//
void print(int mat[4][4]){

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            // Makes sure not to print space in last index
            (j < 3) ? cout << mat[i][j] << " " : cout << mat[i][j];
        }
        cout << endl;
    }
}