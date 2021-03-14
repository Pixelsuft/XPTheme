//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include "MainFrame.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TTimer *StartupTimer;
	TImage *left_top;
	TImage *right_top;
	TImage *left_down;
	TImage *right_down;
	TImage *center_top2;
	TImage *center_down;
	TImage *left_center;
	TImage *right_center;
	TImage *center_top1;
	TImage *center_top3;
	TImage *close_btn;
	TImage *max_btn;
	TImage *min_btn;
	TImage *res_btn;
	TImage *prog_icon;
	TTimer *double_click_timer;
	TLabel *caption_label;
	TBaseFrame *BaseFrame1;
	void __fastcall StartupTimerTimer(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall center_top2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall center_top2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall center_top2MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall left_centerMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall left_centerMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall left_centerMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall right_centerMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall right_centerMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall right_centerMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall center_downMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall center_downMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall center_downMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall left_topMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall left_topMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall left_topMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall right_topMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall right_topMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall right_topMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall left_downMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall left_downMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall left_downMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall right_downMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall right_downMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall right_downMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall close_btnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall close_btnMouseEnter(TObject *Sender);
	void __fastcall close_btnMouseLeave(TObject *Sender);
	void __fastcall close_btnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall min_btnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall min_btnMouseEnter(TObject *Sender);
	void __fastcall min_btnMouseLeave(TObject *Sender);
	void __fastcall min_btnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall max_btnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall max_btnMouseLeave(TObject *Sender);
	void __fastcall max_btnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall max_btnMouseEnter(TObject *Sender);
	void __fastcall res_btnMouseEnter(TObject *Sender);
	void __fastcall res_btnMouseLeave(TObject *Sender);
	void __fastcall res_btnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall res_btnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall double_click_timerTimer(TObject *Sender);











private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
