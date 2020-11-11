unit Mz;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Addit, Del, SemiCon, Cond, Ins, Graph, All, XpMan;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
begin
  form2.visible:=true;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  form3.visible:=true;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  form4.visible:=true;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  form5.visible:=true;
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
  form6.visible:=true;
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
  form7.Visible:=true;
end;

procedure TForm1.Button7Click(Sender: TObject);
begin
  form8.visible:=true;
end;

procedure TForm1.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  closefile(men);
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  assignfile(men,'YAY.pas');
  reset(men);
end;

end.
