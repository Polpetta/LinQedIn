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
    void clear();

private:

    QVector<QLabel*> obj;
    QVBoxLayout* layout;
};

#endif // LISTVIEWER_H
