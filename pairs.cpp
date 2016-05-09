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



//Pairs
//Given NN integers, count the number of pairs of integers whose difference is KK.
//
//Input Format
//
//The first line contains NN and KK.
//The second line contains NN numbers of the set.All the NN numbers are unique.
//
//Output Format
//
//An integer that tells the number of pairs of integers whose difference is KK.
//
//Constraints:
//N?10N?1055
//0<K<100<K<1099
//    Each integer will be greater than 00 and at least KK smaller than 223131?1?1.
//
//    Sample Input
//
//    5 2
//    1 5 3 4 2
//    Sample Output
//
//    3
//    Explanation
//
//    There are 3 pairs of integers in the set with a difference of 2.