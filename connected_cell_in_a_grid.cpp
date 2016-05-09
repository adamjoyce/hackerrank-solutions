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
