#ifndef FILEGENERATOR_H
#define FILEGENERATOR_H

#include <utility>
#include <QString>

class QFile;
struct Config;

enum class FileStatus
{
    OPEN,
    CLOSED
};

enum class GenerationCase
{
    MATCHING_NAME, // Имя файла соответствует маске
    UNMATCHING_NAME, // Имя файла не соответствует маске
    FIXED_MATCHING_NAME // Имя файла соответствует маске, но является фиксированным(для симуляции ситуации с одинаковыми именами файлов)
};


class FileGenerator
{
    static std::pair<FileStatus, GenerationCase> generateCondition();

    static QString generateDataString();

    static QString generateFileName(const Config* _config, GenerationCase _gcase);

public:

    static QFile* generate(const Config* _config);
};


#endif // FILEGENERATOR_H
