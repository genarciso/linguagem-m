#include <stdlib.h>
#include <stdio.h>

int main() {

{
int i = 0;
loopStart0: if(!(i < 10)) goto loopEnd0;
{
int g;
printf("%d\n", i);
}
i = i + 1;
goto loopStart0;
loopEnd0:;
}
;
int j = 0;

{
loopStart2: if(!(j < 2)) goto loopEnd2;
{
int x;
printf("2\n");

{
int i = 5;
loopStart1: if(!(i < 10)) goto loopEnd1;
{
int g;
printf("%d\n", i);
}
i++;
goto loopStart1;
loopEnd1:;
}
;
j++;
}
goto loopStart2;
loopEnd2:;
}
;
int i = 0;

{
loopStart3:
{
int x;
printf("4\n");
i++;
}
if(i < 3) goto loopStart3;
}
;
}