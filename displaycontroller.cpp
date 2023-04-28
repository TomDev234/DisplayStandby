#include "displaycontroller.h"
#include <Windows.h>

#pragma comment(lib,"user32")

DisplayController::DisplayController() {

}

QTimer *timer;
int timeInterval;

void DisplayController::Setup(HWND hwnd) {
    this->hwnd = hwnd;
    ::timer = new QTimer(this);
    connect(::timer, &QTimer::timeout, this, &DisplayController::DisplayStandby);
}

void DisplayController::GetMonitorInformation() {
//    QList <QScreen *> screenList = QGuiApplication::screens();
//    const QList <QScreen *> &constScreenList = screenList;
//    for (QScreen *screen : constScreenList) {
//        qDebug("Manufacturer:%s",qPrintable(screen->manufacturer()));
//        qDebug("Model:%s",qPrintable(screen->model()));
//        qDebug("Name:%s",qPrintable(screen->name()));
//        qDebug("Size:%i*%i",screen->size().width(),screen->size().height());
//        qDebug("Depth:%i",screen->depth());
//        qDebug("Refreshrate:%f",screen->refreshRate());
//    }
}

void DisplayController::SetTimeinterval(int timeInterval) {
    ::timeInterval = timeInterval;
}

void DisplayController::StartTimer() {
    qDebug() << "Start Timer";
    ::timer->start(::timeInterval);
}

void ResetTimer() {
    ::timer->start(timeInterval);
}

void DisplayController::StopTimer() {
    ::timer->stop();
}

void DisplayController::inhibitSystemBlanker() {
    // SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);
}

void DisplayController::uninhibitSystemBlanker() {
    // SetThreadExecutionState(ES_CONTINUOUS);
}

HHOOK sHookKeyboard, sHookMouse;

long long HookProcedure (int i, WPARAM w, LPARAM l) {
    ::ResetTimer();
    return ::CallNextHookEx(sHookKeyboard, i, w, l);
}

void DisplayController::AddInputEventHandler() {
    sHookKeyboard = ::SetWindowsHookExA(WH_KEYBOARD_LL, HookProcedure, 0, 0);
    sHookMouse = ::SetWindowsHookExA(WH_MOUSE_LL, HookProcedure, 0, 0);
}

bool DisplayController::RemoveInputEventHandler() {
    bool result = UnhookWindowsHookEx(sHookKeyboard) && UnhookWindowsHookEx(sHookMouse);
    return result;
    return true;
}

void DisplayController::DisplayStandbyWithDelay(int timeInterval) {
    Sleep(timeInterval);
    DisplayStandby();
}

void DisplayController::DisplayStandby() {
    SendMessage(hwnd, WM_SYSCOMMAND, SC_MONITORPOWER, OFF);
}
