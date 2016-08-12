const int N=1100,INF=0x3f3f3f3f;
const int M=N*N;
int pre[N],d[N],p[N],ans;
int cnt,head[N];
int q[M],l,r;
struct edge
{
    int u,v,w,c,next;
}e[M];
void init()
{
    memset(head,-1,sizeof(head));
    ans=cnt=0;
}
void add(int u,int v,int w,int c)
{
    e[cnt].u=u,e[cnt].v=v,e[cnt].w=w,e[cnt].c=c;
    e[cnt].next=head[u],head[u]=cnt++;
    e[cnt].u=v,e[cnt].v=u,e[cnt].w=-w,e[cnt].c=0;
    e[cnt].next=head[v],head[v]=cnt++;
}
void updata(int s,int t)
{
    int i,f=INF;
    for(i=t;i!=s;i=e[pre[i]].u)
        f=min(f,e[pre[i]].c);
    for(i=t;i!=s;i=e[pre[i]].u)
    {
       e[pre[i]].c-=f;
       e[pre[i]^1].c+=f;
       ans+=f*e[pre[i]].w;
    }
}
int spfa(int s,int t)
{
    int i,u,v,w;
    memset(p,0,sizeof(p));
    memset(pre,-1,sizeof(pre));
    memset(d,0x3f,sizeof(d));
    l=r=0;
    q[++r]=s,p[s]=1,d[s]=0;
    while(l<r)
    {
        p[u=q[++l]]=0;
        for(i=head[u];i!=-1;i=e[i].next)
        {
            v=e[i].v,w=e[i].w;
            if(e[i].c&&d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pre[v]=i;
                if(!p[v])
                {
                    p[v]=1;
                    q[++r]=v;
                }
            }
        }
    }
    if(pre[t]==-1)
        return 0;
    return 1;
}
void MiCMaF(int s,int t)
{
    ans=0;
    while(spfa(s,t))
        updata(s,t);
}

MiCMaF