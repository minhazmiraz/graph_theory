#include <bits/stdc++.h>
using namespace std;


int matrix[1000][1000], degree[1000];
int edge, vertex;

/*
int dist[100];
void dijkstra(int source){
	set< int > st;
	st.insert(source);
	dist[source]=0;
	while(!st.empty()){
		auto top=st.begin();
		int u=*top;
		st.erase(u);
		for(int i=1;i<=vertex;i++){
			if(matrix[u][i]){
				if(dist[u]+matrix[u][i]<dist[i]){
					st.erase(i);
					dist[i]=dist[u]+matrix[u][i];
					st.insert(i);
				}
			}
		}
	}
}
*/

int main(){
	cin>>vertex>>edge;
	int sum=0;
	
	for(int i=1;i<=vertex;i++){
		for(int j=1;j<=vertex;j++){
			matrix[i][j]=100000;	//infinity value
			if(i==j) matrix[i][j]=0;
		}
	}
	for(int i=1;i<=edge;i++){
		int u,v,c;
		cin>>u>>v>>c;
		matrix[u][v]=c;
		matrix[v][u]=c;
		degree[u]++; degree[v]++;
		sum+=c;
	}

	vector< int > vc;
	for(int i=1;i<=vertex;i++){
		if(degree[i]%2!=0) vc.push_back(i);
	}
	if(vc.size()==0){
		//eulerian
		cout<<sum<<endl;
	} else{
		/*
		for(int i=1;i<=vertex;i++)
			dist[i]=1000000;
		int src=vc[0], dest=vc[1];
		dijkstra(src);
		cout<<sum+dist[dest]<<endl;
		*/

		int src=vc[0], dest=vc[1];
		for(int k=1;k<=vertex;k++){
			for(int i=1;i<=vertex;i++){
				for(int j=1;j<=vertex;j++){
					matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j]);
				}
			}
		}

		cout<<sum+matrix[src][dest]<<endl;

	}
	return 0;
}