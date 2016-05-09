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
