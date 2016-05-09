#include <vector>
#include <iostream>
#include <algorithm>

int numberOfElements, originalValues[100005], sortedValues[100005];

int main() {
    // Read in the number of elements and setup the arrays.
    std::cin >> numberOfElements;
    for (int i = 0; i < numberOfElements; i ++) {
        std::cin >> originalValues[i];
        sortedValues[i] = originalValues[i];
    }
    
    std::sort(sortedValues, sortedValues + numberOfElements);
    
    // Store any incorrectly positioned value's indices.
    std::vector<int> differentIndicies;
    for (int i = 0; i < numberOfElements; i++) {
        if (originalValues[i] != sortedValues[i]) {
            differentIndicies.push_back(i);
        }
    }
    
    // Check if the original array is already sorted or two values can be swapped to make it sorted.
    int differentSize = differentIndicies.size();
    if (!differentSize) {
        std::cout << "yes";
        return 0;
    } else if (differentSize == 2 && (originalValues[differentIndicies[0]] == sortedValues[differentIndicies[1]]) && originalValues[differentIndicies[1]] == sortedValues[differentIndicies[0]]) {
        std::cout << "yes\nswap " << differentIndicies[0] + 1 << " " << differentIndicies[1] + 1;
        return 0;
    }
    
    std::reverse(originalValues + differentIndicies[0], originalValues + differentIndicies.back() + 1);
    
    // Check to see if all the elements match when the sub-section between mismatching elements is reversed.
    int reversed = 1;
    for (int i = 0; i < numberOfElements; i++) {
        reversed &= (originalValues[i] == sortedValues[i]);
    }
    
    if (reversed) {
        std::cout << "yes\nreverse " << differentIndicies[0] + 1 << " " << differentIndicies.back() + 1;
    } else {
        std::cout << "no";
    }
    
    return 0;
}
