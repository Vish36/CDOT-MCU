/*

$Log: median.c,v $
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


Revision 1.1  2007/10/22 07:40:51  shorne
*** empty log message ***

Revision 1.2  2006/08/01 13:06:50  rjongbloed
Added a raft of unvalidated audio codecs from OpenH323 tree

Revision 1.1.2.1  2006/07/22 14:03:18  rjongbloed
Added more plug ins

Revision 1.1.2.1  2006/05/08 13:49:57  rjongbloed
Imported all the audio codec plug ins from OpenH323

Revision 1.1  2004/05/04 11:16:43  csoutheren
Initial version

Revision 1.1  2000/06/05 04:45:12  robertj
Added LPC-10 2400bps codec

 * Revision 1.1  1996/08/19  22:31:31  jaf
 * Initial revision
 *

*/

#ifdef P_R_O_T_O_T_Y_P_E_S
extern integer median_(integer *d1, integer *d2, integer *d3);
#endif

/*  -- translated by f2c (version 19951025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* ********************************************************************* */

/* 	MEDIAN Version 45G */

/* $Log: median.c,v $
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
/* Revision 1.1  2007/10/22 07:40:51  shorne
/* *** empty log message ***
/*
/* Revision 1.2  2006/08/01 13:06:50  rjongbloed
/* Added a raft of unvalidated audio codecs from OpenH323 tree
/*
/* Revision 1.1.2.1  2006/07/22 14:03:18  rjongbloed
/* Added more plug ins
/*
/* Revision 1.1.2.1  2006/05/08 13:49:57  rjongbloed
/* Imported all the audio codec plug ins from OpenH323
/*
/* Revision 1.1  2004/05/04 11:16:43  csoutheren
/* Initial version
/*
/* Revision 1.1  2000/06/05 04:45:12  robertj
/* Added LPC-10 2400bps codec
/*
 * Revision 1.1  1996/08/19  22:31:31  jaf
 * Initial revision
 * */
/* Revision 1.2  1996/03/14  22:30:22  jaf */
/* Just rearranged the comments and local variable declarations a bit. */

/* Revision 1.1  1996/02/07 14:47:53  jaf */
/* Initial revision */


/* ********************************************************************* */

/*  Find median of three values */

/* Input: */
/*  D1,D2,D3 - Three input values */
/* Output: */
/*  MEDIAN - Median value */

integer median_(integer *d1, integer *d2, integer *d3)
{
    /* System generated locals */
    integer ret_val;

/*       Arguments */
    ret_val = *d2;
    if (*d2 > *d1 && *d2 > *d3) {
	ret_val = *d1;
	if (*d3 > *d1) {
	    ret_val = *d3;
	}
    } else if (*d2 < *d1 && *d2 < *d3) {
	ret_val = *d1;
	if (*d3 < *d1) {
	    ret_val = *d3;
	}
    }
    return ret_val;
} /* median_ */

