#include <GL/glut.h>  
 
char title[] = "Rectangulo";
int n=5;
//GLfloat angleCube = 180.0f; 
//int refreshMills = 15; 
 
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClearDepth(1.0f);                   
   glEnable(GL_DEPTH_TEST);   
   glDepthFunc(GL_LEQUAL);    
   glShadeModel(GL_SMOOTH);   
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}
 
void dibujaRectangulo() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glMatrixMode(GL_MODELVIEW);     
    
   glLoadIdentity();                 
   glTranslatef(0.5f, 0.0f, -9.0f);  
   //glRotatef(angleCube, 1.0f, 1.0f, 1.0f); 

      glBegin(GL_QUADS);                
      glColor3f(0.0f, 1.0f, 0.0f);     //Verde
      glVertex3f( 2.0f, 1.0f, -1.0f);
      glVertex3f(-2.0f, 1.0f, -1.0f);
      glVertex3f(-2.0f, 1.0f,  1.0f);
      glVertex3f( 2.0f, 1.0f,  1.0f);
      
      glColor3f(1.0f, 0.5f, 0.0f);     //Naranja
      glVertex3f( 2.0f, -1.0f,  1.0f);
      glVertex3f(-2.0f, -1.0f,  1.0f);
      glVertex3f(-2.0f, -1.0f, -1.0f);
      glVertex3f( 2.0f, -1.0f, -1.0f);
       
      glColor3f(1.0f, 0.0f, 0.0f);     //Rojo
      glVertex3f( 2.0f,  1.0f, 1.0f);
      glVertex3f(-2.0f,  1.0f, 1.0f);
      glVertex3f(-2.0f, -1.0f, 1.0f);
      glVertex3f( 2.0f, -1.0f, 1.0f);
 
	  glColor3f(1.0f, 1.0f, 0.0f);  //Amarillo
      glVertex3f( 2.0f, -1.0f, -1.0f);
      glVertex3f(-2.0f, -1.0f, -1.0f);
      glVertex3f(-2.0f,  1.0f, -1.0f);
      glVertex3f( 2.0f,  1.0f, -1.0f);
 
      glColor3f(0.0f, 0.0f, 1.0f);    //Azul
      glVertex3f(-2.0f,  1.0f,  1.0f);
      glVertex3f(-2.0f,  1.0f, -1.0f);
      glVertex3f(-2.0f, -1.0f, -1.0f);
      glVertex3f(-2.0f, -1.0f,  1.0f);
 
      glColor3f(1.0f, 0.0f, 1.0f);     //Rosa
      glVertex3f(2.0f,  1.0f, -1.0f);
      glVertex3f(2.0f,  1.0f,  1.0f);
      glVertex3f(2.0f, -1.0f,  1.0f);
      glVertex3f(2.0f, -1.0f, -1.0f);
   glEnd();  
 
   glutSwapBuffers(); 
   //angleCube -= 0.15f;
}
//Metodo recursivo para dibujar piramide
/*void dibujaPiramide(int n){
for
}*/

void timer(int value) {
   glutPostRedisplay();     
   //glutTimerFunc(refreshMills, timer, 0); 
}
 
void reshape(GLsizei width, GLsizei height) {  
   
   if (height == 0) height = 1;                
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
       glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();             
      gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 

int main(int argc, char** argv) {
   glutInit(&argc, argv);            
   glutInitDisplayMode(GLUT_DOUBLE); 
   glutInitWindowSize(640, 480);   
   glutInitWindowPosition(50, 50); 
   glutCreateWindow(title);          
   glutDisplayFunc(dibujaRectangulo);       
   glutReshapeFunc(reshape);      
   initGL();     
   glutTimerFunc(0, timer, 0);
   glutMainLoop();                 
   return 0;
}