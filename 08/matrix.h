#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h> /* sqrt */

template <class T>
class Matrix {
public:

	static_assert(std::is_move_constructible<T>(), "Element type is not move-constructible");
	static_assert(std::is_move_assignable<T>(), "Element type is not move-assignable");

   	// constructors
	Matrix();
	// normal matrix
	Matrix(const int num_rows, const int num_cols);
	// Square matrix
	explicit Matrix(const int size);

	// copy constructor
	Matrix(const Matrix<T>& copy);

	Matrix(std::initializer_list<T> init_list);

	// move constructor
	Matrix(Matrix<T>&& other);

	~Matrix();
	// operators	

	// move assign op
	Matrix& operator= (Matrix && other);

	T& operator() (const int m, const int n);
	const T& operator() (const int m, const int n) const;

	void operator= (const Matrix<T>& mat);
	//Matrix<T> operator- (Matrix<T>& lhs, Matrix<T>& rhs);

	void operator+= (const Matrix<T>& rhs);
	void operator*= (const Matrix<T>& rhs);
	void operator-= (const Matrix<T>& rhs);

	friend std::ostream& operator<< (std::ostream& out, const Matrix<T>& mat){
		
		for(int i = 0; i<mat.rows();++i){
			
			for (int j = 0; j<mat.cols(); ++j){
				
				if(i>10000){
					if(mat(i,j) < 0){
						out << mat(i,j);
					}else{
						out << " "<< mat(i,j);
					}
				}else{
					if(mat(i,j) < 0){
						out << " " << mat(i,j);
					}else{
						out << "  " << mat(i,j);
					}
				}
			}
			if(i != mat.rows()-1){
				out << std::endl;
			}else{
				out << "\n";
			}
		}
		return out;
	}

	// input from file
	friend std::ifstream& operator>> (std::ifstream& in, Matrix<T>& mat){

		std::string str;
		std::string line;

		while(true){
			std::getline((std::istream&)in,line);
			if(line.empty()) break;
			str.append(line);
			str.append(";");
		}

		mat.parse_input(str,mat);
		return in;
	}

	// normal terminal input FORMAT: 1 2 3; 4 5 6; 7 8 9
	friend std::istream& operator>> (std::istream& in, Matrix<T>& mat){
		std::string str,sub_string;
		// read in the line of input
		std::getline(in,str);
		mat.parse_input(str,mat);

		return in;
	}

	// methods
	size_t rows() const{
		return m_rows;
	} 

	size_t cols() const{
		return m_cols;
	}

	void reset();
	Matrix<T> transpose();

	void insert_row(const int row_num);
	void append_row(const int row_num);
	void remove_row(const int row_num);
	void insert_column(const int col_num);
	void append_column(const int col_num);
	void remove_column(const int col_num);
	
private:

	void parse_input(std::string str, Matrix<T>& mat);

	size_t m_rows;
	size_t m_cols;
	size_t m_capacity;
	T * m_vec;
};


struct Proxy {

	Proxy(uint64_t & bit_array, int index): _bit_array(bit_array), _index(index){
		
		int bit = (bit_array >> index) & 1; // check bit
		if(bit > 0 ){
			 _is_true = true; 
		}else{
			_is_true = false;
		}
	};

	// conversion function
	operator bool() const{
		// check bit
		return _is_true;
	}


	void operator=(bool b){
		//std::cout << "index: " << _index << std::endl;
		if(b == true){
			_bit_array |= 1 << _index;
		}else{
			// clear bit
			_bit_array &= ~(1 << _index);
		}
		_is_true = b;
	}

	void operator=(Proxy p){
		//std::cout << "index: " << _index << std::endl;
		if(p == true){
			_bit_array |= 1 << _index;
		}else{
			// clear bit
			_bit_array &= ~(1 << _index);
		}
		_is_true = p;
	}

	/*
	friend std::ostream& operator<< (std::ostream& out,Proxy proxy){

		// check bit
		int bit = (proxy._bit_array >> proxy._index) & 1; // check bit
		if(bit > 0 ){
			out << 1; 
		}else{
			out << 0;
		}
		return out;
	}
	*/

	bool _is_true;
	uint64_t & _bit_array;
	int _index;
};

// lab 8
template <>
class Matrix<bool> {

public:
	static_assert(std::is_move_constructible<bool>(), "Element type is not move-constructible");
	static_assert(std::is_move_assignable<bool>(), "Element type is not move-assignable");

   	// constructors
	Matrix();
	// normal matrix
	Matrix(const int num_rows, const int num_cols);
	// Square matrix
	explicit Matrix(const int size);

	// copy constructor
	Matrix(const Matrix<bool>& copy);

	Matrix(std::initializer_list<bool> init_list);

	// move constructor
	Matrix(Matrix<bool>&& other);

	~Matrix();
	// operators	

	// move assign op
	Matrix& operator= (Matrix && other);

	Proxy operator() (const int m, const int n);
	const bool operator() (const int m, const int n) const;
	void operator= (const Matrix<bool>& mat);
	
	void operator&=(const Matrix<bool> &rhs);
	void operator|=(const Matrix<bool> &rhs);
	void operator^=(const Matrix<bool> &rhs);

	Matrix<bool> operator&(const Matrix<bool> &rhs);
	Matrix<bool> operator|(const Matrix<bool> &rhs);
	Matrix<bool> operator^(const Matrix<bool> &rhs);
	
	friend std::ostream& operator<< (std::ostream& out, const Matrix<bool>& mat){
		
		//capacity 
		for(int i = 0; i<mat.m_capacity; ++i){


			/*
			int row_index = (int) i/m_cols;
			int col_index = (int) i%m_capacity;
			*/

			// get bit
			int bit_position = i%mat.m_capacity; // position in uint64_t
			int array_index = (int) i/mat.m_capacity;

			if(i%mat.m_cols < 1 && i!=0) out << "\n";
			out << mat.check_bit(bit_position,mat.m_vec[array_index]) << " ";
			
		}
		return out;
	}

