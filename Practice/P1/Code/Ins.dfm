object Form6: TForm6
  Left = 0
  Top = 0
  Caption = 'Insulators'
  ClientHeight = 231
  ClientWidth = 505
  Color = clWindow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnHide = FormHide
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 13
    Width = 177
    Height = 13
    Caption = 'Enter the desired atomic weight here'
  end
  object Edit1: TEdit
    Left = 16
    Top = 40
    Width = 185
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 232
    Top = 38
    Width = 100
    Height = 25
    Caption = 'Show names'
    TabOrder = 1
    OnClick = Button1Click
  end
end
