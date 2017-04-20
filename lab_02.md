# Lab 2: Complex numbers

For this lab you will create a class that represents a complex number. In essence, you will create a class that can handle addition, subtraction, multiplication and division.
How to do this can be found out by reading the [wikipedia page](https://en.wikipedia.org/wiki/Complex_number)

## Functions
In the style of [cpprefferenc](http://en.cppreference.com/w/cpp/numeric/complex) the following things should be defined:

|Member functions
| ---                 | --- |
|(constructor)        | constructs a complex number|
|operator=            | assigns the contents|
|real                 | accesses the real part of the complex number|
|imag                 | accesses the imaginary part of the complex number|
|operator+= -= /= *=  | compound assignment of two complex numbers or a complex and a scalar|

|Non-member functions
| ---             | ---|
| operator+ -     | applies unary operators to complex numbers|
| operator+ - * / | performs complex number arithmetics on two complex values or a complex and a scalar|
| operator== !=   | compares two complex numbers or a complex and a scalar|
| real            | returns the real component|
| imag            | returns the imaginary component|
| abs             | returns the magnitude of a complex number|

## Specific Requirements

These following requirements need to be fulfilled to pass this lab.

* You are not allowed to use any implicit functions, you have to write all of them by yourself.

* The type that you use to save the values should be doubles.

* There should be three constructors. Default, real, real and imaginary.

* There should be both a copy assign and a assign that takes a real.

* You should be able to answer what function/functions will be called for all types of assignments and constructions. This is most easily tested by adding prints to them.
