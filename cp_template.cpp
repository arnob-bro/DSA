#include<bits/stdc++.h>
using namespace std;

void stringMethods()
{
    string s = "I love meowmeow";
    int stringSize = s.size();
    string subString = s.substr(3, 2);
    int searchingSubStr = s.find("love");
}

//for pqueue
struct Node
{   int value;
    int priority;
    bool operator<(const Node &other) const {
        return priority < other.priority; // Max-Heap (higher priority first)
    }
};
// Custom comparator for priority queue
struct Compare {
    bool operator()(const Node &a, const Node &b) {
        return a.priority < b.priority; // Higher priority value comes first
    }
};

void STL_LIB()
{
    //vector
    vector<int> v;
    vector<vector<int>> vec_2d;
    int size_of_vector = v.size();
    v.push_back(2); // inserting elements in 1d vec
    vec_2d.push_back({1,2,3}); // inserting elements in vec_2d
    v.pop_back(); // Deleting last element
    v.erase(find(v.begin(), v.end(), 2)); // Deleting element 2
    vec_2d.erase(vec_2d.begin() + 1); // Delete the second row
    vec_2d[0].erase(vec_2d[0].begin() + 1); // Delete second element in first row
    v.empty();
    v.front();
    v.back();
    v.clear();

    //deque
    deque<int> d;
    d.push_back(10);
    d.push_front(20);
    d.pop_front();
    d.pop_back();
    deque<int>::iterator it = d.begin();
    ++it;
    it = d.insert(it, 10); // insert at 2nd position(index 1)


    //stack
    stack<int> st;
    st.push(21);
    int num=0;
    st.push(num);
    st.pop();
    st.pop();
    while (!st.empty()) {
        cout << st.top() <<" ";
        st.pop();
    }


    //queue
    queue<int> que;
    que.push(10);
    que.push(20);
    que.push(30);
    cout << "The queue gquiz is : ";
    cout << "\nsize() : " << que.size();
    cout << "\nfront() : " << que.front();
    cout << "\nback() : " << que.back();
    que.pop();


    //priority_queue
    priority_queue<int> pq;
    priority_queue <int, vector<int>, greater<int>> gq;
    priority_queue<Node, vector<Node>, Compare> cpq;
    pq.top();
    pq.pop();
    pq.push(1);
    pq.pop();
    int value = 1, priority = 1;
    cpq.push({value, priority});


    //unordered map
    unordered_map<string, int> umap;
    umap["GeeksforGeeks"] = 10;
    unordered_map<string, double> umap2 =
    {
    {"One", 1},
    {"Two", 2},
    {"Three", 3}
    };
    string key = "city";
    if (umap.find(key) == umap.end())
        cout << key << " not found\n\n"; // If key not found in map iterator , to end is returned
    else
        cout << "Found " << key << "\n\n"; // If key found then iterator to that key is returned
     // iterating over all value of umap
    unordered_map<string, int>::iterator itr;
    for (itr = umap.begin();
        itr != umap.end(); itr++)
    {
        cout << itr->first << "  " << // itr->first stores the key part and
                itr->second << endl;  // itr->second stores the value part

    }

}

void remove_all_duplicates_from_a_vector()
{
    vector<int> v = { 1, 2, 3, 3, 3, 10, 1, 2, 3, 7, 7, 8 };
    vector<int>::iterator ip;
    sort(v.begin(), v.end());
    ip = unique(v.begin(), v.begin() + 12);
    v.resize(std::distance(v.begin(), ip));
    //v.erase(unique(v.begin(), v.end()), v.end());
    for (ip = v.begin(); ip != v.end(); ++ip) {
        cout << *ip << " ";
    }
}

//permutation
void permutation_checker()
{
    int A[] = {1, 7, 0, 2};
    int B[] = {0, 7, 2, 1};

    if ( is_permutation ( A, A+4, B ) )   cout << "B is a permutation of A" ;
    else   cout << "B is not a permutation of A" ;
}

