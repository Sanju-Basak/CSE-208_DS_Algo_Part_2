#include<iostream>
#include<vector>
#include<string>

using namespace std;

int time;

struct edge
{
    int u;
    int v;
    string str;
};

void add_edge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
}

void dfs_visit(vector<int> adj[], int visited[], int start[], int finish[], int parent[], vector<string>&str, int v, int source)
{
    time++;
    start[source]= time;
    visited[source]= 1;
    cout<< source<< " ";
    for(int i=0; i< adj[source].size(); i++)
    {
        int y= adj[source][i];
        string str1= to_string(source);
        string str2= to_string(y);
        if(visited[y]== 2)
        {
            if(start[source]< start[y])
                str.push_back("Forward edge "+ str1+ " --> "+ str2);
            else
                str.push_back("Cross edge "+ str1+ " --> "+ str2);

        }
        else if(visited[y]== 1)
            str.push_back("Back edge "+ str1+ " --> "+ str2);

        if(visited[y]== 0)
        {
            parent[y]= source;
            str.push_back("Tree edge "+ str1+ " --> "+ str2);
            dfs_visit(adj,visited,start,finish,parent, str, v,y);
        }
    }
    time++;
    visited[source]= 2;
    finish[source]= time;

}

void dfs(vector<int> adj[], int start[], int finish[], vector<string>&str, int v)
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
            dfs_visit(adj, visited, start, finish, parent, str, v, i);
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
    vector<string> str;
    dfs(adj, start, finish, str, v);
    cout<< endl;
    for(int i=0; i<str.size(); i++)
    {
        cout<<str[i]<< endl;
    }

}

