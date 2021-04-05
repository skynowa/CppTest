/**
 * \file
 * \brief
 *
 * \todo
 */


/* Written by Nick Welch <mack@incise.org>, 2005.
 *
 * http://incise.org/xlib-key-passing.html
 * https://stackoverflow.com/questions/36764217/ubuntu-hotkeys-with-x11-xlib-x-error-badaccess
 */


#include <stdio.h>
#include <iostream>
#include <X11/Xlib.h>
//-------------------------------------------------------------------------------------------------
void swallow_keystroke(Display * dpy, XEvent * ev)
{
    XAllowEvents(dpy, AsyncKeyboard, ev->xkey.time);
    /* burp */
}
//-------------------------------------------------------------------------------------------------
void passthru_keystroke(Display * dpy, XEvent * ev)
{
    /* pass it through to the app, as if we never intercepted it */
    XAllowEvents(dpy, ReplayKeyboard, ev->xkey.time);
    XFlush(dpy); /* don't forget! */
}
//-------------------------------------------------------------------------------------------------
int main(void)
{
    Display * dpy = XOpenDisplay(nullptr);
    KeyCode F1;
    XEvent ev;

    if(!dpy) return 1;

    F1 = XKeysymToKeycode(dpy, XStringToKeysym("F3"));

    /* grab our key combo -- we use AnyModifier because of caps lock/num lock
     * complexity.  just grab every F1 press.
     */
    int iRv = XGrabKey(dpy, F1, AnyModifier, DefaultRootWindow(dpy), 1, GrabModeSync,
            GrabModeSync);
	std::cout << "XGrabKey: " << iRv << std::endl;

    for (;;) {
		std::cout << "XNextEvent: start" << std::endl;

        XNextEvent(dpy, &ev);

        if (ev.type == KeyPress || ev.type == KeyRelease) {
            /* again the lock key issues -- we just fire if alt is being
             * pressed, regardless if other modifiers are being pressed or not.
             */
            if (ev.xkey.keycode == F1 && ev.xkey.state & Mod1Mask) {
                if(ev.type == KeyPress)
                    fprintf(stderr, "got Alt+F1\n");

                swallow_keystroke(dpy, &ev);
            } else {
                fprintf(stderr, "got (something else)+F1, passing through\n");
                passthru_keystroke(dpy, &ev);
            }
        }

		std::cout << "XNextEvent: stop\n" << std::endl;
    }
}
//-------------------------------------------------------------------------------------------------
/* a simpler pseudo-code version showing only the logic:
 *
 * handle_key_event()
 * {
 *     if key event is alt+f1 keypress:
 *         print "got alt+f1!"
 *         swallow key event
 *
 *     elif key event is alt+f1 keyrelease:
 *         swallow key event
 *
 *     else:
 *         pass through key event
 *         xflush
 * }
 */
//-------------------------------------------------------------------------------------------------
