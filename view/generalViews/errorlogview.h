#ifndef ERRORLOGVIEW_H
#define ERRORLOGVIEW_H

#include "../navigation/simplenavigateablewidget.h"
#include "../../errorreporter.h"
#include "../textedit.h"
#include <QPushButton>

/**
 * @brief The ErrorLogView class provides functionality to display reported error messages.
 *
 * ErrorLogView inherits SimpleNavigateableWidget.
 *
 * @author Frank Loeffler
 */
class ErrorLogView : public SimpleNavigateableWidget
{
    Q_OBJECT
public:
    /**
     * @brief ErrorLogView Creates a new ErrorLogView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit ErrorLogView(QWidget *parent = 0);
    ~ErrorLogView(){}

    bool hasAdditionalNavigation() const{
        return true;
    }

    QList<QAbstractButton*> * getAdditionalNavigation() const;

signals:

public slots:
    void onEnter();
    void onLeaving();

private slots:
    void btnClearErrorLogClicked();

private:
    TextEdit *txtBxErrors;
    QPushButton *btnClearErrorLog;
};

#endif // ERRORLOGVIEW_H
