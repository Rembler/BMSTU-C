program Mendel;

uses
  Forms,
  Mz in 'Mz.pas' {Form1},
  Addit in 'Addit.pas' {Form2},
  Del in 'Del.pas' {Form3},
  SemiCon in 'SemiCon.pas' {Form4},
  Cond in 'Cond.pas' {Form5},
  Ins in 'Ins.pas' {Form6},
  Graph in 'Graph.pas' {Form7},
  All in 'All.pas' {Form8};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TForm2, Form2);
  Application.CreateForm(TForm3, Form3);
  Application.CreateForm(TForm4, Form4);
  Application.CreateForm(TForm5, Form5);
  Application.CreateForm(TForm6, Form6);
  Application.CreateForm(TForm7, Form7);
  Application.CreateForm(TForm8, Form8);
  Application.Run;
end.
