unit Del;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TForm3 = class(TForm)
    Label2: TLabel;
    Edit2: TEdit;
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

type elem = record
  name:string[15];
  num:integer;
  wei:real;
  con:string[15];
end;

var
  Form3: TForm3;
  men: file of elem;

function check2(obj:openstring;len:integer):boolean;

function check1(obj:openstring;len:integer):boolean;

implementation

{$R *.dfm}

function check2(obj:openstring;len:integer):boolean;
var i:integer;
begin
  result:=true;
  for i := 1 to len do
    if ((ord(obj[i])<48) and (ord(obj[i])<>44)) or (ord(obj[i])>57) then
      result:=false;
end;

function check1(obj:openstring;len:integer):boolean;
var i:integer;
begin
  result:=true;
  for i := 1 to len do
    if (ord(obj[i])<48) or (ord(obj[i])>57) then
      result:=false;
  if (obj[1]='0') then
    result:=false;
end;

procedure TForm3.Button1Click(Sender: TObject);
var key:boolean;
    sel:elem;
    pde:integer;
begin
  seek(men,0);
  key:=false;
  if (edit2.Text<>'') then
  begin
    while (not eof(men)) and (key=false) do
    begin
      read(men,sel);
      if (sel.name=edit2.Text) then
        key:=true;
    end;
    if (key=true) then
    begin
      pde:=filepos(men)-1;
      while (not eof(men)) do
      begin
        read(men,sel);
        seek(men,pde);
        write(men,sel);
        pde:=filepos(men);
        seek(men,filepos(men)+1);
      end;
      seek(men,filepos(men)-1);
      truncate(men);
      edit2.Text:='';
    end;
  end;
end;

end.
