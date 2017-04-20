#include "iterator.h"


int main(){

	Node<int,double> * root = nullptr;

	insert(root, 5, 3.0);
	insert(root, 6, 1.0);
	insert(root, 2, 5.0);
	insert(root, 1, 6.0);
	insert(root, 3, 7.1);
	insert(root, 8, 2.3);
	insert(root, 3, 5.1);
	insert(root, 4, 4.1);
	postorder(root,0);

	std::cout << "max: " << max_height(root) << std::endl;
	std::cout << "min: " << min_height(root) << std::endl;
	std::cout << "est balancée: " << ((is_balanced(root) != 0) ? "true" : "false")  << std::endl;

	auto it = root->begin();
	//it->data = 4.0;

	*it = 30;

	std::cout << it->data << std::endl;

	auto a = root->begin();
	a = it++;
	*a++;
	std::cout << "node: " << std::endl;
	a++;
	//*a = node;
	*a = 10;
	a->data = 11;
	auto b(a);
	b++;

	auto c = b;

	std::cout << a->data << std::endl;
	std::cout << b->data << std::endl;
	std::cout << "c: " << c->data << std::endl;
	std::swap(a,b);

	std::cout << a->data << std::endl;
	std::cout << b->data << std::endl;



	it = root->begin();

	while(it != root->end()){
		std::cout << it->data << std::endl;
		it++;
	}
	
	std::cout << "const iterator:" << std::endl;
	auto cit = root->cbegin();
	while(cit != root->cend()){
		//cit->data = 12;
		//*cit = 12;
		std::cout << cit->data << std::endl;
		cit++;
	}

	/*
	std::cout << "iterator: " << ", " << it->data << std::endl;
	++it;
	std::cout << "iterator2: " << ", " << it->data << std::endl;
	++it;
	std::cout << "iterator3: " << ", " << it->data << std::endl;
	++it;
	std::cout << "iterator4: " << ", " << it->data << std::endl;
	++it;
	std::cout << "iterator5: " << ", " << it->data << std::endl;
	++it;
	std::cout << "iterator6: " << ", " << it->data << std::endl;
	++it;
	std::cout << "iterator7: " << ", " << it->data << std::endl;
	++it;
	std::cout << "iterator8: " << ", " << it->data << std::endl;
	++it;
	std::cout << "iterator9: " << ", " << it->data << std::endl;
	*/

	try{
		remove(root,11);
	}catch(std::exception& e){
		std::cout << e.what() <<std::endl;
	}
	std::cout << "remove" << std::endl;
	postorder(root,0);

	delete_tree(root);



std::cout << "triple print" << std::endl;
//...
{
    Node<int,double> * root;
	insert(root, 5, 3.0);
	insert(root, 6, 1.0);
	insert(root, 2, 5.0);
	insert(root, 1, 6.0);
	insert(root, 3, 7.1);
	insert(root, 8, 2.3);
	insert(root, 3, 5.1);
	insert(root, 4, 4.1);
    //....
	std::cout << "first print" << std::endl;

    // first print
    printinorder(root);

	std::cout << "second print" << std::endl;

    // second print
    for (auto p = root->begin(); p != root->end(); ++p){
        std::cout << *p << std::endl;
    }

	std::cout << "third print" << std::endl;

    // third print (exactly the same code as above)
    for (auto q = root->begin(); q != root->end(); ++q){
        std::cout << *q << std::endl;
    }	
}





	return 0;

}