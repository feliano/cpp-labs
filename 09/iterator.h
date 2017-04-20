// Lab 9 Iterator for Node class
#include <iostream>
#include <iomanip>

template <class S, class T>
struct Node {

    friend class TREE_ITERATOR;
    friend class CONST_TREE_ITERATOR;
    friend class MyTestSuite;
    template<class U,class V>
    friend void insert(Node<U,V> * & p, U key, V to_be_inserted);
    template<class U,class V>
    friend bool is_balanced(Node<U,V> * p);
    template<class U,class V>
    friend const V & find(Node<U,V> * p, const U & to_be_found);
    template<class U,class V>
    friend V & edit(Node<U,V> * p, const U & to_be_changed);
    template<class U,class V>
    friend void delete_tree(Node<U,V> * & p);
    template<class U,class V>
    friend unsigned int size(Node<U,V> * p);
    template<class U,class V>
    friend Node<U,V> * best_replacement(Node<U,V> * p);
    template<class U,class V>
    friend void remove(Node<U,V> * & p, const U & key);
    template<class U,class V>
    friend void postorder(Node<U,V> * p, int indent);
    template<class U,class V>
    friend void printinorder(Node<U, V> * p);
    template<class U,class V>
    friend unsigned int max_height(Node<U,V> * p);
    template<class U,class V>
    friend unsigned int min_height(Node<U,V> * p);

    S key;
    T data;

    Node(): parent(nullptr),right(nullptr),left(nullptr){}

    struct CONST_TREE_ITERATOR: public std::iterator<std::forward_iterator_tag,Node<S,T> *> {


        CONST_TREE_ITERATOR() = delete;

        CONST_TREE_ITERATOR(Node<S,T> * node){
            // set nullpointer if called by end()
            if(node != nullptr){
                _node = get_left_most(node);
            }else{
                _node = nullptr;
            }
        }

        // Copy Constructor
        CONST_TREE_ITERATOR(const CONST_TREE_ITERATOR & it):_node(it._node){}

        // Copy assigment operator
        CONST_TREE_ITERATOR & operator=(const CONST_TREE_ITERATOR & it){
            _node = it._node;
            return *this;
        }

        // no parameter makes this indirection operator instead of multiplication
        const T & operator*() {
            return _node->data;
        }

        const T * operator->() {
            return & (_node->data);
        }

        // pre-increment
        CONST_TREE_ITERATOR & operator++(){
            // if right has subtree, find leftmost element
            if(_node->right != nullptr){
                _node = get_left_most(_node->right);
                return *this;
            }
            // else back up the tree
            while(_node->parent != nullptr && _node == _node->parent->right){
                _node = _node->parent;
            }
            _node = _node->parent;
            return *this;
        }
        
        //post-increment (takes a dummy int to distinguish between pre and postfix (allowed to have same return type))
        CONST_TREE_ITERATOR operator++(int i){
            this->operator++();
            return *this;
        }

        bool operator==(const CONST_TREE_ITERATOR & other){
            if(_node == other._node){
                return true;
            }else{
                return false;
            }
        }

        bool operator!=(const CONST_TREE_ITERATOR & other){
            return !this->operator==(other);
        }

    protected:

        // get left
        Node<S,T> * get_left_most(Node<S,T> * node){
            while(node->left != nullptr){
                node = node->left; 
            }
            return node;
        }

        Node<S, T> * _node;
    };

    struct TREE_ITERATOR: public CONST_TREE_ITERATOR {

        TREE_ITERATOR() = delete;

        TREE_ITERATOR(Node<S,T> * node): CONST_TREE_ITERATOR(node){}

        // Copy assigment operator
        TREE_ITERATOR & operator=(const TREE_ITERATOR & it){
            CONST_TREE_ITERATOR::_node = it._node;
            return *this;
        }

        // assignment operator for const_iterator (operator(const CONST_TREE_ITERATOR))
        using CONST_TREE_ITERATOR::operator=;

        // no parameter makes this indirection operator instead of multiplication
        T & operator*() {
            return CONST_TREE_ITERATOR::_node->data;
        }

        T * operator->() {
            return & (CONST_TREE_ITERATOR::_node->data);
        }
    };

    typedef TREE_ITERATOR iterator;
    typedef CONST_TREE_ITERATOR const_iterator; 

    iterator begin(){
        return iterator(this);
    }
    
    iterator end(){
        return iterator(nullptr);
    }
            
