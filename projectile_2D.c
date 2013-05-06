#include <GL/gl.h>
#include <GL/glut.h>

#define GRAVITY 10
#define VELOCITY_X 40
#define VELOCITY_Y 70

float time;
float xCoordinate;
float yCoordinate;

void init()
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
}

void calculatPosition()
{
   xCoordinate = VELOCITY_X * time;
   yCoordinate = VELOCITY_Y * time - 0.5 * GRAVITY * time * time;
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (-20., (GLdouble) w-20.0, -20.0, (GLdouble) h-20.0);
   glMatrixMode (GL_MODELVIEW);
}

void display()
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 0.0, 0.0);
   glLoadIdentity ();             /* clear the matrix */

   glTranslatef(xCoordinate, yCoordinate, 0.0);
   glutWireSphere(20, 100, 2);   /* draw the ball */

   glEnd();

   glFlush ();
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
   case 'f':
   case 'F':
      time += 0.1;
      calculatPosition();
      glutPostRedisplay();
      break;
   case 'r':
   case 'R':
      time -= 0.1;
      calculatPosition();
      glutPostRedisplay();
      break;
   default:
      break;
   }
}

int main(int argc, char *argv[])
{
   time = xCoordinate = yCoordinate = 0.0;

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (600, 400);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
