#include<iostream>
#include<queue>
#include<vector>

using namespace std;

bool bfs(vector < vector < int> > &adj, int v, int source, int dest, int parent[], bool visited[])
{
    for(int i=0; i<v; i++)
    {
        visited[i]= false;
        parent[i]= -1;
    }
    queue<int> que;
    visited[source]= true;
    que.push(source);
    while(!que.empty())
    {
        int x= que.front();
        for(int i=0; i<v; i++)
        {
            if(!visited[i] && adj[x][i]>0)
            {
                if(i== dest)
                {
                    parent[i]= x;
                    return true;

                }
                visited[i]= true;
                que.push(i);
                parent[i]= x;
            }
        }
        que.pop();

    }
    return false;
}


int main()
{
    int v, e;
    freopen("input.txt", "r", stdin);
    cin>> v>> e;
    vector < vector < int > > mat;
    mat.assign(v, vector < int >(v, 0));
    vector < vector < int > > cf;
    cf.assign(v, vector < int >(v, 0));
    for(int i=0; i<e; i++)
    {
        int u, v, w;
        cin>> u>> v>> w;
        mat[u][v]= w;
        cf[u][v]= w;
    }
    int s, t;
    cin>> s>> t;
    int max_flow= 0;
    int parent[v];
    bool visited[v];

    while(bfs(cf, v, s, t, parent, visited))
    {
        int res_flow= INT_MAX;
        for(int i= t; i!= s; i= parent[i])
        {
            int u= parent[i];
            if(res_flow> cf[u][i])
                res_flow= cf[u][i];
        }
        for(int i=t; i!=s; i= parent[i])
        {
            int u= parent[i];
            cf[u][i]= cf[u][i]- res_flow;
            cf[i][u]= cf[i][u]+ res_flow;
        }
        max_flow= max_flow+ res_flow;
    }
    cout<< "Max_flow: "<< max_flow<< endl;
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(visited[i] && !visited[j] && mat[i][j]>0)
                cout<< i<< "-" << j<< endl;
        }
    }

}
