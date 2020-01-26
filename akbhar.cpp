#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
 
vector< pair<ll ,ll > >bfs;
vector<ll>adj[10000007];//adjacency vector
vector<ll>par(10000007);//index of the soldier central city
vector<ll>col(10000007);//for mainting the range of a guard from each city
queue<ll>q;
 
 
int BFS(int a){
 
	ll ct=bfs[a].ff;
	if(par[ct]!=-1){
		// cout<<"already taken city:"<<ct<<" by par:"<<par[ct]<<endl;
		return 0;
	}
	if(par[ct]==-1 && bfs[a].ss==0){
		// cout<<"bfs of city"<<ct<<" done;"<<" col"<<bfs[a].ss<<endl;
		par[ct]=ct;
		col[ct]=bfs[a].ss;
		return 1;
	}
	else{
		// cout<<"bfs of city "<<ct<<" started;"<<" col"<<bfs[a].ss<<endl;
		par[ct]=ct;
		col[ct]=bfs[a].ss;	
		// cout<<"pushed p:"<<ct<<endl;
		q.push(ct);
		while(!q.empty()){
 
			ll p=q.front();
			// cout<<"popped p:"<<p<<endl;
			q.pop();
			for (int i = 0; i < adj[p].size() && col[p]; ++i)
			{
				if(col[adj[p][i]]==-1){
					par[adj[p][i]]=ct;
					col[adj[p][i]]=col[p]-1;
					// cout<<"pushed "<<adj[p][i]<<" with col"<<col[adj[p][i]]<<"; par:"<<par[adj[p][i]]<<endl;
					q.push(adj[p][i]);
				}
				else if(par[adj[p][i]]==ct && col[adj[p][i]]<col[p]-1){
						col[adj[p][i]]=col[p]-1;
						q.push(col[adj[p][i]]);
						// cout<<"pushed "<<adj[p][i]<<" with updated col"<<col[adj[p][i]]<<"; par:"<<par[adj[p][i]]<<endl;
				}
				else if(par[adj[p][i]]!=ct  ){
					// cout<<"differnet parent for "<<adj[p][i]<<"->"<<"par:"<<par[adj[p][i]]<<endl;
					return 0;
				}
			}
		}
		return 1;		
	}
}
 
int main(){
 
	int t;
	cin>>t;
	while(t--){
		ll n,r,m;
		cin>>n>>r>>m;
		for (int i = 1; i <=n ; ++i)
		{
			adj[i].clear();
			par[i]=-1;
			col[i]=-1;
		}
		bfs.clear();
		ll city1,city2,str;
		for (int i = 0; i < r; ++i)
		{
			cin>>city1>>city2;
			adj[city1].pb(city2);
			adj[city2].pb(city1);		
		}
		for (int i = 0; i < m; ++i)
		{
			cin>>city1>>str;
			bfs.pb(mp(city1,str));
		}
		int flag=0;
		for (int i = 0; i < m; ++i)
		{
			// cout<<"flag:"<<flag<<"; bfs head node:"<<bfs[i].ff<<endl;
			flag=BFS(i);
			// cout<<"flag:"<<flag<<"; bfs head node done:"<<bfs[i].ff<<endl;
			if(flag==0)break;
		}
		for (int i = 1; i <=n && flag; ++i)
		{
			// cout<<"city:"<<i<<"; col:"<<col[i]<<"; "<<endl;
			if(col[i]==-1){
				flag=0;
				break;
			}
		}
		if (flag==0)
		{
			cout<<"No\n";
		}
		else
			cout<<"Yes\n";
 
 
	}
	return 0;
}
