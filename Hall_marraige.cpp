#include <bits/stdc++.h>
using namespace std;
queue< int > choice[1000];
int main(){
	int girl,boy;;
	cin>>girl>>boy;
	for(int i=1;i<=girl;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			int b;
			cin>>b;
			choice[i].push(b);
		}
	}

	int bmarraige[1000], gmarraige[1000], cnt=0;
	memset(gmarraige,0,sizeof gmarraige);
	memset(bmarraige,0,sizeof bmarraige);
	while(cnt<girl){
		vector< int > propose[1000];
		for(int i=1;i<=girl;i++){
			if(gmarraige[i]==0){
				int tmp=choice[i].front();
				propose[tmp].push_back(i);
				choice[i].pop();
				choice[i].push(tmp);
			}
		}


		for(int i=1;i<=boy;i++){
			for(int j=0;j<propose[i].size();j++){
				int tmp=propose[i][j];
				gmarraige[bmarraige[i]]=0;
				gmarraige[tmp]=i;
				bmarraige[i]=tmp;
				break;
			}
		}
		
		cnt=0;
		for(int i=1;i<=girl;i++){
			if(gmarraige[i]) cnt++;
		}
	}

	for(int i=1;i<=girl;i++){
		cout<<i<<" : "<<gmarraige[i]<<endl;
	}
	return 0;
}