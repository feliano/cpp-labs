#include <iostream>
#include <math.h>


namespace myLib{

class Complex{

public:
	Complex();
    Complex(double real); // Note: non explicit
	constexpr Complex(double real, double imag): _real(real), _imag(imag) {
        //std::cout << "other constructor" << std::endl;
    }
    constexpr Complex(const Complex &rhs): _real(rhs.real()), _imag(rhs.imag()){
        //std::cout << "Copy constructor" << std::endl;
    }

    const Complex& operator= (const Complex& c);
    void operator+= (const Complex& c);
    void operator-= (const Complex& c);
    void operator*= (const Complex& c);
    void operator/= (const Complex& c);

    friend std::istream& operator>> (std::istream& in, Complex& c);

    double real() const;
    double imag() const;
private:
	double _real;
	double _imag;
};

// Unary
Complex operator+ (const Complex& a);
Complex operator- (const Complex& a);

// Binary
Complex operator+ (const Complex& a, const Complex& b);
Complex operator- (const Complex& a, const Complex& b);
Complex operator/ (const Complex& a, const Complex& b);
Complex operator* (const Complex& a, const Complex& b);

std::ostream& operator<< (std::ostream& out, const Complex& c);
std::istream& operator>> (std::istream& in, Complex& c);

bool operator== (const Complex& a, const Complex& b);
bool operator!= (const Complex& a, const Complex& b);

double abs(const Complex& c);
double real(const Complex& c);
double imag(const Complex& c);
Complex multiplyComplex(const Complex& a, const Complex& b);
constexpr Complex operator""_i(long double arg){
    return Complex{0.0,static_cast<double>(arg)};
}
constexpr Complex operator""_i(unsigned long long arg){
    return Complex{0.0,static_cast<double>(arg)};
}

}