#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>


#define PI 3.14159265358979323846

// Function declarations
void draw_circle(float x, float y, float radius);
void DrawSky();
void DrawGround();
void DrawSun();
void DrawMoon();
void DrawClouds();
void DrawStars();
void DrawBuildings();
void DrawTrees();
void DrawHighway();
void DrawVehicles();
void DrawStreetLights();
void myDisplay();
void update(int);
void keyboard(unsigned char key, int x, int y);

// Global variables for animations
float moveVehicles = 0.0f;
float moveClouds = 0.0f;
float vehicleSpeed = 1.0f; // Default vehicle speed

static float airplaneX = 0.0;  // Starting position of the airplane on the right side
static float airplaneY = 700.0;







bool isDay = true;

void timerFunction(int value) {
    // Move the airplane right
    airplaneX += 2.0;  // Increase the value for rightward movement

    // No reset to the left, airplane will keep moving forward
    glutPostRedisplay();  // Trigger a redraw

    // Call the timer function again after 20 milliseconds
    glutTimerFunc(20, timerFunction, 0);
}



// --- Utility Function: Draw a Circle ---
void draw_circle(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * PI / 180.0f;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

// --- Sky ---
void DrawSky() {
    if (isDay)
        glColor3f(0.4, 0.7, 1.0); // Blue sky (Day)
    else
        glColor3f(0.0, 0.0, 0.2); // Dark blue sky (Night)

    glBegin(GL_POLYGON);
    glVertex2i(0, 400);
    glVertex2i(800, 400);
    glVertex2i(800, 800);
    glVertex2i(0, 800);
    glEnd();
}


// --- Ground (light green Area) ---
void DrawGround() {
    glBegin(GL_POLYGON);
    glColor3f(0.6, 1.0, 0.6); // light green ground
    glVertex2i(0, 0);
    glVertex2i(800, 0);
    glVertex2i(800, 400);
    glVertex2i(0, 400);
    glEnd();
}

// --- Sun ---
void DrawSun() {
    if (isDay) {
        glColor3f(1.0, 0.9, 0.0); // Yellow sun
        draw_circle(100, 700, 40);
    }
}


// --- Moon ---
void DrawMoon() {
    if (!isDay) {
        glColor3f(0.9, 0.9, 0.9); // White moon
        draw_circle(700, 700, 30);
    }
}

// --- Stars ---
void DrawStars() {
    if (!isDay) {
        glColor3f(1.0, 1.0, 1.0); // White stars
        for (int i = 0; i < 10; i++) {
            float x = rand() % 800;
            float y = 400 + (rand() % 400);
            draw_circle(x, y, 0.90);
        }
    }
}


// --- Clouds ---
void DrawClouds() {
    glPushMatrix();
    glTranslatef(moveClouds, 0.0f, 0.0f);
     if (isDay)
        glColor3f(1.0, 1.0, 1.0); // White clouds (Day)
    else
        glColor3f(0.75, 0.75, 0.75); // Grey clouds (Night)

    // Cloud 1
    draw_circle(200, 720, 20);
    draw_circle(220, 730, 25);
    draw_circle(240, 720, 20);

    // Cloud 2
    draw_circle(400, 750, 25);
    draw_circle(430, 760, 30);
    draw_circle(460, 750, 25);

    // Cloud 3
    draw_circle(600, 700, 20);
    draw_circle(620, 710, 25);
    draw_circle(640, 700, 20);

    glPopMatrix();
}

// --- Buildings ---
void DrawBuildings() {
    int x = 50; // Start position for buildings
    int heights[] = {250, 300, 280, 320, 260};
    int widths[] = {80, 100, 90, 110, 70};
    float colors[][3] = {
        {0.6, 0.8, 1.0}, // Blue building
        {0.9, 0.7, 0.3}, // Yellow building
        {1.0, 0.5, 0.5}, // Red building
        {0.4, 0.7, 0.9}, // Light blue building
        {0.9, 0.6, 0.7}  // Pink building
    };

    for (int i = 0; i < 5; i++) {
        // Building body
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        glBegin(GL_POLYGON);
        glVertex2i(x, 300);
        glVertex2i(x + widths[i], 300);
        glVertex2i(x + widths[i], 300 + heights[i]);
        glVertex2i(x, 300 + heights[i]);
        glEnd();

        // Rooftop decoration
        glColor3f(0.3, 0.3, 0.3); // Gray rooftop
        glBegin(GL_POLYGON);
        glVertex2i(x - 5, 300 + heights[i]);
        glVertex2i(x + widths[i] + 5, 300 + heights[i]);
        glVertex2i(x + widths[i] + 5, 300 + heights[i] + 10);
        glVertex2i(x - 5, 300 + heights[i] + 10);
        glEnd();

        // Adding windows (uniform design for all buildings)
        glColor3f(0.8, 0.8, 0.8); // Frame color
        for (int wx = x + 10; wx < x + widths[i] - 10; wx += 20) {
            for (int wy = 310; wy < 300 + heights[i] - 20; wy += 30) {
                // Window frame
                glBegin(GL_POLYGON);
                glVertex2i(wx - 2, wy - 2);
                glVertex2i(wx + 12, wy - 2);
                glVertex2i(wx + 12, wy + 22);
                glVertex2i(wx - 2, wy + 22);
                glEnd();

                // Inner window
                glColor3f(0.3, 0.6, 0.9); // Blue windows
                glBegin(GL_POLYGON);
                glVertex2i(wx, wy);
                glVertex2i(wx + 10, wy);
                glVertex2i(wx + 10, wy + 20);
                glVertex2i(wx, wy + 20);
                glEnd();
                glColor3f(0.8, 0.8, 0.8); // Reset frame color
            }
        }

        // Adding glass windows (just like the inner ones)
        glColor3f(0.6, 0.9, 1.0); // Glass windows
        for (int wx = x + 10; wx < x + widths[i] - 10; wx += 20) {
            for (int wy = 320; wy < 300 + heights[i] - 20; wy += 30) {
                glBegin(GL_POLYGON);
                glVertex2i(wx, wy);
                glVertex2i(wx + 10, wy);
                glVertex2i(wx + 10, wy + 20);
                glVertex2i(wx, wy + 20);
                glEnd();
            }
        }

        x += widths[i] + 40; // Equal spacing between buildings
    }
}

// --- Trees ---
void DrawTrees() {
    int treeX = 20;
    for (int i = 0; i < 8; i++) {
        glColor3f(0.55, 0.27, 0.07); // Tree trunk
        glBegin(GL_POLYGON);
        glVertex2i(treeX, 280);
        glVertex2i(treeX + 15, 280);
        glVertex2i(treeX + 15, 330); // Taller stems
        glVertex2i(treeX, 330);
        glEnd();

        glColor3f(0.0, 0.8, 0.0); // Tree canopy
        draw_circle(treeX + 8, 350, 25);
        draw_circle(treeX - 5, 330, 25);
        draw_circle(treeX + 20, 330, 25);

        treeX += 100;
    }
}

// --- Highway ---
void DrawHighway() {
    // Road base
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3); // Dark gray highway
    glVertex2i(0, 0);
    glVertex2i(800, 0);
    glVertex2i(800, 200); // Increased road width
    glVertex2i(0, 200);
    glEnd();

    // Side borders
    glColor3f(0.5, 0.5, 0.5); // Gray border
    glBegin(GL_POLYGON);
    glVertex2i(0, 190);
    glVertex2i(800, 190);
    glVertex2i(800, 200);
    glVertex2i(0, 200);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(800, 0);
    glVertex2i(800, 10);
    glVertex2i(0, 10);
    glEnd();

    // White dashed lines
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 800; i += 80) {
        glBegin(GL_POLYGON);
        glVertex2i(i + 30, 100); // Adjusted dashed line position
        glVertex2i(i + 50, 100);
        glVertex2i(i + 50, 105);
        glVertex2i(i + 30, 105);
        glEnd();
    }
}

