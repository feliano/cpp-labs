#include <cxxtest/TestSuite.h>
#include "iterator.h"

static int TEST_ID = 0;


class MyTestSuite : public CxxTest::TestSuite {
  public:

    /*

	void insert(Node<int,double> * & p, int key, double to_be_inserted);
	void remove(Node * & p, const int & key);
	const double & find(Node * p, const int & to_be_found);
	double & edit(Node * p, const double & to_be_changed);
	void delete_tree(Node * & p);

	unsigned int max_height(Node * p);
	unsigned int min_height(Node * p);
	unsigned int size(Node * p);
	bool is_balanced(Node * p);

	Node * best_replacement(Node * p, const int & key);
    */

  	// TEST FUNCTIONS WITH NULL POINTER
    void test1 () {
    	// SYNOPSIS:
    	// insert(nullptr)
    	// a new node should be inserted as root of the tree

    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p, 5, 2.1);
		TS_ASSERT_EQUALS(p->key,5);
		delete_tree(p);

    }

    void test2 () {
    	// SYNOPSIS
    	// remove (nullptr,10)
    	// should throw out of range exception
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
    	try{
			remove(p,10);
			TS_FAIL("nothing to remove - should throw out of range exception");
    	}catch(std::exception& e){
    		std::cout << e.what() << std::endl;
    	}
		delete_tree(p);

    }

    void test3() {
    	//SYNOPSIS:
    	// find(nullptr,10),
    	// should throw out of range exception

    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
    	try{
			find(p,10);
			TS_FAIL("nothing to find - should throw out of range exception");
    	}catch(std::exception& e){
    		std::cout << e.what() << std::endl;
    	}
		delete_tree(p);

    }

    void test4() {
    	// SYNOPSIS
    	// edit(nullptr)
    	// should throw out of range exception

    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
    	try{
			edit(p,10);
			TS_FAIL("nothing to edit - should throw out of range exception");
    	}catch(std::exception& e){
    		std::cout << e.what() << std::endl;
    	}
		delete_tree(p);

    }
	
    void test5() {
    	// SYNOPSIS
    	// delete_tree(nullptr)
    	// should throw out of range exception

    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
    	delete_tree(p);	
    	TS_ASSERT_EQUALS(p,nullptr);

    }

    void test6() {
    	//SYNOPSIS
    	// call max_height() with nullptr
    	// should return 0;

    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

    	Node<int,double> * p = nullptr;
    	unsigned int height = max_height(p);

    	TS_ASSERT_EQUALS(height,0);
		delete_tree(p);

    }


    void test7() {
    	//SYNOPSIS
    	// call min_height() with nullptr
    	// should return 0;

    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

    	Node<int,double> * p = nullptr;
    	unsigned int height = min_height(p);

    	TS_ASSERT_EQUALS(height,0);
		delete_tree(p);

    }


    void test8() {
    	//SYNOPSIS
    	// call size() with nullptr
    	// should return 0
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

    	Node<int,double> * p = nullptr;
    	unsigned int s = size(p);

    	TS_ASSERT_EQUALS(s,0);
		delete_tree(p);

    }

    void test9() {
    	//SYNOPSIS
    	// call is_balanced() with nullptr
    	// should return true
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

    	Node<int,double> * p = nullptr;
		bool b = is_balanced(p);

    	TS_ASSERT_EQUALS(b,true);
		delete_tree(p);

    }

    void test10() {
		//SYNOPSIS
    	// call best_replacement() with nullptr
    	// should return true
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

    	Node<int,double> * p = nullptr;

    	try{
    		best_replacement(p);
    		TS_FAIL("can't find best best_replacement in empty tree");
    	}catch(std::exception& e){
    		std::cout << e.what() << std::endl;
    	}
		delete_tree(p);

    }


    // TEST FUNCTIONS WITH TREE OF SIZE 1;
    //
    //

    void test11() {
    	//SYNOPSIS
    	// insert()
    	// should return size two, child node's key and data: 3, 3.0

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

    	Node<int,double> * p = nullptr;
    	insert(p,5,2.0);
    	insert(p,3,3.0);

    	TS_ASSERT_EQUALS(size(p),2);
    	TS_ASSERT_EQUALS(p->left->key,3);
    	TS_ASSERT_EQUALS(p->left->data,3.0);
		delete_tree(p);

    }

    void test12() {
    	//SYNOPSIS
    	// remove() on tree of size 1
    	// p should be nullptr
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

    	Node<int,double> * p = nullptr;
    	insert(p,5,2.0);
		remove(p,5);
    	
    	TS_ASSERT_EQUALS(p,nullptr);
		TS_ASSERT_EQUALS(size(p),0);

		delete_tree(p);

	}

	void test13() {
		// SYNOPSIS
		// find() with tree of size 1
		// data should be 3.1

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,4,3.1);

		TS_ASSERT_EQUALS(find(p,4),3.1);

		delete_tree(p);

	}

	void test14() {
		// SYNOPSIS
		// edit() with tree of size 1
		// data should be 2.0

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,4,3.1);

		double & val = edit(p,4);
		val = 2.0;

		TS_ASSERT_EQUALS(find(p,4),2.0);

		delete_tree(p);

	}

	void test15() {
		// SYNOPSIS
		// delete_tree() with tree of size 1
		// size should be 0

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,4,3.1);

		delete_tree(p);

		TS_ASSERT_EQUALS(size(p),0);
	}

	void test16() {
		// SYNOPSIS
		// max_height() with tree of size 1
		// height should be 1

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,4,3.1);

		TS_ASSERT_EQUALS(max_height(p),1);
		delete_tree(p);

	}


	void test17() {
		// SYNOPSIS
		// min_height() with tree of size 1
		// height should be 1

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,4,3.1);

		TS_ASSERT_EQUALS(min_height(p),1);
		delete_tree(p);

	}


	void test18() {
		// SYNOPSIS
		// size() with tree of size 1
		// size should be 1

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,4,3.1);

		TS_ASSERT_EQUALS(size(p),1);
		delete_tree(p);

	}


	void test19() {
		// SYNOPSIS
		// is_balanced() with tree of size 1
		// should be true
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,5,3.1);
	
		TS_ASSERT_EQUALS(is_balanced(p),true);
		delete_tree(p);
	}

	void test20() {
		// SYNOPSIS
		// is_balanced() with tree of size 1
		// should be true
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,4,3.1);

		TS_ASSERT_EQUALS(is_balanced(p),true);
		delete_tree(p);
	}

    // TEST FUNCTIONS WITH TREE OF SIZE > 1;
    //
    //

	void test21() {
		// SYNOPSIS
		// insert() with tree of size > 1
		// node hierarchy should match and size should be 5 

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,4,13.1);
		insert(p,2,0.1);
		insert(p,3,20.3);
		insert(p,7,10.1);
		insert(p,8,3.9);

		TS_ASSERT_EQUALS(p->key,4);
		TS_ASSERT_EQUALS(p->data,13.1);
		TS_ASSERT_EQUALS(p->left->key,2);
		TS_ASSERT_EQUALS(p->left->data,0.1);
		TS_ASSERT_EQUALS(p->left->right->key,3);
		TS_ASSERT_EQUALS(p->left->right->data,20.3);
		TS_ASSERT_EQUALS(p->right->key,7);
		TS_ASSERT_EQUALS(p->right->data,10.1);
		TS_ASSERT_EQUALS(p->right->right->key,8);
		TS_ASSERT_EQUALS(p->right->right->data,3.9);

		TS_ASSERT_EQUALS(size(p),5);

		delete_tree(p);
	}


	void test22() {
		// SYNOPSIS
		// remove() with tree of size > 1
		// node hierarchy should match
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,5,13.1);
		insert(p,3,0.1);
		insert(p,2,20.3);
		insert(p,4,10.1);
		insert(p,8,3.9);
		insert(p,7,3.9);

		remove(p,3);

		TS_ASSERT_EQUALS(p->key,5);
		TS_ASSERT_EQUALS(p->data,13.1);
		TS_ASSERT_EQUALS(p->left->key,4);
		TS_ASSERT_EQUALS(p->left->data,10.1);

		TS_ASSERT_EQUALS(size(p),5);

		delete_tree(p);
	}

	void test23() {
		// SYNOPSIS
		// find() with tree of size > 1
		// insert(p,k,d);
		// d == find(p,k);
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,5,13.1);
		insert(p,3,0.1);
		insert(p,2,20.3);
		insert(p,4,10.1);
		insert(p,8,3.9);
		insert(p,7,4.8);

		TS_ASSERT_EQUALS(find(p,5),13.1);
		TS_ASSERT_EQUALS(find(p,3),0.1);
		TS_ASSERT_EQUALS(find(p,2),20.3);
		TS_ASSERT_EQUALS(find(p,4),10.1);
		TS_ASSERT_EQUALS(find(p,8),3.9);
		TS_ASSERT_EQUALS(find(p,7),4.8);

		delete_tree(p);
	}

	void test24() {
		// SYNOPSIS
		// edit() with tree of size > 1
		// insert(p,k,d);
		// edit(p,k) == find(p,k)

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,5,13.1);
		insert(p,3,0.1);
		insert(p,2,20.3);
		insert(p,4,10.1);
		insert(p,8,3.9);
		insert(p,7,4.8);

		TS_ASSERT_EQUALS((edit(p,5) = 10.0),find(p,5));
		TS_ASSERT_EQUALS((edit(p,3) = 13.0),find(p,3));
		TS_ASSERT_EQUALS((edit(p,2) = 21.3),find(p,2));
		TS_ASSERT_EQUALS((edit(p,4) = 10.7),find(p,4));
		TS_ASSERT_EQUALS((edit(p,8) = 3.2),find(p,8));
		TS_ASSERT_EQUALS((edit(p,7) = 4.7),find(p,7));

		delete_tree(p);
	}

	void test25() {
		// SYNOPSIS
		// delete_tree() with tree of size > 1
		// size of p should be 0 and 

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,5,13.1);
		insert(p,3,0.1);
		insert(p,2,20.3);
		insert(p,4,10.1);
		insert(p,8,3.9);
		insert(p,7,4.8);
		insert(p,10,10.1);
		insert(p,15,3.9);
		insert(p,1,4.8);

		delete_tree(p);

		TS_ASSERT_EQUALS(size(p),0);
		TS_ASSERT_EQUALS(p,nullptr);
	}

	void test26() {
		// SYNOPSIS
		// max_height() with tree of size > 1
		// height should be 4 

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,5,13.1);
		insert(p,3,0.1);
		insert(p,2,20.3);
		insert(p,4,10.1);
		insert(p,8,3.9);
		insert(p,7,4.8);
		insert(p,10,10.1);
		insert(p,15,3.9);
		insert(p,1,4.8);

		TS_ASSERT_EQUALS(max_height(p),4);

		delete_tree(p);
	}

	void test27() {
		// SYNOPSIS
		// min_height() with tree of size > 1
		// height should be 2 

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,5,13.1);
		insert(p,3,0.1);
		insert(p,2,20.3);
		insert(p,4,10.1);
		insert(p,8,3.9);
		insert(p,7,4.8);
		insert(p,10,10.1);
		insert(p,15,3.9);
		insert(p,1,4.8);


		TS_ASSERT_EQUALS(min_height(p),3);

		delete_tree(p);
	}

	void test28() {
		// SYNOPSIS
		// size() with tree of size > 1
		// size should be 11

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,5,13.1);
		insert(p,3,0.1);
		insert(p,2,20.3);
		insert(p,4,10.1);
		insert(p,8,3.9);
		insert(p,7,4.8);
		insert(p,10,10.1);
		insert(p,15,3.9);
		insert(p,1,4.8);
		insert(p,12,1.9);
		insert(p,13,9.8);

		TS_ASSERT_EQUALS(size(p),11);

		delete_tree(p);
	}

	void test29() {
		// SYNOPSIS
		// is_balanced() with tree of size > 1
		// first one should be true, second one false 

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,5,13.1);
		insert(p,3,0.1);
		insert(p,2,20.3);
		insert(p,4,10.1);
		insert(p,8,3.9);
		insert(p,7,4.8);
		insert(p,10,10.1);

		TS_ASSERT_EQUALS(is_balanced(p),true);

		insert(p,15,3.9);
		insert(p,1,4.8);
		insert(p,12,1.9);
		insert(p,13,9.8);

		TS_ASSERT_EQUALS(is_balanced(p),false);

		delete_tree(p);
	}

	void test30() {
		// SYNOPSIS
		// best_replacement() with tree of size > 1
		// x -> y (x replaces y)
		// 15->13
		// 3->4
		// 1->nullptr
		// 10->9
		// 5->4

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,5,13.1);
		insert(p,3,0.1);
		insert(p,2,20.3);
		insert(p,4,10.1);
		insert(p,8,3.9);
		insert(p,7,4.8);
		insert(p,10,10.1);
		insert(p,15,3.9);
		insert(p,1,4.8);
		insert(p,12,1.9);
		insert(p,13,9.8);
		insert(p,29,2.9);
		insert(p,9,7.8);
		insert(p,22,2.9);
		insert(p,19,7.8);

	
		TS_ASSERT_EQUALS(best_replacement(p->right->right->right)->key,13);
		TS_ASSERT_EQUALS(best_replacement(p->left)->key,4);
		TS_ASSERT_EQUALS(best_replacement(p->left->left->left),nullptr);
		TS_ASSERT_EQUALS(best_replacement(p->right->right)->key,9);
		TS_ASSERT_EQUALS(best_replacement(p)->key,4);

		delete_tree(p);
	}


	void test31() {
		// SYNOPSIS
		// provoke std::out_of_range
		// find()

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);




		try{
			find(p,11);
			TS_FAIL("Should throw out of range exception");
		}catch (std::out_of_range& e){
			std::cout << e.what() << std::endl;
		}

		delete_tree(p);
	}


	void test32() {
		// SYNOPSIS
		// provoke std::out_of_range
		// edit()

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);


		try{
			edit(p,17);
			TS_FAIL("Should throw out of range exception");
		}catch (std::out_of_range& e){
			std::cout << e.what() << std::endl;
		}
		
		delete_tree(p);
	}

	void test33() {
		// SYNOPSIS
		// provoke std::out_of_range
		// remove()

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		
		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);

		try{
			remove(p,17);
			TS_FAIL("Should throw out of range exception");
		}catch (std::out_of_range& e){
			std::cout << e.what() << std::endl;
		}
		
		delete_tree(p);
	}


	// non-const iterator
	void test34() {
		// Synopsis
		// Test correct iteration order
		//

		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);

		auto it = p->begin();
		std::vector<double> values = {10.1,8.1,3.1,13.1,1.1,20.1,32.1,98.1};  

		for(int i = 0;i<values.size();++i){
			TS_ASSERT_EQUALS(*it,values[i]);
			++it;
		}
		delete_tree(p);
	}

	void test35() {
		// Synopsis
		// while iteration stops correctly
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);

		auto it = p->begin();
	
		int count = 0;
		while(it != p->end()){
			++it;
			++count;
			if(count > 8) TS_FAIL("looped out of range");
		}

		TS_ASSERT_EQUALS(count,8);

		delete_tree(p);
	}

	void test36() {
		// Synopsis
		// copy construction of iterator
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);

		Node<int,double>::iterator a = p->begin();
		TS_ASSERT_EQUALS(*a,10.1);
		a++;
		Node<int,double>::iterator b(a);
		TS_ASSERT_EQUALS(*a,8.1);
		TS_ASSERT_EQUALS(*a,*b);
		b++;
		TS_ASSERT_EQUALS(*a,8.1);
		TS_ASSERT_EQUALS(*b,3.1);				

		delete_tree(p);
	}

	void test37() {
		// Synopsis
		// copy assignent of iterator
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);

		Node<int,double>::iterator a = p->begin();
		TS_ASSERT_EQUALS(*a,10.1);
		a++;
		Node<int,double>::iterator b(nullptr);
		b = a;
		TS_ASSERT_EQUALS(*a,8.1);
		TS_ASSERT_EQUALS(*a,*b);
		b++;
		TS_ASSERT_EQUALS(*a,8.1);
		TS_ASSERT_EQUALS(*b,3.1);				

		delete_tree(p);
	}

	void test38() {
		// Synopsis
		// Comparison operator== of iterator
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);

		Node<int,double>::iterator a = p->begin();
		Node<int,double>::iterator b = p->begin();
		
		a++;
		TS_ASSERT_EQUALS(a==b,false);
		b++;

		while(a != p->end()){
			++a;
			++b;
			TS_ASSERT_EQUALS(a==b,true);
		}
		delete_tree(p);
	}

	void test39() {
		// Synopsis
		// Comparison operator!= of iterator
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);

		Node<int,double>::iterator a = p->begin();
		Node<int,double>::iterator b = p->begin();
		

		a++;
		TS_ASSERT_EQUALS(a!=b,true);
		b++;

		while(a != p->end()){
			++a;
			++b;
			TS_ASSERT_EQUALS(a==b,true);
		}
		delete_tree(p);
	}

	void test40() {
		// Synopsis
		// dereference (indirection) operator*() of iterator
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);

		Node<int,double>::iterator a = p->begin();
		Node<int,double>::iterator b = p->begin();
		
		a++;
		b++;

		while(a != p->end()){
			
			++a;
			++b;
			TS_ASSERT_EQUALS(a==b,true);
		}
		delete_tree(p);
	}


	void test41() {
		// Synopsis
		// dereference and value assignment
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);

		Node<int,double>::iterator a = p->begin();
		Node<int,double>::iterator b = p->begin();
		
		a++;
		*a = 89.0;
		b++;
		TS_ASSERT_EQUALS(*b,89.0);
		delete_tree(p);
	}

	void test42() {
		// Synopsis
		// swap iterators
		// std::swap(a,b)
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);
		insert(p,21,98.1);
		insert(p,30,17.1);
		insert(p,25,48.1);

		Node<int,double>::iterator a = p->begin();
		Node<int,double>::iterator b = p->begin();
	
		a++;
		a++;
		TS_ASSERT_EQUALS(*a,3.1);		
		TS_ASSERT_EQUALS(*b,10.1);		
		std::swap(a,b);
		TS_ASSERT_EQUALS(*a,10.1);		
		TS_ASSERT_EQUALS(*b,3.1);		

		delete_tree(p);
	}

	void test43() {
		// Synopsis
		// const_iterator
		// const_iterator can be converted to iterator
		// not the other way around
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);
		insert(p,21,98.1);
		insert(p,30,17.1);
		insert(p,25,48.1);

		Node<int,double>::const_iterator a = p->cbegin();
		Node<int,double>::iterator b = p->begin();
	
		a++;
		a++;
		a = b;
		//*a = 17.3;
		TS_ASSERT_EQUALS(*a,10.1);		
		TS_ASSERT_EQUALS(*b,10.1);		
	
		delete_tree(p);
	}

	void test44() {
		// Synopsis
		// a->member (access data's member member) 
		// and modify
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		struct S
		{
			int gold_member;
		};

		Node<int,S> * p = nullptr;
		insert(p,30,S{10});
		insert(p,25,S{12});
		insert(p,20,S{14});
		insert(p,31,S{18});
		insert(p,33,S{11});

		Node<int,S>::const_iterator a = p->cbegin();
		Node<int,S>::iterator b = p->begin();

		std::vector<int> v = {14,12,10,18,11};


		for(int i = 0; i<v.size(); ++i){
			TS_ASSERT_EQUALS(a->gold_member,v[i]);
			a++;
			b->gold_member = 88;
			TS_ASSERT_EQUALS(b->gold_member,88);
		}

		delete_tree(p);
	}

	void test45() {
		// Synopsis
		// std::swap(a,b)
		// swap two iterators
		// can't swap const_iterator and iterator
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);
		insert(p,21,98.1);
		insert(p,30,17.1);
		insert(p,25,48.1);
		
		Node<int,double>::iterator a = p->begin();
		Node<int,double>::iterator b = p->begin();

		++b;
		std::swap(a,b);

		TS_ASSERT_EQUALS(*a,8.1);
		TS_ASSERT_EQUALS(*b,10.1);

		delete_tree(p);
	}

	void test46() {
		// Synopsis
		// std::swap(a,b)
		// swap two iterators
		// can't swap const_iterator and iterator
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

		Node<int,double> * p = nullptr;
		insert(p,10,13.1);
		insert(p,6,8.1);
		insert(p,8,3.1);
		insert(p,12,20.1);
		insert(p,11,1.1);
		insert(p,20,98.1);
		insert(p,18,32.1);
		insert(p,3,10.1);
		insert(p,21,98.1);
		insert(p,30,17.1);
		insert(p,25,48.1);
		
		Node<int,double>::const_iterator a = p->cbegin();
		Node<int,double>::const_iterator b = p->cbegin();

		++b;
		std::swap(a,b);

		TS_ASSERT_EQUALS(*a,8.1);
		TS_ASSERT_EQUALS(*b,10.1);

		delete_tree(p);
	}


	void test47() {
		// Synopsis
		// <int,char> iterator
		
		std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;

	    Node<int, char> * P = nullptr;
	    insert(P, 1, 'a');
	    Node<int,char>::iterator I = P->begin();
	    *I = 5;             // sets the data field (3) to 'b'

		TS_ASSERT_EQUALS(*I,5);

		delete_tree(P);
	}





};