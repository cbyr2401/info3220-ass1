#ifndef BUILDER_H
#define BUILDER_H

#include <QString>
#include <QPixmap>


class Builder
{
public:
    Builder();
    ~Builder();
    //void buildPart();

private:
    int dx;
    int dy;
    int ds;
    QPixmap dmap;
    QString path;

};


#endif // BUILDER_H
