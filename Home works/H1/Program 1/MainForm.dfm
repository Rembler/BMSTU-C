object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Graphics editor'
  ClientHeight = 273
  ClientWidth = 320
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 24
    Top = 24
    Width = 273
    Height = 185
    OnMouseDown = Image1MouseDown
    OnMouseUp = Image1MouseUp
  end
  object ColorBox1: TColorBox
    Left = 96
    Top = 232
    Width = 145
    Height = 22
    ItemHeight = 16
    TabOrder = 0
  end
end
