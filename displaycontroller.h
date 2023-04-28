#ifndef DISPLAYCONTROLLER_H
#define DISPLAYCONTROLLER_H

#include <QObject>

enum MonitorState {
    ON = -1,
    OFF = 2,
    STANDBY = 1
};

class DisplayController: public QObject {
    Q_OBJECT
    HWND hwnd;
public:
    DisplayController();
    void Setup(HWND hwnd);
    void GetMonitorInformation();
    void SetTimeinterval(int timeInterval);
    void StartTimer();
    void StopTimer();
    void inhibitSystemBlanker();
    void uninhibitSystemBlanker();
    void AddInputEventHandler();
    bool RemoveInputEventHandler();
    void DisplayStandbyWithDelay(int timeInterval);
    void DisplayStandby();
private slots:
};

#endif // DISPLAYCONTROLLER_H
