# C++ Questions [todo]

---------------------------------------------------------------------------------------------------
// [DONE]
Question:       What does the const member function qualifier do?
Choice 1
     It allows the invocation of a non-const member function for the object pointed to by this.
Choice 2
     It guarantees that only mutable member variables of the object pointed to by this can be changed.
Choice 3
     It ensures that all constants remain invariable.
Choice 4
     It prevents inheritance.
Choice 5
     It allows changes to the state of the object pointed to by this.

---------------------------------------------------------------------------------------------------
Sample code:

     class Value {
            std::string s_val;
            int         i_val;

        public:
            Value(std:string s, int i) :
                s_val(s), i_val(i)
            {
            }
     };

Question:  Referring to the Sample code above, which one of the following operators do you need to override in
order to be able to use the container "std::set<Value>"?
Choice 1
     operator <
Choice 2
     operator >=
Choice 3
     operator <=
Choice 4
     operator !=
Choice 5
     operator >

---------------------------------------------------------------------------------------------------
Sample code:

     extern void done(int, int) throw(const char*, RangeErr);

Question:  Referring to the Sample code above, which one of the following statements is true regarding the declaration of done?
Choice 1
     done is an extern void; therefore, it does not throw exceptions.
Choice 2
     done guarantees that it only throws RangeErr exceptions.
Choice 3
     done guarantees that it only throws char* exceptions.
Choice 4
     done guarantees that it only throws RangeErr and character pointer exceptions.
Choice 5
     done guarantees that it only throws integer exceptions.

---------------------------------------------------------------------------------------------------
Sample code:

    class professor {};
    class researcher {};
    class teacher :
        public professor {};
    class myprofessor :
        public teacher,
        public virtual researcher {};

Question:  Referring to the Sample code above, when an object of class myprofessor goes out of scope, what is
the correct order of destructor invocation?
Choice 1
     ~teacher(),~researcher(),~myprofessor(),~professor()
Choice 2
     ~myprofessor(),~teacher(),~professor(),~researcher()
Choice 3
     ~professor(), ~teacher(),~myprofessor(), ~researcher()
Choice 4
     ~researcher(),~professor(), ~teacher(), ~myprofessor()
Choice 5
     ~myprofessor(),~professor(), ~teacher(),~researcher()

---------------------------------------------------------------------------------------------------
Sample code:

    #include <iostream>

    class Airplane {
        /*....*/
    };

    void do_stuff_and_output(Airplane &a){
        /* ... */
        std::cout << a << '\n'; // output the Airplane object a
    }

Question:  Referring the Sample code above, which one of the following operators needs to be defined so that
the airplane object can be output as shown?
Choice 1
     Define:
std::ostream& operator<<(std::ostream&, Airplane const&)
as a stand alone, overloaded operator.
Choice 2
     Define:
std::streambuf& operator<<(std::ostream&, Airplane const&)
as a stand alone, overloaded operator.
Choice 3
     Define:
std::ostream& operator<<(std::ostream&)
as a member function of class Airplane.
Choice 4
     Define:
void std::operator<<(std::ostream&)
as a member function of class Airplane.
Choice 5
     Define:
void <<operator<<(std::ostream&, Airplane const&)
as a stand alone, overloaded operator.

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    #include <iostream>
    #include <vector>
    #include <algorithm>

    int main() {
       std::vector<std::string> vs;

       std::fill_n(std::back_inserter(vs), 5, "hello");

       for (
          std::vector<std::string>::iterator it = vs.begin();
          it != vs.end();
          ++it)
       {
          std::cout << *it << std::endl;
       }

       return 0;
    }

Question:  Referring to the container definition above, which one of the following
lines of code fills vs with five strings containing the word "hello"?

Choice 1
     std::fill(vs.begin(), vs.end(), "hello");
Choice 2
     std::generate_n(std::back_inserter(vs), 5, "hello");
Choice 3+
     std::fill_n(std::back_inserter(vs), 5, "hello");
Choice 4
     vs = std::vector<std::string>("hello");
Choice 5
     std::generate(vs.begin(), 5, "hello");

---------------------------------------------------------------------------------------------------
Scenario:
     You have a class whose internal representation is not exposed
	 to the user and can change transparently.
Question:  The above scenario is an example of which one of the following?
Choice 1
     Inheritance
Choice 2
     Abstraction
Choice 3
     Derivation
Choice 4
     Encapsulation
Choice 5
     Polymorphism

---------------------------------------------------------------------------------------------------
// [DONE]
Question:
	Which one of the following is the correct way to declare a pointer to non-static member function
	of class A that accepts an int reference and returns void?
