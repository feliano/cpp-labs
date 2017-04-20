## Lab 4 - Lambdas

#### What is a capture list in a lambda expression?
It specifies which varaibles can be passed from outside to the inside of the body

#### What does & mean inside the parameter list?
It allows for any reference outside of the lambda scope to be accessed in the body of the lambda function.

#### When could capturing data by reference [&] be useful?
that any variable in scope can be passed in to the body by reference

#### What does {4} in the code below do?

```
struct A {
    int data;

};

A * p = new A {4} ;
```

aggregate initialization. Sets 'data' to 4;
aggregate has no private or protected data members
has no user defined constructors

#### Why is it a compile error to call foo with a unique_ptr without a move?
```
void foo(unique_ptr<A> p) {
    cout << p->data << endl;
}

//...

foo(pa);

```
A unique_ptr cannot be copied therefore one has to use move.

#### Was there ever a memory leak when calling foo2 with a shared pointer?
No smart pointers such as shared_ptr automatically deletes the object to which it points.

#### What is the use of a weak_ptr?
accessing the object pointed to by a shared pointer
cyclic dependencies: shared_ptr in parent pointing to child with weak_ptr pointing back. Having shared_ptr in both would result in memory leaks.

#### How do you create a unique_ptr with a special deleter?
you specify it in the type declaration and provide it as a parameter.
Example:

```
auto deleter = [&](B* b){
	delete[] b;
};

unique_ptr<B, decltype(deleter)> pb2(new B[2], deleter);
```

Another Example:
```
unique_ptr<B, function<void(B*)> > pb1(new B[2], [&](B* b){
	delete[] b;
});
```

#### What is decltype ?
It's a keyword that inspects the type of an expression. Like in the above example with decltype(deleter) looking up the type of the lambda.

#### What is std::function?
"std::function can store, copy, and invoke any Callable target meaning". This means that an object of this type can hold a specific function call.
For example:

```
struct A {
void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

// ...

std::function<void(int)> calling_a = A();
calling_a(10);
```

output: 
```
10
```


#### What did you learn in this assignement?
How lambda functions and smart pointers work.


