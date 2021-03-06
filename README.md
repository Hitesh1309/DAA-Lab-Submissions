# DAA-Lab-Submissions
Design and Analysis of Algorithms Lab Course @IIITDM, 2021.
## Team
```
D Abishek        - CS20B1064
Nithish Vasanth  - CS20B1068
Ryan A           - CS20B1094
K Hitesh Gupta   - CS20B1127
```
## Lab-1
```
Problem: Finding MIN, MAX, Second MIN, Second MAX in an integer array
Present 3 different logic. NO logic should use sorting. For example, one of the logic is to divide the array into
two equal halves, find min/max/smin/smax for each, recursively update to get the final min/max/smin/smax.
Implementation using C++ classes and objects.
```
---
## Lab-2
```
1. Trapping Rain Water:
https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
2. Implement two stacks in an array
https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1
3. Triplet Sum in Array
https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
4. Given an array write an algorithm to find the sum of all the possible sub-arrays.
Example: for array = {1, 2, 3, 4}, All sub arrays are:
[1], [12], [123], [1234],
[2], [23], [234]
[3], [34]
[4]
```
---
## Lab-3
```
Divide and Conquer Paradigm
1. Find MAX using 1-way, 2-way, 3-way, k-way approach
2. Count the number of negative numbers in an integer array using 2-way and 3-way approach.
3. Implement an Iterative and a Recursive algorithm for binary search, ternary search.
```
---
## Lab-4
```
1. Implement Classical Bubble, Selection, Insertion Sort, Merge Sort, Heap Sort.
2. Insertion Variant: Note that at iteration i, the first (iā1) elements are sorted and as part of the insertion
sort algorithm, we look for the right position for A[i]. The position for A[i] is determined by performing a
linear search on A[1..(i ā 1)]. You are asked to implement the following; since A[1..(i ā 1)] is sorted, perform
binary search to identify the right position for A[i]. At each iteration i, perform binary search instead of
linear search to identify the right position for A[i] so that at the end of the iteration A[1..i] is sorted.
```
---
## Mid-Sem
#### `Coding Best Practice`
   1. Proper indentation,  name of the function must be self explanatory (ex; find_min, find_max, avoid f1, f2).   
   2. Except loop indices (i,j,k), all other variables must be self explanatory (ex: Min, SecondMin, avoid, variables, a,b,temp, m1,m2,temp2).  
   3. All functions must be public and defined in the class template.

