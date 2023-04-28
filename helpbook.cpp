#include "helpbook.h"
#include "ui_helpbook.h"

HelpBook::HelpBook(QWidget *parent) : QDialog(parent), ui(new Ui::HelpBook) {
    ui->setupUi(this);
}

HelpBook::~HelpBook() {
    delete ui;
}

void HelpBook::OpenHelpBook() {
    webEngineView.setUrl(QStringLiteral("qrc:/DisplayStandby.html"));
    webEngineView.resize(800, 500);
    webEngineView.show();
}

void HelpBook::CloseHelpBook() {
    webEngineView.close();
}
