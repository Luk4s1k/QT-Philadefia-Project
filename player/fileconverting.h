#ifndef FILECONVERTING_H
#define FILECONVERTING_H

#include  <stdio.h>
#include  <fstream>
#include  <vector>
#include  <map>
#include  <string>

#include  <QString>

typedef std::map<std::string, int> StrIntMap;
typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;


class ScryptFile {
public:

    QString filename;
    QString basicWordsListFile;
    std::vector<std::string> words;
    unsigned int difficulty;
    StrIntMap map;
private:
    std::vector<std::string> signalWords;

public:
    ScryptFile();
    ScryptFile(QString filename);
    ScryptFile(QString filename, unsigned int difficulty);

    void createWordVector();
    void createSignalWords(unsigned int positions);
    void makeparsedFile();
    void makeNonSortedHashOfWords();
    void rewriteFile();
    void removeSpaces();
    void removePaddings();
    void removeNumeration();
    void removeUnwantedWord(std::string Word);
    void removeBasicWordsFromFile();
    void splitFileintoWords();
    void toAlphabetical();

    std::vector<std::string> getSignalWords();

};


#endif // FILECONVERTING_H
