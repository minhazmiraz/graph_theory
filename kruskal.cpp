#include<bits/stdc++.h>
using namespace std;

typedef pair< int, pair< int, int > > edge;
int vertexNo, edgeNo, sum;
int root[1000], ansMatrix[1000][1000];
vector< edge > pq;

///disjoint set

//int find_root(int n){
//    if(n!=root[n])
//        return find_root(root[n]);
//    return n;
//}

int find_root(int n){
    int tmp=n;
    while(root[tmp]!=tmp){
		tmp=root[tmp];
	}
	return tmp;
}

///kruskal

void kruskal(){
	sort(pq.begin(), pq.end());
    int countVertex=1;
    for(int i=0;i<=vertexNo;i++){
        root[i]=i;
    }

    for(int i=0;i<pq.size();i++){
        if(countVertex==vertexNo) break;
        edge e = pq[i];
        int u = e.second.first;
        int v = e.second.second;
        int cost = e.first;
        int px = find_root(u);
        int py = find_root(v);
        if(px!=py){
            root[px]=py;
            countVertex++;
            sum+=cost;
            ansMatrix[u][v]=cost;
        }
    }


    for(int i=0;i<=vertexNo;i++){
		for(int j=0;j<=vertexNo;j++){
		    if(ansMatrix[i][j]!=0)
		        cout<<i<<" "<<j<<" "<<ansMatrix[i][j]<<endl;
		}
	}
}



int main(){
	cout<<"Enter No of vertex and edge: \n";
	cin>>vertexNo>>edgeNo;
	cout<<"Enter All edge: \n";
    for(int i=1;i<=edgeNo;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        pq.push_back({cost, {u,v}});
    }
    sum=0;
    kruskal();
    cout<<"Total Cost: "<<sum<<endl;
    return 0;
}
