unit Graph;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, Del, StdCtrls;

type
  TForm7 = class(TForm)
    Image1: TImage;
    Label1: TLabel;
    Label2: TLabel;
    procedure FormShow(Sender: TObject);
    procedure FormHide(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form7: TForm7;

implementation

{$R *.dfm}

var res1:array of tlabel;
    res2:array of tlabel;
    mem:integer;

procedure TForm7.FormHide(Sender: TObject);
var i:integer;
begin
  image1.Canvas.Brush.Color := ClWhite;
  image1.Canvas.FillRect(Canvas.ClipRect);
  for i := 0 to mem-1 do
  begin
    res1[i].Caption:='';
    res1[i].Free;
    res2[i].Caption:='';
    res2[i].Free;
  end;
end;

procedure TForm7.FormShow(Sender: TObject);
var sor:array of elem;
    i,j:integer;
    b:elem;
    m:boolean;
begin
  mem:=filesize(men);
  with image1.Canvas do
  begin
    pen.Color:=clblack;
    moveto(4,4);
    lineto(0,0);
    lineto(0,299);
    lineto(943,299);
    lineto(939,295);
  end;
  seek(men,0);
  setlength(sor,mem);
  for i := 0 to mem - 1 do
    read(men,sor[i]);
  i:=0;
  m:=true;
  while (i<=mem-2) and (m=true) do
  begin
    m:=false;
    for j := 0 to mem-i-2 do
      if (sor[j].num>sor[j+1].num) then
      begin
        b:=sor[j];
        sor[j]:=sor[j+1];
        sor[j+1]:=b;
        m:=true;
      end;       
  end;
  if (mem>0) then
  begin
    setlength(res1,mem);
    setlength(res2,mem);
    image1.Canvas.pen.color:=clred;
    image1.canvas.Pen.Width:=2;
    image1.Canvas.moveto(sor[0].num*8,299-round(sor[0].wei));
    for i := 0 to mem-1 do
    begin
      res1[i]:=tlabel.create(form7);
      with res1[i] do
      begin
        parent:=form7;
        top:=325;
        left:=sor[i].num*8+26;
        caption:=inttostr(sor[i].num);
      end;
      res2[i]:=tlabel.create(form7);
      with res2[i] do
      begin
        parent:=form7;
        top:=299-round(sor[i].wei)+18;
        left:=8;
        caption:=inttostr(round(sor[i].wei));
      end;
      with image1.canvas do
      begin
        lineto(sor[i].num*8,299-round(sor[i].wei));
        Pen.Color:=clgray;
        Pen.Width:=1;
        LineTo(sor[i].num*8,299);
        MoveTo(sor[i].num*8,299-round(sor[i].wei));
        lineto(0,299-round(sor[i].wei));
        MoveTo(sor[i].num*8,299-round(sor[i].wei));
        Pen.Color:=clred;
        Pen.Width:=2;
      end;
    end;
  end;
end;

end.
