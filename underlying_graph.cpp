#include <bits/stdc++.h>
using namespace std;
int graph[1005][1005];
int main(){
	int vertex, edge;
	cin>>vertex>>edge;
	for(int i=1;i<=edge;i++){
		int u,v;
		cin>>u>>v;
		graph[u][v]=1;
		graph[v][u]=1;
	}

	for(int i=1;i<=vertex;i++){
		for(int j=1;j<=vertex;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}