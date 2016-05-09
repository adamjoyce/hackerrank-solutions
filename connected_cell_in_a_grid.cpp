#include <cstdio>

int rows, columns, count;
int grid[10][10];
int visited[10][10];

// The eight location coordinates around (x, y).
int dX[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dY[8] = {0, -1, 0, 1, 1, -1, 1, -1};

void dfs(int x, int y) {
    visited[x][y] = 1;
    count++;
    
    // Recursively depth first search surrounding cells.
    for (int i = 0; i < 8; i++) {
        int newX = x + dX[i];
        int newY = y + dY[i];
        
        // Check new coordinates are within range, 1, and have not been previously visited.
        if (newX < 0 || newX >= rows || newY < 0 || newY >= columns || !grid[newX][newY] || visited[newX][newY])
            continue;
        
        dfs(newX, newY);
    }
}

int main() {
    std::scanf("%d%d", &rows, &columns);
    
    // Setup the grid.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::scanf("%d", &grid[i][j]);
        }
    }
    
    // Search.
    int connected = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (!visited[i][j] && grid[i][j]) {
                count = 0;
                dfs(i, j);
                
                if (count > connected) {
                    connected = count;
                }
            }
        }
    }
    
    std::printf("%d\n", connected);
    return 0;
}



//Connected Cell in a Grid
//You are given a matrix with mm rows and nn columns of cells, each of which contains either 11 or 00. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.The connected and filled(i.e.cells that contain a 11) cells form a region.There may be several regions in the matrix.Find the number of cells in the largest region in the matrix.
//
//Input Format
//There will be three parts of t input :
//The first line will contain mm, the number of rows in the matrix.
//The second line will contain nn, the number of columns in the matrix.
//This will be followed by the matrix grid : the list of numbers that make up the matrix.
//
//Output Format
//Print the length of the largest region in the given matrix.
//
//Constraints
//0<m<100<m<10
//    0<n<100<n<10
//
//    Sample Input :
//
//4
//4
//1 1 0 0
//0 1 1 0
//0 0 1 0
//1 0 0 0
//Sample Output :
//
//5
//Task :
//    Write the complete program to find the number of cells in the largest region.
//
//    Explanation
//
//    X X 0 0
//    0 X X 0
//    0 0 X 0
//    1 0 0 0
//    The X characters indicate the largest connected component, as per the given definition.There are five cells in this component.
//

