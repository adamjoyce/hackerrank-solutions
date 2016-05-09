#include <vector>
#include <iostream>

int numberOfNodes, testValue;
int bitArray[200005];
std::vector<int> adjacencyList[100005];
long long similarPairs;

// Query the running total sum from the starting index to parameter index.
int query(int index) {
    int sum = 0;
    for (int i = index; i > 0; i -= i & -i) {
        sum += bitArray[i];
    }
    return sum;
}

// Insert or remove a node by altering its value.
void update(int index, int value) {
    for (int i = index; i <= numberOfNodes * 2; i += i & -i) {
        bitArray[i] += value;
    }
}

// Depth first search algorithm.
void dfs(int node) {
    similarPairs += (long long)query(node + testValue) - query(node - testValue - 1);
    update(node, 1);
    
    for (int i = 0; i < adjacencyList[node].size(); i++) {
        dfs(adjacencyList[node][i]);
    }
    
    update(node, -1);
}

int main() {
    int x, y;
    std::cin >> numberOfNodes >> testValue;
    similarPairs = 0;
    
    // Store the parent nodes of each line of input and ajust the adjacency list accordingly.
    int parentNode[100005];
    for (int i = 1; i < numberOfNodes; i++) {
        std::cin >> x >> y;
        parentNode[y] = x;
        adjacencyList[x].push_back(y);
    }
    
    // Find the root node and call a depth first search on it.
    for (int i = 1; i < numberOfNodes; i++) {
        if (!parentNode[i]) {
            dfs(i);
        }
    }
    
    std::cout << similarPairs;   
    return 0;
}



//Similar Pairs
//You are given a tree where each node is labeled from 11 to nn.How many similar pairs(S) are there in this tree ?
//
//A pair(A, B) is a similar pair if the following are true :
//
//    node AA is the ancestor of node BB
//    abs(A?B)?Tabs(A?B)?T
//    Input format :
//The first line of the input contains two integers, nn and TT.This is followed by n?1n?1 lines, each containing two integers ssii and eeii where node ssii is a parent to node eeii.
//
//Output format :
//Output a single integer which denotes the number of similar pairs in the tree.
//
//Constraints :
//    1?n?1000001?n?100000
//    0?T?n0?T?n
//    1?s1?sii, eeii ?n?n
//
//    Sample Input :
//
//5 2
//3 2
//3 1
//1 4
//1 5
//Sample Output :
//
//4
//Explanation :
//    The similar pairs are : (3, 2) (3, 1) (3, 4) (3, 5).