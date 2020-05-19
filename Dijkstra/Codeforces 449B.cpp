#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define fil(x) memset(x, 0, sizeof(x))
#define fillb(x) memset(x,false,sizeof(x))
#define fillm(x) memset(x, -1, sizeof(x))
#define mp make_pair
#define pll pair<int, int>
#define pf printf
#define sf scanf
#define all(x) x.begin(),x.end()
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define np std::string::npos
#define fo(i,n) for(int i=0;i<n;i++)
#define of(i,n) for(int i=n-1;i>=0;i--)
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define cases(cs,t) for(int cs=1;cs<=t;cs++)
#define PI acos(-1)
#define nl endl

typedef unsigned long long lll;
typedef long long ll;
int knigtx8[] = {2, 2, -2, -2, 1, 1, -1, -1}; ///knight move in chess
int knigty8[] = {1, -1, 1, -1, 2, -2, 2, -2}; ///knight move in chess
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; ///for 8 directions
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1}; ///for 8 directions
int dx4[] = {0, 0, 1, -1}; ///for 4 directions
int dy4[] = {1, -1, 0, 0}; ///for 4 directions
const int maxx=100005;

//this fuction sorts vector pair according to first element in descending order.
bool sortinrev(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}

int atoz(){
    int frnt,bck,nibo,present,i;string s;
        frnt = abs(s[i]-present);
        bck = 26-frnt;
        nibo = min(frnt,bck);
}

template<typename T>inline T Bigmod(T base, T power, T MOD){
    T ret=1;
    while(power)
    {
        if(power & 1)ret=(ret*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return ret;
}

vector<pair<int ,int>>road[300003];
int ache[300003];
ll dis[300003];
ll n,m,cnt=0;
set<pair<int,int>>mul;
void dijkstra()
{
    //fil(vis);
    dis[1] = 0;
	//vis[1]=1;
	mul.insert({0,1});
	while(!mul.empty())
    {
        pair<int,int> p = *mul.begin();
        int node = p.second;
        int weight = p.first;
        mul.erase(mul.begin());
        if(dis[node] != weight) continue;
        fo(i,road[node].size())
        {
            int n = road[node][i].first;
            int w = road[node][i].second;
            if(dis[node]+w<=dis[n])
            {
                dis[n] = dis[node]+w;
                mul.insert({dis[n],n});
                ache[n]=0;
            }
            else if(dis[node]+w==dis[n] and ache[n]==1)
            {
                ache[n]=0;
            }
        }
    }
}

int main()
{
    IOS;
    ll k;
    cin>>n>>m>>k;
    for (int i = 2; i <= n; ++i) {
		dis[i] =(1LL<<62);
	}
    fo(i,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        road[u].pb({v,w});
        road[v].pb({u,w});
    }
    set<int>s;
    fo(i,k)
    {
        ll u,w;
        cin>>u>>w;
        s.insert(u);
        dis[u] = min(dis[u],w);
        ache[u]=1;
        mul.insert({dis[u],u});
    }
    dijkstra();
    for(auto x : s){
        if(ache[x]==1)cnt++;
    }
    cout<<k-cnt<<endl;
    return 0;
}
