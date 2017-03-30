#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

class MovingObject
{
public:
    MovingObject(int x_position, int y_position);
    ~MovingObject();

    virtual int* getPosition(int * arr);

private:
    int dx;
    int dy;
protected:

};



#endif // MOVINGOBJECT_H
