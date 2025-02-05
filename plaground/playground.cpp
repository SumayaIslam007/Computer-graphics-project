#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#include<stdio.h>

#define PI 3.1416
static GLfloat spin = 0.0;

static float	tx	=  0.0,bx=0.0,by=0.0,isbaby=0,dolnay=0,glUp=1,angle=0,step=0,stepx=0,stepy=0,cloudleftx=0,cloudmiddlex=0,cloudrightx=0,cloudrightupx=0,countdolna=0;
static float	ty	=  5.0;

static float cloudLeftMove=0,shipMove=70,shipx=0;
static float xx=10,yy=13;

void baby();

void circle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void halfcircle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 51; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void sky()
{
    glPushMatrix();
    glColor3f(0.53f,0.807f,0.98f);
    glTranslated(0,10,1),
    glBegin(GL_QUADS);
    glVertex2d(-150.0,0.0);
    glVertex2d(150.0,0.0);
    glVertex2d(150.0,-8);
    glVertex2d(-150.0,-8);
    glEnd();
    glPopMatrix();

}

void hillSide()
{
    glPushMatrix();
    glScaled(1,0.6,0);
    glPushMatrix(); //pahar
    glTranslated(-9.5,0.0,1);
    glColor3f(0.42, 0.56, 0.137);
    glTranslatef(0,5,0);
    halfcircle(12,5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(8.5,0.0,1);
    glColor3f(0.0,1.0,0);
    glTranslatef(0,5,0);
    halfcircle(15,7);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4.5,0.0,1);
    glColor3f(0.68, 1, 0.184);
    glTranslatef(0,5,0);
    halfcircle(6,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-13.4,5,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(1.0,0.0);
    glVertex2f(4.0,1.75);
    glVertex2f(5.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.2,5,1);
    glRotated(180,0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(1.0,0.0);
    glVertex2f(4.0,1.78);
    glVertex2f(5.0,0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void hillTree()
{
    glPushMatrix();//Big tree
    glTranslated(-15,6,0);
    glScaled(0.5,0.2,0);
    glPushMatrix();
    glTranslated(-1,-10,1);
    glColor3f(0.55,0.27,0.0745);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(1.0,10.0);
    glVertex2d(1.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5,0,0);
    glScaled(0.4,1,1);
    glPushMatrix();
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(7,6);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.5,1.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.5,-0.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0,6.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.5,-3.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.5,-3.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}

void field()
{

    glPushMatrix();
    glColor3f(0.4, 0.8039, 0);
    glBegin(GL_QUADS);
    glVertex2d(-150.0,0.0);
    glVertex2d(150.0,0.0);
    glVertex2d(150.0,-50);
    glVertex2d(-150.0,-50);
    glEnd();
    glPopMatrix();
}

void river()
{

    glPushMatrix();
    glTranslatef(0,20,0);
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.85, 0.90);
    glVertex2d(-150.0,-16.4);
    glVertex2d(150.0,-16.4);
    glVertex2d(150.0,-16.5);
    glVertex2d(-150.0,-16.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.565f, 1.0f);
    glVertex2d(150.0,-16.5);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2d(-150.0,-16.5);
    glColor3f(0.062f, 0.31f, 0.545f);
    glVertex2d(-150.0,-20);
    glColor3f(0.388f, 0.72f, 1.0f);
    glVertex2d(150.0,-20);
    glEnd();

    glPopMatrix();
    glPopMatrix();

}


void ship()
{

    if(isbaby==8)
    {

        shipx=shipx-0.03;
        if(shipx<-25)
            shipx=20;

    }


    glPushMatrix();
    glTranslated(0+shipx,0.8,0);
    glScaled(0.5,0.2,0);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f); //ship body front
    glVertex2d(0.0f,0.0f);
    glVertex2d(-3.0f,7.0f);
    glVertex2d(10.0f,7.0f);
    glVertex2d(8.0f,0.0f);

    glColor3f(0.0f,1.0f,0.0f); //green box front
    glVertex2d(2.0f,7.0f);
    glVertex2d(2.0f,9.0f);
    glVertex2d(8.0f,9.0f);
    glVertex2d(8.0f,7.0f);

    glColor3f(0.0f,0.0f,1.0f); //blue box front
    glVertex2d(3.0f,9.0f);
    glVertex2d(3.0f,11.0f);
    glVertex2d(7.0f,11.0f);
    glVertex2d(7.0f,9.0f);

    glColor3f(1.0f,0.0f,0.0f); //red stand front
    glVertex2d(4.0f,9.0f);
    glVertex2d(4.0f,15.0f);
    glVertex2d(6.0f,15.0f);
    glVertex2d(6.0f,9.0f);

    glEnd();
    glPopMatrix();
}

void sun()
{
    glPushMatrix();
    glTranslated(-4,8,0);
    glScaled(0.3,0.3,0);
    glColor3f(1,0.843,0);
    circle(2.5,3.5);
    glPopMatrix();
}


void cloudLeft()
{
    cloudleftx=cloudleftx-0.01;
    if(cloudleftx<-4)
    {
        cloudleftx=40;
    }
    //printf("%f\n",cloudleftx);

    glPushMatrix();
    glTranslated(-20+cloudleftx,8.5,1);
    glScaled(0.5,0.2,1);
    glColor3f(1.0f,1.0f,1.0f);
    glPushMatrix();
    glTranslated(0,0,1),
                 circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.5,1,1),
                 circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,1.5,1),
                 circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.5,-0.7,1),
                 circle(2.5,2.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.0,-1.0,1),
                 circle(1.5,2.5);
    glPopMatrix();
    glPopMatrix();


}


