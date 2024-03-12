#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>      // handle the window-managing operations
#else
#include <GL/glew.h>
#include <GL/freeglut.h>    // handle the window-managing operations
#endif
#define GL_SILENCE_DEPRECATION
#include <iostream>


GLint win_width = 700,
      win_hight = 700;
GLdouble PI = 3.14159265359;

using namespace std;

//transvalue variable
float TransValue;
float transValue;
float transValue1;
float transValue2;
float transleet;
int page; //frame counter
GLuint myTexture1;

// Object position
float objectX = 0.0f;

// Distance traveled
float distanceTraveled = 0.0f;
// Translation value
float translateX = 0.01f;
 // in degrees per frame
float timerr;
float xpos = -0.0;//initail x position
int state = 1; // to move lrft or rigt
//-------------------------------------------

char image1Path[] = "/Users/macbookpro/Desktop/CG-project/lighthouse1.bmp";

//-----------------------------

// draw a Horizontal filled semicircle
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 1.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                   x + (radius * cos(i *  twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount))
                   ); }
    glEnd();
    
}

//draw a filled vertical circle
void drawFilledCircle1(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                   x + (radius * cos(i *  twicePi / triangleAmount)),
                   y + (0.04 * sin(i * twicePi / triangleAmount))
                   ); }
    glEnd();
    
}

//Basic Circle
void drawFilledCircle2(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

//Large circle for ocean on the scene 4
void drawFilledCircle3(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 100; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

//------------------------------------


//reference
//https://youtu.be/CR5SW3gmxPE?feature=shared
void timer1(int)  //translate squid arms
{
    glutPostRedisplay();
    glutTimerFunc(500, timer1, 0);//update the display frame

    switch (state)
    {
    case 1://to go right
        if (xpos <= 0.03) {
            xpos += 0.05;
        }
        else {
            state = -1;
        }
        break;
    case -1://to go left
        if (xpos >= -0.03) {
            xpos -= 0.05;
        }
        else {
            state = 1;
        }
        break;
    }
}


static void play(void)
{
    glutPostRedisplay();
}


void click(){ //In the box for a message, press t to move
    
    glColor3f(0.3, 0.1, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(1.0, -0.7);
    glColor3f(0.5, 0.1, 0.0);
    glVertex2f(1.0, -1.0);
    glColor3f(0.3, 0.1, 0.0);
    glVertex2f(0.37, -1.0);
    glColor3f(0.5, 0.1, 0.0);
    glVertex2f(0.37, -0.7);
    glEnd();
    
    
    //Possibility of writing text on the rectangle from stack overflow
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(0.39, -0.87);
        const char* text4 = "Click 't' to start story";
        while (*text4) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text4); // Use the desired font size
            text4++;
        }
}

//--------------------------------------
void ocean(){
    glColor3f(0, 0.0, 0.6);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(-1.0, 0.15);
    
    glColor3f(0, 0.0, 0.3);
    glVertex2f(1.0 , 0.15);
    
    glColor3f(0, 0.0, 0.2);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0 , -1.0);

    glEnd();

}

void oceanLines(){
    //--------------------------------
    // sea lines
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.95, 0.05);
    glVertex2f(-0.70,0.05);
    glEnd();
    
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.40, 0.0);
    glVertex2f(0.0,0.0);
    glEnd();
    
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(0.10, -0.70);
    glVertex2f(0.40, -0.70);
    glEnd();
    
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.30, -0.50);
    glVertex2f( 0.10, -0.50);
    glEnd();
    
    
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(0.40, -0.20);
    glVertex2f(0.80, -0.20);
    glEnd();
    
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.80, -0.80);
    glVertex2f(-0.60, -0.80);
    glEnd();
    
    
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.30,-0.30);
    glVertex2f( 0.20,-0.30);
    glEnd();
    
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f( 0.70, 0.10);
    glVertex2f( 0.95, 0.10);
    glEnd();
    
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f( 0.70, -0.55);
    glVertex2f( 0.95, -0.55);
    glEnd();
    
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f( -0.50, -0.40);
    glVertex2f( -0.95, -0.40);
    glEnd();
    
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f( -0.60, -0.15);
    glVertex2f( -0.80, -0.15);
    glEnd();
    
    
    glColor3f(0.0,0.0,0.6);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f( -0.60, 0.05);
    glVertex2f( -0.10, 0.05);
    glEnd();
    
}

//-----------------------------------------
void boat(){
// boat structure
    glColor3f(0.4, 0.2, 0.0);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(-0.85, -0.15);
    glVertex2f(-0.50, -0.15);
    glVertex2f(-0.82, -0.25);
    glVertex2f(-0.53, -0.25);
    
    glEnd();

    //----------------------------
    //blocks 1
    glColor3f(0.3,0.1,0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.85, -0.15);
    glVertex2f(-0.79, -0.15);
    glVertex2f(-0.79, -0.18);
    glVertex2f(-0.84, -0.18);
    glEnd();

    //blocks 2
    glColor3f(0.3,0.1,0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.79, -0.15);
    glVertex2f(-0.79, -0.18);
    glVertex2f(-0.68, -0.18);
    glVertex2f(-0.68, -0.15);
    glEnd();

    //blocks 3
    glColor3f(0.3,0.1,0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.68, -0.15);
    glVertex2f(-0.68, -0.18);
    glVertex2f(-0.59, -0.18);
    glVertex2f(-0.59, -0.15);
    glEnd();

    //blocks 4
    glColor3f(0.3,0.1,0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.59, -0.15);
    glVertex2f(-0.59, -0.18);
    glVertex2f(-0.51, -0.18);
    glVertex2f(-0.50, -0.15);
    glEnd();

    //blocks 5
    glColor3f(0.3,0.1,0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.84, -0.18);
    glVertex2f(-0.70, -0.18);
    glVertex2f(-0.70, -0.21);
    glVertex2f(-0.83, -0.21);
    glEnd();

    //blocks 6
    glColor3f(0.3,0.1,0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.70, -0.18);
    glVertex2f(-0.70, -0.21);
    glVertex2f(-0.58, -0.21);
    glVertex2f(-0.58, -0.18);
    glEnd();

    //blocks 7
    glColor3f(0.3,0.1,0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.58, -0.18);
    glVertex2f(-0.58, -0.21);
    glVertex2f(-0.52, -0.21);
    glVertex2f(-0.51, -0.18);
    glEnd();

    //blocks 8
    glColor3f(0.3,0.1,0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.83, -0.21);
    glVertex2f(-0.75, -0.21);
    glVertex2f(-0.75, -0.25);
    glVertex2f(-0.82, -0.25);
    glEnd();

    //blocks 9
    glColor3f(0.3,0.1,0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.75, -0.21);
    glVertex2f(-0.60, -0.21);
    glVertex2f(-0.60, -0.25);
    glVertex2f(-0.75, -0.25);
    glEnd();

    //blocks 10
    glColor3f(0.3,0.1,0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.75, -0.21);
    glVertex2f(-0.52, -0.21);
    glVertex2f(-0.53, -0.25);
    glVertex2f(-0.75, -0.25);
    glEnd();

    //----------------------------
    
   //Boat sail on the right of the screen
    glColor3f(1.0, 1.0, 0.7);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.65, 0.15);
    glVertex2f(-0.90, -0.05);
    glVertex2f(-0.65, -0.05);
    glEnd();

    //Boat sail on the left of the screen
    glColor3f(1.0, 1.0, 0.7);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.65, 0.15);
    glVertex2f(-0.47, -0.05);
    glVertex2f(-0.65, -0.05);
    glEnd();
    
    //Boat sail pole
    glColor3f(0.7, 0.5, 0.3);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-0.65, -0.15);
    glVertex2f(-0.65, 0.15);
    glEnd();
    
}