Choice 1
     void (A::f)(int&);
Choice 2
     void (A::f*)(int&);
Choice 3
     void (A*::f)(int&);
Choice 4+
     void (A::*f)(int&);
Choice 5
     void (*A::f)(int&);

---------------------------------------------------------------------------------------------------
// [DONE]
Question:       Where do you initialize a non-static class member that is a reference?
Choice 1
     Point of declaration and member initialization list
Choice 2
     Member initialization list and body of constructor
Choice 3
     Body of constructor only
Choice 4
     Point of declaration only
Choice 5
     Member initialization list only


---------------------------------------------------------------------------------------------------
Sample code:

    template <typename T>
    class Foo {
           T tVar;

        public:
           Foo(T t) : tVar(t) { }
    };

    class FooDerived :
        public Foo<std::string>
    {
    };

    FooDerived fd;

Question:  What is preventing the above code from being legal C++?
Choice 1
     FooDerived uses the non-C++ type std::string.
Choice 2
     FooDerived is a non-template class that derives from a template class.
Choice 3
     The initialization of tVar occurs outside the body of Foo's constructor.
Choice 4
     A constructor must be provided in FooDerived.
Choice 5
     tVar is a variable of an unknown type.

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    #include <iostream>

    class Base {};
    class Sub1  : public virtual Base { };
    class Sub2  : public         Base { };
    class Multi : public Sub1, public Sub2 { };

    int main() {
       Multi m;

       return 0;
    }

Question:  Referring to the Sample code above, how many times is the constructor for Base called?
Choice 1+
     0
Choice 2
     1
Choice 3
     2
Choice 4
     3
Choice 5
     4

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    #include <iostream>

    struct B {
       void Go() {
          std::cout << "B::Go ";
       }
       void Back() {
          std::cout << "B::Back ";
       }
    };

    struct C :
       public B
    {
       void Go() {
          std::cout << "C::Go ";
       }
    };

    struct D :
       public B
    {
       void Back() {
          std::cout << "D::Go ";
       }
    };

    B *bd = new D;
    B *bc = new C;
    D  d;

    void foo() {
       bd->Go();
       bd->Back();

       bc->Go();
       bc->Back();

       d.Go();
    }

    int main() {
       foo();

       return 0;
    }

Question:  Referring to the Sample code above, what is the displayed output when f() is called?
Choice 1
     B::Go D::Back C::Go B::Back B::Go
Choice 2
     B::Go B::Back C::Go B::Back D::Go
Choice 3
     B::Go D::Back C::Go B::Back D::Go
Choice 4
     D::Go B::Back C::Go B::Back B::Go
Choice 5+
     B::Go B::Back B::Go B::Back B::Go

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    class A
    {
        public:
            A () {}
            A (A& a) {}
            A& operator = (const A &a) {
                return (*this);
            }
    };

    int main ()
    {
        const A a1;
        A a2(a1);

        return 0;
    }

Question:  Given the Sample code shown above, which one of the following statements is true?
Choice 1
     There is nothing wrong with the code.
Choice 2+
     The instantiation of a2 is illegal.
Choice 3
     Class objects cannot be declared as const.
Choice 4
     The assignment operator for A is illegal.
Choice 5
     The constructor declaration for A is illegal.

---------------------------------------------------------------------------------------------------
// [DONE]
Statement
    C++ contains numerous algorithm functions that accept function objects as a parameter.

Question:  Referring to the statement above, which one of the following is another name for function objects?
Choice 1+
     Predicates
Choice 2
     Iterators
Choice 3
     Use Case
Choice 4
     Operators
Choice 5
     Actions

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    class Foo {
        public:
           explicit Foo(int i);
    };

Question:  In the Sample code above, what is the purpose of explicit keyword?
Choice 1
     It is a syntax error.
Choice 2
     It requires that Foo be initialized from an integer literal.
Choice 3+
     It prevents the constructor from being used to implicitly convert from int to Foo.
Choice 4
     It is the return type for the Foo member function.
Choice 5
     It prevents the constructor from being called from a non-explicit function.

---------------------------------------------------------------------------------------------------
// [DONE]
Scenario:

    std::string s("Hello World");
    char *c = s.c_str();
    float f = strlen(c);

Question:  Referring to the scenario above, what causes the error?
Choice 1
     std::string::c_str() is missing a parameter
Choice 2
     You cannot assign strlen(c) to a floating point variable.
Choice 3
     You cannot assign a char* literal to a string constructor.
