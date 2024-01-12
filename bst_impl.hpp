#ifndef BST_IMPL_HPP
#define BST_IMPL_HPP

// constructor
template <typename T>
BST<T>::BST() : root(nullptr) {}

// destructor
template <typename T>
BST<T>::~BST()
{
    clear();
}

// insert
template <typename T>
void BST<T>::insert(const T& value)
{
    root = insert_helper(root, value);
}

// insert_helper
template <typename T>
typename BST<T>::Node*
BST<T>::insert_helper(Node* root, const T& value)
{
    if (root == nullptr)
    {
        root = new Node(value);
        return root;
    }
    else if (value < root->value)
    {
        root->left = insert_helper(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert_helper(root->right, value);
    }
    return root;
}

// remove
template <typename T>
void BST<T>::remove(const T& value)
{
	root = remove_helper(root, value);		
}

// remove_helper
template <typename T>
typename BST<T>::Node* BST<T>::remove_helper(Node* root, const T& value)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (value < root->value) 
    {
		root->left = remove_helper(root->left, value);
	} 
    else if (value > root->value) 
    {
		root->right = remove_helper(root->right, value);
	} 
    else 
    {	
		if(root->left == nullptr)
        {
            Node* tmp = root->right;
            delete root;
            return tmp;
		} 
        else if (root->right == nullptr) 
        {
            Node* tmp = root->left;
            delete root;
            return tmp;
		}
		Node* tmp = find_min_helper(root->right);
		root->value = tmp->value;
		root->right = remove_helper(root->right, root->value);
	}
	return root;
}

// search
template <typename T>
bool BST<T>::BST::search(const T& value)
{
    if(search_helper(root, value))
    {
        return true;
    }

    return false;
}

// search_helper
template <typename T>
typename BST<T>::Node* BST<T>::search_helper(Node* root, const T& value)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    if(root->value == value)
    {
        return root;
    }

    if(value < root->value)
    {
        return search_helper(root->left, value);
    }

    else 
    {
        return search_helper(root->right, value);
    }
}

// inorder
template <typename T>
void BST<T>::inorder()  // left root right
{   
    inorder_helper(root);
}

// inorder_helper
template <typename T>
void BST<T>::inorder_helper(Node* root)
{
    if (root != nullptr)
    {
        inorder_helper(root->left);
        std::cout << root->value << " ";
        inorder_helper(root->right);
    }
}

// preorder
template <typename T>
void BST<T>::preorder()
{
	preorder_helper(root);  // root left right
}

// preorder_helper
template <typename T>
void BST<T>::preorder_helper(Node* root)   
{
    if(root != nullptr)
    {
        std::cout << root->value << " ";
        preorder_helper(root->left);
        preorder_helper(root->right);
            
    }
}

// postorder
template <typename T>
void BST<T>::postorder()    // left right root
{
	postorder_helper(root);
} 

// postorder_helper
template <typename T>
void BST<T>::postorder_helper(Node* root)   
{
	if(root != nullptr) {
		postorder_helper(root->left);
		postorder_helper(root->right);
		std::cout << root->value << " ";
	}
}

// find_min
template <typename T>
T BST<T>::find_min() const
{
    Node* min_node = find_min_helper(root);
    if (min_node == nullptr) 
    {
        throw std::runtime_error("Tree is empty");
    }
    return min_node->value;
}

// find_min_helper
template <typename T>
typename BST<T>::Node* BST<T>::find_min_helper(Node* root) const
{
	if(root->left == nullptr)
	{
		return root;
	}
	return find_min_helper(root->left);
}

// find_max
template <typename T>
T BST<T>::find_max() const
{
    Node* max_node = find_max_helper(root);
    if (max_node == nullptr) 
    {
        throw std::runtime_error("Tree is empty");
    }
    return max_node->value;
}


// find_max_helper
template <typename T>
typename BST<T>::Node* BST<T>::find_max_helper(Node* root) const
{
	if(root->right == nullptr)
	{
		return root;
	}
	return find_max_helper(root->right);
}

// successor
template <typename T>
T BST<T>::successor(const T& value)
{
    if (search(value))
    {
        Node* succ = nullptr;
        successor_helper(root, succ, value);
        if (succ != nullptr)
        {
            return succ->value;
        }
        else
        {
            throw std::runtime_error("Successor does not exist");        
        }
    }
    else
    {
        throw std::invalid_argument("The tree hasn't a node with this value");        
    }
}

// successor_helper
template <typename T>
typename BST<T>::Node* BST<T>::successor_helper(Node* root, Node*& succ, const T& value) 
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->value == value)
    {
        if (root->right != nullptr)
        {
            Node* tmp = root->right;
            while (tmp->left != nullptr)
            {
                tmp = tmp->left;
            }
            succ = tmp;
        }
    }
    else if (value < root->value)
    {
        succ = root;
        return successor_helper(root->left, succ, value);
    }
    else
    {
        return successor_helper(root->right, succ, value);
    }
    return succ;
}

// predecessor
template <typename T>
T BST<T>::predecessor(const T& value)
{
    if (search(value))
    {
        Node* pred = nullptr;
        predecessor_helper(root, pred, value);
        if (pred != nullptr)
        {
            return pred->value;
        }
        else 
        {
            throw std::runtime_error("Predecessor does not exist");
        }
    }
    else
    {
        throw std::invalid_argument("The tree hasn't a node with this value");        
    }
}

