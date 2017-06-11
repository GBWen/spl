program testGoto;
label 100;
var
	A,B,C : integer;

begin
	goto 100;
	write("123");
	100:
		writeln(1);
end.
