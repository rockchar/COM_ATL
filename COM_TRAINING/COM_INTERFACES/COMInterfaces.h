#pragma once
#include <Windows.h>
/**************************************  DESCRIPTION ****************************************************
COM,OLE and ACTIVEX Relationship:
COM is the backbone of all the OLE technologies.OLE 1.0 was a 16-Bit technology that appeared around 1991.
It enabled software applications to share information through linking and embedding. Certain applications 
may export visual objects to other applications. A host application may embed this object inside itself 
(Which produced a copy of the original data) or reference through a link(which is the connection to thr 
original data source)

A classic example of this technology is an MS-Word document containing an embedded MS-Excel spreadsheet.

Active X is the current blanket name for any COM-based technology
*********************************************************************************************************/


/*************************************** INTERFACES *****************************************************
                                
COM is all about interfaces - the only way in which clients and servers can communicate is through the 
COM interfaces.
An interface is a collection of semantically related functions, which describe a single and unique 
behavior that may be supported by a class.
Interfaces have - no state,no Implementation
Every COM interface (standard or custom) must ultimately derive from the core COM interface - IUnknown
*********************************************************************************************************/
//Could also derive from another IUnknown derived interface as well 

interface IDraw : public IUnknown
{
	// this also brings in virtual definitions of QueryInterface()
	// addref() and release()
	virtual void Draw() = 0;
};

class CoHexagon : public IDraw {
public:
	HRESULT _stdcall QueryInterface(REFIID riid, void ** ppv);
	ULONG   _stdcall AddRef();
	ULONG   _stdcall Release();
	// IDraw
	void Draw();
};
