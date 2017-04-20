#### The Matrix

## How many methods/functions have you implemented?

11 methods
+
1 function
+
6 constructors
+
13 operators
+
1 destructor
total = 32

## How many methods/functions have you tested?
28 (remaining are implicitly tested)

## Why should (some?) constructors be explicit? Explain with a code example.
To disable implicit conversion
Example:
Matrix<int> mat2 = mat + 2;  
// 2 would be converted to matrix of size 2 if not constructor not explicit -> 	explicit Matrix(const int size);
// since all elements in matrix are init to 0 it's probably not what one would expect from the above code.

## What is the benefit of a move-constructor? Explain with a code example.
It can remove some of the uneccessary temporaries that would've been created by a copy constructor. 
Example:

// copy
template <class T>
Matrix<T>::Matrix(const Matrix<T>& copy): m_rows(copy.rows()) ,m_cols(copy.cols()){
	std::cout << "Copy_Constructor" << std::endl; 
	m_vec = new T[m_rows*m_cols];   <---- EXTRA WORK
	for(int i = 0; i<m_rows; ++i){
		for(int j = 0; j<m_cols; ++j){
			std::cout << i*m_cols + j << std::endl; 
			m_vec[i*m_cols + j] = copy(i,j);
		}
	}
};

// move
template <class T>
Matrix<T>::Matrix(Matrix<T>&& other): m_rows(std::move(other.m_rows)),m_cols(std::move(other.m_cols)) {
	m_vec = other.m_vec;
	other.m_vec = nullptr;
	std::cout << "move constr" << std::endl;
}

## Describe how you manage memory when resizing. When do you need to resize?
resize is needed for multiplication and transpose. as well as for assignment of a matrix of different size.

I create a new T[rows*cols] which I fill with the values of m_vec of the old matrix then I delete m_vec and assign the new vector to m_vec

## Why do you need to implement a const-version of the accessor operator?
Because some methods require const for the params. Example: 
friend std::ostream& operator<< (std::ostream& out, const Matrix<T>& mat);

## What synonyms, if any, are there for accessor in object oriented programming?
	Getters, setter methods

## What was hardest to implement in this assignment?
i didn't know how the static asserts worked but the most time consuming was probably making the input and output streams compatible

## What did you learn from this assignment?
more about how the move constructor and move assignment operator works.
difficulties regarding templates
