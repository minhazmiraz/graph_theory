#include <bits/stdc++.h>
using namespace std;
int matrix[100][100];
int vertex,edge;
int vis[100], lvl[100], par[100];
void bfs(int s){
	vis[s]=1;
	lvl[s]=0;
	par[s]=-1;
	queue< int > q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=1;i<=vertex;i++){
			if(matrix[u][i]==1 && vis[i]==0){
				q.push(i);
				vis[i]=1;
				lvl[i]=lvl[u]+1;
				par[i]=u;
			}
		}
	}
}


void path(int dest){
	int tmp=dest;
	cout<<tmp<<" ";
	while(par[tmp]!=-1){
		tmp=par[tmp];
		cout<<tmp<<" ";
	}
}

int main(){
	cin>>vertex>>edge;

	//edge input
	for(int i=1;i<=edge;i++){
		int u,v;
		cin>>u>>v;
		matrix[u][v]=1;
		matrix[v][u]=1;
	}

	int src, dest;
	cin>>src>>dest;
	bfs(src);
	path(dest);
	cout<<endl;
	return 0;
}
