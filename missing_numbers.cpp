#include <iostream>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int maxValue = 10001;
    int frequency[maxValue] = {0};
    int size;
    int value;
    
    // Decrement the list a index values in frequency.
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> value;
        frequency[value]--;
    }
    
    // Increment the list b index values in frequency.
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> value;
        frequency[value]++;
    }
    
    // Any values in the array above 0 are missing from list a.
    for (int i = 0; i < maxValue; i++) {
        if (frequency[i] > 0) {
            std::cout << i << " ";
        }
    }
    
    return 0;
}