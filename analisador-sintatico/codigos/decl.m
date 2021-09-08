double x = 1;
int y = 0;

float t(int d, int f) {
	float f = 2 ** 3 + 10 ** 3;
}

double d;

int t2() {
	double f = 2 ** 3.2 + 10 ** 3;
}

double s;

int main(int x) {
	for(int i = 0; i < 10; i = i+1) {
		if(x == i || y == i){
			printf("equal\n");
		}else {
			printf("not\n");
		}
	}

	x = 1.1f;

	t2();
	t(1+1, y);
}

