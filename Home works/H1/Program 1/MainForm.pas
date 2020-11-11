unit MainForm;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls, Storage;

type
  TForm1 = class(TForm)
    Image1: TImage;
    ColorBox1: TColorBox;
    procedure Image1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Image1MouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);
begin
  with image1.Canvas do
  begin
    pen.color:=clblack;
    rectangle(0,0,272,184);
  end;
end;

procedure TForm1.Image1MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if (button=mbright) then
    figl.sinit(x,y,image1)
  else
    fige.sinit(x,y,image1);
end;

procedure TForm1.Image1MouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if (button=mbright) then
  begin
    figl.einit(x,y);
    figl.drawline(colorbox1.Selected);
  end
  else
  begin
    fige.einit(x,y);
    fige.drawellipse(colorbox1.Selected);
  end
end;

end.
