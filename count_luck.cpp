#include <iostream>

int n, m, ronsGuess;
char forest[110][110];
int dX[4] = {-1, 1, 0, 0};
int dY[4] = {0, 0, -1, 1};
int noOfMoves = 0;

bool dfs(int x, int y, int previousX = -1, int previousY = -1) {
    if (forest[x][y] == '*')
        return 1;
    
    int pathPresent = 0;
    int noOfPaths = 0;
    
    for (int i = 0; i < 4; i++) {
        int newX = x + dX[i];
        int newY = y + dY[i];
        
        // Ensure the new coordinates are within the forest, not the same as previously, and not blocked.
        if (newX < 0 || newX >= n || newY < 0 || newY >= m || (newX == previousX && newY == previousY) || forest[newX][newY] == 'X')
            continue;
        
        // Check if the next position can go somewhere that is not this position.
        if (dfs(newX, newY, x, y))
            pathPresent = 1;
            
        noOfPaths++;
    }
    
    // Increment the number of moves if multiple valid paths are present.
    if (pathPresent && noOfPaths > 1)
        noOfMoves++;
    
    return pathPresent;
}

int main() {
    int testCases;
    std::cin >> testCases;
    
    for (int i = 0; i < testCases; i++) {
        std::cin >> n >> m;
        
        // Construct the forest.
        int startX, startY;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> forest[j][k];
                if (forest[j][k] == 'M') {
                    startX = j;
                    startY = k;
                }
            }
        }
        
        // Reset the number of moves and get Ron's guess.
        noOfMoves = 0;
        cin >> ronsGuess;
        
        dfs(startX, startY);
        
        if (noOfMoves != ronsGuess)
            std::cout << "Oops!\n";
        else
            std::cout << "Impressed\n";
    }
    
    return 0;
}