    const_iterator cbegin(){
        return const_iterator(this);
    }
    const_iterator cend(){
        return const_iterator(nullptr);
    }

private:
    Node<S, T> * parent;    // points to parent node
    Node<S, T> * right;
    Node<S, T> * left;

};

// Node * & p = reference to pointer
// p is root
template <class S, class T>
void insert(Node<S,T> * & p, S key, T to_be_inserted){

    if(p  == nullptr){
        p = new Node<S,T>;
        p->key = key;
        p->data = to_be_inserted;
        p->left = nullptr;
        p->right = nullptr;
    }else if (key < p->key){
        // go to left
        insert(p->left,key,to_be_inserted);
        p->left->parent = p;
    }else if (key > p->key){
        // go to right
        insert(p->right,key,to_be_inserted);
        p->right->parent = p;
    }else{
        // key == p->key  - replace data
        p->data = to_be_inserted;
    }
}

template <class S, class T>
const T & find(Node<S,T> * p, const S & to_be_found){

    // break out when 
    // 1. current Node<S,T> is none or key is match
    Node<S,T> * current = p;
    while (current != nullptr){
        if(current->key == to_be_found){
            return current->data;
        }else if (to_be_found < current->key){
            // go left
            current = current->left;
        }else {
            // go right
            current = current->right;
        }
    }
    // throw exception
    throw std::out_of_range("Key not in tree");
}

template <class S, class T>
T & edit(Node<S,T> * p, const S & to_be_changed){
    Node<S,T> * current = p;
    while (current != nullptr){
        if(current->key == to_be_changed){
            return current->data;
        }else if (to_be_changed < current->key){
            // go left
            current = current->left;
        }else {
            // go right
            current = current->right;
        }
    }
    // throw exception
    throw std::out_of_range("Key not in tree");
}

template <class S, class T>
void delete_tree(Node<S,T> * & p){
    if(p != nullptr){
        delete_tree(p->left);
        delete_tree(p->right);
        //std::cout << "key to del: " << p->key << std::endl;
        delete p;
        p = nullptr;
    }
}

template <class S, class T>
unsigned int size(Node<S,T> * p){
    unsigned int node_count = 0;
    if(p != nullptr){
        node_count++;
        node_count+= size(p->left);
        node_count+= size(p->right);
        return node_count;
    }else{
        return node_count;
    }
}

template <class S, class T>
Node<S,T> * best_replacement(Node<S,T> * p){

    if(p == nullptr){
        throw std::out_of_range("Can't find best_replacement to nullptr");
    }

    const S key = p->key;

    Node<S,T> * best_left_child = p->left;
    Node<S,T> * best_right_child = p->right;
    Node<S,T> * min_node = nullptr;

    int diff_left = 0;
    int diff_right = 0;


    if(best_left_child == nullptr && best_right_child == nullptr){
        // node has no children 
        return nullptr;
    }

    if(best_left_child != nullptr){

        while(best_left_child->right != nullptr){
            best_left_child = best_left_child->right;
        }
        diff_left = key - (best_left_child->key);
    }

    std::cout << "best left: " <<  best_left_child->key << std::endl;


    if(best_right_child != nullptr){
        
        while(best_right_child->left != nullptr){
            best_right_child = best_right_child->left;
        }

        diff_right = (best_right_child->key) - key;
    }

    std::cout << "best right: " <<  best_right_child->key << std::endl;


    if(diff_left != 0 && diff_right != 0){
        // child nodes on both sides
        // check min difference
        std::cout << "best key1: " << diff_left << "  " << diff_right << std::endl;

        if(diff_left < diff_right){
            // diff_left is best
            min_node = best_left_child;
        }else{
            //right is best
            min_node = best_right_child;
        }
    }else if(diff_left == 0 && diff_right != 0){
        // best right is best
        std::cout << "best key2: "  << std::endl;

        min_node = best_right_child;
    }else{
        std::cout << "best key3: " << std::endl;

        // best left is best
        min_node = best_left_child;
    }

    std::cout << "best key: " <<  min_node->key << std::endl;

    return min_node;
}

