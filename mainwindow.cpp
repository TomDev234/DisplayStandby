#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "monitormodel.h"
#include "jsonserializer.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    if (!ReadProgramData())
        MessageBox::Show("ReadProgramData Error!");
    SetupDisplayController();
    SetupTableView();
    SetupUserInterface();
    UpdateUserInterface();
    statusBar()->showMessage(tr("Ready"));
}

MainWindow::~MainWindow() {
    ExitDisplayController();
    if (!WriteProgramData())
        MessageBox::Show("WriteProgramData Error!");
    delete ui;
}

QString MainWindow::GetProgramDataName() {
    QString applicationName = QFileInfo(QCoreApplication::applicationFilePath()).baseName();
    QString fileName = applicationName + ".json";
    return fileName;
}

bool MainWindow::ReadProgramData() {
    bool result = true;
    QFile file(GetProgramDataName());
    QTextStream textStream;
    QString json;
    if (file.open(QIODevice::ReadOnly)) {
       QTextStream textStream(&file);
       json = textStream.readAll();
       result =  textStream.status() == QTextStream::Ok;
       file.close();
       if (result)
          JsonSerializer::Parse(json,userDefaults);
       if (userDefaults.timeInterval < 60 * 1000)
           userDefaults.timeInterval = 60 * 1000;
    }
    return result;
}

bool MainWindow::WriteProgramData() {
    bool result = false;
    QFile file(GetProgramDataName());
    if (file.open(QIODevice::WriteOnly)) {
       QString json = JsonSerializer::Serialize(userDefaults);
       QTextStream textStream(&file);
       textStream << json;
       result =  textStream.status() == QTextStream::Ok;
       file.close();
    }
    return result;
}

void MainWindow::UpdateUserInterface() {
    if (userDefaults.activate)
        ui->activateCheckBox->setCheckState(Qt::Checked);
    else
        ui->activateCheckBox->setCheckState(Qt::Unchecked);
    ui->horizontalSlider->setSliderPosition(userDefaults.timeInterval / 1000 / 60);
}

void MainWindow::SetupDisplayController() {
    HWND hwnd = HWND(winId());
    displayController.Setup(hwnd);
    displayController.GetMonitorInformation();
    if (userDefaults.activate)
        displayController.AddInputEventHandler();
    displayController.SetTimeinterval(userDefaults.timeInterval);
    if (userDefaults.activate)
        displayController.StartTimer();
    // displayController.inhibitSystemBlanker();
}

void MainWindow::ExitDisplayController() {
    // displayController.uninhibitSystemBlanker();
}

void MainWindow::SetupTableView() {
    QList <QScreen *> screenList = QGuiApplication::screens();
    MonitorDataMap monitor_data;
    MonitorDataList monitor_data_list;
    const QList <QScreen *> &constScreenList = screenList;
    for (const QScreen *screen : constScreenList) {
        monitor_data["Manufacturer"] = screen->manufacturer(); // empty on Windows
        monitor_data["Model"] = screen->model(); // empty on Windows
        monitor_data["Name"] = screen->name();
        monitor_data["Size"] = QStringLiteral("%1*%2").arg(screen->size().width()).arg(screen->size().height());
        monitor_data["Depth"] = QStringLiteral("%1").arg(screen->depth());
        monitor_data["Refreshrate"] = QStringLiteral("%1").arg(screen->refreshRate());
        monitor_data_list.append(monitor_data);
    }
    MonitorModel *monitorModel = new MonitorModel(this);
    monitorModel->populateModel(monitor_data_list);
    ui->tableView->setModel(monitorModel);
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();
}

void MainWindow::SetupUserInterface() {
    ui->logoButton->setStyleSheet("border-image:url(:/Banner.png);");
    ui->label->setText(VERSIONSTRING);
}

void MainWindow::HandleAutoStart() {
    QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    if (userDefaults.runAtStartup) {
        QString applicationFilePath = QCoreApplication::applicationFilePath();
        QString apostroph = "\"";
        qDebug() << applicationFilePath;
        applicationFilePath.replace("/","\\");
        applicationFilePath = apostroph + applicationFilePath + apostroph + " --argument";
        qDebug() << applicationFilePath;
        settings.setValue("name", applicationFilePath);
    }
    else {
        settings.remove("name");
    }
}

void MonitorModel::populateModel(const QList <QMap<QString,QString>> &monitor_data_list) {
    mm_monitor_data_list.clear();
    mm_monitor_data_list = monitor_data_list;
    return;
}

int MonitorModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return mm_monitor_data_list.length();
}

int MonitorModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 6;
}

QVariant MonitorModel::data(const QModelIndex &index, int role) const {
    QVariant result;
    if (!index.isValid() || role != Qt::DisplayRole) {
        result = QVariant();
    }
    else if (index.column() == 0) {
        result = mm_monitor_data_list[index.row()]["Manufacturer"];
    }
    else if (index.column() == 1) {
        result = mm_monitor_data_list[index.row()]["Model"];
    }
    else if (index.column() == 2) {
        result = mm_monitor_data_list[index.row()]["Name"];
    }
    else if (index.column() == 3) {
        result = mm_monitor_data_list[index.row()]["Size"];
    }
    else if (index.column() == 4) {
        result = mm_monitor_data_list[index.row()]["Depth"];
    }
    else if (index.column() == 5) {
        result = mm_monitor_data_list[index.row()]["Refreshrate"];
    }
    else
        result = QVariant();
    return result;
}

QVariant MonitorModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Manufacturer");
        }
        else if (section == 1) {
            return QString("Model");
        }
        else if (section == 2) {
            return QString("Name");
        }
        else if (section == 3) {
            return QString("Size");
        }
        else if (section == 4) {
            return QString("Depth");
        }
        else if (section == 5) {
            return QString("Refreshrate");
        }
    }
    return QVariant();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    helpBook.CloseHelpBook();
    event->accept();
}

void MainWindow::on_standbyButton_clicked() {
    statusBar()->showMessage(tr("DisplayStandbyWithDelay"));
    displayController.DisplayStandbyWithDelay(1000);
}

void MainWindow::on_helpButton_clicked() {
    statusBar()->showMessage(tr("OpenHelpBook"));
    helpBook.OpenHelpBook();
}

void MainWindow::on_activateCheckBox_stateChanged(int arg1) {
    userDefaults.activate = arg1 == Qt::Checked;
    if (userDefaults.activate) {
        displayController.AddInputEventHandler();
        displayController.StartTimer();
    }
    else {
        displayController.RemoveInputEventHandler();
        displayController.StopTimer();
    }
}

void MainWindow::on_timeEdit_userTimeChanged(const QTime &time) {
    ui->horizontalSlider->setSliderPosition(time.hour() * 60 + time.minute());
}

void MainWindow::on_horizontalSlider_valueChanged(int value) {
    userDefaults.timeInterval = value * 60 * 1000;
    displayController.SetTimeinterval(userDefaults.timeInterval);
    if (userDefaults.activate)
        displayController.StartTimer();
    QTime time;
    int h = value / 60;
    int m = value - h * 60;
    time.setHMS(h, m, 0, 0);
    ui->timeEdit->setTime(time);
}

void MainWindow::on_logoButton_clicked() {
    if (!QDesktopServices::openUrl(QUrl("https://software-design-1.jimdosite.com/")))
        MessageBox::Show("Could not open URL Error!");
}
