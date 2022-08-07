#include <iostream>
#include <unordered_map>
#include <list>



using namespace std;

template <typename T>

class graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        // direction=0-->undirected graph
        // direction=1-->directed graph

        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdj()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};
int main()
{
    //Taking Input The No. Of Nodes
    int n;
    cout<<"Enter The Number Of Nodes"<<endl;
    cin>>n;
    // Taking Input The No. Of Edges
    int m;
    cout << "Enter The Number Of Edges" << endl;
    cin >> m;

    graph<int> g;//g is the object of type/class graph
    
    for(int i=0;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        //Creating an undirected graph;
        g.addEdge(u,v,0);
    }
    //printing graph
    g.printAdj();

}
