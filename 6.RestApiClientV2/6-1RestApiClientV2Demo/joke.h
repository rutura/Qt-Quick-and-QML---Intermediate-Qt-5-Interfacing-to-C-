#ifndef JOKE_H
#define JOKE_H

#include <QObject>

class Joke : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString joke READ joke WRITE setJoke NOTIFY jokeChanged)
public:
    explicit Joke(const QString & joke, QObject *parent = nullptr);

    QString joke() const;

    void setJoke(QString joke);

signals:
    void jokeChanged(QString joke);

private :
    QString m_joke;
};

#endif // JOKE_H
