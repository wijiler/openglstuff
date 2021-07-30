#include <GL/gl.h>
#include <GL/glut.h>

void render(void);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100); 
  glutInitWindowSize(640,480);
  glutCreateWindow("editor or smth");
  
  glutDisplayFunc(render);
  glutMainLoop();
}

void render(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glBegin(GL_TRIANGLES);
       glColor3f(1, 0 , 0);
       glVertex2f(-0.5, -0.5);
       glColor3f(0, 1 , 0);
       glVertex2f(0.5, -0.5);
       glColor3f(0, 0 , 1);
       glVertex2f(0.0, 0.5); 
    glEnd();

    glutSwapBuffers();
}
