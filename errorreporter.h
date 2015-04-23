#ifndef ERRORREPORTER
#define ERRORREPORTER

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "standardpaths.h"

/**
 * @brief The ErrorReporter class is a tracker for errors durring the
 * execution of the application.
 * The reported errors get immediately saved in the error log of the application.
 *
 * @author Frank Loeffler
 */
class ErrorReporter
{
public:
    /**
     * @brief Reports a new error which occured durring the execution
     * of the application with the current date and time of the report and
     * the given error message.
     *
     * @param errorMessage
     *          The message of the error that should be reported.
     */
    static void reportError(const QString &errorMessage){
        QFile file(StandardPaths::errorLog());
        if(file.open(QIODevice::Append | QFile::Text)){
            QTextStream out(&file);
            out<<QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz")<<" "
              <<errorMessage<<"\n";
            file.close();
        }
    }

    /**
     * @brief Returns all entries/reported errors in the error log of the application
     * with the saved date and time of the report and the message.
     *
     * @return
     *      A list of all reported errors with the date time stamp.
     */
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

    /**
     * @brief Deletes the complete error log.
     */
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

