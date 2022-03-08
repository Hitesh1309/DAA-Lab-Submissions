#include <bits/stdc++.h>

using namespace std;

int n;
queue<int> v;

struct node_ds // nodes have data and its corresponding tree lvl
{
    int data;         // holding data
    int BFS_tree_lvl; // lvl in BFS
    int DFS_tree_lvl; // lvl in DFS
};

struct edge_ds
{
    int edge_g;         // stored as in 2-d array [source][destination]
    int edge_BFS;       // 1 if its present
    int edge_DFS;       // same as above
    int back_track_BFS; // edge present in graph but not in BFS tree
};

node_ds nodes[1000]; // nodes with data and lvl data  [index] same as data here (since int)

edge_ds edges[1000][1000]; // adjacent matrix

int visted_BFS[1000] = {0}; // list where it marks if it is visted or not
int visted_DFS[1000] = {0}; //  same as above

void BFS(int a)
{
    visted_BFS[a] = 1;

    //queue<int> temp;

    for (int i = 1; i <= n; i++)
    {
        if (edges[a][i].edge_BFS == 0 && edges[a][i].edge_g == 1 && visted_BFS[i] == 0 && a != i) // check conditions for not visted and if edge is present or not
        {
            visted_BFS[i] = 1;        // marking it visted
            edges[a][i].edge_BFS = 1; // below is 1 becoz its undirected graph
            edges[i][a].edge_BFS = 1;
            nodes[i].BFS_tree_lvl = nodes[a].BFS_tree_lvl + 1; // marking lvl
            v.push(i);                                         // this is to note down children of the current parent node of the tree
        }
    }

    if (!v.empty())
    {
        int t = v.front();
        v.pop();

        BFS(t);
    }
    cout << "\n";

    if (v.empty())
        return;
}
// 1 2 3 4 6
// 2 3 -> t = 2 | q -> 3
// 3 4 6 -> t = 3 | q -> 4 6
// 4 6 7 -> t = 4 | q -> 6 7
// 6 7 6 5 -> t = 6 | q-> 7 6 5
// 7 6 5 5 -> t = 7 | q-> 6 5 5

void DFS(int a) //along with back track
{
    if (a == 0)
        return;

    visted_DFS[a] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (edges[a][i].edge_DFS == 0 && edges[a][i].edge_g == 1 && visted_DFS[i] == 0 && a != i)
        {
            visted_DFS[i] = 1; // same with DFS as the BFS
            edges[a][i].edge_DFS = 1;
            edges[i][a].edge_DFS = 1;
            nodes[i].DFS_tree_lvl = nodes[a].DFS_tree_lvl + 1;

            DFS(i); // but recursing here itself since going depth first
        }
    }
}

bool check_connect_BFS()
{
    int n1 = 0; // counter to check the no. of edges in a tree

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++) // considering only upper half triangle
        {
            if (edges[i][j].edge_BFS == 1)
                n1++; // counter ++
        }
    }

    if (n1 == n - 1)
        return true; // trees have n-1 edges only

    else
        return false; // else return false
}

void check_cycle(bool &iscycle, bool &isbipart) // default false | true
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (edges[i][j].back_track_BFS == 1)
            {
                iscycle = true; // if there exist a back track then cycle exist

                if (nodes[j].BFS_tree_lvl == nodes[i].BFS_tree_lvl) // if the back track edge exist in the same node BFS lvl then its a odd cycle therefore not bipart
                {
                    isbipart = false;
                }
            }
        }
    }
}

void insert_edge(int a, int b) // simple function to add edge
{
    edges[a][b].edge_g = 1;
    edges[b][a].edge_g = 1;

    if (a == b)
        edges[a][b].edge_g = 0; // edge to itself not considered here
}

int main()
{
    cout << "\nEnter number of nodes: ";
    cin >> n; // Enter no. of nodes

    cout << "\nEntering nodes as 1,2....n format\n\n";

    cout << "\nEnter " << n << " chars are the name of the nodes:\n";
    for (int i = 1; i < n; i++)
    {
        nodes[i].data = i;         // here index is the data itself
        nodes[i].BFS_tree_lvl = 0; // assigning default values
        nodes[i].DFS_tree_lvl = 0;
    }
    cout << "\n";

    bool temp = true;
    int a, b;

    while (temp)
    {
        cout << "In range of 1-" << n << " enter (enter 0 or out of range to exit the adding of edges):\n";
        cout << "Source node: ";
        cin >> a;
        cout << "Destination node: ";
        cin >> b;
        cout << "\n";
        insert_edge(a, b);

        if (a > n || a < 1 || b < 1 || b > n) // when out of range nodes are given ie <1 and >n then loop exit
            break;
    }

    cout << "\n\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << edges[i][j].edge_g << " "; // displaying the graph adj. matrix
        }
        cout << "\n";
    }

    BFS(1); // calling bfs wrt 1

    cout << "\nBFS adj. matrix:\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << edges[i][j].edge_BFS << " ";                                    // displaying BFS adj. matrix
            edges[i][j].back_track_BFS = edges[i][j].edge_g - edges[i][j].edge_BFS; // assign back edges as well ( 1-0 | 1-1 | 0-0)
        }
        cout << "\n";
    }

    cout << "\n\n";

    cout << "\nDisplaying BFS lvl:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << nodes[i].BFS_tree_lvl << "\n"; // displaying node lvl in the BFS trss
    }

    DFS(1); // calling dfs

    cout << "\nDFS adj. matrix\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << edges[i][j].edge_DFS << " "; // displaying DFS adj. matrix
        }
        cout << "\n";
    }

    cout << "\n\n";

    cout << "\nDisplaying DFS lvl:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << nodes[i].DFS_tree_lvl << "\n"; // displaying nodes DFS lvls
    }

    cout << "\n\n";

    cout << "\nChecking if the graph is connected using the BFS matrix: ";

    if (check_connect_BFS()) // check_connect_BFS returns boolean value
        cout << "Graph is connected\n";

    else
        cout << "Graph is not connected\n";

    cout << "\n";

    bool iscycle, isbipart; // booleans holding whether it is or not (respectively as the name suggests)

    iscycle = false;
    isbipart = true; // default true for no edges could be splited in two sets of any combinations

    check_cycle(iscycle, isbipart); // check_cycle will change values of those boolean respectively

    cout << "\nCycle exists? : ";

    if (iscycle)
        cout << "Yes\n";
    else
        cout << "No\n";

    cout << "\nBipartiteness exists? : ";

    if (isbipart)
        cout << "Yes\n";
    else
        cout << "No\n\n";
}

// DFS trees more than one possibilities
