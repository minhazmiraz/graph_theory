#include<bits/stdc++.h>
using namespace std;
typedef pair< int, pair< int, int > > edge;
int vertexNo, edgeNo;
int vis[1000], matrix[1000][1000], ansMatrix[1000][1000];

//pair< int, pair< int,int > > p;
//p.first, p.second.first, p.second.second

void prim(int s){
    int countVertex=0; // Counting number of visited vertex
    int u=s, v, cost, total;
    countVertex++;  //increment for source vertex
    vis[u]=1;   //visiting source vertex
    priority_queue< edge > pq;  //declaring priority queue
    for(int i=1;i<=vertexNo;i++){   //visiting all adjacent non-visited vertex of source
        if(matrix[s][i]!=0 && !vis[i])  //condition if edge exist between source and i vertex and i is not visited
            pq.push({-matrix[s][i], {s,i}}); // if true push the edge to priority queue. First one is cost between s and i.
                                            // We push it as negative so that we can find the lowest value first as priority queue
                                            //sorted in decreasing order. 2nd and 3rd one is endpoint of the edge.
    }

    while(!pq.empty()){ // run the loop until priority queue is empty
        if(countVertex == vertexNo) break;  //if all vertex is visited break the loop
        edge e = pq.top();  // get the top edge in p. q. with lowest cost.
        pq.pop();   //pop the edge
        u = e.second.first; // get the endpoints u, v
        v = e.second.second;// same
        cost = (-1)*e.first;// get the cost between u and v. multiply with -1 to make it positive

        if(!vis[v]){    // if the endpoint v is not visited we will proceed
            countVertex++;  // incrementing no of visited vertex
            total+=cost;    // add the cost to total cost
            ansMatrix[u][v]=cost;   // add the edge to your answer matrix
            vis[v]=1;   // mark v as visited
            for(int i=1;i<=vertexNo;i++){   // now visiting all adjacent non-visited vertex of v
                if(matrix[v][i]!=0 && !vis[i]) //condition if edge exist between v and i vertex and i is not visited
                    pq.push({-matrix[v][i], {v,i}}); // if true push the edge to priority queue. First one is cost between v and i.
                                            // We push it as negative so that we can find the lowest value first as priority queue
                                            //sorted in decreasing order. 2nd and 3rd one is endpoint of the edge.
            }
        }
    }


    //print the ans matrix
    for(int i=0;i<=vertexNo;i++){
        for(int j=0;j<=vertexNo;j++){
            if(ansMatrix[i][j]!=0)
                cout<<i<<" "<<j<<" "<<ansMatrix[i][j]<<endl;
        }
    }

    //printing total cost
    cout<<"Total Cost: "<<total<<endl;
}


int main(){
    cout<<"Enter No of vertex and edge: \n";
    cin>>vertexNo>>edgeNo;
    cout<<"Enter All edge: \n";
    for(int i=1;i<=edgeNo;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        matrix[u][v]=cost;
        matrix[v][u]=cost;
    }
    //@memset(vis,0,sizeof vis);
    int src;
    cout<<"Enter Source Vertex:\n";
    cin>>src;
    prim(src);
    cout<<endl;
    return 0;
}
