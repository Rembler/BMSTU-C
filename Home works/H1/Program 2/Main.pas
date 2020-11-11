unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, FigStor;

type
  TForm1 = class(TForm)
    Image1: TImage;
    Timer1: TTimer;
    Image3: TImage;
    Timer2: TTimer;
    Image2: TImage;
    Timer3: TTimer;
    procedure Timer1Timer(Sender: TObject);
    procedure Timer2Timer(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Timer3Timer(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

var cir:circle;
    squ:square;
    arc:archi;
    t1:real=0;
    t2:real=0;
    t3:real=0;

procedure TForm1.FormCreate(Sender: TObject);
begin
  squ.init(image1);
  cir.init(image2);
  arc.init(image3);
end;

procedure TForm1.Timer1Timer(Sender: TObject);
begin
  squ.draw(t1);
  t1:=t1+0.1;
  if (t1>=2*pi) then
    t1:=0;
end;

procedure TForm1.Timer2Timer(Sender: TObject);
begin
  arc.draw(t2);
  t2:=t2+0.1;
  if (t2>=2*pi) then
    t2:=0;
end;

procedure TForm1.Timer3Timer(Sender: TObject);
begin
  cir.draw(t3);
  t3:=t3+0.1;
  if (t3>=2*pi) then
    t3:=0;
end;

end.
