#include "MainWindow.h"
/*********************************************************************
//Cardinal Curve
//Author: Competed by Yang Yang (NO.SA13226226).
//Date: Dec 7th, 2013.
//Course: Advanced Computer Graphic in USTC.
*********************************************************************/

Point2f point[] = {
	Point2f( -0.9f, 0.6f ),
	Point2f( -0.5f, 0.1f ),
	Point2f( -0.1f, 0.7f ),
	Point2f( 0.1f, 0.4f ),
	Point2f( 0.5f, -0.8f ),
	Point2f( 0.9f, -0.2f )
};

Point2f result( 0.0f, 0.0f);

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("cardinalÇúÏß");
	glutDisplayFunc(drawCardinal);
	glutMainLoop();
	return 0;
}

Point2f::Point2f(GLfloat inputX, GLfloat inputY){
	this ->x = inputX;
	this ->y = inputY;
}

GLfloat Point2f::getX(){
	return this ->x;
}

GLfloat Point2f::getY(){
	return this ->y;
}

void Point2f::setX(GLfloat newX){
	this ->x = newX;
}

void Point2f::setY(GLfloat newY){
	this ->y = newY;
}

void calcInterpolation(Point2f& p1,
					  Point2f& p2,
					  Point2f& p3,
					  Point2f& p4,
					  float s,
					  float u,
					  Point2f& result){
	float u2 = u * u;
	float u3 = u2 * u;
	result.setX(p1.getX()*(2*s*u2-s*u3-s*u)
		+p2.getX()*((2-s)*u3+(s-3)*u2+1)
		+p3.getX()*((s-2)*u3+(3-2*s)*u2+s*u)
		+p4.getX()*(s*u3-s*u2));
	result.setY(p1.getY()*(2*s*u2-s*u3-s*u)
		+p2.getY()*((2-s)*u3+(s-3)*u2+1)
		+p3.getY()*((s-2)*u3+(3-2*s)*u2+s*u)
		+p4.getY()*(s*u3-s*u2));
}

void CardinalCurve(float tension){
	float s =(1.0 - tension)/2.0;
	GLfloat step=1.0/(float)SUBDIVISION;
	glColor3f(0.0f,0.0f,1.0f);
	glBegin(GL_LINE_STRIP);
		float uValue;
		for(int i=0; i < 6; i++){
			uValue=0.0f;
			for(int j=0;j<SUBDIVISION;j++){
				calcInterpolation(point[i],
					point[(i+1)%6],
					point[(i+2)%6],
					point[(i+3)%6],
					s,
					uValue,
					result);
				glVertex2f(result.getX(),result.getY());
				uValue+=step;
			}
		}
	glEnd();
	glutSwapBuffers();
}

void drawCardinal(){
	glClear( GL_COLOR_BUFFER_BIT );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	CardinalCurve(0.0);
	drawPoints();
	glutSwapBuffers();
}

void drawPoints(){
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(4);
	glBegin(GL_POINTS);
	for(int i = 0; i< 6; i++)
		glVertex2f(point[i].getX(),point[i].getY());
	glEnd();
	glPointSize(1);
}