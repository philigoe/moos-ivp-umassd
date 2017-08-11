/****************************************************************************/
/* DynamicRIDMain.cpp */
/****************************************************************************/

// DynamicRID Includes
#include "DynamicRID.h"


/*************************************************************************//**
 * The main function, which is responsible for starting the DynamicRID
 * MOOS Application and properly handing it the .moos file.
 *
 * @return  the number of errors
 */
int main(int argc , char *argv[])
{
  // Set a default, blank mission file
  const char *sMissionFile = "pMoosDynamicRID.moos";

  // Set a default process name
  const char *sMOOSName = "pMoosDynamicRID";

  // Handle command line arguments
  switch(argc)
  {
    case 3:
      sMOOSName = argv[2];    // alternate process name provided
    case 2:
      sMissionFile = argv[1]; // alternate mission file provided
  }

  // Iniitialize and start the extended MOOSApp class
  CMOOSDynamicRID MOOSDynamicRID;
  MOOSDynamicRID.Run(sMOOSName, sMissionFile);

  return 0;
}

