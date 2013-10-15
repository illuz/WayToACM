
#include <cstdio>
#include <cstring>

double solve(char o) {
	char op[10];
	double o1, o2;
	scanf("%s", op);
	if (op[0] >= '0' && op[0] <= '9')
		sscanf(op, "%lf", &o1);
	else 
		o1 = solve(op[0]);
	scanf("%s", op);
	if (op[0] >= '0' && op[0] <= '9')
		sscanf(op, "%lf", &o2);
	else 
		o2 = solve(op[0]);
	switch(o) {
		case '+': return o1 + o2;
		case '-': return o1 - o2;
		case '*': return o1 * o2;
		case '/': return o1 / o2;
	}
}

int main() {
	char op[5];

	while (scanf("%s", op) != EOF) {
		printf("%.2lf\n", solve(op[0]));
	}
	return 0;
}        
