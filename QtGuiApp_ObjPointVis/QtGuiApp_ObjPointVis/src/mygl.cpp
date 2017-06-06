#include "mygl.h"
#include "la.h"

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

#include <QApplication>
#include <QEvent>
#include <QKeyEvent>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>

#include "face.h"
#include "vertex.h"
#include "halfedge.h"


#define DBOUT( s )            \
{                             \
   std::ostringstream os_;    \
   os_ << s;                   \
   OutputDebugString( os_.str().c_str() );  \
}

class Face;
class Vertex;
class HalfEdge;

MyGL::MyGL(QWidget *parent)
	: GLWidget277(parent),
	//geom_cylinder(this), geom_sphere(this),
	prog_lambert(this), prog_flat(this),
	gl_camera(),
	geom_halfMesh(this),
	hVert(this), hPoint(this),
	allPoints(HighlightAllPoints(this)), allObjVertices(HighlightAllObjV(this)),
	timeCount(0), renderMode(0), posMode(0),
	loadingObject(false),
	mouseOffset(QPoint(0, 0)),
	drawing(true), viewObjV(true), viewMesh(true),
	creatingPoints(true),
	nextPointId(1)
{
    // Connect the timer to a function so that when the timer ticks the function is executed
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    // Tell the timer to redraw 60 times per second
    timer.start(16);

    this->setFocusPolicy(Qt::StrongFocus);
}

MyGL::~MyGL()
{
    makeCurrent();
    glDeleteVertexArrays(1, &vao);
    //geom_cylinder.destroy();
    //geom_sphere.destroy();
    geom_halfMesh.destroy();
    hVert.destroy(); 
	hPoint.destroy();
	allPoints.destroy();
}

void MyGL::initializeGL()
{
    // Create an OpenGL context using Qt's QOpenGLFunctions_3_2_Core class
    // If you were programming in a non-Qt context you might use GLEW (GL Extension Wrangler)instead
    initializeOpenGLFunctions();
    // Print out some information about the current OpenGL context
    debugContextVersion();

    // Set a few settings/modes in OpenGL rendering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    // Set the size with which points should be rendered
    glPointSize(5);
    // Set the color with which the screen is filled at the start of each render call.
    glClearColor(0.5, 0.5, 0.5, 1);

    printGLErrorLog();

    // Create a Vertex Attribute Object
    glGenVertexArrays(1, &vao);

    // GEOMETRY
    //geom_halfMesh.makeCube();
	// starting with cube geometry
	QString file = QString("./_objFiles/cube.obj");
	slot_loadFileData(file);
	for (Vertex* v : geom_halfMesh.vertices) {
		emit sig_addVertex(v);
	}
    
    renderMode = 0;
    
	// SHADERS
    prog_lambert.create(":/glsl/lambert.vert.glsl", ":/glsl/lambert.frag.glsl");
    prog_flat.create(":/glsl/flat.vert.glsl", ":/glsl/flat.frag.glsl");
    prog_lambert.setGeometryColor(glm::vec4(0,1,0,1));

    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
//    vao.bind();
    glBindVertexArray(vao);
}

void MyGL::resizeGL(int w, int h)
{
    //This code sets the concatenated view and perspective projection matrices used for
    //our scene's camera view.
    gl_camera = Camera(w, h);
    glm::mat4 viewproj = gl_camera.getViewProj();

    // Upload the view-projection matrix to our shaders (i.e. onto the graphics card)

    prog_lambert.setViewProjMatrix(viewproj);
    prog_flat.setViewProjMatrix(viewproj);
    prog_lambert.setModelMatrix(glm::mat4(1.0f));
    prog_flat.setModelMatrix(glm::mat4(1.0f));

    printGLErrorLog();
}

