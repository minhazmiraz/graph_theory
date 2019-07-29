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
		matrix[u][v]=1;
		matrix[v][u]=1;
	}

	int zero=0, one=0, two=0, three=0, vertexMinusOne=0;

	cout<<"Degree: "<<endl;
	int sum=0;
	for(int i=1;i<=vertex;i++){
		int cnt=0;
		for(int j=1;j<=vertex;j++){
			cnt+=matrix[i][j];
		}
		cout<<i<<": "<<cnt<<endl;
		sum+=cnt;
		if(cnt==0) zero++;
		if(cnt==1) one++;
		if(cnt==2) two++;
		if(cnt==3) three++;
		if(cnt==vertex-1) vertexMinusOne++;
	}
	cout<<"Total: "<<sum<<endl;

	if(edge==0) cout<<"Null\n";
	else if(vertexMinusOne==vertex) cout<<"Complete Graph\n";
	else if(two==vertex) cout<<"Cycle Graph\n";
	else if(two==vertex-2 && one==2) cout<<"Path Graph\n";
	else if(three==vertex-1 && vertexMinusOne==1) cout<<"Wheel Graph\n";
	else cout<<"Other Graph\n";
	return 0;
}
