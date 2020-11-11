unit Storage;

interface

uses ExtCtrls, Graphics;

type figure=object
  xs,ys,xe,ye:integer;
  can:timage;
  procedure sinit(x,y:integer;ic:timage);
  procedure einit(x,y:integer);
end;

line=object(figure)
  procedure drawline(col:tcolor);
end;

ellipse=object(figure)
  procedure drawellipse(col:tcolor);
end;

var figl:line;
    fige:ellipse;

implementation

procedure figure.sinit(x: Integer; y: Integer; ic: TImage);
begin
  xs:=x;
  ys:=y;
  can:=ic;
end;

procedure figure.einit(x: Integer; y: Integer);
begin
  xe:=x;
  ye:=y;
end;

procedure line.drawline(col: TColor);
begin
  with can.Canvas do
  begin
    pen.color:=col;
    moveto(xs,ys);
    lineto(xe,ye);
  end;
end;

procedure ellipse.drawellipse(col: TColor);
begin
  with can.Canvas do
  begin
    pen.color:=col;
    ellipse(xs,ys,xe,ye);
  end;
end;

end.
