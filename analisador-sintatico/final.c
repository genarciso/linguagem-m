#include <stdlib.h>
#include <stdio.h>

int main() {
int x = 1;
int y = 0;

{
int i = 0;;
loopStart0: if(!(i < 10)) goto loopEnd0;
{

{
if(!(x == i || y == i)) goto endIf1;
{
printf("equal\n");
}
goto endAllIf0;
endIf1:;

if(0) goto endIf0;
{
printf("not\n");
}
endIf0:;


endAllIf0:;
}
;
}
i = i + 1;
goto loopStart0;
loopEnd0:;
}
;
}