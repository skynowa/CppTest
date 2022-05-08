/**
 * \file  xgrabkey.cpp
 * \brief
 *
 * Compile: gcc xgrabkey.c `pkg-config --cflags --libs x11`
 *
 * https://gist.github.com/jouyouyun/669726de58df8d333666
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
#include <X11/Xlib.h>
#include <xcb/xcb.h>
//-------------------------------------------------------------------------------------------------
int isError = False;
//-------------------------------------------------------------------------------------------------
void
errorText(
	Display     *a_display,
	XErrorEvent *a_event
)
{
	char errorText[255 + 1] {};
	::XGetErrorText(a_display, a_event->error_code, errorText, sizeof(errorText) - 1);

	std::cout << "QxtX11ErrorHandler:\n"
		<< "  Display: " << DisplayString(a_display) << "\n"
		<< "  Error:   " << a_event->error_code << " - " << errorText << "\n"
		<< "  Event: "   << a_event->type << std::endl;
}
//-------------------------------------------------------------------------------------------------
int
qxtX11ErrorHandler(
	Display     *a_display,
	XErrorEvent *a_event
)
{
    std::cout << "::::: " << __FUNCTION__ << " :::::" << std::endl;

	if (a_event->error_code == Success) {
		isError = False;
		std::cout << "Success" << std::endl;
		return 0;
	}

	isError = True;
	errorText(a_display, a_event);

	switch (a_event->error_code) {
	case BadAccess:
	case BadValue:
	case BadWindow:
	// case BadMatch:
		if (a_event->request_code == 33 /* X_GrabKey */ ||
			a_event->request_code == 34 /* X_UngrabKey */)
		{
			if (a_event->error_code == BadAccess) {
				printf("ERROR: A client attempts to grab/ungrab a key/button combination already\n"
					"        grabbed by another client. Ignoring.\n");
				return 0;
			}

			///
		}
	}

    exit(1);  // exit the application for all unhandled errors.

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    using x11_error_handler_t = std::add_pointer<int(Display *display, XErrorEvent *event)>::type;
    x11_error_handler_t _errorHandlerLast {};

	Display *dpy = XOpenDisplay(0);
	if (dpy == NULL) {
		printf("Open Display Failed\n");
		return -1;
	}

	auto errorHandlerLast = ::XSetErrorHandler(qxtX11ErrorHandler);
	if (errorHandlerLast == NULL) {
		printf("XSetErrorHandler Failed\n");
		return -1;
	}

	Window root = DefaultRootWindow(dpy);
	std::cout << "DefaultRootWindow" << std::endl;

	KeyCode F;
	F = XKeysymToKeycode(dpy, XStringToKeysym("F3"));

	unsigned int mod {};
	mod = mod | ControlMask | ShiftMask;

    int iRv = XGrabKey(dpy, F /* AnyKey */, AnyModifier /* mod */, root, True, GrabModeAsync, GrabModeAsync);
	std::cout << "XGrabKey: " << iRv << std::endl;

	XEvent event;
	for ( ;; ) {
		std::cout << "XNextEvent - start" << std::endl;

		XNextEvent(dpy, &event);

		if (event.type == KeyPress) {
			std::cout << "KeyPress" << std::endl;
		}

		std::cout << "XNextEvent - stop\n" << std::endl;
	}

	XAllowEvents(dpy, AsyncKeyboard, CurrentTime);
	std::cout << "XAllowEvents" << std::endl;

	XUngrabKey(dpy, AnyKey, AnyModifier, root);
	std::cout << "XUngrabKey" << std::endl;

	XSync(dpy, False);
	std::cout << "XSync" << std::endl;

	XCloseDisplay(dpy);
	std::cout << "XCloseDisplay" << std::endl;

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------