//---------------------------------------------
void island(){
    //draw a dark rock
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.72, -0.32);
    glVertex2f(0.71, -0.24);
    glVertex2f(0.69, -0.22);
    glVertex2f(0.65, -0.14);
    glVertex2f(0.54, -0.13);
    glVertex2f(0.47, -0.15);
    glVertex2f(0.45, -0.22);
    glVertex2f(0.37, -0.32);
    glVertex2f(0.37, -0.30);
    glVertex2f(0.31, -0.32);
    glVertex2f(0.31, -0.30);
    glVertex2f(0.40, -0.20);
    glVertex2f(0.45, -0.10);
    glEnd();
    
    //Lighting the rock
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.47, -0.32);
    glVertex2f(0.69, -0.32);
    glVertex2f(0.46, -0.24);
    glVertex2f(0.51, -0.17);
    glVertex2f(0.61, -0.20);
    glVertex2f(0.64, -0.22);
    glVertex2f(0.66, -0.30);
    glEnd();
    
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.34, -0.32);
    glVertex2f(0.34, -0.32);
    glVertex2f(0.32, -0.29);
    glVertex2f(0.39, -0.27);
    glVertex2f(0.42, -0.27);
    glVertex2f(0.44, -0.29);
    glVertex2f(0.44, -0.32);
    glEnd();
    
}

//-------------------------------------------
void Lighthouse(){
    
    //the block below lighthouse structure
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.63, -0.14);
    glVertex2f(0.62,-0.12);
    glVertex2f(0.49, -0.14);
    glVertex2f(0.48, -0.12);
    glEnd();
    
    // structure lighthouse
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(0.61, -0.12);
    glVertex2f(0.50, -0.12);
    glVertex2f(0.53, 0.30);
    glVertex2f(0.59, 0.30);
    glEnd();
     
    //---------------------------------------
    
    // 3 window of lighthouse
    
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.53, 0.05);
    glVertex2f(0.56, 0.05);
    glVertex2f(0.53, 0.07);
    glVertex2f(0.56, 0.07);
    glEnd();
    
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.53, 0.10);
    glVertex2f(0.56, 0.10);
    glVertex2f(0.53, 0.12);
    glVertex2f(0.56, 0.12);
    glEnd();
    
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.53, 0.15);
    glVertex2f(0.56, 0.15);
    glVertex2f(0.53, 0.17);
    glVertex2f(0.56, 0.17);
    glEnd();
    
    //---------------------------------------
    
    // The shadow of the upper part of the lighthouse
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0.53, 0.30);
    glVertex2f(0.59, 0.30);
    glVertex2f(0.61, 0.32);
    glVertex2f(0.51, 0.32);
    glEnd();
    
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.51, 0.32);
    glVertex2f(0.61, 0.32);
    glVertex2f(0.51, 0.37);
    glVertex2f(0.61, 0.37);
    glEnd();

    glColor3f(1.0, 1.0, 0.8);
    drawFilledCircle1(0.56,0.44,.02);

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.52, 0.37);
    glVertex2f(0.60, 0.37);
    glVertex2f(0.52, 0.42);
    glVertex2f(0.60, 0.42);
    glEnd();

    //---------------------------------------
    //upper body

    glColor3f(0.2, 0.2, 0.2);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0.59, 0.42);
    glVertex2f(0.59, 0.52);
    glEnd();
    
    glColor3f(0.2, 0.2, 0.2);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0.56, 0.42);
    glVertex2f(0.56, 0.52);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0.53, 0.42);
    glVertex2f(0.53, 0.52);
    glEnd();

    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.59, 0.52);
    glVertex2f(0.53, 0.52);
    glVertex2f(0.61, 0.54);
    glVertex2f(0.51, 0.54);
    glEnd();

    glColor3f(0.6, 0.0, 0.0);
    drawFilledCircle(0.56,0.54,.06);

    glColor3f(0.6, 0.0, 0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(0.56, 0.59);
    glVertex2f(0.56, 0.63);
    glEnd();

    //---------------------------------------

}

void light(){
    // The lighthouse light on the right of the screen
    glColor4f(1.0, 1.0, 0.8,0.8);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.56, 0.45);
    glColor4f(0.9, 0.9, 0.2,0.1);
    glVertex2f(-0.40, 0.2);
    glColor4f(0.9, 0.9, 0.2,0.1);
    glVertex2f(-0.20, -0.15);
    glEnd();
    
}

void light1(){
    // Lighthouse light in the middle of the screen
    glColor4f(1.0, 1.0, 0.8,0.8);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.56, 0.45);
    glColor4f(0.9, 0.9, 0.2,0.1);
    glVertex2f(0.74, -0.22);
    glColor4f(0.9, 0.9, 0.2,0.1);
    glVertex2f(0.27, -0.22);
    glEnd();
    
}



//-----------------------------------------

