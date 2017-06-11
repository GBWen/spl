{
  block comment
  multi line supporting
}
// one line comment
program test;
label 1001;
label 122;
const
  AA = 123;
type
  UpperCase = 'A'..'Z';
  OverHundred = 100..1000;

  // another comment

  DayTemperatures = array {inner comment} [ 1 .. 24] of integer;
  testArrayRange = array [OverHundred] of integer;
  testArrayRange2 = array [integer] of integer;
  MonthTemps = array [ 1 .. 31] of DayTemperatures;

  Date = record
    Month : integer;
    Day : integer;
    Year : integer;
  end;

  Diary = record
    writeDownDate : Date;
    title, content : string;
  end;

  DiaryBook = record
    content : array [1..31] of Date;
    buyDate : Date;
    author : string;
  end;

var
  UppLetter : UpperCase;
  ThisMonth : MonthTemps;
  BirthDay  : Date;

  A, B, C : integer;
  D, E, F : real;
  G, H : char;
  J, K, L : boolean;

  txt : string;

  twoDimention : array [1..5] of array[1..5] of integer;

procedure testwhile(A, B: integer);
const
  C = 123;
begin
  while A < C do
    B := pred(B);
  writeln(B);
end;

procedure testfor(A, B: integer);
var
  i, k, j : integer;

  procedure MyProcedure;
  begin
    read(k);
  end;

begin
  k := 0;
  MyProcedure;
  for i := A to B do
    for j := B downto A do
      k := succ(k);
  writeln(k);
end;

function testrepeat(var A: integer):real;
var
  count : real;
begin
  count := 0;
  repeat
    count := count + 0.5;
    count := count - 5e-3;
    count := count * -0.6;
    A := pred(A);
  until (A <= 0);
  exit(count);
end;

begin

  read(A);
  B := A;
  write(B);

  A := maxint;

  D := 1E5;

  E := -1e+5;

  F := +0.005;

  A := +0;

  A := - - - - - - - -1;

  UppLetter := 'E';
  ThisMonth[2,1] := 30;
  ThisMonth[1] := ThisMonth[2];

  BirthDay.Year := 1900;
  BirthDay.Month := 1;
  BirthDay.Day := 1;

1001:
  A := BirthDay.Year;
  C := B;

122:
  C := A * 2;

  if A >= B then
  begin
    C := A * 3;
  end;

  if A < C then
    B := C
  else
    B := A;

  D := E;
  E := F;
  F := testrepeat(A);

  testfor(A, 42);
  testwhile(A, 123 div 41 * 5);

{
  A, B, C : integer;
  D, E, F : real;
  G, H, I : char;
  J, K, L : boolean;
  to test all the token is checked in lex
}
  G := 'C';
  A := ord(G);
  B := succ(pred(succ(A)));
  H := chr(B);
  write(G);
  writeln(H);

  J := odd(abs(-B));
  K := not not not not not not odd(B shl 2 shr 1 mod 3);
  L := J and K or J xor K;

  A := 90 * B - maxint div 3;
  D := A / 5.3e-2 + 6 - 8E1;

  J := (D >= A) or (A > B);
  K := (C <= A) or (C < B);
  L := (D = A) and (A <> B) and L;
  L := true and false or true and J;

  twoDimention[2, 2] := 1;
  twoDimention[2, 3] := twoDimention[2, 2];

  txt := '{this is not a comment}';

  UppLetter := succ(UppLetter);

  case A of
    1: txt := 'One';
    2: txt := 'Two';
    3: txt := 'Three';
    4: goto 1001;
    5: goto 122;
  end;

end.
