/*
 * This file was generated automatically by xsubpp version 1.9 from the 
 * contents of gd.xs. Don't edit this file, edit gd.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "gd.h"
#include "stdio.h"

/* Copyright 1995, Lincoln D. Stein.  See accompanying README file for
	usage restrictions */

static int 
not_here(CPerl *pPerl, char *s)
{
    croak("%s not implemented on this architecture", s);
    return -1;
}

static double 
constant(CPerl *pPerl, char *name, int arg)
{
    errno = 0;
    switch (*name) {
    	case 'A':
			break;
	    case 'B':
			break;
	    case 'C':
			break;
	    case 'D':
			break;
	    case 'E':
			break;
	    case 'F':
			break;
	    case 'G':
			break;
	    case 'H':
			break;
    	case 'I':
			break;
	    case 'J':
			break;
    	case 'K':
			break;
	    case 'L':
			break;
    	case 'M':
			break;
	    case 'N':
			break;
    	case 'O':
			break;
	    case 'P':
			break;
    	case 'Q':
			break;
	    case 'R':
			break;
	    case 'S':
			break;
    	case 'T':
			break;
	    case 'U':
			break;
    	case 'V':
			break;
	    case 'W':
			break;
    	case 'X':
			break;
	    case 'Y':
			break;
    	case 'Z':
			break;
	    case 'a':
			break;
    	case 'b':
			break;
	    case 'c':
			break;
    	case 'd':
			break;
	    case 'e':
			break;
    	case 'f':
			break;
	    case 'g':
			if (strEQ(name, "gdBrushed"))
			#ifdef gdBrushed
	    		return gdBrushed;
			#else
	    		goto not_there;
			#endif
			if (strEQ(name, "gdDashSize"))
			#ifdef gdDashSize
	    		return gdDashSize;
			#else
    			goto not_there;
			#endif
			if (strEQ(name, "gdMaxColors"))
			#ifdef gdMaxColors
	    		return gdMaxColors;
			#else
    			goto not_there;
			#endif
			if (strEQ(name, "gdStyled"))
			#ifdef gdStyled
	    		return gdStyled;
			#else
			    goto not_there;
			#endif
			if (strEQ(name, "gdStyledBrushed"))
			#ifdef gdStyledBrushed
	    		return gdStyledBrushed;
			#else
	    		goto not_there;
			#endif
			if (strEQ(name, "gdTiled"))
			#ifdef gdTiled
	    		return gdTiled;
			#else
			    goto not_there;
			#endif
			if (strEQ(name, "gdTransparent"))
			#ifdef gdTransparent
	    		return gdTransparent;
			#else
			    goto not_there;
			#endif
			break;
       	case 'h':
			break;
	    case 'i':
			break;
	    case 'j':
			break;
    	case 'k':
			break;
	    case 'l':
			break;
    	case 'm':
			break;
	    case 'n':
			break;
    	case 'o':
			break;
	    case 'p':
			break;
    	case 'q':
			break;
	    case 'r':
			break;
    	case 's':
			break;
	    case 't':
			break;
    	case 'u':
			break;
	    case 'v':
			break;
    	case 'w':
			break;
	    case 'x':
			break;
    	case 'y':
			break;
	    case 'z':
			break;
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}

typedef gdImagePtr	GD__Image;
typedef gdFontPtr	GD__Font;
extern 	gdFontPtr	gdFontLarge;
extern	gdFontPtr	gdFontSmall;
extern	gdFontPtr	gdFontMediumBold;
extern	gdFontPtr	gdFontTiny;

/* Utility functions */
FILE* fh2file(CPerl *pPerl, char *fhandle, char *style)
{
  dSP ;
  int count ;
  int fd;
  
  ENTER ;
  SAVETMPS;
  PUSHMARK(sp) ;
  XPUSHs(sv_2mortal(newSVpv(fhandle,0)));
  PUTBACK ;
  count = perl_call_pv("GD::fileno", G_SCALAR);
  SPAGAIN ;
  if (count != 1)
    croak("Didn't get a single result from fileno() call.\n");
  fd = POPi;
  PUTBACK ;
  FREETMPS ;
  LEAVE ;

  return fdopen(fd,style);
}

XS(XS_GD_constant)
{
    dXSARGS;
    if (items != 2) {
	croak("Usage: GD::constant(name,arg)");
    }
    {
	char *	name = (char *)SvPV(ST(0),na);
	int	arg = (int)SvIV(ST(1));
	double	RETVAL;

	RETVAL = constant(pPerl, name, arg);
	ST(0) = sv_newmortal();
	sv_setnv(ST(0), (double)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Debug)
{
		/*	This assumes, of course, that there will be at least on parameter passed
			on the stack, the reference to the object ($self)
		*/
    dXSARGS;
    if (items > 2) {
	croak("Usage: GD::Debug([1|0])");
    }
    {
		
	if (items > 1){
		gdSetDebug(((int)SvIV(ST(1)))? 1:0);
	}
	ST(0) = sv_newmortal();
	sv_setnv(ST(0), (double)gdGetDebug());
    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdnew)
{
    dXSARGS;
    if (items < 0 || items > 3) {
	croak("Usage: GD::Image::new(packname=\"GD::Image\", x=64, y=64)");
    }
    {
	char *	packname;
	int	x;
	int	y;
	GD__Image	RETVAL;

	if (items < 1)
	    packname = "GD::Image";
	else {
	    packname = (char *)SvPV(ST(0),na);
	}

	if (items < 2)
	    x = 64;
	else {
	    x = (int)SvIV(ST(1));
	}

	if (items < 3)
	    y = 64;
	else {
	    y = (int)SvIV(ST(2));
	}
	{

		gdImagePtr theImage;

		theImage = gdImageCreate(x,y);

		RETVAL = theImage;

	}

	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "GD::Image", (void*)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdnewFromGif)
{
    dXSARGS;
    if (items < 1 || items > 2) {
	croak("Usage: GD::Image::newFromGif(packname=\"GD::Image\", filehandle)");
    }
    {
	char *	packname;
	char *	filehandle = (char *)SvPV(ST(1),na);
	GD__Image	RETVAL;

	if (items < 1)
	    packname = "GD::Image";
	else {
	    packname = (char *)SvPV(ST(0),na);
	}
	{

		gdImagePtr theImage;

		FILE*	theFile;

		theFile = fh2file(pPerl, filehandle,"r");

		if (theFile == NULL) {

			RETVAL = NULL;

		} else {

			theImage = gdImageCreateFromGif(theFile);

			RETVAL = theImage;

		}

	}

	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "GD::Image", (void*)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdnewFromXbm)
{
    dXSARGS;
    if (items < 1 || items > 2) {
	croak("Usage: GD::Image::newFromXbm(packname=\"GD::Image\", filehandle)");
    }
    {
	char *	packname;
	char *	filehandle = (char *)SvPV(ST(1),na);
	GD__Image	RETVAL;

	if (items < 1)
	    packname = "GD::Image";
	else {
	    packname = (char *)SvPV(ST(0),na);
	}
	{

		gdImagePtr theImage;

		FILE*	theFile;

		theFile = fh2file(pPerl, filehandle,"r");

		if (theFile == NULL) {

			RETVAL = NULL;

		} else {

			theImage = gdImageCreateFromXbm(theFile);

			RETVAL = theImage;

		}

	}

	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "GD::Image", (void*)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdnewFromGd)
{
    dXSARGS;
    if (items < 1 || items > 2) {
	croak("Usage: GD::Image::newFromGd(packname=\"GD::Image\", filehandle)");
    }
    {
	char *	packname;
	char *	filehandle = (char *)SvPV(ST(1),na);
	GD__Image	RETVAL;

	if (items < 1)
	    packname = "GD::Image";
	else {
	    packname = (char *)SvPV(ST(0),na);
	}
	{

		gdImagePtr theImage;

		FILE*	theFile;

		theFile = fh2file(pPerl, filehandle,"r");

		if (theFile == NULL) {

			RETVAL = NULL;

		} else {

			theImage = gdImageCreateFromGd(theFile);

			RETVAL = theImage;

		}

	}

	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "GD::Image", (void*)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdDESTROY)
{
    dXSARGS;
    if (items != 1) {
	croak("Usage: GD::Image::DESTROY(image)");
    }
    {
	GD__Image	image;

	if (SvROK(ST(0))) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not a reference");
	{

		gdImageDestroy(image);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gd__Gif)
{
    dXSARGS;
    if (items != 2) {
		croak("Usage: GD::Image::__Gif(image,filedescriptor)");
    }

	GD__Image	image;
	char	szFile[1024];
	char	szComment[128];
  	gdImagePtr theImage;
  	FILE	*theFile;
	BOOL	bResult = TRUE;

	int	filedescriptor = (int)SvIV(ST(1));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}else{
	    croak("image is not of type GD::Image");
	}

	theFile = fdopen(filedescriptor, "wb");
	
	if (theFile){
		gdImageGif(image,theFile);
		if (fflush(theFile)){
			bResult = FALSE;
		}
		fclose(theFile);
	}else{
		bResult = FALSE;
	}
	XSRETURN(bResult);
}

XS(XS_GD__Image_gd__Gd)
{														  
    dXSARGS;
    if (items != 2) {
	croak("Usage: GD::Image::__Gd(image,filedescriptor)");
    }
    
	GD__Image	image;
	int	filedescriptor = (int)SvIV(ST(1));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}else{
	    croak("image is not of type GD::Image");
	}

	gdImagePtr theImage;
	FILE*	theFile;
	BOOL	bResult = TRUE;
		
	theFile = fdopen(filedescriptor,"wb");
	if (theFile != NULL) {
		gdImageGd(image,theFile);
		if (fflush(theFile)){
			bResult = FALSE;
		}
		fclose(theFile);
	}else{
		bResult = FALSE;
	}							 
	XSRETURN(bResult);
}

	
XS(XS_GD__Image_gdtransparent)
{
    dXSARGS;
    if (items < 1) {
	croak("Usage: GD::Image::transparent(image, ...)");
    }
    {
	GD__Image	image;
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		int color;

		if (items > 1) {

			color=(int)SvIV(ST(1));

			gdImageColorTransparent(image,color);

		}

		RETVAL = gdImageGetTransparent(image);

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdgetBounds)
{
    dXSARGS;
    if (items != 1) {
	croak("Usage: GD::Image::getBounds(image)");
    }
    SP -= items;
    {
	GD__Image	image;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		int sx,sy;

		sx = gdImageSX(image);

		sy = gdImageSY(image);

		EXTEND(sp,2);

		PUSHs(sv_2mortal(newSViv(sx)));

		PUSHs(sv_2mortal(newSViv(sy)));

	}

	PUTBACK;
	return;
    }
}

XS(XS_GD__Image_gdrgb)
{
    dXSARGS;
    if (items != 2) {
	croak("Usage: GD::Image::rgb(image,color)");
    }
    SP -= items;
    {
	GD__Image	image;
	int	color = (int)SvIV(ST(1));
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		int r,g,b;

		r = gdImageRed(image,color);

		g = gdImageGreen(image,color);

		b = gdImageBlue(image,color);

		EXTEND(sp,3);

		PUSHs(sv_2mortal(newSViv(r)));

		PUSHs(sv_2mortal(newSViv(g)));

		PUSHs(sv_2mortal(newSViv(b)));

	}

	PUTBACK;
	return;
    }
}

XS(XS_GD__Image_gdboundsSafe)
{
    dXSARGS;
    if (items != 3) {
	croak("Usage: GD::Image::boundsSafe(image,x,y)");
    }
    {
	GD__Image	image;
	int	x = (int)SvIV(ST(1));
	int	y = (int)SvIV(ST(2));
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		RETVAL=gdImageBoundsSafe(image,x,y);

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdgetPixel)
{
    dXSARGS;
    if (items != 3) {
	croak("Usage: GD::Image::getPixel(image,x,y)");
    }
    {
	GD__Image	image;
	int	x = (int)SvIV(ST(1));
	int	y = (int)SvIV(ST(2));
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		RETVAL=gdImageGetPixel(image,x,y);

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdsetPixel)
{
    dXSARGS;
    if (items != 4) {
	croak("Usage: GD::Image::setPixel(image,x,y,color)");
    }
    {
	GD__Image	image;
	int	x = (int)SvIV(ST(1));
	int	y = (int)SvIV(ST(2));
	int	color = (int)SvIV(ST(3));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		gdImageSetPixel(image,x,y,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdline)
{
    dXSARGS;
    if (items != 6) {
	croak("Usage: GD::Image::line(image,x1,y1,x2,y2,color)");
    }
    {
	GD__Image	image;
	int	x1 = (int)SvIV(ST(1));
	int	y1 = (int)SvIV(ST(2));
	int	x2 = (int)SvIV(ST(3));
	int	y2 = (int)SvIV(ST(4));
	int	color = (int)SvIV(ST(5));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		gdImageLine(image,x1,y1,x2,y2,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gddashedLine)
{
    dXSARGS;
    if (items != 6) {
	croak("Usage: GD::Image::dashedLine(image,x1,y1,x2,y2,color)");
    }
    {
	GD__Image	image;
	int	x1 = (int)SvIV(ST(1));
	int	y1 = (int)SvIV(ST(2));
	int	x2 = (int)SvIV(ST(3));
	int	y2 = (int)SvIV(ST(4));
	int	color = (int)SvIV(ST(5));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		gdImageDashedLine(image,x1,y1,x2,y2,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdpolygon)
{
    dXSARGS;
    if (items != 3) {
	croak("Usage: GD::Image::polygon(image,poly,color)");
    }
    {
	GD__Image	image;
	SV *	poly = ST(1);
	int	color = (int)SvIV(ST(2));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		dSP ;

		int length,count ;

		int x,y,i ;

		gdPointPtr polyptr;


		ENTER ;

		SAVETMPS ;

		PUSHMARK(sp) ;

		XPUSHs(poly) ;

		PUTBACK ;

		count = perl_call_method("length",G_SCALAR) ;

		SPAGAIN ;

		if (count != 1)

			croak("Didn't get a single result from GD::Poly::length() call.\n");

		length = POPi ;

		PUTBACK ;

		FREETMPS ;

		LEAVE ;


		polyptr = (gdPointPtr)safemalloc(sizeof(gdPoint)*length);

		if (polyptr == NULL)

			croak("safemalloc() returned NULL in GD::Image::poly().\n");


		for (i=0;i<length;i++) {

			ENTER ;

			SAVETMPS ;

			PUSHMARK(sp) ;

			XPUSHs(poly) ;

			XPUSHs(sv_2mortal(newSViv(i))) ;

			PUTBACK ;

			count = perl_call_method("getPt",G_ARRAY) ;

			SPAGAIN ;

			if (count != 2)

				croak("Didn't get a single result from GD::Poly::length() call.\n");

			y = POPi ;

			x = POPi ;

			PUTBACK ;

			FREETMPS ;

			LEAVE ;


			polyptr[i].x = x;

			polyptr[i].y = y;

		}


		gdImagePolygon(image,polyptr,length,color);

		safefree((char*) polyptr);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdfilledPolygon)
{
    dXSARGS;
    if (items != 3) {
	croak("Usage: GD::Image::filledPolygon(image,poly,color)");
    }
    {
	GD__Image	image;
	SV *	poly = ST(1);
	int	color = (int)SvIV(ST(2));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		dSP ;

		int length,count ;

		int x,y,i ;

		gdPointPtr polyptr;


		ENTER ;

		SAVETMPS ;

		PUSHMARK(sp) ;

		XPUSHs(poly) ;

		PUTBACK ;

		count = perl_call_method("length",G_SCALAR) ;

		SPAGAIN ;

		if (count != 1)

			croak("Didn't get a single result from GD::Poly::length() call.\n");

		length = POPi ;

		PUTBACK ;

		FREETMPS ;

		LEAVE ;


		polyptr = (gdPointPtr)safemalloc(sizeof(gdPoint)*length);

		if (polyptr == NULL)

			croak("safemalloc() returned NULL in GD::Image::poly().\n");


		for (i=0;i<length;i++) {

			ENTER ;

			SAVETMPS ;

			PUSHMARK(sp) ;

			XPUSHs(poly) ;

			XPUSHs(sv_2mortal(newSViv(i))) ;

			PUTBACK ;

			count = perl_call_method("getPt",G_ARRAY) ;

			SPAGAIN ;

			if (count != 2)

				croak("Didn't get a single result from GD::Poly::length() call.\n");

			y = POPi ;

			x = POPi ;

			PUTBACK ;

			FREETMPS ;

			LEAVE ;


			polyptr[i].x = x;

			polyptr[i].y = y;

		}


		gdImageFilledPolygon(image,polyptr,length,color);

		safefree((char*) polyptr);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdrectangle)
{
    dXSARGS;
    if (items != 6) {
	croak("Usage: GD::Image::rectangle(image,x1,y1,x2,y2,color)");
    }
    {
	GD__Image	image;
	int	x1 = (int)SvIV(ST(1));
	int	y1 = (int)SvIV(ST(2));
	int	x2 = (int)SvIV(ST(3));
	int	y2 = (int)SvIV(ST(4));
	int	color = (int)SvIV(ST(5));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		gdImageRectangle(image,x1,y1,x2,y2,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdfilledRectangle)
{
    dXSARGS;
    if (items != 6) {
	croak("Usage: GD::Image::filledRectangle(image,x1,y1,x2,y2,color)");
    }
    {
	GD__Image	image;
	int	x1 = (int)SvIV(ST(1));
	int	y1 = (int)SvIV(ST(2));
	int	x2 = (int)SvIV(ST(3));
	int	y2 = (int)SvIV(ST(4));
	int	color = (int)SvIV(ST(5));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		gdImageFilledRectangle(image,x1,y1,x2,y2,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdarc)
{
    dXSARGS;
    if (items != 8) {
	croak("Usage: GD::Image::arc(image,cx,cy,w,h,s,e,color)");
    }
    {
	GD__Image	image;
	int	cx = (int)SvIV(ST(1));
	int	cy = (int)SvIV(ST(2));
	int	w = (int)SvIV(ST(3));
	int	h = (int)SvIV(ST(4));
	int	s = (int)SvIV(ST(5));
	int	e = (int)SvIV(ST(6));
	int	color = (int)SvIV(ST(7));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		gdImageArc(image,cx,cy,w,h,s,e,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_fillToBorder)
{
    dXSARGS;
    if (items != 5) {
	croak("Usage: GD::Image::fillToBorder(image,x,y,border,color)");
    }
    {
	GD__Image	image;
	int	x = (int)SvIV(ST(1));
	int	y = (int)SvIV(ST(2));
	int	border = (int)SvIV(ST(3));
	int	color = (int)SvIV(ST(4));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		gdImageFillToBorder(image,x,y,border,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_fill)
{
    dXSARGS;
    if (items != 4) {
	croak("Usage: GD::Image::fill(image,x,y,color)");
    }
    {
	GD__Image	image;
	int	x = (int)SvIV(ST(1));
	int	y = (int)SvIV(ST(2));
	int	color = (int)SvIV(ST(3));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		gdImageFill(image,x,y,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_setBrush)
{
    dXSARGS;
    if (items != 2) {
	croak("Usage: GD::Image::setBrush(image,brush)");
    }
    {
	GD__Image	image;
	GD__Image	brush;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");

	if (sv_isa(ST(1), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(1)));
	    brush = (GD__Image) tmp;
	}
	else
	    croak("brush is not of type GD::Image");
	{

		gdImageSetBrush(image,brush);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_setTile)
{
    dXSARGS;
    if (items != 2) {
	croak("Usage: GD::Image::setTile(image,tile)");
    }
    {
	GD__Image	image;
	GD__Image	tile;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");

	if (sv_isa(ST(1), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(1)));
	    tile = (GD__Image) tmp;
	}
	else
	    croak("tile is not of type GD::Image");
	{

		gdImageSetTile(image,tile);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_setStyle)
{
    dXSARGS;
    if (items < 1) {
	croak("Usage: GD::Image::setStyle(image, ...)");
    }
    {
	GD__Image	image;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		int	*style;

		int	i;


		if (items < 2)

			return;

		style = (int*) safemalloc(sizeof(int)*(items-1));

		if (style == NULL)

			croak("malloc returned NULL at setStyle().\n");

		for(i=1;i<items;i++) {

			style[i-1]=(int)SvIV(ST(i));

		}

		gdImageSetStyle(image,style,items-1);

		safefree((char*) style);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_colorAllocate)
{
    dXSARGS;
    if (items != 4) {
	croak("Usage: GD::Image::colorAllocate(image,r,g,b)");
    }
    {
	GD__Image	image;
	int	r = (int)SvIV(ST(1));
	int	g = (int)SvIV(ST(2));
	int	b = (int)SvIV(ST(3));
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		RETVAL = gdImageColorAllocate(image,r,g,b);

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_colorClosest)
{
    dXSARGS;
    if (items != 4) {
	croak("Usage: GD::Image::colorClosest(image,r,g,b)");
    }
    {
	GD__Image	image;
	int	r = (int)SvIV(ST(1));
	int	g = (int)SvIV(ST(2));
	int	b = (int)SvIV(ST(3));
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		RETVAL = gdImageColorClosest(image,r,g,b);

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_colorExact)
{
    dXSARGS;
    if (items != 4) {
	croak("Usage: GD::Image::colorExact(image,r,g,b)");
    }
    {
	GD__Image	image;
	int	r = (int)SvIV(ST(1));
	int	g = (int)SvIV(ST(2));
	int	b = (int)SvIV(ST(3));
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		RETVAL = gdImageColorExact(image,r,g,b);

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_colorsTotal)
{
    dXSARGS;
    if (items != 1) {
	croak("Usage: GD::Image::colorsTotal(image)");
    }
    {
	GD__Image	image;
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		RETVAL = gdImageColorsTotal(image);

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_interlaced)
{
    dXSARGS;
    if (items < 1) {
	croak("Usage: GD::Image::interlaced(image, ...)");
    }
    {
	GD__Image	image;
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		if (items > 1) {

			if (SvOK(ST(1)))

				gdImageInterlace(image,1);

			else

				gdImageInterlace(image,0);

		}

		RETVAL = gdImageGetInterlaced(image);

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Image_colorDeallocate)
{
    dXSARGS;
    if (items != 2) {
	croak("Usage: GD::Image::colorDeallocate(image,color)");
    }
    {
	GD__Image	image;
	int	color = (int)SvIV(ST(1));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");
	{

		gdImageColorDeallocate(image,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_copy)
{
    dXSARGS;
    if (items != 8) {
	croak("Usage: GD::Image::copy(destination,source,dstX,dstY,srcX,srcY,w,h)");
    }
    {
	GD__Image	destination;
	GD__Image	source;
	int	dstX = (int)SvIV(ST(2));
	int	dstY = (int)SvIV(ST(3));
	int	srcX = (int)SvIV(ST(4));
	int	srcY = (int)SvIV(ST(5));
	int	w = (int)SvIV(ST(6));
	int	h = (int)SvIV(ST(7));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    destination = (GD__Image) tmp;
	}
	else
	    croak("destination is not of type GD::Image");

	if (sv_isa(ST(1), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(1)));
	    source = (GD__Image) tmp;
	}
	else
	    croak("source is not of type GD::Image");
	{

		gdImageCopy(destination,source,dstX,dstY,srcX,srcY,w,h);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_copyResized)
{
    dXSARGS;
    if (items != 10) {
	croak("Usage: GD::Image::copyResized(destination,source,dstX,dstY,srcX,srcY,destW,destH,srcW,srcH)");
    }
    {
	GD__Image	destination;
	GD__Image	source;
	int	dstX = (int)SvIV(ST(2));
	int	dstY = (int)SvIV(ST(3));
	int	srcX = (int)SvIV(ST(4));
	int	srcY = (int)SvIV(ST(5));
	int	destW = (int)SvIV(ST(6));
	int	destH = (int)SvIV(ST(7));
	int	srcW = (int)SvIV(ST(8));
	int	srcH = (int)SvIV(ST(9));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    destination = (GD__Image) tmp;
	}
	else
	    croak("destination is not of type GD::Image");

	if (sv_isa(ST(1), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(1)));
	    source = (GD__Image) tmp;
	}
	else
	    croak("source is not of type GD::Image");
	{

		gdImageCopyResized(destination,source,dstX,dstY,srcX,srcY,destW,destH,srcW,srcH);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdchar)
{
    dXSARGS;
    if (items != 6) {
	croak("Usage: GD::Image::char(image,font,x,y,c,color)");
    }
    {
	GD__Image	image;
	GD__Font	font;
	int	x = (int)SvIV(ST(2));
	int	y = (int)SvIV(ST(3));
	char *	c = (char *)SvPV(ST(4),na);
	int	color = (int)SvIV(ST(5));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");

	if (sv_isa(ST(1), "GD::Font")) {
	    IV tmp = SvIV((SV*)SvRV(ST(1)));
	    font = (GD__Font) tmp;
	}
	else
	    croak("font is not of type GD::Font");
	{

		gdImageChar(image,font,x,y,*c,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdcharUp)
{
    dXSARGS;
    if (items != 6) {
	croak("Usage: GD::Image::charUp(image,font,x,y,c,color)");
    }
    {
	GD__Image	image;
	GD__Font	font;
	int	x = (int)SvIV(ST(2));
	int	y = (int)SvIV(ST(3));
	char *	c = (char *)SvPV(ST(4),na);
	int	color = (int)SvIV(ST(5));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");

	if (sv_isa(ST(1), "GD::Font")) {
	    IV tmp = SvIV((SV*)SvRV(ST(1)));
	    font = (GD__Font) tmp;
	}
	else
	    croak("font is not of type GD::Font");
	{

		gdImageCharUp(image,font,x,y,*c,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdstring)
{
    dXSARGS;
    if (items != 6) {
	croak("Usage: GD::Image::string(image,font,x,y,s,color)");
    }
    {
	GD__Image	image;
	GD__Font	font;
	int	x = (int)SvIV(ST(2));
	int	y = (int)SvIV(ST(3));
	char *	s = (char *)SvPV(ST(4),na);
	int	color = (int)SvIV(ST(5));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");

	if (sv_isa(ST(1), "GD::Font")) {
	    IV tmp = SvIV((SV*)SvRV(ST(1)));
	    font = (GD__Font) tmp;
	}
	else
	    croak("font is not of type GD::Font");
	{

		gdImageString(image,font,x,y,s,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Image_gdstringUp)
{
    dXSARGS;
    if (items != 6) {
	croak("Usage: GD::Image::stringUp(image,font,x,y,s,color)");
    }
    {
	GD__Image	image;
	GD__Font	font;
	int	x = (int)SvIV(ST(2));
	int	y = (int)SvIV(ST(3));
	char *	s = (char *)SvPV(ST(4),na);
	int	color = (int)SvIV(ST(5));

	if (sv_isa(ST(0), "GD::Image")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    image = (GD__Image) tmp;
	}
	else
	    croak("image is not of type GD::Image");

	if (sv_isa(ST(1), "GD::Font")) {
	    IV tmp = SvIV((SV*)SvRV(ST(1)));
	    font = (GD__Font) tmp;
	}
	else
	    croak("font is not of type GD::Font");
	{

		gdImageStringUp(image,font,x,y,s,color);

	}

    }
    XSRETURN(1);
}

XS(XS_GD__Font_gdSmall)
{
    dXSARGS;
    if (items < 0 || items > 1) {
	croak("Usage: GD::Font::Small(packname=\"GD::Font\")");
    }
    {
	char *	packname;
	GD__Font	RETVAL;

	if (items < 1)
	    packname = "GD::Font";
	else {
	    packname = (char *)SvPV(ST(0),na);
	}
	{

		RETVAL = gdFontSmall;

	}

	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "GD::Font", (void*)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Font_gdLarge)
{
    dXSARGS;
    if (items < 0 || items > 1) {
	croak("Usage: GD::Font::Large(packname=\"GD::Font\")");
    }
    {
	char *	packname;
	GD__Font	RETVAL;

	if (items < 1)
	    packname = "GD::Font";
	else {
	    packname = (char *)SvPV(ST(0),na);
	}
	{

		RETVAL = gdFontLarge;

	}

	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "GD::Font", (void*)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Font_gdMediumBold)
{
    dXSARGS;
    if (items < 0 || items > 1) {
	croak("Usage: GD::Font::MediumBold(packname=\"GD::Font\")");
    }
    {
	char *	packname;
	GD__Font	RETVAL;

	if (items < 1)
	    packname = "GD::Font";
	else {
	    packname = (char *)SvPV(ST(0),na);
	}
	{

		RETVAL = gdFontMediumBold;

	}

	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "GD::Font", (void*)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Font_gdTiny)
{
    dXSARGS;
    if (items < 0 || items > 1) {
	croak("Usage: GD::Font::Tiny(packname=\"GD::Font\")");
    }
    {
	char *	packname;
	GD__Font	RETVAL;

	if (items < 1)
	    packname = "GD::Font";
	else {
	    packname = (char *)SvPV(ST(0),na);
	}
	{

		RETVAL = gdFontTiny;

	}

	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "GD::Font", (void*)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Font_gdnchars)
{
    dXSARGS;
    if (items != 1) {
	croak("Usage: GD::Font::nchars(font)");
    }
    {
	GD__Font	font;
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Font")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    font = (GD__Font) tmp;
	}
	else
	    croak("font is not of type GD::Font");
	{

		RETVAL = font->nchars;

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Font_gdoffset)
{
    dXSARGS;
    if (items != 1) {
	croak("Usage: GD::Font::offset(font)");
    }
    {
	GD__Font	font;
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Font")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    font = (GD__Font) tmp;
	}
	else
	    croak("font is not of type GD::Font");
	{

		RETVAL = font->offset;

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Font_gdwidth)
{
    dXSARGS;
    if (items != 1) {
	croak("Usage: GD::Font::width(font)");
    }
    {
	GD__Font	font;
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Font")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    font = (GD__Font) tmp;
	}
	else
	    croak("font is not of type GD::Font");
	{

		RETVAL = font->w;

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_GD__Font_gdheight)
{
    dXSARGS;
    if (items != 1) {
	croak("Usage: GD::Font::height(font)");
    }
    {
	GD__Font	font;
	int	RETVAL;

	if (sv_isa(ST(0), "GD::Font")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    font = (GD__Font) tmp;
	}
	else
	    croak("font is not of type GD::Font");
	{

		RETVAL = font->h;

	}

	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

extern "C"
XS(boot_GD)
{
    dXSARGS;
    char* file = __FILE__;

    newXS("GD::constant", XS_GD_constant, file);
    newXS("GD::Image::Debug", XS_GD__Debug, file);
    newXS("GD::Image::new", XS_GD__Image_gdnew, file);
    newXS("GD::Image::newFromGif", XS_GD__Image_gdnewFromGif, file);
    newXS("GD::Image::newFromXbm", XS_GD__Image_gdnewFromXbm, file);
    newXS("GD::Image::newFromGd", XS_GD__Image_gdnewFromGd, file);
    newXS("GD::Image::DESTROY", XS_GD__Image_gdDESTROY, file);
    newXS("GD::Image::__Gif", XS_GD__Image_gd__Gif, file);
    newXS("GD::Image::__Gd", XS_GD__Image_gd__Gd, file);
    newXS("GD::Image::transparent", XS_GD__Image_gdtransparent, file);
    newXS("GD::Image::getBounds", XS_GD__Image_gdgetBounds, file);
    newXS("GD::Image::rgb", XS_GD__Image_gdrgb, file);
    newXS("GD::Image::boundsSafe", XS_GD__Image_gdboundsSafe, file);
    newXS("GD::Image::getPixel", XS_GD__Image_gdgetPixel, file);
    newXS("GD::Image::setPixel", XS_GD__Image_gdsetPixel, file);
    newXS("GD::Image::line", XS_GD__Image_gdline, file);
    newXS("GD::Image::dashedLine", XS_GD__Image_gddashedLine, file);
    newXS("GD::Image::polygon", XS_GD__Image_gdpolygon, file);
    newXS("GD::Image::filledPolygon", XS_GD__Image_gdfilledPolygon, file);
    newXS("GD::Image::rectangle", XS_GD__Image_gdrectangle, file);
    newXS("GD::Image::filledRectangle", XS_GD__Image_gdfilledRectangle, file);
    newXS("GD::Image::arc", XS_GD__Image_gdarc, file);
    newXS("GD::Image::fillToBorder", XS_GD__Image_fillToBorder, file);
    newXS("GD::Image::fill", XS_GD__Image_fill, file);
    newXS("GD::Image::setBrush", XS_GD__Image_setBrush, file);
    newXS("GD::Image::setTile", XS_GD__Image_setTile, file);
    newXS("GD::Image::setStyle", XS_GD__Image_setStyle, file);
    newXS("GD::Image::colorAllocate", XS_GD__Image_colorAllocate, file);
    newXS("GD::Image::colorClosest", XS_GD__Image_colorClosest, file);
    newXS("GD::Image::colorExact", XS_GD__Image_colorExact, file);
    newXS("GD::Image::colorsTotal", XS_GD__Image_colorsTotal, file);
    newXS("GD::Image::interlaced", XS_GD__Image_interlaced, file);
    newXS("GD::Image::colorDeallocate", XS_GD__Image_colorDeallocate, file);
    newXS("GD::Image::copy", XS_GD__Image_copy, file);
    newXS("GD::Image::copyResized", XS_GD__Image_copyResized, file);
    newXS("GD::Image::char", XS_GD__Image_gdchar, file);
    newXS("GD::Image::charUp", XS_GD__Image_gdcharUp, file);
    newXS("GD::Image::string", XS_GD__Image_gdstring, file);
    newXS("GD::Image::stringUp", XS_GD__Image_gdstringUp, file);
    newXS("GD::Font::Small", XS_GD__Font_gdSmall, file);
    newXS("GD::Font::Large", XS_GD__Font_gdLarge, file);
    newXS("GD::Font::MediumBold", XS_GD__Font_gdMediumBold, file);
    newXS("GD::Font::Tiny", XS_GD__Font_gdTiny, file);
    newXS("GD::Font::nchars", XS_GD__Font_gdnchars, file);
    newXS("GD::Font::offset", XS_GD__Font_gdoffset, file);
    newXS("GD::Font::width", XS_GD__Font_gdwidth, file);
    newXS("GD::Font::height", XS_GD__Font_gdheight, file);
    ST(0) = &sv_yes;
    XSRETURN(1);
}
