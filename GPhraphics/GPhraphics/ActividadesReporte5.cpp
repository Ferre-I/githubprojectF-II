//Semestre 2018 - 2

//************************************************************//

//************************************************************//

//************** Alumno (s):Avila Armenta Fernando**********//

//*************											******//

//*************											******//

//************************************************************//

#include "Main.h"



//Posiciones de la luz de iluminación

GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position

GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position


int screenW = 0.0;

int screenH = 0.0;

///////keyboard & arrow_keys
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;

//Angulos de control de los brazos
float angHombro = 0.0f;
float angCodo = 0.0f;
float angPalma = 0.0f;
float angPulgar1 = 0.0f;
float angPulgar2 = 0.0f;
float angMenique1 = 0.0f;
float angMenique2 = 0.0f;
float angMenique3 = 0.0f;
float angAnular1 = 0.0f;
float angAnular2 = 0.0f;
float angAnular3 = 0.0f;
//////


void InitGL(void)     // Inicializamos parametros

{



	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer

	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing



														//Configuracion luz

	glLightfv(GL_LIGHT0, GL_POSITION, Position);

	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);





	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar

	glEnable(GL_COLOR_MATERIAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}



void prisma(void)

{

	GLfloat vertice[8][3] = {

		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0

		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1

		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2

		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3

		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4

		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5

		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6

		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7

	};



	glBegin(GL_POLYGON);	//Front

	glNormal3f(0.0f, 0.0f, 1.0f);

	glVertex3fv(vertice[0]);

	glVertex3fv(vertice[4]);

	glVertex3fv(vertice[7]);

	glVertex3fv(vertice[1]);

	glEnd();



	glBegin(GL_POLYGON);	//Right

	glNormal3f(1.0f, 0.0f, 0.0f);

	glVertex3fv(vertice[0]);

	glVertex3fv(vertice[3]);

	glVertex3fv(vertice[5]);

	glVertex3fv(vertice[4]);

	glEnd();



	glBegin(GL_POLYGON);	//Back

	glNormal3f(0.0f, 0.0f, -1.0f);

	glVertex3fv(vertice[6]);

	glVertex3fv(vertice[5]);

	glVertex3fv(vertice[3]);

	glVertex3fv(vertice[2]);

	glEnd();



	glBegin(GL_POLYGON);  //Left

	glNormal3f(-1.0f, 0.0f, 0.0f);

	glVertex3fv(vertice[1]);

	glVertex3fv(vertice[7]);

	glVertex3fv(vertice[6]);

	glVertex3fv(vertice[2]);

	glEnd();



	glBegin(GL_POLYGON);  //Bottom

	glNormal3f(0.0f, -1.0f, 0.0f);

	glVertex3fv(vertice[0]);

	glVertex3fv(vertice[1]);

	glVertex3fv(vertice[2]);

	glVertex3fv(vertice[3]);

	glEnd();



	glBegin(GL_POLYGON);  //Top

	glNormal3f(0.0f, 1.0f, 0.0f);

	glVertex3fv(vertice[4]);

	glVertex3fv(vertice[5]);

	glVertex3fv(vertice[6]);

	glVertex3fv(vertice[7]);

	glEnd();

}



void cuerpo() {

	glPushMatrix();

	//cabeza
	glPushMatrix();
	//(0,0,0)--->pivote
	glColor3f(1.0, 0.0, 0.0);
	prisma();
	glPopMatrix();

	//cuello
	glPushMatrix();
	//(0,-0.75,0)--->pivote de cuello
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.5, 0.5, 1.0);  //escalamos el cuello
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	//torso
	glPushMatrix();
	//(0,-2.5,0)--->pivote del torso
	glTranslatef(0.0, -2.5, 0.0);
	glScalef(3.0, 3.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	prisma();
	glPopMatrix();


	//Pierna Derecha
	glPushMatrix();
	//(-1,-7.5,0)--->pivote del torso
	glTranslatef(-1, -7.5, 0.0);
	glScalef(1.0, 7.0, 1.0);
	glColor3f(0.0, 0.8, 0.8);
	prisma();
	glPopMatrix();

	//Pie Derecho
	glPushMatrix();
	//(-1,-7.5,0)--->pivote del torso
	glTranslatef(-2, -12.5, 0.0);
	glScalef(3.0, 3.0, 1.0);
	glColor3f(0.2, 0.2, 0.0);
	prisma();
	glPopMatrix();


	//Pierna Izquierdo
	glPushMatrix();
	//(1,-7.5,0)--->pivote del torso
	glTranslatef(1, -7.5, 0.0);
	glScalef(1.0, 7.0, 1.0);
	glColor3f(0.0, 0.8, 0.8);
	prisma();
	glPopMatrix();

	//Pie Izquierdo
	glPushMatrix();
	//(1,-7.5,0-)--->pivote del torso
	glTranslatef(2, -12.5, 0.0);
	glScalef(3.0, 3.0, 1.0);
	glColor3f(0.2, 0.2, 0.0);
	prisma();
	glPopMatrix();



	glPopMatrix();

}



