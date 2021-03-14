//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBaseFrame *BaseFrame;
//---------------------------------------------------------------------------
__fastcall TBaseFrame::TBaseFrame(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