	// input from file
	friend std::ifstream& operator>> (std::ifstream& in, Matrix<bool>& mat){

		std::string str;
		std::string line;

		while(true){
			std::getline((std::istream&)in,line);
			if(line.empty()) break;
			str.append(line);
			str.append(";");
		}

		mat.parse_input(str,mat);
		return in;
	}

	// normal terminal input FORMAT: 100;010;000
	friend std::istream& operator>> (std::istream& in, Matrix<bool>& mat){
		std::string str,sub_string;
		// read in the line of input
		std::getline(in,str);
		mat.parse_input(str,mat);

		return in;
	}

	// methods
	size_t rows() const{
		return m_rows;
	} 

	size_t cols() const{
		return m_cols;
	}

	void reset();
	Matrix<bool> transpose();

	void insert_row(const int row_num);
	void append_row(const int row_num);
	void remove_row(const int row_num);
	void insert_column(const int col_num);
	void append_column(const int col_num);
	void remove_column(const int col_num);

private:

	void parse_input(std::string str, Matrix<bool>& mat);

	void set_bit(int position, uint64_t& bit_array);
	bool check_bit(int position, uint64_t bit_array) const;
	void clear_bit(int position, uint64_t& bit_array);

	size_t m_rows;
	size_t m_cols;
	size_t m_capacity;
	uint64_t * m_vec; // array of 64 bit unsigned integers
};

Matrix<bool> Matrix<bool>::operator&(const Matrix<bool> &rhs){
	
	if(m_rows != rhs.m_rows || m_cols != rhs.m_cols) throw std::runtime_error("can't perform and-operation on matrices of different dimension");
	
	Matrix<bool> mat(m_rows,m_cols);

	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8)));

	for(int i = 0; i<number_of_integers; ++i){
		mat.m_vec[i] = m_vec[i] & rhs.m_vec[i];
	}
	return mat;
}

Matrix<bool> Matrix<bool>::operator|(const Matrix<bool> &rhs){

	if(m_rows != rhs.m_rows || m_cols != rhs.m_cols) throw std::runtime_error("can't perform or-operation on matrices of different dimension");

	Matrix<bool> mat(m_rows,m_cols);
	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8)));

	for(int i = 0; i<number_of_integers; ++i){
		mat.m_vec[i] = m_vec[i] | rhs.m_vec[i];
	}
	return mat;
}

Matrix<bool> Matrix<bool>::operator^(const Matrix<bool> &rhs){
	
	if(m_rows != rhs.m_rows || m_cols != rhs.m_cols) throw std::runtime_error("can't perform xor-operation on matrices of different dimension");

	Matrix<bool> mat(m_rows,m_cols);
	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8)));

	for(int i = 0; i<number_of_integers; ++i){
		mat.m_vec[i] = m_vec[i] ^ rhs.m_vec[i];
	}
	return mat;
}

void Matrix<bool>::operator&=(const Matrix<bool> &rhs){

	if(m_rows != rhs.m_rows || m_cols != rhs.m_cols) throw std::runtime_error("can't perform and-operation on matrices of different dimension");
	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8)));

	for(int i = 0; i<number_of_integers; ++i){
		m_vec[i] &= rhs.m_vec[i];
	}
}

void Matrix<bool>::operator|=(const Matrix<bool> &rhs){

	if(m_rows != rhs.m_rows || m_cols != rhs.m_cols) throw std::runtime_error("can't perform or-operation on matrices of different dimension");
	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8)));

	for(int i = 0; i<number_of_integers; ++i){
		m_vec[i] |= rhs.m_vec[i];
	}
}

void Matrix<bool>::operator^=(const Matrix<bool> &rhs){

	if(m_rows != rhs.m_rows || m_cols != rhs.m_cols) throw std::runtime_error("can't perform xor-operation on matrices of different dimension");
	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8)));

	std::cout << "number: " << number_of_integers << std::endl;
	for(int i = 0; i<number_of_integers; ++i){
		m_vec[i] ^= rhs.m_vec[i];
	}

	std::cout << "number2: " << number_of_integers << std::endl;


}


Proxy Matrix<bool>::operator() (const int m, const int n){
	if(m<0 || n<0) throw std::out_of_range("invalid index for matrix");
	if(m>m_rows-1 || n>m_cols-1) throw std::out_of_range("invalid index for matrix");
	int index = ((m) * (m_cols)) + (n);
	int bit_array_index = index/m_capacity;
	int bit_index = index % m_capacity; // bit index in bit array (uint64_t)
	return Proxy(m_vec[bit_array_index],bit_index);
}

const bool Matrix<bool>::operator() (const int m, const int n) const{

	int index = ((m-1) * (m_cols)) + (n-1);

	int bit_array_index = index/m_capacity;
	int bit_index = index % m_capacity; // bit index in bit array (uint64_t)

	//std::cout << "bit_arrindex: " << bit_array_index << std::endl;
	//std::cout << "const bit_index: " << bit_index << std::endl;

	// get bit

	return check_bit(bit_index,m_vec[bit_array_index]);

}

Matrix<bool>::Matrix():m_rows(0),m_cols(0),m_capacity(0){
	m_vec = new uint64_t[0];
	std::cout << "bool default constructor" << std::endl;
}

Matrix<bool>::~Matrix(){
	delete[] m_vec;
}

// normal matrix
Matrix<bool>::Matrix(const int num_rows, const int num_cols): m_rows(num_rows),m_cols(num_cols),m_capacity(m_rows*m_cols){

	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8))); // calculate how many unsigned integers are needed to store array
	m_vec = new uint64_t[number_of_integers];
	std::cout << "bool mnormal constructor" << std::endl;
	std::cout << number_of_integers << std::endl;
	
	// set all bits to false
	for(int i = 0; i<number_of_integers; ++i){
		m_vec[i] = uint64_t(0);
	}
};

// square matrix constructor
Matrix<bool>::Matrix(const int size): m_rows(size),m_cols(size){

	m_capacity = size*size;
	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8))); // calculate how many unsigned integers are needed to store array
	m_vec = new uint64_t[number_of_integers];

	// set all bits to false
	for(int i = 0; i<number_of_integers; ++i){
		m_vec[i] = uint64_t(0);
	}
}

