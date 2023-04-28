#include "messagebox.h"

void MessageBox::Show(QString message) {
    QMessageBox messageBox;
    messageBox.setText(message);
    messageBox.exec();
}
