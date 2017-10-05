//Semestre 2018 - 1
//************************************************************//
//************************************************************//
// ******* Alumno (s): Avila Armenta Fernando Ivan ***********//
//*************											******//
//*************											******//
//************************************************************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;

bool light=false;




GLfloat Diffuse[]=   { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]=  { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat Direccion[]= { 0.0f, -2.0f, 0.0f, 1.0f };			// Light Diection

GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat LightPosition1[] = { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };				// Light Direction


GLfloat LightAmbient1[] = { 0.0f, 0.0f, 1.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightDiffuse1[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular1[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light 


GLfloat WoodAmbient[] = { 1, 1, 0};
GLfloat WoodDiffuse[] = { 0.7038, 0.27048, 0.0828 };			// Mercurio
GLfloat WoodSpecular[] = {0.256777, 0.137622, 0.086014 };
GLfloat WoodShininess[] = { 80.0 };



CTexture t_puerta;
CTexture t_Ajedrez2;
CTexture t_metal01;
CTexture t_ladrillo;
CTexture t_madera;
CTexture t_ventanaM;

CTexture t_tejado;

int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;

int i = 0;

//V
float b = 3, h = 2;
float px = 0, py = +0.35; //PV Wnd, px*LX,py*LY <=0.25
float lx = 2.1 * 2, ly = 0.7 * 2, x1 = 0.5 + 0.25*lx + px;
GLfloat WI[2][2] = { { -0.25*lx + px,0.25*lx + px },
{ -0.25*ly + py, 0.25*ly + py },
};
GLfloat WE[5][2] = {
	{ 0.5*b,-0.5*h },
	{ 0.5*b,0.5*h },
	{ -0.5*b,0.5*h },
	{ -0.5*b,-0.5*h },
	{ 0.5*b,-0.5*h }
};

GLfloat CT[2][2] = { { (0.5*b - 0.25*lx + px) / b, (0.5*b + 0.25*lx + px) / b },
{ (0.5*h - 0.25*ly + py) / h, (0.5*h + 0.25*ly + py) / h }
};

float z = 0.05;


void InitGL(GLvoid)     // Inicializamos parametros
{


	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glShadeModel(GL_FLAT); //Especial
	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);



	t_puerta.LoadTGA("puerta.tga");
	t_puerta.BuildGLTexture();
	t_puerta.ReleaseImage();

	t_metal01.LoadTGA("madera.tga");
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_Ajedrez2.LoadTGA("02.tga");
	t_Ajedrez2.BuildGLTexture();
	t_Ajedrez2.ReleaseImage();

	t_ladrillo.LoadTGA("textura1.tga");
	t_ladrillo.BuildGLTexture();
	t_ladrillo.ReleaseImage();

	t_madera.LoadTGA("muroMadera.tga");
	t_madera.BuildGLTexture();
	t_madera.ReleaseImage();

	t_ventanaM.LoadTGA("ventana.tga");
	t_ventanaM.BuildGLTexture();
	t_ventanaM.ReleaseImage();

	t_tejado.LoadTGA("tejado.tga");
	t_tejado.BuildGLTexture();
	t_tejado.ReleaseImage();
	
}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}




void prisma (GLuint textura1, GLuint textura2)  //Funcion creacion prisma
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

		
		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			//glColor3f(1.0,1.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();
	
		glBindTexture(GL_TEXTURE_2D, 0);
		glColor3f(0.2,0,0);
		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		

		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(4.0, 4.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0, 4.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(0, 0, -5);
	glTranslatef(pos_camX, pos_camY, pos_camZ);
	glRotatef(eye_camX, 1.0, 0.0, 0.0);
	glRotatef(eye_camY, 0.0, 1.0, 0.0);
	glRotatef(eye_camZ, 0.0, 0.0, 1.0);
	
		glPushMatrix();
		
		//Pivote (0,0,0)
		glTranslatef(0,0,3.05);
			glPushMatrix();
			//Muro del frente
				
			glBindTexture(GL_TEXTURE_2D, t_madera.GLindex);
				//Frente
				glBegin(GL_QUAD_STRIP);
					glColor3f(1,1,1);
					glNormal3f(0, 0, 1);
					glTexCoord2f(0.667,0); glVertex3f(0.4, -1.5, z);
					glTexCoord2f(1,0); glVertex3f(1.5, -1.5, z);
					glTexCoord2f(0.6334, 0.5836); glVertex3f(0.4, 0.25, z);
					glTexCoord2f(1, 0.667); glVertex3f(1.5, 0.5, z);
					glTexCoord2f(0.3667,0.5836); glVertex3f(-0.4, 0.25, z);
					glTexCoord2f(0, 0.667); glVertex3f(-1.5, 0.5, z);
					glTexCoord2f(0.334, 0); glVertex3f(-0.4, -1.5, z);
					glTexCoord2f(0, 0); glVertex3f(-1.5, -1.5, z);
				glEnd();

				glBegin(GL_POLYGON);
				glColor3f(1, 1, 1);
				glNormal3f(0, 0, 1);
				glTexCoord2f(1, 0.667); glVertex3f(1.5,0.5, z);
				glTexCoord2f(0.5, 1); glVertex3f(0,1.5, z);
				glTexCoord2f(0, 0.667); glVertex3f(-1.5, 0.5, z);
				glEnd();

				glPushMatrix();
				glTranslatef(0,-0.625,z);
				glScalef(0.8,1.75,0.01);
				glRotatef(90,0,0,1);
				prisma(t_puerta.GLindex, t_metal01.GLindex);
				glPopMatrix();
			glPopMatrix();


			//Ventanas
			/////////////////////////////////////////////////
			glPushMatrix();
				
			glTranslatef(1.55,-0.5,-1.45);
			glRotatef(90,0,1,0);
				glPushMatrix();
				//Muro de enfrente
				glBindTexture(GL_TEXTURE_2D, t_madera.GLindex);
					glBegin(GL_QUAD_STRIP);
					glColor3f(1, 1, 1);
					glNormal3f(0, 0, 1);
					glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], z);
					glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], z);
					glTexCoord2f(CT[0][1], CT[1][1]); glVertex3f(WI[0][1], WI[1][1], z);
					glTexCoord2f(1, 1); glVertex3f(WE[1][0], WE[1][1], z);
					glTexCoord2f(CT[0][0], CT[1][1]); glVertex3f(WI[0][0], WI[1][1], z);
					glTexCoord2f(0, 1); glVertex3f(WE[2][0], WE[2][1], z);
					glTexCoord2f(CT[0][0], CT[1][0]); glVertex3f(WI[0][0], WI[1][0], z);
					glTexCoord2f(0, 0); glVertex3f(WE[3][0], WE[3][1], z);
					glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], z);
					glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], z);
					glEnd();

					
					for (i = 0; i<4; i++) {
						glBegin(GL_QUAD_STRIP);	
						glColor3f(1, 1, 1);
						glNormal3f(1, 0, 0);
						glTexCoord2f(0, 0); glVertex3f(WE[i][0], WE[i][1], -z);
						glTexCoord2f(0.2, 0); glVertex3f(WE[i][0], WE[i][1], z);
						glTexCoord2f(0, 1); glVertex3f(WE[i + 1][0], WE[i + 1][1], -z);
						glTexCoord2f(0.2, 1); glVertex3f(WE[i + 1][0], WE[i + 1][1], z);
						glEnd();
					}

						glBegin(GL_QUAD_STRIP);
						glColor3f(1, 1, 1);
						glNormal3f(1, 0, 0);
						glTexCoord2f(0, 0); glVertex3f(WI[0][0], WI[1][0], -z);
						glTexCoord2f(0, 0.2); glVertex3f(WI[0][0], WI[1][0], z);
						glTexCoord2f(1, 0); glVertex3f(WI[0][0], WI[1][1], -z);
						glTexCoord2f(1, 0.2); glVertex3f(WI[0][0], WI[1][1], z);
						glEnd();


						glBegin(GL_QUAD_STRIP);
						glBindTexture(GL_TEXTURE_2D, t_madera.GLindex);
						glColor3f(1, 1, 1);
						glNormal3f(1, 0, 0);
						glTexCoord2f(0, 0); glVertex3f(WI[0][0], WI[1][1], -z);
						glTexCoord2f(0, 0.2); glVertex3f(WI[0][0], WI[1][1], z);
						glTexCoord2f(1, 0); glVertex3f(WI[0][1], WI[1][1], -z);
						glTexCoord2f(1, 0.2); glVertex3f(WI[0][1], WI[1][1], z);
						glEnd();


						glBegin(GL_QUAD_STRIP);
						glColor3f(1, 1, 1);
						glNormal3f(1, 0, 0);
						glTexCoord2f(0, 0); glVertex3f(WI[0][1], WI[1][1], -z);
						glTexCoord2f(0, 0.2); glVertex3f(WI[0][1], WI[1][1], z);
						glTexCoord2f(1, 0); glVertex3f(WI[0][1], WI[1][0], -z);
						glTexCoord2f(1, 0.2); glVertex3f(WI[0][1], WI[1][0], z);
						glEnd();


						glBegin(GL_QUAD_STRIP);
						glColor3f(1, 1, 1);
						glNormal3f(1, 0, 0);
						glTexCoord2f(0, 0); glVertex3f(WI[0][1], WI[1][0], -z);
						glTexCoord2f(0, 0.2); glVertex3f(WI[0][1], WI[1][0], z);
						glTexCoord2f(1, 0); glVertex3f(WI[0][0], WI[1][0], -z);
						glTexCoord2f(1, 0.2); glVertex3f(WI[0][0], WI[1][0], z);
						glEnd();


						glBegin(GL_QUAD_STRIP);
						glColor3f(1, 1, 1);
						glNormal3f(0, 0, 1);
						glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], -z);
						glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], -z);
						glTexCoord2f(CT[0][1], CT[1][1]); glVertex3f(WI[0][1], WI[1][1], -z);
						glTexCoord2f(1, 1); glVertex3f(WE[1][0], WE[1][1], -z);
						glTexCoord2f(CT[0][0], CT[1][1]); glVertex3f(WI[0][0], WI[1][1], -z);
						glTexCoord2f(0, 1); glVertex3f(WE[2][0], WE[2][1], -z);
						glTexCoord2f(CT[0][0], CT[1][0]); glVertex3f(WI[0][0], WI[1][0], -z);
						glTexCoord2f(0, 0); glVertex3f(WE[3][0], WE[3][1], -z);
						glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], -z);
						glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], -z);
						glEnd();
						

				glPopMatrix();
				
				glPushMatrix();
				glTranslatef(0, 0.35, 0);
				glBindTexture(GL_TEXTURE_2D, t_ventanaM.GLindex);
				glBegin(GL_QUADS);
				glColor3f(1, 1, 1);
				glNormal3f(0, 0, 1);
				glTexCoord2f(0, 0); glVertex3f(-1.05, -0.35, 0);
				glTexCoord2f(0, 1); glVertex3f(-1.05, 0.35, 0);
				glTexCoord2f(1, 1); glVertex3f(1.05, 0.35, 0);
				glTexCoord2f(1, 0); glVertex3f(1.05, -0.35, 0);
				glEnd();
				glPopMatrix();

			glPopMatrix();
			/////////////////////////////////////////////////////////////////////////

			glPushMatrix();

			glTranslatef(1.55, -0.5, -4.45);
			glRotatef(90, 0, 1, 0);
			glPushMatrix();
			//Muro de enfrente
			glBindTexture(GL_TEXTURE_2D, t_madera.GLindex);
			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], z);
			glTexCoord2f(CT[0][1], CT[1][1]); glVertex3f(WI[0][1], WI[1][1], z);
			glTexCoord2f(1, 1); glVertex3f(WE[1][0], WE[1][1], z);
			glTexCoord2f(CT[0][0], CT[1][1]); glVertex3f(WI[0][0], WI[1][1], z);
			glTexCoord2f(0, 1); glVertex3f(WE[2][0], WE[2][1], z);
			glTexCoord2f(CT[0][0], CT[1][0]); glVertex3f(WI[0][0], WI[1][0], z);
			glTexCoord2f(0, 0); glVertex3f(WE[3][0], WE[3][1], z);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], z);
			glEnd();


			for (i = 0; i<4; i++) {
				glBegin(GL_QUAD_STRIP);
				glColor3f(1, 1, 1);
				glNormal3f(1, 0, 0);
				glTexCoord2f(0, 0); glVertex3f(WE[i][0], WE[i][1], -z);
				glTexCoord2f(0.2, 0); glVertex3f(WE[i][0], WE[i][1], z);
				glTexCoord2f(0, 1); glVertex3f(WE[i + 1][0], WE[i + 1][1], -z);
				glTexCoord2f(0.2, 1); glVertex3f(WE[i + 1][0], WE[i + 1][1], z);
				glEnd();
			}

			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][0], WI[1][0], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][0], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][0], WI[1][1], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][0], WI[1][1], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glBindTexture(GL_TEXTURE_2D, t_madera.GLindex);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][0], WI[1][1], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][0], WI[1][1], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][1], WI[1][1], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][1], WI[1][1], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][1], WI[1][1], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][1], WI[1][1], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][1], WI[1][0], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][1], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][0], WI[1][0], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][0], WI[1][0], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], -z);
			glTexCoord2f(CT[0][1], CT[1][1]); glVertex3f(WI[0][1], WI[1][1], -z);
			glTexCoord2f(1, 1); glVertex3f(WE[1][0], WE[1][1], -z);
			glTexCoord2f(CT[0][0], CT[1][1]); glVertex3f(WI[0][0], WI[1][1], -z);
			glTexCoord2f(0, 1); glVertex3f(WE[2][0], WE[2][1], -z);
			glTexCoord2f(CT[0][0], CT[1][0]); glVertex3f(WI[0][0], WI[1][0], -z);
			glTexCoord2f(0, 0); glVertex3f(WE[3][0], WE[3][1], -z);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], -z);
			glEnd();


			glPopMatrix();

			glPushMatrix();
			glTranslatef(0, 0.35, 0);
			glBindTexture(GL_TEXTURE_2D, t_ventanaM.GLindex);
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-1.05, -0.35, 0);
			glTexCoord2f(0, 1); glVertex3f(-1.05, 0.35, 0);
			glTexCoord2f(1, 1); glVertex3f(1.05, 0.35, 0);
			glTexCoord2f(1, 0); glVertex3f(1.05, -0.35, 0);
			glEnd();
			glPopMatrix();

			glPopMatrix();
			///////////////////////////////////////////////////////////////////
			glPushMatrix();

			glTranslatef(-1.55, -0.5, -1.45);
			glRotatef(90, 0, 1, 0);
			glPushMatrix();
			//Muro de enfrente
			glBindTexture(GL_TEXTURE_2D, t_madera.GLindex);
			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], z);
			glTexCoord2f(CT[0][1], CT[1][1]); glVertex3f(WI[0][1], WI[1][1], z);
			glTexCoord2f(1, 1); glVertex3f(WE[1][0], WE[1][1], z);
			glTexCoord2f(CT[0][0], CT[1][1]); glVertex3f(WI[0][0], WI[1][1], z);
			glTexCoord2f(0, 1); glVertex3f(WE[2][0], WE[2][1], z);
			glTexCoord2f(CT[0][0], CT[1][0]); glVertex3f(WI[0][0], WI[1][0], z);
			glTexCoord2f(0, 0); glVertex3f(WE[3][0], WE[3][1], z);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], z);
			glEnd();


			for (i = 0; i<4; i++) {
				glBegin(GL_QUAD_STRIP);
				glColor3f(1, 1, 1);
				glNormal3f(1, 0, 0);
				glTexCoord2f(0, 0); glVertex3f(WE[i][0], WE[i][1], -z);
				glTexCoord2f(0.2, 0); glVertex3f(WE[i][0], WE[i][1], z);
				glTexCoord2f(0, 1); glVertex3f(WE[i + 1][0], WE[i + 1][1], -z);
				glTexCoord2f(0.2, 1); glVertex3f(WE[i + 1][0], WE[i + 1][1], z);
				glEnd();
			}

			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][0], WI[1][0], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][0], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][0], WI[1][1], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][0], WI[1][1], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glBindTexture(GL_TEXTURE_2D, t_madera.GLindex);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][0], WI[1][1], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][0], WI[1][1], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][1], WI[1][1], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][1], WI[1][1], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][1], WI[1][1], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][1], WI[1][1], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][1], WI[1][0], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][1], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][0], WI[1][0], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][0], WI[1][0], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], -z);
			glTexCoord2f(CT[0][1], CT[1][1]); glVertex3f(WI[0][1], WI[1][1], -z);
			glTexCoord2f(1, 1); glVertex3f(WE[1][0], WE[1][1], -z);
			glTexCoord2f(CT[0][0], CT[1][1]); glVertex3f(WI[0][0], WI[1][1], -z);
			glTexCoord2f(0, 1); glVertex3f(WE[2][0], WE[2][1], -z);
			glTexCoord2f(CT[0][0], CT[1][0]); glVertex3f(WI[0][0], WI[1][0], -z);
			glTexCoord2f(0, 0); glVertex3f(WE[3][0], WE[3][1], -z);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], -z);
			glEnd();


			glPopMatrix();

			glPushMatrix();
			glTranslatef(0, 0.35, 0);
			glBindTexture(GL_TEXTURE_2D, t_ventanaM.GLindex);
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-1.05, -0.35, 0);
			glTexCoord2f(0, 1); glVertex3f(-1.05, 0.35, 0);
			glTexCoord2f(1, 1); glVertex3f(1.05, 0.35, 0);
			glTexCoord2f(1, 0); glVertex3f(1.05, -0.35, 0);
			glEnd();
			glPopMatrix();

			glPopMatrix();
			/////////////////////////////////////////////////////////////////////////

			glPushMatrix();

			glTranslatef(-1.55, -0.5, -4.45);
			glRotatef(90, 0, 1, 0);
			glPushMatrix();
			//Muro de enfrente
			glBindTexture(GL_TEXTURE_2D, t_madera.GLindex);
			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], z);
			glTexCoord2f(CT[0][1], CT[1][1]); glVertex3f(WI[0][1], WI[1][1], z);
			glTexCoord2f(1, 1); glVertex3f(WE[1][0], WE[1][1], z);
			glTexCoord2f(CT[0][0], CT[1][1]); glVertex3f(WI[0][0], WI[1][1], z);
			glTexCoord2f(0, 1); glVertex3f(WE[2][0], WE[2][1], z);
			glTexCoord2f(CT[0][0], CT[1][0]); glVertex3f(WI[0][0], WI[1][0], z);
			glTexCoord2f(0, 0); glVertex3f(WE[3][0], WE[3][1], z);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], z);
			glEnd();


			for (i = 0; i<4; i++) {
				glBegin(GL_QUAD_STRIP);
				glColor3f(1, 1, 1);
				glNormal3f(1, 0, 0);
				glTexCoord2f(0, 0); glVertex3f(WE[i][0], WE[i][1], -z);
				glTexCoord2f(0.2, 0); glVertex3f(WE[i][0], WE[i][1], z);
				glTexCoord2f(0, 1); glVertex3f(WE[i + 1][0], WE[i + 1][1], -z);
				glTexCoord2f(0.2, 1); glVertex3f(WE[i + 1][0], WE[i + 1][1], z);
				glEnd();
			}

			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][0], WI[1][0], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][0], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][0], WI[1][1], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][0], WI[1][1], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glBindTexture(GL_TEXTURE_2D, t_madera.GLindex);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][0], WI[1][1], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][0], WI[1][1], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][1], WI[1][1], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][1], WI[1][1], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][1], WI[1][1], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][1], WI[1][1], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][1], WI[1][0], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(0, 0.2); glVertex3f(WI[0][1], WI[1][0], z);
			glTexCoord2f(1, 0); glVertex3f(WI[0][0], WI[1][0], -z);
			glTexCoord2f(1, 0.2); glVertex3f(WI[0][0], WI[1][0], z);
			glEnd();


			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], -z);
			glTexCoord2f(CT[0][1], CT[1][1]); glVertex3f(WI[0][1], WI[1][1], -z);
			glTexCoord2f(1, 1); glVertex3f(WE[1][0], WE[1][1], -z);
			glTexCoord2f(CT[0][0], CT[1][1]); glVertex3f(WI[0][0], WI[1][1], -z);
			glTexCoord2f(0, 1); glVertex3f(WE[2][0], WE[2][1], -z);
			glTexCoord2f(CT[0][0], CT[1][0]); glVertex3f(WI[0][0], WI[1][0], -z);
			glTexCoord2f(0, 0); glVertex3f(WE[3][0], WE[3][1], -z);
			glTexCoord2f(CT[0][1], CT[1][0]); glVertex3f(WI[0][1], WI[1][0], -z);
			glTexCoord2f(1, 0); glVertex3f(WE[0][0], WE[0][1], -z);
			glEnd();


			glPopMatrix();

			glPushMatrix();
			glTranslatef(0, 0.35, 0);
			glBindTexture(GL_TEXTURE_2D, t_ventanaM.GLindex);
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-1.05, -0.35, 0);
			glTexCoord2f(0, 1); glVertex3f(-1.05, 0.35, 0);
			glTexCoord2f(1, 1); glVertex3f(1.05, 0.35, 0);
			glTexCoord2f(1, 0); glVertex3f(1.05, -0.35, 0);
			glEnd();
			glPopMatrix();

			glPopMatrix();

			///////////////////////////////////////////////////////////////////
			//////Ventanas
			//////////////////////////////////////////////////////77


			glPushMatrix();
			glTranslatef(0, 0, -5.95);
			//Muro del fondo

			glBindTexture(GL_TEXTURE_2D, t_madera.GLindex);
			//Frente
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-1.5, -1.5, z);
			glTexCoord2f(1, 0); glVertex3f(1.5, -1.5, z);
			glTexCoord2f(1, 0.667); glVertex3f(1.5, 0.5, z);
			glTexCoord2f(0, 0.667); glVertex3f(-1.5, 0.5, z);
			glEnd();

			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(1, 0.667); glVertex3f(1.5, 0.5, z);
			glTexCoord2f(0.5, 1); glVertex3f(0, 1.5, z);
			glTexCoord2f(0, 0.667); glVertex3f(-1.5, 0.5, z);
			glEnd();
			glPopMatrix();

			glBindTexture(GL_TEXTURE_2D, t_tejado.GLindex);
			glBegin(GL_QUAD_STRIP);
			glColor3f(1, 1, 1);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0,0); glVertex3f(1.5, 0.5, z+1);
			glTexCoord2f(1, 0); glVertex3f(1.5, 0.5, z-7);
			glTexCoord2f(0, 1); glVertex3f(0, 1.5, z+1);
			glTexCoord2f(1, 1); glVertex3f(0, 1.5, z-7);
			glTexCoord2f(0, 0); glVertex3f(-1.5, 0.5, z+1);
			glTexCoord2f(1, 0); glVertex3f(-1.5, 0.5, z - 7);
			glEnd();
			glPopMatrix();

		glPopMatrix();
		///////////////////////////////////
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas");
	glEnable(GL_TEXTURE_2D);
	

	glutSwapBuffers ( );

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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
	case 'q':   //Movimientos de camara
	case 'Q':
		pos_camY += 0.5f;
		//eye_camZ -= 0.5f;
		break;

	case 'e':
	case 'E':
		pos_camY -= 0.5f;
		//eye_camZ += 0.5f;
		break;

		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			light = !light;
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
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
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
  glutInitWindowSize  (1280, 780);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 8"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}