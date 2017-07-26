// File: EdgeListGraph.cpp
// Author: Jeremy Butt [201527710]
// Finished: July 24th, 2017
// Commented: July 25th, 2017
// Last Modified: July 25th, 2017

#include "EdgeListGraph.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeListGraph::EdgeListGraph(const VertexCollection& v,const EdgeCollection& e)
{
  this->myEdges = e; // load the Edge collection into the object instance
  this->myVertices = v; // load the Vertext collection into the object instance
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
VertexCollection EdgeListGraph::vertices() const
{
  return myVertices;// return the VertexCollection
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeCollection EdgeListGraph::edges() const
{
  return myEdges;// return the Edge collection
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
bool EdgeListGraph::insertVertex(const Vertex& v)
{
  this->myVertices.push_back(v);// push the vertext into the VertexCollection myVertices
  return true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
