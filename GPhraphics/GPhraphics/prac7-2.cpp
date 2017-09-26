//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s):Avila Armenta Fernando Ivan ******//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna_tierra = 0;
int planeta = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

//El cuarto 1, indica luz posicional, el 0 direccional
GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position


GLfloat MercuryDiffuse[] = { 0.545, 0.271, 0.075, 1.0f };			// Mercurio
GLfloat MercurySpecular[] = {1.0, 1,0, 0.0, 1.0 };
GLfloat MercuryShininess[] = { 60.0 };

GLfloat VenusDiffuse[] = { 0.957, 0.643, 0.376, 1.0f };			// Venus
GLfloat VenusSpecular[] = {1.0, 1.0, 0.0, 1.0 };
GLfloat VenusShininess[] = { 100.0 };


GLfloat EarthDiffuse[] = { 0.0f, 0.7f, 0.7f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.0, 1, 1, 1.0 };
GLfloat EarthShininess[] = { 70.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna 1
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat Moon2Diffuse[] = { 0.137255,0.419608, 0.556863, 1.0f };			// Luna 2
GLfloat Moon2Specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat Moon2Shininess[] = { 70.0 };

GLfloat MarsDiffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat MarsShininess[] = { 30.0 };

GLfloat JupiterDiffuse[] = { 1.000, 0.855, 0.725, 1.0f };			// Jupiter
GLfloat JupiterSpecular[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat JupiterShininess[] = { 40.0 };

GLfloat SaturnDiffuse[] = { 1.000, 0.627, 0.478, 1.0f };			// Saturno
GLfloat SaturnSpecular[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat SaturnShininess[] = { 40.0 };


GLfloat Ring1Diffuse[] = { 1.000, 0.980, 0.804, 1.0f };			// Anillo 1
GLfloat Ring1Specular[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat Ring1Shininess[] = { 30.0 };

GLfloat Ring2Diffuse[] = { 1.000, 0.498, 0.314, 1.0f };			// Anillo 2
GLfloat Ring2Specular[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat Ring2Shininess[] = { 30.0 };



GLfloat UranusDiffuse[] = { 0.275, 0.510, 0.706, 1.0f };			// Urano
GLfloat UranusSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat UranusShininess[] = { 80.0 };

GLfloat NeptuneDiffuse[] = { 0.000, 0.000, 0.804, 1.0f };			// Neptuno
GLfloat NeptuneSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat NeptuneShininess[] = { 90.0 };


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);				
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara
	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glDisable(GL_LIGHTING);
	glutSolidSphere(2, 20, 20);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();
	//Mercurio
	glPushMatrix();
		glColor3f(0.545, 0.271, 0.075);
		glRotatef(planeta * -4, 0.0, 1.0, 0.0);//Traslación de Mercurio
		glTranslated(2.5,0.2,0.2);
		glRotatef(mercurio, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MercuryDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MercurySpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MercuryShininess);
		glutSolidSphere(0.25, 10, 10);  //Draw Mercury (radio,H,V);
	glPopMatrix();

	//Venus
	glPushMatrix();
		glColor3f(0.957, 0.643, 0.376);
		glRotatef(45, 0, 0, 1);
		glRotatef(planeta * (4), 0.0, 1.0, 0.0); //Traslación de Venus
		glTranslated(3.5, 0.2, 0.2);
		glRotatef(venus, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
		glutSolidSphere(0.3, 10, 10);  //Draw Venus (radio,H,V);
	glPopMatrix();

	//Tierra
	glPushMatrix();
		glColor3f(0.118, 0.565, 1.000);
		glRotatef(90, 0, 0, 1);
		glRotatef(planeta * 3, 0.0, 1.0, 0.0); //Traslación de la Tierra
		glTranslated(5.5, 0.2, 0.2);
		//(5.5,0.2,0.2)
		glPushMatrix();
			glRotatef(tierra, 0.0, 1.0,0.0);	//Rotación de la Tierra
			glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
			glutSolidSphere(0.4, 10, 10);  //Draw Earth (radio,H,V);
		glPopMatrix();
		//Luna
		glColor3f(0.753, 0.753, 0.753);
		glRotatef(luna_tierra, 0.0, 1.0, 0.0);	//Traslación de la Luna 
		glTranslated(1.2, 0.2, 0.2);
		glRotatef(planeta*2, 0.0, 1.0, 0.0);	//Rotación de la Luna
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
		glutSolidSphere(0.2, 10, 10);  //Draw Moon (radio,H,V);
	glPopMatrix();

	//Marte
	glPushMatrix();
		glColor3f(0.698, 0.133, 0.133);
		glRotatef(135, 0, 0, 1);
		glRotatef(planeta * 2, 0.0, 1.0, 0.0);
		glTranslated(8.0, 0.2, 0.2);
		glRotatef(planeta*3, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
		glutSolidSphere(0.35, 10, 10);  //Draw Mars (radio,H,V);
	glPopMatrix();

	//Jupiter
	glPushMatrix();
		glColor3f(1.000, 0.855, 0.725);
		glRotatef(180, 0, 0, 1);
		glRotatef(planeta * -1, 0.0, 1.0, 0.0);
		glTranslated(10.0, 0.2, 0.2);
		glPushMatrix();
			glRotatef(planeta*3, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);
			glutSolidSphere(0.7, 10, 10);  //Draw Jupiter (radio,H,V);
		glPopMatrix();
		glPushMatrix();
			//Luna 1
			glColor3f(0.753, 0.753, 0.753);
			glRotatef(planeta*3, 0.0, 1.0, 0.0);	//Traslación de la Luna 
			glTranslated(1.1, 0.2, 0.2);
			glRotatef(planeta * 2, 0.0, 1.0, 0.0);	//Rotación de la Luna 1
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.2, 10, 10);  //Draw Moon (radio,H,V);
		glPopMatrix();

		glPushMatrix();
			//Luna 2
			glColor3f(0.753, 0.753, 0.753);
			glRotatef(planeta * 3, 1.0, 0.0, 0.0);	//Traslación de la Luna 
			glTranslated(0.0, 1.0, 0.2);
			glRotatef(planeta * 2, 0.0, 1.0, 0.0);	//Rotación de la Luna 2
			glMaterialfv(GL_FRONT, GL_DIFFUSE, Moon2Diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, Moon2Specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, Moon2Shininess);
			glutSolidSphere(0.2, 10, 10);  //Draw Moon (radio,H,V);
		glPopMatrix();

	glPopMatrix();

	//Saturno
	glPushMatrix();
		glColor3f(1.000, 0.627, 0.478);
		glRotatef(225, 0, 0, 1);
		glRotatef(planeta * 2, 0.0, 1.0, 0.0); //Traslación de Saturno
		glTranslated(14.0, 0.2, 0.2);
		glPushMatrix();
			glRotatef(planeta * 3, 0.0, 1.0, 0.0);	//Rotación de Saturno
			glMaterialfv(GL_FRONT, GL_DIFFUSE, SaturnDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, SaturnShininess);
			glutSolidSphere(0.675, 10, 10);  //Draw Saturn (radio,H,V);
		glPopMatrix();

		glPushMatrix();
			//Luna 1
			glColor3f(0.753, 0.753, 0.753);
			glRotatef(30, 0, 0, 1);
			glRotatef(planeta * 3, 0.0, 1.0, 0.0);	//Traslación de la Luna 
			glTranslated(1.9, 0.2, 0.2);
			glRotatef(planeta * (-2), 0.0, 1.0, 0.0);	//Rotación de la Luna 1
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.2, 10, 10);  //Draw Moon (radio,H,V);
		glPopMatrix();

		glPushMatrix();
		//Luna 2
		glColor3f(0.753, 0.753, 0.753);
		glRotatef(30, 0, 0, 1);
		glRotatef(planeta * 3, 1.0, 0.0, 0.0);	//Traslación de la Luna 
		glTranslated(0.0, 1.8, 0.2);
		glRotatef(planeta * (-2), 0.0, 1.0, 0.0);	//Rotación de la Luna 2
		glMaterialfv(GL_FRONT, GL_DIFFUSE, Moon2Diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, Moon2Specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, Moon2Shininess);
		glutSolidSphere(0.2, 10, 10);  //Draw Moon (radio,H,V);
		glPopMatrix();

		glPushMatrix();
		//Anillo 1
			glRotatef(90, 0.0, 0.0, 1.0);
			glRotatef(planeta*(-1), 0.0, 1.0, 0.0);
			glColor3f(1.000, 0.980, 0.804);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, Ring1Diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, Ring1Specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, Ring1Shininess);
			glutSolidTorus(0.1,0.9,10,10);
		glPopMatrix();

		glPushMatrix();
		//Anillo 2
			glRotatef(90, 0.0, 0.0, 1.0);
			glRotatef(planeta * (-1), 0.0, 1.0, 0.0);
			glColor3f(1.000, 0.498, 0.314);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, Ring2Diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, Ring2Specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, Ring2Shininess);
			glutSolidTorus(0.1, 1.0, 10, 10);
		glPopMatrix();

	glPopMatrix();

	//Urano
	glPushMatrix();
		glColor3f(0.275, 0.510, 0.706);
		glRotatef(270, 0, 0, 1);
		glRotatef(planeta * 1, 0.0, 1.0, 0.0); //Traslación de Urano
		glTranslated(17.5, 0.2, 0.2);
		glRotatef(planeta * 3, 0.0, 1.0, 0.0);	//Rotación de Urano
		glMaterialfv(GL_FRONT, GL_DIFFUSE, UranusDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, UranusSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, UranusShininess);
		glutSolidSphere(0.625, 10, 10);  //Draw Uranus (radio,H,V);
	glPopMatrix();

	//Neptuno
	glPushMatrix();
		glColor3f(0.000, 0.000, 0.804);
		glRotatef(315, 0, 0, 1);
	glRotatef(planeta * (-2), 0.0, 1.0, 0.0); //Traslación de Neptuno
		glTranslated(19.0, 0.2, 0.2);
		glRotatef(planeta * 3, 0.0, 1.0, 0.0);	//Rotación de Neptuno
		glMaterialfv(GL_FRONT, GL_DIFFUSE, NeptuneDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, NeptuneSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, NeptuneShininess);
		glutSolidSphere(0.6, 10, 10);  //Draw Neptune (radio,H,V);
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();

}

void animacion() //Esta función sirve que se mueva automático el Sol
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime() //GetTickCount() sirve para que funcione a la misma velocidad en 
									//cualquier máquina
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;

		mercurio = (mercurio - 8) % 360;

		dwLastUpdateTime = dwCurrentTime;

		venus = (venus + 4) % 360;

		dwLastUpdateTime = dwCurrentTime;

		tierra = (tierra - 7) % 360;

		dwLastUpdateTime = dwCurrentTime;

		luna_tierra = (luna_tierra + 8) % 360;

		dwLastUpdateTime = dwCurrentTime;

		planeta = (planeta+1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay(); //Vuelve a dibujar la figura
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 500.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 7"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion); //Cuando no esté oprimiendo nada se va a llamar a la función animación
	glutMainLoop();          // 

	return 0;
}