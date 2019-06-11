#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H
#include <QObject>

class ClickableLabel : public QObject
{
    Q_OBJECT
public:
    explicit ClickableLabel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CLICKABLELABEL_H
