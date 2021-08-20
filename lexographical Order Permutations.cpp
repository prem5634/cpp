#include<bits/stdc++.h>
using namespace std;
#define many(t) {int t; cin>>t; while(t--){solve();}}
#define endl "\n"
#define tostring(x) to_string(x) // i/p int; returns string form of x 
#define toint(x) stoi(x)    // i/p string; returns int form of x
#define ll long long 
#define pb push_back
#define pp pop_out
#define MOD 1000000007
#define mp make_pair
#define ff first
#define ss second
#define vint vector<int>
#define mpint map<int,int>
#define mpll map<ll,ll>
#define mpstring map<string,int>
#define mpchar map<char,int>
#define vll vector<ll>
#define pll pair<ll,ll>
#define fr(i,s,e) for(int i=s;i<e;i++)
#define frl(i,s,e) for(ll i=s;i<e;i++)
#define in(a,n) {ll x; for(int i=0;i<n;i++){ cin>>x; a.pb(x);} }
#define all(a) a.begin(),a.end()


// simply calls getline, takes line, returns vector of strings
vector<string> stringvector(){
	vector<string> v;
	string t,s;
	getline(cin,s);
	stringstream X(s);
	while(getline(X, t, ' ')){
		v.pb(t);
	}
	return v;
}
void fast(){
	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
	  }
ll max(ll a, ll b){
	if(a>=b)return a;
	else return b;
}     
ll min(ll a , ll b){
	if(a<=b )return a;
	else return b;
}
ll lcm(ll x,ll y){
	if(x==0 || y==0)return 0;
	else return (x*y)/(__gcd(x,y));
}
bool comp(const char &a, const char &b){
	return a< b;
}

void lexographicalOrder(string s, int index){
	int l,r;
	l=-1;
	cout<<s<<" "<<index<<endl;

	//finding largest s[l] to swap
	for(int i=s.size()-2; i>=0;i--){
		if(s[i]<s[i+1]){
			l=i; 
			break;
		}
	}
	if(l==-1){
		cout<<"finsihed"<<endl;
		return ;
	}
	//fniding smallest s[r] in [l+1 n] to swap s[l]
	r=l+1;
	for(int i=l+2;i<=s.size()-1;i++){
		if(s[i]>s[l] && s[i]<s[r]){
			r=i;
		}
	}
	swap(s[l], s[r]);


	int strt=l+1, end=s.size()-1;
	for(int i=strt; i<=(strt+end)/2;i++){
		swap(s[i], s[end-(i-strt)]);
	}
	lexographicalOrder(s, ++index);
}
void solve(){
	string s;
	cin>>s;

	vector<char> v;
	for(int i=0;i<s.size();i++){
		v.pb(s[i]);
	}
	sort(v.begin(), v.end(), comp);
	s="";
	for(char x: v){
		s+=x;
	}
	cout<<"sorted"<<s<<endl;
	int index=1;
	lexographicalOrder(s,index);
}
 
int main(){
	fast();
	solve();
	// many(t);
	return 0;
	} 
