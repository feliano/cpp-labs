## Lab 9 - Iterator

Questions
####Is there another way of implementing the iterator class instead of inheriting from forward_iterator?
forward_iterator defines a lot of typedefs which are useful when passing the iterator to iterator_traits. 

Otherwise your class could add these typedefs manually.

```
template <class Iterator>
struct iterator_traits {
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type        value_type;
	typedef typename Iterator::difference_type   difference_type;
	typedef typename Iterator::pointer           pointer;
	typedef typename Iterator::reference         reference;
};
```

Iterator traits is a common interface to access traits of an iterator, e.g. what value type the iterator is pointing to is.

"Standard algorithms determine certain properties of the iterators passed to them and the range they represent by using the members of the corresponding iterator_traits instantiation."



####How do you keep track of which nodes you already visited when iterating?
I don't, I just keep track where the iterator is at the moment then it follows simple rules which will move it in the right direction.

If node has right child: get the leftmost node of the subtree (where right child is top)
Otherwise move back up: if parent is to the left continue backing up, if parent is to the right that's the next node to move to. 

####What sort of access rights should you use on the Node class?
Yes you should at least make key private and use an accessor which can handle the value change, i.e reorder the nodes.
Without reordering it's going to mess up the tree and ruin the search functions.

Data should probably also be this but it's not as important as for key.

####If your test classes needs access rights to private members, how should you manage that?
Depends on testing philosophy, in black box testing you should only test the public interface. But otherwise you could add the test class as a friend to the node class or provide special accessors for the test class, though I much prefer the former.

Assuming protected members. Another solution is to derive from the class to test and then add some extra accessors to the derived class for the protected members. 

####This assignement has forced you to write a Node class and functions that operatoes on the Node. The usual object oreiented solution is to have a Binarytree class with member functions that operate on an internal Node class. What benefits would that solution have compared to the assignment?
With the usual approach we would only have had to template the Node class and not each function. We would also improve encapsulation by removing access to private members from outside the class (via friends).

####What was the most difficult in this assignment?
remove code duplication in const non-const int