Matrix<bool>::Matrix(std::initializer_list<bool> init_list){

	int root = sqrt(init_list.size());
	if(root*root != init_list.size()){
		throw std::out_of_range("init_list error: square root is not an even number");
	}
	m_cols = root;
	m_rows = root;

	m_capacity = root*root;
	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8))); // calculate how many unsigned integers are needed to store array
	m_vec = new uint64_t[number_of_integers];

	for(int i = 0;i<number_of_integers;++i){
		m_vec[i] = uint64_t(0);
	}

	// cant do random access in init_list so create a temp array storing init values
	bool * bool_list =  new bool[m_capacity];
	int index = 0;
	auto ptr = init_list.begin();
	while (ptr != init_list.end()){
		*(bool_list+index) = *ptr;
		++index;
		++ptr;
	}

	for(int i = 0; i<m_capacity; ++i){

		// which bit_array and what index
		int bit_array_index = i/(sizeof(uint64_t) * 8);
		int bit_index = i % (sizeof(uint64_t) * 8);

		if(*(bool_list + i) == 1){
			set_bit(bit_index,m_vec[bit_array_index]);
		}else{
			clear_bit(bit_index,m_vec[bit_array_index]);
		}
	}
	delete[] bool_list;
}

// copy constructor
Matrix<bool>::Matrix(const Matrix<bool>& copy): m_rows(copy.rows()) ,m_cols(copy.cols()){
	//std::cout << "Copy_Constructor" << std::endl; 

	m_capacity = copy.m_capacity;

	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8)));
	m_vec = new uint64_t[number_of_integers];

	for(int i = 0;i<number_of_integers;++i){
		m_vec[i] = copy.m_vec[i];
	}
};

// Move constructor
Matrix<bool>::Matrix(Matrix<bool>&& other): m_rows(std::move(other.m_rows)),m_cols(std::move(other.m_cols)),m_capacity(std::move(other.m_capacity)) {
	m_vec = other.m_vec;
	other.m_vec = nullptr;
}

void Matrix<bool>::set_bit(int position, uint64_t& bit_array){
	bit_array |= 1 << position;
}

void Matrix<bool>::clear_bit(int position, uint64_t& bit_array){
	bit_array &= ~(1 << position);
}

bool Matrix<bool>::check_bit(int position, uint64_t bit_array) const{
	int bit = (bit_array >> position) & 1; // check bit
	if(bit > 0 ){
		return true; 
	}else{
		return false;
	}
}

Matrix<bool>& Matrix<bool>::operator= (Matrix<bool> && other){
	delete[] m_vec;
	m_vec = std::move(other.m_vec);
	m_rows = std::move(other.m_rows);
	m_cols = std::move(other.m_cols);
	m_capacity = std::move(other.m_capacity);


	other.m_vec = nullptr; // important otherwise will be delete[]d for this when other goes out of scope
	//std::cout << "move assigned\n";
	return *this;
}

void Matrix<bool>::operator= (const Matrix<bool>& mat){

	//std::cout << "Assignment Operator" << std::endl; 
	// TODO: UPDATE CAPACITY
	m_rows = mat.rows();
	m_cols = mat.cols();

	delete[] m_vec;

	m_capacity = m_rows*m_cols;
	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8))); 

	m_vec = new uint64_t[number_of_integers];
	for(int i = 0; i<number_of_integers; ++i){
		m_vec[i] = mat.m_vec[i];
	}	
}

void Matrix<bool>::parse_input(std::string str, Matrix<bool>& mat){


	if(str.size() < 1){
		throw std::runtime_error("input must contain at least one char");
	}

	int rows = 1;
	int cols = 1;
	int matrix_width = 1;


	if(str[str.size()-1] != ';') throw std::runtime_error("must have ending semi-colon");


	// figuring out the size of the matrix
	for(int i = 0; i<str.size();++i){

		if(str[i] == '0'){
			//mat(rows,cols) = false;
			++cols;
		}else if(str[i] == '1'){
			//mat(rows,cols) = true;
			++cols;
		}else if(str[i] == ';'){
			if(i == 0) throw std::runtime_error("first input char can't be ';'");
			if(rows == 1) matrix_width = cols;
			if(rows > 1 && matrix_width != cols) throw std::runtime_error("row lengths don't match");  
			++rows;
			cols = 1;
		}else{
			std::string err = "invalid input: ";
			err+=str[i];
			throw std::runtime_error(err);
		}
	}

	Matrix<bool> temp(rows-1,matrix_width-1);


	rows = 1;
	cols = 1;

	for(int i = 0; i<str.size();++i){

		if(str[i] == '0'){
			temp(rows-1,cols-1) = false;
			++cols;
		}else if(str[i] == '1'){
			temp(rows-1,cols-1) = true;
			++cols;
		}else if(str[i] == ';'){
			if(i == 0) throw std::runtime_error("first input char can't be ';'");
			if(rows == 1) matrix_width = cols;
			++rows;
			cols = 1;
		}else{
			std::string err = "invalid input: ";
			err+=str[i];
			throw std::runtime_error(err);
		}
	}

	mat = temp;
	
}