void cloudRightUp()
{
    glPushMatrix();
    glTranslated(14,16.5,1);
    glScaled(0.5,0.2,0);
    glColor3f(1.0f,1.0f,1.0f);
    glPushMatrix();
    glTranslated(0,-38,1),
                 circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,-35,1),
                 circle(2,3);
    glPopMatrix();

    glPushMatrix();

    glTranslated(3,-35,1),
                 circle(2,3);
    glPopMatrix();

    glPushMatrix();

    glTranslated(4.5,-37.5,1);
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,-38.5,1),
                 circle(1.5,2.5);
    glPopMatrix();
    glPopMatrix();

}

void cloudRight()
{

    cloudrightx-=0.02;
    if(cloudrightx<-35)
    {
        cloudrightx=2;
    }
    //printf("%f\n",cloudrightx);

    glPushMatrix();
    glTranslated(12+cloudrightx,16,1);
    glScaled(0.5,0.2,1);
    glColor3f(1.0f,1.0f,1.0f);
    glPushMatrix();
    glTranslated(0,-38,1),
                 circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,-35,1),
                 circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,-35,1),
                 circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.5,-37.5,1),
                 circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,-38.5,1),
                 circle(1.5,2.5);
    glPopMatrix();
    glPopMatrix();
}



void cloudMiddle()
{
    cloudmiddlex=cloudmiddlex-0.03;
    if(cloudmiddlex<-20)
    {
        cloudmiddlex=30;
    }
    //printf("%f\n",cloudmiddlex);
    glPushMatrix();
    glTranslated(-3.5+cloudmiddlex,16,1);
    glScaled(0.5,0.2,1);
    glColor3f(1.0f,1.0f,1.0f);
    glPushMatrix();
    glTranslated(0,-38,1),
                 circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,-35,1),
                 circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,-35,1),
                 circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.5,-37.5,1),
                 circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,-38.5,1),
                 circle(1.5,2.5);
    glPopMatrix();
    glPopMatrix();


}

