//---------------------------------------------------------------------------

#ifndef MainFrameH
#define MainFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TBaseFrame : public TFrame
{
__published:	// IDE-managed Components
	TButton *TestButton;
private:	// User declarations
public:		// User declarations
	__fastcall TBaseFrame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBaseFrame *BaseFrame;
//---------------------------------------------------------------------------
#endif
