#include <bits/stdc++.h>
#include <GL/glut.h>
#include <stdlib.h>

using namespace std;

struct Point{
    int x, y;
    bool isConvex = false;
};

struct Triangulo{
    Point t1, t2, t3;
};

int pos_x = 0;
int pos_y = 0;

bool apertarEnter = false;

vector<Point> vec;
vector<Point> convex;
vector<Triangulo> triangulos;

Point addPoint(int x, int y){
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

int* getPoint(Point p){
    int aux[2];
    aux[0] = p.x;
    aux[1] = p.y;
    return aux;
}

bool existe_elemento(vector<Point> v, int x, int y){

  for (int i = 0; i < v.size(); i++)
        if(v[i].x == x && v[i].y == y)
            return true;

    return false;
}

int existe_elemento_indice(vector<Point> v, int x, int y){

  for (int i = 0; i < v.size(); i++)
        if(v[i].x == x && v[i].y == y)
            return i;

    return -1;
}

bool existe_elemento_tri(vector<Triangulo> tri, Triangulo tr){

  for (int i = 0; i < tri.size(); i++)
        if(tri[i].t1.x == tr.t1.x && tri[i].t1.y == tr.t1.y &&
           tri[i].t2.x == tr.t2.x &&tri[i].t2.x == tr.t2.x &&
           tri[i].t3.x == tr.t3.x &&tri[i].t3.x == tr.t3.x)
            return true;

    return false;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}


bool estaDentro(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{

   float A = area (x1, y1, x2, y2, x3, y3);

   float A1 = area (x, y, x2, y2, x3, y3);

   float A2 = area (x1, y1, x, y, x3, y3);

   float A3 = area (x1, y1, x2, y2, x, y);

   return (A == A1 + A2 + A3);
}


vector<Point> noConvex(){

    vector<Point> p;
    for (int j = 0; j < vec.size(); j++){
       if(vec.size() > 3)
        if(vec[j].isConvex == false){
            printf("\nPONTOS NAO CONVEXOS: x %d y %d ", vec[j].x, vec[j].y);
            Point r;
            r.x = vec[j].x;
            r.y = vec[j].y;
            r.isConvex = false;
            p.push_back(r);
        }
    }
    return p;
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2; // 1 esta na ordem CC, 2 esta na ordem CCW
}

vector<Point> convexHull(Point points[], int n){

    // Armazena os pontos convexos
    vector<Point> hull;

    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x){
            l = i;
        }

    int p = l, q;
    do{

    if(convex.empty()){
        Point t;
        t.x = points[p].x;
        t.y = points[p].y;
        t.isConvex = true;
        int r = existe_elemento_indice(vec, t.x, t.y);
        vec[r].isConvex = true;
        convex.push_back(t);
         printf("\nENTROU: x %d y %d ", points[p].x, points[p].y);
    }else{
     if(existe_elemento(convex, points[p].x, points[p].y) == false){
        Point t;
        t.x = points[p].x;
        t.y = points[p].y;
        t.isConvex = true;
        int r = existe_elemento_indice(vec, t.x, t.y);
        vec[r].isConvex = true;
        convex.push_back(t);
        printf("\nENTROU: x %d y %d ", points[p].x, points[p].y);
     }
   }
        hull.push_back(points[p]);


        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {

           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;



        }

        p = q;

    } while (p != l); 

    return hull;
}


void desenharPonto(int x, int y) {
    int i;
	y = 500-y;

	glPointSize(7);
    glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(x , y);
    glEnd();
    if(x != 0){
    if(vec.empty()){
        Point p = addPoint(x, y);
        vec.push_back(p);
    } else{
    Point aux = vec.back();
    if(aux.x != x && aux.y != y){
       Point p = addPoint(x, y);
            vec.push_back(p);
    }
  }
}
  glutSwapBuffers();
}

void triangulacao(vector<Point> v){

            vector<Point> vet = v;

            Point p0 = vet.back();
            vet.pop_back();
            Point pHelper = vet.back();
            vet.pop_back();
            Point pTemp;
            while(!vet.empty()){

              pTemp = vet.back();
              vet.pop_back();

              if(triangulos.empty()){
              Triangulo t;
              t.t1 = p0;
              t.t2 = pTemp;
              t.t3 = pHelper;
              triangulos.push_back(t);

                }else{
              Triangulo t;
              t.t1 = p0;
              t.t2 = pTemp;
              t.t3 = pHelper;
                if(existe_elemento_tri(triangulos, t) == false){
              triangulos.push_back(t);
                }
                }

              glLineWidth(2);
              glColor3f(1.0, 0.0, 0.0);
              glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
              glBegin(GL_TRIANGLES);
              glVertex2f(p0.x, p0.y);
              glVertex2f(pTemp.x , pTemp.y);
              glVertex2f(pHelper.x , pHelper.y);
              glEnd();

              pHelper = pTemp;
            }
}


void display (void){

    int i, j = 0;
    desenharPonto(pos_x, pos_y);
	if(apertarEnter == true){
            Point points[vec.size()];
    for(i = 0; i < vec.size(); i++){
        points[i] = vec[i];
    }
              vector<Point> res = convexHull(points, vec.size());
              triangulacao(res);

              vector<Point> nConvex = noConvex();
              for(int i = 0; i < nConvex.size(); i++){
                    for(int j = 0; j < triangulos.size(); j++){
              if(estaDentro(triangulos[j].t1.x,triangulos[j].t1.y,
                            triangulos[j].t2.x,triangulos[j].t2.y,
                            triangulos[j].t3.x,triangulos[j].t3.y,
                            nConvex[i].x, nConvex[i].y)){
              glLineWidth(2);
              glColor3f(1.0, 0.0, 0.0);
              glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
              glBegin(GL_LINE_LOOP);
              glVertex2f(triangulos[j].t1.x,triangulos[j].t1.y);
              glVertex2f(triangulos[j].t2.x,triangulos[j].t2.y);
              glVertex2f(triangulos[j].t3.x,triangulos[j].t3.y);
              glVertex2f(nConvex[i].x, nConvex[i].y);
              glEnd();

                }

              }
    }
    apertarEnter = false;
}
	glFlush();
}

void mouse(int bin, int state , int x , int y) {
	if(bin == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
            pos_x = x;
            pos_y = y;
    }
    if(bin == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
          apertarEnter = true;
    }

    glutPostRedisplay();
}


void init (){

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport( 0, 0, 500, 500 );
	glMatrixMode(GL_PROJECTION);
	glOrtho( 0.0, 500.0, 0.0, 500.0, 1.0, -1.0 );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main (int argc,char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("FECHO CONVEXO DE TRIANGULARIZAÇÃO");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}


