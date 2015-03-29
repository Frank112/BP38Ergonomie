#ifndef IACTIVITY_H
#define IACTIVITY_H

#include <QtPlugin>

/**
 * @brief The IActivity class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving an activity is provided.
 *
 * @author Marius Gassen
 */
class IActivity {

signals:

    /**
     * @brief saveActivity A signal that can be emitted to signal that an activity with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveActivity(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setActivity Sets the activity to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column as specified in the application's database.
     */
    virtual void setActivity(QHash<QString, QVariant> values) = 0;
};

#define IActivity_iid "IActivity"
Q_DECLARE_INTERFACE(IActivity, IActivity_iid)

#endif // IACTIVITY_H
