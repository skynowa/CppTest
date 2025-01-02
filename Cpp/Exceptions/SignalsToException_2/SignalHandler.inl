/**
 * \file  SignalHandler.inl
 * \brief
 */


//-------------------------------------------------------------------------------------------------
bool SignalHandler::_isGotExitSignal {};
//-------------------------------------------------------------------------------------------------
/**
 * Returns the bool flag indicating whether we received an exit signal
 *
 * @return Flag indicating shutdown of program
 */
bool
SignalHandler::gotExitSignal()
{
    return _isGotExitSignal;
}
//-------------------------------------------------------------------------------------------------
/**
 * Sets the bool flag indicating whether we received an exit signal
 */
void
SignalHandler::setExitSignal(bool a_bExitSignal)
{
    _isGotExitSignal = a_bExitSignal;
}
//-------------------------------------------------------------------------------------------------
/**
 * Sets exit signal to true.
 *
 * @param[in] _ignored Not used but required by function prototype to match required handler
 */
void
SignalHandler::exitSignalHandler(int /* a_ignored */)
{
    _isGotExitSignal = true;

    std::cout << "_isGotExitSignal: " << _isGotExitSignal << std::endl;
}
//-------------------------------------------------------------------------------------------------
/**
 * Set up the signal handlers for "ыCTRL-C"
 */
void
SignalHandler::setupSignalHandlers()
{
	sighandler_t signalNum = signal(SIGFPE, SignalHandler::exitSignalHandler);
    if (signalNum == SIG_ERR) {
        throw SignalException("!!!!! Error setting up signal handlers !!!!!");
    }
}
//-------------------------------------------------------------------------------------------------
