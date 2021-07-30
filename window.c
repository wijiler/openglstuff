#include <GL/gl.h>
#include <GL/glut.h>

void render(void);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); // sets values like I want depth and color
  glutInitWindowPosition(100,100);
  glutInitWindowSize(640,480);
  glutCreateWindow("editor or smth"); // window title
  
  glutDisplayFunc(render); // tells opengl hey stinky head render is the render function
  glutMainLoop(); // will make it not crash
}

void render(void) {
}