template <class S, class T>
void remove(Node<S,T> * & p, const S & key){

    //if only one node exists
    if(size(p) == 1){
        delete p;
        p = nullptr;
        return;
    }

    Node<S,T> * node_to_delete = nullptr;
    Node<S,T> * current = p;
    Node<S,T> * parent = nullptr;

    while (current != nullptr){
        if(current->key == key){
            node_to_delete = current;
            std::cout << node_to_delete << " pointer" << std::endl;
            break; 
        }else if (key < current->key){
            // go left
            parent = current;
            current = current->left;
        }else {
            // go right
            parent = current;
            current = current->right;
        }
    }
    if(node_to_delete == nullptr){
        // throw exception
        throw std::out_of_range("Key not in tree, cannot delete non-existing node");
    }

    //find best replacement
    //int best_key = best_replacement(p,key);
    if(node_to_delete->left == nullptr && node_to_delete->right == nullptr){
        // no child nodes just remove node
        delete node_to_delete;
        if(parent != nullptr){
            if(node_to_delete->key < parent->key){
                parent->left = nullptr;             
            }else{
                parent->right = nullptr;                
            }
        }
        node_to_delete = nullptr;
        return;
    }

    Node<S,T> * min_node = best_replacement(node_to_delete);
    std::cout << "best replacement: " << best_replacement(node_to_delete) << std::endl;

    // copy min node's data to p
    node_to_delete->key = min_node->key;
    node_to_delete->data = min_node->data;

    // remove the min node and connect it's children to a parent
    // if only one child replace min
    if(min_node->left == nullptr && min_node->right != nullptr){
        Node<S,T> * node_to_replace = min_node->right;

        std::cout << "HERE 1 " << min_node->key << std::endl;
        // replace min with right child
        min_node->key = node_to_replace->key;
        min_node->data = node_to_replace->data;
        min_node->left = node_to_replace->left;
        min_node->right = node_to_replace->right;

        // delete and return
        delete node_to_replace;
        if(parent != nullptr){
            if(node_to_delete->key < parent->key){
                parent->left = nullptr;             
            }else{
                parent->right = nullptr;                
            }
        }
        node_to_replace = nullptr;
        return;
    }

    if(min_node->right == nullptr && min_node->left != nullptr){
        Node<S,T> * node_to_replace = min_node->left;

        std::cout << "HERE 2 " << min_node->key << std::endl;
        min_node->key = node_to_replace->key;
        min_node->data = node_to_replace->data;
        min_node->left = node_to_replace->left;
        min_node->right = node_to_replace->right;

        delete node_to_replace;
        if(parent != nullptr){
            if(node_to_delete->key < parent->key){
                parent->left = nullptr;             
            }else{
                parent->right = nullptr;                
            }
        }
        node_to_replace = nullptr;
        return;
    }

    // both left right of min_node can be nullptr
    if(min_node->right == nullptr && min_node->left == nullptr){
        std::cout << "HERE 3 " << min_node->key << std::endl;

        if(parent != nullptr){
            if(min_node->key < node_to_delete->key){
                node_to_delete->left = nullptr;             
            }else{
                node_to_delete->right = nullptr;                
            }
        }
        delete min_node;
        return;
    }
}

template <class S, class T>
unsigned int max_height(Node<S,T> * p){
    if(p != nullptr){
        unsigned int left_height = max_height(p->left);
        unsigned int right_height = max_height(p->right);
        return left_height > right_height ? left_height + 1 : right_height + 1;
    }else{
        return 0;
    }
}

template <class S, class T>
unsigned int min_height(Node<S,T> * p){
    if(p != nullptr){
        unsigned int left_height = min_height(p->left);
        unsigned int right_height = min_height(p->right);
        return left_height > right_height ? right_height + 1 : left_height + 1;
    }else{
        return 0;
    }
}

template <class S, class T>
bool is_balanced(Node<S,T> * p){

    /*
    The left and right subtrees' heights differ by at most one, AND
    The left subtree is balanced, AND
    The right subtree is balanced
    */
    if(p != nullptr){
        bool rb = is_balanced(p->right);
        bool lb = is_balanced(p->left);
        int rheight = max_height(p->right);
        int lheight = max_height(p->left);

        if(rb == false || lb == false){
            return false;
        }
        return (std::abs(rheight-lheight) < 2) ? true : false;
    }else{
        return true;
    }
}

template<class S,class T>
void printinorder(Node<S, T> * p) {
    if (p != nullptr) {
        printinorder(p->left);
        std::cout << p->data << std::endl;
        printinorder(p->right);
    }
}

// help print function
template <class S, class T>
void postorder(Node<S,T> * p, int indent){
    if(p != nullptr) {
        if(p->right) {
            postorder(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->key << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->left, indent+4);
        }
    }
}
