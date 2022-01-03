#include "joke.h"

Joke::Joke(const QString & joke,QObject *parent) : QObject(parent),
    m_joke(joke)
{

}

QString Joke::joke() const
{
    return m_joke;
}

void Joke::setJoke(QString joke)
{
    if (m_joke == joke)
        return;

    m_joke = joke;
    emit jokeChanged(m_joke);
}