/*Member methods*/
void Matrix<bool>::insert_row(const int row_num){
	if(row_num > m_rows-1){
		throw std::out_of_range("error: row number outside of matrix");
		return;
	}

	int number_of_integers = ceil(((float) (m_capacity+m_cols) / (sizeof(uint64_t) * 8))); // calculate how many unsigned integers are needed to store array
	uint64_t * new_vec = new uint64_t[number_of_integers];
	
	// init uints in array
	for(int i = 0; i<number_of_integers;++i){
		new_vec[i] = uint64_t(0);
	}

	bool is_inserted = false;
	for(int i = 0; i<m_rows+1; ++i){
		for(int j = 0; j<m_cols; ++j){
			if(i == row_num){
				// insert new row
				int index = (i * m_cols) + j;
				std::cout << index << std::endl;
				int bit_array_index = index/(sizeof(uint64_t) * 8);
				int bit_index = index % (sizeof(uint64_t) * 8);
				clear_bit(bit_index,new_vec[bit_array_index]);
				if(j == m_cols-1) is_inserted = true;
			}else{
				if(is_inserted){
					int index = ((i) * m_cols) + j; 
					int bit_array_index = index/(sizeof(uint64_t) * 8);
					int bit_index = index % (sizeof(uint64_t) * 8);
					int old_vec_index = ((i-1) * m_cols) + j; 
					int old_bit_array_index = old_vec_index/(sizeof(uint64_t) * 8);
					int old_bit_index = old_vec_index % (sizeof(uint64_t) * 8);
					if(check_bit(old_bit_index,m_vec[old_bit_array_index])){
						set_bit(bit_index,new_vec[bit_array_index]);
					}else{
						clear_bit(bit_index,new_vec[bit_array_index]); // TODO not necessary all are set to zero anyway.
					}	
				}else{
					int index = (i * m_cols) + j; 
					int bit_array_index = index/(sizeof(uint64_t) * 8);
					int bit_index = index % (sizeof(uint64_t) * 8);	
					if(check_bit(bit_index,m_vec[bit_array_index])){
						set_bit(bit_index,new_vec[bit_array_index]);
					}else{
						clear_bit(bit_index,new_vec[bit_array_index]); // TODO not necessary all are set to zero anyway.
					}			
				}
			}
		}
	}

	m_capacity += m_cols;
	++m_rows; // added one new row
	delete[] m_vec;
	m_vec = new_vec;
}

void Matrix<bool>::append_row(const int row_num){
	if(row_num > m_rows-1){
		throw std::out_of_range("error: row number outside of matrix");
		return;
	}

	int number_of_integers = ceil(((float) (m_capacity+m_cols) / (sizeof(uint64_t) * 8))); // calculate how many unsigned integers are needed to store array
	uint64_t * new_vec = new uint64_t[number_of_integers];
	
	// init uints in array
	for(int i = 0; i<number_of_integers;++i){
		new_vec[i] = uint64_t(0);
	}

	bool is_inserted = false;
	for(int i = 0; i<m_rows+1; ++i){
		for(int j = 0; j<m_cols; ++j){
			if(i == row_num+1){
				// insert new row
				int index = (i * m_cols) + j;
				int bit_array_index = index/(sizeof(uint64_t) * 8);
				int bit_index = index % (sizeof(uint64_t) * 8);
				clear_bit(bit_index,new_vec[bit_array_index]);
				if(j == m_cols-1) is_inserted = true;
			}else{
				if(is_inserted){
					int index = ((i) * m_cols) + j; 
					int bit_array_index = index/(sizeof(uint64_t) * 8);
					int bit_index = index % (sizeof(uint64_t) * 8);
					int old_vec_index = ((i-1) * m_cols) + j; 
					int old_bit_array_index = old_vec_index/(sizeof(uint64_t) * 8);
					int old_bit_index = old_vec_index % (sizeof(uint64_t) * 8);
					if(check_bit(old_bit_index,m_vec[old_bit_array_index])){
						set_bit(bit_index,new_vec[bit_array_index]);
					}else{
						clear_bit(bit_index,new_vec[bit_array_index]); // TODO not necessary all are set to zero anyway.
					}	
				}else{
					int index = (i * m_cols) + j; 
					int bit_array_index = index/(sizeof(uint64_t) * 8);
					int bit_index = index % (sizeof(uint64_t) * 8);	
					if(check_bit(bit_index,m_vec[bit_array_index])){
						set_bit(bit_index,new_vec[bit_array_index]);
					}else{
						clear_bit(bit_index,new_vec[bit_array_index]); // TODO not necessary all are set to zero anyway.
					}			
				}
			}
		}
	}

	m_capacity += m_cols;
	++m_rows; // added one new row
	delete[] m_vec;
	m_vec = new_vec;

}

void Matrix<bool>::remove_row(const int row_num){
	if(row_num > m_rows-1){
		throw std::out_of_range("error: row number outside of matrix");
		return;
	}

	int number_of_integers = ceil(((float) (m_capacity-m_cols) / (sizeof(uint64_t) * 8))); // calculate how many unsigned integers are needed to store array
	uint64_t * new_vec = new uint64_t[number_of_integers];
	
	// init uints in array
	for(int i = 0; i<number_of_integers;++i){
		new_vec[i] = uint64_t(0);
	}

	bool is_removed = false;
	for(int i = 0; i<m_rows; ++i){
		for(int j = 0; j<m_cols; ++j){
			if(i == row_num){
				// dont do anything
				if(j==m_cols-1) is_removed = true;
			}else{
				if(is_removed){
					int index = ((i-1) * m_cols) + j; 
					int bit_array_index = index/(sizeof(uint64_t) * 8);
					int bit_index = index % (sizeof(uint64_t) * 8);
					int old_vec_index = ((i) * m_cols) + j; 
					int old_bit_array_index = old_vec_index/(sizeof(uint64_t) * 8);
					int old_bit_index = old_vec_index % (sizeof(uint64_t) * 8);
					if(check_bit(old_bit_index,m_vec[old_bit_array_index])){
						set_bit(bit_index,new_vec[bit_array_index]);
					}else{
						clear_bit(bit_index,new_vec[bit_array_index]); // TODO not necessary all are set to zero anyway.
					}	
				}else{
					int index = (i * m_cols) + j;
					int bit_array_index = index/(sizeof(uint64_t) * 8);
					int bit_index = index % (sizeof(uint64_t) * 8);	
					if(check_bit(bit_index,m_vec[bit_array_index])){
						set_bit(bit_index,new_vec[bit_array_index]);
					}else{
						clear_bit(bit_index,new_vec[bit_array_index]); // TODO not necessary all are set to zero anyway.
					}			
				}
			}
		}
	}
	m_capacity -= m_cols;
	--m_rows; // removed one row
	delete[] m_vec;
	m_vec = new_vec;

}

