#include <bits/stdc++.h>
using namespace std;
int matrix[100][100];
int main(){
	int vertex,edge;
	cin>>vertex>>edge;
	
	//matrix input
	/*for(int i=1;i<=vertex;i++){
		for(int j=1;j<=vertex;j++){
			cin>>matrix[i][j];
		}
	}*/


	//edge input
	for(int i=1;i<=edge;i++){
		int u,v;
		cin>>u>>v;
		matrix[u][v]=1;
		matrix[v][u]=1;
	}


	for(int i=1;i<=vertex;i++){
		for(int j=1;j<=vertex;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
