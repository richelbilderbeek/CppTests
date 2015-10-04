#!/bin/sh
./cva-input -s "mouselocation" 
./cva-input -s "mousexy 100 100" 
./cva-input -s "mouseclick"
./cva-input -s "mouselocation"

exit


Libcvautomation version: 2.1
cva-input -s <command_string>

The cva-input program demonstrates the XTest section of libcvautomation.
The return code is 1 if there are no commands given, or if all commands fail.
It is 0 otherwise.

Usage: 

	-h, --help:		Display this usage message.
	-u, --usage:		Display this usage message.
	-d, --display:		Specify the X display to use.
	-m, --search-method:	Specify a method to search by. See `cva-match --help'
				for more information on this.
	-t, --tolerance:	Specify how strict the match is.
	-b, --button:		Specify the mouse button to press (default 1).
	-c, --center:		Instead of matching the top-left corner of an image,
				match the center of the image.
	-o, --sane-tolerance:	Set the tolerance using a scale of 1-100,
	-i, --timeout:		Specify the timeout to use when using the 'waitfor' function
	-s, --string:		Command string - see below.
				Please make sure to use the '-t' or '-o' options when using this.

This program works kind of like a mini-language. All options
are parsed left-to-right, and executed right there. Thus, specifying "--display"
at different places in the options will cause this program to use the most recent
given display.
Available commands:
	mouseclick:	Click the mouse in-place.
	imouseclick:	Click the mouse at an image's top-left corner.
	icmouseclick:	Click the mouse at an image's center.
	mousexy:	Move the mouse to the given coordinate.
	mouserxy:	Move the mouse by the given x and y values (relative motion).
	mouseimage:	Move the mouse to an image's top-left corner.
	cmouseimage:	Move the mouse to an image's center.
	mousedown:	Push and leave down a mouse button.
	mouseup:	Release a mouse button.
	mousejiggle:	Jiggle the mouse (helps to activate some widgets).
	mousescrollu:	Scroll the mouse wheel up.
	mousescrolld:	Scroll the mouse wheel down.
	mouselocation:	Return the location of the mouse.
	keyclick:	Click a keyboard button.
	keydown:	Push and leave down a keyboard button.
	keyup:	Release a keyboard button.
	keystring:	Input a string of keys to X11.
	waitfor:	Wait for an image to be displayed.

If you have any questions, comments, concerns, email <bspeice@uncc.edu>.

