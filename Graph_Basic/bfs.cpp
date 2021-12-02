#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void add_edge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs_visit(vector<int> adj[], int v, int source, bool visited[], int parent[], int dist[])
{
    queue<int> que;
    visited[source]= true;
    dist[source]= 0;
    que.push(source);
    while(!que.empty())
    {
        int x= que.front();
        cout<< x<< " ";
        for(int i=0; i<adj[x].size(); i++)
        {
            int y= adj[x][i];
            if(!visited[y])
            {
                visited[y]= true;
                que.push(y);
                parent[y]= x;
                dist[y]= dist[x]+1;
            }
        }
        que.pop();

    }
    cout<< endl;
}

void bfs(vector<int> adj[], int v, int source)
{
    bool visited[v];
    int parent[v];
    int dist[v];
    for(int i=0; i<v; i++)
    {
        visited[i]= false;
        parent[i]= -1;
        dist[v]= INT_MAX;
    }
    bfs_visit(adj, v, source, visited, parent, dist);
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
            bfs_visit(adj, v, i, visited, parent, dist);
    }


}

int main()
{
    int v, e;
    cin>>v>>e;
    vector<int>adj[v];
    for(int i=0; i<e; i++)
    {
        int x, y;
        cin>> x>> y;
        add_edge(adj, x, y);
    }
    int source;
    cin>> source;
    bfs(adj, v, source);
}