Choice 4
     c is not a pointer to const.
Choice 5
     You cannot assign a literal character to a char* variable.

Answer: Choice 4
    source.cpp:7:23: error: invalid conversion from 'const char*' to 'char*' [-fpermissive]

---------------------------------------------------------------------------------------------------
Scenario:
     You need to define the following function so that it will return true if the sets passed to it have any intersection
	 and false otherwise.

template<class T>
bool hasIntersection(std::vector<T>& set1, std::vector<T>& set2);

Question:  Referring to the scenario above, which one of the following STL functions can be used to implement hasIntersection?
Choice 1
     std::find_first_of()
Choice 2
     std::adjacent_find()
Choice 3
     std::equal()
Choice 4
      std::nth_element()
Choice 5
     std::search_n()

---------------------------------------------------------------------------------------------------
Sample code:

    class mybase {};
    class derived1 { };
    class derived2 : public mybase, derived1{};

Question:  Referring to the Sample code above, which one of the following statements is true regarding derived2?
Choice 1
     The declaration of derived2 is invalid because derived1 must have an access specifier.
Choice 2
     derived2 uses public inheritance for mybase and public inheritance for derived1.
Choice 3
     derived2 uses public inheritance for mybase and private inheritance for derived1.
Choice 4
     The declaration of derived2 is invalid because derived2 can only inherit from one class.
Choice 5
     The declaration of derived2 is invalid because either derived or mybase must be virtual.

---------------------------------------------------------------------------------------------------
Sample code:

    void f() throw(std::runtime_error) {
        /* imagine some code here */

        if (/* some error condition */) {
            throw (some_exception);
        }
    }

Question:  Which one of the following types is valid for some_exception above?
Choice 1
     std::range_error
Choice 2
     std::bad_alloc
Choice 3
     std::exception
Choice 4
     std::invalid_argument
Choice 5
     std::logic_error


---------------------------------------------------------------------------------------------------
Question:       With regard to enumeration types, which one of the following statements is true?
Choice 1
     Only one identifier in an enum list can have the value zero.
Choice 2
     When an enumerator is used, its value is implicitly converted to an integer when needed.
Choice 3
     Enumeration types must be defined in the body of a class definition.
Choice 4
     Enumerators for which no value is explicitly specified have a value of zero.
Choice 5
     An integer can implicitly be converted to an enumeration type.

---------------------------------------------------------------------------------------------------
Sample code:

    #include <string>
    #include <iostream>

    using namespace std;
    std::string str;

Question:  Referring to the Sample code above, which one of the following statements do you use in order to read a std::string, of any length, from the standard input stream?

Choice 1
     getline(cin, str);
Choice 2
     cout.read(str);
Choice 3
     cin.read(str);
Choice 4
     getline(str);
Choice 5
     cin.getline(str);

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    class Z {
        public:
            Z(): e(0), i(0)
            {}
            int Enter() const {
                ++e;
                return (i);
            }
            int Leave() const {
                --e;
                return (i);
            }
            void Wait() {
                while (e > 0);
            }
        private:
            int         i;
            mutable int e;
    };

Question:  Referring to the Sample code above, why is the member variable e declared as mutable?
Choice 1
     It tells the compiler to allow modification to e in const member functions.
Choice 2
     It tells the compiler not to optimize access to the member variable e.
Choice 3
     Being declared as mutable is incorrect in this context.
Choice 4
     It tells the compiler to allow modification to e in non-member functions.
Choice 5
     It tells the compiler to allocate storage for e in a separate section.

---------------------------------------------------------------------------------------------------
Sample code:

     template<>
     class Stack<char> {
        public:
            int  Push(char);
            char Pop ();
     };

Question:  Referring to the Sample code above, the template<> signifies that this class is an example of which one of the following?
Choice 1
     Default template initialization
Choice 2
     A queue class
Choice 3
     Template specialization
Choice 4
     A virtual template class
Choice 5
     An empty template declaration

---------------------------------------------------------------------------------------------------
Question:       What happens if a function throws an exception that is NOT listed in the function exception specification list?
Choice 1
     The exception is passed up the handler chain.
Choice 2
     unhandled() is immediately invoked.
Choice 3
     terminate() is immediately invoked.
Choice 4
     unexpected() is immediately invoked.
Choice 5
     abort() is immediately invoked.

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    #include <iostream>

    class A {
        int i;

    public:
        A              (int ii)     { i = ii; }
        A              (const A &a) { i = a.i; ++ i; }
        A&  operator = (const A &a) { i = a.i; -- i; return *this; }

        int get        ()           { return i; }
    };

    int main(void) {
        A a(4);
        A b = a;

        std::cout << b.get() << std::endl;

        return 0;
    }

