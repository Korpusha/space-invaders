#include "headers/Record.h"

Record::Record(const std::string& name_, unsigned int value_)
{
    this->setName(name_);
    this->setValue(value_);
}

const std::string& Record::getName() const
{
    return this->name;
}

unsigned int Record::getValue() const
{
    return this->value;
}

void Record::setName(const std::string& name_)
{
    this->name = name_;
}

void Record::setValue(unsigned int value_)
{
    this->value = value_;
}

std::vector<Record> Record::loadFromFile()
{
    std::vector<Record> records = std::vector<Record> {};
    std::ifstream fin(StaticManager::getScores());

    if (!fin.is_open()) {
        return records;
    }

    std::string n, v;
    while (std::getline(fin, n, ';') && std::getline(fin, v, '\n')) {
        Record record = Record { n, stoul(v) };
        records.emplace_back(record);
    }

    fin.close();

    return records;
}

void Record::loadToFile(std::vector<Record>& records)
{
    std::ofstream fout(StaticManager::getScores());

    if (!fout.is_open()) {
        fout.close();
        return;
    }

    for (int i = 0; i < records.size() && i < Record::MAX_RECORDS; ++i) {
        fout << records[i] << std::endl;
    }

    fout.close();
}

void Record::appendToFile(const Record& record)
{
    std::vector<Record> records = Record::loadFromFile();
    records.push_back(record);
    std::sort(records.begin(), records.end());
    Record::loadToFile(records);
}

bool Record::operator<(Record &record)
{
    return this->getValue() > record.getValue();
}

std::ofstream &operator<<(std::ofstream &fout, Record &record)
{
    fout << record.getName() << ";" << std::to_string(record.getValue());
    return fout;
}

std::ostream &operator<<(std::ostream &out, Record &record)
{
    out << std::setfill('.') << std::left << std::setw(15) << record.getName()
        << std::setfill('.') << std::right << std::setw(5) << record.getValue();
    return out;
}

bool Record::operator==(const Record &record) const
{
    return record.getName() == this->getName() && record.getValue() == this->getValue();
}
