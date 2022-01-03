#ifndef APPWRAPPER_H
#define APPWRAPPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QQmlApplicationEngine>

class AppWrapper : public QObject
{
    Q_OBJECT
public:
    explicit AppWrapper(QObject *parent = nullptr);

    Q_INVOKABLE void fetchPosts( int number);

    Q_INVOKABLE void removeLast();

    QStringList jokes() const;

    bool initialize();

signals:

public slots:
private slots:
    void dataReadyRead();
    void dataReadFinished();

private:

    void resetModel () ;

    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
    QStringList mJokes;

    QQmlApplicationEngine mEngine;

};

#endif // APPWRAPPER_H