// --- Vehicles ---
void DrawVehicles() {
    glPushMatrix();
    glTranslatef(moveVehicles, 0.0f, 0.0f);

    // Car 1: Red car
    glColor3f(1.0, 0.0, 0.0); // Red car body
    glBegin(GL_POLYGON);
    glVertex2i(100, 50);
    glVertex2i(170, 50);
    glVertex2i(170, 70);
    glVertex2i(100, 70);
    glEnd();

    // Car 1 roof
    glBegin(GL_POLYGON);
    glVertex2i(110, 70);
    glVertex2i(160, 70);
    glVertex2i(150, 85);
    glVertex2i(120, 85);
    glEnd();

    // Car 1 windows
    glColor3f(1.0, 1.0, 1.0); // White windows
    glBegin(GL_POLYGON);
    glVertex2i(120, 75);
    glVertex2i(130, 75);
    glVertex2i(130, 80);
    glVertex2i(120, 80);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(140, 75);
    glVertex2i(150, 75);
    glVertex2i(150, 80);
    glVertex2i(140, 80);
    glEnd();

    // Car 1 wheels
    glColor3f(0.0, 0.0, 0.0); // Black wheels
    draw_circle(120, 50, 10);
    draw_circle(160, 50, 10);

    // Car 2: Blue car
    glColor3f(0.0, 0.0, 1.0); // Blue car body
    glBegin(GL_POLYGON);
    glVertex2i(300, 50);
    glVertex2i(370, 50);
    glVertex2i(370, 70);
    glVertex2i(300, 70);
    glEnd();

    // Car 2 roof
    glBegin(GL_POLYGON);
    glVertex2i(310, 70);
    glVertex2i(360, 70);
    glVertex2i(350, 85);
    glVertex2i(320, 85);
    glEnd();

    // Car 2 windows
    glColor3f(1.0, 1.0, 1.0); // White windows
    glBegin(GL_POLYGON);
    glVertex2i(320, 75);
    glVertex2i(330, 75);
    glVertex2i(330, 80);
    glVertex2i(320, 80);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(340, 75);
    glVertex2i(350, 75);
    glVertex2i(350, 80);
    glVertex2i(340, 80);
    glEnd();

    // Car 2 wheels
    glColor3f(0.0, 0.0, 0.0); // Black wheels
    draw_circle(320, 50, 10);
    draw_circle(360, 50, 10);

    glPopMatrix();
}

