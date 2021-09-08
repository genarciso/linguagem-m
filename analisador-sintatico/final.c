#include <stdlib.h>
#include <stdio.h>

int x = 1;
int y = 0;
int main(int x) {
	int i = 0;
loopStart0:
	if(!(i < 10)) {
		goto loopEnd0;
	}
	{
	if(x == i || y == i){
	printf("equal\n");
} 
else{
	printf("not\n");
}
}
	i = i + 1;
	goto loopStart0;
loopEnd0:;

}
double s;
float t(int d) {
	printf("asd");
}
float f(d) {
	int a;
loopStart1: if(!(a < 10)) {
	goto loopEnd1;
}
	{
	printf(a);
a = a + 1;
}
	goto loopStart1;
loopEnd1:;

}






