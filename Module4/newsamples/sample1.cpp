
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

// Global variables
int currentGroup = 0;  // 0=Basic, 1=Named, 2=Sky/Nature, 3=UI, 4=Pastel
int currentColor = 0;
char colorName[50] = "Dark Blue (Default)";

// Function to set background color by index and group
void setBackgroundColor(int group, int index) {
    switch (group) {
        // ========== GROUP 0: BASIC COLORS ==========
    case 0:
        switch (index % 8) {
        case 0: glClearColor(0.0, 0.0, 0.0, 1.0); strcpy(colorName, "Black"); break;
        case 1: glClearColor(1.0, 1.0, 1.0, 1.0); strcpy(colorName, "White"); break;
        case 2: glClearColor(1.0, 0.0, 0.0, 1.0); strcpy(colorName, "Red"); break;
        case 3: glClearColor(0.0, 1.0, 0.0, 1.0); strcpy(colorName, "Green"); break;
        case 4: glClearColor(0.0, 0.0, 1.0, 1.0); strcpy(colorName, "Blue"); break;
        case 5: glClearColor(1.0, 1.0, 0.0, 1.0); strcpy(colorName, "Yellow"); break;
        case 6: glClearColor(1.0, 0.0, 1.0, 1.0); strcpy(colorName, "Magenta"); break;
        case 7: glClearColor(0.0, 1.0, 1.0, 1.0); strcpy(colorName, "Cyan"); break;
        }
        break;

        // ========== GROUP 1: NAMED COLORS ==========
    case 1:
        switch (index % 14) {
        case 0: glClearColor(0.5, 0.5, 0.5, 1.0); strcpy(colorName, "Gray"); break;
        case 1: glClearColor(0.2, 0.2, 0.2, 1.0); strcpy(colorName, "Dark Gray"); break;
        case 2: glClearColor(0.8, 0.8, 0.8, 1.0); strcpy(colorName, "Light Gray"); break;
        case 3: glClearColor(0.0, 0.5, 0.0, 1.0); strcpy(colorName, "Dark Green"); break;
        case 4: glClearColor(0.0, 0.8, 0.0, 1.0); strcpy(colorName, "Lime Green"); break;
        case 5: glClearColor(0.0, 0.5, 0.5, 1.0); strcpy(colorName, "Teal"); break;
        case 6: glClearColor(0.5, 0.0, 0.5, 1.0); strcpy(colorName, "Purple"); break;
        case 7: glClearColor(0.5, 0.0, 0.0, 1.0); strcpy(colorName, "Maroon"); break;
        case 8: glClearColor(0.5, 0.5, 0.0, 1.0); strcpy(colorName, "Olive"); break;
        case 9: glClearColor(0.0, 0.0, 0.5, 1.0); strcpy(colorName, "Navy Blue"); break;
        case 10: glClearColor(1.0, 0.5, 0.0, 1.0); strcpy(colorName, "Orange"); break;
        case 11: glClearColor(0.5, 0.25, 0.0, 1.0); strcpy(colorName, "Brown"); break;
        case 12: glClearColor(0.7, 0.4, 0.2, 1.0); strcpy(colorName, "Wood Brown"); break;
        case 13: glClearColor(0.9, 0.6, 0.0, 1.0); strcpy(colorName, "Gold"); break;
        }
        break;

        // ========== GROUP 2: SKY & NATURE ==========
    case 2:
        switch (index % 10) {
        case 0: glClearColor(0.0, 0.5, 1.0, 1.0); strcpy(colorName, "Sky Blue"); break;
        case 1: glClearColor(0.2, 0.6, 1.0, 1.0); strcpy(colorName, "Bright Sky"); break;
        case 2: glClearColor(0.0, 0.3, 0.6, 1.0); strcpy(colorName, "Ocean Blue"); break;
        case 3: glClearColor(0.0, 0.8, 1.0, 1.0); strcpy(colorName, "Cyan Sky"); break;
        case 4: glClearColor(0.5, 0.8, 1.0, 1.0); strcpy(colorName, "Day Sky"); break;
        case 5: glClearColor(0.1, 0.1, 0.3, 1.0); strcpy(colorName, "Night Sky"); break;
        case 6: glClearColor(0.2, 0.0, 0.4, 1.0); strcpy(colorName, "Twilight"); break;
        case 7: glClearColor(0.0, 0.4, 0.2, 1.0); strcpy(colorName, "Forest Green"); break;
        case 8: glClearColor(0.8, 1.0, 0.8, 1.0); strcpy(colorName, "Mint"); break;
        case 9: glClearColor(0.95, 0.95, 0.85, 1.0); strcpy(colorName, "Parchment"); break;
        }
        break;

        // ========== GROUP 3: UI FRIENDLY ==========
    case 3:
        switch (index % 8) {
        case 0: glClearColor(0.96, 0.96, 0.86, 1.0); strcpy(colorName, "Paper"); break;
        case 1: glClearColor(0.15, 0.15, 0.15, 1.0); strcpy(colorName, "Near Black"); break;
        case 2: glClearColor(0.25, 0.25, 0.25, 1.0); strcpy(colorName, "Dark UI"); break;
        case 3: glClearColor(0.98, 0.92, 0.86, 1.0); strcpy(colorName, "Antique White"); break;
        case 4: glClearColor(0.94, 0.90, 0.90, 1.0); strcpy(colorName, "Misty Rose"); break;
        case 5: glClearColor(0.87, 0.92, 0.97, 1.0); strcpy(colorName, "Alice Blue"); break;
        case 6: glClearColor(0.93, 0.87, 0.93, 1.0); strcpy(colorName, "Thistle"); break;
        case 7: glClearColor(1.0, 0.98, 0.92, 1.0); strcpy(colorName, "Cornsilk"); break;
        }
        break;

        // ========== GROUP 4: PASTEL ==========
    case 4:
        switch (index % 8) {
        case 0: glClearColor(1.0, 0.8, 0.8, 1.0); strcpy(colorName, "Pastel Red"); break;
        case 1: glClearColor(0.8, 1.0, 0.8, 1.0); strcpy(colorName, "Pastel Green"); break;
        case 2: glClearColor(0.8, 0.8, 1.0, 1.0); strcpy(colorName, "Pastel Blue"); break;
        case 3: glClearColor(1.0, 1.0, 0.8, 1.0); strcpy(colorName, "Pastel Yellow"); break;
        case 4: glClearColor(1.0, 0.8, 1.0, 1.0); strcpy(colorName, "Pastel Magenta"); break;
        case 5: glClearColor(0.8, 1.0, 1.0, 1.0); strcpy(colorName, "Pastel Cyan"); break;
        case 6: glClearColor(1.0, 0.9, 0.85, 1.0); strcpy(colorName, "Peach"); break;
        case 7: glClearColor(0.9, 0.8, 1.0, 1.0); strcpy(colorName, "Lavender"); break;
        }
        break;

        // ========== DEFAULT ==========
    default:
        glClearColor(0.1, 0.1, 0.2, 1.0);
        strcpy(colorName, "Dark Blue (Default)");
        break;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay(); // Trigger redraw to update text
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw color name as text
    glColor3f(1.0, 1.0, 1.0); // White text
    glRasterPos2f(-0.9, 0.9); // Top-left

    char label[100];
    sprintf(label, "Group %d - Color: %s", currentGroup, colorName);
    for (int i = 0; label[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, label[i]);
    }

    // Draw a sample shape so you can see contrast
    glColor3f(1.0, 1.0, 0.0); // Yellow triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.0, 0.3);
    glEnd();

    glFlush();
}

// Reshape function
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Keyboard handler
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '0': currentGroup = 0; currentColor = 0; setBackgroundColor(0, 0); break;
    case '1': currentGroup = 1; currentColor = 0; setBackgroundColor(1, 0); break;
    case '2': currentGroup = 2; currentColor = 0; setBackgroundColor(2, 0); break;
    case '3': currentGroup = 3; currentColor = 0; setBackgroundColor(3, 0); break;
    case '4': currentGroup = 4; currentColor = 0; setBackgroundColor(4, 0); break;

    case 'n': case 'N':
        currentColor++;
        setBackgroundColor(currentGroup, currentColor);
        break;

    case 'p': case 'P':
        currentColor--;
        if (currentColor < 0) {
            // Wrap around based on group
            int max;
            switch (currentGroup) {
            case 0: max = 8; break;
            case 1: max = 14; break;
            case 2: max = 10; break;
            case 3: max = 8; break;
            case 4: max = 8; break;
            default: max = 1;
            }
            currentColor = max - 1;
        }
        setBackgroundColor(currentGroup, currentColor);
        break;

    case 27: // ESC
        exit(0);
        break;
    }
}

// Special keys for quick group jump
void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_F1: currentGroup = 0; currentColor = 0; setBackgroundColor(0, 0); break;
    case GLUT_KEY_F2: currentGroup = 1; currentColor = 0; setBackgroundColor(1, 0); break;
    case GLUT_KEY_F3: currentGroup = 2; currentColor = 0; setBackgroundColor(2, 0); break;
    case GLUT_KEY_F4: currentGroup = 3; currentColor = 0; setBackgroundColor(3, 0); break;
    case GLUT_KEY_F5: currentGroup = 4; currentColor = 0; setBackgroundColor(4, 0); break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Background Color Explorer");

    // Initialize with default
    setBackgroundColor(0, 0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    printf("=== CONTROLS ===\n");
    printf("Keys 0-4: Switch color groups\n");
    printf("'n' or 'N': Next color in group\n");
    printf("'p' or 'P': Previous color in group\n");
    printf("F1-F5: Jump to group 0-4\n");
    printf("ESC: Quit\n");

    glutMainLoop();
    return 0;
}
