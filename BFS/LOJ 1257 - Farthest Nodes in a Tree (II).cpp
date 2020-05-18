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
vector<pair<int,int>>edge[30010];

ll vis[30010];
ll dis1[30010];
ll dis2[30010];
ll mx,nxt;
int n;
void bfs(int s)
{
    mx=0;
    fil(vis);
    fil(dis1);
    vis[s] = 1;
    dis1[s]=0;
    queue<pair<int,int>>mul;
    mul.push({0,s});
    while(!mul.empty())
    {
        pair<int,int> p = mul.front();
        int weight = p.first;
        int node = p.second;
        mul.pop();
        if(dis1[node]>mx){
            mx = dis1[node];
            nxt = node;
        }
        fo(i,edge[node].size())
        {
            int n = edge[node][i].first;
            int w = edge[node][i].second;
            if(!vis[n])
            {
                vis[n] = 1;
                dis1[n] = dis1[node]+w;
                //mx=max(mx,dis1[n]);
                mul.push({dis1[n],n});
            }
        }

    }
}
void bfs1(int s)
{
    fil(dis2);
    fil(vis);
    //cout<<"bolo="<<s<<endl;
    vis[s]=1;
    dis2[s]=0;
    queue<pair<int,int>>q;
    q.push({0,s});
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        int node = p.second;
        q.pop();

        fo(i,edge[node].size())
        {
            int n = edge[node][i].first;
            int w = edge[node][i].second;
            if(!vis[n])
            {
                vis[n] = 1;
                dis2[n] = dis2[node]+w;
                q.push({dis2[n],n});
            }
        }
    }
}
int main()
{
    IOS;
    int t;
    scanf("%d",&t);
    fo(tt,t)
    {
        scanf("%d",&n);
        fo(i,n)
        {
            edge[i].clear();
        }
        fo(i,n-1)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edge[u].pb({v,w});
            edge[v].pb({u,w});
        }
        bfs(0);
        bfs(nxt);
        bfs1(nxt);

        ll maxi;
        printf("Case %d:\n",tt+1);
        fo(i,n)
        {
            maxi = max(dis1[i],dis2[i]);
            printf("%lld\n",maxi);
        }

    }
    return 0;
}

