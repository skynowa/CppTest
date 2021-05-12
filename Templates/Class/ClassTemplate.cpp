/**
 * \file  ClassTemplate.cpp
 * \brief
 */


#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;
//-------------------------------------------------------------------------------------------------
template <class T>
class Stack
{
public:
   void push(T const&);
   void pop();
   T    top() const;

   bool empty() const
   {
      return elems.empty();
   }

private:
   vector<T> elems {};
};
//-------------------------------------------------------------------------------------------------
template <class T>
void
Stack<T>::push(T const& elem)
{
   // append copy of passed element
   elems.push_back(elem);
}
//-------------------------------------------------------------------------------------------------
template <class T>
void
Stack<T>::pop()
{
   if (elems.empty()) {
      throw out_of_range("Stack<>::pop(): empty stack");
   }

   // remove last element
   elems.pop_back();
}
//-------------------------------------------------------------------------------------------------
template <class T>
T
Stack<T>::top() const
{
   if (elems.empty()) {
      throw out_of_range("Stack<>::top(): empty stack");
   }

   // return copy of last element
   return elems.back();
}
//-------------------------------------------------------------------------------------------------
int main()
{
   try {
      Stack<int>    intStack;
      Stack<string> stringStack;

      intStack.push(7);
      cout << intStack.top() <<endl;

      stringStack.push("hello");
      cout << stringStack.top() << std::endl;

      stringStack.pop();
      stringStack.pop();

   }
   catch (exception const& ex) {
      cerr << "Exception: " << ex.what() << endl;
      return - 1;
   }
   catch (...) {
      cerr << "Exception: unknown" << endl;
      return - 1;
   }

   return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

7
hello
Exception: Stack<>::pop(): empty stack

#endif
