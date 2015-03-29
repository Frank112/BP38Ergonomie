#ifndef ICOMMENT
#define ICOMMENT

#include <QtPlugin>
/**
 * @brief The IComment class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a comment is provided.
 *
 * @author Marius Gassen
 */
class IComment {
signals:
    /**
     * @brief saveComment A signal that can be emitted to signal that a comment with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveComment(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setComment Sets the comment to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setComment(QHash<QString, QVariant> values) = 0;
};

#define IComment_iid "IComment"
Q_DECLARE_INTERFACE(IComment, IComment_iid)

#endif // ICOMMENT

