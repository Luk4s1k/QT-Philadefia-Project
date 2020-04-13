#ifndef INTERVALFILE_H
#define INTERVALFILE_H

#include "fileconverting.h"

#include <stdio.h>
#include <fstream>
#include <vector>
#include <map>
#include <string>

typedef std::map<std::string,std::vector<std::string>> IntervalMap;

class IntervalFile : public ScryptFile{
public:
    IntervalMap intervalmap;
    IntervalMap::iterator intervalIterator;

public:
    IntervalFile(QString filename);
    void makeIntervalmap();
    void toIntrervatFormatFile();
    void toAlphabeticalInterval();

    IntervalMap getIntervalMap();
    void getNextInterval();
    std::vector<std::string> getIntervalWords(IntervalMap::iterator intervalIterator);
};

#endif // INTERVALFILE_H
