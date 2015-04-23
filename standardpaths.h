#ifndef STANDARDPATHS_H
#define STANDARDPATHS_H

#include <QObject>
#include <QStandardPaths>

/**
 * @brief The StandardPaths class contains all file and/or directory paths
 * for the important files like the database. Also it contains the directory
 * with write permissions.
 *
 * <b>Note:</b> The class works platform independent.
 */
class StandardPaths
{   
public:
    /**
     * @brief Returns the directory of the writable location for the
     * application data.
     *
     * @return
     *        The absolute path to the directory with write permission.
     */
    static QString writeableLocation(){
        #if defined(Q_OS_ANDROID)
            return QString("%1").arg(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));
        #elif defined(Q_OS_IOS)
            return QString("%1").arg(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
        #else
            return QString("%1").arg(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));
        #endif
    }

    /**
     * @brief The path to the database file which gets deliverd with the application.
     *
     * <b>Note: </b>This is not the database file you are currently working with the application.
     * The file is also always located in a only readable location on the device.
     *
     * @return
     *        The absolute path to the original database file.
     */
    static QString originDatabasePath(){
        #if defined(Q_OS_IOS)
            return QString("%1/%2/%3").arg(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)).arg("Documents").arg("ergoAppDB.sqlite");
        #else
            return QString(":/assets/ergoAppDB.sqlite");
        #endif
    }

    /**
     * @brief Returns the path to the currently used database file in the application.
     *
     * @return
     *      The absolute path of the database file you are currently working with.
     */
    static QString databasePath(){
        return QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("ergoAppDB.sqlite");
    }

    /**
     * @brief Returns the directory where taken images are located.
     *
     * @return
     *      The absolute path to the directory with the taken images.
     */
    static QString imageDirectoryPath(){
        return QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("images");
    }

    /**
     * @brief Returns the path to the currently taken screenshot of the application.
     *
     * @return
     *      The absolute path to the last taken screenshot
     */
    static QString screenshotPath(){
        return QString("%1/%2").arg(StandardPaths::imageDirectoryPath()).arg("screenshot.png");
    }

    /**
     * @brief Returns the path to the directory for the XML import data download.
     *
     * @return
     *      The absolute path to the directory with the imported XML files.
     */
    static QString xmlDirectoryPath(){
        return QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("xmlData");
    }

    /**
     * @brief Returns the path to the configuration file of the application.
     *
     * @return
     *      The absolute path to the configuration file of the application.
     */
    static QString configFile(){
        return QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("config.txt");
    }

    /**
     * @brief Returns the path to the error log file of the application.
     *
     * @return
     *      The absolute path to the error log file of the application.
     */
    static QString errorLog(){
        return QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("error.log");
    }
};

#endif // STANDARDPATHS_H

