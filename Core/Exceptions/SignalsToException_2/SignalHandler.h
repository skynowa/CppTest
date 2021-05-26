/**
 * \file  SignalHandler.h
 * \brief
 */


#pragma once

#include <stdexcept>
// #include <signal.h>
// #include <errno.h>
//-------------------------------------------------------------------------------------------------
class SignalException :
    public std::runtime_error
{
public:
    SignalException(const std::string& _message) :
        std::runtime_error(_message)
    {
    }
};
//-------------------------------------------------------------------------------------------------
class SignalHandler
{
protected:
    static bool _isGotExitSignal;

public:
    SignalHandler() = default;
    ~SignalHandler() = default;

    static bool gotExitSignal();
    static void setExitSignal(bool bExitSignal);

    void        setupSignalHandlers();
    static void exitSignalHandler(int ignored);
};
//-------------------------------------------------------------------------------------------------

#include "SignalHandler.inl"
