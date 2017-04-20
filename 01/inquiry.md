## Lab 1 answers

The file format is [markdown](https://en.wikipedia.org/wiki/Markdown) a tutorial on markdown can be found [here](http://www.markdowntutorial.com/). Write your answers here. Copy relevant code to put questions and answers in context.
Commit and push _inquiry.md_ each day you work with the file.

#### g++ compiler questions

#### Where can you find the manual to g++?

https://gcc.gnu.org/onlinedocs/

####     What is the purpose of _-Wall_ and _-g_, when passed as arguments to _g++_?

-Wall:
	Enables all warnings of construction which are deemed to be easily avoidable by the developer. Things that are not necessarily bad but suspicious.

-g:
    debug information, good for debugging

####     How can you store the previous mentioned flags in a variable in the makefile?

CPPFLAGS = -Wall -g

$(CPPFLAGS)

#### Find and write down 3 other arguments tp _g++_ that you think might be useful and write a short motivation why you selected these specific 3 arguments.

-o:
    Name the program. Very useful if you§ want specify the name yourself.

-pedantic:
    Turns off more extensions and generates more warnings. example: compiler must support string literal of at least 509. -pedantic will warn for longer

-std=c++11:
    enable c++11

####   What is the difference between an object file, and an executable?

Object files are compiled source code, linked object files make up an executable

#### Git Questions

#### What does _git show HEAD~:01/makefile_ show?

The first parent of the current commit

#### What does _git show HEAD:01/makefile_ show?

The current commit

#### What would _git show HEAD~~:01/makefile_ show?

The first parent of the first parent of the commit

#### What does the _~_ in the previous _git show_ commands mean?

It’s refering to parent commits. ~~ = ~2.

#### Why can you not ommit _01_ in the previous commands (i.e. _git show HEAD~:makefile_ instead of  _git show HEAD~:01/makefile_)

Because of the filetree git uses. ‘.’ can replace the currently visited path

#### Sometimes you may need to do a _git pull_ before you can do a _git push_ how can that be?

Someone else could have made and commited changes to git which means you need to upgrade your local copy before pushing.

#### What is the purpose of the .git_ignore file and why should \*.o \*.out \*.exe be in this file when developing C++?

it’s meant to keep track of files which are to be excluded from version control. The files generated are system dependent and will not run correctly if they’re copied between machines. C++ is platform independent but the compilers are different and the code needs to be compiled and linked on the machine it’s supposed to run on.

#### makefile questions

#### If you invoke _touch hello.cpp_ prior to invoking _make_, how many files were rebuilt?

Two, hello.cpp and main.cpp. 

#### Why?

Main is dependent on hello.cpp. (if hello.cpp is updated then main must be updated)

#### Why do you think _make_ checks the modification timestamp of the relevant files as part of deciding what to do?

For large projects it would be time consuming to compile everything from scratch, it saves time to keep track of what actually needs to be updated.

#### What is the difference between an implicit rule and an explicit rule in a makefile?

Implicit rules don’t have to specify target (general case) which explicit rules do

#### What does _\$*_ mean inside a _makefile_?

  _\$*_ is replace by the target file name  _\test_ but without extension


#### Hello world questions

#### What is the purpose of _std::cout_, _std::cerr_, and _std::clog_, respectively?

Three different streams, separates error/log from regular messages

#### How does #include work?

The compiler replaces it by copy pasting the files specified after the include


#### debugging questions

Using lldb
useful commands:
breakpoint set -f weird.cpp -l 16
c 
n
thread until 16
br del 1 - (deletes first breakpoint)
c -i 50 - (ignores the 50 next breakpoints in the thread)
p variable - prints the variable value
expr i = 50 - sets the local variable i to 50 

#### Why does not _powerof_ return the expected value (_16_), when invoked with _2_ and _4_?

The body of the for loop is empty.

int powerof (int x, int y) {
  int res = 1;

  for (int i = 0; i < y; ++i);     // <------ THIS SEMICOLON
    res = res * x;

  return res;
}

#### Why does not _adding_a_decimal_ output 100000?

Because of precision errors with floats.
Step is not represented as 0.1 but rather 0.10000001
These precision errors will add up quickly if we use +=

void adding_a_decimal(float step) {
  float sum = step;
  for (int i = 0; i < 1000*1000; ++i) {
    sum += step;
  }
  std::cout << std::setw(4) << sum << std::endl;
}

#### Describe how _weird.out_ is invoked by _echo '3.1415' | ./weird.out_  

The symbol | is called a pipe and it will redirect the output of the program on the left as input to the program on the right. echo is a program which writes it’s argument to the standard output stream.

#### Why does not _y_ compare equal to _3.1415_?

Because 3.1415 is a double which will be cast to a float but since they have different precision from the beginning they’re not going to match.

float y;
  std::cout << "What is the value of PI? ";
  std::cin >> y;
  if (y == 3.1415)
    std::cout << y << " is equal to 3.1415!\n";
  else
    std::cout << y << " is not equal to 3.1415!\n";
}

