/*
 * main.h
 *
 * PWLib application header file for ThreadSafe
 *
 * Copyright 2002 Equivalence
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
 * Revision 1.7  2006/06/21 03:28:42  csoutheren
 * Various cleanups thanks for Frederic Heem
 *
 * Revision 1.6  2003/10/27 22:12:56  dereksmithies
 * Add more good changes to get Compare method work. Thanks to Gene Small
 *
 * Revision 1.5  2003/10/13 23:38:31  dereksmithies
 * Add debugging statements, usage(), Fixed Compare method. Thanks Gene Small.
 *
 * Revision 1.4  2002/12/11 03:38:35  robertj
 * Added more tests
 *
 * Revision 1.3  2002/12/02 01:08:29  robertj
 * Updated to latest safe collection classes, thanks Vladimir Nesic
 *
 * Revision 1.2  2002/05/02 00:30:03  robertj
 * Allowed for non-template containers
 *
 * Revision 1.1  2002/05/01 04:16:44  robertj
 * Added thread safe collection classes.
 *
 */

#ifndef _ThreadSafe_MAIN_H
#define _ThreadSafe_MAIN_H

#include <ptlib/pprocess.h>
#include <ptlib/safecoll.h>


class ThreadSafe;

class TestObject : public PSafeObject
{
    PCLASSINFO(TestObject, PSafeObject);
  public:
    TestObject(ThreadSafe & process, unsigned val);
    ~TestObject();

    Comparison Compare(const PObject & obj) const;
    void PrintOn(ostream & strm) const;

    ThreadSafe & process;
    unsigned value;
};


class ThreadSafe : public PProcess
{
  PCLASSINFO(ThreadSafe, PProcess)

  public:
    ThreadSafe();
    ~ThreadSafe();
    void Main();

  private:
    void Usage();

    void Test1(PArgList & args);
    void Test1Output();
    void Test1OutputEnd();
    PDECLARE_NOTIFIER(PThread, ThreadSafe, Test1Thread);

    void Test2(PArgList & args);
    PDECLARE_NOTIFIER(PThread, ThreadSafe, Test2Thread1);
    PDECLARE_NOTIFIER(PThread, ThreadSafe, Test2Thread2);

    void Test3(PArgList & args);
    PDECLARE_NOTIFIER(PThread, ThreadSafe, Test3Thread1);
    PDECLARE_NOTIFIER(PThread, ThreadSafe, Test3Thread2);

    PSafeList<TestObject> unsorted;
    PSafeSortedList<TestObject> sorted;
    PSafeDictionary<POrdinalKey, TestObject> sparse;

    PINDEX        threadCount;
    PTimeInterval startTick;
    PMutex        mutexObjects;
    unsigned      totalObjects;
    unsigned      currentObjects;

  friend class TestObject;
};


#endif  // _ThreadSafe_MAIN_H


// End of File ///////////////////////////////////////////////////////////////
