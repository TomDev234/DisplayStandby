#include "userdefaults.h"

void UserDefaults::Read(const QJsonObject &jsonObject) {
    this->activate = jsonObject["activate"].toBool();
    this->runAtStartup = jsonObject["runAtStartup"].toBool();
    this->startHidden = jsonObject["hidden"].toBool();
    this->timeInterval = jsonObject["timeInterval"].toInt();
}

void UserDefaults::Write(QJsonObject &jsonObject) const {
    jsonObject["activate"] = this->activate;
    jsonObject["runAtStartup"] = this->runAtStartup;
    jsonObject["hidden"] = this->startHidden;
    jsonObject["timeInterval"] = this->timeInterval;
}
