#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <vector>

template <typename T>
class BST
{
public:
    BST();
    ~BST();

private:
    class Node
    {
    public:
        Node* right;
        Node* left;
        T value;
        Node(const T& val) : value(val), right(nullptr), left(nullptr) {}
    };

    Node* root;
    Node* insert_helper(Node* root, const T& value);
    Node* remove_helper(Node* root, const T& value);
    Node* find_min_helper(Node* root) const;
    Node* find_max_helper(Node* root) const;
    Node* search_helper(Node* root, const T& value);
    Node* successor_helper(Node* root, Node*& succ, const T& value);
    Node* predecessor_helper(Node* root, Node*& pred, const T& value);
    Node* copy_helper(Node* root);
    Node* kth_smallest_helper(Node* root, int& index, const int& k);
    void inorder_helper(Node* root);
    void preorder_helper(Node* root);
    void postorder_helper(Node* root);
    void clear_helper(Node* &root);
    void level_order_helper(Node* node, int level);
    void serialize_helper(Node* root, std::vector<T>& result);
    int height_helper(Node* root);
    int size_helper(Node* root);
    bool is_valid_bst_helper(Node* root);

public:
    void insert(const T& value);
    void remove(const T& value);
    bool search(const T& value);
    void inorder();
    void preorder();
    void postorder();
    T find_min() const;
    T find_max() const;
    T successor(const T& value);   
    T predecessor(const T& value);
    int height();
    int size();
    bool is_valid_bst();
    void print_tree();
    void level_order();
    void clear();
    std::vector<T> serialize();
    void range_query(int start, int end);
    Node* copy();
    T kth_smallest(const int& k);
    T kth_largest(const int& k);
    void update(int value, int new_value);
};

#include "bst_impl.hpp"

#endif  // BST_HPP
