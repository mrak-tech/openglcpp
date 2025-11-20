//#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#define BUFFER_OFFSET(i) ((void*)(i))
void GLAPIENTRY MessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam);
using namespace std;
void displayObject();

// Pyramid vertices (4 triangular faces = 12 vertices)
GLfloat vertices[] = {
	//Triangle (Pyramid)
	0.0f, 1.0f, 0.0f,
	-1.0f, -1.0f, 1.0f,
	1.0f, -1.0f, 1.0f,
	0.0f, 1.0f, 0.0f,
	1.0f, -1.0f, 1.0f,
	1.0f, -1.0f, -1.0f,
	0.0f, 1.0f, 0.0f,
	1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	0.0f,  1.0f,  0.0f,
	-1.0f,-1.0f, -1.0f,
	-1.0f,-1.0f,  1.0f,
	//Cube (6 faces as quads = 24 vertices)
	1.0f, 1.0f, -1.0f,
	-1.0f, 1.0f, -1.0f,
	-1.0f, 1.0f,  1.0f,
	 1.0f, 1.0f,  1.0f,
	 1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
     1.0f,  1.0f, 1.0f,
	-1.0f,  1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f,
	 1.0f, -1.0f, 1.0f,
	 1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,
	 1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,
	1.0f,  1.0f, -1.0f,
	1.0f,  1.0f,  1.0f,
	1.0f, -1.0f,  1.0f,
	1.0f, -1.0f, -1.0f,
};

// Colors for the pyramid (12 vertices)
GLfloat colors[] = {
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f,0.0f,0.0f,
	0.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f
};

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("simple");
	glutDisplayFunc(displayObject);
	
	
	GLenum err = glewInit();
	if (err == GLEW_OK) {
		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(MessageCallback, 0);
		printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
		printf("OpenGL vendor (%s): \n", glGetString(GL_VENDOR));
		glutMainLoop();
	}
}

void displayObject() {
	GLuint VBOid;
	glGenBuffers(1, &VBOid);
	glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	glBufferData(GL_ARRAY_BUFFER, ((9 * 4) + (12 * 6) + (9 * 4) + (12 * 6)) * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, ((9 * 4) + (12 * 6)) * sizeof(GLfloat), ((9 * 4) * sizeof(GLfloat)), colors);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glColorPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(((9 * 4) + (12 * 6)) * sizeof(GLfloat)));
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	glDrawArrays(GL_TRIANGLES, 0, 12);  // Draw the pyramid
	//glDrawArrays(GL_QUADS, 0, 24);     // Uncomment to draw the cube instead
	glFlush();
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBOid);
}

void GLAPIENTRY MessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
		type, severity, message);
}