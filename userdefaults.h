#ifndef USERDEFAULTS_H
#define USERDEFAULTS_H

#include "jsonserializable.h"

class UserDefaults : public JsonSerializable {
public:
    bool activate;
    bool runAtStartup;
    bool startHidden;
    int timeInterval;
    void Read(const QJsonObject &jsonObject);
    void Write(QJsonObject &jsonObject) const;
};

#endif // USERDEFAULTS_H
