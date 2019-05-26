/**
 * A testbed for methods of a  weighted diagraph and implementations of 
 * basic weighted digraph algorithms.
 * @author Duncan, Aaron Cao
 * @since 04-18-2017
 * @see Graph.cpp, City.cpp, City.h
 */

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <limits>
#include <iomanip>
#include <string>
#include <queue>
#include <vector>
#include <functional>
#include "City.h"
#include "Graph.h"
#include "Graph.cpp"

using namespace std;

#define INFINITY numeric_limits<double>::max()

/* function prototypes */   
void display(const City& c);
void readGraph(Graph<City>& newGraph, string filename);
int menu();
void floyd(const Graph<City>& g, double**& dist, int**& path);
void dijkstra(Graph<City> g, double dist[], int pred[], int source, int destination);
void dfsOut(const Graph<City>& g, int v, bool seen[], int linearOrder[], int& index);
void topoSort(const Graph<City>& g, int* linearOrder);
double  primMST(const Graph<City>& g, int root, int* parent) throw (GraphException);

int main(int argc, char **argv)
{
   if (argc != 2)
   {
      cout << "Usage: GraphDemo <filename>" << endl;
      exit(1);
   }
   Graph<City> g;
   City aCity1, aCity2;
   int menuReturnValue, i, j;  
   int* top; //for argument to topoSort in Project # 5
   int* mst; //for argument to primMST in Project # 5  
   readGraph(g,argv[1]);
   long s = g.size();
   menuReturnValue = -1;
   while (menuReturnValue != 0)
   {
      menuReturnValue = menu();
      switch(menuReturnValue)
      {
         case 1: //Adjacency Matrix
          {
            //write code to generate the adjacency matrix
            cout << fixed << endl;
            cout << "Adjacency Matrix For The Graph In" << argv[1] << endl;
            cout << "==============================================================================================" << endl;
            cout << setw(8);

            for(int i = 1; i <= s; i++)
                cout << i << setw(4);

            cout << endl;

            for(int i = 1; i <= s; i++)
            {
                cout << i << setw(5);

                for(int j = 1; j <= s; j++)
                {
                    if (g.retrieveVertex(i) == g.retrieveVertex(j))
                        cout << "0" << setw(4);

                    else if (g.isEdge(i,j))
                        cout <<  setprecision(0) << g.retrieveEdge(i,j) << setw(4);

                    else
                        cout << "INF" << setw(4);
                }
                cout << endl;
            }
            cout << "==============================================================================================" << endl;
            cout << endl << endl;
            break;
          }
        
         case 2: //Transitive Closure Matrix
          {
            //write code to generate the transitive closure matrix
            cout << fixed << endl;
            cout << "Transitive Closure Matrix For The Graph In" << argv[1] << endl;
            cout << "==============================================================================================" << endl;
            cout << setw(8);

            for(int i = 1; i <= s; i++)
                cout << i << setw(4);

            cout << endl;

            for(int i = 1; i <= s; i++)
            {
                cout << i << setw(5);

                for(int j = 1; j <= s; j++)
                {
                    if (g.retrieveVertex(i) == g.retrieveVertex(j))
                        cout << "1" << setw(4);

                    else if(g.isReachable(i,j))
                        cout << "1" << setw(4);

                    else
                        cout << "0" << setw(4);
                }
                cout << endl;
            }

            cout << "==============================================================================================" << endl;
            cout << endl << endl;
            break;

         case 3://Shortest-path algorithm
            cout<<"Enter the source vertex: ";
            int src;
            cin>>src;
            City srcCity = City(src);           
            cout<<"Enter the destination vertex: ";  
            int dest;
            cin>>dest;
            City destCity = City(dest);                     
            if (g.isReachable(srcCity,destCity))
            {
               double totalDistance = 0;
                  
               //Declare additional variables and arrays as necessary
               int size = g.size();
               int path[size][size];
               double distance[size][size];
                  
               cout << "Shortest route from " << srcCity.getLabel() << " to " << destCity.getLabel() << ":" << endl;                
               cout << "==============================================================================================" << endl;              
               //Write code to call either dijkstra or floyd method and then     
               //Give all intermediate connections beginning with the source city and ending
               //with the destination city aligned in column format as indicated below:
               //
               //        cityX            ->             cityY           distance
               //
               //Display the intermediate distances one per line
               for (i = 1; i < size; i++)
               {
                  for(j = 1; j < size; j++)
                  {
                     path[i][j] = 0;
                     distance[i][j] = g.retrieveEdge(i, j);
                  }
               }
                
               for(int i = 1; i < size; i++)
               {
                  for(int j = 1; j < size; j++)
                  {
                     for(int k = 1; k < size; k++)
                     {
                        if(distance[j][k] > distance[j][i] + distance[i][k])
                        {
                           path[j][k] = i;
                           distance[j][k] = g.retrieveEdge(j,k);
                        }
                     }
                  }
                 cout<< src << " -> " << dest << " distance of " << distance[src][dest] << " with path of " << path[src][dest];
               }
               cout << "==============================================================================================" << endl;
               cout << "The total distance  " << setprecision(2) << totalDistance << " miles." << endl << endl;
            }
            else
               cout << "There is no path." << endl << endl;
            break;
         }
         case 4: //post-order depth-first-search traversal
            cout<<endl;
            cout<<"PostOrder DFS Traversal For The Graph In "<<argv[1]<<endl;
            cout<<"==============================================================="<<endl;

            g.dfsTraverse(display);

            cout<<"==============================================================="<<endl;
            cout<<endl;
            cout<<endl;
            break;
         case 5: //breadth-first-search traversal
            cout<<endl;
            cout<<"BFS Traversal For The Graph In "<<argv[1]<<endl;
            cout<<"==============================================================="<<endl;

            g.bfsTraverse(display);

            cout<<"==============================================================="<<endl;
            cout<<endl;
            cout<<endl;
            break;
         case 6: //number of edges
            cout<<endl;
            cout<<"The graph has "<<g.countEdges()<<" edges."<<endl;
            cout<<endl;
            break;
         case 7: //topoSort
            cout<<endl;
            cout<<"Topological Sorting of The Graph In "<<argv[1]<<endl;
            cout<<"==============================================================="<<endl;
            top = new int[(int)g.size()];
            topoSort(g,top);
            for (i=1; i<=g.size(); i++)
            {
                aCity1 = g.retrieveVertex(City(top[i-1]));
                display(aCity1);
            }
            cout<<"==============================================================="<<endl;
            cout<<endl<<endl;
            break;
         case 8: //primMST
            cout<<"Enter the root of the MST: ";
            cin>>j;
            mst = new int[(int)g.size()];
            double totalWeight = primMST(g,j,mst);
            for (i=1; i<=g.size(); i++)
                cout<<"parent["<<i<<"] = "<<mst[i-1]<<endl;
            cout<<"The weight of the minimum spanning tree/forest is "<<totalWeight<<" miles."<<endl<<endl;
            break;
         //default: ;
      }
   }
   return 0;
}     

