 /*
 * \file  SignalsToException.cpp
 * \brief http://www.ibm.com/developerworks/library/l-cppexcep/
 *
 * \review
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
#include <execinfo.h>
//-------------------------------------------------------------------------------------------------
class StackTrace
{
public:
    virtual ~StackTrace()
    {
    }

    StackTrace()
    {
        void*  array[25];
        int    size    = ::backtrace(array, 25);
        char** symbols = ::backtrace_symbols(array, size);

        // std::cout << "\n::::: "  << __FUNCTION__ << "::::: " << std::endl;

        for (int i = 0; i < size; ++ i) {
            // std::cout << symbols[i] << std::endl;
        }

        // std::cout << ":::::::::::::::::::::::::\n" << std::endl;

        std::free(symbols);
    }
};
//-------------------------------------------------------------------------------------------------
template<class T>
class SignalTranslator
{
public:
    SignalTranslator()
    {
        static SingleToTranslator translator;
    }

private:
    class SingleToTranslator
    {
    public:
        SingleToTranslator()
        {
            ::signal(T::signalNumber(), signalHandler);
        }

        static
        void signalHandler(int)
        {
            throw std::runtime_error("Hello, world!");
            // throw T();
        }
    };
};
//-------------------------------------------------------------------------------------------------
// An example for SIGSEGV
class SegmentationFault :
    public std::exception,
    public StackTrace
{
public:
    static
    int signalNumber()
    {
        return SIGSEGV;
    }

    std::string whatEx() const
    {
        return "Error - Line: " + std::to_string(__LINE__);
    }
};
//-------------------------------------------------------------------------------------------------
// An example for SIGFPE
class FloatingPoint :
    public std::exception,
    public StackTrace
{
public:
    static
    int signalNumber()
    {
        return SIGFPE;
    }

    std::string whatEx() const
    {
        return "Error - Line: " + std::to_string(__LINE__);
    }
};
//-------------------------------------------------------------------------------------------------
class ExceptionHandler
{
public:
     ExceptionHandler()
     {
        static SingleToHandler handler;
     }

private:
    class SingleToHandler
    {
    public:
        SingleToHandler()
        {
            std::set_terminate(handler);
        }

        static
        void handler()
        {
            // Exception from construction / destruction of global variables
            try {
                // re-throw
                throw;
            }
            catch (const SegmentationFault &ex) {
                std::cout << "::: SegmentationFault exception: " << ex.whatEx() << "::: " << std::endl;
            }
            catch (const FloatingPoint &ex) {
                std::cout << "::: FloatingPoint exception: " << ex.whatEx() << "::: " << std::endl;
            }
            catch (const std::exception &ex) {
                std::cout << "::: std::exception: " << ex.what() << "::: " << std::endl;
            }
            catch (...) {
                std::cout << "::: Unknown Exception ::: " << std::endl;
            }

            // if this is a thread performing some core activity
            //-- std::abort();

            // else if this is a thread used to service requests
            // pthread_exit();
        }
    };
};
//-------------------------------------------------------------------------------------------------
class A
{
public:
    A()
    {
        int i = 0;
        int j = 1 / i;
        (void)j;

        // *(int *)0 = 0;
    }
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // SignalTranslator<SegmentationFault>  segmentationFaultTranslator;
    // SignalTranslator<FloatingPoint>      floatingPointTranslator;

    // Before defining any global variable, we define a dummy instance
    // of ExceptionHandler object to make sure that
    // ExceptionHandler::SingleToHandler::SingleToHandler() is invoked
    ExceptionHandler exceptionHandler;

    A a;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

SegmentationFault: Error - Line: 80
Aborted

#endif
