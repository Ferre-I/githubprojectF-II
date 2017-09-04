//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Avila Armenta Fernando Ivan******//
//*************											******//
//*************											******//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


float color(int r, int g, int b) {
	//Función para codificar colores rgb, con un byte para cada color.
	//Forma un paleta rgb de tres bytes
	int color = 0;
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255)) {
		color = 0;
	}
	else {
		color = r*(65536) + g*(256) + b;
	}
	return color;
}

void InitGL ( GLvoid )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(int cS, int cIq, int cD, int cI, int cF, int cA, float Base, float Altura)
{
	float CP[6][3] = { { ((float)((cF >> 16)) )/ 255,(float)((cF & 0xFF00)>>8) / 255,(float)(cF & 0xFF) / 255},
					   { (float)(cD >> 16) / 255,(float)((cD & 0xFF00)>>8) / 255,(float)(cD & 0xFF) / 255},
					   { (float)(cA >> 16) / 255,(float)((cA &0xFF00)>>8) / 255,(float)(cA & 0xFF) / 255},
					   { (float)(cIq >> 16) /255,(float)((cIq&0xFF00)>>8) / 255,(float)(cIq & 0xFF) / 255},
					   { (float)(cI >> 16) / 255,(float)((cI &0xFF00)>> 8) / 255,(float)(cI & 0xFF) / 255},
					   { (float)(cS >> 16) / 255,(float)((cS &0XFF00)>> 8) / 255,(float)(cS & 0xFF) / 255}
						};

	GLfloat vertice [8][3] = {
				{0.5*Base ,-0.5*Altura, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5*Base,-0.5*Altura, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5*Base,-0.5*Altura, -0.5},    //Coordenadas Vértice 2 V2
				{0.5*Base,-0.5*Altura, -0.5},    //Coordenadas Vértice 3 V3
				{0.5*Base,0.5*Altura, 0.5},    //Coordenadas Vértice 4 V4
				{0.5*Base,0.5*Altura, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5*Base,0.5*Altura, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5*Base,0.5*Altura, 0.5},    //Coordenadas Vértice 7 V7
				};
	system("cls");
	printf("Frente \n%f %f %f\n ", CP[0][0], CP[0][1], CP[0][2]);
	printf("Derecha \n%f %f %f\n ", CP[1][0], CP[1][1], CP[1][2]);
	printf("Atras \n%f %f %f\n ", CP[2][0], CP[2][1], CP[2][2]);
	printf("Izquierda \n%f %f %f\n", CP[3][0], CP[3][1], CP[3][2]);
	printf("Fondo \n%f %f %f\n", CP[4][0], CP[4][1], CP[4][2]);
	printf("Techo \n%f %f %f\n ", CP[5][0], CP[5][1], CP[5][2]);
		
		glBegin(GL_POLYGON);	//Front
			glColor3f(CP[0][0], CP[0][1], CP[0][2]);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
		glColor3f(CP[1][0], CP[1][1], CP[1][2]);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
		glColor3f(CP[2][0], CP[2][1], CP[2][2]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
		glColor3f(CP[3][0], CP[3][1], CP[3][2]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
	
		glColor3f(CP[4][0], CP[4][1], CP[4][2]);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
		glColor3f(CP[5][0], CP[5][1], CP[5][2]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		//Poner Código Aquí.
	glTranslatef(0+transX,0+transY,0+transZ);
	
	//F
	glTranslatef(1, 0,-10);
	glRotatef(angleX, -1, 0, 0);
	glRotatef(angleY, 0, 1, 0);
	glRotatef(angleZ, 0, 0, 1);
	glTranslatef(-1, 0, 0);
	//Poner colores conforme al código rgb de 0 a 255, en
	//el siguiente orden:
			//Superior,Inferior,Derecho,Izquierdo,Frente,Atras
			//En este caso se puso 
			//Rojo, Azul Marino, Verde Limón, Verde, Amarillo, Azul Cielo
	//Luego insertar dimensiones las caras frontal y trasera del Cubo
	//en el siguiente orden:	
			//Base, Altura
	prisma(color(255, 1, 0), color(0, 255, 0), color(200, 250, 100), color(0, 69, 99),
	color(255, 255, 0), color(0, 200, 200), 5, 5);


    glutSwapBuffers ( );
    //glFlush();
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
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 100.0);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ -=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 's':
		case 'S':
			transZ +=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			printf("Posicion en X: %f\n", transX);
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			printf("Posicion en X: %f\n", transX);
			break;
		case 'r':
		case 'R':
			transY += 0.2f;
			printf("Posicion en Y: %f\n", transY);
			break;
		case 'F':
		case 'f':
			transY -= 0.2f;
			printf("Posicion en Y: %f\n", transY);
			break;
		case 'i':
		case 'I':
			angleX += 1.15f;
			printf("Posicion en X: %f\n", angleX);
			break;
		case 'k':
		case 'K':
			angleX -= 1.15f;
			printf("Posicion en X: %f\n", angleX);
			break;
		case 'j':
		case 'J':
			angleY += 1.15f;
			printf("Posicion en X: %f\n", angleX);
			break;
		case 'l':
		case 'L':
			angleY -= 1.15f;
			printf("Posicion en X: %f\n", angleX);
			break;
		case 'u':
		case 'U':
			angleZ += 1.15f;
			printf("Posicion en X: %f\n", angleX);
			break;
		case 'o':
		case 'O':
			angleZ -= 1.15f;
			printf("Posicion en X: %f\n", angleX);
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



