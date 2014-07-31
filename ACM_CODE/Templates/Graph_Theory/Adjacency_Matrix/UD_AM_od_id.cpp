#define MAXN 100
int Edge[MAXN][MAXN];	//martrix
int main()
{
	int i, j;	//cycle
	int n, m;	//vertext edge
	int u, v;	//start, end
	int od, id;	//out_degree, in_degree
	while (1)
	{
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0)	break;
		memset(Edge, 0, sizeof(Edge));
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &u, &v);
			Edge[u - 1][v - 1] = 1;	//build
		}
//-------------------------------------------------
//the out_degree of i-th vertext
		od = 0;
		for(j = 0; j < n; j++)	//accumulate i-th row
			od += Edge[i][j];
		
//-------------------------------------------------
//the in_degree of i-th vertext
		id = 0;
		for(j = 0; j < n; j++)
			id += Edge[j][i];	//accumulate i-th col
	}
	return 0;
}