//This function is called by Qt any time your GL window is supposed to update
//when the function updateGL is called, paintGL is called implicitly.
void MyGL::paintGL()
{
    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    prog_flat.setViewProjMatrix(gl_camera.getViewProj());
    prog_lambert.setViewProjMatrix(gl_camera.getViewProj());

	#define NOPE
	#ifdef NOPE
//    prog_lambert.setModelMatrix(glm::mat4(1.0));
//    prog_lambert.draw(geom_cylinder);

	if (viewMesh) {
		prog_lambert.draw(geom_halfMesh);
	}
    
	if (allObjVertices.vertices.size() > 0 && viewObjV) {
		prog_flat.draw(allObjVertices);
	}
	
	if (allPoints.points.size() > 0 && drawing) {
		prog_flat.draw(allPoints);
	}

    glDisable(GL_DEPTH_TEST);
	if (hVert.currentVertex != nullptr) {
		prog_flat.draw(hVert);
	}
	if (hPoint.currentPoint != nullptr) {
		prog_flat.draw(hPoint);
	}
    glEnable(GL_DEPTH_TEST);
	#endif
}


void MyGL::keyPressEvent(QKeyEvent *e)
{
	float amount = 2.0f;
	if (e->modifiers() & Qt::ShiftModifier) {
		amount = 10.0f;
	}

	if (e->key() == Qt::Key_Escape) {
		QApplication::quit();
	} else if (e->key() == Qt::Key_Right) {
		gl_camera.RotateAboutUp(-amount);
	} else if (e->key() == Qt::Key_Left) {
		gl_camera.RotateAboutUp(amount);
	} else if (e->key() == Qt::Key_Up) {
		gl_camera.RotateAboutRight(-amount);
	} else if (e->key() == Qt::Key_Down) {
		gl_camera.RotateAboutRight(amount);
	} else if (e->key() == Qt::Key_1) {
		gl_camera.fovy += amount;
	} else if (e->key() == Qt::Key_2) {
		gl_camera.fovy -= amount;
	} else if (e->key() == Qt::Key_W) {
		gl_camera.TranslateAlongLook(amount);
	} else if (e->key() == Qt::Key_S) {
		gl_camera.TranslateAlongLook(-amount);
	} else if (e->key() == Qt::Key_D) {
		gl_camera.TranslateAlongRight(amount);
	} else if (e->key() == Qt::Key_A) {
		gl_camera.TranslateAlongRight(-amount);
	} else if (e->key() == Qt::Key_Q) {
		gl_camera.TranslateAlongUp(-amount);
	} else if (e->key() == Qt::Key_E) {
		gl_camera.TranslateAlongUp(amount);
	//R: render mode turns on or off
	} /* else if (e->key() == Qt::Key_R) {
		//        gl_camera = Camera(this->width(), this->height()); //- old
		if (renderMode == 0) {
			renderMode = 1;
			prog_lambert.setRenderMode(renderMode);
		} else {
			renderMode = 0;
			prog_lambert.setRenderMode(renderMode);
		}
	//Z: position mode turns on or off
	} else if (e->key() == Qt::Key_Z) {
        posMode = 1 - posMode;
        prog_lambert.setPosMode(posMode);
	}*/

    gl_camera.RecomputeAttributes();
    update();  // Calls paintGL, among other things
}

void MyGL::wheelEvent(QWheelEvent *e) {
	// mouse was scrolled
	if ( ! e->angleDelta().isNull()) {
		int scrollAmt = e->angleDelta().manhattanLength() / 15;
		if (e->angleDelta().ry() > 0) {
			gl_camera.fovy -= scrollAmt;
		} else  {
			gl_camera.fovy += scrollAmt;
		}
	}

	gl_camera.RecomputeAttributes();
	update();  // Calls paintGL, among other things
}

void MyGL::mousePressEvent(QMouseEvent *e) {
	// store movement offset
	mouseOffset = e->pos();

	if (e->buttons() & Qt::LeftButton && creatingPoints) {
		mouseClickFindIntersect(e);
		//std::ofstream ofs("logfile.txt", std::ios::out | std::ios::trunc); // clear contents
	}

	gl_camera.RecomputeAttributes();
	update();  // Calls paintGL, among other things
}

void MyGL::slot_creatingPoints(bool b) {
	creatingPoints = b;
	this->update();
}

