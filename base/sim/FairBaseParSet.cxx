/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
// -------------------------------------------------------------------------
// -----                       FairBaseParSet source file              -----
// -----                Created 06/01/04  by M. Al/Turany              -----
// -------------------------------------------------------------------------

#include "FairBaseParSet.h"

#include "FairParamList.h"              // for FairParamList
#include "FairPrimaryGenerator.h"       // for FairPrimaryGenerator


ClassImp(FairBaseParSet)

FairBaseParSet::FairBaseParSet(const char* name,const char* title,const char* context)
  : FairParGenericSet(name,title,context),
    fDetList(0),
    fPriGen(0),
    fBeamMom(15),
    fContNameList(new TObjArray())
{


}


FairBaseParSet::~FairBaseParSet(void)
{
}

void FairBaseParSet::clear(void)
{
  if(fPriGen) { delete fPriGen; }
  if(fDetList) { delete fDetList; }
  if(fContNameList) { delete fContNameList; }

}

void FairBaseParSet::putParams(FairParamList* l)
{
  if (!l) { return; }
  l->addObject("Detector List", fDetList);
  l->addObject("Event Generator", fPriGen);
  l->add("Beam Momentum Gev/c", fBeamMom);
  l->addObject("Parameter containers list", fContNameList);
}

Bool_t FairBaseParSet::getParams(FairParamList* l)
{
  if (!l) { return kFALSE; }
  if (!l->fillObject("Detector List", fDetList)) { return kFALSE; }
  if (!l->fillObject("Event Generator", fPriGen)) { return kFALSE; }
  if (!l->fill("Beam Momentum Gev/c", &fBeamMom)) { return kFALSE; }
  if (!l->fillObject("Parameter containers list", fContNameList)) { return kFALSE; }
  return kTRUE;
}


