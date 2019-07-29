#include <bits/stdc++.h>
using namespace std;

int edge, vertex;
int graph[1000][1000];
int vis[1000][1000], color[1000][1000];

int get_color(int u, int v){
	bool cvis[100];
	memset(cvis,0,sizeof cvis);
	for(int i=1;i<=vertex;i++){
		if(graph[u][i]) cvis[color[u][i]]=1;
	}
	for(int i=1;i<=vertex;i++){
		if(graph[v][i]) cvis[color[v][i]]=1;
	}

	for(int i=1;i<=100;i++){
		if(!cvis[i]) return i;
	}
}


int bfs(int s, int t){
	memset(vis,0,sizeof vis);
	queue< pair< int, int > > q;
	q.push({s,t});
	vis[s][t]=vis[t][s]=1;
	while(!q.empty()){
		int u=q.front().first;
		int v=q.front().second;
		color[u][v]=color[v][u]=get_color(u,v);
		q.pop();
		for(int i=1;i<=vertex;i++){
			if(graph[u][i] && !vis[u][i]){
				q.push({u,i});
				vis[u][i]=vis[i][u]=1;
			}
		}

		for(int i=1;i<=vertex;i++){
			if(graph[v][i] && !vis[v][i]){
				q.push({v,i});
				vis[v][i]=vis[i][v]=1;
			}
		}
	}
}


int main(){
	cin>>vertex>>edge;
	int sx, sy;
	for(int i=1;i<=edge;i++){
		int u,v;
		cin>>u>>v;
		graph[u][v]=1;
		graph[v][u]=1;
		sx=u; sy=v;
	}
	bfs(sx,sy);

	bool cvis[100];
	memset(cvis,0,sizeof cvis);
	for(int i=1;i<=vertex;i++){
		for(int j=1;j<=vertex;j++){
			cvis[color[i][j]]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=100;i++){
		if(cvis[i]) cnt++;;
	}

	cout<<"Total Chromatic Number: "<<cnt<<endl;
	for(int i=1;i<=vertex;i++){
		for(int j=i+1;j<=vertex;j++){
			if(graph[i][j]) cout<<i<<" "<<j<<" : "<<color[i][j]<<endl;
		}
	}

	return 0;
}