void MyGL::mouseClickFindIntersect(QMouseEvent *e) {
	// location that the user clicked on the screen in abs then from mygl reference
	QPoint p = this->mapFromGlobal(e->globalPos());
	glm::vec2 point(p.x(), p.y());

	// Generate a ray from this pixel sample
	glm::vec2 sample = point;
	Ray ray = gl_camera.Raycast(sample);

	IntersectionEngine iEngine = IntersectionEngine();
	iEngine.halfMesh = &geom_halfMesh;
	Intersection isect = iEngine.GetIntersection(ray);

	// found an intersection with an object
	if (isect.t > 0) {
		// add new pont at that location and make it highlighted
		Point* p = new Point(isect.point, nextPointId);
		nextPointId += 1;

		allPoints.points.push_back(p);
		emit sig_addPoint(p);

		this->highlightPoint(p);

		allPoints.create();
		this->update();
	}

}

void MyGL::mouseMoveEvent(QMouseEvent *e) {
	// translate in current plane of view
	if (e->buttons() & Qt::MiddleButton || e->buttons() & Qt::RightButton) {
		QPoint moved = e->pos() - mouseOffset;
		float amountRL = (moved.rx() /*+ gl_camera.width / 2*/) / (-300.0f);
		float amountUD = (moved.ry() /*+ gl_camera.height / 2*/) / (300.0f);

		if (glm::abs(moved.rx()) > glm::abs(moved.ry())) {
			gl_camera.TranslateAlongRight(amountRL);
		} else {
			gl_camera.TranslateAlongUp(amountUD);
		}
	// rotate about current centered pov
	} else if (e->buttons() & Qt::LeftButton) {
		QPoint moved = e->pos() - mouseOffset;
		//std::ofstream log("logfile.txt", std::ios_base::app | std::ios_base::out);

		//log << "dif: " << moved.x() << ", " << moved.y() << "\n"; //"e->pos: " << e->pos().x()<<", " <<e->pos().y() << " mouseOffset: " << mouseOffset.x() <<", "<<mouseOffset.y()<<"\n";

		//char msgbuf[256];
		//sprintf(msgbuf, "&d, &d", moved.x(), moved.y());
		//DBOUT(std::string(msgbuf));

		//std::cout << moved.x() << ", " << moved.y() << "\n";

		glm::mat4 viewP = gl_camera.getViewProj();
		glm::vec3 trans = glm::vec3(viewP[3][0], viewP[3][1], viewP[3][2]);

		float amountUD = moved.ry() * 1.0f;
		float amountRL = moved.rx() * 1.0f;

		if (glm::abs(moved.rx()) > glm::abs(moved.ry())) {
			gl_camera.RotateAboutUp(amountUD * -1.0f);
		} else {
			gl_camera.RotateAboutRight(amountRL * -1.0f);
		}
	}

	mouseOffset = e->pos();

	gl_camera.RecomputeAttributes();
	update();  // Calls paintGL, among other things
}

void MyGL::timerUpdate()
{
    // This function is called roughly 60 times per second.
    // USED FOR PERFORMING REPEATED ACTIONS

    timeCount++;
    prog_lambert.setPosTime(timeCount);
    prog_lambert.setColTime(timeCount);
    if (renderMode == 1) {
        this->update();
    }
    if (posMode == 1) {
        this->update();
    }
}

void MyGL::highlightVertex(Vertex* v) {
	if (v != nullptr) {
		hVert.currentVertex = v;
		hVert.create();
		this->update();

		sig_DisplayPosX(hVert.currentVertex->pos[0]);
		sig_DisplayPosY(hVert.currentVertex->pos[1]);
		sig_DisplayPosZ(hVert.currentVertex->pos[2]);
	}
}

void MyGL::highlightPoint(Point* p) {
	if (p != nullptr) {
		hPoint.currentPoint = p;

		hPoint.create();
		this->update();

		sig_DisplayPosX(hPoint.currentPoint->pos[0]);
		sig_DisplayPosY(hPoint.currentPoint->pos[1]);
		sig_DisplayPosZ(hPoint.currentPoint->pos[2]);
	}
}

void MyGL::slot_vertexItemClicked(QListWidgetItem *it) {
    if (it != hVert.currentVertex) {
		highlightVertex((Vertex*)(it));
    }
}

void MyGL::slot_interestPointItemClicked(QListWidgetItem *it) {
	if (it != hPoint.currentPoint) {
		highlightPoint((Point*)(it));
	}
}

void MyGL::slot_highlightVertexById(int id) {
	for (Vertex* v : geom_halfMesh.vertices) {
		if (v->id == id) { highlightVertex(v); }
	}
}

