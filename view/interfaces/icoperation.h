#ifndef ICOPERATION
#define ICOPERATION

#include <QtPlugin>

/**
 * @brief The ICorperation class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a corporation is provided.
 *
 * @author Frank Loeffler
 */
class ICorperation {

signals:
    /**
     * @brief saveCorperation A signal that can be emitted to signal that a corporation with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveCorperation(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setCorporation Sets the corporation to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setCorporation(QHash<QString, QVariant> values) = 0;
};


#define ICorperation_iid "ICorperation"
Q_DECLARE_INTERFACE(ICorperation, ICorperation_iid)

#endif // ICOPERATION

