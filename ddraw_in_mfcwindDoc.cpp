// ddraw_in_mfcwindDoc.cpp : implementation of the CDdraw_in_mfcwindDoc class
//

#include "stdafx.h"
#include "ddraw_in_mfcwind.h"

#include "ddraw_in_mfcwindDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDdraw_in_mfcwindDoc

IMPLEMENT_DYNCREATE(CDdraw_in_mfcwindDoc, CDocument)

BEGIN_MESSAGE_MAP(CDdraw_in_mfcwindDoc, CDocument)
	//{{AFX_MSG_MAP(CDdraw_in_mfcwindDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDdraw_in_mfcwindDoc construction/destruction

CDdraw_in_mfcwindDoc::CDdraw_in_mfcwindDoc()
{
	// TODO: add one-time construction code here

}

CDdraw_in_mfcwindDoc::~CDdraw_in_mfcwindDoc()
{
}

BOOL CDdraw_in_mfcwindDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDdraw_in_mfcwindDoc serialization

void CDdraw_in_mfcwindDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDdraw_in_mfcwindDoc diagnostics

#ifdef _DEBUG
void CDdraw_in_mfcwindDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDdraw_in_mfcwindDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDdraw_in_mfcwindDoc commands
