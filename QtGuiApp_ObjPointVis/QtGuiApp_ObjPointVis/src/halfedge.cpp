#include "halfedge.h"

//constructors

HalfEdge::HalfEdge()
    : face(nullptr), vert(nullptr), next(nullptr), sym(nullptr), id(-1) {}

HalfEdge::HalfEdge(Face *f, Vertex *v, HalfEdge *n, HalfEdge *s, int i)
    : face(f), vert(v), next(n), sym(s), id(i) {
    QListWidgetItem::setText(QString::number(i));
}

//the following are the setters for the instance variables

void HalfEdge::setFace(Face* f) {
    face = f;
    f->start_edge = this;
}

void HalfEdge::setVert(Vertex* v) {
    vert = v;
    v->edge = this;
}

void HalfEdge::setHEdgeNext(HalfEdge* n) {
    next = n;
}

void HalfEdge::setHEdgeSym(HalfEdge* s) {
    sym = s;
    s->sym = this;
}

void HalfEdge::setID(int i) {
    id = i;
    QListWidgetItem::setText(QString::number(i));
}
