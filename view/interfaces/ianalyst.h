#ifndef IANALYST
#define IANALYST

#include <QtPlugin>

/**
 * @brief The IAnalyst class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving an analyst is provided.
 *
 * @author Markus Danz
 */
class IAnalyst {

public slots:
    /**
     * @brief setAnalyst Sets the analyst to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setAnalyst(QHash<QString, QVariant> values) = 0;

signals:
    /**
     * @brief saveAnalyst A signal that can be emitted to signal that an analyst with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveAnalyst(QHash<QString, QVariant> values) = 0;
};

#define IAnalyst_iid "IAnalyst"
Q_DECLARE_INTERFACE(IAnalyst, IAnalyst_iid)

#endif // IANALYST

