#include <stdlib.h>
#include <GL/glut.h>

//ARRAY - HERMITE
float Array[4][3] = {
	{0.0 ,10.0, 0.0},	//	PONTO 1
	{-10.0,5.0,-2.0},	//	PONTO 2
	{-5.0, 6.0, 0.0},	//	PONTO TANGENTE 1
	{-2.0, -8.0 ,2.0}	//	PONTO TANGENTE 2
};

//ARRAY2 - BÉZIER
float Array2[4][3] = {
	{10.0,10.0,0.0},
	{5.0 ,15.0,2.0},
	{-5.0,0.0,0.0},
	{-10.0,5.0,-2.0}
};

int SUB = 10;
bool HERMITE  = true, BEZIER = false;

void reshape(int w, int h){

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40,(float)w/h, 0.4 ,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display() {

	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//POSICIONAMENTO DA CÂMERA
	gluLookAt(1.0 ,10.0 ,30.0,0.0,5.0,0.0,0.0,1.0,0.0);

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_STRIP);
	int i = 0;
	while(i != SUB){

		float u = (float)i/(SUB-1);
		float b0, b1, b2, b3, x, y, z;

		if(HERMITE == true){
		// BLENDING FUNCTIONS - HERMITE
		b0 =  2*u*u*u - 3*u*u + 1;
		b1 = -2*u*u*u + 3*u*u;
		b2 = u*u*u - 2*u*u + u;
		b3 = u*u*u - u*u;

		x = b0*Array[0][0] + b1*Array[1][0] + b2*Array[2][0] + b3*Array[3][0];
		y = b0*Array[0][1] + b1*Array[1][1] + b2*Array[2][1] + b3*Array[3][1];
		z = b0*Array[0][2] + b1*Array[1][2] + b2*Array[2][2] + b3*Array[3][2];

		} else if(BEZIER == true){
		// BLENDING FUNCTIONS - BÉZIER
		float iu = 1.0f - u;
		b0 = u*u*u;
		b1 = 3*u*u*iu;
		b2 = 3*u*iu*iu;
		b3 =  iu*iu*iu;

		x = b0*Array2[0][0] + b1*Array2[1][0] + b2*Array2[2][0] + b3*Array2[3][0];
		y = b0*Array2[0][1] + b1*Array2[1][1] + b2*Array2[2][1] + b3*Array2[3][1];
		z = b0*Array2[0][2] + b1*Array2[1][2] + b2*Array2[2][2] + b3*Array2[3][2];

		}
		glVertex3f(x, y, z);
		++i;
	}
	glEnd();

	if(HERMITE == true){
    //PONTOS 1 E 2
	glColor3f(0.0,1.0,0.0);
	glPointSize(4);
	glBegin(GL_POINTS);//DESENHA OS PONTOS INCIAL E FINAL
		glVertex3fv(Array[0]);
		glVertex3fv(Array[1]);
	glEnd();

	//PONTOS DAS TANGENTES
	glPushMatrix();
		glTranslatef(Array[0][0],Array[0][1],Array[0][2]);
		glBegin(GL_LINES);//DESENHA A LINHA DA PRIMEIRA TANGENTE
			glVertex3f(0.0,0.0,0.0 );
			glVertex3fv(Array[2]);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(Array[1][0],Array[1][1], Array[1][2]);
		glBegin(GL_LINES);//DESENHA A LINHA DA SEGUNDA TANGENTE
			glVertex3f(0.0,0.0,0.0 );
			glVertex3fv(Array[3]);
		glEnd();
	glPopMatrix();

	} else if(BEZIER == true){

	//DESENHA OS 4 PONTOS DE CONTROLE
	glColor3f(1.0,0.0,0.0);
	glPointSize(3);
	glBegin(GL_POINTS);
		for(int i=0;i!=4;++i) {
			glVertex3fv(Array2[i]);
		}
	glEnd();

	//DESENHA AS 4 LINHAS ENTRE OS PONTOS DE CONTROLE
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINE_STRIP);
		for(int i=0;i!=4;++i) {
			glVertex3fv(Array2[i] );
		}
	glEnd();
	}

	glutSwapBuffers();
}

void teclado(int key,int,int) {

    if(key == GLUT_KEY_F1){
            HERMITE = true;
            BEZIER = false;
            glutPostRedisplay();

    } else if(key == GLUT_KEY_F2){
            HERMITE = false;
            BEZIER = true;
            glutPostRedisplay();
    }

    if(key == GLUT_KEY_UP){
		++SUB;

    } else if(key == GLUT_KEY_DOWN){
		--SUB;
		if (SUB < 3)
			SUB = 3;
    }
	glutPostRedisplay();
}


int main(int argc,char** argv) {

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize(640,480);
	glutCreateWindow("CURVAS EM OPENGL *** F1 - HERMITE ---- F2 - BÉZIER ***");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(teclado);
	glutMainLoop();
	return 0;
}
