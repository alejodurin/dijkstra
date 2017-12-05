#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>


const int MAXout = 20;
typedef std::pair<int,int> Router;
struct cmp {
    bool operator() ( const Router &a , const Router &b ) {
        return a.second > b.second;
    }
};

class Graph
{
public:
    //Constructors.
    //Graph();
    Graph(int v, double density);

    //Setters and Getters.
    int _V(); // Return the number of vertices in the graph.
    int _E(); // Return the number of egdes in the graph.
    int _MAX()const;
    void setV(int v);
    void setE(int e);
    int get_node_value(Graph g, int x); // Return the value associated with the node x.
    void set_node_value(Graph g, int x,int a); // Set the value associated with the node x to a.
    int get_edge_value(Graph g, int x, int y); // Return the value associated with a edge between x and y.
    void set_edge_value(Graph g, int x, int y, int cost); // Set the value associated with a edge between x and y. With a cost.


    std::vector<Router>* Adj();
    bool adjacent(const Graph &g, int x, int y); // Test whether there is an edge between node x and y.
    void neighbors(int x); // List all nodes y such that there is an edge from x to y.

    //Functions to add edges.
    void add(Graph &g, int x, int y); //Add a edge to g, from x to y. If not exists.
    void add(Graph &g, int x, int y, int cost); //Add a edge to g, from x to y. If not exists.
    void add(Graph &g, int x, std::pair<int,int> routePair); // Set the value associated with a edge between x and y. With a cost. Using a pair.

    void deleteEdge(Graph g, int x, int y); //Remove the edge from x to y, if it's there.

    void printGraph();

    void loadAdjadences(std::vector<Router> adj[], const std::vector<std::vector<int>> &graphT, int size, bool **graph);
    void makeGraph(int size);
    void boolMatrix(int size);
    void makeEdges();
    bool is_Conected(bool* graph[], int size);
    Graph operator=(const Graph& g);

private:
    bool** graph;
    const int INF = 1 << 30;
    const int MAX = 20;
    int V; //Vertices.
    int E; //Edges.
    double density;
    std::vector<Router> adj[MAXout]; //Define a router as a pair(firs,second), where first is a vertex adjacent, and second is a weight of the edge.


};

#endif // GRAPH_H
