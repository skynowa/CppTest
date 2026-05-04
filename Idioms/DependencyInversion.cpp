/**
 * \file  DependencyInversion.cpp
 * \brief High level code depends on an abstraction, not on a concrete device
 *
 * Demonstrates controlling a device through a small abstract interface.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class ISwitchable
{
public:
	virtual ~ISwitchable() = default;

	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
};
//--------------------------------------------------------------------------------------------------
class Lamp :
	public ISwitchable
{
public:
	void turnOn() override
	{
		std::cout << "Lamp: on" << std::endl;
	}

	void turnOff() override
	{
		std::cout << "Lamp: off" << std::endl;
	}
};
//--------------------------------------------------------------------------------------------------
class PowerSwitch
{
public:
	explicit PowerSwitch(ISwitchable &a_device) :
		_device{a_device}
	{
	}

	void press()
	{
		if (_enabled) {
			_device.turnOff();
		} else {
			_device.turnOn();
		}

		_enabled = !_enabled;
	}

private:
	ISwitchable &_device;
	bool         _enabled {};
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	Lamp lamp;
	PowerSwitch powerSwitch(lamp);

	powerSwitch.press();
	powerSwitch.press();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Lamp: on
Lamp: off

#endif
