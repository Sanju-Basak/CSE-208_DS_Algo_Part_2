#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void add_edge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void dfs_visit(vector<int>adj[], bool visited[], stack<int>&stk, int source)
{
    visited[source]= true;
    for(int i=0; i< adj[source].size(); i++)
    {
        int y= adj[source][i];
        if(!visited[y])
            dfs_visit(adj, visited, stk, y);
    }
    stk.push(source);
}

void dfs(vector<int> adj[], int v, stack<int>& stk)
{
    bool visited[v+1];
    for(int i=1; i<=v; i++)
        visited[i]= false;
    for(int i=1; i<=v; i++)
    {
        if(!visited[i])
            dfs_visit(adj, visited, stk, i);
    }
}

void dfs2_visit(vector<int>adj[], bool visited[], int source)
{
    visited[source]= true;
    cout<< source<< " ";
    for(int i=0; i< adj[source].size(); i++)
    {
        int y= adj[source][i];
        if(!visited[y])
            dfs2_visit(adj, visited, y);
    }
}


void dfs2(vector<int> adj[], int v, stack<int>& stk)
{
    bool visited[v+1];
    for(int i=1; i<=v; i++)
        visited[i]= false;
    while(!stk.empty())
    {
        int x= stk.top();
        if(!visited[x])
        {
            dfs2_visit(adj, visited, x);
            cout<< endl;
        }
        stk.pop();

    }
}

void traspose(vector<int> adj[], vector<int> adj2[], int v)
{
    for(int i=1; i<=v; i++)
    {
        for(int j=0; j< adj[i].size(); j++)
        {
            add_edge(adj2, adj[i][j], i);
        }
    }
}

void printGraph(vector<int> adj[], int v)
{
    for(int i=1; i<=v; i++)
    {
        cout<< "Adjacent nodes of "<<i<< " are: ";
        for(int j=0; j< adj[i].size(); j++)
            cout<< adj[i][j]<< " ";
        cout<< endl;
    }

}

int main()
{
    int v, e;
    cin>>v>>e;
    vector<int>adj[v+1];
    vector<int>adj2[v+1];
    for(int i=0; i<e; i++)
    {
        int x, y;
        cin>> x>> y;
        add_edge(adj, x, y);
    }
    stack<int> stk;
    dfs(adj, v, stk);
    traspose(adj, adj2, v);
    dfs2(adj2, v, stk);
}
