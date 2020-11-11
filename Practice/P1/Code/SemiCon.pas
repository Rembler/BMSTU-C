unit SemiCon;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Del;

type
  TForm4 = class(TForm)
    procedure FormShow(Sender: TObject);
    procedure FormHide(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form4: TForm4;

implementation

{$R *.dfm}

var res:array of tlabel;

procedure TForm4.FormHide(Sender: TObject);
var i:integer;
begin
  for i := 0 to filesize(men)-1 do
    if (res[i].caption<>'') then
      res[i].caption:='';
end;

procedure TForm4.FormShow(Sender: TObject);
var cur:elem;
    i,x:integer;
begin
  setlength(res,filesize(men));
  seek(men,0);
  i:=0;
  x:=10;
  while (not eof(men)) do
  begin
    read(men,cur);
    if (cur.con='Semiconductor') then
    begin
      res[i]:=tlabel.Create(form4);
      with res[i] do
      begin
        parent:=form4;
        Top:=x;
        Left:=10;
        caption:='Name: '+cur.name+' | Atomic weight: '+floattostr(cur.wei);
      end;
      x:=x+20;
      inc(i);
    end;
  end;
end;

end.
