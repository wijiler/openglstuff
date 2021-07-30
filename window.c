#include <GL/gl.h>
#include <GL/glut.h>

void display()
{
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100); 
  glutInitWindowSize(640,480);
  glutCreateWindow("editor or smth");
  
  glutDisplayFunc(display);
  glutMainLoop();
}
