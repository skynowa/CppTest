/**
 * observer.h
 * Implemented by Blueprint Technologies, Inc.
 *
 * \todo
 */


#include <iostream>
#include <vector>
using namespace std;

/**
 * Defines an updating interface for objects that should be
 * notified of changes in a subject.
 */

class Ibserver
{

public:
	virtual void update() = 0;

};

/**
 * Maintains a reference to a ConcreteSubject object. Stores
 * state that should stay consistent with the subject's.
 * Implements the Ibserver updating interface to keep its
 * state consistent with the subject's.
 */

class ConcreteObserver: public Ibserver
{

public:
	virtual void update()
	{
		cout << "ConcreteObserver::update()" << endl;
	};
};

/**
 * Knows its observers. Any number of Ibserver objects may
 * observe a subject. Provides an interface for attaching and
 * detaching Ibserver objects.
 */

class Subject
{

private:
	vector< Ibserver* > observers;

public:
	void attach( Ibserver* observer )
	{
		vector< Ibserver* >::iterator i;
		int contained = 0;
		for( i = observers.begin(); i != observers.end(); ++i )
		{
			if( *i == observer )
			{
				contained = 1;
			}
		}
		if( !contained )
		{
			observers.push_back( observer );
		}
	};

	void detach( Ibserver* observer )
	{
		vector< Ibserver* >::iterator i;
		for( i = observers.begin(); i != observers.end(); ++i )
		{
			if( *i == observer )
			{
				observers.erase(i);
				return;
			}
		}
	};

	void notify()
	{
		vector< Ibserver* >::iterator i;
		for( i = observers.begin(); i != observers.end(); ++i )
		{
			(*i) -> update();
		}
	};

};

/**
 * Stores state of interest to ConcreteObserver objects. Sends a
 * notification to its observers when its state changes.
 */

class ConcreteSubject: public Subject
{
};


int main()
{
	return 0;
}
