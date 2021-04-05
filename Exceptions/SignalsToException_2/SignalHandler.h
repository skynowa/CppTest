/**
 * \file  SignalHandler.h
 * \brief
 *
 * \todo
 */


#pragma once

#include <stdexcept>

using std::runtime_error;

//-------------------------------------------------------------------------------------------------
class SignalException :
  public runtime_error
{
public:
   SignalException(const std::string& _message)
      : std::runtime_error(_message)
   {}
};
//-------------------------------------------------------------------------------------------------
class SignalHandler
{
protected:
    static bool _isGotExitSignal;

public:
    SignalHandler();
    ~SignalHandler();

    static bool gotExitSignal();
    static void setExitSignal(bool bExitSignal);

    void        setupSignalHandlers();
    static void exitSignalHandler(int ignored);
};
//-------------------------------------------------------------------------------------------------

#include "SignalHandler.inl"
