/*
 * main.h
 *
 * Queue - a tester of the PQueueChannel class in pwlib
 *
 * Copyright (c) 2006 Derek J Smithies
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Jester
 *
 * The Initial Developer of the Original Code is Derek J Smithies
 *
 * Contributor(s): ______________________________________.
 *
 * $Log: main.h,v $
 * Revision 1.1.1.1  2020/01/20 06:08:44  bishnu
 * conference is the CDOT-MCU (CDOT conferencing server or CDOT- multipoint control unit)
 * It should be integrated with CDOT-ngms (in MAX-NG C5 or any other SIP PROXY, which can actually land the conferencing call on the CDOT-MCU)
 * CDOT-MCU works as service provider (roomNo@serviceIP:Port)
 * room number should be dialed from any point such as MAX-NG C5 or any proxy, because a SIP hardphone can not dial the full SIP-URI (roomNo@serviceIP:Port) hence there should be any intermediate entity.
 *
 * For more Details go through the 'conferncing_Overview-mod' document
 *
 * Revision 1.1.1.1  2020/01/14 11:23:53  root
 * Final version of CDOT-MCU
 *
 * Revision 1.1.1.1  2020/01/14 08:43:29  root
 * Final changes for the CDOT-MCU
 *
 * Revision 1.1.1.1  2019/12/19 09:12:34  root
 *
 * CDOT-MCU  conferencing module
 *
 *
 * Revision 1.2  2006/12/07 20:49:39  dereksmithies
 * Add doxygen comments to this program.
 * Add doxygen configure file.
 *
 * Revision 1.1  2006/12/07 08:46:17  dereksmithies
 * Initial cut of code to test the operation of PQueueChannel class.
 *
 *
 */

#ifndef _QUEUE_MAIN_H
#define _QUEUE_MAIN_H

#include <ptlib/pprocess.h>
#include <ptclib/delaychan.h>
#include <ptclib/qchannel.h>


/** The main class that is instantiated to do things */
class QueueProcess : public PProcess
{
  PCLASSINFO(QueueProcess, PProcess)

  public:
  /**Constructor, which initalises version number, application name etc*/
    QueueProcess();

  /**Execution starts here, where the command line is processed. In here, the
     child threads (for generating and consuming data) are launched. */
    void Main();

  protected:

#ifdef DOC_PLUS_PLUS
    /**Generate a Block of data, (an array of bytes) and push them onto the
       PQueueChannel class, at some user specified rate. The rate of writing
       the data can be different to the rate of reading the data */
    virtual void GenerateBlockData(PThread &, INT);
#else
    PDECLARE_NOTIFIER(PThread, QueueProcess, GenerateBlockData);
#endif

#ifdef DOC_PLUS_PLUS
    /**Read in a block of data (an array of bytes) from the PQueueChannel
       class at some user specified rate.  The rate of reading the data can be
       different to the rate of writing the data */
    virtual void ConsumeBlockData(PThread &, INT);
#else
    PDECLARE_NOTIFIER(PThread, QueueProcess, ConsumeBlockData);
#endif

    /**The class that acts as a queue */
    PQueueChannel queue;

    /**The number of iterations we run for */
    PINDEX iterations;

    /**The delay (in ms) between consecutive writes */
    PINDEX writeDelay;

    /**the delay (in ms) between consucutive reads */
    PINDEX readDelay;

    /**The size (in bytes) of each write block */
    PINDEX writeSize;

    /**The size (in bytes) of each read block */
    PINDEX readSize;
};


#endif  // _QUEUE_MAIN_H


// End of File ///////////////////////////////////////////////////////////////
