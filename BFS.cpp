#include<bits/stdc++.h>
using namespace std;

vector<int> v[11];
int parent[11];
int level[11];

void BFS(int source)
{
    level[source]=0;
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0 ;i < v[u].size();i++)
        {
            int x = v[u][i];
            if(level[x] == -1)
            {
                level[x] = level[u]+1;
                parent[x] = u;
                q.push(x);
            }

        }

    }


}

void path(int destination)
{

    if(parent[destination] != destination)
    {
        path(parent[destination]);
    }
    cout<<destination<< " ";
}

int main()
{
    int node,edge;
    //getting the input of total number of nodes and edges
    cin>>node>>edge;

    //getting the input of all node connections
    for(int i=0;i<edge;i++)
    {
        int nodeA,nodeB;
        cin>>nodeA>>nodeB;
        v[nodeA].push_back(nodeB);
        v[nodeB].push_back(nodeA);
    }

    //Printing the node adjacency list
    for(int i=1;i<=node;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";

        }
        cout<<endl;

    }

    //initially declaring the levels to be -1
    for(int i =1 ; i<= node;i++)
    {
        level[i] = -1;
        parent[i] = i;

    }

    //implementing breadth first search(BFS) function
    int source,destination;
    cout<<"Input the Source: ";
    cin>>source;
    cout<<"Input the destination: ";
    cin>>destination;
    BFS(source);
    cout<<"length of shortest path : "<< level[destination] << endl;

    //print the path of the shortest path
    path(destination);


    return 0;
}
