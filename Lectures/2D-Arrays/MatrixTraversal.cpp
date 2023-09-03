#include "MatrixTraversal.h"

void Traversal_DFS(int matrix[ROW_MATRIX][COL_MATRIX]) {
    Init(seen);
    DFS(matrix, 0, 0, seen, values);
}

void
DFS(int matrix[ROW_MATRIX][COL_MATRIX], int row, int col) {
    if (row < 0 || col < 0 || row >= ROW_MATRIX || col >= COL_MATRIX || seen[row][col])
        return;

    seen[row][col] = true;
    values.push_back(matrix[row][col]);

    for (int i = 0; i < ROW_DIRECTIONS; i++) {
        int currentDir[COL_DIRECTIONS];
        Copy(currentDir, directions[i], COL_DIRECTIONS);
        DFS(matrix, row + currentDir[0], col + currentDir[1]);
    }

}

void Init(bool matrix[ROW_MATRIX][COL_MATRIX]) {
    for (int i = 0; i < ROW_MATRIX; i++)
        for (int j = 0; j < COL_MATRIX; j++)
            matrix[i][j] = false;
}

void Copy(int a[], int b[], int size) {
    for (int i = 0; i < size; ++i)
        a[i] = b[i];
}