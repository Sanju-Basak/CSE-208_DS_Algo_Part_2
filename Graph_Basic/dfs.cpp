#include<iostream>
#include<vector>

using namespace std;

int time;

void add_edge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
}

void dfs_visit(vector<int> adj[], bool visited[], int start[], int finish[], int parent[], int v, int source)
{
    time++;
    start[source]= time;
    visited[source]= true;
    cout<< source<< " ";
    for(int i=0; i< adj[source].size(); i++)
    {
        int y= adj[source][i];
        if(!visited[y])
        {
            parent[y]= source;
            dfs_visit(adj,visited,start,finish,parent, v,y);
        }
    }
    time++;
    finish[source]= time;

}

void dfs(vector<int> adj[], int start[], int finish[], int v)
{
    bool visited[v];
    int parent[v];
    for(int i=0; i<v; i++)
    {
        visited[i]= false;
        parent[i]= -1;
    }
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
            dfs_visit(adj, visited, start, finish, parent, v, i);
        cout<< endl;
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
    int start[v], finish[v];
    dfs(adj, start, finish, v);
    cout<< endl;
    for(int i=0; i<v; i++)
    {
        cout<< "Node:" <<i << " Start time: "<< start[i]<< " , "<< "Finish time: "<< finish[i]<< endl;
    }

}
