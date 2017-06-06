#include "vertex.h"

Vertex::Vertex() : pos(glm::vec3(0.0)), edge(nullptr), id(-1), halfEdgesOfCurrVertex() {}

Vertex::Vertex(glm::vec3 p, HalfEdge* e, int i) : pos(p), edge(e), id(i), halfEdgesOfCurrVertex() {
    QListWidgetItem::setText(QString::number(i));
}

Vertex::Vertex(glm::vec3 p, HalfEdge* e, int i, std::vector<HalfEdge*> hEdgesList)
    : pos(p), edge(e), id(i), halfEdgesOfCurrVertex(hEdgesList) {
    QListWidgetItem::setText(QString::number(i));
}

Vertex::Vertex(Vertex* v) : Vertex(v->pos, v->edge, v->id, v->halfEdgesOfCurrVertex) { }

void Vertex::setId(int i) {
    id = i;
    QListWidgetItem::setText(QString::number(i));
}

void Vertex::setHEdge(HalfEdge* h) {
   edge = h;
}

void Vertex::setPos(glm::vec3 p) {
    pos = p;
}

void Vertex::setHEdgeList(std::vector<HalfEdge*> hList) {
    halfEdgesOfCurrVertex = hList;
}

void Vertex::addHEdgeToList(HalfEdge* h) {
    halfEdgesOfCurrVertex.push_back(h);
}

void Vertex::removeHEdgeFromList(HalfEdge* h) {
    int id = h->id;

    bool notFound = true;
    int size = (int)(halfEdgesOfCurrVertex.size());
    for (int i=0; i<size&&notFound; i++) {
        HalfEdge* hEdge = halfEdgesOfCurrVertex[i];
        if (hEdge->id == id) {
            halfEdgesOfCurrVertex.erase(halfEdgesOfCurrVertex.begin() + i);
            notFound = false;
        }
    }
}
