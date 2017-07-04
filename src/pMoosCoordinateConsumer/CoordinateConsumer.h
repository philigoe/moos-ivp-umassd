/****************************************************************************/
/* CoordinateConsumer.h */
/****************************************************************************/

#ifndef MOOS_APP_CoordinateConsumer_H_
#define MOOS_APP_CoordinateConsumer_H_

// MOOS Includes
#include "MOOS/libMOOS/App/MOOSApp.h"
//#include "MOOS/libMOOSGeodesy/MOOSGeodesy.h"


/*************************************************************************//**
 * Class that extends CMOOSApp to produce pMoosCoordinateConsumer.
 */
class CMOOSCoordinateConsumer : public CMOOSApp
{
  public:
    CMOOSCoordinateConsumer();
    virtual ~CMOOSCoordinateConsumer();

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

    bool newNavXValue;
    double navX;
    bool newNavYValue;
    double navY;

    // Functions
    void DoRegistrations();
};

#endif // #ifndef MOOS_APP_CoordinateConsumer_H_
