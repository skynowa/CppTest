/*
Intent:
    - Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.
    - The C++ and Java standard library abstraction that makes it possible to decouple collection classes and algorithms.
    - Promote to �full object status� the traversal of a collection.
    - Polymorphic traversal

Problem:
    Need to �abstract� the traversal of wildly different data structures so that algorithms can be defined that are capable of interfacing with each transparently.
*/

/*
Design an �iterator� class for the �container� class
Add a createIterator() member to the container class
Clients ask the container object to create an iterator object
Clients use the first(), isDone(), next(), and currentItem() protocol
*/


#include <iostream>

//---------------------------------------------------------------------------
class StackIter;
class Stack {
  public:
        friend class StackIter;

        Stack() {
            sp =  - 1;
        }

        void push(int in) {
            items[++sp] = in;
        }

        int pop() {
            return items[sp--];
        }

        bool isEmpty() {
            return (sp ==  - 1);
        }

    private:
        int items[10];
        int sp;
};
//---------------------------------------------------------------------------
class StackIter {
    public:
        StackIter(const Stack &s): stk(s) {
            index = 0;
        }

        void operator++(){
            index++;
        }

        bool operator()() {
            return index != stk.sp + 1;
        }

        int operator *() {
            return stk.items[index];
        }

    private:
        const Stack &stk;
        int          index;
};
//---------------------------------------------------------------------------
bool
operator == (const Stack &l, const Stack &r) {
    StackIter itl(l), itr(r);

    for (; itl(); ++itl, ++itr) {
        if (*itl !=  *itr) {
            break;
        }
    }

    return !itl() && !itr();
}
//---------------------------------------------------------------------------
int main()
{
    Stack s1;

    for (int i = 1; i < 5; i++) {
        s1.push(i);
    }

    Stack s2(s1), s3(s1), s4(s1), s5(s1);
    s3.pop();
    s5.pop();
    s4.push(2);
    s5.push(9);

    std::cout << "1 == 2 is " << (s1 == s2) << std::endl;
    std::cout << "1 == 3 is " << (s1 == s3) << std::endl;
    std::cout << "1 == 4 is " << (s1 == s4) << std::endl;
    std::cout << "1 == 5 is " << (s1 == s5) << std::endl;
}
//---------------------------------------------------------------------------

/*
    Output:
        1 == 2 is 1
        1 == 3 is 0
        1 == 4 is 0
        1 == 5 is 0
*/
