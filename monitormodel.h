#ifndef MONITORMODEL_H
#define MONITORMODEL_H

#include <QAbstractTableModel>
#include <QObject>

typedef QMap <QString,QString> MonitorDataMap;
typedef QList <MonitorDataMap> MonitorDataList;

class MonitorModel : public QAbstractTableModel {
    Q_OBJECT
    MonitorDataList mm_monitor_data_list;
public:
    explicit MonitorModel(QObject *parent = nullptr);
    void populateModel(const QList <QMap<QString,QString>> &monitorData);
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
};

#endif // MONITORMODEL_H
