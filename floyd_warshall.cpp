#include <bits/stdc++.h>
using namespace std;

int graph[1000][1000], par[1000][1000];
int main(){
	int edge, vertex;
	cin>>vertex>>edge;
	
	for(int i=1;i<=vertex;i++){
		for(int j=1;j<=vertex;j++){
			graph[i][j]=100000;	//infinity value
			par[i][j]=-1;	//NIL value
			if(i==j) graph[i][j]=0;
		}
	}

	for(int i=1;i<=edge;i++){
		int u,v,cost;
		cin>>u>>v>>cost;
		graph[u][v]=cost;
		par[u][v]=u;
	}

	for(int k=1;k<=vertex;k++){
		for(int i=1;i<=vertex;i++){
			for(int j=1;j<=vertex;j++){
				if(graph[i][j]>graph[i][k]+graph[k][j]){
					graph[i][j]=graph[i][k]+graph[k][j];
					par[i][j]=par[k][j];
				}
			}
		}
	}


	for(int i=1;i<=vertex;i++){
		for(int j=1;j<=vertex;j++){
			cout<<graph[i][j]<<"\t";
		}
		cout<<endl;
	}

	cout<<endl;

	for(int i=1;i<=vertex;i++){
		for(int j=1;j<=vertex;j++){
			cout<<par[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}