void MyGL::slot_highlightPointById(int id) {
	for (Point* p : allPoints.points) {
		if (p->id == id) { highlightPoint(p); }
	}
}

void MyGL::slot_removedInterestPoint() {
	if (hPoint.currentPoint != nullptr) {

		bool looking = true;
		int numItems = allPoints.points.size();
		for (int i = 0; i < numItems && looking; i++){ 
			Point* p = allPoints.points[i];
			if (p->id == hPoint.currentPoint->id) {
				allPoints.points.erase(allPoints.points.begin() + i);
				looking = false;
				emit sig_removeSelectedVertPoint(hPoint.currentPoint);

				allPoints.create();
				this->update();
			}
		}
		//hPoint.currentPoint = nullptr;
	}
}

void MyGL::slot_removedPoint(QListWidgetItem* item) {
	hPoint.currentPoint = (Point*)item;
	slot_removedInterestPoint();
}

void MyGL::slot_addPointFromVertex() {
	if (hVert.currentVertex == nullptr) {
		return; // no vertex to add as a point
	}
	//int maxVal = 0; // because all indexing starts at 1
	float delta = 0.0001f;

	// find max & check doesnt already exist as a point
	for (Point * p : allPoints.points) {
		bool same = true;
		//if (p->id > maxVal) { maxVal = p->id; }
		for (int i = 0; i < 3; i++) {
			same = same && (glm::abs(p->pos[i] - hVert.currentVertex->pos[i]) < delta);
		}

		if (same) {
			sig_preExistingVertex(hVert.currentVertex->id);
			return;
		} // already exists so delete/done
	}

	Point* nPoint = new Point(hVert.currentVertex->pos, nextPointId);
	nextPointId += 1;
	hPoint.currentPoint = nPoint;
	allPoints.points.push_back(nPoint);
	emit sig_addPoint(nPoint);

	hPoint.create();
	allPoints.create();
	this->update();
}

void MyGL::slot_recenter() {
	gl_camera.recenter();
	gl_camera.RecomputeAttributes();
	update();
}

void MyGL::slot_viewPointsSet(bool b) {
	drawing = b;
	this->update();
}

void MyGL::slot_viewObjVertices(bool b) {
	viewObjV = b;
	this->update();
}

void MyGL::slot_viewMesh(bool b) {
	viewMesh = b;
	this->update();
}

void MyGL::slot_loadPointsFromTxt(QString filePath) {
	//precondition not guaranteed: text file in proper formatting for idNums
	// this method:
	//		if file is not formatted properly throws and error while running and asks user to recheck file at a particular line number
	// preferred txt formatting:
	//		each id is on a separate line with no commas spaces etc and no negative signs
	//		proper vertex flags can be added later to be associated on the same line as the vertex - tbd

	// CLEAR OUT ALL CURRENT POINTS - TO DO

	emit sig_clearPointList();
	allPoints.points.clear();

	// LOAD UP ALL NEW POINTS FROM TXT FILE

	//variables to read data from the files
	std::string fPath = filePath.toStdString();
	std::string line = "";

	//strem to parse the file
	std::ifstream myFile(fPath); //opens file instream

	//iterating through all the lines in the file
	int onLine = 1;
	int onId = geom_halfMesh.vertices.size() + 1; // id always starts as 1 more of current vertices count for obj
	bool fileCorrect = true;
	while (std::getline(myFile, line) && fileCorrect) {

		//note: for the following code - c++ strings check equality with x.compare(y)
		if (line.size() > 0) {

			Point* p = parseLineForPoint(line, onLine);

			if (p == nullptr) {
				fileCorrect = false;
				allPoints.points.clear();
				emit sig_clearPointList();
			} else {
				p->changeId(onId);
				allPoints.points.push_back(p);
				emit sig_addPoint(p);
			}
		}//END of: if (line.size() > 0)	

		onId += 1;
		onLine += 1;
	}//END of: while (std::getline(myFile, line))

	if (fileCorrect) { nextPointId = onId; }
	allPoints.create();
	this->update();

	myFile.close(); //closes file instream
}

