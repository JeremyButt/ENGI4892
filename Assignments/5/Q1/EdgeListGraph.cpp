// File: EdgeListGraph.cpp
// Author: Jeremy Butt [201527710]
// Finished: July 24th, 2017
// Commented: July 25th, 2017
// Last Modified: July 25th, 2017

#include "EdgeListGraph.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//O(1) because we are just setting 2 member variables
EdgeListGraph::EdgeListGraph(const VertexCollection& v,const EdgeCollection& e)
{
  this->myEdges = e; // load the Edge collection into the object instance
  this->myVertices = v; // load the Vertext collection into the object instance
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//O(1) because we are just returning one value
VertexCollection EdgeListGraph::vertices() const
{
  return myVertices;// return the VertexCollection
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//O(1) because we are just returning one value
EdgeCollection EdgeListGraph::edges() const
{
  return myEdges;// return the Edge collection
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//O(n) worst case wed be going through the entire vector of edges (myEdges)
EdgeCollection EdgeListGraph::incidentEdges(const Vertex& v) const
{
  EdgeCollection incidentEdges;// to store all incidentEdges
  for(Edge const edge : myEdges){// for every edge in myEdges
    if (edge.contains(v)){  // if the edge contains the vertex
      incidentEdges.push_back(edge); // add it to the vertex of incidentEdges
    }
  }
  return incidentEdges;// return vector of incidentEdges
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//O(n) worst case wed be going through the entire vector of edges (myEdges)
bool EdgeListGraph::areAdjacent(const Vertex& v, const Vertex& w) const
{
  for(Edge const edge : myEdges){// for all edges in myEdges
    if(edge.contains(v) && edge.contains(w)){ // if the edge contains both the vertices
      return true;// they are adjacent
    }
  }
  return false;// else nope they are not adjacent
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//O(n) if the vertex is not in myVertices then O(n).
bool EdgeListGraph::insertVertex(const Vertex& v)
{
  bool found = false;
  for(Vertex const vertex : myVertices){
    if(vertex == v){
      found = true;
    }
  }
  if(!found)
    this->myVertices.push_back(v);// push the vertext into the VertexCollection myVertices
  return found;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// O(m+n+x) because of looping though 2 vectors of different length. (m - is length of the myVertices vector.
//                                                                    n - length of the incidentEdges
//                                                                    x- length of myedges)
bool EdgeListGraph::removeVertex(const Vertex& v)
{
  for (std::vector<Vertex>::iterator it = myVertices.begin() ; it != myVertices.end(); ++it){ // for all the vertices in myVertices (iterator approach to have iterator to perform operations)
    if(*it == v){ // if v == current vertex
      myVertices.erase(it);// erase the current vertex
      EdgeCollection temp = incidentEdges(v); // get a collection of edges for all incidentEdges of the vertex
      for(Edge const edge : temp){// for every edge in the incidentEdges
        removeEdge(edge);// remove that edge from the myEdges  vector
      }
      return true;// was removed
    }
  }
  return false; // wasnt removed (not found to remove)
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// O(n) because looping thought 2 vectors of different lengths(n - endVertices which is always 2
//                                                             m - myVertices)
//
bool EdgeListGraph::insertEdge(const Edge& e)
{
  VertexCollection temp = e.endVertices(); // vertex collection for all the end vertices of the edge
  for(Vertex const vertex1 : temp){ // for all end vertices
    bool found = false; // bool to see if found
    for(Vertex const vertex2 : myVertices){ // for all vertices in myVertices
      if(vertex1 == vertex2){// if the vertices match
        found = true; // found a match
        break; // break out of the loop
      }
    }
    if(!found){ // if the vertices was not found in the myVertices vector
      insertVertex(vertex1); // add the vertex to myVertices
    }
  }

  this->myEdges.push_back(e); // add the edge to the myEdges vector
  return true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// O(n) because looping through myEdges
bool EdgeListGraph::removeEdge(const Edge& e)
{
  for (std::vector<Edge>::iterator it = myEdges.begin() ; it != myEdges.end(); ++it){ // for all edges in myEdges (iterator approach)
    if(*it == e){ // if current edge matches edge e
      myEdges.erase(it); // erase the current edge at "it"
      return true; // was removed
    }
  }
  return false; // wasnt removed
}
