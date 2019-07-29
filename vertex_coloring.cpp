#include <bits/stdc++.h>
using namespace std;

int edge, vertex;
int graph[1005][1005];
int vis[1005], color[1005];

int get_color(int u){
	bool cvis[105];
	memset(cvis,0,sizeof cvis);
	for(int i=1;i<=vertex;i++){
		if(graph[u][i]) cvis[color[i]]=1;
	}
	for(int i=1;i<=100;i++){
		if(!cvis[i]) return i;
	}
}


int bfs(int s){
	memset(vis,0,sizeof vis);
	vis[s]=1;
	queue< int > q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		color[u]=get_color(u);
		q.pop();
		for(int i=1;i<=vertex;i++){
			if(graph[u][i] && vis[i]==0){
				q.push(i);
				vis[i]=1;
			}
		}
	}
}


int main(){
	cin>>vertex>>edge;
	for(int i=1;i<=edge;i++){
		int u,v;
		cin>>u>>v;
		graph[u][v]=1;
		graph[v][u]=1;
	}
	bfs(1);

	bool cvis[105];
	memset(cvis,0,sizeof cvis);
	for(int i=1;i<=vertex;i++){
		cvis[color[i]]=1;
	}
	int cnt=0;
	for(int i=1;i<=100;i++){
		if(cvis[i]) cnt++;
	}

	cout<<"Total Chromatic Number: "<<cnt<<endl;
	for(int i=1;i<=vertex;i++){
		cout<<i<<" : "<<color[i]<<endl;
	}

	return 0;
}
