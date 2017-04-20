#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct MY {
void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};


struct A {
    int data;

};

struct B {
    B() { b = new int[4]; }

    int * b;
    ~B() { delete [] b; }
    B(const B &) = delete;
    void operator= (const B & ) = delete;
};

void foo(unique_ptr<A> p) {
    cout << p->data << endl;
}

void foo2(shared_ptr<A> p) {
    cout << p->data << endl;
}



struct BhasA;

struct AhasB {
    AhasB(shared_ptr<BhasA> b) : m_b(b)  {
        resource = new int[4];
    };

    weak_ptr<BhasA> m_b;
    int * resource;

    ~AhasB() {delete [] resource;}
    AhasB(const AhasB &) = delete;
    void operator=(const AhasB &) = delete;
};

struct BhasA {
    BhasA() {resource = new int[4];};

    shared_ptr<AhasB> m_a;
    int * resource;

    ~BhasA() {delete [] resource;}
    BhasA(const BhasA &) = delete;
    void operator=(const BhasA &) = delete;
};





//...
int main() {

	/** PART. 1 LAMBDAS*/
    vector<int> v = {1, 3, 4, 5, 6, 7, 8, 9};
    
    // printing odd numbers
    for_each(v.cbegin(), v.cend(), [](int a){if ((a % 2) != 0) cout << a << endl;}); // lambda here

    // multiply odd numbers by 2
    for_each(v.begin(), v.end(), [](int& a){
    	if((a % 2) != 0) a=a*2;
    }); // lambda here

    // printing v
    cout << "vector v:" << endl;
    for (auto x : v) { cout << x << " ";};
    cout << endl;

    // add vector size to each element
	int size = v.size();
    for_each(v.begin(), v.end(), [size](int& a){
    	a+=size;
    }); // lambda here

    cout << "vector v:" << endl;
    for (auto x : v) { cout << x << " ";};
    cout << endl;

    vector<int> v1 = {1, 1, 1, 1, 1, 1, 1, 1};
	// pass data from outside to inside and change something
    for_each(v.begin(), v.end(), [& v](int& a){
    	a=v[3];
    }); // lambda here

    cout << "vector v:" << endl;
    for (auto x : v) { cout << x << " ";};
    cout << endl;
	


	/** PART. 2 POINTERS*/
	
	// UNIQUE POINTER
	{ 
		unique_ptr<A> pa(new A {4} );
		cout << pa -> data;

        //foo(pa); // unique pointer cannot be copied
		foo(std::move(pa));
	}

	// SHARED POINTER & WEAK POINTER
	{
		shared_ptr<A> sa(new A {5});
	    cout << sa -> data;

        //foo2(sa);            // check with valgrind
        foo2(move(sa));    // check with valgrind    
        //weak_ptr<A> wa(new A {5});
        weak_ptr<A> wa = sa;

        if(shared_ptr<A> sp = wa.lock()){
	        cout << sp->data;
	    }
	}

	// CIRCULAR DEPENDENCIES
	{
	    shared_ptr<BhasA> bptr(new BhasA);
        shared_ptr<AhasB> aptr(new AhasB(bptr));
        bptr->m_a=aptr;
    }

    // USING A DELETER
    {
        //unique_ptr<B> pb(new B[2]); // not expect array - but adding <B[]> solves it

        auto deleter = [&](B* b){
			delete[] b;
	    };
    
        unique_ptr<B, decltype(deleter)> pb2(new B[2], deleter);

        unique_ptr<B, function<void(B*)> > pb1(new B[2], [&](B* b){
			delete[] b;
	    });

    }


    // TEST AREA
    {

		// ...

		std::function<void(int)> calling_a = MY();
		calling_a(10);

    }


	return 0;
}