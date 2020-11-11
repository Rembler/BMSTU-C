object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Main menu'
  ClientHeight = 304
  ClientWidth = 273
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 271
    Width = 100
    Height = 25
    Caption = 'Add'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 166
    Top = 271
    Width = 100
    Height = 25
    Caption = 'Delete'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 8
    Width = 120
    Height = 70
    Caption = 'Show names and numbers of all semiconductors'
    TabOrder = 2
    WordWrap = True
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 146
    Top = 8
    Width = 120
    Height = 70
    Caption = 
      'Show info about all conductors in increasing order of atomic wei' +
      'ght'
    TabOrder = 3
    WordWrap = True
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 96
    Width = 120
    Height = 70
    Caption = 
      'Show names of all insulators whose atomic weight does not exceed' +
      ' this value'
    TabOrder = 4
    WordWrap = True
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 146
    Top = 96
    Width = 120
    Height = 70
    Caption = 'Show relation between atomic weight and number of element'
    TabOrder = 5
    WordWrap = True
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 75
    Top = 184
    Width = 120
    Height = 70
    Caption = 'Show info about all elements'
    TabOrder = 6
    WordWrap = True
    OnClick = Button7Click
  end
end
