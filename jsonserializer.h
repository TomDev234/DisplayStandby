#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

#include "jsonserializable.h"

class JsonSerializer
{
public:
    static QString Serialize(const JsonSerializable &object);
    static void Parse(const QString &json, JsonSerializable &jsonSerializable);
};

#endif // JSONSERIALIZER_H
