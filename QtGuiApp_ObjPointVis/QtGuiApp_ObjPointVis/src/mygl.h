#ifndef MYGL_H
#define MYGL_H

#include "glwidget277.h"
#include "utils.h"
#include "shaderprogram.h"
#include "camera.h"

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>

#include "halfedgemesh.h"
#include "mylistwidget.h"

#include "highlightface.h"
#include "highlightvertex.h"
#include "highlighthedge.h"
#include "highlightpoint.h"

#include "highlightallpoints.h"
#include "HighlightallobjV.h"

#include "point.h"

#include "scene/intersection.h"

class MyGL
    : public GLWidget277
{
    Q_OBJECT
private:
    //Cylinder geom_cylinder;// The instance of a unit cylinder we can use to render any cylinder
    //Sphere geom_sphere;// The instance of a unit sphere we can use to render any sphere
    ShaderProgram prog_lambert;// A shader program that uses lambertian reflection
    ShaderProgram prog_flat;// A shader program that uses "flat" reflection (no shadowing at all)

    GLuint vao; // A handle for our vertex array object. This will store the VBOs created in our geometry classes.
                // Don't worry too much about this. Just know it is necessary in order to render geometry.

    Camera gl_camera;

    /// Timer linked to timerUpdate(). Fires approx. 60 times per second
    QTimer timer;

    //mesh data variables
    HalfEdgeMesh geom_halfMesh;

    //highlighting variables
    HighlightVertex hVert; 
	HighlightPoint hPoint;
	HighlightAllPoints allPoints; 
	HighlightAllObjV allObjVertices;

    //openGL Fun variables
    int timeCount; 
    int renderMode; 
    int posMode; 

	// if currently set to have allPoints render in mygl
	bool drawing;
	// if currently set to view all obj vertices
	bool viewObjV;
	// view mesh
	bool viewMesh;
	// creating mode turned on or off
	bool creatingPoints;
	// current max point id for next created point
	int nextPointId;

    //loading an object
    //  bc list indexing starts at 1 versus 0 so when adding new
    //  items during extrusion and vertex etc need to account for proper num
    bool loadingObject;

	//variables for mouse behavior
	QPoint mouseOffset;

public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    HalfEdge* getPrevHEdge(HalfEdge* h); 

protected:
    void keyPressEvent(QKeyEvent *e);	
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);

    //used when parsing the files for data
    Vertex* parseLineForVertex(std::string); 
    Face* parseLineForFace(std::string,
                           std::vector<Vertex*>&,
                           std::map<Face*,
                           std::vector<Vertex*>>&); 
	Point* parseLineForPoint(std::string, int);

    void buildHEdges(std::vector<Face*> &,
                     std::vector<HalfEdge*>&,
                     std::map<Face*, std::vector<Vertex*>>&,
                     std::map<Vertex*, std::vector<HalfEdge*>>&,
                     int&); 
    void linkSymsForHEdges(std::vector<HalfEdge*>&,
                           std::map<Vertex*, std::vector<HalfEdge*>>&); 

	void highlightVertex(Vertex*);
	void highlightPoint(Point*);

	void redoPointIdNumbers();

	void mouseClickFindIntersect(QMouseEvent *);

	//void raycast(glm::vec2 pt, glm::vec3* origin, glm::vec3* dir);
	//void mouseClickFindIntersect(QMouseEvent *e);

private slots:
    /// Slot that gets called ~60 times per second
    void timerUpdate();

public slots:
    void slot_vertexItemClicked(QListWidgetItem*);
	void slot_interestPointItemClicked(QListWidgetItem*);

    void slot_loadFileData(QString);
	void slot_loadPointsFromTxt(QString);
	void slot_savePointsToTxt(QString);

	void slot_recenter();

	void slot_removedInterestPoint();

	void slot_removedPoint(QListWidgetItem*);
	void slot_addPointFromVertex();

	void slot_highlightVertexById(int);
	void slot_highlightPointById(int);

	void slot_viewPointsSet(bool);
	void slot_viewObjVertices(bool);

	void slot_viewMesh(bool);
	void slot_creatingPoints(bool);

signals:
    void sig_addVertex(QListWidgetItem*);
	void sig_vertexChanged(QListWidgetItem*);

	void sig_addPoint(QListWidgetItem*);

	void sig_clearVertexList();
	void sig_clearPointList();

	void sig_invalidTxtFileLine(int);

	void sig_addSelectedVertPoint(QListWidgetItem*);
	void sig_removeSelectedVertPoint(QListWidgetItem*);

    void sig_DisplayPosX(double);
    void sig_DisplayPosY(double);
    void sig_DisplayPosZ(double);

	void sig_preExistingVertex(int);
};


#endif // MYGL_H
