#include "CSCIx229.h"


/*
 *  Draw a cube
 *     at (x,y,z)
 *     dimensions (dx,dy,dz)
 *     rotated th about the y axis
 */
static void cube(
double x,double y,double z,
double dx,double dy,double dz,
double th,
double r, double g, double b,
unsigned int id
)
{
   //  Save transformation
   glPushMatrix();
   //  Offset
   glTranslated(x, y, z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);

   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, id);

   //  Cube
   glBegin(GL_QUADS);
   //  Front
   glColor3f(r, g, b);
   glNormal3f(0, 0, 1);
   glTexCoord2f(0, 0); glVertex3f(-1,-1, 1);
   glTexCoord2f(1, 0); glVertex3f(+1,-1, 1);
   glTexCoord2f(1, 1); glVertex3f(+1,+1, 1);
   glTexCoord2f(0, 1); glVertex3f(-1,+1, 1);
   //  Back
   glColor3f(r, g, b);
   glNormal3f(0, 0, -1);
   glTexCoord2f(0, 0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1, 0); glVertex3f(-1,-1,-1);
   glTexCoord2f(1, 1); glVertex3f(-1,+1,-1);
   glTexCoord2f(0, 1); glVertex3f(+1,+1,-1);
   //  Right
   glColor3f(r, g, b);
   glNormal3f(1, 0, 0);
   glTexCoord2f(0, 0); glVertex3f(+1,-1,+1);
   glTexCoord2f(1, 0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1, 1); glVertex3f(+1,+1,-1);
   glTexCoord2f(0, 1); glVertex3f(+1,+1,+1);
   //  Left
   glColor3f(r, g, b);
   glNormal3f(-1, 0, 0);
   glTexCoord2f(0, 0); glVertex3f(-1,-1,-1);
   glTexCoord2f(1, 0); glVertex3f(-1,-1,+1);
   glTexCoord2f(1, 1); glVertex3f(-1,+1,+1);
   glTexCoord2f(0, 1); glVertex3f(-1,+1,-1);
   //  Top
   glColor3f(r, g, b);
   glNormal3f(0, 1, 0);
   glTexCoord2f(0, 0); glVertex3f(-1,+1,+1);
   glTexCoord2f(1, 0); glVertex3f(+1,+1,+1);
   glTexCoord2f(1, 1); glVertex3f(+1,+1,-1);
   glTexCoord2f(0, 1); glVertex3f(-1,+1,-1);
   //  Bottom
   glColor3f(r, g, b);
   glNormal3f(0, -1, 0);
   glTexCoord2f(0, 0); glVertex3f(-1,-1,-1);
   glTexCoord2f(1, 0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1, 1); glVertex3f(+1,-1,+1);
   glTexCoord2f(0, 1); glVertex3f(-1,-1,+1);
   //  End
   glEnd();
   glDisable(GL_TEXTURE_2D);
   //  Undo transformations
   glPopMatrix();
}



/*
 *  Draw a ball
 *     at (x,y,z)
 *     radius r
 */
static void ball(double x,double y,double z,double r)
{
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   glTranslated(x,y,z);
   glScaled(r,r,r);
   //  White ball
   glColor3f(1,1,1);
   glutSolidSphere(1.0,16,16);
   //  Undo transofrmations
   glPopMatrix();
}