//simple helper method for making a vertex from a line of position data
//returns the vertex of the line that was parsed
//note: sets the vertex's id to -1, bc in this method: do not have access to current idNum
Point* MyGL::parseLineForPoint(std::string line, int lineNum) {
	std::string dataOfLine = line;

	//the values we want to trim off between tokens
	const char* space = " ";

	//firstToken
	int spaceLoc = -1;
	try {
		spaceLoc = dataOfLine.find_first_of(space);
		if (spaceLoc == -1) {
			throw std::exception();
		}
	} catch (...) {
		emit sig_invalidTxtFileLine(lineNum);
		return nullptr;
	}

	std::string xPos = dataOfLine.substr(0, spaceLoc);

	//shift string for next token
	dataOfLine = dataOfLine.substr(spaceLoc + 1);
	//secondToken
	try {
		spaceLoc = dataOfLine.find_first_of(space);
		if (spaceLoc == -1) {
			throw std::exception();
		}
	}
	catch (...) {
		emit sig_invalidTxtFileLine(lineNum);
		return nullptr;
	}

	std::string yPos = dataOfLine.substr(0, spaceLoc);

	//shift string for next token
	dataOfLine = dataOfLine.substr(spaceLoc + 1);
	//thirdToken
	std::string zPos = dataOfLine;

	glm::vec3 pos(NAN);

	try {
		pos[0] = std::stof(xPos);
		pos[1] = std::stof(yPos);
		pos[2] = std::stof(zPos);
	}
	catch (...) {
		emit sig_invalidTxtFileLine(lineNum);
		return nullptr;
	}

	return new Point(pos, -1);
}

void MyGL::slot_savePointsToTxt(QString filePath) {

	//stream to save data to the file
	std::string fPath = filePath.toStdString();
	std::ofstream myFile(fPath); //opens file outstream
	std::string line = "";

	//saving vertices to the file
	std::vector<Point*> allP = allPoints.points;
	for (Point* p : allP) {
		myFile << "" << p->pos[0] <<" "<< p->pos[1] <<" " << p->pos[2] << "\n";
	}

	myFile.close(); //closes file instream
}

bool myIsDigit(int character) {
	return (character >= 0x30 && character <= 0x39);
}

