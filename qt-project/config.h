#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

enum class OutputExist
{
    REWRITE,
    MODIFY_ADD_COUNTER
};

enum class FileMaskTypes
{
    REGULAR_EXPRESSION,
    FILE_EXTENSION,
    EXACT_FILENAME
};

enum class OperationTypes
{
    XOR,
    AND,
    OR,
    NOT
};

struct Config
{
    FileMaskTypes fileMaskType = FileMaskTypes::REGULAR_EXPRESSION;

    QString fileMask = "*";

    bool removeFiles = false;

    OutputExist outputExistBehavior = OutputExist::REWRITE;

    bool useTimer = false;

    uint timerInterval = 0;

    QString outputDirectory;

    OperationTypes operationType;

    quint64 bitmask;
};

#endif // CONFIG_H
