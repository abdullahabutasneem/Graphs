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

vector<pair<int,int>>edge[100007];
int vis[100007];
ll dis[100007];
int n,m;
void dijkstra()
{
    fil(vis);
    dis[1] = 0;
    for (int i = 2; i <= n; ++i) {
		dis[i] =(1LL<<62);
	}
	multiset<pair<int,int>>mul;
	mul.insert({0, 1});
    while(!mul.empty())
    {
        pair<int,int> p = *mul.begin();
        int node = p.second;
        int weight = p.first;
        mul.erase(mul.begin());
            fo(i, edge[node].size())
            {
                int n = edge[node][i].first;
                int w = edge[node][i].second;
                if(dis[node]+w < dis[n]){
                    dis[n] = dis[node] +w;
                    mul.insert({dis[n], n});
                }
            }

    }
}

int main()
{
    IOS;
    scanf("%d%d",&n,&m);
    fo(i,m)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        //cin>>u>>v;
        edge[u].pb({v,0});
        edge[v].pb({u,1});
    }
    dijkstra();
    if(dis[n]==(1LL<<62)){
        printf("-1");
    }
    else printf("%d",dis[n]);
    //cout<<dis[n]<<endl;
    return 0;
}
