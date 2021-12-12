#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>

#include<math.h>

static float	tp3	=  0;
static float	cm=  -300.0;


GLfloat	tx	=  5;
GLfloat	ty	=  5;



void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0;i<=360; i++){
    rad = i*(3.1416/180);
    glVertex2f(x+rx*cos(rad),y+ry*sin(rad));

    }
    glEnd();


}

void sun()
{
    glPushMatrix();
    glTranslated(270,260,0);
    glColor3f(1.0, 0.76, 0.3);
    circle(20,30,0,0);
    glPopMatrix();
}


void make_cloud(int x, int y)
{

    glColor3f(1.0, 1.0, 1.0);
    circle(15,15,x,y);
    circle(15,15,x+10,y);
    circle(15,15,x+30,y);
    circle(15,15,x+5,y-10);
    circle(15,15,x+20,y-10);
    circle(15,15,x+5,y+10);
    circle(15,15,x+25,y+10);

}

void cloud_move_right(GLfloat t){
    tp3=tp3+t;
    if(tp3>600)
        tp3 = -300;
    glutPostRedisplay();
}


void cloud()
{
    glPushMatrix();
    glTranslatef(tp3,0,0);
    make_cloud(-300,280);
    make_cloud(-500,280);
    make_cloud(-200,250);
    make_cloud(-400,250);
    make_cloud(200,250);
    make_cloud(-100,250);
    make_cloud(-350,230);
    glPopMatrix();
    cloud_move_right(.1);

    glEnd();
}




void rectangle(int x, int y, int x1, int y1)
{
    glBegin(GL_QUADS);
        glVertex2d(x,y);
        glVertex2d(x,y1);
        glVertex2d(x1,y1);
        glVertex2d(x1,y);


    glEnd();
}

void triangle(int x, int y, int x1, int x2,int y1)
{
    glBegin(GL_POLYGON);
        glVertex2d(x,y);
        glVertex2d(x1,y);

        glVertex2d(x1,y);
        glVertex2d(x2,y1);

        glVertex2d(x2,y1);
        glVertex2d(x,y);
        glEnd();
}
void rectangle1(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_QUADS);
        glVertex2d(x1,y1);
        glVertex2d(x3,y3);
        glVertex2d(x4,y4);
        glVertex2d(x2,y2);
        glEnd();
}

void ground()
{
     glColor3f(1.3, 1.0, 0.53);
     rectangle(-300,-300,300,-10);

}
void road()
{

        glColor3f(0.3, 0.3, 0.3);
        rectangle(-300,-200,300,-30);

        glColor3f(0.0, 0.0, 0.0);
        rectangle(-300,-30,300,-33);

        glColor3f(0.0, 0.0, 0.0);
        rectangle(-300,-205,300,-200);

        glColor3f(1.0, 1.0, 1.0);
        rectangle(-270,-120,-230,-110);

        glColor3f(1.0, 1.0, 1.0);
        rectangle(-270,-120,-200,-110);

        glColor3f(1.0, 1.0, 1.0);
        rectangle(-150,-120,0,-110);

        glColor3f(1.0, 1.0, 1.0);
        rectangle(50,-120,150,-110);
        glColor3f(1.0, 1.0, 1.0);
        rectangle(200,-120,290,-110);

}
void building3()
{
    glColor3f(1.0, 1.0, 1.0);



     rectangle(-290,160,-130,-10);
     glColor3f(0.0, 0.0, 0.0);
     rectangle(-130,160,-120,-10);

     glColor3f(0.0, 0.0, 0.0);

     rectangle(-200,50,-220,-10);

     rectangle(-280,20,-250,-2);

        rectangle(-280,30,-250,50);

        rectangle(-280,60,-250,80);

        rectangle(-280,90,-250,110);

        rectangle(-280,120,-250,140);



        rectangle(-225,120,-245,140);

        rectangle(-225,90,-245,110);

        rectangle(-225,60,-245,80);
        rectangle(-225,30,-245,50);
        rectangle(-225,20,-245,-2);


        rectangle(-200,60,-220,80);
        rectangle(-200,90,-220,110);
        rectangle(-200,120,-220,140);


        rectangle(-175,120,-195,140);
        rectangle(-175,90,-195,110);
        rectangle(-175,60,-195,80);
        rectangle(-175,30,-195,50);
        rectangle(-175,20,-195,-2);


         rectangle(-140,20,-170,-2);
         rectangle(-140,30,-170,50);
         rectangle(-140,60,-170,80);
         rectangle(-140,90,-170,110);
         rectangle(-140,120,-170,140);



}

