/****************************************************************************/
/* MoosTestApp.cpp */
/****************************************************************************/

// MoosTestApp Includes
#include "MoosTestApp.h"
#include <iostream>
#include <math.h>
#include <sstream>

/*************************************************************************//**
 * A constructor for the MoosTestApp object.
 */
CMOOSMoosTestApp::CMOOSMoosTestApp()
{
  // Initialization
  newDesiredHeadingValue = false;
  newDesiredSpeedValue = false;
  newDesiredDepthValue = false;

  // Character classification and case convention reset to POSIX standard
  setlocale(LC_CTYPE, "");
}


/*************************************************************************//**
 * A destructor for the MoosTestApp object.
 */
CMOOSMoosTestApp::~CMOOSMoosTestApp()
{
  // No dynamic memory to deallocate
}


/*************************************************************************//**
 * Overloaded function that is run once, when MoosTestApp first connects
 * to the MOOSdb.  Registration for MOOSdb variables we want to track takes
 * place here and in OnStartUp(), as per the MOOS documentation.
 *
 * @return  a boolean indicating success or failure
 */
bool CMOOSMoosTestApp::OnConnectToServer()
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
bool CMOOSMoosTestApp::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
  dfTimeNow = MOOSTime();

  // To  check for mail from  DESIRED_HEADING, _SPEED, and _DEPTH, print to
  // MoosTrace.  Using example code:

  // Process the new mail

  for(p = NewMail.begin(); p != NewMail.end(); p++)
  {
    CMOOSMsg &Message = *p;

    if (Message.m_sKey == "DESIRED_HEADING")
    {
      desiredHeading = Message.m_dfVal;
      newDesiredHeadingValue = true;
    } else if (Message.m_sKey == "DESIRED_SPEED")
    {
      desiredSpeed = Message.m_dfVal;
      newDesiredSpeedValue = true;
    } else if (Message.m_sKey == "DESIRED_DEPTH")
    {
      desiredDepth = Message.m_dfVal;
      newDesiredDepthValue = true;
    }
  }

  /* Success */
  return true;
}


/*************************************************************************//**
 * Overloaded function called every 1/Apptick to process data and do work.
 */
bool CMOOSMoosTestApp::Iterate()
{
  // Main
  if(newDesiredHeadingValue) {
    MOOSTrace("Desired heading value: %f\n", desiredHeading);
    newDesiredHeadingValue = false;
  } else if(newDesiredSpeedValue) {
    MOOSTrace("Desired speed value: %f\n", desiredSpeed);
    newDesiredSpeedValue = false;
  } else if(newDesiredDepthValue) {
    MOOSTrace("Desired depth value: %f\n", desiredDepth);
    newDesiredDepthValue = false;
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
bool CMOOSMoosTestApp::OnStartUp()
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
void CMOOSMoosTestApp::DoRegistrations()
{
  // Second parameter is the interval  at which it's  fetched - 0 recives
  // all mail
  m_Comms.Register("DESIRED_HEADING", 0);
  m_Comms.Register("DESIRED_SPEED", 0);
  m_Comms.Register("DESIRED_DEPTH", 0);
}