void babySwing()
{
    glPushMatrix();
    //printf("Hi:%f\n",dolnay);

    if(isbaby==1 /*&& (dolnay==0|| dolnay>=1 || dolnay<=-1)*/)
    {

        if(dolnay==0)
        {
            glTranslated(-14,1,0);
            glScaled(0.05,0.05,0);
            //glTranslatef(20,24+dolnay,0);
        }
        else if(dolnay>=1 )
        {
            glTranslated(-14,-0.4+dolnay,0);
            glScaled(0.04,0.04,0);
            dolnay=-0.1;

            //dolnay=-1;
            //glTranslatef(20,26.5+dolnay,0);
        }
        else if(dolnay<=-1 )
        {
            glTranslated(-14,2.4+dolnay,0);
            //glTranslated(-14,1,0);
            glScaled(0.06,0.06,0);
            dolnay=0.1;
            //printf("hi");
            //dolnay=1;
            //glTranslatef(20,23+dolnay,0);
        }
        else if(dolnay>0.1 && dolnay <1)
        {
            //glTranslated(-14,0.65+dolnay,0);
            glTranslated(0,-0.29+dolnay,0);
            glTranslated(-14,1,0);
            glScaled(0.05,0.05,0);
            countdolna++;
            //printf("hi");
        }

        else if(dolnay<-0.1 && dolnay >-1)
        {
            glTranslated(-14,1.35+dolnay,0);
            glScaled(0.05,0.05,0);
        }


        glPopMatrix();

        glPopMatrix();
    }
    glPopMatrix();
}

