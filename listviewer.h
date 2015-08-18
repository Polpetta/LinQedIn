#ifndef LISTVIEWER_H
#define LISTVIEWER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>

class listViewer : public QWidget
{
    Q_OBJECT

public:
    listViewer(QWidget * = nullptr);
    ~listViewer();

    void addLabel(QLabel*);
    void addLabel(const QString &);
    void clear();

    void changeLabel(const QString &, const QString &);

private:

    QVector<QLabel*> obj;
    QVBoxLayout* layout;
};

#endif // LISTVIEWER_H
