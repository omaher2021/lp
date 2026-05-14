#include<iostream>
#include<vector>
#include<queue>
#include<omp.h>
using namespace std;

vector<int> g[10];
bool v[10];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    v[s]=1;

    while(!q.empty()){
        int n=q.front();
        q.pop();

        cout<<n<<" ";

        #pragma omp parallel for.
        for(int i=0;i<g[n].size();i++)
        {
            int x=g[n][i];
            if(!v[x])
            {
                v[x]=1;
                q.push(x);

            }
        }
    }
}
int main()
{
   int vertices,edges;

   cout<<"Enter the number of vertices:";
   cin>>vertices;

   cout<<"Enter the number of edges";
   cin>>edges;

   cout<<"Enter the value(u ,v):"<<endl;
   for(int i=0;i<edges;i++)
   {
    int u, v;
    cin>>u>>v;

    g[u].push_back(v);
    g[v].push_back(u);
   }
   int start;
   cout<<"Enter starting vartex for BFS:";
   cin>>start;
   cout<<"BFS traversal:";
   bfs(start);
    return 0;


}