void MyGL::slot_loadFileData(QString filePath) {
    loadingObject = true;

	// LOADING FOR POINTS AND HIGHLIGHTING OF VERTICES

    //SETTING UP VARIABLES
    //filler variable used when checking if an item is a digit
    std::locale locale;
    //int id variables: note they all start at 1 bc obj files index starting from 1
    int vertexId = 1;
    int faceId = 1;
    int halfEdgeId = 1;
    //variables to read data from the files
    std::string fPath = filePath.toStdString();
    std::string line = "";

    //SETTING UP VECTORS
    //setting up vectors for vertices, faces, and halfedges
    std::vector<Vertex*> vertices;
    std::vector<Face*> faces;
    std::vector<HalfEdge*> hEdges;

    //SETTING UP MAPS
    //setting up map of face to all vertices for making halfEdges
    std::map<Face*, std::vector<Vertex*>> mapFaceToAllVertices;
    //setting up map of vertex to all half edges that point to it (for setting up syms later)
    std::map<Vertex*, std::vector<HalfEdge*>> mapVertexToAllHEdges;

    //SETTING UP STREAM TO PARSE FILE
    std::ifstream myFile (fPath); //opens file instream

    //iterating through all the lines in the file
    while (std::getline(myFile, line)) {
        //note: for the following code - c++ strings check equality with x.compare(y)
        //if line has at least 2 elements in it - then we can see if first let and second let are
        //as follows [as per the formatting]
        if (line.size() > 0) {
            std::string firstLet = line.substr(0, 1);

            if (line.size() > 1) {
                std::string secondLet = line.substr(1, 2);

                //we trim spaces and tabs
                const char* t = " \t"; //the values we want to trim off
                firstLet = firstLet.erase(0, firstLet.find_first_not_of(t)); //trimming front
                firstLet = firstLet.erase(firstLet.find_last_not_of(t) + 1); //trimming back
                secondLet = secondLet.erase(0, secondLet.find_first_not_of(t)); //trimming front
                secondLet = secondLet.erase(secondLet.find_last_not_of(t) + 1); //trimming back

                //now parsing check: checking current line for usable data

                //VERTEX DATA
                //if first character in the line is v add it and following data to a vertex vector
                if ((firstLet.at(0) == 'v') && (myIsDigit(secondLet[0]) || secondLet.at(0) == ('-'))) {
                    //std::cout<<"FIRST: "<<line<<std::endl;

                    //PARSE for vertex
                    Vertex* v = parseLineForVertex(line);
                    v->setId(vertexId);

                    //ADD VERTEX to vector of vertices and INCREMENT id
                    vertices.push_back(v);
                    vertexId += 1;

                //FACE DATA
                //if first character in the line is f add it and following data to a face vector
                //in below compare: starting for second let (vertex id for face) with 1 bc .obj files index from 1
                } else if (firstLet.at(0) == 'f' && myIsDigit(secondLet[0]) && secondLet.at(0) != '0') {
                    //PARSE for face
                    Face* face = parseLineForFace(line, vertices, mapFaceToAllVertices);
                    face->setId(faceId);
         
                    //ADD FACE to vector of faces and INCREMENT id
                    faces.push_back(face);
                    faceId += 1;

                // if else is hit the line was skipped
                } else {
                    //std::cout<<"line not printed: was skipped"<<std::endl;

                }//END of: FACE DATA AND VERTEX DATA (not syms)
            }//END of: if (line.size() > 1)
        }//END of: if (line.size() > 0) {
    }//END of: while (std::getline(myFile, line))

    myFile.close(); //closes file instream

    buildHEdges(faces, hEdges,  mapFaceToAllVertices, mapVertexToAllHEdges, halfEdgeId);
    linkSymsForHEdges(hEdges, mapVertexToAllHEdges);
	
    //if all vectors have data then load up new mesh
    //otherwise dont update to any new mesh
    if (vertices.size() != 0 && faces.size() != 0 && hEdges.size() != 0) {
        //give data to mesh, send to vbos, and update
        geom_halfMesh.vertices = vertices;
		geom_halfMesh.faces= faces;
		geom_halfMesh.hEdges = hEdges;

        geom_halfMesh.create();
        emit sig_clearVertexList();
        for (Vertex* v: geom_halfMesh.vertices) {
            emit sig_addVertex(v);
			allObjVertices.vertices.push_back(v);
        }
		allObjVertices.create();

        this->update();

        //to make sure highlights follow the new mesh
        slot_vertexItemClicked(geom_halfMesh.vertices[0]);

		// LOADING FOR CHECKING FOR OBJECT INTERSECTION
		geom_halfMesh.mesh = new Mesh();
		geom_halfMesh.mesh->LoadOBJ(filePath);
		//Transform t = geom_halfMesh.mesh->transform;
		geom_halfMesh.mesh->transform = Transform();
    }

	redoPointIdNumbers();
}

//simple helper method for making a vertex from a line of position data
//returns the vertex of the line that was parsed
//note: sets the vertex's id to -1, bc in this method: do not have access to current idNum
Vertex* MyGL::parseLineForVertex(std::string line) {
    //cut of the first char (v) and the space
    std::string dataOfLine = line.substr(2);

    //the values we want to trim off between tokens
    const char* space = " ";

    //firstToken
    int spaceLoc = dataOfLine.find_first_of(space);
    std::string xPos = dataOfLine.substr(0, spaceLoc);

    //shift string for next token
    dataOfLine = dataOfLine.substr(spaceLoc+1);
    //secondToken
    spaceLoc = dataOfLine.find_first_of(space);
    std::string yPos = dataOfLine.substr(0, spaceLoc);

    //shift string for next token
    dataOfLine = dataOfLine.substr(spaceLoc+1);
    //thirdToken
    spaceLoc = dataOfLine.find_first_of(space);
    std::string zPos = dataOfLine.substr(0, spaceLoc);

    return new Vertex(glm::vec3(std::stod(xPos),
                                std::stod(yPos),
                                std::stod(zPos)),
                                nullptr,
                                -1);
}