// predecessor_helper
template <typename T>
typename BST<T>::Node* BST<T>::predecessor_helper(Node* root, Node*& pred, const T& value)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->value == value)
    {
        if (root->left != nullptr)
        {
            Node* tmp = root->left;
            while (tmp->right != nullptr)
            {
                tmp = tmp->right;
            }
            pred = tmp;
        }
    }
    else if (value < root->value)
    {
        return predecessor_helper(root->left, pred, value);
    }
    else
    {
        pred = root;
        return predecessor_helper(root->right, pred, value);
    }
    return pred;
}

// height
template <typename T>
int BST<T>::height()
{
    return height_helper(root);
}

// height_helper
template <typename T>
int BST<T>::height_helper(Node* root) 
{
    if (root == nullptr) 
    {
        return 0;
    }
    int left_height = height_helper(root->left);
    int right_height = height_helper(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

// size
template <typename T>
int BST<T>::size()
{
    return size_helper(root);
}

// size_helper
template <typename T>
int BST<T>::size_helper(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left_size = size_helper(root->left);
    int rightSize = size_helper(root->right);
    
    return left_size + rightSize + 1;
}

// is_valid_bst
template <typename T>
bool BST<T>::is_valid_bst()
{
    return is_valid_bst_helper(root);
}

// is_valid_bst_helper
template <typename T>
bool BST<T>::is_valid_bst_helper(Node* root)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->left != nullptr && root->left->value > root->value)
    {
        return false;
    }
    if (root->right != nullptr && root->right->value < root->value)
    {
        return false;
    }

    bool left = is_valid_bst_helper(root->left);
    bool right = is_valid_bst_helper(root->right);
    if (left == true && right == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// print_tree
template <typename T>
void BST<T>::print_tree()
{
    int h = height();
    for (int i = 1; i <= h; ++i)
    {
        std::cout << "Level " << i << ": ";
        level_order_helper(root, i);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// level_order
template <typename T>
void BST<T>::level_order()
{
    int h = height_helper(root);
    for(int i = 1 ; i <= h ; ++i)
    {
        level_order_helper(root,i);
    }
    std::cout << std::endl;
}

// level_order_helper
template <typename T>
void BST<T>::level_order_helper(Node* node, int level)
{
    if(node == nullptr)
    {
        return;
    }

    if(level == 1)
    {
        std::cout << node -> value << " ";
    }

    else if(level > 1)
    {
        level_order_helper(node -> left, level - 1);
        level_order_helper(node -> right , level - 1);
    }
}

// clear
template<typename T>
void BST<T>::clear()
{
    clear_helper(root);
}

// clear_helper
template<typename T>
void BST<T>::clear_helper(Node*& root)
{
    if(root == nullptr)
    {   
        return;
    }

    clear_helper(root->left);
    clear_helper(root->right);
    delete root;
    root = nullptr;  
}

// serialize
template <typename T>
std::vector<T> BST<T>::serialize()
{
    std::vector<T> result;
    serialize_helper(root, result);
    return result;
}

// serialize_helper
template <typename T>
void BST<T>::serialize_helper(Node* root, std::vector<T>& result)
{ 
    if (root != nullptr) 
    {
        serialize_helper(root->left, result);
        result.push_back(root->value);
        serialize_helper(root->right, result);
    }
} 

// range_query
template <typename T>
void BST<T>::range_query(int start, int end)
{
    for(int i = start; i <= end; ++i)
    {
        if(search(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

// copy
template <typename T>
typename BST<T>::Node* BST<T>::copy()
{
    return copy_helper(root);
}

// copy_helper
template <typename T>
typename BST<T>::Node* BST<T>::copy_helper(Node* root) 
{
    if (root == nullptr) 
    {
        return nullptr;
    }

    Node* new_root = new Node(root->value);

    new_root->left = copy_helper(root->left);
    new_root->right = copy_helper(root->right);

    return new_root;
}

// kth_smallest
template <typename T>
T BST<T>::kth_smallest(const int& k)
{
    int index = 0;
    Node* tmp = kth_smallest_helper(root, index, k);
    if (!tmp)
    {
        return -1;
    }
    return tmp->value;
}

// kth_smallest_helper
template <typename T>
typename BST<T>::Node* BST<T>::kth_smallest_helper(Node* root, int& index, const int& k)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    Node* left_result = kth_smallest_helper(root->left, index, k);
    if (left_result != nullptr)
    {
        return left_result;
    }
    index++;
    if (index == k)
    {
        return root;
    }
    return kth_smallest_helper(root->right, index, k);
}

// kth_largest
template <typename T>
T BST<T>::kth_largest(const int& k)
{
    int ind = 0;
    int real_k = size() - k + 1;
    Node* tmp = kth_smallest_helper(root, ind, real_k);
    if(!tmp) 
    {
        return -1;
    } 
    return tmp->value;
}

// update
template <typename T>
void BST<T>::update(int value , int new_value)
{
    if(!search(value))
    {
        std::cout << "Node doesn't exist: " << std::endl;
        return;
    }

    remove(value);
    insert(new_value);
}

#endif  // BST_IMPL_HPP