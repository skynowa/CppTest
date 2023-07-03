/**
 * \file  NullObject.cpp
 * \brief Object with no referenced value or with defined neutral (null) behavior
 *
 * Null object creates a special object to mean nothing/null/absent/default.
 * It means that the default behaviour can be implementer in the null object
 * instead of making an explicit check for null, or using NULL pointers.
 *
 * \see   https://en.wikipedia.org/wiki/Null_object_pattern
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class IRecipient
{
public:
	virtual ~IRecipient() = default;

	virtual std::string name() const = 0;
};
//--------------------------------------------------------------------------------------------------
class NullRecipient final :
    public IRecipient
{
public:
	std::string name() const override
    {
        return "[n/a]";
    }
};
//--------------------------------------------------------------------------------------------------
class World :
    public IRecipient
{
public:
	std::string name() const override
    {
        return "world";
    }
};
//--------------------------------------------------------------------------------------------------
void
helloWorld(
    const IRecipient &a_recipient = NullRecipient()
)
{
	std::cout << "Hello " << a_recipient.name() << "!" << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	::helloWorld( World() );
	::helloWorld();

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

"Hello world!"
"Hello [n/a]!"

#endif
