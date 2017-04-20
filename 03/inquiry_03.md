## Lab 3

#### If the signature of insert was changed like below, how would that affect your code?

Old: void insert(Node * & p, int key, double to_be_inserted);
New: Node * insert(Node * p, int key, double value);

The new one wouldn't affect my code much but I would have to update the tree root node variable outside the function that when I insert the first node. also when removing the last node I would have to return the pointer and update the variable outside.

#### Which of the two insert variants would you prefer? Motivate.

I think the code is cleaner using the old and it wouldn't have to create new local variables each time the function is called and unnecessary assignments can be avoided outside the function.

#### How do you check if two classes are equal if they have only operator< and not operator==?

First check if one is less than the other, then if the other is less than the first. If both are false then they're equal.

#### Does a < b and !(b < a) compare the same thing?

No the first checks if a is less than b. the second if b isn't less than a. They will return the same output if a and b are different but not if they're equal:

a < b returns false if equal
!(b < a) returns true if equal

#### When you tested balancing the tree, what would be the effect if you had removed the tree in each iteration?

There wouldn't be memory leaks...
	
	// do this 800 times
	for(int i = 0; i<800; ++i){
		Node * root = nullptr;
		for(int n : vec){
			insert(root,n,n);
		}
		
		max_res[i] = max_height(root);
		min_res[i] = min_height(root);

		// free up memory
		delete_tree(root); <<<------
		std::next_permutation(vec.begin(),vec.end());		
		//std::shuffle(vec.begin(),vec.end(),std::default_random_engine(SEED));
	}



#### What was hardest to implement in this assignment?

The remove function was the trickiest method when the node to remove wasn't a leaf node (aka had children)

#### What did you learn from this asignment?

How to build a tree hierarchy with pointers