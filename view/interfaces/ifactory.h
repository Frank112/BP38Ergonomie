#ifndef IFACTORY
#define IFACTORY

#include <QtPlugin>
/**
 * @brief The IFactory class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving an factory is provided.
 *
 * @author Frank Loeffler
 */
class IFactory {

signals:
    /**
     * @brief saveFactory A signal that can be emitted to signal that a factory with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveFactory(QHash<QString, QVariant> values) = 0;

public slots:

    /**
     * @brief setFactory Sets the factory to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setFactory(QHash<QString, QVariant> values) = 0;
};


#define IFactory_iid "IFactory"
Q_DECLARE_INTERFACE(IFactory, IFactory_iid)

#endif // IFACTORY

