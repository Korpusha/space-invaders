#ifndef SPACE_INVADERS_RECORD_H
#define SPACE_INVADERS_RECORD_H


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

class Record {
private:
    std::string name;
    unsigned int value;
    static const std::string RECORDS_PATH;
    static const unsigned int MAX_RECORDS;
private:
    void setName(const std::string& name_);
    void setValue(unsigned int value_);
    void static loadToFile(std::vector<Record>& records);
public:
    Record() = delete;
    Record(const std::string& name_, unsigned int value_);
    const std::string& getName();
    unsigned int getValue();
    static std::vector<Record> loadFromFile();
    static void appendToFile(const Record& record);
    bool operator<(Record& record);
    bool operator==(Record& record);
    friend std::ofstream& operator<<(std::ofstream& fout, Record& record);
    friend std::ostream& operator<<(std::ostream& out, Record& record);
};


#endif
