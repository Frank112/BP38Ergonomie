#ifndef COMMENTVIEW_H
#define COMMENTVIEW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "../textlineedit.h"
#include "../textedit.h"
#include "../navigation/simplenavigateablewidget.h"
#include "../interfaces/icomment.h"
#include "../../databaseHandler/dbconstants.h"

/**
 * @brief The CommentView class provides funtionality to display and save comments for a workplace in a form.
 *
 * CommentView inherits SimpleNavigateableWidget and implements IComment.
 *
 * @author Frank Loeffler
 */
class CommentView : public SimpleNavigateableWidget, IComment
{
    Q_OBJECT
    Q_INTERFACES(IComment)
public:
    /**
     * @brief CommentView Creates a new CommentView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit CommentView(QWidget *parent = 0);
    ~CommentView();

signals:
    void saveComment(QHash<QString, QVariant> values);

public slots:
    void setComment(QHash<QString, QVariant> values);
    void onLeaving();

private:
    QLabel *lblProblem;
    QLabel *lblProblemName;
    QLabel *lblProblemDescription;
    QLabel *lblMeasure;
    QLabel *lblMeasureName;
    QLabel *lblMeasureDescription;
    QLabel *lblWorkerPerception;
    QLabel *lblWorkerPerceptionDescription;

    TextLineEdit *txtBxProblemName;
    TextEdit *txtBxProblemDescription;
    TextLineEdit *txtBxMeasureName;
    TextEdit *txtBxMeasureDescription;
    TextEdit *txtBxPerceptionDescription;
};

#endif // COMMENTVIEW_H
