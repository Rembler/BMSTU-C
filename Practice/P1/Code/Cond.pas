unit Cond;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Del;

type
  TForm5 = class(TForm)
    procedure FormShow(Sender: TObject);
    procedure FormHide(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form5: TForm5;

implementation

{$R *.dfm}

var res:array of tlabel;

procedure TForm5.FormHide(Sender: TObject);
var i:integer;
begin
  for i := 0 to filesize(men)-1 do
    if (res[i].caption<>'') then
      res[i].caption:='';
end;

procedure TForm5.FormShow(Sender: TObject);
var sor:array of elem;
    i,j,x:integer;
    m:boolean;
    b:elem;
begin
  seek(men,0);
  setlength(sor,filesize(men));
  for i := 0 to filesize(men)-1 do
    read(men,sor[i]);
  i:=0;
  m:=true;
  while (i<=filesize(men)-2) and (m=true) do
  begin
    m:=false;
    for j := 0 to filesize(men)-i-2 do
      if (sor[j].wei>sor[j+1].wei) then
      begin
        b:=sor[j];
        sor[j]:=sor[j+1];
        sor[j+1]:=b;
        m:=true;
      end;       
  end;
  setlength(res,filesize(men));
  x:=10;
  for i := 0 to filesize(men)-1 do
    if (sor[i].con='Conductor') then
    begin
      res[i]:=tlabel.Create(form5);
      with res[i] do
      begin
        parent:=form5;
        Top:=x;
        Left:=10;
        caption:='Name: '+sor[i].name+' | Number: '+inttostr(sor[i].num);
        caption:=caption+' | Atomic weight: '+floattostr(sor[i].wei);
      end;
      x:=x+20;
    end;
end;

end.
