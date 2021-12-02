#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void add_edge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void dfs_visit_util(vector<int> adj[], bool visited[], int source, queue<int>& stk)
{

    visited[source]= true;
    for(int i=0; i< adj[source].size(); i++)
    {
        int y= adj[source][i];
        if(!visited[y])
        {
            dfs_visit_util(adj, visited, y, stk);
        }
    }
    stk.push(source);

}

void dfs_visit(vector<int> adj[], int visited[], int &c, int v, int source)
{

    visited[source]= 1;
    for(int i=0; i< adj[source].size(); i++)
    {
        int y= adj[source][i];
        if(visited[y]== 1)
            c=1;
        if(visited[y]== 0)
        {
            dfs_visit(adj,visited, c, v,y);
        }
    }
    visited[source]= 2;

}

void dfs(vector<int> adj[], int &c, int v)
{
    int visited[v+1];
    for(int i=1; i<=v; i++)
    {
        visited[i]= 0;
    }
    for(int i=1; i<=v; i++)
    {
        if(visited[i]==0)
            dfs_visit(adj,visited, c, v, i);
    }
}

void topsort(vector<int> adj[], int v, int source, queue<int>& stk)
{
    bool visited[v+1];
    for(int i=1; i<=v; i++)
        visited[i]= false;
    dfs_visit_util(adj, visited, source, stk);
    for(int i=1; i<=v; i++)
    {
        if(!visited[i])
            dfs_visit_util(adj, visited, i, stk);
    }


}

int main()
{
    int node, edge;
    cin>> node;
    cin>> edge;
    vector<int>adj[node+1];
    for(int i=0; i<edge; i++)
    {
        int x,y;
        cin>> x>> y;
        add_edge(adj, x, y);
    }
    queue<int> stk;
    int c=0;
    dfs(adj, c, node);
    if(c)
        cout<< "Not possible";
    else
    {
        topsort(adj, node, 1, stk);

        while(!stk.empty())
        {
            cout<< stk.front()<< " ";
            stk.pop();
        }
    }



}

