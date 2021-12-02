#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void add_edge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool bipartite(vector<int> adj[], int v, int source)
{
    bool visited[v];
    int partite[v];
    for(int i=0; i<v; i++)
    {
        visited[i]= false;
        partite[i]= 0;
    }
    queue<int> que;
    que.push(source);
    visited[source]= true;
    partite[source]= 1;
    while(!que.empty())
    {
        int y= que.front();
        for(int i=0; i<adj[y].size(); i++)
        {
            int x= adj[y][i];
            if(partite[x]== partite[y] && y!= x)
                return false;
            else if(!visited[x])
            {
                visited[x]= true;
                partite[x]= 3- partite[y];
                que.push(x);
            }
        }
        que.pop();
    }
    return true;
}

int main()
{
    int node, edge;
    cin>> node>> edge;
    vector<int>adj[node];
    for(int i=0; i<edge; i++)
    {
        int x,y;
        cin>> x>> y;
        add_edge(adj, x,y);
    }
    if(bipartite(adj, node, 0))
        cout<< "Bipartite graph";
    else
        cout<< "Not bipartite graph";

}

