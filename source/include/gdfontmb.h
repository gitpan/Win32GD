#ifndef GDFONTMB_H
#define GDFONTMB_H 1

/* gdfontmb.h: brings in the middle of the provided fonts.
	Also link with gdfonth.c. */

#include "gd.h"

/* 7x13B font derived from a public domain font in the X
        distribution. Contains the 127 standard ascii characters. */

	#ifdef __cplusplus
        extern "C" gdFontPtr gdFontMediumBold;
    #else
    	extern gdFontPtr gdFontMediumBold;
	#endif

#endif
