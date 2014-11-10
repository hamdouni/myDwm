/* See LICENSE file for details. */
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

void
eprint(const char *errstr, ...) {
	va_list ap;

	va_start(ap, errstr);
	vfprintf(stderr, errstr, ap);
	va_end(ap);
	exit(EXIT_FAILURE);
}

int
main(int argc, char **argv) {
	int status, format;
	unsigned char *data = NULL;
	unsigned long n, extra;
	Display *dpy;
	Window root;
	Atom netwmcheck, netwmname, utf8_string, real;

	if(argc > 2)
		eprint("usage: wmname [name] [-v]\n");
	else if(argc == 2 && !strncmp(argv[1], "-v", 3))
		eprint("wmname-"VERSION", © 2008-2013 Anselm R Garbe\n", stdout);

	if(!(dpy = XOpenDisplay(0)))
		eprint("wmname: cannot open display\n");
	root = DefaultRootWindow(dpy);
	netwmcheck = XInternAtom(dpy, "_NET_SUPPORTING_WM_CHECK", False);
	netwmname = XInternAtom(dpy, "_NET_WM_NAME", False);
	utf8_string = XInternAtom(dpy, "UTF8_STRING", False);
	if(argc == 1) {
		status = XGetWindowProperty(dpy, root, netwmname, 0L, 32L, False, utf8_string, &real, &format, &n, &extra, (unsigned char **) &data);
		if(status == Success && data != NULL)
			fprintf(stdout, "%s\n", data);
		XFree(data);
	}
	else {
		XChangeProperty(dpy, root, netwmcheck, XA_WINDOW, 32, PropModeReplace, (unsigned char *)&root, 1);
		XChangeProperty(dpy, root, netwmname, utf8_string, 8, PropModeReplace, (unsigned char *)argv[1], strlen(argv[1]));
	}
	XSync(dpy, False);
	XCloseDisplay(dpy);
	return 0;
}
