#include <bits/stdc++.h>
using namespace std;
int matrix[100][100];
int vertex,edge;
int vis[100], par[100];


void dfs(int s){
	vis[s]=1;	// declaring visited node
	par[s]=-1;
	stack< int > stk;
	stk.push(s);
	while(!stk.empty()){
		int u = stk.top();
		stk.pop();
		for(int i=1;i<=vertex;i++){
			if(matrix[u][i]==1 && vis[i]==0){
				stk.push(i);
				vis[i]=1;
				par[i]=u;
			}
		}
	}
}


void path(int dest){	//Function for Finding path
	int tmp=dest;
	cout<<tmp<<" ";
	while(par[tmp]!=-1){	//Last parent Flag
		tmp=par[tmp];	//finding current node parent
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
	dfs(src);
	path(dest);
	cout<<endl;
	return 0;
}
