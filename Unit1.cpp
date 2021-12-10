//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -4;
int y = -4;

int pickups = 0;
int right_points = 0;
int left_points = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BallTimerTimer(TObject *Sender)
{
    Ball->Left += x;
    Ball->Top += y;
    //upper reflection
    if (Ball->Top <= Background->Top)
    {
        y = -y;
    }
    if (Ball->Top + Ball->Height - 16 >= Background->Height)
    {
        y = -y;
    }
    //loss
    if (Ball->Left <= Background->Left)
    {
        right_points++;
        BallTimer->Enabled = false;
        Ball->Visible = false;
        Winner->Caption = "PUNKT DLA PRAWEJ STRONY >";
        Winner->Visible = true;
        Results->Caption = "WYNIK: "+IntToStr(left_points)+":"+IntToStr(right_points);
        Results->Visible = true;
        newGame->Left = 824;
        newGame->Visible = true;
        newRound->Left = 516;
        newRound->Visible = true;
        Form1->BorderStyle = bsSizeable;
    }
    //ball hit
    else if (Ball->Top > LeftPaddle->Top - Ball->Height/2 &&
            Ball->Top < LeftPaddle->Top + LeftPaddle->Height - Ball->Height/2 &&
            Ball->Left < LeftPaddle->Left + LeftPaddle->Width)
    {
        if (x < 0)
        {
            x = -x;
            pickups++;
            if (pickups%5 == 0)
            {
                x++;
                if (y < 0)
                {
                    y--;
                }
                else
                {
                    y++;
                }
            }
        }
        //acceleration
        if (Ball->Top > LeftPaddle->Top + LeftPaddle->Height/3 - Ball->Height/2 &&
            Ball->Top < LeftPaddle->Top + 2*LeftPaddle->Height/3 - Ball->Height/2)
        {
            x += 1.5*x;
        }
    }
    //loss
    if (Ball->Left + Ball->Width >= Background->Width)
    {
        left_points++;
        BallTimer->Enabled = false;
        Ball->Visible = false;
        Winner->Caption = "PUNKT DLA LEWEJ STRONY >";
        Winner->Visible = true;
        Results->Caption = "WYNIK: "+IntToStr(left_points)+":"+IntToStr(right_points);
        Results->Visible = true;
        newGame->Left = 824;
        newGame->Visible = true;
        newRound->Left = 516;
        newRound->Visible = true;
        Form1->BorderStyle = bsSizeable;
    }
    //pickup
    else if (Ball->Top > RightPaddle->Top - Ball->Height/2 &&
            Ball->Top < RightPaddle->Top + RightPaddle->Height - Ball->Height/2 &&
            Ball->Left + Ball->Width > RightPaddle->Left)
    {
        if (x > 0)
        {
            x = -x;
            pickups++;
            if (pickups%5 == 0)
            {
                x--;
                if (y < 0)
                {
                    y--;
                }
                else
                {
                    y++;
                }
            }
        }
        //acceleration
        if (Ball->Top > RightPaddle->Top + RightPaddle->Height/3 - Ball->Height/2 &&
            Ball->Top < RightPaddle->Top + 2*RightPaddle->Height/3 - Ball->Height/2)
        {
            x = 1.5*x;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LeftPaddleUpTimer(TObject *Sender)
{
    if (LeftPaddle->Top > 10)
    {
        LeftPaddle->Top -= 10;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LeftPaddleDownTimer(TObject *Sender)
{
    if (LeftPaddle->Top + LeftPaddle->Height < Background->Height - 10)
    {
        LeftPaddle->Top += 10;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if ((Key == 'a') || (Key == 'A'))
    {
        LeftPaddleUp->Enabled = true;
    }

    if ((Key == 'z') || (Key == 'Z'))
    {
        LeftPaddleDown->Enabled = true;
    }

    if (Key == VK_UP)
    {
        RightPaddleUp->Enabled = true;
    }

    if (Key == VK_DOWN)
    {
        RightPaddleDown->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if ((Key == 'a') || (Key == 'A'))
    {
        LeftPaddleUp->Enabled = false;
    }

    if ((Key == 'z') || (Key == 'Z'))
    {
        LeftPaddleDown->Enabled = false;
    }

    if (Key == VK_UP)
    {
        RightPaddleUp->Enabled = false;
    }

    if (Key == VK_DOWN)
    {
        RightPaddleDown->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightPaddleUpTimer(TObject *Sender)
{
    if (RightPaddle->Top > 10)
    {
        RightPaddle->Top -= 10;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightPaddleDownTimer(TObject *Sender)
{
    if (RightPaddle->Top + RightPaddle->Height < Background->Height - 10)
    {
        RightPaddle->Top += 10;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	ShowMessage("Zapraszam na partyjke Ping-Ponga.\n\n Lewy gracz steruje klawiszami A oraz Z. Prawy gracz steruje strzalkami.\n Nowa gre rozpocznij klikajac przycisk newGame.\n");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameClick(TObject *Sender)
{
    x = -4;
    y = -4;
    pickups = 0;
    right_points = 0;
    left_points = 0;
    Ball->Visible = true;
    newGame->Visible = false;
    newRound->Visible = false;
    Winner->Visible = false;
    Results->Visible = false;
    LeftPaddle->Left = Background->Left + 20;
    RightPaddle->Left = Background->Width - 20 - RightPaddle->Width;
    Ball->Left = Background->Width/2;
    Ball->Top = Background->Height/2;
    LeftPaddle->Top = Background->Height/2 - LeftPaddle->Height/2;
    RightPaddle->Top = Background->Height/2 - RightPaddle->Height/2;
    BallTimer->Enabled = true;
    Form1->BorderStyle = bsDialog;
}
void __fastcall TForm1::newRoundClick(TObject *Sender)
{
    x = -4;
    y = -4;
    pickups = 0;
    Ball->Visible = true;
    newGame->Visible = false;
    newRound->Visible = false;
    Winner->Visible = false;
    Results->Visible = false;
    LeftPaddle->Left = Background->Left + 20;
    RightPaddle->Left = Background->Width - 20 - RightPaddle->Width;
    Ball->Left = Background->Width/2;
    Ball->Top = Background->Height/2;
    LeftPaddle->Top = Background->Height/2 - LeftPaddle->Height/2;
    RightPaddle->Top = Background->Height/2 - RightPaddle->Height/2;
    BallTimer->Enabled = true;
    Form1->BorderStyle = bsDialog;
}