void Matrix<bool>::insert_column(const int col_num){
	if(col_num > m_cols-1){
		throw std::out_of_range("error: column number outside of matrix");
		return;
	}

	int number_of_integers = ceil(((float) (m_capacity+m_rows) / (sizeof(uint64_t) * 8))); // calculate how many unsigned integers are needed to store array
	uint64_t * new_vec = new uint64_t[number_of_integers];
	
	// init uints in array
	for(int i = 0; i<number_of_integers;++i){
		new_vec[i] = uint64_t(0);
	}

	for(int i = 0; i<m_capacity+m_rows; ++i){
			
		int current_col = i/(m_cols+1);
		current_col = current_col * (m_cols+1);
		current_col = i - current_col;

		if(current_col == col_num){
			// insert new column
			// do nothing already init to zero
		}else if(current_col > col_num){
			// col
			int cols_added = i/(m_cols+1);
			int index = i;
			int bit_array_index = index/(sizeof(uint64_t) * 8);
			int bit_index = index % (sizeof(uint64_t) * 8);
			int old_vec_index = (i - cols_added - 1); 
			int old_bit_array_index = old_vec_index/(sizeof(uint64_t) * 8);
			int old_bit_index = old_vec_index % (sizeof(uint64_t) * 8);
			if(check_bit(old_bit_index,m_vec[old_bit_array_index])){
				set_bit(bit_index,new_vec[bit_array_index]);
			}else{
				clear_bit(bit_index,new_vec[bit_array_index]); // TODO not necessary all are set to zero anyway.
			}	
		}else{
			int cols_added = i/(m_cols+1);
			int index = (i); 
			int bit_array_index = index/(sizeof(uint64_t) * 8);
			int bit_index = index % (sizeof(uint64_t) * 8);
			int old_vec_index = (i - cols_added);
			int old_bit_array_index = old_vec_index/(sizeof(uint64_t) * 8);
			int old_bit_index = old_vec_index % (sizeof(uint64_t) * 8);
			if(check_bit(old_bit_index,m_vec[old_bit_array_index])){
				set_bit(bit_index,new_vec[bit_array_index]);
			}else{
				clear_bit(bit_index,new_vec[bit_array_index]); // TODO not necessary all are set to zero anyway.
			}
		}	
	}

	m_capacity += m_rows;
	++m_cols; // added one new column
	delete[] m_vec;
	m_vec = new_vec;

}

void Matrix<bool>::append_column(const int col_num){
	if(col_num > m_cols-1){
		throw std::out_of_range("error: column number outside of matrix");
		return;
	}

	int number_of_integers = ceil(((float) (m_capacity+m_rows) / (sizeof(uint64_t) * 8))); // calculate how many unsigned integers are needed to store array
	uint64_t * new_vec = new uint64_t[number_of_integers];
	
	// init uints in array
	for(int i = 0; i<number_of_integers;++i){
		new_vec[i] = uint64_t(0);
	}

	for(int i = 0; i<m_capacity+m_rows; ++i){
			
		int current_col = i/(m_cols+1);
		current_col = current_col * (m_cols+1);
		current_col = i - current_col;

		if(current_col == col_num+1){
			// insert new column
			// do nothing already init to zero
		}else if(current_col > col_num+1){
			// col
			int cols_added = i/(m_cols+1);
			int index = i;
			int bit_array_index = index/(sizeof(uint64_t) * 8);
			int bit_index = index % (sizeof(uint64_t) * 8);
			int old_vec_index = (i - cols_added - 1); 
			int old_bit_array_index = old_vec_index/(sizeof(uint64_t) * 8);
			int old_bit_index = old_vec_index % (sizeof(uint64_t) * 8);
			if(check_bit(old_bit_index,m_vec[old_bit_array_index])){
				set_bit(bit_index,new_vec[bit_array_index]);
			}else{
				clear_bit(bit_index,new_vec[bit_array_index]); // TODO not necessary all are set to zero anyway.
			}	
		}else{
			int cols_added = i/(m_cols+1);
			int index = (i); 
			int bit_array_index = index/(sizeof(uint64_t) * 8);
			int bit_index = index % (sizeof(uint64_t) * 8);
			int old_vec_index = (i - cols_added);
			int old_bit_array_index = old_vec_index/(sizeof(uint64_t) * 8);
			int old_bit_index = old_vec_index % (sizeof(uint64_t) * 8);
			if(check_bit(old_bit_index,m_vec[old_bit_array_index])){
				set_bit(bit_index,new_vec[bit_array_index]);
			}else{
				clear_bit(bit_index,new_vec[bit_array_index]); // TODO not necessary all are set to zero anyway.
			}
		}	
	}

	m_capacity += m_rows;
	++m_cols; // added one new column
	delete[] m_vec;
	m_vec = new_vec;

}

void Matrix<bool>::remove_column(const int col_num){
	if(col_num > m_cols-1){
		throw std::out_of_range("error: column number outside of matrix");
		return;
	}

	int number_of_integers = ceil(((float) (m_capacity+m_rows) / (sizeof(uint64_t) * 8))); // calculate how many unsigned integers are needed to store array
	uint64_t * new_vec = new uint64_t[number_of_integers];
	
	// init uints in array
	for(int i = 0; i<number_of_integers;++i){
		new_vec[i] = uint64_t(0);
	}

	for(int i = 0; i<m_capacity; ++i){
			
		int current_col = i/(m_cols); // row
		current_col = current_col * (m_cols);
		current_col = i - current_col;

		if(current_col == col_num){
			// insert new column
			// do nothing already init to zero
		}else if(current_col > col_num){
			// col
			int cols_added = i/(m_cols);
			int index = i;
			int bit_array_index = index/(sizeof(uint64_t) * 8);
			int bit_index = index % (sizeof(uint64_t) * 8);
			int old_vec_index = (i - cols_added - 1); 
			int old_bit_array_index = old_vec_index/(sizeof(uint64_t) * 8);
			int old_bit_index = old_vec_index % (sizeof(uint64_t) * 8);

			if(check_bit(bit_index,m_vec[bit_array_index])){
				set_bit(old_bit_index,new_vec[old_bit_array_index]);
			}else{
				clear_bit(old_bit_index,new_vec[old_bit_array_index]); // TODO not necessary all are set to zero anyway.
			}	
		}else{
			int cols_added = i/(m_cols);
			int index = (i); 
			int bit_array_index = index/(sizeof(uint64_t) * 8);
			int bit_index = index % (sizeof(uint64_t) * 8);
			int old_vec_index = (i - cols_added);
			int old_bit_array_index = old_vec_index/(sizeof(uint64_t) * 8);
			int old_bit_index = old_vec_index % (sizeof(uint64_t) * 8);
			if(check_bit(bit_index,m_vec[bit_array_index])){
				set_bit(old_bit_index,new_vec[old_bit_array_index]);
			}else{
				clear_bit(old_bit_index,new_vec[old_bit_array_index]); // TODO not necessary all are set to zero anyway.
			}
		}	
	}

	m_capacity -= m_rows;
	--m_cols; // added one new column
	delete[] m_vec;
	m_vec = new_vec;

}

