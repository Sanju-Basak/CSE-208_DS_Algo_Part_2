#include<bits/stdc++.h>

using namespace std;

bool bfs(vector < vector < int> > &adj, int v, int source, int dest, int parent[])
{
    bool visited[v];
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
    int v;
    cin>> v;
    string str[v+1];
    int w[v], l[v], r[v];
    int match[v][v];
    for(int i=0; i<v; i++)
    {
        cin>> str[i]>> w[i]>> l[i]>> r[i];
        for(int j=0; j<v; j++)
            cin>> match[i][j];
    }
    int tot_v= v+1 + ((v-1)*(v-1)-(v-1))/2;
    int g= ((v-1)*(v-1)-(v-1))/2;
    for(int i=0; i<v; i++)
    {
        vector < vector < int > > cf;
        cf.assign(tot_v, vector < int >(tot_v, 0));
        int tot_cap= 0;
        int x= 1, s=0, t=tot_v-1;

        ///Making network
        for(int j=0; j<v; j++)
        {
            if(j!=i)
            {
                for(int k=0; k<v; k++)
                {
                    if(k!= i && j<k)
                    {
                        cf[s][s+x]= match[j][k];
                        x++;
                        tot_cap= tot_cap+ match[j][k];
                    }
                }
            }
        }
        int z=1, y=2;
        for(int j= 1; j<=g; j++)
        {
            cf[j][g+z]= INT_MAX;
            cf[j][g+y]= INT_MAX;
            if(y== v-1)
            {
                z++;
                y=z+1;
            }
            else
                y++;
        }
        for(int j= g+1,k=0; j< t; j++, k++)
        {
            if(k==i)
                k++;
            cf[j][t]= w[i]+ r[i]- w[k];
        }

        ///Edmond Karp
        int max_flow= 0;
        int parent[tot_v];
        while(bfs(cf, tot_v, s, t, parent))
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
        if(max_flow< tot_cap)
            cout<< str[i]<< " is eliminated\n";

    }
}
