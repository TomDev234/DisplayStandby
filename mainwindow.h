#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userdefaults.h"
#include "displaycontroller.h"
#include "helpbook.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
    UserDefaults userDefaults;
    DisplayController displayController;
    HelpBook helpBook;
    Ui::MainWindow *ui;
    QString GetProgramDataName();
    bool ReadProgramData();
    bool WriteProgramData();
    void UpdateUserInterface();
    void SetupDisplayController();
    void ExitDisplayController();
    void SetupTableView();
    void SetupUserInterface();
    void HandleAutoStart();
    void closeEvent(QCloseEvent *event);
private slots:
    void on_standbyButton_clicked();
    void on_helpButton_clicked();
    void on_activateCheckBox_stateChanged(int arg1);
    void on_timeEdit_userTimeChanged(const QTime &time);
    void on_horizontalSlider_valueChanged(int value);
    void on_logoButton_clicked();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
