#ifndef IWORKPROCESS
#define IWORKPROCESS

#include <QtPlugin>

/**
 * @brief The IWorkProcess class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a work process is provided.
 *
 * @author Frank Loeffler
 */
class IWorkProcess{

signals:

    /**
     * @brief saveWorkProcess A signal that can be emitted to signal that a work process with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveWorkProcess(QHash<QString, QVariant> values) = 0;

public slots:

    /**
     * @brief setWorkProcess Sets the work process to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setWorkProcess(QHash<QString, QVariant> values) = 0;

};

#define IWorkProcess_iid "IWorkProcess"
Q_DECLARE_INTERFACE(IWorkProcess, IWorkProcess_iid)

#endif // IWORKPROCESS