//simple helper method for making the face from a line of vertex/uv/normals data
//  currently updates map of face to the vertices pointing to that face
//  returns the face of the line that was parsed
//note: sets the face's id to -1, bc in this method: do not have access to current idNum
Face* MyGL::parseLineForFace(std::string line,
                             std::vector<Vertex*>& vertices,
                             std::map<Face*, std::vector<Vertex*>>& mapFaceToAllVertices) {
    //cut of the first char (v) and the space
    //add "~" to end of it bc our obj file will not be taking this character in
    //  used to delineate when a line finishes [as per obj file format]
    std::string dataOfLineFace = line.substr(2) + "~";

    //current face: note: putting max of 255, 255, 255
    //note: i can use floats from 0 to 255 bc in my create method for my mesh class i divide all the colorsRGBs by 255 already
	// currently: light blue for same face coloring. toggle has set up to switch to normal if user wants to do so.
	float r = 0.0f; //std::rand() % 255;
	float g = 140.0f; //std::rand() % 255;
	float b = 255.0f; //std::rand() % 255;
    glm::vec4 faceColor = glm::vec4(r, g, b, 1.0f);
    Face* face = new Face(nullptr, faceColor, -1);

    //the values we want to trim off between tokens and or search for
    const char* space = " ";
    const char* slash = "/";
    //to search at each looping for vertex/uvofvert/normalofvert in a line want to be able
    //      to cut dataOfLine so only includes info that hasn't been reached yet.
    //      includes " " between each full loop and ~ to tell us we finished the line
    const char* spaceSquig = " ~";

    //currentVertex(includes: vertex/uvofvert/normalofvert)
    int spaceLoc = dataOfLineFace.find_first_of(space);
    std::string currentVertexInfo;
    while(!dataOfLineFace.empty()) {
        currentVertexInfo = dataOfLineFace.substr(0, spaceLoc);
        //vertex Id
        int slashLoc = currentVertexInfo.find_first_of(slash);
        std::string vId = currentVertexInfo.substr(0, slashLoc);

        //uv Id - CURRENTLY DONT NEED FOR HW05
        //shift string for next token past "/"
        currentVertexInfo = currentVertexInfo.substr(slashLoc+1);
        slashLoc = currentVertexInfo.find_first_of(slash);
        std::string uvId = currentVertexInfo.substr(0, slashLoc);

        //normal Id - CURRENTLY DONT NEED FOR HW05
        //shift string for next token past "/"
        currentVertexInfo = currentVertexInfo.substr(slashLoc+1);
        slashLoc = currentVertexInfo.find_first_of(slash);
        std::string norId = currentVertexInfo.substr(0, slashLoc);

        //map current face to vertex with that id
        int vIdInt = std::stoi(vId);
        for (Vertex* vertexHere: vertices) {
            if (vIdInt == vertexHere->id) {
                mapFaceToAllVertices[face].push_back(vertexHere);
            }
        }

        //shift full line string for next token past " " or make it empty if finished
        //  last for the current face
        int spaceSquigLoc = dataOfLineFace.find_first_of(spaceSquig);
        //if not last element
        if (spaceSquigLoc < (int)(dataOfLineFace.size())-1) {
            dataOfLineFace = dataOfLineFace.substr(spaceSquigLoc+1);
        //otherwise this current looping was the last element so make dataOfLine empty
        } else {
            dataOfLineFace = "";
        }
    }

    return face;
}

