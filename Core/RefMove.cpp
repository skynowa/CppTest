#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct A
{
    A(const A &a) : _str(a._str) {cout << "A(const A &)" << endl;}
	A(A &&a) : _str(move(a._str)) {cout << "A(A &&)" << endl;}
	// A & operator = (const A &) {cout << "A & operator = (const A &)" << endl;}
	// A & operator = (A &&) {cout << "A & operator = (A &&)" << endl;}
	A() {cout << "A()" << endl;}
    A(const string &str): _str(str) {cout << "A(string str)" << endl; }
    ~A() {cout << "destructor" << endl;}

    string _str;
};

void func()
{
    // string str = "1";
    A a1("kfsdfkjasn gjkansjkdfnasjkdf kasj kfjkl;sdjgiuhwughsdn jsodjsdpi");
    // const A a2("2");
    // const A a3("3");
    // cout << "initialize" << endl;

    // vector<A> v;// {a1, a2, a3};
    vector<A> v;// {{a1}, {a2}, {a3}};

    // cout << "size = " << v.size() << endl;

    // v.resize(3);
    v.push_back(a1);
    // v.push_back(a2);
    // v.push_back(a3);

// cout << "vector: " << v[0]._str << endl;
cout << "Start*********" << endl;

    for (auto && it: v) {
        cout << typeid(it).name() << endl;
        auto test = move(it._str);

        // cout << test._str << endl;
        // cout << it._str << endl;
        cout << v.at(0)._str << endl;
    }

    cout << "a1._str = " << a1._str << endl;
    return;// move(v);
}

int main()
{

    // vector<A> v = func();
    func();
    // cout <<"size = " <<  v.size() << endl;
    // cout << v[0] << endl;
    // cout << v[1] << endl;
    // cout << v[2] << endl;
}