void brazo(int sentido) {
	glPushMatrix();
		//hombro
	angAnular2 = angAnular3 = angAnular1;
		glRotatef(angHombro*sentido, 0.0, 0.0, 1.0); //Rotación del hombro. Sólo rota en z
		glPushMatrix();
			//(0,0,0)
			glColor3f(1.0, 0.0, 0.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
			glPopMatrix();

			//bícep (0,-0.75,0)
			glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glScalef(0.5, 1.0, 1.0);
			glColor3f(0.0, 1.0, 0.0);
			prisma();
			glPopMatrix();

			//codo
			glTranslatef(0.0, -0.75, 0.0);
			glRotatef(angCodo*sentido, 0.0, 0.0, 1.0); //Generalmente los rotate se ponen después de un traslado
			glPushMatrix();
			//(0,-0.75,0)
			glScalef(0.5, 0.5, 1.0);
			glColor3f(0.0, 0.0, 1.0);
			prisma();
			glPopMatrix();

			//antebrazo
			glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			//(0,-0.75,0)
			glScalef(0.5, 1.0, 1.0);
			glColor3f(0.4, 0.0, 0.0);
			prisma();
			glPopMatrix();

			//palma   (0,-3.0,0)	
			glTranslatef(0.0, -0.75, 0.0);
			glRotatef((angPalma)*sentido, 0.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.5, 0.5, 1.0);
			glColor3f(1.0, 1.0, 0.0);
			prisma();
			glPopMatrix();

			//pulgar. 
			//dedo 1
			glPushMatrix();
			glTranslatef(0.25*sentido, 0.0, 0.35);
			glRotatef(-60, 1.0, 0.0, 0.0);
			glRotatef((angPulgar1-30)*sentido, 0.0, 0.0, 1.0);
			glTranslatef(0.1*sentido, 0.0, 0.0);

			glColor3f(0.3, 0.5, 0.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 0.3);
			prisma();
			glPopMatrix();

			//dedo2	
			glTranslatef(0.1*sentido, 0.0, 0.0);
			glRotatef((angPulgar2)*sentido, 0.0, 0.0, 1.0);
			glTranslatef(0.1*sentido, 0.0, 0.0);

			glColor3f(1.0, 0.87, 0.55);
			glScalef(0.2, 0.1, 0.3);
			prisma();
			glPopMatrix();

			//meñique
			//dedo1
			glPushMatrix();
			glTranslatef(-0.2*sentido, -0.25, 0.35);
			glRotatef(angAnular1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);

			glColor3f(0.3, 0.5, 0.0);
			glPushMatrix();
			glScalef(0.1, 0.1, 0.3);
			prisma();
			glPopMatrix();

			//dedo2	
			glTranslatef(0.0, -0.05, 0.0);
			glRotatef(angAnular2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);

			glColor3f(1.0, 0.87, 0.55);
			glPushMatrix();
			glScalef(0.1, 0.1, 0.3);
			prisma();
			glPopMatrix();
			//dedo	
			glTranslatef(0.0, -0.05, 0.0);
			glRotatef(angAnular3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);

			glColor3f(0.23, 0.67, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.1, 0.3);
			prisma();
			glPopMatrix();

			glPopMatrix();


			//Anular
			//dedo1
			glPushMatrix();
			glTranslatef(-0.067*sentido, -0.25, 0.35);
			glRotatef(angAnular1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glColor3f(0.3, 0.5, 0.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 0.3);
			prisma();
			glPopMatrix();

			//dedo2	
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angAnular2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glColor3f(1.0, 0.87, 0.55);
			glPushMatrix();
			glScalef(0.1, 0.2, 0.3);
			prisma();
			glPopMatrix();
			//dedo	
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angAnular3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glColor3f(0.23, 0.67, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 0.3);
			prisma();
			glPopMatrix();

			glPopMatrix();


			//Medio
			//dedo1
			glPushMatrix();
			glTranslatef(0.067*sentido, -0.25, 0.35);
			glRotatef(angAnular1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.15, 0.0);

			glColor3f(0.3, 0.5, 0.0);
			glPushMatrix();
			glScalef(0.1, 0.3, 0.3);
			prisma();
			glPopMatrix();

			//dedo2	
			glTranslatef(0.0, -0.15, 0.0);
			glRotatef(angAnular2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.15, 0.0);

			glColor3f(1.0, 0.87, 0.55);
			glPushMatrix();
			glScalef(0.1, 0.3, 0.3);
			prisma();
			glPopMatrix();
			//dedo	
			glTranslatef(0.0, -0.15, 0.0);
			glRotatef(angAnular3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.15, 0.0);

			glColor3f(0.23, 0.67, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.3, 0.3);
			prisma();
			glPopMatrix();

			glPopMatrix();

			//Índice
			//dedo1
			glPushMatrix();
			glTranslatef(0.2*sentido, -0.25, 0.35);
			glRotatef(angAnular1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glColor3f(0.3, 0.5, 0.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 0.3);
			prisma();
			glPopMatrix();

			//dedo2	
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angAnular2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glColor3f(1.0, 0.87, 0.55);
			glPushMatrix();
			glScalef(0.1, 0.2, 0.3);
			prisma();
			glPopMatrix();
			//dedo	
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angAnular3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glColor3f(0.23, 0.67, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 0.3);
			prisma();
			glPopMatrix();

			glPopMatrix();


		glPopMatrix();

	glPopMatrix();



}








void display ( void )   // Creamos la funcion donde se dibuja

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer

	//glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();



		glTranslatef(transX, transY +2, transZ-2);
		glTranslatef(0,-4.5,0);
		glRotatef(angleX, 1, 0, 0);
		glRotatef(angleY, 0, 1, 0);
		glRotatef(angleZ, 0, 0, 1);
		glTranslatef(0, 4.5, 0);
		cuerpo();
		glPushMatrix();
			glTranslatef(1.74,-1.25,0);
			brazo(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.74, -1.25, 0);
		brazo(-1);
		glPopMatrix();

		//Poner Código Aquí.



	
		
									

  glutSwapBuffers ( );

  // Swap The Buffers

}




void reshape ( int width , int height )   // Creamos funcion Reshape

{

  if (height==0)										// Prevenir division entre cero

	{

		height=1;

	}



	glViewport(0,0,width,height);	



	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix

	glLoadIdentity();



	// Tipo de Vista

	//glOrtho(-5,5,-5,5,0.2,20);	

	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);



	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix

}




void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ -= 0.2f;
		//printf("Posicion en Z: %f\n", transZ);
		break;
	case 's':
	case 'S':
		transZ += 0.2f;
		//printf("Posicion en Z: %f\n", transZ);
		break;
	case 'a':
	case 'A':
		transX -= 0.2f;
		//printf("Posicion en X: %f\n", transX);
		break;
	case 'd':
	case 'D':
		transX += 0.2f;
		//printf("Posicion en X: %f\n", transX);
		break;
	case 'r':
	case 'R':
		transY += 0.2f;
		//printf("Posicion en Y: %f\n", transY);
		break;
	case 'F':
	case 'f':
		transY -= 0.2f;
		//printf("Posicion en Y: %f\n", transY);
		break;
	case 'H':
	case 'h':
		if(angHombro<180)
		angHombro += 1.15f;
		else
		angHombro =180;
		break;
	case 'L':
	case 'l':
		if (angHombro > 0)
			angHombro -= 1.15f;
		else
			angHombro = 0;
		//printf("Posicion en X: %f\n", angleX);
		break;
	case 'j':
	case 'J':
		if (angCodo < 150)
			angCodo += 1.15f;
		else
			angCodo = 150;
		break;
	case 'k':
	case 'K':
		if (angCodo > 0)
			angCodo -= 1.15f;
		else
			angCodo = 0;
		//printf("Posicion en X: %f\n", angleX);
		break;
	case 'o':
		if (angPulgar1 > -60)
			angPulgar1 -= 1.15f;
		else
			angPulgar1 = -60;
		break;
	case 'O':
		if (angPulgar1 < 0)
			angPulgar1 += 1.15f;
		else
			angPulgar1 = 0;
		//printf("Posicion en X: %f\n", angleX);
		break;
	case 'y':
		if (angPulgar2 > -90)
			angPulgar2 -= 1.15f;
		else
			angPulgar2 = -90;
		break;
	case 'Y':
		if (angPulgar2 < 0)
			angPulgar2 += 1.15f;
		else
			angPulgar2 = 0;
		//printf("Posicion en X: %f\n", angleX);
		break;
	case 'p':
		if (angPalma < 20)
			angPalma += 1.15f;
		else
			angPalma = 20;
		//printf("Posicion en X: %f\n", angleX);
		break;
	case 'P':
		if (angPalma > 0)
			angPalma -= 1.15f;
		else
			angPalma = 0;
		//printf("Posicion en X: %f\n", angleX);
		break;
	case 'i':
	case 'I':
		if (angAnular1 < 0)
			angAnular1 += 1.15f;
		else
			angAnular1 = 0;
		break;
	case 'u':
	case 'U':
		if (angAnular1 > -90)
			angAnular1 -= 1.15f;
		else
			angAnular1 = -90;
		//printf("Posicion en X: %f\n", angleX);
		break;


	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}




void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)

{

  switch ( a_keys ) {

    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX -= 1.15f;
		break;

    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX += 1.15f;
		break;

	case GLUT_KEY_LEFT:
		angleY--;
		break;

	case GLUT_KEY_RIGHT:
		angleY++;
		break;

    default:

      break;

  }

  glutPostRedisplay();

}





int main ( int argc, char** argv )   // Main Function

{

  glutInit            (&argc, argv); // Inicializamos OpenGL

  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )

  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )

  screenW = glutGet(GLUT_SCREEN_WIDTH);

  screenH = glutGet(GLUT_SCREEN_HEIGHT);

  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana

  glutInitWindowPosition (0, 0);	//Posicion de la Ventana

  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana

  printf("Resolution H: %i \n", screenW);

  printf("Resolution V: %i \n", screenH);

  InitGL ();						// Parametros iniciales de la aplicacion

  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo

  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano

  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado

  glutSpecialFunc     ( arrow_keys );	//Otras

  glutMainLoop        ( );          // 



  return 0;

}