//HALFEDGES (all data but syms)
void MyGL::buildHEdges(
        std::vector<Face*>& faces,
        std::vector<HalfEdge*>& hEdges,
        std::map<Face*, std::vector<Vertex*>>& mapFaceToAllVertices,
        std::map<Vertex*, std::vector<HalfEdge*>>& mapVertexToAllHEdges,
        int& halfEdgeId) {

    for (Face* f: faces) {
        //loop through all vertices to make halfEdges that point to them and that are associated with
        //   this face
        //the first half edge you make - add it as the start edge for this face
        //for each half edge that points to a vertex
        //          add it to the vertex's vector of half edges
        //          if the vertex does not yet have a half edge member variable (points to nullptr) - add it there as well
        std::vector<Vertex*> faceToVert = mapFaceToAllVertices[f];

        HalfEdge* prev = nullptr;
        HalfEdge* first = nullptr;
        int faceVertVectorSize = (int)faceToVert.size();
        for (int i=0; i < faceVertVectorSize; i++) {
            Vertex* vert = faceToVert[i];

            //CREATE HEDGE
            HalfEdge* half = new HalfEdge(f, vert, nullptr, nullptr, halfEdgeId);
            //if this is the first halfedge created - store it so can use as next for the last one
            if (i == 0) {
                first = half;
            }

            //FILL IN VERT HALFEDGE VAL IF NONE THERE
            //if vertex.halfedge (for one of the ones pointing to it is not set yet so nullptr)
            //  set it to current half edge
            if (vert->edge == nullptr) {
                vert->edge = half;
            }
            //FILL IN FACE HALFEDGE VAL IF NONE THERE
            //if vertex.halfedge (for one of the ones pointing to it is not set yet so nullptr)
            //  set it to current half edge
            if (f->start_edge == nullptr) {
                f->start_edge = half;
            }

            //SET HEDGE NEXT
            //if prev has been initialized in the prev loop of this for each then can add
            if (i != 0) {
                prev->setHEdgeNext(half);
            }
            //update prev for next halfedge in next iteration through this for loop
            prev = half;

            //SET FIRST HEDGE NEXT
            //if on last vertex - update
            if (i == faceVertVectorSize-1) {
                half->setHEdgeNext(first);
            }

            //ADD HALFEDGE TO VECTOR OF HALFEDGES
            hEdges.push_back(half);

            //add current half edge to map of vertex to all halfedges that point to it
            mapVertexToAllHEdges[vert].push_back(half);

           //INCREMENT hId so next face we see will have the next id num
           halfEdgeId += 1;
        }
    }//END of: HALFEDGES (but not syms)
}

//HALFEDGES SYMS
//IN THIS METHOD I ALSO ADD THE VERTTOHEDGE VECTOR TO THE APPROPRIATE VERTEX (bc filling all params of a vertex now)
void MyGL::linkSymsForHEdges(std::vector<HalfEdge*>& hEdges, std::map<Vertex*, std::vector<HalfEdge*>>& mapVertexToAllHEdges) {
    for(HalfEdge* h: hEdges) {
        Vertex* v = h->vert;
        std::vector<HalfEdge*> vertToHEdge = mapVertexToAllHEdges[v];

        v->setHEdgeList(vertToHEdge);

        //if the half edge's sym has not been matched yet then:
        if (h->sym == nullptr) {
            //to find the sym for our current half edge, we do the following:
            //iterate through each halfEdge in the vector vertToHEdge
            //  if our halfedge(h)'s vertex(v), is the vertex of the prev HEdge (prevOfChecked) for the (checkedHalfEdge)
            //  AND if the (checkedHalfEdge)'s vertex is the vertex of the prev HEdge (prevOfH) for (h)
            //      then they are syms
            //  otherwise they are not.

            for (HalfEdge* checkedHalfEdge: vertToHEdge) {
                //find prev HalfEdge of (h)
                HalfEdge* prevOfH = getPrevHEdge(h);
                //find prev HalfEdge of (checkedHalfEdge)
                HalfEdge* nextOfChecked = checkedHalfEdge->next;

                //if the above described condition holds, then set both of them as each other's sym
                int Hp = prevOfH->vert->id;
                int H = h->vert->id;
                int Cp = checkedHalfEdge->vert->id;
                int C = nextOfChecked->vert->id;
                if ((Hp == C) && (H == Cp)) {
                    nextOfChecked->setHEdgeSym(h);
                    h->setHEdgeSym(checkedHalfEdge->next);
                }
            }
        } //END of: if h->sym == nullptr
    }//END of: HALFEDGES SYMS
}

//simple helper method to get the previous half edge (on a face) of a specified half edge
//  so just going in a circle
HalfEdge* MyGL::getPrevHEdge(HalfEdge* h) {
    bool first = true;
    HalfEdge* curr = h;
    while (first || curr->next != h) {
        first = false;
        curr = curr->next;
    }
    return curr;
}

void MyGL::redoPointIdNumbers() {
	int startId = geom_halfMesh.vertices.size() + 1;
	for (Point* p : allPoints.points) {
		p->changeId(startId);
		startId += 1;
	}

	this->nextPointId = startId;

	this->update();
}
