/*
* Titulo:  Proyecto Recorrido por virtual por Teotihuacan
* Materia: Graficación
* Alumnos: López Niño Ingrid Paola
*		   Martínez Hernández Gabriela
*		   Ziga López Antonio
*/

#include <windows.h>  
#include <GL/glut.h>  
#include "math.h"

//--------------------------------VARIABLES------------------------------------------------
//Variables (lx y lz) que definen la dirección en la que ve la cámara
//Variables (x y z) para la posición de la cámara
//Variable (angulo) para asignar el ángulo de rotación de la cámara en el eje y (Ocupados en el método GlulookAt)
float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 5.0f;
float angulo = 0.0f;

//--------------------------------MÉTODOS---------------------------------------------------
// Método que dibuja la figura
void dibujaFigura(){
	glColor3f(1.0f, 1.0f, 1.0f);

	// Dibuja esfera
	glTranslatef(0.0f, 0.75f, 0.0f);
	glutSolidSphere(0.75f, 20, 20);
}

void dibujarPiramide(){
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 0.75f, 0.0f);  
	glBegin(GL_QUADS);      
	glPushMatrix();
      glColor3f(0.0f, 1.0f, 0.0f);     
      glVertex3f( 3.0f, 1.0f, -1.0f);
      glVertex3f(-3.0f, 1.0f, -1.0f);
      glVertex3f(-3.0f, 1.0f,  1.0f);
      glVertex3f( 3.0f, 1.0f,  1.0f);
 
     
      glColor3f(1.0f, 0.5f, 0.0f);     
      glVertex3f( 3.0f, -1.0f,  1.0f);
      glVertex3f(-3.0f, -1.0f,  1.0f);
      glVertex3f(-3.0f, -1.0f, -1.0f);
      glVertex3f( 3.0f, -1.0f, -1.0f);
 
      
      glColor3f(1.0f, 0.0f, 0.0f);     
      glVertex3f( 3.0f,  1.0f, 1.0f);
      glVertex3f(-3.0f,  1.0f, 1.0f);
      glVertex3f(-3.0f, -1.0f, 1.0f);
      glVertex3f( 3.30f, -1.0f, 1.0f);
 
	  glColor3f(1.0f, 1.0f, 0.0f);  
      glVertex3f( 3.0f, -1.0f, -1.0f);
      glVertex3f(-3.0f, -1.0f, -1.0f);
      glVertex3f(-3.0f,  1.0f, -1.0f);
      glVertex3f( 3.0f,  1.0f, -1.0f);
 
      
      glColor3f(0.0f, 0.0f, 1.0f);    
      glVertex3f(-3.0f,  1.0f,  1.0f);
      glVertex3f(-3.0f,  1.0f, -1.0f);
      glVertex3f(-3.0f, -1.0f, -1.0f);
      glVertex3f(-3.0f, -1.0f,  1.0f);
 
      glColor3f(1.0f, 0.0f, 1.0f);     
      glVertex3f(3.0f,  1.0f, -1.0f);
      glVertex3f(3.0f,  1.0f,  1.0f);
      glVertex3f(3.0f, -1.0f,  1.0f);
      glVertex3f(3.0f, -1.0f, -1.0f);
	  glPopMatrix();
}

// MÉTODO RESHAPE PARA EL AJUSTE DE LA VENTANA CUANDO CAMBIE DE TAMAÑO
void reshape(int w, int h){
	// Esto proviene que el tamaño de la ventana sea cero
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);// Se usa la matriz de proyección
	glLoadIdentity();// Limpia la Matriz
	glViewport(0, 0, w, h);// El punto de vista inicial
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);// Se asigna la perspectiva
	glMatrixMode(GL_MODELVIEW);// Se usa la matriz del modelo de vista
}

// MÉTODO PARA LA CREACIÓN DE LA ESCENA
void creacionEscena(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Método par limpiar el buffer de color y el depth buffer
	glLoadIdentity();//Limpia las transformaciones

	//Método gluLookAt que sirve para acomodar la cámara dondé:
	//Los primeros 3 valores indican la posición de la cámara
	//Los siguientes 3 indican hacia donde se está observando
	//Y los últimos 3 utilizados para invertir la posición de la cámara
	gluLookAt(x, 1.0f, z,x + lx, 1.0f, z + lz,0.0f, 1.0f, 0.0f);

	glColor3f(0.0,1.0,1.0);
	glutSolidSphere(45, 20, 20);

	//Creación del suelo del escenario
	glBegin(GL_QUADS);
	glColor3f(0.5,1.0,0.0);
	glVertex3f(-50.0f, 0.0f, -50.0f);
	glVertex3f(-50.0f, 0.0f, 50.0f);
	glVertex3f(50.0f, 0.0f, 50.0f);
	glVertex3f(50.0f, 0.0f, -50.0f);
	glEnd();

	// Dibujo de los elementos que contendrá la escena
	for (int i = -1; i < 1; i++)
		for (int j = -1; j < 1; j++) {
			glPushMatrix();
			glTranslatef(i*10.0, 0, j * 10.0);
			dibujaFigura();
			glPopMatrix();
		}
	glutSwapBuffers();
}

// MÉTODO QUE ESTABLECE LAS ACCIONES QUE SERÁN REALIZADAS AL PRESIONAR CIERTA TECLA
void specialKey(int key, int xx, int yy){
	//Cada vez que una tecla se oprime modifica los valores de la cámara como angulo, posición o vista
	float fraccion = 0.5f;

	switch (key) {
	case GLUT_KEY_LEFT:
		angulo -= 0.01f;
		lx = sin(angulo);
		lz = -cos(angulo);
		break;
	case GLUT_KEY_RIGHT:
		angulo += 0.01f;
		lx = sin(angulo);
		lz = -cos(angulo);
		break;
	case GLUT_KEY_UP:
		x += lx * fraccion;
		z += lz * fraccion;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraccion;
		z -= lz * fraccion;
		break;
	}
}

// MÉTODO MAIN
int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("RECORRIDO VIRTUAL POR TEOTIHUÁCAN");
	glutInitWindowPosition(100, 100); //Posición inicial de la ventana
	glutInitWindowSize(320, 320); //Tamaño inicial de la ventana
	glutDisplayFunc(creacionEscena);//Función para la creación de la escena
	glutReshapeFunc(reshape); //Función para el cambio de temaño de la ventana
	glutIdleFunc(creacionEscena); //Función que ejecuta un método todo el tiempo
	glutSpecialFunc(specialKey); //Función de las teclas
	glEnable(GL_DEPTH_TEST); 
	glutMainLoop();
}