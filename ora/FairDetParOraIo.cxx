
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[18];
};
static const struct sqlcxp sqlfpn =
{
    17,
    "FairDetParOraIo.pc"
};


static unsigned int sqlctx = 8982723;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
            void  *sqhstv[3];
   unsigned int   sqhstl[3];
            int   sqhsts[3];
            void  *sqindv[3];
            int   sqinds[3];
   unsigned int   sqharm[3];
   unsigned int   *sqharc[3];
   unsigned short  sqadto[3];
   unsigned short  sqtdso[3];
} sqlstm = {12,3};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned int *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(char *, int *); }

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,0,0,29,64,0,0,0,0,0,1,0,
20,0,0,2,0,0,31,72,0,0,0,0,0,1,0,
35,0,0,3,93,0,4,149,0,0,3,2,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,
};


//*-- AUTHOR : Ilse Koenig
//*-- Created : 26/11/2004

//////////////////////////////////////////////////////////////////////////////
// FairDetParOraIo
//
// Base class for all detector I/O  classes from database Oracle
// (uses the Oracle C/C++ precompiler)
//
//////////////////////////////////////////////////////////////////////////////

using namespace std;
#include "FairOraConn.h"
#include "FairDetParOraIo.h"
#include "FairRun.h"
#include "FairRuntimeDb.h"
#include "FairRtdbRun.h"
#include "FairParSet.h"
#include "TClass.h"
#include <iostream>
#include <iomanip>

#define SQLCA_STORAGE_CLASS extern
#define ORACA_STORAGE_CLASS extern

// Oracle communication area
#include "oraca.h"
// Include the SQL Communications Area
#include "sqlca.h"
 
ClassImp(FairDetParOraIo)
ClassImp(FairParOraSet)

FairParOraSet::FairParOraSet(const char* pName) {
  SetName(pName);
  contextId=-1;
  clearVersDate();
}

void FairParOraSet::clearVersDate() {
  versDate[0]=-1;
  versDate[1]=1.E+12;
}

FairDetParOraIo::FairDetParOraIo(FairOraConn* pC) : FairDetParIo() {
  // constructor gets a pointer to the connection class
  pConn=pC;
  actContVers=0;
  actRunId=-1;
  containerList=0;
}

FairDetParOraIo::~FairDetParOraIo(void) {
  // destructor
  if (containerList) {
    containerList->Delete();
    delete containerList;
    containerList=0;
  } 
}

void FairDetParOraIo::commit(void) {
  // commits all changes
  /* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 0;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


  cout<<"Transaction committed"<<endl;
  return;
}
 

void FairDetParOraIo::rollback(void) {
  // discards all changes since last commit
  /* EXEC SQL ROLLBACK WORK; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 0;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )20;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


  cout<<"Transaction rolled back"<<endl;
  return;
}


void FairDetParOraIo::showSqlError(const char* f) {
  // shows SQL error messages 
  Error(f,"\n%s",sqlca.sqlerrm.sqlerrmc);
}


Int_t FairDetParOraIo::getRunStart(FairParSet* pPar) {
  // Gets the actual run id from the runtime database and compares it with
  // the last used actRunId for fetching data.
  // If they are different, the run start time (converted to ansi C time) is
  // read from Oracle and stored together with the run id in the data members
  // run_id and runStart
  actRunId=-1;
  Int_t runStart=-1;
  actContVers=(FairRtdbRun*)FairRun::Instance()->GetRuntimeDb()->getCurrentRun();
  if (!actContVers) {
    Error("getRunStart()","current run not set in runtime database");
    return -1;
  }
  const Text_t* refRun=actContVers->getRefRun();
  if (strlen(refRun)>0) sscanf(refRun,"%i",&actRunId); 
  else actRunId=actContVers->getRunId();
  if (pPar) {
    Int_t contVers=getPredefVersion(pPar);
    if (contVers>=0) actRunId=contVers;
  }
  runStart=pConn->getRunStart(actRunId);
  return runStart;
}


const char* FairDetParOraIo::getHistoryDate() {
  // returns the timestamp set by the user to read historic data
  return pConn->getHistoryDate();
}


Int_t FairDetParOraIo::getPredefVersion(FairParSet* pPar) {
  // finds out if a version for the parameter container has been set by
  // the user (typically by defining a reference run for initialisation
  // in the macro
  // returns -1, if no version found 
  FairParVersion* pv=(FairParVersion*)actContVers->getParVersion((char*)pPar->GetName());
  if (pv) return pv->getInputVersion(inputNumber);
  else return -1;
}


FairParOraSet* FairDetParOraIo::getOraSet(FairParSet* pPar) {
  if (!containerList) containerList=new TList;
  FairParOraSet* pSet=(FairParOraSet*)(containerList->FindObject(pPar->GetName()));
  if (!pSet) { 
    pSet=new FairParOraSet(pPar->GetName());
    pSet->contextId=getContextId(pPar->IsA()->GetName(),pPar->getParamContext());
    containerList->Add(pSet);
  }
  return pSet;
}

Int_t FairDetParOraIo::getContextId(const char* className, const char* paramContext) {
  // return the parameter_context_id
  if (strlen(paramContext)==0) return -1;
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

     char* p_class;
     char* p_context;
     int context_id=-1;
  /* EXEC SQL END DECLARE SECTION; */ 

  p_class=(char*)className;
  p_context=(char*)paramContext;
  /* EXEC SQL WHENEVER SQLERROR GOTO not_found; */ 

  /* EXEC SQL WHENEVER NOT FOUND GOTO not_found; */ 

  /* EXEC SQL SELECT context_id
           INTO :context_id
           FROM cbm_ana.all_param_contexts
           WHERE class = :p_class and context = :p_context; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select context_id into :b0  from cbm_ana.all_param_contexts\
 where (class=:b1 and context=:b2)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )35;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&context_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)p_class;
  sqlstm.sqhstl[1] = (unsigned int  )0;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)p_context;
  sqlstm.sqhstl[2] = (unsigned int  )0;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) goto not_found;
  if (sqlca.sqlcode < 0) goto not_found;
}


  // cout<<"Id of context "<<paramContext<<": "<<context_id<<endl;
  return context_id;
not_found:
  Error("FairDetParOraIo::getContextId","\nContext %s for class %s not found!",
        p_context,p_class);
  return -1;
};

void FairDetParOraIo::setChanged(FairParSet* pPar) {
  // sets the changed flag, the version (id of actual run) and the comment
  pPar->setChanged();
  pPar->setInputVersion(getActRunId(),inputNumber);
  TString s="Read from Oracle\n             Valid for Run Id ";
  s.Append(Form("%d",getActRunId()));
  s.Append("\n             Status at ");
  s.Append(pConn->getHistoryDate());
  pPar->setDescription(s.Data());    
}