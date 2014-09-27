#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define N 500007

typedef long long ll;

// node
struct Edge{
	ll v;
	ll w;
	Edge *next; 
	ll id;
} edge2[N*4], edge[N*4];

// node
Edge *head[N],*query[N];
ll val[N];
bool vis[N];
ll fa[N];
ll pre[N];
ll tot;
void init(){
	tot=0;
	memset(head,NULL,sizeof(head));
	memset(query,NULL,sizeof(query));
	memset(vis,false,sizeof(vis));
	memset(val,0,sizeof(val));
}
void addEdge(ll u,ll v){  //函数重载 
	edge[tot].v=v;
	edge[tot].next=head[u];
	head[u]=&edge[tot++];
}
void addEdge(ll u,ll v,ll w){
	edge[tot].v=v;
	edge[tot].w=w;
	edge[tot].next=query[u];
	query[u]=&edge[tot++];
}
ll find(ll x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
void tarjan(ll u,ll pa){   //LCA问题的离线算法tarjan 
	vis[u]=true;
	fa[u]=u;
	pre[u]=pa;
	for(Edge *p=query[u];p;p=p->next){
		ll v=p->v;
		ll w=p->w;
		if(vis[v]){
			ll lca=find(v);
			val[v]+=w;   
			val[u]+=w;
			val[lca]-= w;
			if(pre[lca]!=-1) val[pre[lca]]-=w; 
		}
	}
	for(Edge *p=head[u];p;p=p->next){
		ll v=p->v;
		if(vis[v]) continue;
		tarjan(v,u);
		fa[v]=u;
	}
}
ll dfs(ll u,ll pa){
	for(Edge *p=head[u];p;p=p->next){
		ll v=p->v;
		if(v==pa) continue;
		val[u]+=dfs(v,u);
	} 
	return val[u];
}

// edge

Edge *head2[N],*query2[N];
ll val2[N];
bool vis2[N];
ll fa2[N];
ll pre2[N];
ll tot2;
void init2(){
	tot2=0;
	memset(head2,NULL,sizeof(head2));
	memset(query2,NULL,sizeof(query2));
	memset(vis2,false,sizeof(vis2));
	memset(val2,0,sizeof(val2));
}
void addEdge2(ll u,ll v){  //函数重载 
	edge2[tot2].v=v;
	edge2[tot2].next=head2[u];
	edge2[tot2].id = tot2;
	head2[u]=&edge2[tot2++];
}
void addEdge2(ll u,ll v,ll w){
	edge2[tot2].v=v;
	edge2[tot2].w=w;
	edge2[tot2].next=query2[u];
	query2[u]=&edge2[tot2++];
}
ll find2(ll x){
	if(fa2[x]==x) return fa2[x];
	return fa2[x]=find2(fa2[x]);
}
void tarjan2(ll u,ll pa){   //LCA问题的离线算法tarjan 
	vis2[u]=true;
	fa2[u]=u;
	pre2[u]=pa;
	for(Edge *p=query2[u];p;p=p->next){
		ll v=p->v;
		ll w=p->w;
		if(vis2[v]){
			ll lca=find2(v);
			val2[v]+=w;   
			val2[u]+=w;
			val2[lca]-= 2 * w;
		}
	}
	for(Edge *p=head2[u];p;p=p->next){
		ll v=p->v;
		if(vis2[v]) continue;
		tarjan2(v,u);
		fa2[v]=u;
	}
}
ll dfs2(ll u,ll pa){
	for(Edge *p=head2[u];p;p=p->next){
		ll v=p->v;
		if(v==pa) continue;
		val2[u]+=dfs2(v,u);
	} 
	return val2[u];
}

ll sunxu[N];

void dfs3(ll u,ll pa){
	for(Edge *p=head2[u];p;p=p->next){
		ll v=p->v;
		sunxu[v] = p->id;
		if(v==pa) continue;
		dfs3(v,u);
	} 
}


int main(){
	ll T,ca=1;
	ll n,m;
	ll u,v,w;
	ll i;
	scanf("%lld",&T);
	while(T--){
		init();
		init2();
		scanf("%lld%lld",&n, &m);
		for(i=1;i<n;++i){
			scanf("%lld%lld",&u,&v);
			addEdge(u-1,v-1);
			addEdge(v-1,u-1);
			addEdge2(u-1,v-1);
			addEdge2(v-1,u-1);

		}
		char op[5];
		for(i=0;i<m;++i){
			scanf("%s", op);
			if (op[3] == '1') {
				scanf("%lld%lld%lld",&u,&v,&w);
				addEdge(u-1,v-1,w);
				addEdge(v-1,u-1,w);
			} else {
				scanf("%lld%lld%lld",&u,&v,&w);
				addEdge2(u-1,v-1,w);
				addEdge2(v-1,u-1,w);
			}
		}
		tarjan2(0,-1);
		dfs2(0,-1);
		tarjan(0,-1);
		dfs(0,-1);
		memset(sunxu, 0, sizeof(sunxu));
		dfs3(0, -1);
		printf("Case #%lld:\n",ca++);
		printf("%lld", val[0]);
		for(i=1;i<n;++i)
			printf(" %lld",val[i]);
		puts("");
		sort(sunxu, sunxu+n-1);
		printf("%lld" ,val2[sunxu[0]]);
		for(i=1;i<n-1;++i) {
			printf(" %lld" ,val2[sunxu[i]]);
		}
		puts("");
	}
	return 0;
}
