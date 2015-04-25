#ifndef ILOADHANDLING
#define ILOADHANDLING

#include <QtPlugin>
/**
 * @brief The ILoadHandling class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving an load handling is provided.
 *
 * @author Frank Loeffler
 */
class ILoadHandling{

signals:

    /**
     * @brief saveLoadHandling A signal that can be emitted to signal that a load handling with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveLoadHandling(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setLoadHandling Sets the load handling to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setLoadHandling(QHash<QString, QVariant> values) = 0;

};

#define ILoadHandling_iid "ILoadHandling"
Q_DECLARE_INTERFACE(ILoadHandling, ILoadHandling_iid)

#endif // ILOADHANDLING