void swing()
{
    glPushMatrix();
    glTranslated(-18,-1.5,0);
    glScaled(0.7,0.4,0);

    glColor3f(1,0,0);

    glPushMatrix(); //Dolna left bar
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(0.4,10.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //dolna right bar
    glTranslated(10,0,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(0.4,10.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //dolna up bar
    glTranslated(0,9,1);
    glRotatef(-90,0,0,1);

    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.4);
    glVertex2d(0.4,10.4);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    //glPushMatrix();
    /*
                if(dolnay=1){
                    glScalef(0.5,1,0);
                }

                else if(dolnay=0){
                    glScaled(1,1,1);
                }
                else if(dolnay=-1){
                    glScaled(1.5,1,0);
                }
                */

    glPushMatrix();  //dolna left line
    glTranslated(2.9,3,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,dolnay);
    glVertex2d(0.0,6.0);
    glVertex2d(0.1,6.0);
    glVertex2d(0.1,dolnay);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //dolna right side
    glTranslated(7.7,3,1);
    glBegin(GL_QUADS);
    glVertex2d(0,dolnay);
    glVertex2d(0,6.0);
    glVertex2d(0.1,6.0);
    glVertex2d(0.1,dolnay);
    glEnd();
    glPopMatrix();



    glPushMatrix(); //dolna sitting table

    glTranslated(1.8,3,1);
    // glRotated(45,0,1,0);
    glBegin(GL_QUADS);
    glVertex2d(1.0,dolnay+1);
    glVertex2d(6.0,dolnay+1);
    glVertex2d(7.0,dolnay);
    glVertex2d(0.0,dolnay);


    glEnd();
    glPopMatrix();

    glPushMatrix();  //dolna under extra line
    //glRotatef(-90,0,0,1);
    glTranslated(1.8,2.7,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,dolnay);
    glVertex2d(7,dolnay);
    glVertex2d(7,dolnay+0.1);
    glVertex2d(0,dolnay+0.1);
    glEnd();
    glPopMatrix();

    //glPopMatrix();





    glPopMatrix();
    babySwing();



}

void wheerligig()
{
    glPushMatrix();
    //glTranslated(-70,20,0);
    //glScaled(2,2,0);

    glPushMatrix();  //stand
    glTranslated(13,-5,1);
    glScaled(0.4,0.25,0);
    glColor3f(0.184,0.31,0.31);
    glBegin(GL_QUADS);
    glVertex2d(0,-10);
    glVertex2d(1,-10);
    glVertex2d(1,30);
    glVertex2d(0,30);
    glEnd();
    /*
    glPushMatrix();
        glTranslated(0.5,30,0);
        glColor3f(0.545,0,0);
        circle(1,1);
    glPopMatrix();*/

    glPopMatrix();

    /*glPushMatrix();
        glTranslated(13,-5,1);
        glColor3f(0.184,0.31,0.31);
        circle(1,1);
    glPopMatrix();*/

    glPushMatrix();
    glTranslated(13.25,2.5,1);
    glScaled(0.35,0.2,0);
    glRotated(angle,0,0,1);
    glPushMatrix();
    glTranslatef(10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    //glScaled(1.5,1.5,0);
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();



    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();


    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(55.5,-20,0);
    //glRotated(45,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);

    glVertex2d(0,0);
    glVertex2d(10,13);
    // glVertex2d(xx.yy);
    glVertex2d(0,0);
    glVertex2d(10,-13);
    glVertex2d(0,0);       //4 cross lines
    glVertex2d(-10,-13);
    glVertex2d(0,0);
    glVertex2d(-10,13);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,0);
    glColor3f(0.545,0,0);
    circle(1,1);
    glPopMatrix();


    glPopMatrix();
    glPopMatrix();
    //printf("angle:%f\n",angle);
    // glPopMatrix();

}

void bench()
{
    glPushMatrix();
    glTranslated(-8,-3,1);
    glColor3f(0,0,1);
    //glRotated(25,0,1,1);
    glScaled(0.8,0.6,1);
    glPushMatrix(); //Brench
    glTranslated(1.8,3,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(1.0,1.0);
    glVertex2d(6.0,1.0);
    glVertex2d(7.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,0,1);
    glTranslated(-2.8,1.8,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,7.0);
    glVertex2d(0.1,7.0);
    glVertex2d(0.1,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,1.7,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,1.0);
    glVertex2d(0.4,1.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(7,1.7,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,1.0);
    glVertex2d(0.4,1.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    if(isbaby==3)
    {
        // babySwing();
        glTranslated(-4,0.5,0);
        glScaled(0.05,0.06,0);


    }
    glPopMatrix();
}


void baby()
{
    glPushMatrix();
    if(isbaby==0)
    {
        // printf("%f\n",by);
        glTranslated(0+bx,0+by,0);
        glScalef(0.05,0.07,0);
    }

    else if(isbaby==5)
    {
        glTranslated(-0.5,2,0);
        //glTranslated(0+bx,0+by,0);
        glScaled(0.07,0.2,0);
    }
    else if(isbaby==6)
    {
        glTranslated(0+bx,0+by,0);
        //printf("HI");
        glScalef(0.04,0.06,0);
    }

    else if(isbaby==8)
    {

        glTranslated(0+shipx,3,0);
        glTranslated(0,0,0);
        //printf("HI");
        glScalef(0.04,0.04,0);
    }

    //glRotated(20,1,1,0);


    glPopMatrix();


    glPopMatrix();
}


void babySlide()
{


    glPushMatrix();

    if(isbaby==7 && step==4)
    {
        /*
        if(frnt==0){
        glTranslatef(20,24+dolnay,0);
        }
        else if(frnt==1 && dolnaMove==1){
        glTranslatef(20,26.5+dolnay,0);
        }
        else if(frnt==-1 && dolnaMove==-1){
        glTranslatef(20,23+dolnay,0);
        }*/

        glTranslatef(3.5+stepx,-1.7+stepy,0);
        glScaled(0.04,0.06,0);
        //glRotated(20,1,1,0);



        glPopMatrix();
    }
    glPopMatrix();


}

void slide()
{

    glPushMatrix();
    //glRotatef(90,1,0,0);
    glTranslatef(2,-3,0);
    //glScalef(0.8,1,0);
    glPushMatrix();
    glTranslatef(-3,-3,0);
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(2.8,-0.1);
    glVertex2d(-0.1,-0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,-2,0);
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(2.8,-0.1);
    glVertex2d(-0.1,-0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,-1,0);
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(2.8,-0.1);
    glVertex2d(-0.1,-0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.54,0.396,0.031);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(0.3,0);
    glVertex2d(-3.7,-4);
    glVertex2d(-4,-4);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.54,0.396,0.031);
    glBegin(GL_QUADS);
    glVertex2d(3,0);
    glVertex2d(2.7,0);
    glVertex2d(-1.3,-4);
    glVertex2d(-1,-4);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(6,-5);
    glVertex2d(3,-5);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    babySlide();

}

void glidder()
{
    glPushMatrix();
    //glRotatef(-15,1,0,0);
    glTranslated(-18.5,-6,0);
    glColor3f(0,0,0.54);
    glScalef(0.8,0.5,0);
    //glPushMatrix(); // glidder body
    //glRotatef(-glAngle,0,0,1);
    if(glUp==0)
    {
        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(13,3.0);
        glVertex2f(13,3.3);
        glVertex2f(0,0.3);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(3.0,0.9);
        glVertex2d(3.0,1.5);
        glVertex2d(3.3,1.5);
        glVertex2d(3.3,0.9);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(10.0,2.4);
        glVertex2d(10.0,3.0);
        glVertex2d(9.7,3.0);
        glVertex2d(9.7,2.4);
        glEnd();
        glPopMatrix();
        glPushMatrix();  //glidder bottom
        glTranslated(6.2,1.0,1);
        //glRotatef(glAngle,0,0,1);
        glBegin(GL_QUADS);
        glVertex2d(0.0,0.5);
        glVertex2d(0.0,-2.0);
        glVertex2d(0.5,-2.0);
        glVertex2d(0.5,0.6);
        glEnd();
        glPopMatrix();
    }

    else if(glUp==1)
    {
        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2f(0,3.0);
        glVertex2f(0,3.3);
        glVertex2f(13,0.3);
        glVertex2f(13,0);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(3.0,2.4);
        glVertex2d(3.0,3.0);
        glVertex2d(3.3,3.0);
        glVertex2d(3.3,2.4);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(10.0,0.9);
        glVertex2d(10.0,1.5);
        glVertex2d(9.7,1.5);
        glVertex2d(9.7,0.9);
        glEnd();
        glPopMatrix();
        glPushMatrix();  //glidder bottom
        glTranslated(6.2,1.0,1);
        //glRotatef(glAngle,0,0,1);
        glBegin(GL_QUADS);
        glVertex2d(0.0,0.6);
        glVertex2d(0.0,-2.0);
        glVertex2d(0.5,-2.0);
        glVertex2d(0.5,0.5);
        glEnd();
        glPopMatrix();

    }




    glPopMatrix();





    glPushMatrix();
    if(isbaby==2)
    {
        if(glUp==0)
        {
            glRotatef(20,1,1,1);
            glTranslated(-17.8,-0.6,0);
        }
        else if(glUp==1)
        {
            glRotatef(-20,1,1,1);
            glTranslated(-15.8,-6.6,0);

        }

        glScaled(0.05,0.05,0);


        //glScalef(0.5,0.5,0);
        //glRotated(20,1,1,0);


        glPopMatrix();
    }

    glPopMatrix();

    glPushMatrix();



    if(glUp==0)
    {
        glRotatef(20,1,1,1);
        glTranslated(-10.6,-1.2,0);
    }
    else if(glUp==1)
    {
        //printf("Hi|");
        glRotatef(-20,1,1,1);
        glTranslated(-8.5,-6.2,0);
    }

    glPopMatrix();

    glPopMatrix();

    //glPopMatrix();
    glPopMatrix();
}
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);


    sky();
    hillSide();


    field();
    river();

    sun();
    cloudLeft();
    cloudRightUp();
    cloudRight();
    cloudMiddle();
    hillTree();

    glidder();
    if(isbaby!=8)
    {
        ship();
        wheerligig();
        swing();

    }
    bench();
    if(isbaby==0||isbaby==6||isbaby==8)
    {
        baby();
    }
    slide();


    if(isbaby==8)
    {
        ship();
        wheerligig();
        swing();

    }

    glFlush();
}

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(-20.0, 20.0, -10.0, 10.0, -15.0, 15.0);
}


void spe_key(int key, int x, int y)
{

    //printf("BX:%f---BY:%f\n",bx,by);
    switch (key)
    {

    case GLUT_KEY_LEFT:


        bx=bx-0.5;
        glutPostRedisplay();

        //glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:


        bx=bx+0.5;
        glutPostRedisplay();
        //glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:

        by=by-0.5;
        glutPostRedisplay();
        //glutPostRedisplay();
        break;

    case GLUT_KEY_UP:

        by=by+0.5;
        glutPostRedisplay();
        //glutPostRedisplay();
        break;
    default:
        break;
    }

}

void windMove()
{
    /*wx=wx-0.1;
    if(wx<-360){
        wx=0;
    }
    glutPostRedisplay();*/

    if(angle<-726.5)
    {
        isbaby=0;
        angle=0;
        bx=7;
        by=0;
        glutIdleFunc(NULL);
    }
    else
    {
        angle=angle-0.2;
    }
    glutPostRedisplay();

}

void dolnaMove()
{
    if(dolnay>=0.1)
    {
        dolnay+=0.001;
    }
    else if(dolnay<=-0.1)
    {
        dolnay-=0.001;
    }

    glutPostRedisplay();

}

void slideMove()
{
    stepx+=0.007;
    stepy-=0.01;
    glutPostRedisplay();
    if(stepy<-4.5)
    {
        isbaby=0;
        step=0;
        stepx=0;
        stepy=0;
        bx=-1;
        by=-4;
        glutIdleFunc(NULL);
        glutPostRedisplay();
    }
}


void normal_key(unsigned char key, int x, int y)
{
    switch (key)
    {


    case 'u':
        isbaby=1;
        dolnay=0.1;
        glutIdleFunc(dolnaMove);
        glutPostRedisplay();
        //spinDisplay_left();
        break;
    case 'd':
        isbaby=0;
        bx=-15;
        by=-0.5;
        glutIdleFunc(NULL);
        glutPostRedisplay();
        break;

    case 'h':
        glUp=1;
        glutPostRedisplay();
        break;

    case 'l':
        glUp=0;
        glutPostRedisplay();
        break;

    case 'r':
        isbaby=3;
        //glUp=0;
        glutPostRedisplay();
        break;

    case 's':
        isbaby=0;
        bx=-4;
        by=-1;
        glutPostRedisplay();
        break;

    case 'w':
        // wx=wx-10;
        // glutPostRedisplay();
        //windRun=1;
        isbaby=5;
        glutIdleFunc(windMove);
        break;


    case 'o':
        //isbaby=0;
        //bx=-15;
        //by=-0.5;
        //glutIdleFunc(NULL);
        isbaby=6;
        step++;
        if(step==1)
        {
            bx=0.5;
            by=-3.5;
        }
        else if(step==2)
        {
            bx=1.5;
            by=-2.5;
        }
        else if(step==3)
        {
            bx=2.5;
            by=-1.5;
        }

        else if(step==4)
        {
            //bx=2.5;
            //by=-1.5;
            isbaby=7;
            glutIdleFunc(slideMove);
        }
        glutPostRedisplay();
        break;


    case 'b':
        isbaby=8;
        glutPostRedisplay();
        break;

    default:
        break;
    }

}



int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT before any other function

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1600, 1000);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Translating Circle");

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(normal_key);
    PlaySound("2ndChoice.wav", NULL, SND_FILENAME| SND_ASYNC);
    glutMainLoop();
    return 0;
}
