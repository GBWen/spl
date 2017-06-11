program testFunc;
var
	C : integer;
function mintest(A, B:integer):integer;
begin
if A > B then
	exit(B)
else
	exit(A);
end;

begin
	C := mintest(10, 20);
	writeln(C);
end.
