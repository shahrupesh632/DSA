#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>
class Graph{
    public:
    unordered_map<T,list<T>> adj;
    void addEgde(T u,T v,bool direction){
        //direction=0 -> undirected graph
        // direction=1 directed graph
        //creating edge from u to v
        adj[u].push_back(v);
        // creating undirected graph
        if(direction ==0)
        adj[v].push_back(u);
    }
    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph<int> g;
    int n;
    cout<<"Enter the no of nodes: ";
    cin>>n;
    int m;
    cout<<"Enter the no of edges: ";
    cin>>m;
    cout<<"Enter the edges "<<endl;
    int adjMat[n+1][n+1]={0};
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //     {
    //         adjMat[i][j]=0;
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEgde(u,v,0);
        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }
    g.print();
    cout<<endl<<"Using adjcency matrix "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            cout<<adjMat[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
