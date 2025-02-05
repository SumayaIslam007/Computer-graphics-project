#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function declarations
void draw_circle(float x, float y, float radius);
void DrawSky();
void DrawGround();
void DrawSun();
void DrawClouds();
void DrawBuildings();
void DrawTrees();
void DrawGardenRoad();
void DrawGardenBench(float xPosition); // Modified to add position
void DrawFlowers();
void myDisplay();
void update(int);

// Global variables for animations
float moveClouds = 0.0f;

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
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.7, 1.0); // Blue sky
    glVertex2i(0, 400);
    glVertex2i(800, 400);
    glVertex2i(800, 800);
    glVertex2i(0, 800);
    glEnd();
}

// --- Ground (Light green Area) ---
void DrawGround() {
    glBegin(GL_POLYGON);
    glColor3f(0.6, 1.3, 0.6); // light green ground
    glVertex2i(0, 0);
    glVertex2i(800, 0);
    glVertex2i(800, 400);
    glVertex2i(0, 400);
    glEnd();
}

// --- Sun ---
void DrawSun() {
    glColor3f(1.0, 0.9, 0.0); // Yellow sun
    draw_circle(700, 700, 40);
}

// --- Clouds ---
void DrawClouds() {
    glPushMatrix();
    glTranslatef(moveClouds, 0.0f, 0.0f);
    glColor3f(1.0, 1.0, 1.0); // White clouds

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
        {1.0, 0.7, 0.4}, // Orange building
        {0.7, 0.5, 0.0}, // Dark Yellow building
        {0.5, 0.0, 0.0}, // Dark Red building
        {0.0, 0.0, 0.5}, // Dark blue building
        {0.8, 0.2, 0.4}  // Dark Pink building
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

// --- Garden Road (Modified to look like a garden) ---
void DrawGardenRoad() {
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.6, 0.3); // Grass green road
    glVertex2i(0, 0);
    glVertex2i(800, 0);
    glVertex2i(800, 200); // Adjust road width and make it curved
    glVertex2i(0, 200);
    glEnd();
}

// --- Garden Bench (Modified to add position) ---
void DrawGardenBench(float xPosition) {
    glColor3f(0.6, 0.3, 0.1); // Brown wood for the bench

    // Bench Seat
    glBegin(GL_POLYGON);
    glVertex2i(xPosition, 150);
    glVertex2i(xPosition + 200, 150);
    glVertex2i(xPosition + 200, 170);
    glVertex2i(xPosition, 170);
    glEnd();

    // Bench Legs
    glBegin(GL_POLYGON);
    glVertex2i(xPosition + 10, 150);
    glVertex2i(xPosition + 20, 150);
    glVertex2i(xPosition + 20, 130);
    glVertex2i(xPosition + 10, 130);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xPosition + 180, 150);
    glVertex2i(xPosition + 190, 150);
    glVertex2i(xPosition + 190, 130);
    glVertex2i(xPosition + 180, 130);
    glEnd();
}

// --- Draw Flowers in the Garden ---
void DrawFlowers() {
    glColor3f(1.0, 0.0, 0.0); // Red flowers

    // Draw flowers randomly within the garden area
    for (int i = 50; i < 800; i += 100) {
        // Flower stem
        glColor3f(0.0, 0.6, 0.2); // Green stem
        glBegin(GL_POLYGON);
        glVertex2i(i, 50); // Bottom of the stem
        glVertex2i(i + 5, 50);
        glVertex2i(i + 5, 100); // Top of the stem
        glVertex2i(i, 100);
        glEnd();

        // Flower petals
        glColor3f(1.0, 0.0, 0.0); // Red flower petals
        draw_circle(i + 2, 105, 10); // Center of the flower
        draw_circle(i - 5, 95, 8); // Left petal
        draw_circle(i + 5, 95, 8); // Right petal
        draw_circle(i - 2, 85, 8); // Lower left petal
        draw_circle(i + 2, 85, 8); // Lower right petal
    }
}

// --- Display function (Modified to include the new benches and flowers) ---
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    DrawSky();
    DrawGround();
    DrawSun();
    DrawClouds();
    DrawBuildings();
    DrawTrees();
    DrawGardenRoad(); // Draw the garden-style road

    // Draw benches on both sides
    DrawGardenBench(100);   // Left bench
    DrawGardenBench(500);   // Right bench

    // Draw flowers in the garden
    DrawFlowers();

    glutSwapBuffers();
}

// --- Animation update function ---
void update(int value) {
    moveClouds += 0.1f; // Move clouds
    if (moveClouds > 800) moveClouds = -800; // Loop clouds back

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

// --- Main function ---
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Beautiful Park Scene with Garden");

    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    gluOrtho2D(0.0, 800.0, 0.0, 800.0); // Set orthographic projection

    glutDisplayFunc(myDisplay);
    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}









