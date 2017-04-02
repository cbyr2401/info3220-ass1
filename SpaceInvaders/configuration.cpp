#include "configuration.h"


Configuration::Configuration(std::string path)
{
    // create the file stream for reading the file.
    std::ifstream infile(path);

    // check that the file exists.
    if(infile){
        std::cout << "File exists!" << std::endl;
    }else{
        std::cout << "File does not exist!" << std::endl;
        return;
    }

    m_path = path;

    // create temporary variables
    std::string tempsize;
    std::string tempstart;

    // read the next line into the temp variables
    std::getline(infile, tempsize);
    std::getline(infile, tempstart);

    // parse the files that were read in
    m_shipsize = tempsize;
    m_start_x = std::stoi(tempstart);

    int counter = 0;
    std::string line;

    // for each line, add to the array of "moves"
    //  move to next line.
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string move;
        if(!(iss >> move)) { break; }
        else { m_moves[counter++] = move; }
    }


}


std::string Configuration::shipSize() { return m_shipsize; }
int Configuration::startPosition() { return m_start_x; }
std::string Configuration::nextCommand() {
    if(m_moves[m_nextIndex] == "") m_nextIndex = 0;
    return m_moves[m_nextIndex++];
}
std::string Configuration::currentCommand() {
    return m_moves[m_nextIndex];
}