void car(){
    glColor3f(1.0, 1.1, 0.0);
    circle(5,15,0,0);
    rectangle(0,-15,60,15);

    glColor3f(0.2, 0.47, 1.0);
    triangle(5,15,20,20,45);
    triangle(40,15,60,40,45);

    glColor3f(0, 0, 0);
    rectangle(20,15,40,45);

    glColor3f(1.0, 1.1, 0.0);
    circle(5,10,80,-5);

    glColor3f(1.0, 1.1, 0.0);
    rectangle1(60,-15,80,-15,60,15,80,5);



    glColor3f(0.0, 0.0, 0.0);
    circle(6,12,10,-15);
    circle(6,12,60,-15);

}
void carMove(){
cm=cm+.4;
    if(cm>330)
        cm =-350;
        glutPostRedisplay();
}

void privatecar()
{
    carMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(cm,-50,0);
     car();
     glPopMatrix();

    }
}


void building()
{
    glColor3f(85.0, 87.0, 115.3);
    rectangle(-100,-9,60,220);
    glColor3f(0.0, 0.0, 0.7);

    glColor3f(0.4, 1.0, 1.0);
    rectangle1(60,-9,70,0,60,220,70,220);

        glColor3f(0, 0, 0);
        rectangle(-35,-9,-5,30);

rectangle(-90,100,-70,80);
rectangle(-90,140,-70,120);
rectangle(-90,180,-70,160);
rectangle(-90,210,-70,190);

        rectangle(-60,100,-40,80);
        rectangle(-60,140,-40,115);
        rectangle(-60,155,-40,175);
        rectangle(-60,210,-40,190);


         rectangle(-30,100,-10,80);
         rectangle(-30,140,-10,120);
         rectangle(-30,175,-10,155);
         rectangle(-30,210,-10,190);

rectangle(0,100,20,80);\
rectangle(0,140,20,120);\
rectangle(0,174,20,155);\
rectangle(0,210,20,190);\




        rectangle(30,100,50,80);

    rectangle(30,140,50,120);
    rectangle(30,175,50,157);
    rectangle(30,210,50,190);


        rectangle(-90,70,-70,50);
        rectangle(-60,70,-40,50);
        rectangle(-30,70,-10,50);
        rectangle(0,70,20,50);
        rectangle(30,70,50,50);


}

void building2()
{



    glColor3f(0.75, 0.5, 0.25);

    rectangle(80,250,190,-10);

    glColor3f(0.0, 0.0, 0.0);

    rectangle(100,40,82,10);
    rectangle(100,70,82,50);
    rectangle(100,80,82,100);
    rectangle(100,110,82,130);
    rectangle(100,145,82,170);
    rectangle(100,180,82,200);
    rectangle(100,210,82,230);

glColor3f(0.0, 0.0, 0.0);
    rectangle(105,210,130,230);
    rectangle(105,180,130,200);
    rectangle(105,145,130,170);
    rectangle(105,110,130,130);
    rectangle(105,80,130,100);
    rectangle(105,70,130,50);
    rectangle(105,40,130,10);


    rectangle(140,40,165,10);
    rectangle(140,70,165,50);
   rectangle(140,80,165,100);
    rectangle(140,110,165,130);
    rectangle(140,145,165,170);
    rectangle(140,180,165,200);
    rectangle(140,210,165,230);

    rectangle(170,40,188,10);
    rectangle(170,40,188,10);
    rectangle(170,70,188,50);
    rectangle(170,80,188,100);
    rectangle(170,110,188,130);
    rectangle(170,145,188,170);
    rectangle(170,180,188,200);
    rectangle(170,210,188,230);

}

void house()
{
    glColor3f(0.1f, 0.1f, 1.0f);
    rectangle1(200,-9,350,-9,200,80,350,80);
    rectangle1(200,80,250,80,200,120,250,120);
    glColor3f(0.0f, 0.1f, 0.0f);
    triangle(195,120,255,225,150);

    glColor3f(0.4, 1.0, 1.0);
    rectangle1(215,95,235,95,215,115,235,115);

    glColor3f(0.95, 0.95, 0.95);
    rectangle1(220,-9,250,-9,220,40,250,40);


}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    sun();
    cloud();
    ground();
    road();
    building3();
    privatecar();
    building();
    building2();
    house();
    glFlush();
}


void init()
{
    glClearColor(0.3, .65, 1, 1.0);
	glOrtho(-300,300,-300,300,-150,500);
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Computer Grapics Project");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
