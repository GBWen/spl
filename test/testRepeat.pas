program testRepeat;
var
	A,B,C : integer;

begin
	A := 100;
	repeat
		B := B + 0.5;
	until (B = A);
end.
