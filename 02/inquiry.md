## Lab2 Questions

#### What is the benefit of having a conversion constructor?

It enables implicit conversion. For example Complex(double real); enables conversion from a double to a Complex object.
For example this will happen if 2 + 2_i is run. The first 2 will be implictly converted to a Complex before addition.
Conversion constructors must have single argument (or default values for the others).

#### Which of your class methods or non member functions returns a copy?

const Complex operator+ (const Complex& a, const Complex& b);
const Complex operator- (const Complex& a, const Complex& b);
const Complex operator/ (const Complex& a, const Complex& b);
const Complex operator* (const Complex& a, const Complex& b);

Complex multiplyComplex(const Complex& a, const Complex& b);
Complex operator""_i(long double arg);
Complex operator""_i(unsigned long long arg);

#### Which of your class methods or non member functions returns a reference?

const Complex& operator= (const Complex& c);

friend std::istream& operator>> (std::istream& in, Complex& c);

std::ostream& operator<< (std::ostream& out, const Complex& c);
std::istream& operator>> (std::istream& in, Complex& c);

#### List some sample test cases (math operations) you have examined.

Complex c = a + b - 2 + 2_i * 1.0;
Complex c = a * b / 2_i;
b += a + Complex(10.3,0.4) - 2.1_i;
c -= 5 + 1.0_i * Complex(5,3);
c = b = a;
a *= b;  
a /= b;
a==b;
a!=b;
abs(a);
Complex(1.0,2.2) / Complex(); // division by zero throws exeption

#### Were there any constructor calls in the above list that surprised you?

Yes, that the copy constructor wasn't called for this code:

Complex res = c + d + e; // where c, d and e are Complex objects

In fact no constructor is called for Complex res and the overloaded assignment operator is not called.
But it's the same as doing this: Complex res = Complex(1.0,3.0);
 
I was surprised by how the compiler chose to parse the calculation.
It initializes all the variables from left to right but the first addition
and the subtraction is actually performed before the multiplication.
Also the operations are performed before all objects have been constructed.
I found that interesting. 

  Complex a(2.0,3.0);
  Complex b(9);
  Complex c = a + b - 2 + 2_i * 1.0;

#### Describe and motivate how your implementation of operator= works

const Complex& myLib::Complex::operator= (const Complex& c){
	std::cout << "operator=" << std::endl;
	_real = c.real();
	_imag = c.imag();
	return *this;
}

It takes in an a complex reference and sets the values of this' members to the same as the argument's.
By returning *this as a reference it will allow for chaining:

a = b = c

where all will be set to c.

#### Describe and motivate how your implementation of operator+= -= /= *= works

void myLib::Complex::operator+= (const Complex& c){
	std::cout << "operator+=" << std::endl;
	_real = _real + c.real();
	_imag = _imag + c.imag();
}

They work similarly to the above operator except that I chose not to allow chaining because I think it's unclear.
So instead of returning a reference they return void.


#### What is the rule of three in C++. Look it up in the course book or on the web.

if a class defines any of:

destructor
copy constructor
copy assignment operator

it should probably define all three of them. 

If one is defined that means that the compiler generated one doesn't fit and probably won't for the other two either.

#### Do you need to explicitly define and implement the copy-constructor in this assignement?

No, the standard behaviour of the implicit copy constructor is the same as the explicitly defined one in this lab

#### The literal i has an underscore before it. Why is that? Look it up in the c++11 draft section 17.6.4.3.5 and explain, write the page number #### where you found the explanation as well.

Literal suffix identifiers that do not start with an underscore are reserved for future standardization.
Basically if the standard in the future wants to use literals without underscore they don't want people to already be using those for their own purposes
I found the answer on page 433 in the draft papers.

#### What was the harderst part (or parts) in this assignment?

Getting the makefile right:
I hadn't personally written many makefiles before so this was a fairly new area for me.

Overloading operator>>
At least this took me some time to get right.
Unit testing this wasn't straight forward either and it was more time consuming than the other operators.
