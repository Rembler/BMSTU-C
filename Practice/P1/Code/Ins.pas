unit Ins;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Del, StdCtrls;

type
  TForm6 = class(TForm)
    Edit1: TEdit;
    Button1: TButton;
    Label1: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure FormHide(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form6: TForm6;

implementation

{$R *.dfm}

var res:array of tlabel;
    i:integer;

procedure TForm6.Button1Click(Sender: TObject);
var x:integer;
    cur:elem;
begin
  if (edit1.Text<>'') and (check2(edit1.text,length(edit1.text))=true) then
  begin
    setlength(res,filesize(men));
    for i := 0 to i-1 do
    begin
      res[i].Caption:='';
      res[i].Free;
    end;
    i:=0;
    x:=70;
    seek(men,0);
    while (not eof(men)) do
    begin
      read(men,cur);
      if (cur.con='Insulator') and (cur.wei<=strtofloat(edit1.text)) then
      begin
        res[i]:=tlabel.create(form6);
        with res[i] do
        begin
          parent:=form6;
          top:=x;
          left:=10;
          caption:='Name: '+cur.name;
        end;
        x:=x+20;
        inc(i);
      end;
    end;
  end
  else
  edit1.text:='ERROR';
end;

procedure TForm6.FormHide(Sender: TObject);
begin
  setlength(res,filesize(men));
  for i := 0 to i-1 do
  begin
      res[i].Caption:='';
      res[i].free;
  end;
  edit1.Text:='';
end;

end.