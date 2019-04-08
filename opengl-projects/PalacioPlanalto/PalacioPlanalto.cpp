#include <GL/glut.h>

#include <cmath>
#include <iostream>

#define PI 3.14159265

double rot_y = 0;
double rot_x = 0;


static float R = 1.2; // RAIO DA SEMIESFERA
static int p = 20; // NÚMERO LONGITUDINAL DE PARTES
static int q = 18; // NÚMERO LATITUDINAL DE PARTES
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0; // ÂNGULOS DE ROTAÇÃO DA SEMIESFERA



void palacio_planalto(){



  glLoadIdentity();
  glRotatef(rot_x, 1.0, 0.0, 0.0 );
  glRotatef(rot_y, 0.0, 1.0, 0.0 );

  //******************TORRE ESQUERDA*********************

 //FRENTE
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  0.005, -0.5, -0.5 );
  glVertex3f(  0.005,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  0.005, -0.5, -0.5 );
  glVertex3f(  0.005,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();


  //ATRÁS
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  0.005, -0.5, 1.5 );
  glVertex3f(  0.005,  3.0, 1.5 );
  glVertex3f( -0.5,  3.0, 1.5 );
  glVertex3f( -0.5, -0.5, 1.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(0.005, -0.5, 1.5 );
  glVertex3f(0.005,  3.0, 1.5 );
  glVertex3f( -0.5,  3.0, 1.5 );
  glVertex3f( -0.5, -0.5, 1.5 );
  glEnd();


   //DIREITA
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  1.0,  1.0 );
  glVertex3f( 0.005, -0.5, -0.5 );
  glVertex3f( 0.005,  3.0, -0.5 );
  glVertex3f( 0.005,  3.0,  1.5 );
  glVertex3f( 0.005, -0.5,  1.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( 0.005, -0.5, -0.5 );
  glVertex3f( 0.005,  3.0, -0.5 );
  glVertex3f( 0.005,  3.0,  1.5 );
  glVertex3f( 0.005, -0.5,  1.5 );
  glEnd();

  //ESQUERDA
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0,  1.0 );
  glVertex3f( -0.5, -0.5, 1.5 );
  glVertex3f( -0.5,  3.0,  1.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( -0.5, -0.5, 1.5 );
  glVertex3f( -0.5,  3.0,  1.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  //TOPO
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  0.005,  3.0,  1.5 );
  glVertex3f(  0.005,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0,  1.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  0.005,  3.0,  1.5 );
  glVertex3f(  0.005,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0,  1.5 );
  glEnd();

  //BASE
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  0.005, -0.5, -0.5 );
  glVertex3f(  0.005, -0.5,  1.5 );
  glVertex3f( -0.5, -0.5, 1.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  0.005, -0.5, -0.5 );
  glVertex3f(  0.005, -0.5,  1.5 );
  glVertex3f( -0.5, -0.5, 1.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();


  //**************TORRE DIREITA******************

  glTranslatef(0.8, 0.0, 0.0);

  //FRENTE
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  0.005, -0.5, -0.5 );
  glVertex3f(  0.005,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  0.005, -0.5, -0.5 );
  glVertex3f(  0.005,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();


  //ATRÁS
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  0.005, -0.5, 1.5 );
  glVertex3f(  0.005,  3.0, 1.5 );
  glVertex3f( -0.5,  3.0, 1.5 );
  glVertex3f( -0.5, -0.5, 1.5 );
  glEnd();


  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(0.005, -0.5, 1.5 );
  glVertex3f(0.005,  3.0, 1.5 );
  glVertex3f( -0.5,  3.0, 1.5 );
  glVertex3f( -0.5, -0.5, 1.5 );
  glEnd();


   //DIREITA
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  1.0,  1.0 );
  glVertex3f( 0.005, -0.5, -0.5 );
  glVertex3f( 0.005,  3.0, -0.5 );
  glVertex3f( 0.005,  3.0,  1.5 );
  glVertex3f( 0.005, -0.5,  1.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( 0.005, -0.5, -0.5 );
  glVertex3f( 0.005,  3.0, -0.5 );
  glVertex3f( 0.005,  3.0,  1.5 );
  glVertex3f( 0.005, -0.5,  1.5 );
  glEnd();

  //ESQUERDA
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0,  1.0 );
  glVertex3f( -0.5, -0.5, 1.5 );
  glVertex3f( -0.5,  3.0,  1.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();


  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( -0.5, -0.5, 1.5 );
  glVertex3f( -0.5,  3.0,  1.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  //TOPO
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  0.005,  3.0,  1.5 );
  glVertex3f(  0.005,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0,  1.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  0.005,  3.0,  1.5 );
  glVertex3f(  0.005,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0, -0.5 );
  glVertex3f( -0.5,  3.0,  1.5 );
  glEnd();

  //BASE
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  0.005, -0.5, -0.5 );
  glVertex3f(  0.005, -0.5,  1.5 );
  glVertex3f( -0.5, -0.5, 1.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  0.005, -0.5, -0.5 );
  glVertex3f(  0.005, -0.5,  1.5 );
  glVertex3f( -0.5, -0.5, 1.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();



   //**************** BASE 1 *****************************
   glTranslatef(-4.5, -0.5, -1.0);

 //FRENTE
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f( 8.0, -0.5, -0.5);
  glVertex3f( 8.0,  0.005, -0.5);
  glVertex3f( -0.5, 0.005, -0.5);
  glVertex3f( -0.5, -0.5, -0.5);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( 8.0, -0.5, -0.5);
  glVertex3f( 8.0,  0.005, -0.5);
  glVertex3f( -0.5, 0.005, -0.5);
  glVertex3f( -0.5, -0.5, -0.5);
  glEnd();


  //ATRÁS
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  8.0, -0.5, 4.0 );
  glVertex3f(  8.0,  0.005, 4.0);
  glVertex3f( -0.5,  0.005, 4.0 );
  glVertex3f( -0.5, -0.5, 4.0 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  8.0, -0.5, 4.0 );
  glVertex3f(  8.0,  0.005, 4.0);
  glVertex3f( -0.5,  0.005, 4.0 );
  glVertex3f( -0.5, -0.5, 4.0 );
  glEnd();


   //DIREITA
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f( 8.0, -0.5, -0.5 );
  glVertex3f( 8.0,  0.005, -0.5 );
  glVertex3f( 8.0,  0.005,  4.0);
  glVertex3f( 8.0, -0.5,  4.0 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( 8.0, -0.5, -0.5 );
  glVertex3f( 8.0,  0.005, -0.5 );
  glVertex3f( 8.0,  0.005,  4.0);
  glVertex3f( 8.0, -0.5,  4.0 );
  glEnd();

  //ESQUERDA
  glBegin(GL_POLYGON);
    glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f( -0.5, -0.5, 4.0 );
  glVertex3f( -0.5,  0.005,  4.0 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( -0.5, -0.5, 4.0 );
  glVertex3f( -0.5,  0.005,  4.0 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  //TOPO
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  8.0,  0.005,  4.0 );
  glVertex3f(  8.0,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005,  4.0 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  8.0,  0.005,  4.0 );
  glVertex3f(  8.0,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005,  4.0 );
  glEnd();

  //BASE
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  8.0, -0.5, -0.5 );
  glVertex3f(  8.0, -0.5,  4.0 );
  glVertex3f( -0.5, -0.5, 4.0 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  8.0, -0.5, -0.5 );
  glVertex3f(  8.0, -0.5,  4.0 );
  glVertex3f( -0.5, -0.5, 4.0 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();


  //******************* BASE 2 *****************************

   glTranslatef(0.3, -0.5, 0.2);

 //FRENTE
  glBegin(GL_POLYGON);
  glColor3f(1.0, 1.0, 1.0);
  glVertex3f( 7.0, -0.5, -0.5);
  glVertex3f( 7.0,  0.005, -0.5);
  glVertex3f( -0.5, 0.005, -0.5);
  glVertex3f( -0.5, -0.5, -0.5);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( 7.0, -0.5, -0.5);
  glVertex3f( 7.0,  0.005, -0.5);
  glVertex3f( -0.5, 0.005, -0.5);
  glVertex3f( -0.5, -0.5, -0.5);
  glEnd();


  //ATRÁS
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  7.5, -0.5, 3.5 );
  glVertex3f(  7.5,  0.005, 3.5);
  glVertex3f( -0.5,  0.005, 3.5 );
  glVertex3f( -0.5, -0.5, 3.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  7.5, -0.5, 3.5 );
  glVertex3f(  7.5,  0.005, 3.5);
  glVertex3f( -0.5,  0.005, 3.5 );
  glVertex3f( -0.5, -0.5, 3.5 );
  glEnd();


   //DIREITA
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  1.0,  1.0 );
  glVertex3f( 7.5, -0.5, -0.5 );
  glVertex3f( 7.5,  0.005, -0.5 );
  glVertex3f( 7.5,  0.005,  3.5);
  glVertex3f( 7.5, -0.5,  3.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( 7.5, -0.5, -0.5 );
  glVertex3f( 7.5,  0.005, -0.5 );
  glVertex3f( 7.5,  0.005,  3.5);
  glVertex3f( 7.5, -0.5,  3.5 );
  glEnd();

  //ESQUERDA
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0,  1.0 );
  glVertex3f( -0.5, -0.5, 3.5 );
  glVertex3f( -0.5,  0.005,  3.5 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( -0.5, -0.5, 3.5 );
  glVertex3f( -0.5,  0.005,  3.5 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  //TOPO
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  7.5,  0.005,  3.5 );
  glVertex3f(  7.5,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005,  3.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  7.5,  0.005,  3.5 );
  glVertex3f(  7.5,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005,  3.5 );
  glEnd();

  //BASE
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  7.5, -0.5, -0.5 );
  glVertex3f(  7.5, -0.5,  3.5 );
  glVertex3f( -0.5, -0.5, 3.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  7.5, -0.5, -0.5 );
  glVertex3f(  7.5, -0.5,  3.5 );
  glVertex3f( -0.5, -0.5, 3.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();



//**************** SEMIESFERA - BAIXO *****************************
 int  i, j;
 glTranslatef(1.3, 0.4, 1.5);
 glColor3f(1.0, 1.0, 1.0);
  for(j = 0; j < q; j++){
      glBegin(GL_TRIANGLE_STRIP);
         for(i = 0; i <= p; i++){
            glVertex3f( R * cos( (float)(j+1)/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ),
                        R * sin( (float)(j+1)/q * PI/2.0 ),
					    R * cos( (float)(j+1)/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI ) );
            glVertex3f( R * cos( (float)j/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ),
                        R * sin( (float)j/q * PI/2.0 ),
					    R * cos( (float)j/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI ) );
		 }
      glEnd();
   }


glColor3f(0.0, 0.0, 0.0);
 for(j = 0; j < q; j++){
         for(i = 0; i <= p; i++){
         glBegin(GL_LINE_LOOP);
            glVertex3f( R * cos( (float)(j+1)/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ),
                        R * sin( (float)(j+1)/q * PI/2.0 ),
					    R * cos( (float)(j+1)/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI ) );
            glVertex3f( R * cos( (float)j/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ),
                        R * sin( (float)j/q * PI/2.0 ),
					    R * cos( (float)j/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI ) );
      glEnd();
		 }
 }


   //****************** SEMIESFERA - CIMA *****************************
  glRotatef(180, 0.0, 0.0, 1.0);
  glTranslatef(-5.0, -1.2, 0.0);
  glColor3f(1.0, 1.0, 1.0);
  for(j = 0; j < q; j++){
      glBegin(GL_TRIANGLE_STRIP);
         for(i = 0; i <= p; i++){
            glVertex3f( R * cos( (float)(j+1)/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI),
                        R * sin( (float)(j+1)/q * PI/2.0 ),
					    R * cos( (float)(j+1)/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI ));

            glVertex3f( R * cos( (float)j/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI),
                        R * sin( (float)j/q * PI/2.0),
					    R * cos( (float)j/q * PI/2.0) * sin(2.0 * (float)i/p * PI ));
		 }
      glEnd();
   }

glColor3f(0.0, 0.0, 0.0);
 for(j = 0; j < q; j++){
         for(i = 0; i <= p; i++){
         glBegin(GL_LINE_LOOP);
            glVertex3f( R * cos( (float)(j+1)/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ),
                        R * sin( (float)(j+1)/q * PI/2.0 ),
					    R * cos( (float)(j+1)/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI ) );
            glVertex3f( R * cos( (float)j/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ),
                        R * sin( (float)j/q * PI/2.0 ),
					    R * cos( (float)j/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI ) );
      glEnd();
		 }
 }


 //**************** RAMPA *****************************
   glRotatef(165, 1.0, 0.0, 0.0);
   glTranslatef(1.6, -0.5, -6.5);

 //FRENTE
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f( 3.0, -0.5, -0.5);
  glVertex3f( 3.0,  0.005, -0.5);
  glVertex3f( -0.5, 0.005, -0.5);
  glVertex3f( -0.5, 0.005, -0.5);
  glEnd();


  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( 8.0, -0.5, -0.5);
  glVertex3f( 8.0,  0.005, -0.5);
  glVertex3f( -0.5, 0.005, -0.5);
  glVertex3f( -0.5, -0.5, -0.5);
  glEnd();


  //ATRÁS
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  3.0, -0.5, 4.0 );
  glVertex3f(  3.0,  0.005, 4.0);
  glVertex3f( -0.5,  0.005, 4.0 );
  glVertex3f( -0.5, -0.5, 4.0 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  3.0, -0.5, 4.0 );
  glVertex3f(  3.0,  0.005, 4.0);
  glVertex3f( -0.5,  0.005, 4.0 );
  glVertex3f( -0.5, -0.5, 4.0 );
  glEnd();


   //DIREITA
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f( 3.0, -0.5, -0.5 );
  glVertex3f( 3.0,  0.005, -0.5 );
  glVertex3f( 3.0,  0.005,  4.0);
  glVertex3f( 3.0, -0.5,  4.0 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( 3.0, -0.5, -0.5 );
  glVertex3f( 3.0,  0.005, -0.5 );
  glVertex3f( 3.0,  0.005,  4.0);
  glVertex3f( 3.0, -0.5,  4.0 );
  glEnd();

  //ESQUERDA
  glBegin(GL_POLYGON);
    glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f( -0.5, -0.5, 4.0 );
  glVertex3f( -0.5,  0.005,  4.0 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f( -0.5, -0.5, 4.0 );
  glVertex3f( -0.5,  0.005,  4.0 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  //TOPO
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  3.0,  0.005,  4.0 );
  glVertex3f(  3.0,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005,  4.0 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  3.0,  0.005,  4.0 );
  glVertex3f(  3.0,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005, -0.5 );
  glVertex3f( -0.5,  0.005,  4.0 );
  glEnd();

  //BASE
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );
  glVertex3f(  3.0, -0.5, -0.5 );
  glVertex3f(  3.0, -0.5,  4.0 );
  glVertex3f( -0.5, -0.5, 4.0 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(  3.0, -0.5, -0.5 );
  glVertex3f(  3.0, -0.5,  4.0 );
  glVertex3f( -0.5, -0.5, 4.0 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

}


void display() {

  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  palacio_planalto();

  glFlush();
  glutSwapBuffers();
}

void specialKeys( int key, int x, int y ) {

  if (key == GLUT_KEY_RIGHT){
    rot_y += 5;
  }

  else if (key == GLUT_KEY_LEFT){
    rot_y -= 5;
}

  else if (key == GLUT_KEY_UP){
    rot_x += 5;
  }

  else if (key == GLUT_KEY_DOWN){
    rot_x -= 5;
  }

  glutPostRedisplay();

}

void myInit(){
     glClearColor(0.0, 0.0, 0.0, 0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-7.0, 7.0, -7.0, 7.0, -7.0, 7.0);
     glMatrixMode(GL_MODELVIEW);

}



int main(int argc, char** argv) {
  glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("PALÁCIO DO PLANALTO");
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
  myInit();
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
}
