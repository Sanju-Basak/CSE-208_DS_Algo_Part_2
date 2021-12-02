#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void add_edge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void dfs_visit(vector<int> adj[], bool visited[], int source, stack<int>& stk)
{

    visited[source]= true;
    for(int i=0; i< adj[source].size(); i++)
    {
        int y= adj[source][i];
        if(!visited[y])
        {
            dfs_visit(adj, visited, y, stk);
        }
    }
    stk.push(source);


}

void topsort(vector<int> adj[], int v, int source, stack<int>& stk)
{
    bool visited[v];
    for(int i=0; i<v; i++)
        visited[i]= false;
    dfs_visit(adj, visited, source, stk);
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
            dfs_visit(adj, visited, i, stk);
    }


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
        add_edge(adj, x, y);
    }
    stack<int> stk;
    int source;
    cin>> source;
    topsort(adj, node, source, stk);

    while(!stk.empty())
    {
        cout<< stk.top()<< " ";
        stk.pop();
    }


}
