#include <gl/glut.h>

const int SUBDIVISION = 100;

class Point2f{
public:
	Point2f(GLfloat inputX, GLfloat inputY);
	GLfloat getX();
	GLfloat getY();
	void setX(GLfloat);
	void setY(GLfloat);
private:
	GLfloat x;
	GLfloat y;
};

void calcInterpolation(Point2f& p1,
					  Point2f& p2,
					  Point2f& p3,
					  Point2f& p4,
					  float s,
					  float u,
					  Point2f& result);

void CardinalCurve(float tension);
void drawCardinal();
void drawPoints();