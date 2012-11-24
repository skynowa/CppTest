/*
Factory method creates some object (in this case a string) in a derived class, 
for use in a base class.
*/


#include <iostream>
#include <string>
//---------------------------------------------------------------------------
class IGreeter {
    public:
        virtual ~IGreeter() { }
        virtual std::string get_message()=0;
        void greet() {
            std::cout << get_message() << std::endl;
        }
};
//---------------------------------------------------------------------------
class CHelloWorld : 
    public IGreeter
{
    public:
        std::string get_message(){
            return "Hello world!";
        }
};
//---------------------------------------------------------------------------
void 
hello_world(IGreeter & greeter) {
	greeter.greet();
}
//---------------------------------------------------------------------------
int main()
{
	CHelloWorld greeter;
	hello_world(greeter);
    
	return 0;
}
//---------------------------------------------------------------------------


#if OUTPUT

    Hello world!
    
#endif
