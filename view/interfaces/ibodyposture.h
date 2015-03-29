#ifndef IBODYPOSTURE
#define IBODYPOSTURE

#include <QtPlugin>

/**
 * @brief The IBodyPosture class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a body posture is provided.
 *
 * @author Frank Loeffler
 */
class IBodyPosture{

public slots:
    /**
     * @brief setBodyPosture Sets the body posture to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setBodyPosture(QHash<QString, QVariant> values) = 0;

signals:
    /**
     * @brief saveBodyPosture A signal that can be emitted to signal that a body posture with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveBodyPosture(QHash<QString, QVariant> values) = 0;
};

#define IBodyPosture_iid "IBodyPosture"
Q_DECLARE_INTERFACE(IBodyPosture, IBodyPosture_iid)

#endif // IBODYPOSTURE

