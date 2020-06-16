/*
 * main.h
 *
 * PWLib application header file for sound test.
 *
 *
 * $Log: audio.h,v $
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
 * Revision 1.5  2006/06/21 03:28:42  csoutheren
 * Various cleanups thanks for Frederic Heem
 *
 * Revision 1.4  2006/04/09 07:08:13  dereksmithies
 * Add reporting functions.
 * Use the selected device to open the sound card for volume levels.
 *
 * Revision 1.3  2006/04/09 05:13:06  dereksmithies
 * add a means to write the collected audio to disk (as a wav file),
 *    or to the trace log (as text data)
 *
 * Revision 1.2  2005/11/30 12:47:39  csoutheren
 * Removed tabs, reformatted some code, and changed tags for Doxygen
 *
 * Revision 1.1  2005/08/18 22:29:15  dereksmithies
 * Add a full duplex sound card test (which was excised from ohphone).
 * Add copyright header and cvs log statements.
 * Fix startup and closedown segfaults.
 * Add safety mechanism so it can never fill up all computer memory.
 */
 
#ifndef _AUDIO_MAIN_H
#define _AUDIO_MAIN_H

#include <ptlib/sound.h>

class Audio : public PProcess
{
  PCLASSINFO(Audio, PProcess);

public:
  Audio();

  void Main();

  PString GetTestDeviceName() { return devName; }

    static Audio & Current()
        { return (Audio &)PProcess::Current(); }

 protected:
  PString devName;
};


/////////////////////////////////////////////////////////////////////////////
PDECLARE_LIST(TestAudioDevice, PBYTEArray *)
#if 0                                //This makes emacs bracket matching code happy.
{
#endif
 public:
  virtual ~TestAudioDevice();
  
  void Test(const PString & captureFileName);
  BOOL DoEndNow();
  
  void WriteAudioFrame(PBYTEArray *data);
  PBYTEArray *GetNextAudioFrame();
  
 protected:
  PMutex access;
  BOOL endNow;

};



class TestAudio : public PThread  
{
  PCLASSINFO(TestAudio, PThread)
  public:
    TestAudio(TestAudioDevice &master);
    virtual ~TestAudio();

    virtual void Terminate() { keepGoing = FALSE; }
    void LowerVolume();
    void RaiseVolume();
    
    void ReportIterations();

  protected:
    PString name;
    BOOL OpenAudio(enum PSoundChannel::Directions dir);

    PINDEX             currentVolume;
    TestAudioDevice    &controller;
    PSoundChannel      sound;
    BOOL               keepGoing;
    PINDEX             iterations;
};

class TestAudioRead : public TestAudio
{
    PCLASSINFO(TestAudioRead, TestAudio);
  public:
    TestAudioRead(TestAudioDevice &master, const PString & _captureFileName);
    
    void ReportIterations();

    void Main();
 protected:
    PString captureFileName;
};


class TestAudioWrite : public TestAudio
{
    PCLASSINFO(TestAudioWrite, TestAudio);
  public:
    TestAudioWrite(TestAudioDevice &master);

    void ReportIterations();
    
    void Main();
};




#endif  // _AUDIO_MAIN_H
