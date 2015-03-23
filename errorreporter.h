#ifndef ERRORREPORTER
#define ERRORREPORTER

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "standardpaths.h"

class ErrorReporter
{
public:
    static void reportError(const QString &errorMessage){
        QFile file(StandardPaths::errorLog());
        if(file.open(QIODevice::Append | QFile::Text)){
            QTextStream out(&file);
            out<<QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz")<<" "
              <<errorMessage<<"\n";
            file.close();
        }
    }

    static QStringList getErrorLog(){
        QFile file(StandardPaths::errorLog());
        QStringList lines = QStringList();
        if(file.open(QIODevice::ReadOnly)){
            QTextStream in(&file);
            while(!in.atEnd())
                lines.append(in.readLine());
            file.close();
        }
        return lines;
    }

    static void clearErrorLog(){
        QFile file(StandardPaths::errorLog());
        if(file.open(QIODevice::WriteOnly)){
            QTextStream out(&file);
            out<<"";
            file.close();
        }
    }
};

#endif // ERRORREPORTER

