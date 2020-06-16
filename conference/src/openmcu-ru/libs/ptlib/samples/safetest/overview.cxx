/*
 * overview.cxx
 *
 * Thread safety test of PSafeXXX structures
 * 
 * Copyright (c) 2005 Indranet Technologies Ltd.
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
 * The Original Code is Open Phone Abstraction Library.
 *
 * The Initial Developer of the Original Code is Indranet Technologies Ltd.
 *
 * The author of this code is Derek J Smithies
 * *
 * $Log: overview.cxx,v $
 * Revision 1.1.1.1  2020/01/20 06:09:07  bishnu
 * conference is the CDOT-MCU (CDOT conferencing server or CDOT- multipoint control unit)
 * It should be integrated with CDOT-ngms (in MAX-NG C5 or any other SIP PROXY, which can actually land the conferencing call on the CDOT-MCU)
 * CDOT-MCU works as service provider (roomNo@serviceIP:Port)
 * room number should be dialed from any point such as MAX-NG C5 or any proxy, because a SIP hardphone can not dial the full SIP-URI (roomNo@serviceIP:Port) hence there should be any intermediate entity.
 *
 * For more Details go through the 'conferncing_Overview-mod' document
 *
 * Revision 1.1.1.1  2020/01/14 11:23:54  root
 * Final version of CDOT-MCU
 *
 * Revision 1.1.1.1  2020/01/14 08:43:31  root
 * Final changes for the CDOT-MCU
 *
 * Revision 1.1.1.1  2019/12/19 09:12:34  root
 *
 * CDOT-MCU  conferencing module
 *
 *
 * Revision 1.1  2006/02/12 21:42:07  dereksmithies
 * Add lots of doxygen style comments, and an introductory page.
 *
 *
 */

/*! \mainpage Thread safe test of PSafeXXX

\section secOverview Overview

     An application to test the operation of the methods in the
     PSafeXXX structures of Pwlib. Specifically, we examine
     PSafeObject, PSafeDictionary, PSafePtr.

     In addition, we examine the PThread structure, because hundreds
     of PThread instances are are created/destroyed every minute.

\version 1.0

\author  Derek J Smithies


$Date: 2020/01/20 06:09:07 $


\section secContents Contents

\li \ref secClassListings 
\li \ref secArchitecture 

\section secClassListings Description of the classes in this application
The following classes are to be found in this application.
\li SafeTest - the parent class of everything, which is descended from 
     PProcess, and contains the dictionary being tested.
\li DelayThread - the worker class, is descended from PSafeObject, and is 
    placed in the dictionary being tested
\li UserInterfaceThread - waits for keyboard input and responds appropriately
\li LauncherThread - creates instances of the DelayThread class
\section secArchitecture Architecture 

The DelayThread class is the "worker bee" class in this
application. Hundreds, or indeed millions of instances of this class
will be created and destroyed. Each DelayThread instance is descended from 
 PSafeObject and does the following things
 \li create an AutoDeletedThread to 
 \li appends this DelayThread instance to a dictionary
 \li sleep for the user defined  number of milliseconds
 \li create an AutoDeletedThread to remove this DelayThread 
     instance from the dictionary.

There are several threads of execution in this program

\li Launcher thread, which runs in the class LauncherThread. There is
   one instance of this thread, which runs in a busy loop fashion to
   create DelayThread instances. This launcher thread will create
   DelayThread instances when the internal counter of the number of
   instances falls below a user defined values.
\li UserInterface thread, which runs in the class
    UserInterfaceThread. This reads input from the console, and will
    report on the progress, (number of iterations, average delay
    period etc) and will end the program on request.
\li Garbage collection thread, which runs inside several methods of
    the SafeTest class. It follows the examples in pwlib of repeatedly
    calling the method dictionary.DelateObjectsToBeDeleted. It
    deviates from these examples by having no delay between calling
    the DeleteObjects method.

This program is ideally run on a multi processor machine. When run,
you will see two threads are consuming 100% of the cpu time, and that
there are several other threads that just "come and go". The idea is
that after some time we expect it to be running just as at the
beginning. No thread will stop with an error condition, and the user
interface will still behave as expected.
*/
