#include "jsonserializer.h"

QString JsonSerializer::Serialize(const JsonSerializable &object) {
    QJsonObject jsonObject;
    object.Write(jsonObject);
    QJsonDocument doc(jsonObject);
    QString result(doc.toJson(QJsonDocument::Indented));
    return result;
}

void JsonSerializer::Parse(const QString &json, JsonSerializable &jsonSerializable) {
    QJsonDocument document = QJsonDocument::fromJson(json.toUtf8());
    QJsonObject jsonObject = document.object();
    jsonSerializable.Read(jsonObject);
}
