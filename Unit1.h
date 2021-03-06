//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Background;
        TShape *LeftPaddle;
        TShape *RightPaddle;
        TTimer *BallTimer;
        TTimer *LeftPaddleUp;
        TTimer *LeftPaddleDown;
        TTimer *RightPaddleDown;
        TTimer *RightPaddleUp;
        TButton *newGame;
        TButton *newRound;
        TStaticText *Winner;
        TStaticText *Results;
        TImage *Ball;
        void __fastcall BallTimerTimer(TObject *Sender);
        void __fastcall LeftPaddleDownTimer(TObject *Sender);
        void __fastcall LeftPaddleUpTimer(TObject *Sender);
        void __fastcall RightPaddleDownTimer(TObject *Sender);
        void __fastcall RightPaddleUpTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift);
      void __fastcall newGameClick(TObject *Sender);
      void __fastcall FormCreate(TObject *Sender);
        void __fastcall newRoundClick(TObject *Sender);
        //void __fastcall BackgroundContextPopup(TObject *Sender,
          //TPoint &MousePos, bool &Handled);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
