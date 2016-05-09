#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

int visited[100009];
int nodeWeight[100009];
int subTreeWeight[100009];
std::vector<int> edges[100009];

int difference(int value, int sum) {
    return std::abs(sum - 2 * value);
}

int dfs(int node) {
    if (visited[node])
        return 0;
    
    if (edges[node].size() == 1) {
        subTreeWeight[node] = nodeWeight[node];
        visited[node] = 1;
        return subTreeWeight[node];
    } else {
        visited[node] = 1;
        
        int totalWeight = nodeWeight[node];
        std::vector<int>::iterator it;
        for (it = edges[node].begin(); it != edges[node].end(); it++) {
            int nodeIndex = *it;
            totalWeight += dfs(nodeIndex);
        }
        
        subTreeWeight[node] = totalWeight;
        return subTreeWeight[node];
    }
}

int main() {
    int numberOfVertices, rootNode;
    std::cin >> numberOfVertices;
    
    // Setup the sub-tree weight and visited arrays.
    for (int i = 0; i < numberOfVertices; i++) {
        subTreeWeight[i] = 0;
        visited[i] = 0;
    }
    
    // Sum the weights of the entire tree.
    int sum = 0;
    for (int i = 1; i <= numberOfVertices; i++) {
        std::cin >> nodeWeight[i];
        sum += nodeWeight[i];
    }
    
    // Setup the tree edges.
    for (int i = 0; i < numberOfVertices; i++) {
        int node1, node2;
        std::cin >> node1 >> node2;
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
    }
    
    // Assign the root node for nodes with multiple branches.
    for (int i = 0; i < numberOfVertices; i++) {
        if (edges[i].size() > 1) {
            rootNode = i;
            break;
        }
    }
    
    int temp = dfs(rootNode);
    
    for (int i = 1; i <= numberOfVertices; i++) {
        subTreeWeight[i - 1] = difference(subTreeWeight[i], sum);
    }
    
    std::sort(subTreeWeight, subTreeWeight + numberOfVertices);
    std::cout << subTreeWeight[0] << std::endl;
    
    return 0;
}



//Cut the Tree
//Atul is into graph theory, and he is learning about trees nowadays.He observed that the removal of an edge from a given tree TT will result in the formation of two separate trees, T1T1 and T2T2.
//
//Each vertex of the tree TT is assigned a positive integer.Your task is to remove an edge, such that the Tree_diff of the resultant trees is minimized.Tree_diff is defined as the following :
//
//F(T) = Sum of numbers written on each vertex of a tree T
//Tree_diff(T) = abs(F(T1) - F(T2))
//Input Format
//The first line will contain an integer NN, i.e.the number of vertices in the tree.
//The next line will contain NN integers separated by a single space, i.e.the values assigned to each of the vertices(where the first one is the root of the tree).
//The next N?1N?1 lines contain a pair of integers each, separated by a single space, that denote the edges of the tree.
//In the above input, the vertices are numbered from 11 to NN.
//
//Output Format
//A single line containing the minimum value of Tree_diff.
//
//Constraints
//3?N?103?N?1055
//1?1? number written on each vertex ?1001?1001
//
//Sample Input
//
//6
//100 200 100 500 100 600
//1 2
//2 3
//2 5
//4 5
//5 6
//Sample Output
//
//400
//Explanation
//
//Originally, we can represent tree as
//
//1(100)
//\
//2(200)
/// \
//(100)5   3(100)
/// \
//(500)4   6(600)
//Cutting the edge at 1 2 would result in Tree_diff = 1500 - 100 = 1400
//Cutting the edge at 2 3 would result in Tree_diff = 1500 - 100 = 1400
//Cutting the edge at 2 5 would result in Tree_diff = 1200 - 400 = 800
//Cutting the edge at 4 5 would result in Tree_diff = 1100 - 500 = 600
//Cutting the edge at 5 6 would result in Tree_diff = 1000 - 600 = 400
//
//Hence, the answer is 400.
