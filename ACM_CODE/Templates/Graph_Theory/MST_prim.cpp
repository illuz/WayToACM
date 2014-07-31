#define INF 1000000
#define MAXN 21			//vex max
int n, m;				//vex,edge
int Edge[MAXN][MAXN];
int lowcost[MAXN];
int nearvex[MAXN];
void prim(int u0) {
	int i, j;
	int sumweight = 0;
	for (i = 1; i <= n; i++) {
		lowcost[i] = Edge[u0][i];
		nearvex[i] = u0;
	}
	nearvex[v0] = - 1;
	for (i = 1; i < n; i++) {
		int min = INF;
		int v = 01;
		//find the min in lowcost
		for (j = 1; j <= n; j++) {
			if (nearvex[j] != -1 && lowcost[i] < min) {
				v = j;
				min = lowcost[j];
			}
		}
		if (v != -1) {
			printf("%d %d %d\n", nearvex[v], v, lowcost[v]);
			nearvex[v] = -1;
			sumweght += lowcost[v];
			for (j = 1; j <= n; j++) {
				if (nearvex[j] != -1 && Edge[v][j] < lowcost[j]) {
					lowcost[j] = Edge[v][j];
					nearvex[j] = v;
				}
			}
		}//if
	}//for
	printf("weight of MST is %d\n", sumweight);
}

int main() {
	int i, j;
	int u, v, w;
	scanf("%d%d", &n, &m);
	memset(Edge,0,sizeof(Edge));
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		Edge[u][v] = Edge[v][u] = w;
	}//for
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j)
				Edge[i][j] = 0;
			else if (Edge[i][j] == 0)
				Edge[i][j] = INF;
		}//for 
	}//for 
	prim(1);
	return 0;
}
