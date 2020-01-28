/*
question https://www.spoj.com/problems/NAKANJ/
solution https://ideone.com/qTr2sj
descrption: this doesnot use adjacency list but simply bfs()s each valid position from starting until we reach the end.
once we reach the end the a[end pos] will give us the minimum no of moves.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MAX 2147483647
#define MAX10 1000000007
	
int a[9][9];
int flag;

int strtx,endx,strty,endy;
queue<pair<int,int>>q;
void validPos(int x, int y,int level){
	
	if( x >= 1 && x <= 8 && y >= 1 && y<= 8 ){
		if(x==strtx && y==strty){}
		else if(a[x][y]==0 ){
			a[x][y]=level+1;
		
			q.push(mp(x,y));
			if(x==endx && y==endy)
				flag=1;
		}
	}
}

void BFS(){
		

		while(!q.empty()){
			q.pop();
		}
		q.push(mp(strtx,strty));
		pair<int,int>p;
		while(!q.empty()){

			p=q.front();
			int x=p.ff,y=p.ss;
			int level=a[x][y];
			q.pop();
			validPos(x-1,y-2,level);
			validPos(x-1,y+2,level);
			validPos(x-2,y-1,level);
			validPos(x-2,y+1,level);
			validPos(x+1,y-2,level);
			validPos(x+1,y+2,level);
			validPos(x+2,y-1,level);
			validPos(x+2,y+1,level);
			if(flag)break;
			
		}
	cout<<a[endx][endy]<<endl;	
}

int main()
{

int t;
cin>>t;
while(t--){
	flag=0;
	int n=8, m=8;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			a[i][j]=0;
		}
	}
	
	string s1,s2;
	cin>>s1>>s2;
	if(s1[0]==s2[0] && s1[1]==s2[1])
		cout<<0<<endl;
	else {
		strtx=s1[0]-'a'+1;
		endx=s2[0]-'a'+1;
		strty=s1[1]-'0';
		endy=s2[1]-'0';
		BFS();
	}
}
	return 0;
} 
