program Drawing;

uses
  Forms,
  MainForm in 'MainForm.pas' {Form1},
  Storage in 'Storage.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
