#include <bits/stdc++.h>
using namespace std;

int edge, vertex;
int graph[1000][1000];
int vis[1000], par[1000];

bool bfs(int s, int t){
	memset(vis,0,sizeof vis);
	vis[s]=1; par[s]=-1;
	bool f=0;
	queue< int > q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		if(u==t){
			f=1;
			break;
		}
		q.pop();
		for(int i=1;i<=vertex;i++){
			if(graph[u][i] && vis[i]==0){
				q.push(i);
				vis[i]=1;
				par[i]=u;
			}
		}
	}
	if(f) return 1;
	else return 0;
}

int get_min(int dest){
	int tmp=dest, mn=INT_MAX;
	while(par[tmp]!=-1){
		mn=min(mn, graph[par[tmp]][tmp]);
		tmp=par[tmp];
	}
	return mn;
}

void path(int dest, int val){
	int tmp=dest;
	while(par[tmp]!=-1){
		graph[tmp][par[tmp]]+=val;		
		graph[par[tmp]][tmp]-=val;		
		tmp=par[tmp];
	}
}

int main(){
	cin>>vertex>>edge;
	for(int i=1;i<=edge;i++){
		int u,v,cost;
		cin>>u>>v>>cost;
		graph[u][v]=cost;
	}
	int s,t, ans=0;
	cin>>s>>t;

	while(1){
		bool tmp=bfs(s,t);
		if(tmp==0) break;
		int val = get_min(t);
		path(t, val);
		ans+=val;
	}

	cout<<ans<<endl;

	return 0;
}