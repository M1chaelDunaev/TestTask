#include "filegenerator.h"
#include "config.h"
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>

std::pair<FileStatus, GenerationCase> FileGenerator::generateCondition()
{
    FileStatus status = static_cast<FileStatus>(QRandomGenerator::global()->bounded(0, 2));
    GenerationCase gcase = static_cast<GenerationCase>(QRandomGenerator::global()->bounded(0,3));

    return {status, gcase};
}

QString FileGenerator::generateFileName(const Config *_config, GenerationCase _gcase)
{
    // Генерация имени файла
    QString fileName;

    switch(_config->fileMaskType)
    {
    case FileMaskTypes::REGULAR_EXPRESSION:
    {
        if(_gcase == GenerationCase::MATCHING_NAME ||
            _gcase == GenerationCase::FIXED_MATCHING_NAME)
        {
            // Если маска является регулярным выражением, данное regex станет именнем файла
            fileName = _config->fileMask;
        }
        else
        {
            // Рандомное имя файла в формате ******.txt
            fileName = QString::number(QRandomGenerator::global()->bounded(111111, 999999)) + ".txt";
        }

        break;
    }
    case FileMaskTypes::FILE_EXTENSION:
    {
        if(_gcase == GenerationCase::MATCHING_NAME)
        {
            // Рандомное имя + маска файла
            fileName = QString::number(QRandomGenerator::global()->bounded(111111, 999999)) + _config->fileMask;
        }
        else if(_gcase == GenerationCase::UNMATCHING_NAME)
        {
            // Рандомное имя + рандомное расширение
            fileName = (QString::number(QRandomGenerator::global()->bounded(111111, 999999)) + "." +
                        QString::number(QRandomGenerator::global()->bounded(111111, 999999)));
        }
        else // FIXED_MATCHING_NAME
        {
            fileName = "fixed" + _config->fileMask;
        }

        break;
    }
    default: // EXACT_FILENAME
    {
        if(_gcase == GenerationCase::MATCHING_NAME ||
            _gcase == GenerationCase::FIXED_MATCHING_NAME)
        {
            fileName = _config->fileMask;
        }
        else
        {
            // Рандомное имя файла в формате ******.txt
            fileName = QString::number(QRandomGenerator::global()->bounded(111111, 999999)) + ".txt";
        }
    }
    } // Конец switch

    return fileName;
}

QFile* FileGenerator::generate(const Config *_config)
{
    auto condition = generateCondition();
    QString fileName = generateFileName(_config, condition.second);

    // Создаем файл
    QFile* file = new QFile("generated_inputs/" + fileName);
    file->open(QFile::WriteOnly);

    // Записываем данные
    QTextStream stream(file);
    stream << QString(256, '1'); // 256 символов '1'

    // Корректирем статус файла
    if(condition.first == FileStatus::OPEN)
        return file;

    file->close();
    return file;
}
