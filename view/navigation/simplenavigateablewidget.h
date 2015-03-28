#ifndef SIMPLENAVIGATABLEWIDGET_H
#define SIMPLENAVIGATABLEWIDGET_H

#include "navigateablewidget.h"

/**
 * @brief The SimpleNavigateableWidget class provides functionality common to navigateable
 * widgets without internal or additional navigation.
 *
 * The class inherits the functionality of the NavigateableWidget and implements the virtual methods getInternalNavigation(), getAdditionalNavigation(),
 * hasInternalNavigation() and hasAdditionalNavigation() methods of NavigateableWidget such that this navigation is not possible on the widget.
 * Furthermore a SimpleNavigateableWidget has the ability to go <i>back</i> as implemented in canGoBack()
 * but not <i>forward</i> as implemented in canGoForward(), though the actual Types::ViewType returned by getBackViewType()
 * is unknown as the actual navigation has to be handled elsewhere based on the sequence in which widgets have been shown.
 *
 * @author Frank Loeffler
 */
class SimpleNavigateableWidget : public NavigateableWidget
{
public:
    /**
     * @brief SimpleNavigateableWidget Constructs an abstract widget with a <i>title</i> and a <i>parent</i>.
     * @param title The <i>title</i> of the widget.
     * @param parent The <i>parent</i> widget of the abstract widget.
     */
    SimpleNavigateableWidget(const QString &title, QWidget *parent = 0) :
        NavigateableWidget(title, parent){

    }

    ~SimpleNavigateableWidget(){

    }

    /**
     * @brief getInternalNavigation Returns 0 as a SimpleNavigateableWidget does not support internal navigation.
     * @return 0
     */
    QWidget* getInternalNavigation() const {
        return 0;
    }

    /**
     * @brief getAdditionalNavigation Returns 0 as a SimpleNavigateableWidget does not support additional navigation.
     * @return 0
     */
    QList<QAbstractButton*> * getAdditionalNavigation() const{
        return 0;
    }

    /**
     * @brief hasInternalNavigation Returns false as a SimpleNavigateableWidget does not support internal navigation.
     * @return false
     */
    bool hasInternalNavigation() const{
        return false;
    }

    /**
     * @brief hasAdditionalNavigation Returns false as a SimpleNavigateableWidget does not support additional navigation.
     * @return false
     */
    bool hasAdditionalNavigation() const{
        return false;
    }

    /**
     * @brief getForwardViewType Returns Types::ViewType::UNKNOWN as the type cannot be specified because a SimpleNavigateableWidget cannot go forward.
     * @return Types::ViewType::UNKNOWN
     */
    Types::ViewType getForwardViewType() const{
        return Types::ViewType::UNKNOWN;
    }

    /**
     * @brief getBackViewType Returns Types::ViewType::UNKNOWN as the type of the <i>previous</i> view is not fixed.
     * @return Types::ViewType::UNKNOWN
     */
    Types::ViewType getBackViewType() const{
        return Types::ViewType::UNKNOWN;
    }

    /**
     * @brief canGoBack Returns true as every SimpleNavigateableWidget has a <i>previous</i> view.
     * @return true
     */
    bool canGoBack() const{
        return true;
    }

    /**
     * @brief canGoForward Returns false as every SimpleNavigateableWidget does not have a <i>next</i> view.
     * @return false
     */
    bool canGoForward() const{
        return false;
    }

};

#endif // SIMPLENAVIGATABLEWIDGET_H
