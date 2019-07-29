#include <bits/stdc++.h>
using namespace std;
int matrix[100][100];
int vertex,edge;
int vis[100], tmpVis[100];
vector< int > finish;

void dfs(int s){
	vis[s]=1;	// declaring visited node
	stack< int > stk;
	stk.push(s);
	while(!stk.empty()){
		int u = stk.top();
		if(tmpVis[u]){	//flag array for finding finishing time of a node
            finish.push_back(u);	//putting node on topsort vector
            stk.pop();
		}
		tmpVis[u]=1;
		for(int i=1;i<=vertex;i++){
			if(matrix[u][i]==1 && vis[i]==0){
				stk.push(i);
				vis[i]=1;
			}
		}
	}
}

int main(){
	cin>>vertex>>edge;

	//edge input
	for(int i=1;i<=edge;i++){
		int u,v;
		cin>>u>>v;
		matrix[u][v]=1;
	}

	for(int i=1;i<=vertex;i++){
        if(!vis[i]){
            dfs(i);
        }
	}
	for(int i=finish.size()-1;i>=0;i--)
        cout<<finish[i]<<" ";
	cout<<endl;
	return 0;
}