void ground() {
   
    // the ground
    glBegin(GL_POLYGON);
    glColor3f(0.28f, 0.18f, 0.18f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(0.4f, -0.6f);
    glVertex2f(.05f, -0.65f);
    glVertex2f(-.1f, -0.7f);
    glVertex2f(-.2f, -0.7f);
    glVertex2f(-.4f, -0.65f);
    glVertex2f(-.6f, -0.55f);
    glVertex2f(-.7f, -0.5f);
    glVertex2f(-.9f, -0.5f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();
    
    //the rock
        glBegin(GL_POLYGON);
        glColor3f(0.3f, 0.3f, 0.4f);
        glVertex2f(0.9f, -0.4f);
        glVertex2f(0.7f, -0.4f);
        glVertex2f(0.6f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.4f, -0.6f);
        glVertex2f(0.4f, -0.7f);
        glVertex2f(0.5f, -0.73f);
        glVertex2f(0.6f, -0.75f);
        glVertex2f(0.6f, -0.78f);
        glVertex2f(0.8f, -0.8f);
        glVertex2f(0.9f, -0.8f);
        glVertex2f(1.0f, -0.6f);
        glEnd();

}

void background() {

    glBegin(GL_QUADS);// the background of frame
    glColor3f(0.2, 0.0f, 0.4f);
    glVertex2f(-1.0f, -1.0f);

    glColor3f(0.0, 0.0f, 0.0f);
    glVertex2f(-1.0f, 1.0f);

    glColor3f(0.0, 0.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);

    glColor3f(0.2, 0.0f, 0.4f);
    glVertex2f(1.0f, -1.0f);

    glEnd();
 }

//these codes are for createing clouds_________________________________
void cloud() {

    // the clouds
    glColor3f(0.3f, 0.3f, 0.5f);
    drawFilledCircle2(-0.75, 0.7, 0.15);
    drawFilledCircle2(-0.63, 0.73, 0.15);
    drawFilledCircle2(-0.6, 0.65, 0.15);
    drawFilledCircle2(-0.5, 0.7, 0.15);
    drawFilledCircle2(-0.4, 0.65, 0.15);

   

}

//these aer the codes to create the spaceship __________________________
void Boom()
{
    glBegin(GL_QUADS);  // Head of the spaceship
    glColor3f(0.2f, 0.2f, 0.1f);
    glVertex2f(-0.1f, 0.7f);
    glVertex2f(-0.1f, 0.6f);
    glVertex2f(0.1f, 0.7f);
    glVertex2f(0.1f, 0.6f);
    glEnd();

    glBegin(GL_TRIANGLES); // Antennae

    glColor3f(0.3f, 0.4f, 0.3f);
    glVertex2f(-0.5f, 0.3f);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.5f, 0.3f);
    glEnd();

 
    glColor3f(0.3f, 0.4f, 0.3f);// Bottom circle
    drawFilledCircle2(0.0, 0.4, 0.15);

    glColor3f(0.3f, 0.4f, 0.3f);// the upper circle
    drawFilledCircle2(0.0, 0.5, 0.2);

    glColor4f(1.0f, 1.0f, 1.0f,0.5); //circle transparency
    drawFilledCircle2(0.0, 0.5, 0.18);

    glBegin(GL_QUADS);  //let this be half a circle
    glColor3f(0.3f, 0.4f, 0.3f);
    glVertex2f(-0.2f,0.5f);
    glVertex2f(-0.2f,0.3f);
    glVertex2f(0.2f,0.3f);
    glVertex2f(0.2f,0.5f);
    glEnd();


     //vehicle lights
    glColor4f(1.0f, 1.0f, 1.0f, 0.8f);
    drawFilledCircle2(0.0, 0.35, 0.02);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle2(0.1, 0.35, 0.02);

    glColor4f(1.0f, 1.0f, 1.0f, 0.8f);
    drawFilledCircle2(0.2, 0.35, 0.02);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle2(0.3, 0.35, 0.02);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle2(-0.1, 0.35, 0.02);

    glColor4f(1.0f, 1.0f, 1.0f, 0.8f);
    drawFilledCircle2(-0.2, 0.35, 0.02);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle2(-0.3, 0.35, 0.02);

}



// This codes are for the beam ___________________________________
void Beam()
{
    glBegin(GL_TRIANGLES);
    glColor4f(1.f, 1.f, 0.0f,0.3);
    glVertex2f(-0.4f, -0.8f);
    glColor3f(1.f, 0.7f, 0.3f);
    glVertex2f(0.0f, 0.3f);
    glColor4f(1.f, 1.f, 0.0f, 0.3);
    glVertex2f(0.4f, -0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor4f(1.f, 0.7f, 0.3,0.2f);
    glVertex2f(-0.5f, -0.8f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.5f, -0.8f);
    glEnd();
    
   
}
//these codes to create the first man____________________________
void Man()
{
    glColor3f(1.0f, 0.8f, 0.6f); //the face
    drawFilledCircle2(0.0, -0.53, 0.06);

    glColor3f(0.0f, 0.0f, 0.0f); // the hat
    drawFilledCircle2(0.0, -0.46, 0.03);

    glColor3f(0.0f, 0.0f, 0.0f); //right eye
    drawFilledCircle2(-0.02, -0.53, 0.01);

    glColor3f(0.0f, 0.0f, 0.0f); //left eye
    drawFilledCircle2(0.02, -0.53, 0.01);

    glBegin(GL_LINES);// left eyebrow
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(-0.038, -0.52);
    glVertex2d(-0.01, -0.52);
    glEnd();

    glBegin(GL_LINES);// right eyebrow
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(0.038, -0.52);
    glVertex2d(0.01, -0.52);
    glEnd();

    glBegin(GL_QUADS);  // mustache
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.02f, -0.545);
    glVertex2f(-0.02f, -0.56f);
    glVertex2f(0.02f, -0.56f);
    glVertex2f(0.02f, -0.545);
    glEnd();



    glBegin(GL_QUADS);  //hat tip
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.05f, -0.47f);
    glVertex2f(-0.05f, -0.50f);
    glVertex2f(0.05f, -0.50f);
    glVertex2f(0.05f, -0.47f);
    glEnd();

    glBegin(GL_TRIANGLES); //hat tip
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.05f, -0.47f);
    glVertex2f(0.0f, -0.43f);
    glVertex2f(0.05f, -0.47f);
    glEnd();

    glBegin(GL_QUADS);  // the body
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.05f, -0.58f);
    glVertex2f(-0.05f, -0.80f);
    glVertex2f(0.05f, -0.80f);
    glVertex2f(0.05f, -0.58f);
    glEnd();

    glBegin(GL_QUADS);  //the arms
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.07f, -0.58f);
    glVertex2f(-0.07f, -0.65f);
    glVertex2f(0.07f, -0.65f);
    glVertex2f(0.07f, -0.58f);
    glEnd();

    glColor3f(1.0f, 0.8f, 0.6f); //left hand palm
    drawFilledCircle2(-0.068, -0.65, 0.01);

    glColor3f(1.0f, 0.8f, 0.6f); //right hand palm
    drawFilledCircle2(0.068, -0.65, 0.01);

    glBegin(GL_QUADS);  //  feet
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.06f, -0.78f);
    glVertex2f(-0.06f, -0.80f);
    glVertex2f(0.06f, -0.80f);
    glVertex2f(0.06f, -0.78f);
    glEnd();

    glBegin(GL_TRIANGLES);//white blouse
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.035f, -0.59f);
    glVertex2f(0.0f, -0.67f);
    glVertex2f(0.035f, -0.59f);
    glEnd();

    glBegin(GL_TRIANGLES);//his craft
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.020f, -0.59f);
    glVertex2f(0.0f, -0.62f);
    glVertex2f(0.020f, -0.59f);
    glEnd();


}

//these codes to create the second man____________________________

