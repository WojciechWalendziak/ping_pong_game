object Form1: TForm1
  Left = 301
  Top = 109
  Width = 1161
  Height = 729
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormCreate
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 13
  object Background: TShape
    Left = 32
    Top = 16
    Width = 1089
    Height = 545
  end
  object LeftPaddle: TShape
    Left = 128
    Top = 128
    Width = 33
    Height = 150
  end
  object RightPaddle: TShape
    Left = 992
    Top = 136
    Width = 33
    Height = 150
  end
  object Ball: TShape
    Left = 568
    Top = 216
    Width = 33
    Height = 41
    Shape = stCircle
  end
  object newGame: TButton
    Left = 824
    Top = 592
    Width = 161
    Height = 33
    Caption = 'newGame'
    TabOrder = 0
    OnClick = newGameClick
  end
  object newRound: TButton
    Left = 516
    Top = 592
    Width = 129
    Height = 33
    Caption = 'newRound'
    TabOrder = 1
    OnClick = newRoundClick
  end
  object Winner: TStaticText
    Left = 98
    Top = 465
    Width = 279
    Height = 41
    Caption = 'Winner'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -33
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object Results: TStaticText
    Left = 792
    Top = 464
    Width = 265
    Height = 49
    Caption = 'Results'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object BallTimer: TTimer
    Interval = 50
    OnTimer = BallTimerTimer
    Left = 120
    Top = 592
  end
  object LeftPaddleUp: TTimer
    Interval = 10
    OnTimer = LeftPaddleUpTimer
    Left = 176
    Top = 592
  end
  object LeftPaddleDown: TTimer
    Interval = 10
    OnTimer = LeftPaddleDownTimer
    Left = 232
    Top = 592
  end
  object RightPaddleDown: TTimer
    Interval = 10
    OnTimer = RightPaddleDownTimer
    Left = 288
    Top = 592
  end
  object RightPaddleUp: TTimer
    Interval = 10
    OnTimer = RightPaddleUpTimer
    Left = 344
    Top = 592
  end
end
