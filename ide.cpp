#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<string>

#define N 100005
#define M 10005
#define mod 1000000007
//#define p 10000007
//#define mod2 1000000009
#define ll long long
#define ull unsigned long long
#define LL long long
#define eps 1e-6
//#define inf 2147483647
#define maxi(a,b) (a)>(b)? (a) : (b)
#define mini(a,b) (a)<(b)? (a) : (b)

using namespace std;

int n;
int x[N],y[N];
map<pair<int,int>,int>mp;
int r[N];
set<int>s;
int ans[N];
int vis[N];
ll mod2=1000000009;

int ok(int i)
{
    int nx,ny,te;
    nx=x[i]-1;ny=y[i]+1;
    te=mp[ make_pair(nx,ny) ];
    if(te!=0 && r[te-1]==1){
        return 0;
    }
    nx=x[i];
    te=mp[ make_pair(nx,ny) ];
    if(te!=0 && r[te-1]==1){
        return 0;
    }
    nx=x[i]+1;
    te=mp[ make_pair(nx,ny) ];
    if(te!=0 && r[te-1]==1){
        return 0;
    }
    return 1;
}

void ini()
{
    int i;
    int nx,ny;
    s.clear();
    memset(r,0,sizeof(r));
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
        mp[ make_pair(x[i],y[i]) ]=i+1;
    }
    for(i=0;i<n;i++){
        nx=x[i]-1;ny=y[i]-1;
        if(mp[ make_pair(nx,ny) ]!=0){
            r[i]++;
        }
        nx=x[i];
        if(mp[ make_pair(nx,ny) ]!=0){
            r[i]++;
        }
        nx=x[i]+1;
        if(mp[ make_pair(nx,ny) ]!=0){
            r[i]++;
        }
    }
    for(i=0;i<n;i++){
        if(ok(i)==1){
            s.insert(i);
            vis[i]=-1;
        }
    }
}

void changeerase(int i)
{
    int nx,ny,te;
    nx=x[i]-1;ny=y[i]-1;
    te=mp[ make_pair(nx,ny) ];
    if(te!=0){
        if(vis[te-1]==-1){
            vis[te-1]=0;s.erase(te-1);
        }
        return;
    }
    nx=x[i];
    te=mp[ make_pair(nx,ny) ];
    if(te!=0){
        if(vis[te-1]==-1){
            vis[te-1]=0;s.erase(te-1);
        }
        return;
    }
    nx=x[i]+1;
    te=mp[ make_pair(nx,ny) ];
    if(te!=0){
        if(vis[te-1]==-1){
            vis[te-1]=0;s.erase(te-1);
        }
        return;
    }
}

void changeadd(int i)
{
    int nx,ny,te;
    nx=x[i]-1;ny=y[i]-1;
    te=mp[ make_pair(nx,ny) ];
    if(te!=0 && ok(te-1)==1){
        s.insert(te-1);
        vis[te-1]=-1;
    }
    nx=x[i];
    te=mp[ make_pair(nx,ny) ];
    if(te!=0 && ok(te-1)==1){
        s.insert(te-1);
        vis[te-1]=-1;
    }
    nx=x[i]+1;
    te=mp[ make_pair(nx,ny) ];
    if(te!=0 && ok(te-1)==1){
        s.insert(te-1);
        vis[te-1]=-1;
    }
}

void updata(int i)
{
    int nx,ny,te;
    nx=x[i]-1;ny=y[i]+1;
    te=mp[ make_pair(nx,ny) ];
    if(te!=0){
        r[te-1]--;
        if(r[te-1]==1)
            changeerase(te-1);
    }
    nx=x[i];
    te=mp[ make_pair(nx,ny) ];
    if(te!=0){
        r[te-1]--;
        if(r[te-1]==1)
            changeerase(te-1);
    }
    nx=x[i]+1;
    te=mp[ make_pair(nx,ny) ];
    if(te!=0){
        r[te-1]--;
        if(r[te-1]==1)
            changeerase(te-1);
    }
}

void solve()
{
    int i,index;
    set<int>::iterator it;
    for(i=0;i<n;i++){
        for (auto &x : s)
        {
            cout << x << ' ';
        }
        cout << '\n';
        if(i%2==0){
            it=s.end();
            it--;
            ans[i]=*it;
        }
        else{
            it=s.begin();
            ans[i]=*it;
        }
        index=*it;
        s.erase(*it);
        mp[ make_pair(x[index],y[index]) ]=0;
        vis[index]=1;
        updata(index);
        changeadd(index);
    }
}

void out()
{
    int i;
    ll aa=0;
    
    for(i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    for(i=0;i<n;i++){
        aa=(aa*(ll)n)%mod2;
        aa=(aa+(ll)ans[i])%mod2;
    }
    printf("%I64d\n",aa);
}

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    //scanf("%d",&T);
    //for(int ccnt=1;ccnt<=T;ccnt++)
    //while(T--)
    //scanf("%d%d",&n,&m);
    while(scanf("%d",&n)!=EOF)
    {
        ini();
        solve();
        out();
    }
    return 0;
}