void man2() {

    glBegin(GL_QUADS);  // the face
    glColor3f(1.0f, 0.8f, 0.6f);
    glVertex2f(-0.05f, -0.50);
    glVertex2f(-0.05f, -0.60f);
    glVertex2f(0.05f, -0.60f);
    glVertex2f(0.05f, -0.50);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); //the hat
    drawFilledCircle2(0.0, -0.46, 0.03);

    glColor3f(0.0f, 0.0f, 0.0f); // right eye
    drawFilledCircle2(-0.02, -0.53, 0.01);

    glColor3f(0.0f, 0.0f, 0.0f); // left eye
    drawFilledCircle2(0.02, -0.53, 0.01);

    glBegin(GL_LINES);// left eyebrow
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(-0.038, -0.52);
    glVertex2d(-0.01, -0.52);
    glEnd();

    glBegin(GL_LINES);// right eyebrow
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(0.038, -0.52);
    glVertex2d(0.01, -0.52);
    glEnd();

    glBegin(GL_TRIANGLES);// left mustache
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.02f, -0.57f);
    glVertex2f(0.0f, -0.54f);
    glVertex2f(0.0f, -0.56f);
    glEnd();

    glBegin(GL_TRIANGLES);// Right mustache
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.02f, -0.57f);
    glVertex2f(0.0f, -0.54f);
    glVertex2f(0.0f, -0.56f);
    glEnd();

    glBegin(GL_QUADS);  // hat tip
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.05f, -0.47f);
    glVertex2f(-0.05f, -0.50f);
    glVertex2f(0.05f, -0.50f);
    glVertex2f(0.05f, -0.47f);
    glEnd();

    glBegin(GL_TRIANGLES); //hat tip
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.05f, -0.47f);
    glVertex2f(0.0f, -0.43f);
    glVertex2f(0.05f, -0.47f);
    glEnd();

    glBegin(GL_QUADS);  // the body
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.05f, -0.58f);
    glVertex2f(-0.05f, -0.80f);
    glVertex2f(0.05f, -0.80f);
    glVertex2f(0.05f, -0.58f);
    glEnd();

    glBegin(GL_QUADS);  //the arms
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.07f, -0.58f);
    glVertex2f(-0.07f, -0.65f);
    glVertex2f(0.07f, -0.65f);
    glVertex2f(0.07f, -0.58f);
    glEnd();

    glColor3f(1.0f, 0.8f, 0.6f); // left hand palm
    drawFilledCircle2(-0.068, -0.65, 0.01);

    glColor3f(1.0f, 0.8f, 0.6f); //right hand palm
    drawFilledCircle2(0.068, -0.65, 0.01);

    glBegin(GL_QUADS);  //   feet
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.06f, -0.78f);
    glVertex2f(-0.06f, -0.80f);
    glVertex2f(0.06f, -0.80f);
    glVertex2f(0.06f, -0.78f);
    glEnd();

    glBegin(GL_TRIANGLES);//white blouse
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.035f, -0.59f);
    glVertex2f(0.0f, -0.67f);
    glVertex2f(0.035f, -0.59f);
    glEnd();

    glBegin(GL_TRIANGLES);//his craft
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.020f, -0.59f);
    glVertex2f(0.0f, -0.62f);
    glVertex2f(0.020f, -0.59f);
    glEnd();
}


//these codes to create the third man____________________________
void man3() {


    glBegin(GL_QUADS);  //the face
    glColor3f(1.0f, 0.8f, 0.6f);
    glVertex2f(-0.05f, -0.50);
    glVertex2f(-0.05f, -0.60f);
    glVertex2f(0.05f, -0.60f);
    glVertex2f(0.05f, -0.50);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f); //the hat
    drawFilledCircle2(0.0, -0.46, 0.03);

    glColor3f(0.0f, 0.0f, 0.0f); // right eye
    drawFilledCircle2(-0.02, -0.53, 0.01);

    glColor3f(0.0f, 0.0f, 0.0f); // left eye
    drawFilledCircle2(0.02, -0.53, 0.01);

    glBegin(GL_LINES);//left eyebrow
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(-0.038, -0.52);
    glVertex2d(-0.01, -0.52);
    glEnd();

    glBegin(GL_LINES);//right eyebrow
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(0.038, -0.52);
    glVertex2d(0.01, -0.52);
    glEnd();

    glBegin(GL_QUADS);  //
    glColor3f(0.0f, 0.0f, 0.0f); // mustache
    glVertex2f(-0.02f, -0.545);
    glVertex2f(-0.02f, -0.563f);
    glVertex2f(0.02f, -0.563f);
    glVertex2f(0.02f, -0.545);
    glEnd();

    glBegin(GL_QUADS);  // hat tip
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.05f, -0.47f);
    glVertex2f(-0.05f, -0.50f);
    glVertex2f(0.05f, -0.50f);
    glVertex2f(0.05f, -0.47f);
    glEnd();

    glBegin(GL_TRIANGLES);  // hat tip
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.05f, -0.47f);
    glVertex2f(0.0f, -0.43f);
    glVertex2f(0.05f, -0.47f);
    glEnd();

    glBegin(GL_QUADS);  //the body
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.05f, -0.58f);
    glVertex2f(-0.05f, -0.85f);
    glVertex2f(0.05f, -0.85f);
    glVertex2f(0.05f, -0.58f);
    glEnd();

    glBegin(GL_QUADS);  // the arms
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.07f, -0.58f);
    glVertex2f(-0.07f, -0.65f);
    glVertex2f(0.07f, -0.65f);
    glVertex2f(0.07f, -0.58f);
    glEnd();

    glColor3f(1.0f, 0.8f, 0.6f); // left hand palm
    drawFilledCircle2(-0.068, -0.65, 0.01);

    glColor3f(1.0f, 0.8f, 0.6f); // right hand palm
    drawFilledCircle2(0.068, -0.65, 0.01);

    glBegin(GL_QUADS);  //  feet
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.06f, -0.85f);
    glVertex2f(-0.06f, -0.87f);
    glVertex2f(0.06f, -0.87f);
    glVertex2f(0.06f, -0.85f);
    glEnd();

    glBegin(GL_TRIANGLES);// white blouse
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.035f, -0.59f);
    glVertex2f(0.0f, -0.67f);
    glVertex2f(0.035f, -0.59f);
    glEnd();

    glBegin(GL_TRIANGLES);// his craft
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.020f, -0.59f);
    glVertex2f(0.0f, -0.62f);
    glVertex2f(0.020f, -0.59f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.8f, 0.6f); //the chin
    glVertex2f(-0.05f, -0.57f);
    glVertex2f(0.0f, -0.60f);
    glVertex2f(0.05f, -0.57f);
    glEnd();

}

//-----------------------------------------

/////////////////////////////////////
// Now moving to another Scene..
////////////////////////////////////

// The Scene is about the storm in the sae that take the three man
// I used function named drawFilledCircle and passes it three arguments
// The first argument representsthe x-coordinate of the circle's center
// the second argument represents the y-coordinate
// and the third argument represents the circle's radius.

