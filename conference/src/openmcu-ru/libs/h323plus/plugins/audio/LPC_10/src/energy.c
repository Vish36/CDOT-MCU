/*

$Log: energy.c,v $
Revision 1.1.1.1  2020/01/20 06:09:02  bishnu
conference is the CDOT-MCU (CDOT conferencing server or CDOT- multipoint control unit)
It should be integrated with CDOT-ngms (in MAX-NG C5 or any other SIP PROXY, which can actually land the conferencing call on the CDOT-MCU)
CDOT-MCU works as service provider (roomNo@serviceIP:Port)
room number should be dialed from any point such as MAX-NG C5 or any proxy, because a SIP hardphone can not dial the full SIP-URI (roomNo@serviceIP:Port) hence there should be any intermediate entity.

For more Details go through the 'conferncing_Overview-mod' document

Revision 1.1.1.1  2020/01/14 11:23:53  root
Final version of CDOT-MCU

Revision 1.1.1.1  2020/01/14 08:43:31  root
Final changes for the CDOT-MCU

Revision 1.1.1.1  2019/12/19 09:12:34  root

CDOT-MCU  conferencing module


Revision 1.1  2007/10/22 07:40:50  shorne
*** empty log message ***

Revision 1.2  2006/08/01 13:06:50  rjongbloed
Added a raft of unvalidated audio codecs from OpenH323 tree

Revision 1.1.2.1  2006/07/22 14:03:15  rjongbloed
Added more plug ins

Revision 1.1.2.1  2006/05/08 13:49:57  rjongbloed
Imported all the audio codec plug ins from OpenH323

Revision 1.1  2004/05/04 11:16:42  csoutheren
Initial version

Revision 1.2  2002/02/15 03:57:55  yurik
Warnings removed during compilation, patch courtesy of Jehan Bing, jehan@bravobrava.com

Revision 1.1  2000/06/05 04:45:12  robertj
Added LPC-10 2400bps codec

 * Revision 1.1  1996/08/19  22:32:17  jaf
 * Initial revision
 *

*/

#ifdef P_R_O_T_O_T_Y_P_E_S
extern int energy_(integer *len, real *speech, real *rms);
#endif

/*  -- translated by f2c (version 19951025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* ********************************************************************* */

/* 	ENERGY Version 50 */

/* $Log: energy.c,v $
/* Revision 1.1.1.1  2020/01/20 06:09:02  bishnu
/* conference is the CDOT-MCU (CDOT conferencing server or CDOT- multipoint control unit)
/* It should be integrated with CDOT-ngms (in MAX-NG C5 or any other SIP PROXY, which can actually land the conferencing call on the CDOT-MCU)
/* CDOT-MCU works as service provider (roomNo@serviceIP:Port)
/* room number should be dialed from any point such as MAX-NG C5 or any proxy, because a SIP hardphone can not dial the full SIP-URI (roomNo@serviceIP:Port) hence there should be any intermediate entity.
/*
/* For more Details go through the 'conferncing_Overview-mod' document
/*
/* Revision 1.1.1.1  2020/01/14 11:23:53  root
/* Final version of CDOT-MCU
/*
/* Revision 1.1.1.1  2020/01/14 08:43:31  root
/* Final changes for the CDOT-MCU
/*
/* Revision 1.1.1.1  2019/12/19 09:12:34  root
/*
/* CDOT-MCU  conferencing module
/*
/*
/* Revision 1.1  2007/10/22 07:40:50  shorne
/* *** empty log message ***
/*
/* Revision 1.2  2006/08/01 13:06:50  rjongbloed
/* Added a raft of unvalidated audio codecs from OpenH323 tree
/*
/* Revision 1.1.2.1  2006/07/22 14:03:15  rjongbloed
/* Added more plug ins
/*
/* Revision 1.1.2.1  2006/05/08 13:49:57  rjongbloed
/* Imported all the audio codec plug ins from OpenH323
/*
/* Revision 1.1  2004/05/04 11:16:42  csoutheren
/* Initial version
/*
/* Revision 1.2  2002/02/15 03:57:55  yurik
/* Warnings removed during compilation, patch courtesy of Jehan Bing, jehan@bravobrava.com
/*
/* Revision 1.1  2000/06/05 04:45:12  robertj
/* Added LPC-10 2400bps codec
/*
 * Revision 1.1  1996/08/19  22:32:17  jaf
 * Initial revision
 * */
/* Revision 1.3  1996/03/18  21:17:41  jaf */
/* Just added a few comments about which array indices of the arguments */
/* are used, and mentioning that this subroutine has no local state. */

/* Revision 1.2  1996/03/13  16:46:02  jaf */
/* Comments added explaining that none of the local variables of this */
/* subroutine need to be saved from one invocation to the next. */

/* Revision 1.1  1996/02/07 14:45:40  jaf */
/* Initial revision */


/* ********************************************************************* */

/* Compute RMS energy. */

/* Input: */
/*  LEN    - Length of speech buffer */
/*  SPEECH - Speech buffer */
/*           Indices 1 through LEN read. */
/* Output: */
/*  RMS    - Root Mean Square energy */

/* This subroutine has no local state. */

/* Subroutine */ int energy_(integer *len, real *speech, real *rms)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    integer i__;

/*       Arguments */
/*       Local variables that need not be saved */
    /* Parameter adjustments */
    --speech;

    /* Function Body */
    *rms = 0.f;
    i__1 = *len;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*rms += speech[i__] * speech[i__];
    }
    *rms = (real)sqrt(*rms / *len);
    return 0;
} /* energy_ */

