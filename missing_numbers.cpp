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



//Missing Numbers
//Numeros, the Artist, had two lists AA and BB, such that BB was a permutation of AA.Numeros was very proud of these lists.Unfortunately, while transporting them from one exhibition to another, some numbers were left out of AA.Can you find the missing numbers ?
//
//Notes
//
//If a number occurs multiple times in the lists, you must ensure that the frequency of that number in both lists is the same.If that is not the case, then it is also a missing number.
//You have to print all the missing numbers in ascending order.
//Print each missing number once, even if it is missing multiple times.
//The difference between maximum and minimum number in BB is less than or equal to 100100.
//Input Format
//There will be four lines of input :
//
//nn - the size of the first list
//This is followed by nn space - separated integers that make up the first list.
//mm - the size of the second list
//This is followed by mm space - separated integers that make up the second list.
//
//Output Format
//Output the missing numbers in ascending order.
//
//Constraints
//1?n, m?10000101?n, m?1000010
//1?x?10000, x?B1?x?10000, x?B
//Xmax?Xmin<101Xmax?Xmin<101
//    Sample Input
//
//    10
//    203 204 205 206 207 208 203 204 205 206
//    13
//    203 204 204 205 206 207 205 208 203 206 205 206 204
//    Sample Output
//
//    204 205 206
//    Explanation
//    204 is present in both arrays.Its frequency in A is 2, while its frequency in B is 3. Similarly, 205 and 206 occur twice in A, but thrice in B.So, these three numbers are our output.The rest of the numbers have thesame frequency in both lists.