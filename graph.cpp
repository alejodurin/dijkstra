#include "graph.h"
#include "time.h"
#include "random"
#include <vector>
#include <iostream>



//Graph::Graph(){}

Graph::Graph(int _v = 7, double _d = 1.0): V(_v), density(_d)
{
   // this->adj = new std::vector<Router>*[V];
    boolMatrix(V);
    std::cout << "Making a graph...\n";
    while(1)
    {
        makeEdges();
        if (!is_Conected(this->graph, V))
        {
            //std::cout << "Error: Graph not connected." << std::endl;
        }
        else
        {
            std::cout << "Graph connected." << std::endl;
            makeGraph(V);
            break;
        }
    }

}

//Make a boolean matrix.
void Graph::boolMatrix(int size)
{
    srand(time(0));
    this->graph = new bool*[size];
    for (int i=0; i < size; ++i)
    {
        this->graph[i] = new bool[size];
    }
}

void Graph::makeEdges()
{

    srand(time(0));
    for (int i=0; i < V; ++i)
    {
        for(int j=0; j < V; ++j)
        {
            if (i == j) this->graph[i][j] = false; // Not have a  loop.
            else
                this->graph[i][j] = this->graph[j][i]= ( (rand() % 100)) < density; //Probability that exist a edge.
        }
    }
}

void Graph::makeGraph(int size)
{
    std::pair<int,int> routerPair; //Destination - Weight.
    srand(time(0));
    int cost;
    for(int i=0; i < size; ++i)
    {
        for(int j=0; j < size; ++j)
        {
            if (this->graph[i][j])//If exists some relation.
            {
                cost = static_cast<int>((rand() % 100) + 1); //Random cost between 1 and 100.
                routerPair.first = j;
                routerPair.second = cost;
                this->adj[i].push_back(routerPair);
                this->E++;
            }
        }
    }
}

//Set a value of an edge between x and y.
void Graph::set_edge_value(Graph g, int x, int y, int cost)
{
    if(adjacent(g,x,y))
        g.adj[x][y].second = cost;
    else
        std::cout << "Error: Not is an edge between " << x << "and " << y << ".\n";
}

//Verify if exist an edge between x and y.
bool Graph::adjacent(const Graph &g, int x, int y)
{
    return g.graph[x][y];
}

//Add a edge between x and y, if not exist.
void Graph::add(Graph &g, int x, int y)
{
    if (!adjacent(g,x,y))
        g.graph[x][y] = true;
    else
        std::cout << "Error: There is already an edge" << std::endl;
}

//Add a edge between x and y, with cost, if not exists already.
void Graph::add(Graph &g, int x, int y, int cost)
{
    std::pair<int,int> routerPair;
    if (!adjacent(g,x,y))
    {
        g.graph[x][y] = true;

        routerPair.first = y;
        routerPair.second = cost;
        g.adj[x].push_back(routerPair);
    }
    else
        std::cout << "Error: There is already an edge" << std::endl;
}

//Add a edge between x and y, with cost, if not exists already. Using a pair.
void Graph::add(Graph &g, int x, std::pair<int, int> routePair)
{
    if(!adjacent(g,x,routePair.first))
    {
        g.graph[x][routePair.first] = true;
        g.adj[x].push_back(routePair);
    }
    else
        std::cout << "Error: There is already an edge" << std::endl;
}

//Return true if is a conected graph.
bool Graph::is_Conected(bool* graph[], int size)
{
    int old_size = 0, c_size = 0; //c_size : Size of close set.
    bool* close = new bool[size];
    bool* open = new bool[size];
    for(int i=0; i < size; ++i)
        open[i] = close[i] = false;
    open[0] = true; //Set the first element as OPEN SET , true.
    //Add to close set.
    while(c_size < size)
    {
        for(int i=0; i < size; ++i)
        {
            old_size = c_size;
            if (open[i] && (close[i] == false))
            {
                close[i] = true; c_size++;
                for(int j=0; j < size; ++j)
                    open[j] = open[j] || graph[i][j]; //If open set is j, is true, or if have some conected node.
            }
        }
        if(c_size == size) return true; //If all nodes are conected.
        if (old_size == c_size) return false; //If someone are not conected.
    }
    return false;
}


//Show a list of nodes conected with x.
void Graph::neighbors(int x)
{
    std::cout << x << ": ";
    for(auto p : this->adj[x])
        std::cout << p.first << "->";
    std::cout << std::endl;
}

//Return number of vertices.
int Graph::_V()
{
    return V;
}

//Return the number of edges.
int Graph::_E()
{
    return E;
}

int Graph::_MAX()const
{
    return MAX;
}

//Return the vector of adjacencies.
std::vector<Router> *Graph::Adj()
{
    return adj;
}

//Set number of edges.
void Graph::setV(int v){this->V = v;}

//Set number of vertices.
void Graph::setE(int e){this->E = e;}

Graph Graph::operator=(const Graph &g)
{
    int i = 0;
    if (this != &g)
    {
        this->graph = g.graph;
        this->E = g.E;
        this->V = g.V;
        this->density = g.density;
        for(auto p : g.adj)
        {
            i++;
            this->adj[i] = p;
        }
        return *this;
    }
    return *this;
}


void Graph::printGraph()
{
    int i=0;
    for(auto p : this->adj)
    {
        std::cout << i << ": ";
        for(auto j : p)
            std::cout << j.second << "(" << j.first << ")" << " ";
        std::cout << std::endl;
        i++;
    }
}