void Matrix<bool>::reset(){

	int number_of_integers = ceil(((float) m_capacity / (sizeof(uint64_t) * 8)));
	for(int i = 0;i<number_of_integers;++i){
		m_vec[i] = uint64_t(0);
	}
}

Matrix<bool> Matrix<bool>::transpose(){

	Matrix mat(m_cols,m_rows);

	for (int i = 0; i < m_rows; ++i) {
		for (int j = 0; j < m_cols; ++j) {
			// m_vec is row-major
			mat(j,i) = (*this)(i,j);
		}		
	}
	return mat;
}


/*

GENERIC MATRIX

*/


template <class T>
Matrix<T>::Matrix():m_rows(0),m_cols(0){
	m_vec = new T[0];
	//std::cout << "default constructor" << std::endl;
};

// normal matrix
template <class T>
Matrix<T>::Matrix(const int num_rows, const int num_cols): m_rows(num_rows),m_cols(num_cols){
	m_vec = new T[num_cols*num_rows];
	//std::cout << "normal constructor" << std::endl;
	for(int i = 0; i<m_rows; ++i){
		for(int j = 0; j<m_cols; ++j){
			//std::cout << i*m_cols + j << std::endl; 
			m_vec[i*m_cols + j] = T();
		}
	}
};

// Square matrix
template <class T>
Matrix<T>::Matrix(const int size): m_rows(size),m_cols(size){
	//std::cout << "size constructor" << std::endl;
	m_vec = new T[size*size];
	for(int i = 0; i<m_rows; ++i){
		for(int j = 0; j<m_cols; ++j){
			//std::cout << i*m_cols + j << std::endl; 
			m_vec[i*m_cols + j] = T();
		}
	}		
};

template <class T>
Matrix<T>::Matrix(const Matrix<T>& copy): m_rows(copy.rows()) ,m_cols(copy.cols()){
	//std::cout << "Copy_Constructor" << std::endl; 
	m_vec = new T[m_rows*m_cols];
	for(int i = 0; i<m_rows; ++i){
		for(int j = 0; j<m_cols; ++j){
			//std::cout << i*m_cols + j << std::endl; 
			m_vec[i*m_cols + j] = copy(i,j);
		}
	}
};

template <class T>
Matrix<T>::Matrix(Matrix<T>&& other): m_rows(std::move(other.m_rows)),m_cols(std::move(other.m_cols)) {

	m_vec = other.m_vec;
	other.m_vec = nullptr;
	//std::cout << "move constr" << std::endl;
}

template <class T>
Matrix<T>::Matrix(std::initializer_list<T> init_list){
		//std::cout << "init list constr" << std::endl;

		int root = sqrt(init_list.size());
		if(root*root != init_list.size()){

			std::cout << "FAIL" << std::endl;
			throw std::out_of_range("error: square root is not an even number");
		}
		m_cols = root;
		m_rows = root;
		m_vec = new T[root*root];

		int index = 0;
		const T * ptr = init_list.begin();
		while(ptr != init_list.end()){
			//std::cout << "ptr: " << *ptr << std::endl;
			m_vec[index] = *ptr;
			++ptr;
			++index;
		}
}

template <class T>
Matrix<T>::~Matrix(){
	delete[] m_vec;
}

// operators
template <class T>
Matrix<T>& Matrix<T>::operator= (Matrix<T> && other){
	delete[] m_vec;
	m_vec = std::move(other.m_vec);
	m_rows = std::move(other.m_rows);
	m_cols = std::move(other.m_cols);

	other.m_vec = nullptr; // important otherwise will be delete[]d for this when other goes out of scope
	//std::cout << "move assigned\n";
	return *this;
}

template <class T>
T& Matrix<T>::operator() (const int m, const int n){
	return m_vec[m * m_cols + n];
}

// operators
template <class T>
const T& Matrix<T>::operator() (const int m, const int n) const{
	return m_vec[m * m_cols + n];
}

template <class T>
void Matrix<T>::operator= (const Matrix<T>& mat){

	//std::cout << "Assignment Operator" << std::endl; 

	m_rows = mat.rows();
	m_cols = mat.cols();

	delete[] m_vec;
	m_vec = new T[m_rows*m_cols];
	for(int i = 0; i<m_rows; ++i){
		for(int j = 0; j<m_cols; ++j){
			//std::cout << i*m_cols + j << std::endl; 
			m_vec[i*m_cols + j] = mat(i,j);
		}
	}	
}

template <class T>
Matrix<T> operator+ (Matrix<T>& lhs, Matrix<T>& rhs){

	if(lhs.rows() != rhs.rows() && lhs.cols() != rhs.cols()){
		throw std::out_of_range("Error: can't add matrices of different DIMENSIONS");
	}

	Matrix<T> mat(lhs.rows(),lhs.cols());
	for(int i = 0; i<lhs.rows(); ++i){
		for(int j = 0; j<lhs.cols(); ++j){
			//std::cout << i*m_cols + j << std::endl;
			mat(i,j) = lhs(i,j) + rhs(i,j);
		}
	}
	return mat;
}

