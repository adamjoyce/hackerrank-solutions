#include<iostream>
#include<unordered_set>

std::unordered_set<int> hashSet;

int main() {
    int numberOfValues, difference, values;
    std::cin >> numberOfValues >> difference;
    
    // Setup the unordered set with our values.
    for (int i = 0; i < numberOfValues; i++) {
        std::cin >> values;
        hashSet.insert(values);
    }
    
    int pairs = 0;
    std::unordered_set<int>::iterator it;
    for (it = hashSet.begin(); it != hashSet.end(); it++) {
        // By searching for the value + difference we can see if a pair exists.
        int value = *it + difference;
        if (hashSet.find(value) != hashSet.end()) {
            pairs++;
        }
    }
        
    std::cout << pairs << std::endl;
    return 0;
}