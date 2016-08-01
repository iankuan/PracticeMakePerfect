#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef int screen;

int main( int argc, char* argv[])
{
	/**
	 * Here are the four major components for Display
	 *
	 * 1. Display 2. Screen 3, Window 4. Event
	 */

	Display *dpy;
	screen scrn;
	Window win;

	XEvent event;

	///open connection with the X server
	dpy = XOpenDisplay( NULL);///< NULL arg will choose the defult DISPLAY(=:0)


	if( dpy == NULL)
	{
		printf("Display not open\n");
		exit(1);
	}

	scrn = DefaultScreen( dpy);///<choose the default screen num on Host server

	/**
	 * Create window
	 *
	 * Window XCreateSimpleWindow(Display *display, Window parent, int x, int y, unsigned int width,
	 *															unsigned int height, unsigned int border_width, unsigned long border,
	 *																unsigned long background);
	 */
	win = XCreateSimpleWindow( dpy, RootWindow( dpy, scrn), 10, 10, 100, 100,
															1, BlackPixel( dpy, scrn), WhitePixel( dpy, scrn));
	
	Atom delWindow = XInternAtom( dpy, "WM_DELET_WINDOW", 0);///< atom = string name + several identifier

	XSetWMProtocols( dpy, win, &delWindow, 1);///< Status XSetWMProtocols(Display *display, Window w, Atom *protocols, int index);

	XSelectInput( dpy, win, ExposureMask | KeyPressMask);///< third arg is event_mask

	XMapWindow( dpy, win);///<make window visible on the screen

	while(1)
	{
		/**
		 * The `XNextEvent` function copies the first event from the event queue
		 *  into the specified XEvent structure and then removes it from the queue.
		 */
		XNextEvent( dpy, &event);

		/**
		 * TODO: Why need Expose event?
		 *
		 * if the window is covered and then uncovered again, its content might require that it be drawn again.
		 * The program is informed that the window or a part of it has to be drawn by the reception of an `Expose` event.
		 *
		 */
		if( event.type == Expose)
		{
			XFillRectangle( dpy, win, DefaultGC( dpy, scrn), 20, 20, 10, 10);///< only use after window created
		}

		if( event.type == KeyPress)
			break;

		if( event.type == ClientMessage)///< The X server generates ClientMessage events only when a client calls the function `XSendEvent()`.
			break;
	}

	XDestroyWindow( dpy, win);

	return 0;
}
