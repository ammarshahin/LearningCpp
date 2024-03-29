/**** Polymorphism Lesson **********/

#include <iostream>
using namespace std;

/**************** ShapeClass ******************/
class Shape
{
  protected:
    /* The Object(Class) Data */
    uint32_t l, w;

  public:
    /* The Object(Class) Constructors */
    Shape()   // Empty Constructor(default Constructor)
    {
        this->l = 0;
        this->w = 0;
    }

    Shape(uint32_t l, uint32_t w)
    {
        this->l = l;
        this->w = w;
    }

    /* The Object(Class) Methods */
    virtual double area() = 0;   // (Overriding)Now the Shape Class is an Abstract Class {We Can't make any objects from the Shape class}

    void setLength(uint32_t l)
    {
        this->l = l;
    }

    void setWidth(uint32_t w)
    {
        this->w = w;
    }

    uint32_t getLength()
    {
        return this->l;
    }

    uint32_t getWidth()
    {
        return this->w;
    }

    /* The Object(Class) Destructor */
    ~Shape()
    {
    }
};

/**************** RectClass ******************/
class RectClass : public Shape   // RectClass is now inherited the Shape attributes (l & w)
{
  public:
    /* The Object(Class) Constructors */
    RectClass()
        : Shape()
    {
    }   // Empty Constructor

    RectClass(uint32_t l, uint32_t w)
        : Shape(l, w)
    {
    }

    /* The Object(Class) Methods */
    double area() override   // Overriding [This method will override the inherited area method]
    {
        return (double)this->l * this->w;
    }

    /* The Object(Class) Destructor */
    ~RectClass()
    {
    }
};

/**************** TriClass ******************/
class TriClass : public Shape
{
  public:
    /* The Object(Class) Constructors */
    TriClass()
        : Shape()
    {
    }   // Empty Constructor

    TriClass(uint32_t l, uint32_t w)
        : Shape(l, w)
    {
    }

    /* The Object(Class) Methods */
    double area() override   // Overriding [This method will override the inherited area method]
    {
        return (double)0.5 * this->l * this->w;
    }

    /* The Object(Class) Destructor */
    ~TriClass()
    {
    }
};

int main()
{
    /* "new" is an operator that creates an object */
    Shape *sp = new RectClass(10, 20);   // sp is a Pointer that points to Shape Class or any Child of it (Polymorphism)
    cout << "Rectangle area = " << sp->area() << endl;

    sp = new TriClass(10, 20);
    cout << "Circle area = " << sp->area() << endl;

    return 0;
}