Question:  What is the value of b.i just before the return statement in main?
Choice 1
     The value of b.i is undefined.
Choice 2
     2
Choice 3
     3
Choice 4
     4
Choice 5+
     5

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    template<typename T>
    bool is_int<T>();

Question:  is_int must return true if T is int and false otherwise. How do you implement is_int?
Choice 1
    template<typename T>
    bool is_int() {
        return false;
    };
    template<>
    bool is_int<int>() {
        return true;
    };

Choice 2
    template<typename T>
    bool is_int<T>() {
        return T is int;
    }

Choice 3
    template<typename T>
    bool is_int<T>() {
        return false;
    };
    template<int>
    bool is_int() {
        return true;
    };

Choice 4
    template<typename T>
    bool is_int<T>() {
        T a;
        return ( NULL != dynamic_cast<int *>( &a ) );
    }

Choice 5+
    template<typename T>
    bool is_int<T>() {
        return ( typeof(T) == typeof(int) );
    };

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    class Base {
        public:
                     Base() {}
            virtual ~Base() {}
    };

    class Derived :
        protected Base
    {
        public:
            virtual ~Derived() {}
    };

    int main() {
        Base *pb = new Derived;

        return 0;
    }

Question:  Referring to the Sample code: above, which one of the following statements is true?
Choice 1+
     A pointer to a Base class cannot point to an instance of a Derived class.
Choice 2
     The code compiles with no errors.
Choice 3
     A constructor needs to be added to Derived class.
Choice 4
     The pointer returned by new cannot be type cast from Derived* to Base*.
Choice 5
     Derived class cannot have a virtual destructor.

---------------------------------------------------------------------------------------------------
// [DONE]
Question:       The number of characters contained in a std::string object can be found using which one of the following functions?
Choice 1+
     std::string::size
Choice 2
     std::strlen
Choice 3
     std::string::strlen
Choice 4
     std::string::c_str
Choice 5
     std::string::capacity

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    /*
        std::range_error -> std::runtime_error -> std::exception
        std::logic_error                       -> std::exception
    */

    #include <stdexcept>
    #include <iostream>

    int main()
    {
        try {
            throw std::range_error("ERROR");
        }
        catch (std::logic_error const &x) {
            std::cout << "A-" << x.what();
        }
        catch (std::exception const &x) {
            std::cout << "B-" << x.what();
        }
        catch (...) {
            std::cout << "C";
        }

        std::cout << "-[DONE]" << std::endl;

        return 0;
    }

Question:  What is the output of the above program?
Choice 1
     A-ERROR-[DONE]
Choice 2
     A-range_error-[DONE]
Choice 3+
     B-ERROR-[DONE]
Choice 4
     B-range_error-[DONE]
Choice 5
     C-[DONE]

---------------------------------------------------------------------------------------------------
// [DONE]:
Question:       Given a variable str of type std::string, which one of the following statements outputs the string backwards?
Choice 1
     std::copy(str.reverse(), std::unary_function(std::cout));
Choice 2
     std::reverse(str); std::cout << str;
Choice 3+
     for (unsigned int i = str.size(); i > 0; i--) {
         std::cout << str[str.length() - i];
     }
Choice 4
     std::reverse_copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout));
Choice 5
     std::cout << str.reverse();

---------------------------------------------------------------------------------------------------
Sample code:

    class X {
        public:
                  X& operator=(const X& rhs);
            const X& operator+(const X& rhs) const;
            const X& operator+(int m);

        private:
            int n;
    };

    int main ()
    {
        X a, b, c;

        return 0;
    }

Question:  Given the Sample code: above, which one of the following statements is illegal?
Choice 1
     a = b + 5;
Choice 2
     a = b + c + 5;
Choice 3
     (c = a + a) = b + c;
Choice 4
     a = a + 5 + c;
Choice 5
     a = a = b + c;

---------------------------------------------------------------------------------------------------
Scenario:
     A function throws an exception of type std::unexpected.

Question:  Referring to the scenario above, what is a logical cause?
Choice 1
     An exception thrown is not yet caught and the destructor for an object throws an exception during the stack unwinding.
Choice 2
     The application is targeting one operating system, but another operating system is being used, which generates the exception.
Choice 3
     There is no catch-all enabled in scope closest to the function call.
Choice 4
     An exception of type std::unexpected can never be thrown in a well-formed C/C++ program.
