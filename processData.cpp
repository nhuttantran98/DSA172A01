/*
 * =========================================================================================
 * Name        : processData.cpp
 * Description : student code for Assignment 1 - Data structures and Algorithms - Spring 2018
 * =========================================================================================
 */
#include "requestLib.h"
#include "dbLib.h"

/// Initialize and Finalize any global data that you use in the program

bool initVGlobalData(void** pGData) {
    // TODO: allocate global data if you think it is necessary.
    /// pGData contains the address of a pointer. You should allocate data for the global data
    /// and then assign its address to *pGData
    return true;
}
void releaseVGlobalData(void* pGData) {
    // TODO: release the data if you finish using it
}

// void quickSort(L1List<VRecord>& recList){

// }

bool processRequest(VRequest& request, L1List<VRecord>& recList, void* pGData) {
    // TODO: Your code comes here
    int lengthRecList=recList.getSize();
    if(!strcmp(request.code,"VFF")){
        VRecord first=recList[0];
        for(int i=1;i<lengthRecList;i++){
            if(first.cmpTimes(recList[i])) continue;
            else first=recList[i];
        }
        cout<<"VFF: ";
        printVRecord(first);
    }
    else if(!strcmp(request.code,"VFL")){
        VRecord last=recList[0];
        for(int i=1;i<lengthRecList;i++){
            if(!last.cmpTimes(recList[i])) continue;
            else last=recList[i];
        }
        cout<<"VFL: ";
        printVRecord(last);
    }
    else if(!strcmp(request.code,"FIN")){
        cout<<"FIN: ";
        //VRecord last=recList[0];
        for(int i=1;i<lengthRecList;i++){
            if(!strcmp(recList[i].id,"51B01489")) printVRecord(recList[i]);
        }
    }
    else if(!strcmp(request.code,"CNV")){
        L1List<VRecord> list;
        list.insertHead(recList[0]);
        bool check=true;
        for(int i=1;i<lengthRecList;i++){
            int lengthList=list.getSize();
            for(int j=0;j<lengthList;j++){
                if(strcmp(recList[i].id,list[j].id)!=0){
                    check=true;
                }
                else {
                    check=false;
                    break;
                }
            }
            if(check==true) list.insertHead(recList[i]);
        }
        cout<<"CNV: "<<list.getSize();
        for(int i=0;i<list.getSize();i++){
            if(!strcmp(recList[i].id," 51B01489")) printVRecord(recList[i]);
        }
    }
    else cout<<"bla bla";
    /// NOTE: The output of the request will be printed on one line
    /// end by the end-line '\n' character.
    return true;
}

