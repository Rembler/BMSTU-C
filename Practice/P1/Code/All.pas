unit All;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Del, StdCtrls;

type
  TForm8 = class(TForm)
    procedure FormShow(Sender: TObject);
    procedure FormHide(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form8: TForm8;

implementation

{$R *.dfm}

var res:array of tlabel;
    siz:integer;

procedure TForm8.FormHide(Sender: TObject);
var i:integer;
begin
  for i := 0 to siz-1 do
  begin
    res[i].caption:='';
    res[i].Free;
  end;
end;

procedure TForm8.FormShow(Sender: TObject);
var sor:array of elem;
    i,x:integer;
begin
  seek(men,0);
  siz:=filesize(men);
  setlength(sor,siz);
  setlength(res,siz);
  x:=10;
  for i := 0 to siz-1 do
  begin
    read(men,sor[i]);
    res[i]:=tlabel.Create(form8);
    with res[i] do
    begin
      parent:=form8;
      top:=x;
      left:=10;
      caption:='Number: '+inttostr(sor[i].num)+' | Name: '+sor[i].name;
      caption:=caption+' | Conduction: '+(sor[i].con);
      caption:=caption+' | Atomic weight: '+floattostr(sor[i].wei);
    end;
    x:=x+20;
  end;
end;

end.
