#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void add_edge(vector<int>adj[], int src, int des)
{
    adj[src].push_back(des);
    adj[des].push_back(src);
}

bool bfs(vector<int> adj[], int source, int dest, int pred[], int dist[], int v)
{
    bool visited[v];
    for(int i=0; i<v; i++)
    {
        visited[i]= false;
        dist[i]= INT_MAX;
        pred[i]= -1;
    }
    queue<int> que;
    que.push(source);
    visited[source]= true;
    dist[source]= 0;
    while(!que.empty())
    {
        int x= que.front();
        for(int i=0; i<adj[x].size(); i++)
        {
            int y= adj[x][i];
            if(!visited[y])
            {
                que.push(y);
                visited[y]= true;
                dist[y]= dist[x]+1;
                pred[y]= x;
            }
            if(y== dest)
                return true;
        }
        que.pop();
    }
    return false;
}

void printShortestPath(vector<int> adj[], int source, int dest, int v)
{
    int pred[v], dist[v];
    if(bfs(adj, source, dest, pred, dist, v)== false)
    {
        cout<< "Given source and destination are not connected";
    }
    else
    {
        cout<< "Minimum dist: "<< dist[dest]<< endl;
        int s= dest;
        vector<int> crawl;
        while(pred[s] != -1)
        {
            crawl.push_back(s);
            s= pred[s];
        }
        crawl.push_back(s);
        for(int i= crawl.size() -1; i>=0; i--)
            cout<< crawl[i]<< " ";
    }
}

int main()
{
    int v, edge;
    cin>>v>> edge;
    vector<int> adj[v];
    for(int i=0; i<edge; i++)
    {
        int x, y;
        cin>>x>>y;
        add_edge(adj, x, y);
    }
    int source, dest;
    cin>> source>> dest;
    printShortestPath(adj, source, dest, v);


}