template <class T>
Matrix<T> operator- (Matrix<T>& lhs, Matrix<T>& rhs){
	
	if(lhs.rows() != rhs.rows() && lhs.cols() != rhs.cols()){
		throw std::out_of_range("Error: can't subtract matrices of different DIMENSIONS");
	}
	Matrix<T> mat(lhs.rows(),lhs.cols());
	for(int i = 0; i<lhs.rows(); ++i){
		for(int j = 0; j<lhs.cols(); ++j){
			//std::cout << i*m_cols + j << std::endl;
			mat(i,j) = lhs(i,j) - rhs(i,j);
		}
	}
	return mat;
}

template <class T>
Matrix<T> operator* (Matrix<T>& lhs, Matrix<T>& rhs){
	
	if(lhs.cols() != rhs.rows()){
		// FAIL
		throw std::out_of_range("DIMENSIONS don't match for matrix multiplication");
	}

	Matrix<T> mat(lhs.rows(),rhs.cols());
	if(lhs.cols() != rhs.rows()){
		// FAIL
		std::cout << "FAIL DIMENSIONS DON'T MATCH FOR MULTIPLICATION" << std::endl;
		return mat;
	}

	for(int i = 0; i<lhs.rows(); ++i){
		for(int k = 0; k<rhs.cols(); ++k){
			for(int j = 0; j<lhs.cols(); ++j){
				std::cout << "i: " << i << " j: " << j << " k: "<< k << std::endl;	
				std::cout << "value: " << mat(i,k) << std::endl;
				mat(i,k) = mat(i,k) + (lhs(i,j) * rhs(j,k));
			}
		}
	}
	return mat;
}

template <class T>
void Matrix<T>::operator+= (const Matrix<T>& rhs){

	if(m_cols != rhs.cols() || m_rows != rhs.rows()){
		throw std::out_of_range("Error: can't add matrices of different DIMENSIONS");
	}

	for(int i = 0; i<m_rows; ++i){
		for(int j = 0; j<m_cols; ++j){
			m_vec[i*m_cols+j] = m_vec[i*m_cols+j] + rhs(i,j);
		}
	}
}

template <class T>
void Matrix<T>::operator*= (const Matrix<T>& rhs){

	if(m_cols != rhs.rows()){
		// FAIL
		throw std::out_of_range("DIMENSIONS don't match for matrix multiplication");
	}

	T * output = new T[m_rows*rhs.cols()];
	for(int i = 0; i<m_rows; ++i){
		for(int k = 0; k<rhs.cols(); ++k){
			for(int j = 0; j<m_cols; ++j){
				if(j == 0){
					output[i*m_cols + k] = (m_vec[i*m_cols + j] * rhs(j,k)); // because output not init on j=0				
				}else {
					output[i*m_cols + k] = output[i*m_cols + k] + (m_vec[i*m_cols + j] * rhs(j,k));	
				}
			}
		}
	}
	delete[] m_vec;
	m_vec = output;
}

template <class T>
void Matrix<T>::operator-= (const Matrix<T>& rhs){
	if(m_cols != rhs.cols() || m_rows != rhs.rows()){
		throw std::out_of_range("Error: can't add matrices of different DIMENSIONS");
	}
	for(int i = 0; i<m_rows; ++i){
		for(int j = 0; j<m_cols; ++j){
			m_vec[i*m_cols+j] = m_vec[i*m_cols+j] - rhs(i,j);
		}
	}
}

template <class T>
void Matrix<T>::parse_input(std::string str, Matrix<T>& mat){

	if(str.size() > 0){
		if(str[0] == ';'){
			throw std::runtime_error("ERROR: input can't start with ; ");
			return;
		}
	}else{
		// no input
		return;
	}

	int rows = 1;
	//count rows
	for(int i=0; i<str.size();++i){

		if(i != 0 && i != str.size()-1){
			// check that num of cols don't differ between rows;
			if(str[i] == ';'){
				std::cout << "i: " << i << std::endl;
				++rows;
			}
		}
	}

	std::string sub_string;
	std::istringstream iss(str);
	// split up line into sub strings
	std::vector<std::string> content;
	while(std::getline(iss,sub_string,' ')){
		std::cout << "str: " << sub_string << std::endl; 
		content.push_back(sub_string);
	}

	std::vector<std::string> clean_content;
	// check each substring for validity and split on ';'
	for(int i = 0; i<content.size();++i){
		std::istringstream iss2(content[i]);
		std::string entry;
		while(std::getline(iss2,entry,';')){
			std::cout << "entry: " << entry << std::endl;
			if(entry.size() > 0 && entry[0] != ' '){
				clean_content.push_back(entry);
			}
		}
	}

	// go through each string and check that only valid chars are left
	for(int i = 0; i<clean_content.size();++i){
		int minus_count = 0;
		for(int j = 0;j<clean_content[i].size();++j){
			std::cout << "char: " << clean_content[i][j] << std::endl;
			if((clean_content[i][j] > '9' ||clean_content[i][j] < '0') && clean_content[i][j] != '.' && clean_content[i][j] != '-'){
				throw std::runtime_error("ERROR: entry is non_numerical");
				return;
			}
			if(clean_content[i][j] == '-'){
				++minus_count;
			}
			if(minus_count > 1){
				throw std::runtime_error("too many minus signs in entry");
				return;
			}
		}
	}


	// convert entry to double and enter in matrix
	if(clean_content.size()%rows != 0){
		// fail
		throw std::runtime_error("errro: num of columns don't match between rows");
		return;
	}

	int cols = clean_content.size()/rows;
	std::cout << "cols: " << cols << std::endl;
	Matrix temp(rows,cols);

	for(int i = 0; i<rows;++i){
		for(int j = 0; j<cols;++j){

			try{
				temp(i,j) = std::stod(clean_content[i*cols + j]);					
			}catch(std::exception& e){
				std::cout << e.what() << std::endl;
				return;
			}
		
			std::cout << "val: " << std::stod(clean_content[i*cols + j]) <<std::endl;
		}

	}

	mat = temp;

	return;
}

template <class T>
void Matrix<T>::reset(){

	for(int i = 0; i<m_rows; ++i){
		for(int j = 0; j<m_cols; ++j){
			m_vec[i*m_cols + j] = T();
		}
	}


	return;
}