Choice 5
     An exception is thrown in which the type is not in the function's exception specification.

---------------------------------------------------------------------------------------------------
// [DONE]
Question:       In order to use std::cin and std::cout, which header file do you include in your code?
Choice 1+
     <iostream>
Choice 2
     "string.h"
Choice 3
     <iomanip.h>
Choice 4
     string.h
Choice 5
     <string.h>

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    #include <iostream>

    namespace N1 {
       int f(int n) {
          return n * 2;
       }
    }

    namespace N2 {
       int f(double n) {
          return n * 3;
       }
    }

    int main()
    {
       using N1::f;
       int i1 = f(1.0);
       std::cout << i1 << std::endl;

       using N2::f;
       int i2 = f(1.0);
       std::cout << i2 << std::endl;

       return 0;
    }

Question:  Referring to the Sample code: above, which one of the following statements is true?
Choice 1
     Both i1 and i2 are set to 2.
Choice 2+
     i1 is set to 2 and i2 is set to 3.
Choice 3
     Both i1 and i2 are set to 3.
Choice 4
     Given the fact that no function prototype exists for a double when the first call to f() is made, the code does not compile.
Choice 5
     Given the fact that the same function name f() is brought into scope multiple times, the code does not compile.

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    #include <iostream>

    namespace {
       static int n;
    }

    namespace A {
       namespace {
          static int n;
       }
    }

    using namespace A;

    int main()
    {
       n = 5;

       std::cout << n << std::endl;

       return 0;
    }

Question:  Referring to the Sample code: above, which one of the following statements is true?
Choice 1
     There is nothing wrong with the Sample code:.
Choice 2
     Nested namespaces that are unnamed are illegal.
Choice 3
     Unnamed namespaces are illegal.
Choice 4+
     The reference to n is ambiguous.
Choice 5
     Nested namespaces are illegal.

---------------------------------------------------------------------------------------------------
// N/A
Sample code:

    #include <iostream>

    struct Foo {
        Foo()        { std::cout << "d"; }
        Foo(int i)   { std::cout << "i"; }
        Foo(char c)  { std::cout << "c"; }
        Foo(long l)  { std::cout << "l"; }
        Foo(float f) { std::cout << "f"; }
    };

    int main()
    {
        Foo f1('a');
        Foo f2('a' + 1);
        Foo f3(1);
        Foo f4(0x01);
        Foo f5(0x0001L);
        Foo f6(1.0f);

        return 0;
    }

Question:  Referring to the above Sample code:, what is the output when the program is executed?
Choice 1
     cciilf
Choice 2
     iiiilf
Choice 3+
     ciiilf
Choice 4
     iciilf
Choice 5
     ciillf

---------------------------------------------------------------------------------------------------
Sample code:

    template<class T>
    class A {
        public:
        A(){}
    };

    template<class T>
    class B {
        public:
            B() {};
            /* add something here to make A a friend */
    };

Question:  Referring to the Sample code: shown above, which one of the following declares every specialization of A to be a friend class of the corresponding specialization of B?
Choice 1
     template friend class A<T>;
Choice 2
     friend class A<T>;
Choice 3
     template<> friend class A;
Choice 4
     friend template class A<B>;
Choice 5
     friend template<class B> class A;

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    #include <iostream>

    int main()
    {
       char abc[] = "";

       std::cout << "[" << abc[0] << "]" << std::endl;

       return 0;
    }

Question:  Which one of the following is true regarding the array abc created by the declaration in the sample above?
Choice 1
     abc contains 0 elements.
Choice 2+
     abc contains 1 element.
Choice 3
     abc contains 2 elements.
Choice 4
     The number of elements in abc is operating system dependent.
Choice 5
     There is a syntax error in that the initializer list is empty.

---------------------------------------------------------------------------------------------------
// [DONE]
Sample code:

    #include <iostream>

    void HandleNoMemory() {
        std::cout << __FUNCTION__ << std::endl;
    }

    int main() {
        int *p = new int[100];
        if (!p) {
            HandleNoMemory();
        }

        return 0;
    }

Question:  Referring to the Sample code: above and assuming the standard C++ new operator is being used, which one of the following statements is true?
Choice 1+
     HandleNoMemory() is never called.
Choice 2
     sizeof(p) is 400 after a successful new.
Choice 3
     This code does not compile.
Choice 4
     An exception of type std::outofmemory can be thrown.
Choice 5
     An exception of type std::failed_alloc can be thrown.

---------------------------------------------------------------------------------------------------
