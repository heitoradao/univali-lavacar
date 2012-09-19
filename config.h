#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

class Config
{
public:
    static Config* getInstance();
    double getTEC();
    double getTS();
    QString distribuicaoTS;
    QString distribuicaoTEC;

private:
    Config();
    static Config* instance;
};

#endif // CONFIG_H
