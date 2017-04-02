#include "configuration.h"




Configuration::Configuration(std::string path)
{
    std::ifstream infile(path);

    m_path = path;

    std::string tempsize;
    std::string tempstart;

    infile >> tempsize;
    infile >> tempstart;

    m_shipsize = tempsize;
    m_start_x = std::stoi(tempstart);

    // check...
    std::cout << m_shipsize << std::endl;
    std::cout << std::to_string(m_start_x) << std::endl;

    int counter = 0;
    std::string line;

    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string move;
        if(!(iss >> move)) { break; }
        else { m_moves[counter++]; }
    }
}


std::string Configuration::shipSize() { return m_shipsize; }
int Configuration::startPosition() { return m_start_x; }
std::string Configuration::nextCommand() {
    return m_moves[m_nextIndex++];
}