void permutation_maker_of_a_string(string str) // can be used on vectors too
{
    sort(str.begin(), str.end());
    cout << "All permutations:\n";
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

//bitwise
void bitwise_operators(int a, int b)
{
    int bitwise_or = a | b;
    int bitwise_and = a & b;
    int bitwise_xor = a ^ b;
    if ((i & 1) == 0)
    {  // If last bit is 0, it's even
        cout << i << " is even" << endl;
    }

}

//searching algo
int Binary_Search(vector<int> numbers, int k)
{
    int n= numbers.size();
    int lo=0, hi= n-1;
    while(lo<=hi)
    {   int mid = (lo+hi)/2;
        if(numbers[mid] == k)  return mid;
        else if(numbers[mid]<k)  lo=mid+1;
        else  hi = mid-1;
    }
    return -1;
}

//bfs
vector<int> v[11];
int parent[11];
int level[11];
void BFS(int source)
{
    level[source]=0;
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {   int u = q.front();
        q.pop();
        for(int i=0 ;i < v[u].size();i++)
        {   int x = v[u][i];
            if(level[x] == -1)
            {   level[x] = level[u]+1;
                parent[x] = u;
                q.push(x);
            }
        }
    }
}

void bfs_path(int destination)
{
    if(parent[destination] != destination)  path(parent[destination]);
    cout<<destination<< " ";
}

void bfs_run()
{
    int node,edge;
    cin>>node>>edge;
    for(int i=0;i<edge;i++) //getting the input of all node connections
    {   int nodeA,nodeB;
        cin>>nodeA>>nodeB;
        v[nodeA].push_back(nodeB);
        v[nodeB].push_back(nodeA);
    }
    for(int i=1;i<=node;i++) //Printing the node adjacency list
    {   cout<<i<<"->";
        for(int j=0;j<v[i].size();j++)
        {   cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i =1 ; i<= node;i++) //initially declaring the levels to be -1
    {   level[i] = -1;
        parent[i] = i;
    }
    int source,destination;
    cout<<"Input the Source: ";
    cin>>source;
    cout<<"Input the destination: ";
    cin>>destination;
    BFS(source);
    cout<<"length of shortest path : "<< level[destination] << endl;
    path(destination);
}

//dfs
vector<int> v_node[100];
char color[100];

void DFS(int source){
    int u = source;
    color[source] = 'g';
    cout<<u<<endl;
    for(auto v : v_node[u]){
        if(color[v] == 'w')
            DFS(v);
    }
    color[u]='b';
}

void DFS_run()
{
     int node,edge;
    cin>>node>>edge;

    for(int i=0;i<edge;i++){
        int a,b;
        cin>>a>>b;
        v_node[a].push_back(b);
        v_node[b].push_back(a);
    }

    for(int i=1;i<=node;i++)
        color[i]='w';
    int source;
    cout<<"insert source node"<<endl;
    cin>>source;
    cout<<"Path for DFS"<<endl;
    DFS(source);

}

//dijkstra
priority_queue<pair<int, int>> q;
vector<pair<int,int> > g[1000];
vector<int> dist(1000,INT_MAX);
vector<int> p(1000,-1);\
set<int> s;

void go(int dest){
    if(p[dest]!=dest){
        go(p[dest]);
        cout<<"->";
    }
    cout<<dest;
}

void initialize_single_source(int n, int s)
{
    for(int i=0;i<n+1;i++){
        dist[i] = INT_MAX;
        p[i] = i;
    }
    dist[s] = 0;
}

void relax(int parent,int child,int weight){
    if(dist[parent]+weight < dist[child]){
        dist[child]=dist[parent]+weight;
        p[child]=parent;

            q.push(make_pair(dist[child],child));
    }
}

void dijkstra(int source,int node)
{
    initialize_single_source(node,source);
    q.push(make_pair(0, source));
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        int parent=u.second;
        for(int v:g[parent]){
            int child=v.first;
            int weight=v.second;
            relax(parent,child,weight);
        }
    }
}

void dijkstra_run()
{
    int node,edge;
    cin>>node>>edge;
    cout<<"From : To : Weight"<<endl;
    for(int i=0;i<edge;i++){
        int from, to, weight;
        cin>>from>>to>>weight;
        g[s].push_back(make_pair(d,w));
    }
    int source;
    cin>>source;
    dijkstra(source,node);
    for(int i=1;i<=node;i++){
        cout<<i<<") cost: "<<dist[i]<<" , Path: ";
        go(i);
        cout<<endl;
    }


}

int main()
{
}
