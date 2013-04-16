#include "FairTutorialDet1Geo.h"
#include "FairGeoNode.h"

ClassImp(FairTutorialDet1Geo)

// -----   Default constructor   -------------------------------------------
FairTutorialDet1Geo::FairTutorialDet1Geo()
  : FairGeoSet()
{
  // Constructor
  fName="tutdet";
  maxSectors=0;
  maxModules=10;
}

// -------------------------------------------------------------------------

const char* FairTutorialDet1Geo::getModuleName(Int_t m)
{
  /** Returns the module name of TutorialDet number m
      Setting MyDet here means that all modules names in the
      ASCII file should start with TutorialDet otherwise they will
      not be constructed
  */
  sprintf(modName,"tutdet%i",m+1);
  return modName;
}

const char* FairTutorialDet1Geo::getEleName(Int_t m)
{
  /** Returns the element name of Det number m */
  sprintf(eleName,"tutdet%i",m+1);
  return eleName;
}