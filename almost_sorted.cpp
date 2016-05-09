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



//Almost Sorted
//Given an array with nn elements, can you sort this array in ascending order using only one of the following operations ?
//
//Swap two elements.
//Reverse one sub - segment.
//Input Format
//The first line contains a single integer, nn, which indicates the size of the array.
//The next line contains nn integers separated by spaces.
//
//n
//d1 d2 ... dn
//
//Constraints
//2?n?1000002?n?100000
//0?d0?dii ?1000000?1000000
//All ddii are distinct.
//
//Output Format
//1. If the array is already sorted, output yes on the first line.You do not need to output anything else.
//
//If you can sort this array using one single operation(from the two permitted operations) then output yes on the first line and then:
//
//a.If you can sort the array by swapping ddll and ddrr, output swap l r in the second line.ll and rr are the indices of the elements to be swapped, assuming that the array is indexed from 11 to nn.
//
//b.Else if it is possible to sort the array by reversing the segment d[l...r]d[l...r], output reverse l r in the second line.ll and rr are the indices of the first and last elements of the subsequence to be reversed, assuming that the array is indexed from 11 to nn.
//
//d[l...r]d[l...r] represents the sub - sequence of the array, beginning at index ll and ending at index rr, both inclusive.
//
//If an array can be sorted by either swapping or reversing, stick to the swap - based method.
//
//If you cannot sort the array in either of the above ways, output no in the first line.
