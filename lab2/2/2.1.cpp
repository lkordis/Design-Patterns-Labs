#include "iostream"
#include <assert.h>
#include "cstdlib"

struct Point
{
    int x;
    int y;
};
struct Shape
{
    enum EType
    {
        circle,
        square
    };
    EType type_;
};
struct Circle
{
    Shape::EType type_;
    double radius_;
    Point center_;
};
struct Square
{
    Shape::EType type_;
    double side_;
    Point center_;
};
void drawSquare(struct Square *)
{
    std::cerr << "in drawSquare\n";
}
void drawCircle(struct Circle *)
{
    std::cerr << "in drawCircle\n";
}
void moveSquare(struct Square*, int x, int y)
{
    std::cout << "moving square for x:" << x << " ,y:" << y << "\n";
}
void moveCircle(struct Circle*, int x, int y)
{
    std::cout << "moving circle for x:" << x << " ,y:" << y << "\n";
}
void drawShapes(Shape **shapes, int n)
{
    for (int i = 0; i < n; ++i)
    {
        struct Shape *s = shapes[i];
        switch (s->type_)
        {
        case Shape::square:
            drawSquare((struct Square *)s);
            break;
        case Shape::circle:
            drawCircle((struct Circle *)s);
            break;
        default:
            assert(0);
            exit(0);
        }
    }
}
void moveShapes(Shape **shapes, int n, int x, int y)
{
    for (int i = 0; i < n; ++i)
    {
        struct Shape *s = shapes[i];
        switch (s->type_)
        {
            case Shape::square:
                moveSquare((struct Square*)s,x,y);
                break;
            case Shape::circle:
                moveCircle((struct Circle*)s,x,y);
                break;
            default:
                assert(0);
                exit(0);
        }
    }
}

int main()
{
    Shape *shapes[4];
    shapes[0] = (Shape *)new Circle;
    shapes[0]->type_ = Shape::circle;
    shapes[1] = (Shape *)new Square;
    shapes[1]->type_ = Shape::square;
    shapes[2] = (Shape *)new Square;
    shapes[2]->type_ = Shape::square;
    shapes[3] = (Shape *)new Circle;
    shapes[3]->type_ = Shape::circle;

    drawShapes(shapes, 4);
    moveShapes(shapes, 4, 2, 3);
}