void BackSeaFoam() //This line defines a function named BackSeaFoam that takes no arguments and returns nothing (void).
{
    glColor4f(1.0f, 1.0f, 1.0f, 0.7f);  // sets the current color used for drawing to white with an alpha value of 0.7.

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
    //The circles are positioned at various locations on the graphics display.
    //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(0.0, 0.9, 0.23);

    drawFilledCircle3(-0.3, 0.7, 0.09);
    drawFilledCircle3(0.3, 0.7, 0.09);

    drawFilledCircle3(-0.3, 0.9, 0.12);
    drawFilledCircle3(0.3, 0.9, 0.12);

    drawFilledCircle3(-0.5, 0.9, 0.12);
    drawFilledCircle3(0.5, 0.9, 0.12);

    drawFilledCircle3(-0.7, 0.8, 0.10);
    drawFilledCircle3(0.7, 0.8, 0.10);

    drawFilledCircle3(-0.7, 0.9, 0.08);
    drawFilledCircle3(0.7, 0.9, 0.08);

    drawFilledCircle3(-0.8, 0.9, 0.08);
    drawFilledCircle3(0.8, 0.9, 0.08);

    drawFilledCircle3(-0.8, 0.7, 0.12);
    drawFilledCircle3(0.8, 0.7, 0.12);

    drawFilledCircle3(-0.9, 0.8, 0.11);
    drawFilledCircle3(0.9, 0.8, 0.11);

    drawFilledCircle3(-0.9, 0.6, 0.10);
    drawFilledCircle3(0.9, 0.6, 0.1);
}
void Big2Circles() //This line defines a function named Big2Circles that takes no arguments and returns nothing (void).
{
    glColor4f(1.0f, 1.0f, 1.0f, 0.8f); //sets the current color used for drawing 2 circle to white with an alpha value of 0.8.
    drawFilledCircle3(-0.6, 0.6, 0.24);
    drawFilledCircle3(0.6, 0.6, 0.24);
}
void SeaFoam1() //This line defines a function named SeaFoam1 that takes no arguments and returns nothing (void).
{
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f); // sets the current color used for drawing SeaFoam to white with an alpha value of 0.9.

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
    //The circles are positioned at various locations on the graphics display.
    //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(0.0, 0.6, 0.09);

    drawFilledCircle3(0.0, 0.7, 0.09);

    drawFilledCircle3(0.0, 0.8, 0.12);

    drawFilledCircle3(-0.1, 0.6, 0.08);
    drawFilledCircle3(0.1, 0.6, 0.08);

    drawFilledCircle3(-0.2, 0.7, 0.11);
    drawFilledCircle3(0.2, 0.7, 0.11);

    drawFilledCircle3(-0.2, 0.8, 0.11);
    drawFilledCircle3(0.2, 0.8, 0.11);

    drawFilledCircle3(-0.2, 0.6, 0.07);
    drawFilledCircle3(0.2, 0.6, 0.07);

    drawFilledCircle3(-0.3, 0.6, 0.07);
    drawFilledCircle3(0.3, 0.6, 0.07);

    drawFilledCircle3(-0.4, 0.8, 0.12);
    drawFilledCircle3(0.4, 0.8, 0.12);

    drawFilledCircle3(-0.4, 0.7, 0.08);
    drawFilledCircle3(0.4, 0.7, 0.08);

    drawFilledCircle3(-0.5, 0.7, 0.08);
    drawFilledCircle3(0.5, 0.7, 0.08);

    drawFilledCircle3(-0.6, 0.8, 0.08);
    drawFilledCircle3(0.6, 0.8, 0.08);

    drawFilledCircle3(-0.6, 0.8, 0.08);
    drawFilledCircle3(0.6, 0.8, 0.08);

    drawFilledCircle3(-0.7, 0.8, 0.10);
    drawFilledCircle3(0.7, 0.8, 0.10);

    drawFilledCircle3(-0.8, 0.7, 0.12);
    drawFilledCircle3(0.8, 0.7, 0.12);
}
void FrontSeaFoam()  //This line defines a function named FrontSeaFoam that takes no arguments and returns nothing (void).
{
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f); // sets the current color used for drawing to white with an alpha value of 0.9.

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
    //The circles are positioned at various locations on the graphics display.
    //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(0.0, 0.5, 0.09);

    drawFilledCircle3(0.0, 0.3, 0.04);
    drawFilledCircle3(0.0, 0.4, 0.06);

    drawFilledCircle3(-0.1, 0.5, 0.06);
    drawFilledCircle3(0.1, 0.5, 0.06);

    drawFilledCircle3(-0.1, 0.4, 0.05);
    drawFilledCircle3(0.1, 0.4, 0.05);

    drawFilledCircle3(-0.2, 0.5, 0.06);
    drawFilledCircle3(0.2, 0.5, 0.06);

}

void SeaWaves1()  //This line defines a function named SeaWaves1 that takes no arguments and returns nothing (void).
{
    glColor3f(0.0f, 0.2f, 0.5f);    //sets the current color for drawing to a shade of blue

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
    //The circles are positioned at various locations on the graphics display.
    //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(0.0, -0.7, 0.48);
    drawFilledCircle3(-0.6, -0.7, 0.48);
    drawFilledCircle3(0.6, -0.7, 0.48);
}
void SeaWaves2()  //This line defines a function named SeaWaves2 that takes no arguments and returns nothing (void).
{
    glColor3f(0.2f, 0.4f, 0.7f);       //sets the current color for drawing to a shade of blue

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
    //The circles are positioned at various locations on the graphics display.
    //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(0.0, -0.5, 0.48);
    drawFilledCircle3(-0.6, -0.5, 0.48);
    drawFilledCircle3(0.6, -0.5, 0.48);

}
void SeaWaves3()  //This line defines a function named SeaWaves3 that takes no arguments and returns nothing (void).
{
    glColor3f(0.3f, 0.5f, 0.8f);   //sets the current color for drawing to a shade of blue

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
    //The circles are positioned at various locations on the graphics display.
    //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(0.0, -0.3, 0.48);
    drawFilledCircle3(-0.6, -0.3, 0.48);
    drawFilledCircle3(0.6, -0.3, 0.48);

}

void SeaWaves4()  //This line defines a function named SeaWaves4 that takes no arguments and returns nothing (void).
{
    glColor3f(0.4f, 0.5f, 0.8f);   //sets the current color for drawing to a shade of blue

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
     //The circles are positioned at various locations on the graphics display.
     //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(0.0, 0.0, 0.40);
    drawFilledCircle3(-0.6, 0.0, 0.40);
    drawFilledCircle3(0.6, 0.0, 0.40);
}


