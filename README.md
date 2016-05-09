# hackerrank-solutions
This is a location for my solved hackerrank solutuions.
Below is a brief description of the approah I took to solving each of the problems:

##Almost Sorted
- For this question I setup an additional array to the original input and sort this array for comparison.
- If the original array matches the sorted array I simply output 'yes'.
- For any values in the two arrays whose indices do not match I store in a vector array.
- If non-matching values exist there must be at least two of them.
- This means that if their are exactly two values that are incorrectly placed it is trivial to test to see if when swapped the original values become sorted.
- If this is the case 'yes swap x y' is printed where x and y are the indices that need to be swapped to form the sorted array.
- Lastly I reverse the sub-section between the mismatching elements in the original array and iterate over it to check if all the values now match those in the sorted array.
- If they match I print 'yes reverse x y' where x and y are the start and end indices of the subsection that needs reversing.
- If they do not match 'no' is printed.


##Connected Cells in a Grid
- I begin by assigning two arrays dX and dY which signify the x and y positions of the eight cells surrounding the cell being tested.
- My depth first search function takes a single cell's x and y coordinate, marks that cell as visited, and proceeds to check if its surrounding cells contain the value 1 (providing they are within grid range and have not been previously visited).#
- The depth first function is recursively called on any cell that contains the value 1 and the overall count is incremented.
- By using this function I can search through each cell in the grid calculating the number of connected cells from the given cell.
- The largest connected count is stored and printed.


##Count Luck
- The forest and the four possible moves in relation to a cell are stored in arrays.
- My depth first search function takes the current and previous x and y coordinates.
- It cycles through the four possible moves discerning their eligibility i.e. if each cell is within the forest bounds, if the new cell is not the previous one, and if it is not blocked.
- If the above is true for a cell I recursively call depth first search on it to check if that cell has a valid path moving forward.
- Once all four cells have been evaluated if their are multiple paths moving forward I increment the number of moves taken.
- This depth first search function will search through the grid eventually finding the the portkey having stored the number of moves taken to reach it.
- It is then a simple case of evaluating is this result matches Ron's guess and printing the appropriate text.


##Cut the Tree
- I begin by storing the sum of all of the on all the vertices in the entire tree.
- By cycling through each node of the tree and calling my depth first search algorithm I am able to calculate the weights of all the sub-trees.
- This means that I can then remove edges and easily calculate the weight difference between the two.
- It is then a simiple case of sorting the results and printing the lowest difference value.


##Missing Numbers
- To solve this question I begin by introducing an array frequency.
- For each value in List A I decrement the corresponding index value in frequency.
- I then do the same with List B, but instead of decrementing the value I increment it.
- This results in any value missing in List A but present in List B having a positive value in frequency.
- Finally I print all the index values in frequency which are greater than zero.
- This results in the missing elements being printed in ascending order.


##Pairs
- For this question I stored the values in a hash table.
- For each element in this container I search for a value in the container that is equal to the sum of the value and the difference.
- If one is found a pair exists.
- The total number of pairs is printed.


##Similar Pairs
- With this problem I needed to find a suitable data structure to keep track of and access a node's parent nodes.
- In addition there must be an easy and time efficient way to insert and remove nodes as I traversed the tree.
- A Binary Index Tree seemed suitable for the requirements the of the problem.
- After determining the root node, i.e. the node with no parent, I traverse the tree using my depth first search algorithm.
- To meet the conditions for a similar pair, I need to find each node's parents where A - B <= T, when A is a parent node of B and T is the given test value.
- I do this by using the binary index tree to keep track of the following node's parents.
- Then for the current node I can query the number of it's own parents that fall in the range of (currentNodeValue - testValue) to (currentNodeValue + testValue), and add that value to the number of similar pairs.
- My update function is used in my depth first search to both add and remove nodes as I traverse and return back along the tree structure.
- Once the depth first search is complete the number of total similar pairs will have been found - this value is printed.


##Submissions
![submission1](https://raw.githubusercontent.com/adamjoyce/hackerrank-solutions/master/images/submissions1.PNG)

![submission2](https://raw.githubusercontent.com/adamjoyce/hackerrank-solutions/master/images/submissions2.PNG)


##Youtube Video
https://youtu.be/cPVosMC-PeM