```
Q1 - Given two integers m,n, the objective is to perform m*n using binary representation of m and n.
Q2 - Implement Quicksort with 2 pivots.   Choose two arbitrary elements of the given array A, say x and y.   Maintain three windows at each iteration, assuming x < y, the first window has elements < x, the second window has elements between x and y, and the third window has elements > y.
```
---
## Lab-5
```
1. Hybrid Sorting: Insertion sort + Merge sort - Consider a large sized array (size at least 1000). Perform
Merge sort recursively until the problem size becomes less than or equal to 20. When problem size becomes
less than or equal to 20, perform Insertion sort.
2. Implement Quicksort with two pivots; suppose the pivot values are x and y such that x ā¤ y, then Partition
1 has values < x, Partition 2 has values between x and y, and Partition 3 has values > y.
3. Given a set of m words (strings), arrange them in dictionary order.
```
---
## Lab-6
```
1. Implement Greedy Algorithms for Coin Change and Fractional Knapsack.
2. Implement Greedy Strategy for Matrix Chain Multiplication and Optimal Binary Search tree
```
---
## Lab-7
```
1. Implement dynamic programming for Coin Change and 0-1 Knapsack
2. Implement dynamic programming for Matrix Chain Multiplication and Optimal Binary Search tree
3. Objective: The goal is to introduce an important feature of OO Programming, namely Polymorphism. We
shall appreciate this feature by taking case studies that follow Dynamic programming or Greedy Technique.

Motivation: 1 Is there a succinct way of implementing functions with similar operations. For exam-
ple, finding max and second max in a set of integers, in a set of floating point numbers, in a set of characters

(characters are compared based on their ascii value). For all three operations, the common theme is āfind
max and second maxā and the only change is ādata typeā. We are looking for a function doing multiple roles
(poly + morph).
Answer: Function Templates.
Task Expected out of you: Read Function templates and implement the following;
(i) Find max and second using n + log n ā 2 comparisons (check problem session), if
(ii) Find max and min with the least number of comparisons (check problem session), if
ā¢ the input is an array of integers
ā¢ the input is an array of double
ā¢ the input is an array of characters
ā¢ use functiontemplate.h to define template and in .cpp invoke the function with appropriate data type

as an argument. Do NOT forget to include .h file at the beginning of the program (include āfunction-
template.hā).

Motivation: 2 Is there a succinct way of implementing functions with similar operations accepting different
number of arguments. Answer: Function overloading.
Task Expected out of you: Read function overloading and implement the following;
ā¢ Knapsack(int W, int Weight, int Profit)
ā Implement Dynamic programming based approach, to be discussed in class on Monday.
ā¢ Knapsack(double W, double Weight, double Profit)
ā Same as above, however, in this we accept floating point numbers.
ā¢ Knapsack(int W, int Weight)
ā Implement knapsack-variant: Knapsack problem with no profits. That is, the objective is to
find a subset of objects with maximum cardinality. Implement DP/Greedy. Hint: Container
Loading.
ā¢ Knapsack(int W, int Weight, int Profit, bool flag)
ā In all of the above, we were not allowed to pick a fraction of objects into the Sack. Suppose, we are
allowed to pick a fraction of objects, i.e., (x1 = 1, x2 = 1, x3 = 0.5) such that w1+w2+0.5w3 = W.
Note: the sum equals W as we are allowed to pick a fraction now. āflagā is artificially introduced

(āflagā is set to true always) so that one can distinguish between fractional knapsack and non-
fraction knapsack problem. Implement Greedy Strategy 3 which was discussed in class.
```
---
## Lab-8
```
1. Implement DFS,BFS, Test for Bipartiteness, Cycle testing and test for connectedness.
```
---
## End-Sem
#### `Coding Best Practice`
   1. Proper indentation,  name of the function must be self explanatory (ex; find_min, find_max, avoid f1, f2).   
   2. Except loop indices (i,j,k), all other variables must be self explanatory (ex: Min, SecondMin, avoid, variables, a,b,temp, m1,m2,temp2).  
   3. All functions must be public and defined in the class template.

```
Consider the Knapsack problem (0-1) version.   
Input:  x_1,...,x_n   objects with weights w_1,...,w_n, profits p_1,...,p_n
Objective: Place objects into the Knapsack not exceeding the capacity of the Knapsack (W) by maximizing the profits.
As part of this lab exam, we shall consider the following FOUR questions.

Q1: Knapsack with all weights same (w_i is same for all objects)
Present a GREEDY algorithm and its implementation in C++.     Run-time of your algorithm must be o(n^2)  (little-oh of n^2).

Q2: Knapsack with all profits same (p_i is same for all objects)
Present a GREEDY algorithm and its implementation in C++.     Run-time of your algorithm must be o(n^2)  (little-oh of n^2).

Q3: (0, 1/2, 1)-Knapsack
In this version, each x_i takes the value 0 or 1/2 or 1.  That is, we include the object in full (1) or in half (1/2) or not included at all (0).
Present a DP (clearly mention the recursive solution, optimal substructure in the code itself) and its implementation in C++.   Run-time must be polynomial in 'n'.

Q4: List all feasible solutions of (0,1)-Knapsack.
Feasible soln: A soln S containing objects is feasible if the sum of weights of objects in S does NOT exceed W.
Optimal soln:  A feasible solution that maximizes the profit.
Example:   3 objects with w_1=1, w_2=2, w_3=3, p_1=10,p_2=20,p_3=30, W=10.
Any subset of {x_1,x_2,x_3} is a feasible solution.
Write a C++ code that LISTs ALL feasible solutions.  Also, print the count (the no of feasible solns)
```
