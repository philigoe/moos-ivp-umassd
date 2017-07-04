/****************************************************************************/
/* CoordinateConversion.h */
/****************************************************************************/

#ifndef MOOS_APP_CoordinateConversion_H_
#define MOOS_APP_CoordinateConversion_H_

// MOOS Includes
#include "MOOS/libMOOS/App/MOOSApp.h"
#include "MOOS/libMOOSGeodesy/MOOSGeodesy.h"


/*************************************************************************//**
 * Class that extends CMOOSApp to produce pMoosCoordinateConversion.
 */
class CMOOSCoordinateConversion : public CMOOSApp
{
  public:
    CMOOSCoordinateConversion();
    virtual ~CMOOSCoordinateConversion();

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
    CMOOSGeodesy m_Geodesy;

    // Global variables filled by the .moos file

    // Global variables
    double dfLatOrigin;
    double dfLonOrigin;
    bool newLatToConvert;
    double latToConvert;
    bool newLongToConvert;
    double longToConvert;


    double dfTimeNow;

    // Functions
    void DoRegistrations();
};

#endif // #ifndef MOOS_APP_CoordinateConversion_H_
