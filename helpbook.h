#ifndef HELPBOOK_H
#define HELPBOOK_H

#include <QDialog>

namespace Ui {
    class HelpBook;
}

class HelpBook : public QDialog {
    Q_OBJECT
public:
    QWebEngineView webEngineView;
    explicit HelpBook(QWidget *parent = nullptr);
    ~HelpBook();
    void OpenHelpBook();
    void CloseHelpBook();
private:
    Ui::HelpBook *ui;
};

#endif // HELPBOOK_H
