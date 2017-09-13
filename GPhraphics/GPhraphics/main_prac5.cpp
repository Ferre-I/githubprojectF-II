//Semestre 2018 - 1

//************************************************************//

//************************************************************//

//************** Alumno (s): Sotres Cataño Mario *************//

//*************											******//

//*************											******//

//************************************************************//

#include "Main.h"



float transZ = -5.0f;

float transX = 0.0f;

float angleX = 0.0f;

float angleY = 0.0f;

int screenW = 0.0;

int screenH = 0.0;
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



GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position

GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position



void InitGL ( void )     // Inicializamos parametros

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

	glEnable ( GL_COLOR_MATERIAL );

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}



void prisma(void)

{

	GLfloat vertice [8][3] = {

				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0

				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1

				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2

				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3

				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4

				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5

				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6

				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7

				};



		glBegin(GL_POLYGON);	//Front

			glNormal3f( 0.0f, 0.0f, 1.0f);

			glVertex3fv(vertice[0]);

			glVertex3fv(vertice[4]);

			glVertex3fv(vertice[7]);

			glVertex3fv(vertice[1]);

		glEnd();



		glBegin(GL_POLYGON);	//Right

			glNormal3f( 1.0f, 0.0f, 0.0f);

			glVertex3fv(vertice[0]);

			glVertex3fv(vertice[3]);

			glVertex3fv(vertice[5]);

			glVertex3fv(vertice[4]);

		glEnd();



		glBegin(GL_POLYGON);	//Back

			glNormal3f( 0.0f, 0.0f, -1.0f);

			glVertex3fv(vertice[6]);

			glVertex3fv(vertice[5]);

			glVertex3fv(vertice[3]);

			glVertex3fv(vertice[2]);

		glEnd();



		glBegin(GL_POLYGON);  //Left

			glNormal3f( -1.0f, 0.0f, 0.0f);

			glVertex3fv(vertice[1]);

			glVertex3fv(vertice[7]);

			glVertex3fv(vertice[6]);

			glVertex3fv(vertice[2]);

		glEnd();



		glBegin(GL_POLYGON);  //Bottom

			glNormal3f( 0.0f, -1.0f, 0.0f);

			glVertex3fv(vertice[0]);

			glVertex3fv(vertice[1]);

			glVertex3fv(vertice[2]);

			glVertex3fv(vertice[3]);

		glEnd();



		glBegin(GL_POLYGON);  //Top

			glNormal3f( 0.0f, 1.0f, 0.0f);

			glVertex3fv(vertice[4]);

			glVertex3fv(vertice[5]);

			glVertex3fv(vertice[6]);

			glVertex3fv(vertice[7]);

		glEnd();

}



void display ( void )   // Creamos la funcion donde se dibuja

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer

	//glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();



	glTranslatef(transX, 0.0f, transZ);

	glRotatef(angleY, 0.0, 1.0, 0.0);

	glRotatef(angleX, 1.0, 0.0, 0.0);

		//Poner Código Aquí.

	//BRAZO

	glPushMatrix();
		//hombro
		glRotatef(angHombro, 0.0,0.0,1.0); //Rotación del hombro. Sólo rota en z
		glPushMatrix();
			//(0,0,0)
			glColor3f(1.0, 0.0, 0.0);
			glScalef(0.5,0.5,1.0);
			prisma();
		glPopMatrix();

		//bícep (0,-0.75,0)
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();			
			glScalef(0.5,1.0,1.0);
			glColor3f(0.0, 1.0, 0.0);
			prisma();
		glPopMatrix();

		//codo
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angCodo, 0.0, 0.0, 1.0); //Generalmente los rotate se ponen después de un traslado
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
		glRotatef(angPalma, 0.0, 0.0, 1.0);
		glPushMatrix();		
			glScalef(0.5, 0.5, 1.0);
			glColor3f(1.0, 1.0, 0.0);
			prisma();
		glPopMatrix();

		//pulgar. 
		//dedo 1
		glPushMatrix();
			glTranslatef(0.25, 0.0, 0.0);
			glRotatef(angPulgar1, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);

			glColor3f(0.3, 0.5, 0.0);
			glPushMatrix();
				glScalef(0.2, 0.1, 0.3);
				prisma();
			glPopMatrix();

		//dedo2	
			glTranslatef(0.1, 0.0, 0.0);
			glRotatef(angPulgar2, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);

			glColor3f(1.0, 0.87, 0.55);
			glScalef(0.2, 0.1, 0.3);
			prisma();
		glPopMatrix();

		//meñique
		//dedo1
		glPushMatrix();
			glTranslatef(-0.2, -0.25, 0.0);
			glRotatef(angMenique1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);

			glColor3f(0.3, 0.5, 0.0);
			glPushMatrix();
				glScalef(0.1, 0.1, 0.3);
				prisma();
			glPopMatrix();

		//dedo2	
			glTranslatef(0.0, -0.05, 0.0);
			glRotatef(angMenique2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);

			glColor3f(1.0, 0.87, 0.55);
			glPushMatrix();
				glScalef(0.1, 0.1, 0.3);
				prisma();
			glPopMatrix();
		//dedo	
			glTranslatef(0.0, -0.05, 0.0);
			glRotatef(angMenique3, 1.0, 0.0, 0.0);
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
			glTranslatef(-0.067, -0.25, 0.0);
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
		glTranslatef(0.067, -0.25, 0.0);
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
		glTranslatef(0.2, -0.25, 0.0);
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

	//glLoadIdentity();									

}