// --- Street Lights ---
void DrawStreetLights() {
    int lightX = 100;
    for (int i = 0; i < 6; i++) {
        // Light pole
        glColor3f(0.5, 0.5, 0.5); // Gray light pole
        glBegin(GL_POLYGON);
        glVertex2i(lightX, 190); // Pole base
        glVertex2i(lightX + 5, 190);
        glVertex2i(lightX + 5, 260);
        glVertex2i(lightX, 260);
        glEnd();

        // Light bulb
        glColor3f(1.0, 1.0, 0.8); // Yellow light
        draw_circle(lightX + 2, 270, 8);

        lightX += 130; // Adjust position for next streetlight
    }
}

void drawAirplane(float x , float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);  // Move the airplane according to the current x and y positions

    // --- Airplane Body ---
    glColor3f(1.0, 1.0, 1.0);  // Body color: white
    glBegin(GL_POLYGON); // Rectangular body
        glVertex2f(0.0,30.0);
        glVertex2f(0.0,55.0);
        glVertex2f(135.0,55.0);
        glVertex2f(135.0,30.0);
    glEnd();

    // --- Cockpit ---
    glColor3f(1.0, 1.0, 1.0);  // Cockpit color: white
    glBegin(GL_POLYGON);
        glVertex2f(135.0,55.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);  // Outline color
    glBegin(GL_LINE_LOOP);
        glVertex2f(135.0,55.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
    glEnd();

    // --- Nose ---
    glColor3f(0.0, 0.75, 1.0);  // Nose color: dark sky blue
    glBegin(GL_POLYGON);
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,30.0);
        glVertex2f(135.0,30.0);
    glEnd();

    // --- Tail ---
    glColor3f(0.0, 0.75, 1.0);  // Tail color: dark sky blue
    glBegin(GL_POLYGON);
        glVertex2f(0.0,55.0);
        glVertex2f(0.0,80.0);
        glVertex2f(10.0,80.0);
        glVertex2f(40.0,55.0);
    glEnd();

    // --- Left Wing ---
    glColor3f(0.0, 0.75, 1.0);  // Left wing color: dark sky blue
    glBegin(GL_POLYGON);
        glVertex2f(65.0,55.0);
        glVertex2f(50.0,70.0);
        glVertex2f(75.0,70.0);
        glVertex2f(90.0,55.0);
    glEnd();

    // --- Right Wing ---
    glColor3f(0.0, 0.75, 1.0);  // Right wing color: dark sky blue
    glBegin(GL_POLYGON);
        glVertex2f(70.0,40.0);
        glVertex2f(100.0,40.0);
        glVertex2f(80.0,15.0);
        glVertex2f(50.0,15.0);
    glEnd();

    glPopMatrix();
}


// --- Display Function ---
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    DrawSky();
    DrawGround();
    DrawSun();
     DrawMoon();
    DrawClouds();
    DrawBuildings();
     DrawStars();
    DrawTrees();
    DrawHighway();
    DrawVehicles();
    DrawStreetLights();

   drawAirplane(airplaneX, airplaneY);

    // Draw the airplane at the updated position
    glPushMatrix();



    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    moveVehicles += vehicleSpeed; // Use vehicleSpeed to move vehicles
    if (moveVehicles > 800) {
        moveVehicles = -200; // Reset vehicle position
    }

    moveClouds += 0.2f; // Move clouds (speed remains the same)
    if (moveClouds > 800) {
        moveClouds = -200; // Reset cloud position
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Continue the animation
}





void keyboard(unsigned char key, int x, int y) {
    if (key == 'n' || key == 'N') {
        isDay = false; // Switch to night
    } else if (key == 'd' || key == 'D') {
        isDay = true; // Switch to day
    } else if (key == '+' || key == '=') {
        vehicleSpeed += 0.5f; // Speed up vehicle
    } else if (key == '-') {
        vehicleSpeed -= 0.5f; // Slow down vehicle
        if (vehicleSpeed < 0.5f) vehicleSpeed = 0.5f; // Prevent speed from going negative
    }

    glutPostRedisplay(); // Redraw the scene
}



// --- Main Function ---
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Street View with Vehicles, Buildings, and Streetlights");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(0.0, 800.0, 0.0, 800.0, -1.0, 1.0);

    glutDisplayFunc(myDisplay);
     glutKeyboardFunc(keyboard);
      glutTimerFunc(20, timerFunction, 0);
    glutTimerFunc(25, update, 0); // Set update interval

    glutMainLoop();
    return 0;
}








