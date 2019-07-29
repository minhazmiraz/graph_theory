#include <bits/stdc++.h>
using namespace std;
int matrix[100][100];
int main(){
	int vertex,edge;
	cin>>vertex>>edge;

	//edge input
	for(int i=1;i<=edge;i++){
		int u,v;
		cin>>u>>v;
		matrix[u][v]++;
		matrix[v][u]++;
	}


	cout<<"Degree: "<<endl;

	int sum=0;
	for(int i=1;i<=vertex;i++){
		int cnt=0;
		for(int j=1;j<=vertex;j++){
			cnt+=matrix[i][j];
		}
		cout<<i<<": "<<cnt<<endl;
		sum+=cnt;
	}
	cout<<"Total: "<<sum<<endl;

	return 0;
}