void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function

{

	switch ( key ) {
		//parte de arriba del anular
	case 'r':
		angAnular3 += 0.5f;
		break;
	case 'R':
		angAnular3 -= 0.5f;

		break;
		//parte de en medio del anular
	case 'j':
		angAnular2 += 0.5f;
		break;
	case 'J':
		angAnular2 -= 0.5f;

		break;
		//parte de en abajo del anular
	case 'c':
		angAnular1 += 0.5f;
		break;
	case 'C':
		angAnular1 -= 0.5f;

		break;

		//parte de arriba del meñique
		case 'z':
			angMenique3 += 0.5f;
		break;
		case 'Z':
			angMenique3 -= 0.5f;

		break;
		case 'h':
			angMenique2 += 0.5f;
		break;
		case 'H':
			angMenique2 -= 0.5f;

		break;
		//parte de en medio del meñique
		case 'v':
			angMenique1 += 0.5f;
		break;
		case 'V':
			angMenique1 -= 0.5f;

		break;
		//parte de abajo del meñique
		case 'g':
			angPulgar2 += 0.5f;
		break;
		case 'G':
			angPulgar2 -= 0.5f;

		break;

		//parte de arriba del pulgar
		case 'm':
			angPulgar2 += 0.5f;
		break;
		case 'M':
			angPulgar2 -= 0.5f;

		break;


		//parte abajo del pulgar
		case 'k':
		case 'K':
			angPulgar1 += 0.5f;
		break;
		case 'L':

		case 'l':

			angPulgar1 -= 0.5f;

		break;

		//manipulación de la mano
		case 'o':
		case 'O':
			angPalma += 0.5f;
		break;
		case 'p':

		case 'P':

			angPalma -= 0.5f;

		break;

		//manipulación antebrazo/codo
		case 'u':
		case 'U':
			angCodo += 0.5f;
		break;
		case 'I':

		case 'i':

			angCodo -= 0.5f;

		break;
		//manipulación de brazo
		case 't':

		case 'T':

			angHombro += 0.5f;

			break;
		case 'Y':

		case 'y':

			angHombro -= 0.5f;

			break;

		case 'w':

		case 'W':

			transZ +=0.2f;

			break;

		case 's':

		case 'S':

			transZ -=0.2f;

			break;

		case 'a':

		case 'A':

			transX +=0.2f;

			break;

		case 'd':

		case 'D':

			transX -=0.2f;

			break;

		case 27:        // Cuando Esc es presionado...

			exit ( 0 );   // Salimos del programa

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

		angleX +=2.0f;

		break;

    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...

		angleX -=2.0f;

		break;

	case GLUT_KEY_LEFT:

		angleY +=2.0f;

		break;

	case GLUT_KEY_RIGHT:

		angleY -=2.0f;

		break;

    default:

      break;

  }

  glutPostRedisplay();

}





int main ( int argc, char** argv )   // Main Function

{

  glutInit            (&argc, argv); // Inicializamos OpenGL

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
