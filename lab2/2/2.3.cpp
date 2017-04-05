#include "iostream"
#include <assert.h>
#include "cstdlib"

class Point
{
  public:
    int x;
    int y;
};

class Shape
{
  public:
    virtual void draw() = 0;
    virtual void move(int x, int y) = 0;
};

class Circle : public Shape
{
  public:
    virtual void draw()
    {
        std::cerr << "in drawSquare\n";
    };
    virtual void move(int x, int y)
    {
        std::cout << "moving square for x:" << x << " ,y:" << y << "\n";
    }

  private:
    double radius_;
    Point center_;
};
class Square : public Shape
{
  public:
    virtual void draw()
    {
        std::cerr << "in drawCircle\n";
    };
    virtual void move(int x, int y)
    {
        std::cout << "moving square for x:" << x << " ,y:" << y << "\n";
    };

  private:
    double side_;
    Point center_;
};
class Rhomb : public Shape
{
  public:
    virtual void draw()
    {
        std::cerr << "in drawRhomb\n";
    };
    virtual void move(int x, int y)
    {
        std::cout << "moving rhomb for x:" << x << " ,y:" << y << "\n";
    };
  private:
    double side_;
    Point center_;
};

void drawShapes(Shape **shapes, int n)
{
    for (int i = 0; i < n; ++i)
    {
        Shape *s = shapes[i];
        s->draw();
    }
}
void moveShapes(Shape **shapes, int n, int x, int y)
{
    for (int i = 0; i < n; ++i)
    {
        Shape *s = shapes[i];
        s->move(x,y);
    }
}

int main()
{
    Shape *shapes[5];
    shapes[0] = new Circle();
    shapes[1] = new Square();
    shapes[2] = new Square();
    shapes[3] = new Circle();
    shapes[4] = new Rhomb();

    drawShapes(shapes, 5);
    moveShapes(shapes, 5, 2, 3);
}