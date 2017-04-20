#include "bintree.h"

using namespace bintree;

// Node * & p      = reference to pointer
// p is root
void bintree::insert(Node * & p, int key, double to_be_inserted){

	if(p  == nullptr){
		p = new Node;
		p->key = key;
   		p->data = to_be_inserted;
   		p->left = nullptr;
   		p->right = nullptr;
	}else if (key < p->key){
		// go to left
		insert(p->left,key,to_be_inserted);
	}else if (key > p->key){
		// go to right
		insert(p->right,key,to_be_inserted);
	}else{
		// key == p->key  - replace data
		p->data = to_be_inserted;
	}
}

const double & bintree::find(Node * p, const int & to_be_found){

	// break out when 
	// 1. current node is none or key is match
	Node * current = p;
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

double & bintree::edit(Node * p, const double & to_be_changed){
	Node * current = p;
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

void bintree::delete_tree(Node * & p){
	if(p != nullptr){
		delete_tree(p->left);
		delete_tree(p->right);
		//std::cout << "key to del: " << p->key << std::endl;
		delete p;
		p = nullptr;
	}
}

unsigned int bintree::size(Node * p){
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

Node * bintree::best_replacement(Node * p){

	if(p == nullptr){
		throw std::out_of_range("Can't find best_replacement to nullptr");
	}

	const int key = p->key;

	Node * best_left_child = p->left;
	Node * best_right_child = p->right;
	Node * min_node = nullptr;

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


void bintree::remove(Node * & p, const int & key){

	//if only one node exists
	if(size(p) == 1){
		delete p;
		p = nullptr;
		return;
	}

	Node * node_to_delete = nullptr;
	Node * current = p;
	Node * parent = nullptr;

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

	Node * min_node = best_replacement(node_to_delete);
	std::cout << "best replacement: " << best_replacement(node_to_delete) << std::endl;

	// copy min node's data to p
	node_to_delete->key = min_node->key;
	node_to_delete->data = min_node->data;

	// remove the min node and connect it's children to a parent
	// if only one child replace min
	if(min_node->left == nullptr && min_node->right != nullptr){
		Node * node_to_replace = min_node->right;

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
		Node * node_to_replace = min_node->left;

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

unsigned int bintree::max_height(Node * p){
	if(p != nullptr){
		unsigned int left_height = max_height(p->left);
		unsigned int right_height = max_height(p->right);
		return left_height > right_height ? left_height + 1 : right_height + 1;
	}else{
		return 0;
	}
}

unsigned int bintree::min_height(Node * p){
	if(p != nullptr){
		unsigned int left_height = min_height(p->left);
		unsigned int right_height = min_height(p->right);
		return left_height > right_height ? right_height + 1 : left_height + 1;
	}else{
		return 0;
	}
}

bool bintree::is_balanced(Node * p){

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

/*
int main(){
	std::cout << "TJENA" << std::endl;
	Node * root = nullptr;

	insert(root, 5, 3.0);
	insert(root, 6, 1.0);
	insert(root, 2, 5.0);
	insert(root, 1, 6.0);
	insert(root, 3, 7.1);
	insert(root, 8, 2.3);
	insert(root, 3, 5.1);
	insert(root, 4, 4.1);
	postorder(root);

	std::cout << "max: " << max_height(root) << std::endl;
	std::cout << "min: " << min_height(root) << std::endl;
	std::cout << "est balancée: " << ((is_balanced(root) != 0) ? "true" : "false")  << std::endl;
	
	try{
		remove(root,11);
	}catch(std::exception& e){
		std::cout << e.what() <<std::endl;
	}
	std::cout << "remove" << std::endl;
	postorder(root);

	delete_tree(root);
}
*/
