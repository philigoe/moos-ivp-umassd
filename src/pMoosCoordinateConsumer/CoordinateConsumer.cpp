/****************************************************************************/
/* CoordinateConsumer.cpp */
/****************************************************************************/

// CoordinateConsumer Includes
#include "CoordinateConsumer.h"


/*************************************************************************//**
 * A constructor for the CoordinateConsumer object.
 */
CMOOSCoordinateConsumer::CMOOSCoordinateConsumer()
{
  // Initialization
  newNavXValue = false;
  navX = 0.0;
  newNavYValue = false;
  navY = 0.0;

  // Character classification and case convention reset to POSIX standard
  setlocale(LC_CTYPE, "");
}


/*************************************************************************//**
 * A destructor for the CoordinateConsumer object.
 */
CMOOSCoordinateConsumer::~CMOOSCoordinateConsumer()
{
  // No dynamic memory to deallocate
}


/*************************************************************************//**
 * Overloaded function that is run once, when CoordinateConsumer first connects
 * to the MOOSdb.  Registration for MOOSdb variables we want to track takes
 * place here and in OnStartUp(), as per the MOOS documentation.
 *
 * @return  a boolean indicating success or failure
 */
bool CMOOSCoordinateConsumer::OnConnectToServer()
{
  DoRegistrations();

  /* Success */
  return true;
}


/*************************************************************************//**
 * Overloaded function called each time a MOOSdb variable that we are
 * subscribed to is updated.
 *
 * @return  a boolean indicating success or failure
 */
bool CMOOSCoordinateConsumer::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
  dfTimeNow = MOOSTime();

  // Process the new mail

  for(p = NewMail.begin(); p != NewMail.end(); p++)
  {
    CMOOSMsg &Message = *p;

    if (Message.m_sKey == "NAV_X") {
      if(Message.m_dfVal != navX) {
        navX = Message.m_dfVal;
        newNavXValue = true;
      }

    } else if (Message.m_sKey == "NAV_Y") {
      if(Message.m_dfVal != navY) {
        navY = Message.m_dfVal;
        newNavYValue = true;
      }
    } else if(Message.m_sKey == "CONVERTED_LATITUDE") {
      convertedLatitude = Message.m_dfVal;
      newConvertedLatitudeValue = true;
    } else if(Message.m_sKey == "CONVERTED_LONGITUDE") {
      convertedLongitude = Message.m_dfVal;
      newConvertedLongitudeValue = true;
    }
  }

  /* Success */
  return true;
}


/*************************************************************************//**
 * Overloaded function called every 1/Apptick to process data and do work.
 */
bool CMOOSCoordinateConsumer::Iterate()
{
  // Main
  if(newNavXValue || newNavYValue) {
    MOOSTrace("Nav local location: (%f,%f)\n", navX, navY);
    newNavXValue = false;
    newNavYValue = false;

    //  Let's notify the CoordinateConversion app to get these NAV_X and NAV_Y values converted
    m_Comms.Notify("NAV_X_TO_LONG", navX);
    m_Comms.Notify("NAV_Y_TO_LAT", navY);
  }

  // See if we have converted location values
  if(newConvertedLatitudeValue || newConvertedLongitudeValue) {
    MOOSTrace("Recieved converted location: (%f,%f)\n", convertedLatitude, convertedLongitude);
    newConvertedLatitudeValue = false;
    newConvertedLongitudeValue = false;
  }

  /* Success */
  return true;
}


/*************************************************************************//**
 * Overloaded function where we initialize the Local UTM coordinate system,
 * perform initializations based on the contents of the .moos file, and
 * subscribe to any relevant MOOSdb variables.
 *
 * @return  a boolean indicating success or failure
 */
bool CMOOSCoordinateConsumer::OnStartUp()
{
  // Useful temporary variables
  std::string sVal;

  // Retrieve application-specific configuration parameters

  // Register for relevant MOOSdb variables
  DoRegistrations();

  /* Success */
  return true;
}


/*************************************************************************//**
 * Register for the variables of interest in the MOOSdb.
 */
void CMOOSCoordinateConsumer::DoRegistrations()
{
  m_Comms.Register("NAV_X", 0);
  m_Comms.Register("NAV_Y", 0);
  m_Comms.Register("CONVERTED_LATITUDE", 0);
  m_Comms.Register("CONVERTED_LONGITUDE", 0);
}
