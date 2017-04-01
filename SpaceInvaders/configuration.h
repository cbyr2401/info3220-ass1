#ifndef CONFIGURATION_H
#define CONFIGURATION_H


#include <QString>

class Configuration
{
public:
    Configuration();
    ~Configuration();

private:
    QString m_moves[];
    int m_start_x;
    QString m_shipsize;
    QString m_path;
    void readFile(QString path);

};

#endif // CONFIGURATION_H
