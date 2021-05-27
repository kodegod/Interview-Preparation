//https://www.interviewbit.com/problems/cycle-in-undirected-graph/

vector<int> par;
int get_root(int u)
{
    if(par[u]==u)
        return u;
    return par[u]=get_root(par[u]);
}
void merge(int u,int v)
{
    int a=get_root(u);
    int b=get_root(v);
    if(a==b)
        return;
    if(rand()%2)
        par[a]=b;
    else
        par[b]=a;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    par.resize(A+1,0);
    for(int i=1; i<=A; i++)
        par[i]=i;
    for(int i=0; i<B.size(); i++)
    {
        int a=get_root(B[i][0]);
        int b=get_root(B[i][1]);
        if(a==b)
            return 1;
        else
            merge(B[i][0],B[i][1]);
    }
    return 0;
}
