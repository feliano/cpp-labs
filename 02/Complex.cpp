#include "Complex.h"
using namespace myLib;

static const double DOUBLE_PRECISION = 0.000001;

Complex myLib::multiplyComplex(const Complex& a, const Complex& b){
	
	double real = (a.real() * b.real()) - (a.imag() * b.imag());
	double imag = (a.imag() * b.real()) + (a.real() * b.imag());  

	return Complex(real,imag);
}

myLib::Complex::Complex(): _real(0.0), _imag(0.0) {
	std::cout << "default constructor" << std::endl;
}

myLib::Complex::Complex(double real): _real(real), _imag(0) {
	std::cout << "other (only real) constructor" << std::endl;
}

double myLib::Complex::real() const{
	return _real;
}

double myLib::Complex::imag() const{
	return _imag;
}

const Complex& myLib::Complex::operator= (const Complex& c){
	std::cout << "operator=" << std::endl;
	_real = c.real();
	_imag = c.imag();
	return *this;
}

void myLib::Complex::operator+= (const Complex& c){
	std::cout << "operator+=" << std::endl;
	_real = _real + c.real();
	_imag = _imag + c.imag();
}

void myLib::Complex::operator-= (const Complex& c){
	std::cout << "operator-=" << std::endl;
	_real = _real - c.real();
	_imag = _imag - c.imag();
}

void myLib::Complex::operator*= (const Complex& c){
	std::cout << "operator*=" << std::endl;
	double real = (this->real() * c.real()) - (this->imag() * c.imag()); 
	double imag = (this->imag() * c.real()) + (this->real() * c.imag());
	_real = real; 
	_imag = imag;
}

void myLib::Complex::operator/= (const Complex& c){
	std::cout << "operator/=" << std::endl;

	Complex conjugate(c.real(),-c.imag()); // conjugate of the denominator

	Complex numerator = multiplyComplex(*this,conjugate);
	Complex denominator = multiplyComplex(c,conjugate);

	if(denominator.real() == 0.0){
		throw std::runtime_error("error: division by zero");
	}

	_real = numerator.real()/denominator.real();  // denominator's imag part is zero after conjugate multiplication
	_imag = numerator.imag()/denominator.real();
}

std::ostream& myLib::operator<< (std::ostream& out, const Complex& c){
	out << "(" <<c.real() << "," << c.imag() << ")";
	return out;
}

std::istream& myLib::operator>> (std::istream& in, Complex& c){ // 

  	std::string str;
  	in >> str;

  	std::string str2 ("(");  	
  	std::string str3 (",");
  	std::string str4 (")");

	// find '(' , then find ',' then find ')'
  	std::size_t index1 = str.find(str2);
	std::size_t index2 = str.find(str3);
 	std::size_t index3 = str.find(str4);
 	
 	if(index1 == std::string::npos || index2 == std::string::npos || index3 == std::string::npos){
 		// string should be numerical otherwise throw exception
 		// check that all chars are numbers
		try{
			for(int i = 0; i<str.size();++i){
				if((str[i] > '9' || str[i] < '0') && str[i] != '-' && str[i] != '.'){

					throw std::runtime_error("Error: string not numerical");
					return in;
				}

				// if only minus in string
				if(str.size() == 1 && str[i] == '-'){
					throw std::runtime_error("Error: string only containing '-'");
					return in;
				}

				// only first char can be '-' 
				if (i > 0 && str[i] == '-'){
					std::cout << "'-' must come before numbers" << std::endl;
					throw std::runtime_error("'-' must come before numbers");
					return in;
				}
			}

			double real = std::stod(str);
			c = Complex(real);
			return in;
		} catch(const std::exception& ex){
			// if conversion to double doesn't work
			throw std::runtime_error("Couldn't convert string to double");
			return in;
		}
 	}else{
 		// All signs were found '(' ',' ')' 		
 		// count ')' - special case since find will return index
 		// of first it will only affect closing parenthesis 
 		int p_count = 0;
 		for(int i = 0; i<str.size(); ++i){
 			if(str[i] == ')'){
 				p_count++;
 			}
 			if(p_count > 1){
 				throw std::runtime_error("Error: Too many closing parentheses");
 				return in;
 			}
 		}

	 	// check that first char is '('
 		if (str[0] != '(') {
 			throw std::runtime_error("Error: first char should be '('");
 			return in;
 		}

 		// check that the last char is ')'
 		if (str[str.size()-1] != ')'){
 			throw std::runtime_error("Error: last char should be '')'");
 			return in;
 		}

 		// extract substrings for real and imag part 	
	 	std::string real_str = str.substr(index1 + 1,index2 - index1 -1);
		std::string imag_str = str.substr(index2 + 1,index3 - index2 -1);

		// check sizes of strings
		if(real_str.size() < 1 || imag_str.size() < 1){
			throw std::runtime_error("Error: real and imag part must consist of at least one number");
			return in;
		}

		// check if real and imag strings are numerical
		for(int i = 0; i<real_str.size();++i){
				if((real_str[i] > '9' || real_str[i] < '0') && real_str[i] != '-' && real_str[i] != '.'){
					throw std::runtime_error("Error: string not numerical");
					return in;
				}

				// if only minus in string
				if(real_str.size() == 1 && str[i] == '-'){
					throw std::runtime_error("Error: string only containing '-'");
					return in;
				}

				// only first char can be '-' 
				if (i > 0 && real_str[i] == '-'){
					throw std::runtime_error("'-' must come before numbers");
					return in;
				}
		}

		for(int i = 0; i<imag_str.size();++i){
				if((imag_str[i] > '9' || imag_str[i] < '0') && imag_str[i] != '-' && imag_str[i] != '.' ){
					throw std::runtime_error("Error: string not numerical");
					return in;
				}

				// if only minus in string
				if(imag_str.size() == 1 && str[i] == '-'){
					throw std::runtime_error("Error: string only containing '-'");
					return in;
				}

				// only first char can be '-' 
				if (i > 0 && imag_str[i] == '-'){
					throw std::runtime_error("'-' must come before numbers");
					return in;
				}
		}

		try{
			double real = std::stod(real_str);
			double imag = std::stod(imag_str);
			c = Complex(real,imag);
			return in;
		} catch(const std::exception& ex){
			// if conversion to double doesn't work
			std::cout << "Error: " << ex.what() << std::endl;
			throw std::runtime_error("Error: couldn't convert string to double");
			return in;
		}
 	}
}

