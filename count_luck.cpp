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



//Count Luck
//Ron and Hermione are deep in the Forbidden Forest collecting potion ingredients, and they've managed to lose their way. The path out of the forest is blocked, so they must make their way to a portkey that will transport them back to Hogwarts.
//
//Consider the forest as an N×MN×M grid.Each cell is either empty(represented by .) or blocked by a tree(represented by XX).Ron and Hermione can move(together inside a single cell) LEFT, RIGHT, UP, and DOWN through empty cells, but they cannot travel through a tree cell.Their starting cell is marked with the character MM, and the cell with the portkey is marked with a ??.The upper - left corner is indexed as(0, 0)(0, 0).
//
//.X.X......X
//.X*.X.XXX.X
//.XX.X.XM...
//......XXXX.
//In example above, Ron and Hermione are located at index(2, 7)(2, 7) and the portkey is at(1, 2)(1, 2).Each cell is indexed according to Matrix Conventions
//
//Hermione decides it's time to find the portkey and leave. Each time they are able to move in more than one direction, she waves her wand and it points to the correct direction. Ron is betting that she will have to wave her wand exactly KK times. Can you determine if Ron's guesses are correct ?
//
//Note : It is guaranteed that there is only one path from the starting location to the portkey.
//
//    Input Format
//
//    The first line contains an integer, TT, the number of test cases.
//
//    Each test case is described as follows :
//The first line contains 22 space - separated integers, NN and MM, respectively, denoting the forest matrix.
//The NN subsequent lines each contain a string of length MM describing a row of the forest matrix.
//The last line contains an integer, KK, denoting Ron's guess as to how many times Hermione will wave her wand.
//
//Constraints
//
//1?T?101?T?10
//1?N, M?1001?N, M?100
//0?K?100000?K?10000
//There will be exactly one MM and one ?? in the forest.
//Exactly one path exists between MM and ??.
//Output Format
//
//On a new line for each test case, print ImpressedImpressed if Ron impresses Hermione by guessing correctly; otherwise, print Oops!Oops!.
//
//Sample Input
//
//3
//2 3
//* .M
//.X.
//1
//4 11
//.X.X......X
//.X*.X.XXX.X
//.XX.X.XM...
//......XXXX.
//3
//4 11
//.X.X......X
//.X*.X.XXX.X
//.XX.X.XM...
//......XXXX.
//4
//Sample Output
//
//Impressed
//Impressed
//Oops!
//Explanation
//
//For each test case ii, countcount denotes the number of times Hermione waves her wand.
//
//Case 0: Hermione waves her wand at(0, 2)(0, 2), giving us count = 1count = 1. Because count = K = 1count = K = 1, we print ImpressedImpressed on a new line.
//Case 1 : Hermione waves her wand at(2, 9)(2, 9), (0, 5)(0, 5), and (3, 3)(3, 3), giving us count = 3count = 3. Because count = K = 3count = K = 3, we print ImpressedImpressed on a new line.
//Case 2 : Hermione waves her wand at(2, 9)(2, 9), (0, 5)(0, 5), and (3, 3)(3, 3), giving us count = 3count = 3. Because count = 3count = 3 and K = 4K = 4, count?Kcount?K and we print Oops!Oops!on a new line.
