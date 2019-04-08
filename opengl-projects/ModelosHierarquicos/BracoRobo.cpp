#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int art1 = 0, art2 = 0, art3 = 0, art4 = 0, rotOmbro = 0, rotOmbro2 = 0, rotMao = 0, rotMao2 = 0, rotBraco = 0,   rotAnteBraco = 0;
bool BASE = false, A1 = false, A2 = false, A3 = false, A4 = false, MAO = false;


void init(void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
}

void display(void){
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix();

   //BASE
   glTranslatef (-1.0, 0.0, 0.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   if(BASE == true)
   glColor3f(0.0, 1.0, 0.0);
   else glColor3f(1.0,0.0, 0.0);
   glRotatef (90.0, 0.0, 0.0, 1.0);
   glScalef (0.5, 0.5, 1.0);
   glTranslatef (-0.3, 2.0, 0.0);
   glutWireDodecahedron();
   glPopMatrix();

   //ARTICULAÇÃO 1 - ART1
   glTranslatef (-1.0, 0.0, 0.0);
   glRotatef ((GLfloat) art1, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) rotOmbro, 1.0, 0.0, 0.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   if(A1 == true)
   glColor3f(0.0, 1.0, 0.0);
   else glColor3f(1.0,0.0, 0.0);
   glScalef (2.0, 0.5, 0.7);
   glutWireCube (1.0);
   glPopMatrix();

    //ARTICULAÇÃO 2 - ART2
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) art2, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) rotOmbro2, 0.0, 1.0, 0.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   if(A2 == true)
   glColor3f(0.0, 1.0, 0.0);
   else glColor3f(1.0,0.0, 0.0);
   glScalef (2.0, 0.5, 0.7);
   glutWireCube (1.0);
   glPopMatrix();

   //ARTICULAÇÃO 3 - ART3
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) art3, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) rotAnteBraco, 0.0, 1.0, 0.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   if(A3 == true)
   glColor3f(0.0, 1.0, 0.0);
   else glColor3f(1.0,0.0, 0.0);
   glScalef (2.0, 0.5, 0.7);
   glutWireCube (1.0);
   glPopMatrix();

   //ARTICULAÇÃO 4 - ART4
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) art4, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) rotBraco, 0.0, 1.0, 0.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   if(A4 == true)
   glColor3f(0.0, 1.0, 0.0);
   else glColor3f(1.0,0.0, 0.0);
   glScalef (2.0, 0.5, 0.7);
   glutWireCube (1.0);
   glPopMatrix();

   //MAO
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) rotMao, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) rotMao2, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   if(MAO == true)
   glColor3f(0.0, 1.0, 0.0);
   else glColor3f(1.0,0.0, 0.0);
   glutWireOctahedron();
   glPopMatrix();

   //DEDO 1
   glTranslatef (1.0, 0.0, 0.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   if(MAO == true)
   glColor3f(0.0, 1.0, 0.0);
   else glColor3f(1.0,0.0, 0.0);
   glTranslatef (-1.0, 0.0, -0.8);
   glScalef (2.0, 0.4, 0.5);
   glutWireCube (1.0);
   glPopMatrix();

   //DEDO 2
   glTranslatef (1.0, 0.0, 0.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   if(MAO == true)
   glColor3f(0.0, 1.0, 0.0);
   else glColor3f(1.0,0.0, 0.0);
   glTranslatef (-3.0, 0.0, 0.8);
   glScalef (2.0, 0.4, 0.5);
   glutWireCube (1.0);
   glPopMatrix();

   glPopMatrix();
   glutSwapBuffers();

}

void reshape (int w, int h){
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(50.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (-1.5, -2.5, -12.0);
}

void teclado (int key, int x, int y){

   if(key == GLUT_KEY_F1){
           BASE = false;
           A1 = true;
           A2 = false;
           A3 = false;
           A4 = false;
           MAO = false;
         glutPostRedisplay();
   } else if(key == GLUT_KEY_F2){
           BASE = false;
           A1 = false;
           A2 = true;
           A3 = false;
           A4 = false;
           MAO = false;
         glutPostRedisplay();
   } else if(key == GLUT_KEY_F3){
           BASE = false;
           A1 = false;
           A2 = false;
           A3 = true;
           A4 = false;
           MAO = false;
         glutPostRedisplay();
   } else if(key == GLUT_KEY_F4){
           BASE = false;
           A1 = false;
           A2 = false;
           A3 = false;
           A4 = true;
           MAO = false;
         glutPostRedisplay();
   }else if(key == GLUT_KEY_F5){
           BASE = false;
           A1 = false;
           A2 = false;
           A3 = false;
           A4 = false;
           MAO = true;
         glutPostRedisplay();
   }

   if(key == GLUT_KEY_RIGHT){
        if(A1 == true){
         if(rotOmbro <= 90)
            rotOmbro += 5;
         glutPostRedisplay();
        } else if(MAO == true){
            if(rotMao <= 90)
         rotMao += 5;
         glutPostRedisplay();
        }else if(A4 == true){
            if(rotBraco <= 60)
         rotBraco += 5;
         glutPostRedisplay();
        }else if(A3 == true){
            if(rotAnteBraco <= 60)
         rotAnteBraco += 5;
         glutPostRedisplay();
        }else if(A2 == true){
            if(rotOmbro2 <= 60)
         rotOmbro2 += 5;
         glutPostRedisplay();
        }
   }else if(key == GLUT_KEY_LEFT){
        if(A1 == true){
            if(rotOmbro >= -90)
            rotOmbro -= 5;
         glutPostRedisplay();
        }else if(MAO == true){
            if(rotMao >= -90)
         rotMao -= 5;
         glutPostRedisplay();
        }else if(A4 == true){
            if(rotBraco >= -60)
         rotBraco -= 5;
         glutPostRedisplay();
        }else if(A3 == true){
            if(rotAnteBraco >= -60)
         rotAnteBraco -= 5;
         glutPostRedisplay();
        }else if(A2 == true){
            if(rotOmbro2 >= -60)
         rotOmbro2 -= 5;
         glutPostRedisplay();
        }
   }else if(key == GLUT_KEY_UP){
       if(A1 == true){
        if(art1 <= 90)
         art1 +=5;
         glutPostRedisplay();
         } else if(A2 == true){
         if(art2 <= 60)
         art2 +=5;
         glutPostRedisplay();
        }else if(A3 == true){
         if(art3 <= 60)
         art3 +=5;
         glutPostRedisplay();
        }else if(A4 == true){
        if(art4 <= 60)
         art4 +=5;
         glutPostRedisplay();
        }else if(MAO == true){
            if(rotMao2 <= 60)
         rotMao2 += 5;
         glutPostRedisplay();
        }
   }else if(key == GLUT_KEY_DOWN){
       if(A1 == true){
         if(art1 >= -90)
         art1 -=5;
         glutPostRedisplay();
         }else if(A2 == true){
         if(art2 >= -60)
         art2 -=5;
         glutPostRedisplay();
        }else if(A3 == true){
         if(art3 >= -60)
         art3 -=5;
         glutPostRedisplay();
        }else if(A4 == true){
         if(art4 >= -60)
         art4 -=5;
         glutPostRedisplay();
        }else if(MAO == true){
            if(rotMao2 >= -60)
         rotMao2 -= 5;
         glutPostRedisplay();
        }
   }
}


int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (800, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("MODELOS HIERARQUICOS - BRAÇO ROBÔ");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(teclado);
   glutMainLoop();
   return 0;
}
