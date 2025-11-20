//#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/freeglut.h>
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
void initVBO();
void cleanup();
	
GLuint VBOid;

GLfloat vertices[] = {
	//Triangle
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

	//Cube

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

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);

	glutCreateWindow("simple");

	glutDisplayFunc(displayObject);
	
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	
	GLenum err = glewInit();
	if (err == GLEW_OK) {
		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(MessageCallback, 0);
		printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
		printf("OpenGL vendor (%s): \n", glGetString(GL_VENDOR));


		initVBO();

		glutMainLoop();

	}

	cleanup();


}

void initVBO() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	//gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0,-5.0,5.0);
	
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



	glGenBuffers(1, &VBOid);
	glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	glBufferData(GL_ARRAY_BUFFER, ((9 * 4) + (12 * 6) + (9 * 4) + (12 * 6)) * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, ((9 * 4) + (12 * 6)) * sizeof(GLfloat), ((9 * 4) * sizeof(GLfloat)), colors);


	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, 0);
	glColorPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(((9 * 4) + (12 * 6)) * sizeof(GLfloat)));



	
}

void cleanup() {

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBOid);
}

void displayObject() {



	
	glClear(GL_DEPTH_BUFFER_BIT);

	//glPushMatrix();

	glRotatef(20.0f, 0.0, 1.0f, 0.0f); //triangle
	glDrawArrays(GL_TRIANGLES, 0, 12);
	glFlush();

	//glPopMatrix();
	

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







