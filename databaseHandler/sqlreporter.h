#ifndef SQLREPORTER
#define SQLREPORTER

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QSqlRecord>
#include <QSqlField>
#include "standardpaths.h"

class SqlReporter
{

private:
    static QString fieldValueToSqlString(QVariant::Type type, QVariant value){
        switch(type){
            case QVariant::Int:
            case QVariant::Double:
                return value.toString();
            case QVariant::Bool:
                return QString::number(value.toInt());
            default:
                return QString("'%1'").arg(value.toString());
        }

        return "";
    }

public:
    static void reportQuery(const QString &query){
        QFile file(StandardPaths::sqlLog());
        if(file.open(QIODevice::Append | QFile::Text)){
            QTextStream out(&file);
            out<<QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz")<<" "
              <<query<<"\n";
            file.close();
        }
    }

    static void reportInsertQuery(const QString &tblName, const QSqlRecord &record){
        QString absInsert = QString("INSERT INTO %1 (%2) VALUES (%3);").arg(tblName);
        QString valueNames = "";
        QString values = "";
        for(int i = 0; i < record.count(); ++i){
            QSqlField field = record.field(i);
            if(i != 0){
                valueNames.append(", ");
                values.append(", ");
            }
            valueNames.append(field.name());
            values.append(fieldValueToSqlString(field.type(), field.value()));
        }
        reportQuery(absInsert.arg(valueNames).arg(values));
    }

    static void reportUpdateQuery(const QString &tblName, const QSqlRecord &record, const QString &filter){
        QString absUpdate = QString("UPDATE %1 SET %2 %3;").arg(tblName);
        QString whereCondition = "";
        if(filter != "")
            whereCondition = QString("WHERE %1").arg(filter);
        QString set = "";
        for(int i = 0; i < record.count(); ++i){
            QSqlField field = record.field(i);
            if(i != 0)
                set.append(", ");
            set.append(QString("%1=%2").arg(field.name()).arg(fieldValueToSqlString(field.type(), field.value())));
        }
        reportQuery(absUpdate.arg(set).arg(whereCondition));
    }

    static void reportDeleteQuery(const QString &tblName, const QString &filter){
        QString absDeleteQuery = QString("DELETE FROM %1 %2;").arg(tblName);
        QString deleteQuery;
        if(filter == "")
            deleteQuery = absDeleteQuery.arg("");
        else
            deleteQuery = absDeleteQuery.arg(QString("WHERE %1").arg(filter));
        reportQuery(deleteQuery);
    }

    static QStringList getSqlLog(){
        QFile file(StandardPaths::sqlLog());
        QStringList lines = QStringList();
        if(file.open(QIODevice::ReadOnly)){
            QTextStream in(&file);
            while(!in.atEnd())
                lines.append(in.readLine());
            file.close();
        }
        return lines;
    }

    static void clearSqlLog(){
        QFile file(StandardPaths::sqlLog());
        if(file.open(QIODevice::WriteOnly)){
            QTextStream out(&file);
            out<<"";
            file.close();
        }
    }

};

#endif // SQLREPORTER

