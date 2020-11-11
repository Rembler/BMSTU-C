program Moving;

uses
  Forms,
  FigStor in 'FigStor.pas',
  Main in 'Main.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
