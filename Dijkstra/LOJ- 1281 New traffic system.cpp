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
const int maxx=100005, INF = 1000000007;

//this fuction sorts vector pair according to first element in descending order.
bool sortinrev(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
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

vector<pair<pair<int,int>,int >>rasta[20010];
pair<pair<int,int>,int> cur;

ll dis[10010][12];
int vis[10010];
int n,m,k,d;
int dijkstra(int s)
{

    queue<pair<pair<int,int>,int>>q;
    q.push({{0,0}, 0});
    dis[0][0] = 0;
    while(!q.empty())
    {
        pair<pair<int,int>,int>prev = q.front();
        q.pop();

        int node = prev.first.first;
        int cost = prev.first.second;
        int used = prev.second;

        fo(i, rasta[node].size())
        {
            int n = rasta[node][i].first.first;
            int c = rasta[node][i].first.second;
            int t = rasta[node][i].second;

            if(t+used<=d)
            {
                t+=used;
                if(cost+c <= dis[n][t])
                {
                    dis[n][t] = cost+c;
                    q.push({{n,dis[n][t]}, t});
                }
            }
        }
    }
    ll ans = INF;
    fo(i,d+1)
    {
        ans = min(ans, dis[n-1][i]);
    }
    return ans;
}

int main()
{
    IOS;
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d%d%d%d",&n,&m,&k,&d);

        fo(i,n+1)
        {
            rasta[i].clear();
            fo(j,d+1)
                 dis[i][j]=INF;
       }
        fo(i,m)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            rasta[u].pb({{v,w}, 0});
        }
        bool bl=false;
        fo(i,k)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            rasta[u].pb({{v,w}, 1});
        }
        ll ans = dijkstra(0);
        if(ans==INF)
        {
            printf("Case %d: Impossible\n",tt);
        }
        else
        {
            printf("Case %d: %lld\n",tt,ans);
        }
    }
    return 0;
}
