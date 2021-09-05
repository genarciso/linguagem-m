#include <stdlib.h>
#include <stdio.h>

int main() {
int x = 1;
int y = 2;

{
if(!(x == y)) goto endIf3;
{
printf("1\n");
}
goto endAllIf0;
 endIf3:;

{
if(!(x > y)) goto endIf0;
{
printf("2\n");
}
goto endAllIf0;
 endIf0:;
}


{
if(!(x < 0)) goto endIf1;
{
printf("3\n");
}
goto endAllIf0;
 endIf1:;
}



nextIf2: if(0) goto endIf2;
{
printf("4\n");
}
endIf2:;


endAllIf0:;
}


{
if(!(x == y)) goto endIf7;
{
printf("1\n");
}
goto endAllIf1;
 endIf7:;

{
if(!(x < y)) goto endIf4;
{
printf("22\n");
}
goto endAllIf1;
 endIf4:;
}


{
if(!(x < 0)) goto endIf5;
{
printf("3\n");
}
goto endAllIf1;
 endIf5:;
}



nextIf6: if(0) goto endIf6;
{
printf("4\n");
}
endIf6:;


endAllIf1:;
}
;
}