void BackWaves1() //This line defines a function named BackWaves1 that takes no arguments and returns nothing (void).
{
    glColor4f(0.0f, 0.2f, 0.5f, 0.7);  //sets the current color for drawing to a shade of blue

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
    //The circles are positioned at various locations on the graphics display.
    //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(-0.3, -0.5, 0.29);
    drawFilledCircle3(0.3, -0.5, 0.29);

    drawFilledCircle3(-0.9, -0.5, 0.29);
    drawFilledCircle3(0.9, -0.5, 0.29);
}

void BackWaves2()  //This line defines a function named BackWaves2 that takes no arguments and returns nothing (void).
{
    glColor4f(0.2f, 0.4f, 0.7f, 0.7f);  //sets the current color for drawing to a shade of blue

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
    //The circles are positioned at various locations on the graphics display.
    //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(-0.3, -0.3, 0.29);
    drawFilledCircle3(0.3, -0.3, 0.29);

    drawFilledCircle3(-0.9, -0.3, 0.29);
    drawFilledCircle3(0.9, -0.3, 0.29);
}

void BackWaves3()
{
    glColor4f(0.3f, 0.5f, 0.8f, 0.9f);  //sets the current color for drawing to a shade of blue

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
    //The circles are positioned at various locations on the graphics display.
    //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(-0.3, -0.1, 0.30);
    drawFilledCircle3(0.3, -0.1, 0.30);

    drawFilledCircle3(-0.9, -0.1, 0.30);
    drawFilledCircle3(0.9, -0.1, 0.30);
}

void BackWaves4()
{
    glColor4f(0.4f, 0.5f, 0.8f, 0.8);  //sets the current color for drawing to a shade of blue

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
    //The circles are positioned at various locations on the graphics display.
    //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(-0.3, 0.1, 0.29);
    drawFilledCircle3(0.3, 0.1, 0.29);

    drawFilledCircle3(-0.9, 0.1, 0.29);
    drawFilledCircle3(0.9, 0.1, 0.29);
}

void BackWaves5()
{
    glColor4f(0.5f, 0.6f, 0.9f, 0.8f);  //sets the current color for drawing to a shade of blue

    //Each drawFilledCircle call specifies the center position of the circle using the (x, y) coordinates and sets the radius of the circle.
    //The circles are positioned at various locations on the graphics display.
    //Overall, this code is drawing multiple filled circles in different positions.

    drawFilledCircle3(0.0, 0.3, 0.29);

    drawFilledCircle3(-0.3, 0.3, 0.29);
    drawFilledCircle3(0.3, 0.3, 0.29);

    drawFilledCircle3(-0.6, 0.3, 0.29);
    drawFilledCircle3(0.6, 0.3, 0.29);

    drawFilledCircle3(-0.8, 0.3, 0.29);
    drawFilledCircle3(0.8, 0.3, 0.29);
}
//----------------------------------------
void squ() {

    //squid body
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(0.13f, -0.45f);
    glVertex2f(0.1f, -0.4f);
    glVertex2f(0.08f, -0.35f);
    glVertex2f(0.1f, -0.3f);
    glVertex2f(-0.25f, -0.3f);
    glVertex2f(-0.2f, -0.35f);
    glVertex2f(-0.18f, -0.45f);
    glVertex2f(-0.2f, -0.55f);
    glVertex2f(-0.4f, -0.6f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(0.5f, -0.7f);
    glVertex2f(0.4f, -0.6f);
    glVertex2f(0.35f, -0.55f);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(0.13f, -0.45f);
    glVertex2f(-0.2, -0.55);
    glVertex2f(-0.4, -0.6);
    glVertex2f(-0.5f, -0.65f);
    glVertex2f(-0.55f, -0.7f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(0.1f, -0.3f);
    glVertex2f(0.12f, -0.2f);
    glVertex2f(0.13f, -0.1f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.07f, 0.08f);
    glVertex2f(0.0f, 0.1f);
    glVertex2f(-0.05f, 0.12f);
    glVertex2f(-0.1f, 0.11f);
    glVertex2f(-0.15f, 0.1f);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(-0.25f, 0.05f);
    glVertex2f(-0.29f, 0.0f);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(-0.31f, -0.2f);
    glVertex2f(-0.25f, -0.3f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.2f);
    glVertex2f(-0.05f, -0.55f);
    glVertex2f(-0.05f, -0.6f);
    glVertex2f(-0.08f, -0.7f);
    glVertex2f(-0.03f, -0.7f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.2f);
    glVertex2f(-0.2f, -0.55f);
    glVertex2f(-0.35f, -0.7f);
    glVertex2f(-0.34f, -0.7f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.2f);
    glVertex2f(0.13f, -0.5f);
    glVertex2f(0.2f, -0.7f);
    glVertex2f(0.21f, -0.7f);
    glEnd();

    //eyer
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.09f, -0.17f);
    glVertex2f(0.04f, -0.3f);
    glVertex2f(0.08f, -0.3f);
    glEnd();
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.06, -0.27);
    glEnd();


    //eyel
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2f, -0.22f);
    glVertex2f(-0.11f, -0.31f);
    glVertex2f(-0.18f, -0.34f);
    glEnd();
    glPointSize(6.0f);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.165, -0.29);
    glEnd();

}

void squAr() { //squid right arm

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(0.4, -0.6);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.57, -0.4);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.59, -0.24);//
    glVertex2f(0.4, -0.2);
    glVertex2f(0.37, -0.3);
    glVertex2f(0.3, -0.35);
    glVertex2f(0.2, -0.4);
    glVertex2f(0.05, -0.46);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(0.59, -0.24);
    glVertex2f(0.5, -0.1);
    glVertex2f(0.45, 0.03);
    glVertex2f(0.45, 0.05);
    glVertex2f(0.35, 0.15);
    glVertex2f(0.3, 0.06);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.3, -0.05);
    glVertex2f(0.4, -0.2);
    glVertex2f(0.4, -0.2);
    glEnd();
    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle2(0.45, 0.05, 0.03);

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(0.45, 0.05);
    glVertex2f(0.5, 0.1);
    glVertex2f(0.57, 0.13);
    glVertex2f(0.6, 0.16);
    glVertex2f(0.62, 0.2);
    glVertex2f(0.64, 0.25);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.54, 0.3);
    glVertex2f(0.54, 0.25);
    glVertex2f(0.5, 0.21);
    glVertex2f(0.35, 0.15);
    glEnd();
    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle2(0.5, 0.1, 0.03);
    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle2(0.57, 0.15, 0.03);
    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle2(0.59, 0.3, 0.03);

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.57, 0.4);
    glVertex2f(0.55, 0.45);
    glVertex2f(0.52, 0.42);
    glVertex2f(0.5, 0.38);
    glVertex2f(0.54, 0.3);
    glEnd();
    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle2(0.56, 0.4, 0.03);

glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(0.63, 0.43);
    glVertex2f(0.65, 0.42);
    glVertex2f(0.61, 0.4);
    glVertex2f(0.67, 0.41);
    glVertex2f(0.68, 0.45);
    glVertex2f(0.62, 0.48);
    glVertex2f(0.55, 0.45);
    glVertex2f(0.57, 0.4);
    glEnd();
    
}

