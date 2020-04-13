//
//  intervalfile.cpp
//
//
//  Created by Luka Mitrovic on 28/03/2020.
//  Copyright © 2020 Luka Mitrović. All rights reserved.
//

#include "intervalfile.h"

IntervalFile::IntervalFile(QString filename):
    ScryptFile(filename){

    removeNumeration();
    toAlphabeticalInterval();
    splitFileintoWords();
    removePaddings();
    removeBasicWordsFromFile();
    toIntrervatFormatFile();
    makeIntervalmap();
    intervalIterator = intervalmap.begin();
}


void IntervalFile::toAlphabeticalInterval(){
    std::ifstream readFile (this->filename.toStdString(), std::ifstream::in);
    std::ofstream tmpFile ("/Users/luca/Qt/Examples/Qt-5.14.1/multimediawidgets/player/tmp.txt", std::ofstream::out);

    std::string str;
    while(readFile){
        getline(readFile,str);
        for(unsigned int i = 0; i < str.size(); ++i)
        {
            if (!((str[i] >= 'a' && str[i]<='z') || (str[i] >= 'A' && str[i]<='Z') || (str[i] == ':') || (str[i] >= '0' && str[i]<='9') )){
                str[i] = ' ';
            }
        }
        tmpFile << str;
        tmpFile << std::endl;
    }
    readFile.close();
    tmpFile.close();
    rewriteFile();
}


void IntervalFile::toIntrervatFormatFile(){
    std::ifstream readFile(this->filename.toStdString(),std::ifstream::in);
    std::ofstream tmpFile("/Users/luca/Qt/Examples/Qt-5.14.1/multimediawidgets/player/tmp.txt", std::ofstream::out);
    std::string str;
    while(readFile){
        std::getline(readFile, str);
        if(str[0] == '0'){

            std::getline(readFile, str);
            std::getline(readFile, str);

            tmpFile << str;
            tmpFile << std::endl;
            std::getline(readFile, str);
        }
        else {
            tmpFile << str;
            tmpFile << std::endl;}
    }
    readFile.close();
    tmpFile.close();
    rewriteFile();
}

void IntervalFile::makeIntervalmap(){
    std::ifstream readFile(this->filename.toStdString() ,std::ifstream::in);
    std::string str;
    std::string previousKey;

    while(readFile){
        std::getline(readFile, str);
        if(str[0] == '0'){
            previousKey = str;
            intervalmap[str];
        }
        else {
            IntervalMap::iterator it = intervalmap.find(previousKey);
            if (it != intervalmap.end())
                it->second.push_back(str);
            }
    }
}

IntervalMap IntervalFile::getIntervalMap(){
    return intervalmap;
}

void IntervalFile::getNextInterval(){
    this->intervalIterator++;
}
std::vector<std::string> IntervalFile::getIntervalWords(IntervalMap::iterator intervalIterator){
  return intervalIterator->second;
}
