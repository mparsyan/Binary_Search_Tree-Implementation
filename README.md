# Binary Search Tree (BST) Implementation

This C++ implementation provides a basic Binary Search Tree structure with various functions for insertion, removal, searching, traversal, and other operations.

## Overview

A Binary Search Tree is a hierarchical data structure where each node has at most two children, referred to as the left and right subtrees. The key property of a BST is that the left child of a node contains values smaller than the node's value, and the right child contains values greater than the node's value.

## Class: `BST<T>`

### Public Methods:

1. **Constructor: `BST()`**
   - Creates an empty BST.

2. **Destructor: `~BST()`**
   - Deallocates memory used by the BST.

3. **Insertion: `void insert(const T& value)`**
   - Inserts a new node with the given value into the BST.

4. **Removal: `void remove(const T& value)`**
   - Removes a node with the specified value from the BST.

5. **Searching: `bool search(const T& value)`**
   - Checks if a node with the given value exists in the BST.

6. **Traversal:**
   - `void inorder()`: Performs an in-order traversal (left-root-right).
   - `void preorder()`: Performs a pre-order traversal (root-left-right).
   - `void postorder()`: Performs a post-order traversal (left-right-root).
   - `void level_order()`: Performs a level-order traversal.

7. **Minimum and Maximum:**
   - `T find_min() const`: Finds the minimum value in the BST.
   - `T find_max() const`: Finds the maximum value in the BST.

8. **Successor and Predecessor:**
   - `T successor(const T& value)`: Finds the successor of a node with the given value.
   - `T predecessor(const T& value)`: Finds the predecessor of a node with the given value.

9. **Tree Information:**
   - `int height()`: Returns the height of the BST.
   - `int size()`: Returns the number of nodes in the BST.

10. **Validation: `bool is_valid_bst()`**
    - Checks if the BST satisfies the properties of a Binary Search Tree.

11. **Serialization: `std::vector<T> serialize()`**
    - Serializes the BST into a vector using an in-order traversal.

12. **Range Query: `void range_query(int start, int end)`**
    - Prints values within the specified range.

13. **Copy: `Node* copy()`**
    - Creates a deep copy of the BST.

14. **kth Smallest and Largest:**
    - `T kth_smallest(const int& k)`: Finds the kth smallest element in the BST.
    - `T kth_largest(const int& k)`: Finds the kth largest element in the BST.

15. **Update: `void update(int value, int new_value)`**
    - Updates a node with the specified value to a new value.

### Private Helper Methods:

- Several private helper methods are used for implementing the main functionality, including insertion, removal, traversal, and validation.




## How to Use

### Downloading the Code

1. **Clone the Repository:**
   - Open a terminal or command prompt.
   - Run the following command to clone the repository to your local machine:
     ```bash
     git clone https://github.com/mparsyan/Binary_Search_Tree-Implementation.git
     ```

2. **Navigate to the Project Folder:**
   - Change to the directory where you cloned the repository:
     ```bash
     cd your-repository
     ```

### Running the Code

1. **Compile the Code:**
   - Use a C++ compiler (e.g., g++) to compile the source files. Assuming you have the `g++` compiler installed, run:
     ```bash
     g++ main.cpp -o my_program
     ```

2. **Run the Executable:**
   - Execute the compiled program:
     ```bash
     ./my_program
     ```

3. **Explore the HashMap:**
   - Open the `main.cpp` file to see an example of how to use the `HashMap` class.

   ```cpp
   #include "hash_map.hpp"

   int main() {
       // Create a HashMap instance
       HashMap<int, std::string> myMap;

       // Insert key-value pairs
       myMap.put(1, "one");
       myMap.put(2, "two");

       // Retrieve and print a value
       std::string result = myMap.get(1);
       std::cout << "Value for key 1: " << result << std::endl;

       // Check if a key exists
       bool containsKey = myMap.containsKey(1);
       std::cout << "Contains key 1: " << (containsKey ? "Yes" : "No") << std::endl;

       // ...

       return 0;
   }