template <class T>
Matrix<T> Matrix<T>::transpose(){
	Matrix mat(m_cols,m_rows);

	for (int i = 0; i < m_cols; ++i) {
		for (int j = 0; j < m_rows; ++j) {
			// m_vec is row-major
			mat(i,j) = m_vec[j*m_cols + i];
		}		
	}
	return mat;
}

template <class T>
void Matrix<T>::insert_row(const int row_num){

	if(row_num > m_rows-1){
		throw std::out_of_range("error: row number outside of matrix");
		return;
	}

	T * new_vec = new T[(m_rows+1)*m_cols];
	bool is_inserted = false;

	for(int i = 0; i<((m_rows+1)*m_cols); ++i){
		
		if((i/m_cols == row_num)){
			std::cout << "i/numrows: " << i/m_cols << std::endl;	
			std::cout << "i: " << i << std::endl;	
			std::cout << "m_vec: " << m_vec[i] << std::endl;			
			new_vec[i] = T();
			is_inserted = true;
		}else{
			if(is_inserted){
				new_vec[i] = m_vec[i-m_cols];
			}else{
				new_vec[i] = m_vec[i];
			}
		}
	}

	++m_rows;
	delete[] m_vec;
	m_vec = new_vec;
}

template <class T>
void Matrix<T>::append_row(const int row_num){

	if(row_num > m_rows-1){
		throw std::out_of_range("error: row number outside of matrix");
		return;
	}

	T * new_vec = new T[(m_rows+1)*m_cols];
	bool is_inserted = false;

	for(int i = 0; i<((m_rows+1)*m_cols); ++i){
		
		if((i/m_cols == (row_num+1))){
			std::cout << "i/numrows: " << i/m_cols << std::endl;	
			std::cout << "i: " << i << std::endl;	
			std::cout << "m_vec: " << m_vec[i] << std::endl;			
			new_vec[i] = T();
			is_inserted = true;
		}else{
			if(is_inserted){
				new_vec[i] = m_vec[i-m_cols];
			}else{
				new_vec[i] = m_vec[i];
			}
		}
	}

	++m_rows;
	delete[] m_vec;
	m_vec = new_vec;
}

template <class T>
void Matrix<T>::remove_row(const int row_num){

	if(row_num > m_rows-1){
		throw std::out_of_range("error: row number outside of matrix");
		return;
	}

	T * new_vec = new T[(m_rows-1)*m_cols];
	bool is_removed = false;

	for(int i = 0; i<(m_rows*m_cols); ++i){
		
		if((i/m_cols == (row_num))){		
			is_removed = true;
		}else{
			if(is_removed){
				new_vec[i-m_cols] = m_vec[i];
			}else{
				new_vec[i] = m_vec[i];
			}
		}
	}

	--m_rows;
	delete[] m_vec;
	m_vec = new_vec;
}

template <class T>
void Matrix<T>::insert_column(const int col_num){


	if(col_num > m_cols-1){
		throw std::out_of_range("error: column number outside of matrix");
		return;
	}

	T * new_vec = new T[m_rows*(m_cols+1)];
	for(int i = 0; i<(m_rows*(m_cols+1)); ++i){

		int current_col = i/(m_cols+1);
		current_col = current_col * (m_cols+1);
		current_col = i - current_col;

		if(current_col == col_num){
			new_vec[i] = T();
		}else if(current_col > col_num){
			int cols_added = i/(m_cols+1);
			new_vec[i] = m_vec[i-cols_added-1];
		}else{
			int cols_added = i/(m_cols+1);
			new_vec[i] = m_vec[i-cols_added];
		}
	}

	++m_cols;
	delete[] m_vec;
	m_vec = new_vec;
}

template <class T>
void Matrix<T>::append_column(const int col_num){
	
	if(col_num > m_cols-1){
		throw std::out_of_range("error: column number outside of matrix");
		return;
	}

	T * new_vec = new T[m_rows*(m_cols+1)];
	for(int i = 0; i<(m_rows*(m_cols+1)); ++i){

		int current_col = i/(m_cols+1); // row
		current_col = current_col * (m_cols+1);
		current_col = i - current_col;

		if(current_col == col_num+1){
			new_vec[i] = 0.0;
		}else if(current_col > col_num+1){
			int cols_added = i/(m_cols+1);
			new_vec[i] = m_vec[i-cols_added-1];
		}else{
			int cols_added = i/(m_cols+1);
			new_vec[i] = m_vec[i-cols_added];
		}
	}

	++m_cols;
	delete[] m_vec;
	m_vec = new_vec;
}

template <class T>
void Matrix<T>::remove_column(const int col_num){

	if(col_num > m_cols-1){
		throw std::out_of_range("error: column number outside of matrix");
		return;
	}

	T * new_vec = new T[m_rows*(m_cols-1)];
	for(int i = 0; i<(m_rows*m_cols); ++i){

		int current_col = i/(m_cols); // row
		current_col = current_col * (m_cols);
		current_col = i - current_col;

		if(current_col == col_num){
			//new_vec[i] = 0.0;
		}else if(current_col > col_num){
			int cols_added = i/(m_cols);
			new_vec[i-cols_added-1] = m_vec[i];
		}else{
			int cols_added = i/(m_cols);
			new_vec[i-cols_added] = m_vec[i];
		}
	}
	--m_cols;
	delete[] m_vec;
	m_vec = new_vec;
}

template <class T>
Matrix<T> identity(unsigned int size) {
	Matrix<T> mat(size,size);
	for(int i = 0; i<size;++i){
		for(int j = 0; j<size;++j){			
			if(i == j){
				mat(i,j) = 1.0;
			}else{
				mat(i,j) = 0.0;
			}
		}
	}
	return mat;
}

template<>
Matrix<bool> identity<bool>(unsigned int size) {
	Matrix<bool> mat(size,size);
	for(int i = 0; i<size;++i){
		for(int j = 0; j<size;++j){			
			if(i == j){
				mat(i,j) = 1;
			}else{
				mat(i,j) = 0;
			}
		}
	}
	return mat;
}

