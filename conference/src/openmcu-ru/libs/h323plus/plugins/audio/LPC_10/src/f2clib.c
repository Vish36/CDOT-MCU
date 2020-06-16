/*

$Log: f2clib.c,v $
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

Revision 1.1.2.1  2006/07/22 14:03:16  rjongbloed
Added more plug ins

Revision 1.1.2.1  2006/05/08 13:49:57  rjongbloed
Imported all the audio codec plug ins from OpenH323

Revision 1.2  2004/05/05 13:25:38  rjongbloed
Fixed clearly incorrect code (dived by zero) found with an MSVC warning

Revision 1.1  2004/05/04 11:16:42  csoutheren
Initial version

Revision 1.3  2004/02/17 09:21:45  csoutheren
Fix for GM bug 134591

Revision 1.2  2002/02/15 03:57:55  yurik
Warnings removed during compilation, patch courtesy of Jehan Bing, jehan@bravobrava.com

Revision 1.1  2000/06/05 04:45:12  robertj
Added LPC-10 2400bps codec

 * Revision 1.1  1996/08/19  22:32:10  jaf
 * Initial revision
 *

*/

/*
 * f2clib.c
 *
 * SCCS ID:  @(#)f2clib.c 1.2 96/05/19
 */

#include "f2c.h"

#ifdef KR_headers
integer pow_ii(ap, bp) integer *ap, *bp;
#else
integer pow_ii(integer *ap, integer *bp)
#endif
{
	integer pow, x, n;
	unsigned long u;

	x = *ap;
	n = *bp;

	if (n <= 0) {
		if (n == 0 || x == 1)
			return 1;
		if (x != -1)
			return x != 0 ? 1/x : 0;
		n = -n;
		}
	u = n;
	for(pow = 1; ; )
		{
		if(u & 01)
			pow *= x;
		if(u >>= 1)
			x *= x;
		else
			break;
		}
	return(pow);
	}



#ifdef KR_headers
double r_sign(a,b) real *a, *b;
#else
double r_sign(real *a, real *b)
#endif
{
double x;
x = (*a >= 0 ? *a : - *a);
return( *b >= 0 ? x : -x);
}



#ifdef KR_headers
double floor();
integer i_nint(x) real *x;
#else
#undef abs
#include "math.h"
integer i_nint(real *x)
#endif
{
return (integer)( (*x)>=0 ?
	floor(*x + .5) : -(floor(.5 - *x)) );
}
