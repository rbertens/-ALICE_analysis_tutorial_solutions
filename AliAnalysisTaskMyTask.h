/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. */
/* See cxx source for full Copyright notice */
/* $Id$ */

#ifndef AliAnalysisTaskMyTask_H
#define AliAnalysisTaskMyTask_H

#include "AliAnalysisTaskSE.h"

class AliAODEvent;
class TList;
class TH1F;
class AliPIDResponse;

class AliAnalysisTaskMyTask : public AliAnalysisTaskSE  
{
    public:
                                AliAnalysisTaskMyTask();
                                AliAnalysisTaskMyTask(const char *name);
        virtual                 ~AliAnalysisTaskMyTask();

        virtual void            UserCreateOutputObjects();
        virtual void            UserExec(Option_t* option);
        virtual void            Terminate(Option_t* option);

    private:
        AliAODEvent*            fAOD;           //! input event
        TList*                  fOutputList;    //! output list

        // some histograms
        TH1F*                   fHistPt;        //! dummy histogram

        // step 1
        TH1F*                   fHistVertexZ;   //! z position of vertex
        TH1F*                   fHistCentrality;//! centrality 

        // step 2
        TH2F*                   fHistEtaPhi;    // track eta phi
        TH1F*                   fHistPionPtC;   // 
        TH1F*                   fHistPionEtaC;  //
        TH1F*                   fHistPionPhiC;
        TH1F*                   fHistPionPtP;
        TH1F*                   fHistPionEtaP;
        TH1F*                   fHistPionPhiP;


        TH2F*                   fHistPID;       //! pid info
        AliPIDResponse*         fPIDResponse;   //! pid response

        AliAnalysisTaskMyTask(const AliAnalysisTaskMyTask&); // not implemented
        AliAnalysisTaskMyTask& operator=(const AliAnalysisTaskMyTask&); // not implemented

        ClassDef(AliAnalysisTaskMyTask, 1);
};

#endif
