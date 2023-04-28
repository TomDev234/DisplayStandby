#ifndef JSONSERIALIZABLE_H
#define JSONSERIALIZABLE_H

class JsonSerializable
{
public:
    virtual ~JsonSerializable() {}
    virtual void Read(const QJsonObject &jsonObject) = 0;
    virtual void Write(QJsonObject &jsonObject) const = 0;
};

#endif // JSONSERIALIZABLE_H