Complex myLib::operator+ (const Complex& a){
	std::cout << "unary operator + " << std::endl;
	
	return Complex(a.real(),a.imag());
}

Complex myLib::operator- (const Complex& a){
	std::cout << "unary operator - " << std::endl;

	double real = -a.real();
	double imag = -a.imag();

	return Complex(real,imag);
}

Complex myLib::operator+ (const Complex& a, const Complex& b){
	std::cout << "operator + " << std::endl;
	double real = a.real() + b.real();
	double imag = a.imag() + b.imag();

	return Complex(real,imag);
}

Complex myLib::operator- (const Complex& a, const Complex& b){
	std::cout << "operator - " << std::endl;

	double real = a.real() - b.real();
	double imag = a.imag() - b.imag();

	return Complex(real,imag);
}

bool myLib::operator== (const Complex& a, const Complex& b){
	
	if((a.real() < (b.real() + DOUBLE_PRECISION) && (a.real() > (b.real() - DOUBLE_PRECISION)))){
		if((a.imag() < (b.imag() + DOUBLE_PRECISION) && (a.imag() > (b.imag() - DOUBLE_PRECISION)))){
			return true;

		}else{
			return false;
		}
	} else{
		return false;
	}
}

bool myLib::operator!= (const Complex& a, const Complex& b){
	
	if((a.real() < (b.real() + DOUBLE_PRECISION) && (a.real() > (b.real() - DOUBLE_PRECISION)))){
		if((a.imag() < (b.imag() + DOUBLE_PRECISION) && (a.imag() > (b.imag() - DOUBLE_PRECISION)))){
			return false;

		}else{
			return true;
		}
	} else{
		return true;
	}
}

double myLib::abs(const Complex& c){
	double abs = sqrt(c.real()*c.real() + c.imag()*c.imag());
	return abs;
}

double myLib::real(const Complex& c){
	return c.real();
}

double myLib::imag(const Complex& c){
	return c.imag();
}

Complex myLib::operator* (const Complex& a, const Complex& b){
	// (a + bi)(c + di) = (ac - bd) + (bc + ad)i
	std::cout << "operator * " << std::endl;
	return multiplyComplex(a,b);
}

Complex myLib::operator/ (const Complex& a, const Complex& b){
	// (a + bi)(c + di) = (ac - bd) + (bc + ad)i
	Complex conjugate(b.real(),-b.imag()); // conjugate of the denominator

	Complex numerator = multiplyComplex(a,conjugate);
	Complex denominator = multiplyComplex(b,conjugate);  

	if(denominator.real() == 0.0){
		throw std::runtime_error("error: division by zero");
	}

	double real = numerator.real()/denominator.real();  // denominator's imag part is zero after conjugate multiplication
	double imag = numerator.imag()/denominator.real();
	return Complex(real,imag);
}



/*
int main(){
	Complex a(2,3);
	Complex b(2,0);

	Complex c(2,3);
	Complex d(4,-5);	

	a += b;
	Complex e = b + c + d;
	e = a + b + c;

	std::cout << e << std::endl;
}
*/