GD.pm A perl5 interface to Thomas Boutell's gd library.

Modified ever so slightly for use in Win32 Perl by
    Dave Roth <rothd@infowire.com>

ABSTRACT:

This is a autoloadable interface module for libgd, a popular library
for creating and manipulating GIF files.  With this library you can
create GIF images on the fly or modify existing files.  Features
include:

a.  lines, polygons, rectangles and arcs, both filled and unfilled
b.  flood fills
c.  the use of arbitrary images as brushes and as tiled fill patterns
d.  line styling (dashed lines and the like)
e.  horizontal and vertical text rendering
f.  support for transparency and interlacing

For full information on usage, see the accompanying man and html
documentation.

COPYRIGHT INFO

The GD.pm interface is copyright 1995, Lincoln D. Stein.  You are free
to use it for any purpose, commercial or noncommercial, provided that
if you redistribute the source code this statement of copyright
remains attached. The Gd library is covered separately, under a 1994
copyright by Quest Protein Database Center, Cold Spring Harbor Labs.
For usage information see the Gd documentation at the URL given below.


    T O   I N S T A L L   T H I S   B E A S T :
    =========================================

1) You will need to dump the GD.PM file into the \PERL\LIB\ directory.

2) You need to copy either GD105.PLL or GD106.PLL (depending on your
   version of Win32 Perl's build number. Run:  perl -v   to check which build
   you have) into \PERL\LIB\AUTO\GD\GD.PLL

   **** Notice that we are changing the name to GD.PLL!!!!

   ---------------------------------------------------------

That is it!

After all that is finished, try it out and run:
    perl test.pl

A GIF file should dump to your screen!

You can try:
    perl test.pl "c:\temp\test.gif"

The same GIF file will be saved as c:\temp\test.gif


    ===========================================
    ====    CHANGES FROM STEIN'S WORK    ======
    ====                                 ======
    If you are porting from Unix under Stein's
    version of this same module please note
    that there are just a couple of changes:

        1) You really should set $| to 1 so
           that printed data is flushed out.
           This is because the GD library
           was altered a bit to contend with
           Win32 and MSVC 2.2.

        2) The gif() and gd() methods take
           parameters and do NOT return the
           image data!!!!!
           Stein's methods return image data
           that you can redirect to a file but
           since Win32 Perl can not yet use
           the fork() things are a bit different.
           Proper useage:
                $gif->gif;
           will print the image data to STDOUT.
                $gif->gif("c:\\temp\\test.gif");
           will dump the image data to the
           specified file.

        3) Also note that the gif() and gd()
           methods also return a value of 1
           if successfull and 0 if failure.
           Success is the specified file to
           save to was indeed opened for writing.

    ===============================================

This work is a hack on excellent work done by:

	Lincoln Stein
	lstein@genome.wi.mit.edu
	http://www-genome.wi.mit.edu/~lstein

