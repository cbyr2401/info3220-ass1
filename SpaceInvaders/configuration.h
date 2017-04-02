#ifndef CONFIGURATION_H
#define CONFIGURATION_H



#include <fstream>
#include <QString>
#include <iostream>
#include <sstream>
#include <string>

class Configuration
{
public:
    Configuration() {};
    ~Configuration() {}
    Configuration(std::string path);

    std::string nextCommand();
    int startPosition();
    std::string shipSize();



private:
    std::string m_moves[2000];
    int m_start_x;
    std::string m_shipsize;
    std::string m_path;
    int m_nextIndex = 0;
    //void readFile(QString path);

};

#endif // CONFIGURATION_H
