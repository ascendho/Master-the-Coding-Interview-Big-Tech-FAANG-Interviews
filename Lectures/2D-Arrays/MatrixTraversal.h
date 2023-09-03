#ifndef INC_2D_ARRAYS_MATRIXTRAVERSAL_H
#define INC_2D_ARRAYS_MATRIXTRAVERSAL_H

#define ROW_MATRIX 4
#define COL_MATRIX 5
#define ROW_DIRECTIONS 4
#define COL_DIRECTIONS 2

#include <vector>

std::vector<int> values;
bool seen[ROW_MATRIX][COL_MATRIX];

int testMatrix[ROW_MATRIX][COL_MATRIX] = {{1,  2,  3,  4,  5},
                                          {6,  7,  8,  9,  10},
                                          {11, 12, 13, 14, 15},
                                          {16, 17, 18, 19, 20}
};
int directions[ROW_DIRECTIONS][COL_DIRECTIONS] = {
        {-1, 0},
        {0,  1},
        {1,  0},
        {0,  -1}
};

void Traversal_DFS();

void
DFS(int matrix[ROW_MATRIX][COL_MATRIX], int row, int col, bool seen[ROW_MATRIX][COL_MATRIX], std::vector<int> &values);

void Init(bool matrix[ROW_MATRIX][COL_MATRIX]);

void Copy(int a[], int b[], int size);

#endif //INC_2D_ARRAYS_MATRIXTRAVERSAL_H