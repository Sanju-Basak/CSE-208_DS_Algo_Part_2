#include<iostream>
#include<vector>
#include<string>

using namespace std;

int time;

void add_edge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
}

void dfs_visit(vector<int> adj[], int visited[], int start[], int finish[], int parent[], int &c, int v, int source)
{
    time++;
    start[source]= time;
    visited[source]= 1;
    cout<< source<< " ";
    for(int i=0; i< adj[source].size(); i++)
    {
        int y= adj[source][i];
        if(visited[y]== 1)
            c=1;
        if(visited[y]== 0)
        {
            parent[y]= source;
            dfs_visit(adj,visited,start,finish,parent, c, v,y);
        }
    }
    time++;
    visited[source]= 2;
    finish[source]= time;

}

void dfs(vector<int> adj[], int start[], int finish[], int &c, int v)
{
    int visited[v];
    int parent[v];
    for(int i=0; i<v; i++)
    {
        visited[i]= 0;
        parent[i]= -1;
    }
    for(int i=0; i<v; i++)
    {
        if(visited[i]==0)
            dfs_visit(adj, visited, start, finish, parent, c, v, i);
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
    int c=0;
    dfs(adj, start, finish, c, v);
    cout<< endl;
    if(c==0)
        cout<< "No cycle";
    else
        cout<< "Cycle exists";


}