void squAl() { //squid left arm

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(-0.1f, -0.55f);
    glVertex2f(-0.4f, -0.59f);
    glVertex2f(-0.45f, -0.67f);
    glVertex2f(-0.5, -0.67);
    glVertex2f(-0.55, -0.55);
    glVertex2f(-0.53, -0.5);
    glVertex2f(-0.5, -0.41);
    glVertex2f(-0.35, -0.25);
    glVertex2f(-0.25, -0.3);
    glVertex2f(-0.22, -0.33);
    glVertex2f(-0.23, -0.4);
    glVertex2f(-0.25, -0.46);
    glVertex2f(-0.29, -0.41);
    glVertex2f(-0.27, -0.34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(-0.35, -0.25);
    glVertex2f(-0.38, -0.17);
    glVertex2f(-0.46, -0.1);
    glVertex2f(-0.42, 0.03);
    glVertex2f(-0.35, 0.01);
    glVertex2f(-0.3, -0.03);
    glVertex2f(-0.29, -0.2);
    glVertex2f(-0.25, -0.3);
    glEnd();
    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle2(-0.39, -0.18, 0.03);

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(-0.46, -0.1);
    glVertex2f(-0.51, -0.1);
    glVertex2f(-0.6, -0.15);
    glVertex2f(-0.68, -0.17);
    glVertex2f(-0.7, -0.15);
    glVertex2f(-0.73, -0.1);
    glVertex2f(-0.66, -0.08);
    glVertex2f(-0.62, -0.09);
    glVertex2f(-0.55, 0.0);
    glVertex2f(-0.42, 0.03);
    glEnd();
    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle2(-0.46, -0.11, 0.03);
    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle2(-0.55, -0.12, 0.03);
    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle2(-0.64, -0.15, 0.03);
    glColor3f(0.3f, 0.0f, 0.0f);
    drawFilledCircle2(-0.69, -0.14, 0.03);

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(-0.73, -0.1);
    glVertex2f(-0.7, 0.0);
    glVertex2f(-0.65, 0.04);
    glVertex2f(-0.63, 0.01);
    glVertex2f(-0.67, 0.0);
    glVertex2f(-0.66, -0.08);
    glEnd();

}
//----------------------------------------

int trans(int choice) { //switch to translate spaceship

    switch (choice) {
        case 1:
            
            if(transValue1 > -0.1){
                transValue1 -=0.003;
                glTranslatef(0.0f, transValue1, 0.0f);
            }
            
            break;
            
        default:
           
            break;
    }

    return 0;
}

//-----------------------------------------
//LoadTexture

GLuint LoadTexture(const char* filename, int width, int height)
{
    GLuint texture;
    unsigned char* data;
    FILE* file;

    //The following code will read in our RAW file
    file = fopen( filename, "rb" );

    if (file == NULL)
    {
        cout << "Unable to open the image file" << endl << "Program will exit :(" << endl;
        exit(0);
        return 0;
    }

    data = (unsigned char*)malloc(width * height * 3);
    fread(data, width * height * 3, 1, file);

    fclose(file);


    // reorder the image colors to RGB not BGR
    for (int i = 0; i < width * height; ++i)
    {
        int index = i * 3;
        unsigned char B, R;
        B = data[index];
        R = data[index + 2];

        data[index] = R;
        data[index + 2] = B;

    }


    glGenTextures(1, &texture);            //generate the texture with the loaded data
    glBindTexture(GL_TEXTURE_2D, texture); //bind the texture to it's array

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); //set texture environment parameters
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    free(data); //free the texture array

    if (glGetError() != GL_NO_ERROR)
        printf("GLError in genTexture()\n");

    return texture; //return whether it was successfull
}

//--------------------------------------------------------

static void special( int key, int x, int y )
{
    //handle special keys
    switch ( key ) {
        case GLUT_KEY_HOME:
            
            break;
        case GLUT_KEY_LEFT:
            
            break;
        case GLUT_KEY_RIGHT:
        
            break;
        case GLUT_KEY_UP:
            
            break;
        case GLUT_KEY_DOWN:
            
            break;
        default:
            break;
    }
}

//------------------------------------------------

static
void motion( int x, int y )
{}


//----------------------------------------------------------
void init()
{
    glClearColor(0.5f, 0.5f, 0.6f, 1.0f); // Set background color to light blue
    
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
     glMatrixMode(GL_PROJECTION);
     glMatrixMode(GL_MODELVIEW);
     
    //object of image 1 with its dimensions
    myTexture1 = LoadTexture(image1Path, 512, 512);

    if (myTexture1 == -1)
    {
        cout << "Error in loading the texture" << endl;
    }
    else
        cout << "The texture value is: " << myTexture1 << endl;
    
}

//----------------------------------------------------------


void display()   //page 1 'Start page'
{
    page=1;
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
        glPushMatrix(); //start page lighthouse tixure
        glEnable(GL_TEXTURE_2D);
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_QUADS);
    
    // mapping coordinat image
    glTexCoord2f(0.0,0.0);glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0,0.0);glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0,1.0);glVertex2f(1.0 , 1.0);
    glTexCoord2f(0.0,1.0);glVertex2f(-1.0, 1.0);
   
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        glPopMatrix();

    click();
 
    glFlush();
    glutSwapBuffers();
}

//----------------------------------

void lighthouseBoat()  //page 2 'The moment the lighthouse keepers disappeared'
{
    timerr +=0.038; //Initial counter of time to calculate the specific time of appearance function
    page=2;
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    background();
    cloud();
    
    glPushMatrix();
    glTranslatef(1.3, 0.0, 0.7);
    cloud();
    glPopMatrix();
  
    
    ocean();
   
    glPushMatrix();  // move the sea
    transValue +=  0.002;
    glTranslatef(transValue, 0.0, 0.0);
    oceanLines();
    glPopMatrix();

    island();
    Lighthouse();

    glPushMatrix(); //moving the boat and stopping at a certain distance
    glTranslatef(0.0 , -0.3 , 0.0);
    glTranslatef(objectX , 0.0 , 0.0);
    boat();
   
    glPopMatrix();
   

    //-----------------------------
    if (timerr >= 0.0 && timerr <= 3.0) {
        //the appearance and disappearance of the first light

            light();
    }
   
   // the appearance and disappearance of the second light
    if (timerr >= 4.0 && timerr <=6.0 ) {
        glPushMatrix();
        light1();
        
        glPopMatrix();
    }
    
        glFlush();
        glutSwapBuffers();
    }



//----------------------------------

