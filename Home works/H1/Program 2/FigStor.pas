unit FigStor;

interface

uses extctrls, graphics;

type fig=object
  cnv:timage;
  procedure init(icn:timage);
  procedure draw(n:real);
end;

square=object(fig)
  procedure draw(n:real);
end;

circle=object(fig)
  procedure draw(n:real);
end;

archi=object(fig)
  procedure draw(n:real);
end;

implementation

procedure fig.init(icn: TImage);
begin
  cnv:=icn;
end;

procedure fig.draw(n: Real);
begin
  //abstract
end;

procedure square.draw;
var a:array [0..3,1..2] of integer;
    i:integer;
begin
  for i := 0 to 3 do
  begin
    a[i,1]:=50+round(30*cos(n+i*pi/2));
    a[i,2]:=50+round(30*sin(n+i*pi/2));
  end;
  with cnv.Canvas do
  begin
    pen.color:=clwhite;
    brush.Color:=clwhite;
    rectangle(0,0,100,100);
    pen.color:=clred;
    moveto(a[3,1],a[3,2]);
    for i := 0 to 3 do
      lineto(a[i,1],a[i,2]);
  end;
end;

procedure circle.draw(n: Real);
var c:array[1..2,1..2] of integer;
    i:integer;
begin
  for i := 1 to 2 do
  begin
    c[i,1]:=50-round(30*cos(n-(i-1)*3*pi/2));
    c[i,2]:=50+round(30*sin(n-(i-1)*3*pi/2));
  end;
  with cnv.canvas do
  begin
    pen.color:=clwhite;
    brush.color:=clwhite;
    rectangle(0,0,99,99);
    pen.color:=clgreen;
    pie(20,20,80,80,c[2,1],c[2,2],c[1,1],c[1,2]);
  end;
end;

procedure archi.draw(n: Real);
var b:array [1..6,1..6] of integer;
    i:integer;
begin
  b[1,1]:=50;
  b[1,2]:=50;
  b[5,1]:=50;
  b[5,2]:=50;
  for i := 2 to 4 do
  begin
    if (i=3) then
    begin
      b[i,1]:=50+round(sqrt(50)*cos(n-(i-2)*pi/4));
      b[i,2]:=50+round(sqrt(50)*sin(n-(i-2)*pi/4));
    end
    else
    begin
      b[i,1]:=50+round(5*cos(n-(i-2)*pi/4));
      b[i,2]:=50+round(5*sin(n-(i-2)*pi/4));
    end;
  end;
  b[6,1]:=b[2,1];
  b[6,2]:=b[2,2];
  for i := 1 to 6 do
  begin
    b[i,3]:=b[i,1]+round(i*5*cos(n+(2*pi-i*pi/2)));
    b[i,4]:=b[i,2]+round(i*5*sin(n+(2*pi-i*pi/2)));
    b[i,5]:=b[i,1]+round(i*5*cos(n+(3*pi/2-(i mod 4)*pi/2)));
    b[i,6]:=b[i,2]+round(i*5*sin(n+(3*pi/2-(i mod 4)*pi/2)));
  end;
  with cnv.Canvas do
  begin
    pen.color:=clwhite;
    brush.color:=clwhite;
    rectangle(0,0,100,100);
    pen.Color:=clblue;
    for i := 1 to 6 do
      arc(b[i,1]-5*i,b[i,2]-5*i,b[i,1]+5*i,b[i,2]+5*i,b[i,3],b[i,4],b[i,5],b[i,6]);
  end;
end;

end.