#### Is there any difference in behavior if we compare _y_ to _3.1415f_, if so; why?

Yes if force it to be a float it does compare correctly and will say that they’re equal.

#### Describe and motivate the recommended method to use when trying to determine if two floating-point values are equal.

Define a tolerance value, then take the absolute value of the difference between the two floats and see if it’s less than the tolerance threshold. There’s no fixed value to use as tolerance it’s a design choice and depends on the program requirements.

#### unit test questions

#### Why is it important to test the boundary conditions of an implementation, especially in the case of _count_if_followed_by_?
To make sure that it stays inside the range.


#### Describe how the testcase tests if a pointer is accessing an element outside the range specified
It limits the range to zero or the same as the array and check that the result is the expected one.


#### class construction questions

#### What constructors are invoked, and when? List the corresponding lines and name the invoked constructor

l. 32 - some other constructor - 	Complex a("3_2i");
l. 34 - copy constructor -     		Complex b = a;
l. 35 - copy constructor - 			Complex c(a);
l. 36 - default constructor -		Complex d;
l.38 - assignment operator - 		d = a;
l.40 - copy constructor (pass by value), and then destructor (goes out of scope) - no_ref (a);
l.41 - no call, pass by reference -     with_ref (a);

l.43 - default constructor - Complex *aa = new Complex[5];
l.44 - one destructor call - delete aa;

#### Will there be any temporaries created, if so; when?
yes on l.32


#### What will happen if we try to free a dynamically allocated array through _delete p_, instead of _delete [] p_?

It will only call one of the destructors not an array of destructors. furthermore using delete on objects created with new[] is undefined behaviour. I get the error “pointer being freed wasn’t allocated”

#### valgrind

#### _valgrind_ indicates that there is something wrong with _complex.cpp_; what, and why?

It leakes memory because not all of the dynamically allocated memory on line 43 is being freed.

l.43    Complex *aa = new Complex[5];
l.44    delete aa;        // what will happen?

#### _valgrind_ indicates that the program (bad_plumming.cpp) suffers from a few problems, which and why?

struct Data {
    int x, y, z;
};  

Data ** foo(Data ** v, int x) {
    for (int i = 0; i < x; i++)
 		//if (v[i] != 0)  // line 7
     		v[i] = new Data;
    return v;
}

int main () {
    const int size = 5;
    Data ** v = new Data * [size]; // line 14
    Data ** p = foo(v, size);

    // delete each data object
    for(int i = 0; i<size;++i){
    	delete *(p+i);
    }

    delete [] p;
}

The if statement on line 7 depends on unintialized values. Data on line 14 is not being initialized. Static Non-initialized data will be init to zero. 

The other problem is about memory leaks because of the dynamically created values on line 14 not being deleted

#### If you comment out the entire if-block in _foo_, is there any difference in how much memory that is leaked?

No because static non-initialized (file scope and static) are initialized to zero so the if statement will never be true. The only memory leak is the one as before.

#### Why is it that valgrind still issue diagnostics related to memory management?

all the allocated dynamic memory is not freed. The data elements are not being freed. We have a pointer to a pointer to a Data object. The second pointer is what’s taken care of by the delete [] call. We need also to delete each data object.

#### Add code that fixes the memory management

Added a for-loop 

    // delete each data object
    for(int i = 0; i<size;++i){
        delete *(p+i);
    }

