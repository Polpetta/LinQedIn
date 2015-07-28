#include "dbonfile.h"

DBonFile::DBonFile(const QString &nameFile)
    : QFile(nameFile)
{}

DBonFile::~DBonFile() {}
