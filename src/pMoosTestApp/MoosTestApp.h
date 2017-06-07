/****************************************************************************/
/* MoosTestApp.h */
/****************************************************************************/

#ifndef MOOS_APP_MoosTestApp_H_
#define MOOS_APP_MoosTestApp_H_

// MOOS Includes
#include "MOOS/libMOOS/App/MOOSApp.h"
//#include "MOOS/libMOOSGeodesy/MOOSGeodesy.h"


/*************************************************************************//**
 * Class that extends CMOOSApp to produce pMoosTestApp.
 */
class CMOOSMoosTestApp : public CMOOSApp
{
  public:
    CMOOSMoosTestApp();
    virtual ~CMOOSMoosTestApp();

  protected:
    // Inherited from MOOSApp
    bool OnConnectToServer();               /* overloaded */
    bool Iterate();                         /* overloaded */
    bool OnNewMail(MOOSMSG_LIST &NewMail);  /* overloaded */
    bool OnStartUp();                       /* overloaded */
    //bool MakeStatusString();              /* using default */
    //bool OnCommandMsg(CMOOSMsg CmdMsg);   /* unused */
    //bool ConfigureComms();                /* unused*/
    //bool OnDisconnectFromServer();        /* unused*/

  private:
    // Initialize the MOOS coordinate conversion utility
    //CMOOSGeodesy m_Geodesy;

    // Global variables filled by the .moos file

    // Global variables
    //double dfLatOrigin;
    //double dfLonOrigin;
    double dfTimeNow;

    bool newDesiredHeadingValue;
    double desiredHeading;
    bool newDesiredSpeedValue;
    double desiredSpeed;
    bool newDesiredDepthValue;
    double desiredDepth;

    // Functions
    void DoRegistrations();
};

#endif // #ifndef MOOS_APP_MoosTestApp_H_
