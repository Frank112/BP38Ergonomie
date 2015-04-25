#ifndef IRECORDING
#define IRECORDING

#include <QtPlugin>

/**
 * @brief The IRecording class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a recording is provided.
 *
 * @author Marius Gassen
 */
class IRecording {

signals:

    /**
     * @brief saveRecording A signal that can be emitted to signal that a recirdubg with the given <i>values</i> should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveRecording(QHash<QString, QVariant> values) = 0;

public slots:

    /**
     * @brief setRecording Sets the recording to be displayed specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setRecording(QHash<QString, QVariant> values) = 0;
};


#define IRecording_iid "IRecording"
Q_DECLARE_INTERFACE(IRecording, IRecording_iid)

#endif // IRECORDING

