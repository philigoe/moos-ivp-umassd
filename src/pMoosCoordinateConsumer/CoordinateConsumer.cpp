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

  /* EXAMPLE:
  for(p = NewMail.begin(); p != NewMail.end(); p++)
  {
    CMOOSMsg &Message = *p;
    if (Message.m_sKey == "NAV_X")
    {
      dfNavX = Message.m_dfVal;
      bNavXisCurrent = true;
    }
  }
  */

  /* Success */
  return true;
}                                      


/*************************************************************************//**
 * Overloaded function called every 1/Apptick to process data and do work.
 */
bool CMOOSCoordinateConsumer::Iterate()
{   
  // Main

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

  /*
  // Get the latitude origin from the .moos file
  if (m_MissionReader.GetValue("LatOrigin", sVal)) 
  {
    char* end;
    dfLatOrigin = std::strtod(sVal.c_str(), &end);
    if (!(*end == '\0'))
    {
      MOOSTrace("LatOrigin not set; unexpected end of string - FAIL\n");
      MOOSPause(5000);
      exit(1);
    } 
  }
  else 
  {
    MOOSTrace("LatOrigin not set - FAIL\n");
    MOOSPause(5000);
    exit(1);
  } 

  // Get the longitude origin from the .moos file
  if (m_MissionReader.GetValue("LongOrigin", sVal)) 
  {
    char* end;
    dfLonOrigin = std::strtod(sVal.c_str(), &end);
    if (!(*end == '\0'))
    {
      MOOSTrace("LonOrigin not set; unexpected end of string - FAIL\n");
      MOOSPause(5000);
      exit(1);
    } 
  }
  else 
  {
    MOOSTrace("LongOrigin not set - FAIL\n");
    MOOSPause(5000);
    exit(1);
  }

  // Initialize our coordinate origins 
  if (!m_Geodesy.Initialise(dfLatOrigin, dfLonOrigin)) 
  {
    MOOSTrace("Geodesy Init failed - FAIL\n");
    MOOSPause(5000);
    exit(1);
  }
  */

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
  // EXAMPLE:
  //m_Comms.Register("NAV_X", 0);
}