/**
   This function displays a City class object.
   @param c a City class object
   @return none.
*/
void display(const City& c)
{
   cout << left << setw(3) << c.getKey() << " " << left << setw(2) << c.getLabel() << endl;
}


/**
   This function reads a text file formatted as described in the project 
   description.
   @param filename the name of the DIMACS formatted graph file.
   @return an instance of a graph.
*/

void readGraph(Graph<City>& newGraph, string filename)
{
   fstream inFile;
   char temp;
   string tmp;
   int key,v1, v2, size=0, nEdges=0;
   double weight;
   inFile.open(filename.c_str());
   if (inFile.fail())
   {
      cerr << "Error opening " << filename << endl;
      exit(1);
   }
   while (inFile >> temp)
   {
      if (temp == 'p')
      {
         inFile>>size;
         inFile>>nEdges;
      }
      if (temp == 'c')
      {
         getline(inFile,tmp);
      }
      if (temp == 'n')
      {
         inFile>>key;
         getline(inFile,tmp);
         newGraph.insertVertex(City(key,tmp.c_str()));
      }

      if (temp == 'e')
      {
         inFile>>v1;
         inFile>>v2;
         inFile>>weight;
         newGraph.insertEdge(City(v1),City(v2),weight);
      }
   }
   inFile.close();
}

/**
   This function displays the menu interface for the weighted
   digraph application.
   @return an integer representing the menu option selected.
*/
int menu()
{
   int option;
   do
   {
      cout << "  BASIC WEIGHTED GRAPH APPLICATION   " << endl;
      cout << "=====================================" << endl;
      cout << "[1] Adjacency Matrix" << endl;
      cout << "[2] Transitive Matrix" << endl;
      cout << "[3] Single-source Shortest Path" << endl;
      cout << "[4] Postorder DFS Traversal" << endl;
      cout << "[5] BFS Traversal" << endl;
      cout << "[6] Number of Edges" << endl;
      cout << "[7] Topological Sort Labeling" << endl;
      cout << "[8] Prim's Minimal Spanning Tree" << endl;
      cout << "[0] Quit" << endl;
      cout << "=====================================" << endl;
      cout << "Select an option: ";
      cin>>option;
      if (option < 0 || option > 8)
         cout << "Invalid option...Try again" << endl << endl;
      else
         return option;
   }while(true);
}