void spaceship()  //page 3 'People's imaginations of what happened to the three guards "They were taken by alien aliens"'
{
    timerr +=0.038; //Initial counter of time to calculate the specific time of appearance function
    page=3;
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    background();
    ground();
    cloud();
       

        glPushMatrix();
        glTranslatef(1.3, 0.0, 0.7);  //cloud translate to left side on the screen
        cloud();
        glPopMatrix();

    if (timerr >= 10.0 && timerr <= 16.0) {  //3 men disappear with timer
        Man();
        glPushMatrix();
        glTranslatef(0.3, 0.0, 0.7);
        man2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.3, 0.07, -0.7);
        man3();
        glPopMatrix();
    }
    
    if (timerr >= 14.0 && timerr <= 17.0) { //translate the light with timer
        glPushMatrix();
        transValue += 0.0005;
        glTranslatef(0.0, 0.0, transValue);
        Beam();
        glPopMatrix();
    }

     glPushMatrix();  //translate spaceship down
        trans(1);
        Boom();
        glPopMatrix();

    
        glFlush();
        glutSwapBuffers();

}

//---------------------------------
void storm()  //page 4 'People's imaginations of what happened to the three guards "The strong waves of the sea took them away"'
{
    page=4;
    
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    TransValue += 0.02;  // increments the value of TransValue by 0.001.

    Big2Circles();  //calling function

    BackWaves5();   //calling  function

    
    glPushMatrix();
    glTranslatef(TransValue, 0.0, 0.0); //applies a translation transformation to the current matrix. It moves the subsequent drawing commands along the x-axis
    BackWaves4();  //calling  function
    glPopMatrix();

    SeaWaves4();  //calling  function


    glPushMatrix();
    glTranslatef(TransValue, 0.0, 0.0);  //applies a translation transformation to the current matrix. It moves the subsequent drawing commands along the x-axis
    BackWaves3();
    glPopMatrix();
    SeaWaves3();


    glPushMatrix();
    glTranslatef(TransValue, 0.0, 0.0);  //applies a translation transformation to the current matrix. It moves the subsequent drawing commands along the x-axis
    BackWaves2();  //calling  function
    glPopMatrix();

    SeaWaves2();         //calling  function


    glPushMatrix();
    glTranslatef(TransValue, 0.0, 0.0);  //applies a translation transformation to the current matrix. It moves the subsequent drawing commands along the x-axis
    BackWaves1();  //calling  function
    glPopMatrix();

    SeaWaves1();          //calling  function

    glPushMatrix();
    glTranslatef(0.0, 0.0, TransValue);   //applies a translation transformation to the current matrix. It moves the subsequent drawing commands along the z-axis
    FrontSeaFoam(); //calling  function
    glPopMatrix();

    BackSeaFoam(); //calling  function
    SeaFoam1();    //calling  function

    ground();

    //-------------------------------------
    
    Man();

    glPushMatrix();
    glTranslatef(0.3, 0.0, 0.7);
    man2();
    glPopMatrix();

    
    glPushMatrix();
    glTranslatef(-0.3, 0.07, -0.7);
    man3();
    glPopMatrix();
    

    if (TransValue > 2)  //The purpose of if statment is to be to reset the value of TransValue to -2.0 once it exceeds 2.0. This can create a looping effect or animation where TransValue oscillates between -2.0 and 2.0.
        TransValue = -2.0;

    glFlush();
    glutSwapBuffers();

}

//----------------------------------
void giantSquid()//page 5 'People's imaginations of what happened to the three guards "Giant squid took them"'
{
    page=5;
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    background();
    cloud();
       
    glPushMatrix();
    glTranslatef(1.3, 0.0, 0.7);
    cloud();
    glPopMatrix();


        glPushMatrix();
        glTranslatef(xpos, 0.0f, 0.0f);  // right arm translet
        squAr();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(xpos-0.1, 0.0f, 0.0f); // left arm translet
        squAl ();
        glPopMatrix();

        squ();
        ground();
        Man();

        glPushMatrix();
        glTranslatef(0.3,0.0,0.7);
        man2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.3, 0.07, -0.7);
        man3();
        glPopMatrix();

    
    glFlush();
    glutSwapBuffers();
}


//-------------------------------

// we use the key() to flip between scenes by pressing certain buttons on the keyboard
static
void key( unsigned char keyPressed, int x, int y ) // key handling
{
    switch ( keyPressed )
    {
        case 'q':
        case 27:
            exit( 0 );
            break;
            
            // to go to page 2  when you press 't'
            
        case 'T': //case sensitive
        case 't':
            if(page==1){
                glutDisplayFunc ( lighthouseBoat );
            }
            break;

          
            // to go to page 3  when you press 'y'
        case 'Y':
        case 'y':
            if(page==2){
                glutDisplayFunc ( spaceship );
                
            }
         
            break;
            
            // to go to page 4  when you press 'u'
        case 'U':
        case 'u':
            if(page==3){
                glutDisplayFunc ( storm );
                
            }
          
            break;
            
            
            // to go to page 5  when you press 'i'
        case 'I':
        case 'i':
            if(page==4){
                glutDisplayFunc ( giantSquid );
                
            }
          
            break;
            
        default:
            fprintf( stderr, "\nKeyboard commands:\n\n"
                    "t, T        - translate \n"
                    "left  mouse - scale \n"
                    "right mouse - reflect \n"
                    "q, <esc>    - Quit\n" );
            break;
            
           
    }
    glutPostRedisplay();
}


//-------------------------

//reference
// this update function from Stack overflow
// Update function to handle boat movement
void update() {
    // Move boat using translation value
    objectX += translateX;

    // Update distance traveled
    distanceTraveled += abs(translateX);

    // Stop the object after traveling 0.90 half/km
    if (distanceTraveled >= 0.90f) {
        translateX = 0.0f;
    }
}

//https://www.experts-exchange.com/questions/23733731/OpenGL-Timer-Function.html
// Timer function to control the rendering and updating
void timer(int value) {
    // Render the scene
    glutPostRedisplay();

    // Update object position
    update();

    // Set the next timer tick
    glutTimerFunc(15, timer, 0);
}


//-------------------------------

void reshapeFun(GLint newWidth, GLint newHight)
{
    glViewport(0, 0, newWidth, newHight);
    win_width = newWidth;
    win_hight = newHight;
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);   //  Specify the display Mode – RGB, RGBA or color //  Index, single or
    glutInitWindowSize(win_width, win_hight);       // Set the window's initial width & height
    glutInitWindowPosition(50, 50);                 // Position the window's initial top-left corner
    glutCreateWindow("The Flanne Isle Mystery");    // Create a window with the given title
    init();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutIdleFunc( play );
    glutDisplayFunc ( display );
    glutKeyboardFunc ( key );
    glutMotionFunc ( motion );
    glutReshapeFunc(reshapeFun);
    glutSpecialFunc( special );
    // Set the initial timer tick
    glutTimerFunc(3000, timer, 0);
    glutTimerFunc(0, timer1, 0);
    glutMainLoop();                                  // Enter the infinitely event-processing loop
    return 0;
}
