//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MainFrame"
#pragma resource "*.dfm"
TMainForm *MainForm;
int is_move_mouse_down = 0;
bool is_left_center_mouse_down = false;
bool is_right_center_mouse_down = false;
bool is_center_down_mouse_down = false;
bool is_left_top_mouse_down = false;
bool is_right_top_mouse_down = false;
bool is_left_down_mouse_down = false;
bool is_right_down_mouse_down = false;
int move_mouse_start_x = 0;
int move_mouse_start_y = 0;
int is_maximized = false;
int nado_x = 0;
int nado_y = 0;
int nado_w = 0;
int nado_h = 0;
int before_x = 0;
int before_y = 0;
int before_w = 0;
int before_h = 0;
bool is_double_click = false;
AnsiString icons_path = "..\\..\\system";
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TMainForm::StartupTimerTimer(TObject *Sender)
{
	StartupTimer->Enabled=false;
	MainForm->BorderStyle = bsSizeable;
	MainForm->WindowState = wsMaximized;
	nado_x = MainForm->Left;
	nado_y = MainForm->Top;
	if(nado_x < 0)nado_x = 0;
	else if(nado_x > 0)nado_x += 8;
	if(nado_y < 0)nado_y = 0;
	else if(nado_y > 0)nado_y += 8;
	nado_w = Screen->Width - MainForm->ClientWidth - nado_x;
	nado_h = Screen->Height - MainForm->ClientHeight - nado_y;
	if(nado_w > 0)nado_w -= 23;
	if(nado_h > 0)nado_h -= 23;
	MainForm->WindowState = wsNormal;
	MainForm->BorderStyle = bsNone;
	MainForm->Width = 800;
	MainForm->Height = 600;
	MainForm->Left = Screen->Width / 2 - MainForm->Width / 2;
	MainForm->Top = Screen->Height / 2 - MainForm->Height / 2;
	MainForm->AlphaBlendValue=255;
	MainForm->AlphaBlend=false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormResize(TObject *Sender)
{
	if(is_maximized)
	{
		center_top1->Left = 0;
		center_top1->Top = 0;
		center_top3->Left = MainForm->ClientWidth - center_top3->Width;
		center_top3->Top = 0;
		center_top2->Left = center_top1->Width;
		center_top2->Width = MainForm->ClientWidth - center_top1->Width - center_top3->Width;
		center_top2->Top = 0;
		close_btn->Top = 2;
		close_btn->Left = MainForm->ClientWidth - max_btn->Width - 2;
		res_btn->Top = 2;
		res_btn->Left = close_btn->Left - res_btn->Width - 2;
		min_btn->Top = 2;
		min_btn->Left = res_btn->Left - min_btn->Width - 2;
		prog_icon->Left = 5;
		prog_icon->Top = 4;
		caption_label->Top = 3;
		caption_label->Left = prog_icon->Left + prog_icon->Width + 6;
	}
	else
	{
		left_top->Left = 0;
		left_top->Top = 0;
		right_top->Left = MainForm->ClientWidth - right_top->Width;
		right_top->Top = 0;
		left_down->Left = 0;
		left_down->Top = MainForm->ClientHeight - left_down->Height;
		right_down->Left = MainForm->ClientWidth - right_down->Width;
		right_down->Top = MainForm->ClientHeight - right_down->Height;
		center_top1->Top = 0;
		center_top2->Top = 0;
		center_top3->Top = 0;
		center_top1->Left = left_top->Width;
		center_top3->Left = MainForm->ClientWidth - right_top->Width - center_top3->Width;
		center_top2->Left = left_top->Width + center_top1->Width;
		center_top2->Width = MainForm->ClientWidth - left_top->Width - right_top->Width - center_top1->Width - center_top3->Width;
		center_down->Top = MainForm->ClientHeight - center_down->Height;
		center_down->Left = left_down->Width;
		center_down->Width = MainForm->ClientWidth - left_down->Width - right_down->Width;
		left_center->Left = 0;
		left_center->Top = left_top->Height;
		left_center->Height = MainForm->ClientHeight - left_top->Height - left_down->Height;
		right_center->Left = MainForm->ClientWidth - right_center->Width;;
		right_center->Top = right_top->Height;
		right_center->Height = MainForm->ClientHeight - right_top->Height - right_down->Height;
		close_btn->Top = 6;
		close_btn->Left = MainForm->ClientWidth - max_btn->Width - 6;
		max_btn->Top = 6;
		max_btn->Left = close_btn->Left - max_btn->Width - 2;
		min_btn->Top = 6;
		min_btn->Left = max_btn->Left - min_btn->Width - 2;
		prog_icon->Left = 5;
		prog_icon->Top = 7;
		caption_label->Top = 6;
		caption_label->Left = prog_icon->Left + prog_icon->Width + 6;
		BaseFrame1->Left = left_center->Width;
		BaseFrame1->Top = center_top2->Height;
	}
	BaseFrame1->Width = MainForm->ClientWidth - left_center->Width - right_center->Width;
	BaseFrame1->Height = MainForm->ClientHeight - center_top2->Height - center_down->Height;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::center_top2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	move_mouse_start_x = X;
	move_mouse_start_y = Y;
	if(Y <= 4)
	{
		is_move_mouse_down = 1;
	}
	else
	{
		is_move_mouse_down = 2;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::center_top2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	is_move_mouse_down = 0;
	if(is_double_click)
	{
		is_double_click = false;
        double_click_timer->Enabled=false;
		if(center_top2->Cursor == crDefault)
		{
			is_move_mouse_down = 0;
			is_left_center_mouse_down = false;
			is_right_center_mouse_down = false;
			is_center_down_mouse_down = false;
			is_left_top_mouse_down = false;
			is_right_top_mouse_down = false;
			is_left_down_mouse_down = false;
			is_right_down_mouse_down = false;
			move_mouse_start_x = 0;
			move_mouse_start_y = 0;
			if(is_maximized)
			{
				res_btn->Picture->LoadFromFile(icons_path + "\\res.bmp");
				is_maximized=false;
				center_top1->Picture->LoadFromFile(icons_path + "\\v_center_top1.bmp");
				center_top2->Picture->LoadFromFile(icons_path + "\\v_center_top2.bmp");
				center_top2->Height = 30;
				center_top3->Picture->LoadFromFile(icons_path + "\\v_center_top3.bmp");
				left_top->Visible=true;
				right_top->Visible=true;
				left_center->Visible=true;
				right_center->Visible=true;
				left_down->Visible=true;
				right_down->Visible=true;
				center_down->Visible=true;
				MainForm->Left = before_x;
				MainForm->Top = before_y;
				MainForm->Width = before_w;
				MainForm->Height = before_h;
				max_btn->Visible=true;
				res_btn->Visible=false;
			}
			else
			{
				max_btn->Picture->LoadFromFile(icons_path + "\\max.bmp");
				before_x = MainForm->Left;
				before_y = MainForm->Top;
				before_w = MainForm->Width;
				before_h = MainForm->Height;
				center_top1->Picture->LoadFromFile(icons_path + "\\v_center_top1_max.bmp");
				center_top2->Picture->LoadFromFile(icons_path + "\\v_center_top2_max.bmp");
				center_top2->Height = 26;
				center_top3->Picture->LoadFromFile(icons_path + "\\v_center_top3_max.bmp");
				left_top->Visible=false;
				right_top->Visible=false;
				left_center->Visible=false;
				right_center->Visible=false;
				left_down->Visible=false;
				right_down->Visible=false;
				center_down->Visible=false;
				is_maximized=true;
				MainForm->Left = nado_x;
				MainForm->Top = nado_y;
				MainForm->Width = Screen->Width - nado_w;
				MainForm->Height = Screen->Height - nado_h;
				res_btn->Visible=true;
				max_btn->Visible=false;
			}
		}
	}
	else
	{
		is_double_click = true;
		double_click_timer->Enabled=true;
	}
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::center_top2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if(!is_maximized)
	{
		if(is_move_mouse_down == 1)
		{
			int raznica = Y - move_mouse_start_y;
			MainForm->Top += raznica;
			MainForm->Height -= raznica;
		}
		else if(is_move_mouse_down == 2)
		{
			MainForm->Left += X - move_mouse_start_x;
			MainForm->Top += Y - move_mouse_start_y;
		}
		else
		{
			if(Y <= 4)
			{
				center_top1->Cursor = crSizeNS;
				center_top2->Cursor = crSizeNS;
				center_top3->Cursor = crSizeNS;
			}
			else
			{
				center_top1->Cursor = crDefault;
				center_top2->Cursor = crDefault;
				center_top3->Cursor = crDefault;
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::left_centerMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	move_mouse_start_x = X;
	is_left_center_mouse_down = true;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::left_centerMouseMove(TObject *Sender, TShiftState Shift,
		  int X, int Y)
{
	if(is_left_center_mouse_down)
	{
		int raznica = X - move_mouse_start_x;
		MainForm->Left += raznica;
		MainForm->Width -= raznica;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::left_centerMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    is_left_center_mouse_down = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::right_centerMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	is_right_center_mouse_down = false;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::right_centerMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	move_mouse_start_x = X;
	is_right_center_mouse_down = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::right_centerMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if(is_right_center_mouse_down)
	{
		MainForm->Width += X - move_mouse_start_x;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::center_downMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	move_mouse_start_y = Y;
	is_center_down_mouse_down = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::center_downMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	is_center_down_mouse_down = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::center_downMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if(is_center_down_mouse_down)
	{
		MainForm->Height += Y - move_mouse_start_y;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::left_topMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	move_mouse_start_x = X;
	move_mouse_start_y = Y;
	is_left_top_mouse_down = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::left_topMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	is_left_top_mouse_down = false;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::left_topMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	if(is_left_top_mouse_down)
	{
		int raznica_x = X - move_mouse_start_x;
		int raznica_y = Y - move_mouse_start_y;
		MainForm->Left += raznica_x;
		MainForm->Width -= raznica_x;
		MainForm->Top += raznica_y;
		MainForm->Height -= raznica_y;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::right_topMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	move_mouse_start_x = X;
	move_mouse_start_y = Y;
	is_right_top_mouse_down = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::right_topMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	is_right_top_mouse_down = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::right_topMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if(is_right_top_mouse_down)
	{
		int raznica_x = X - move_mouse_start_x;
		int raznica_y = Y - move_mouse_start_y;
		MainForm->Width += raznica_x;
		MainForm->Top += raznica_y;
		MainForm->Height -= raznica_y;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::left_downMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	move_mouse_start_x = X;
	move_mouse_start_y = Y;
	is_left_down_mouse_down = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::left_downMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	is_left_down_mouse_down = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::left_downMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if(is_left_down_mouse_down)
	{
		int raznica_x = X - move_mouse_start_x;
		int raznica_y = Y - move_mouse_start_y;
		MainForm->Left += raznica_x;
		MainForm->Width -= raznica_x;
		MainForm->Height += raznica_y;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::right_downMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	move_mouse_start_x = X;
	move_mouse_start_y = Y;
	is_right_down_mouse_down = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::right_downMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	is_right_down_mouse_down = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::right_downMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if(is_right_down_mouse_down)
	{
		int raznica_x = X - move_mouse_start_x;
		int raznica_y = Y - move_mouse_start_y;
		MainForm->Width += raznica_x;
		MainForm->Height += raznica_y;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::close_btnMouseUp(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	close_btn->Picture->LoadFromFile(icons_path + "\\close.bmp");
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::close_btnMouseEnter(TObject *Sender)
{
	close_btn->Picture->LoadFromFile(icons_path + "\\close_hover.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::close_btnMouseLeave(TObject *Sender)
{
	close_btn->Picture->LoadFromFile(icons_path + "\\close.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::close_btnMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    close_btn->Picture->LoadFromFile(icons_path + "\\close_click.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::min_btnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	min_btn->Picture->LoadFromFile(icons_path + "\\min.bmp");
    MainForm->WindowState = wsMinimized;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::min_btnMouseEnter(TObject *Sender)
{
	min_btn->Picture->LoadFromFile(icons_path + "\\min_hover.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::min_btnMouseLeave(TObject *Sender)
{
	min_btn->Picture->LoadFromFile(icons_path + "\\min.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::min_btnMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	min_btn->Picture->LoadFromFile(icons_path + "\\min_click.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::max_btnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	is_move_mouse_down = 0;
	is_left_center_mouse_down = false;
	is_right_center_mouse_down = false;
	is_center_down_mouse_down = false;
	is_left_top_mouse_down = false;
	is_right_top_mouse_down = false;
	is_left_down_mouse_down = false;
	is_right_down_mouse_down = false;
	move_mouse_start_x = 0;
	move_mouse_start_y = 0;
	max_btn->Picture->LoadFromFile(icons_path + "\\max.bmp");
	before_x = MainForm->Left;
	before_y = MainForm->Top;
	before_w = MainForm->Width;
	before_h = MainForm->Height;
	center_top1->Picture->LoadFromFile(icons_path + "\\v_center_top1_max.bmp");
	center_top2->Picture->LoadFromFile(icons_path + "\\v_center_top2_max.bmp");
	center_top2->Height = 26;
	center_top3->Picture->LoadFromFile(icons_path + "\\v_center_top3_max.bmp");
	left_top->Visible=false;
	right_top->Visible=false;
	left_center->Visible=false;
	right_center->Visible=false;
	left_down->Visible=false;
	right_down->Visible=false;
	center_down->Visible=false;
	is_maximized=true;
	MainForm->Left = nado_x;
	MainForm->Top = nado_y;
	MainForm->Width = Screen->Width - nado_w;
	MainForm->Height = Screen->Height - nado_h;
	res_btn->Visible=true;
	max_btn->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::max_btnMouseLeave(TObject *Sender)
{
	max_btn->Picture->LoadFromFile(icons_path + "\\max.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::max_btnMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	max_btn->Picture->LoadFromFile(icons_path + "\\max_click.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::max_btnMouseEnter(TObject *Sender)
{
    max_btn->Picture->LoadFromFile(icons_path + "\\max_hover.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::res_btnMouseEnter(TObject *Sender)
{
	res_btn->Picture->LoadFromFile(icons_path + "\\res_hover.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::res_btnMouseLeave(TObject *Sender)
{
	res_btn->Picture->LoadFromFile(icons_path + "\\res.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::res_btnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	is_move_mouse_down = 0;
	is_left_center_mouse_down = false;
	is_right_center_mouse_down = false;
	is_center_down_mouse_down = false;
	is_left_top_mouse_down = false;
	is_right_top_mouse_down = false;
	is_left_down_mouse_down = false;
	is_right_down_mouse_down = false;
	move_mouse_start_x = 0;
	move_mouse_start_y = 0;
	res_btn->Picture->LoadFromFile(icons_path + "\\res.bmp");
	is_maximized=false;
	center_top1->Picture->LoadFromFile(icons_path + "\\v_center_top1.bmp");
	center_top2->Picture->LoadFromFile(icons_path + "\\v_center_top2.bmp");
    center_top2->Height = 30;
	center_top3->Picture->LoadFromFile(icons_path + "\\v_center_top3.bmp");
	left_top->Visible=true;
	right_top->Visible=true;
	left_center->Visible=true;
	right_center->Visible=true;
	left_down->Visible=true;
	right_down->Visible=true;
	center_down->Visible=true;
	MainForm->Left = before_x;
	MainForm->Top = before_y;
	MainForm->Width = before_w;
	MainForm->Height = before_h;
	max_btn->Visible=true;
	res_btn->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::res_btnMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	res_btn->Picture->LoadFromFile(icons_path + "\\res_click.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::double_click_timerTimer(TObject *Sender)
{
	double_click_timer->Enabled=false;
    is_double_click = false;
}
//---------------------------------------------------------------------------

