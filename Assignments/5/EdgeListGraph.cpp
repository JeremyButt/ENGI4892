#include "EdgeListGraph.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeListGraph::EdgeListGraph(const VertexCollection& v,const EdgeCollection& e)
{
  this->myEdges = e;
  this->myVertices = v;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
VertexCollection EdgeListGraph::vertices() const
{
  return myVertices;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeCollection EdgeListGraph::edges() const
{
  return myEdges;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeCollection EdgeListGraph::incidentEdges(const Vertex& v) const
{
  EdgeCollection incidentEdges;
  for(Edge const edge : myEdges){
    if (edge.contains(v)){
      incidentEdges.push_back(edge);
    }
  }
  return incidentEdges;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::areAdjacent(const Vertex& v, const Vertex& w) const
{
  for(Edge const edge : myEdges){
    if(edge.contains(v) && edge.contains(w)){
      return true;
    }
  }
  return false;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::insertVertex(const Vertex& v)
{
  this->myVertices.push_back(v);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::removeVertex(const Vertex& v)
{
  for (std::vector<Vertex>::iterator it = myVertices.begin() ; it != myVertices.end(); ++it){
    if(*it == v){
      myVertices.erase(it);
      EdgeCollection temp = incidentEdges(v);
      for(Edge const edge : temp){
        removeEdge(edge);
      }
      return true;
    }
  }
  return false;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::insertEdge(const Edge& e)
{
  VertexCollection temp = e.endVertices();
  for(Vertex const vertex1 : temp){
    bool found = false;
    for(Vertex const vertex2 : myVertices){
      // TODO add vertex when vertex in edge not already in the vertices vector!!
      if(vertex1 == vertex2){
        found = true;
        break;
      }
    }
    if(!found){
      insertVertex(vertex1);
    }
  }

  this->myEdges.push_back(e);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::removeEdge(const Edge& e)
{
  for (std::vector<Edge>::iterator it = myEdges.begin() ; it != myEdges.end(); ++it){
    if(*it == e){
      myEdges.erase(it);
      return true;
    }
  }
  return false;
}
