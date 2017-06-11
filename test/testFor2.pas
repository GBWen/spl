{
  block comment
  multi line supporting
}
// one line comment
program test;

var

  A, B : integer;

procedure testfor;
var
  i, k, j : integer;

  procedure MyProcedure;
  begin
    k := 0;
    for i := A to B do
      k := k + 1;
    writeln(k);
    exit(0);
  end;

begin
  MyProcedure;
  exit(0);
end;

begin
  A := 1;
  B := 10;
  testforrr;
  if A >= 3 then
    writeln(A)
  else
    writeln(B);

end.
