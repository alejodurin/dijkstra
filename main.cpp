#include <iostream>
#include <dijkstra.h>
#include <graph.h>

int main (void)
{
    Graph g(5,25);
    for(int i=0; i<10;i++)
        g.neighbors(i);
    Dijkstra d(g);
    //d.getGraph().neighbors(0);
    double average= 0.0;
    int count = 0;
    d.dijkstra_algorithm(0,4,average,count);
    g.printGraph();

}