/**
   This method computes the cost and path matrices using the
   Floyd all-pairs shortest path algorithm.
   @param g an instance of a weighted directed graph.
   @param dist a matrix containing distances between pairs of vertices.
   @param path a matrix of intermediate vertices along the path between a pair
   of vertices. 0 indicates that the two vertices are adjacent.
   @return none.
*/
void floyd(const Graph<City>& g, double**& dist, int**& path)
{
    
    int size = g.size();

    for(int i = 1; i < size; i++)
    {
        for(int j = 1; j < size; j++)
        {
            for(int k = 1; k < size; k++)
            {
                if(dist[j][k] > dist[j][i] + dist[i][k])
                {
                  path[j][k] = i;
                  dist[j][k] = g.retrieveEdge(j, k);
                }
            }
        }
    }  
} 


/**
 * This method computes the cost and path arrays using the 
 * Dijkstra's single-source shortest path greedy algorithm.
 * @param g an instance of a weighted directed graph
 * @param dist an array containing shortest distances from a source vertex
 * @param pred an array containing predecessor vertices along the shortest path
 */
void dijkstra(Graph<City> g, double dist[], int pred[], int source, int destination)
{
   //Implement this function or floyd function above (not both).      
}

/**
 * an auxilliary function for the topoSort method.
 * @param g a weighted directed graph
 * @param v current vertex
 * @param seen a 1-D boolean matrix of vertices that
 *        have been marked.
 * @param linearOrder a 1-D array containing the
 *        topologically sorted list.
 * @param index current index.
 */
void dfsOut(const Graph<City>& g, int v, bool seen[], int linearOrder[], int& index)
{
   seen[v] = true;

   for (int w = 0; w < g.size(); w++)
   {
        if (g.isEdge(v, w))
        {
            if (seen[w] == false)
                dfsOut(g, w, seen, linearOrder, index);
        }
   }
   linearOrder[index] = v;
   index = index - 1;
}

/**
   This method generates a listing of the vertices of a weighted
   directed graph using the reverse dfs topological sorting.
   @param g a weighted directed graph
   @param linearOrder an array in which the topologically sorted
          list is stored.
   @return none
*/ 
void topoSort(const Graph<City>& g, int* linearOrder)
{
    int size = g.size();
    bool seen[size];
    int count = size;

    for (int i = 0; i < size; i++)
    {
        seen[i] = false;
    }

    for (int i = 0; i < size; i++)
    {
        if (seen[i] == false)
            dfsOut(g, i, seen, linearOrder, count);
    }
}

/**
 * An auxilliary data structure to store the information
 * about an edge.
*/
class EdgeType
{
public:
    /**
     * the weigth on this edge
     */
    double weight;
    /**
     * the source vertex
     */
   int source;
   /**
    * the destination vertex
    */
   int destination;
   /**
    * for tracking purposes in Prim's algorithm
    */
   bool chosen;
};

/**
 * auxilliary function to sort the edgelist
 * Required for the STL qsort function
 * @param arg1 first value
 * @param arg2 second value
 * @return -1 when arg1 comes before arg2, 0 when they are
 * the same, otherwise 1.
*/
int ecompare(const void* arg1, const void* arg2)
{  
   EdgeType e1;
   EdgeType e2;
   e1 = *((EdgeType*)arg1);
   e2 = *((EdgeType*)arg2);
   if (e1.weight < e2.weight)
      return -1;
   else if (e1.weight > e2.weight)
      return  1;
   else if (e1.source < e2.source)
      return -1;
   else if (e1.source > e2.source)
      return 1;
   else if (e1.destination < e2.destination)
      return -1;
   else if (e1.destination > e2.destination)
      return 1;
   else
      return 0;
}

/**
 * This method generates a minimum spanning tree rooted at a given
 * vertex, root. If no such MST exists, then it generates a minimum
 * spanning forest with one of the subtrees at root and with the
 * roots of the other subtrees being the vertex with the smallest
 * key in each  subtree.
 * @param g a weighted directed graph
 * @param r root of the minimum spanning tree, when one exists.
 * @param parent the parent implementation of the minimum spanning tree/forest
 * @return the weight of such a tree or forest.
 * <pre>
 * {@code If a minimum spanning tree rooted at r is in the graph,
 *           the parent implementation of a minimum spanning tree or forest is
 *           determined. If no such tree exist, the parent implementation
 *           of an MST is generated. If the tree is empty, an exception
 *          is generated.
 * }
 * </pre> 
 */ 
double  primMST(const Graph<City>& g, int root, int* parent) throw (GraphException)
{
    double totalWeight = 0;
    /*
    int size = g.size();
    priority_queue<EdgeType, vector<EdgeType>, function<int(EdgeType,EdgeType)>> pQueue(ecompare);
    pQueue.push(make_pair(0, root));
    key[root] = 0;

    while (!pQueue.empty())
    {
        int p = pQueue.top().second();
        pQueue.pop();
        p.chosen = true;

    }
    */

    return totalWeight;
}