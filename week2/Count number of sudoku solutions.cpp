#include <iostream>

using namespace std;

const int SIZE = 9;


bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num) return false;
    }

   
    for (int x = 0; x < SIZE; x++) {
        if (board[x][col] == num) return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }
    
    return true;
}


int solveSudoku(int board[SIZE][SIZE]) {
    int row, col;
    bool isEmpty = true;

    
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                isEmpty = false; 
                break;
            }
        }
        if (!isEmpty) break;
    }

    
    if (isEmpty) return 1;

    
    int count = 0;
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num; // Place the number

           
            count += solveSudoku(board);

            
            board[row][col] = 0;
        }
    }
    
    return count;
}

int main() {
    int board[SIZE][SIZE];

    
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
        }
    }

    
    int solutions = solveSudoku(board);

    
    cout << solutions << endl;

    return 0;
}
