#ifndef NAVIGATABELWIDGET_H
#define NAVIGATABELWIDGET_H

#include "titledwidget.h"
#include <QAbstractButton>
#include <QList>

/**
 * @brief The NavigateableWidget class is an abstract class of navigateable widgets, providing functionality common to view widgets
 * that can navigate to other widgets.
 *
 * The class inherits the functionality of the TitledWidget class and extends it by adding methods to get the
 * <i>previous</i>, <i>next</i> and <i>additional</i> view types iff existent.
 *
 * The ViewController adapts the navigation bar depending on the return values of the provided methods.
 *
 * @author Frank Loeffler
 */
class NavigateableWidget : public TitledWidget
{
    Q_OBJECT
public:

    /**
     * @brief NavigateableWidget Constructs an abstract widget with a <i>title</i> and a <i>parent</i>.
     * @param title The <i>title</i> of the widget as a <a href="http://doc.qt.io/qt-5/QString.html">QString</a>.
     * @param parent The <i>parent</i> widget of the abstract widget.
     */
    explicit NavigateableWidget(const QString &title, QWidget *parent = 0) : TitledWidget(title, parent){

    }

    ~NavigateableWidget(){

    }

    /**
     * @brief getBackViewType Gets the ViewType of the widget that should be displayed when going <i>back</i>.
     *
     * In most cases it logically follows that this means the widget that has been displayed <i>before</i> the current widget.
     *
     * @return The ViewType of the <i>previous</i> widget.
     *
     * <b>Note:</b> When returning the ViewType::UNKNOWN the ViewController handles the navigation with
     * respect to the actual ViewType shown prior.
     *
     * <b>Note:</b> The method is only called iff canGoBack() returns true.
     */
    virtual ViewType getBackViewType() const = 0;

    /**
     * @brief getForwardViewType Gets the ViewType of the widget that should be displayed when going <i>forward</i>.
     *
     * @return The ViewType of the <i>next</i> widget.
     *
     * <b>Note:</b> The method is only called iff canGoForward() returns true.
     */
    virtual ViewType getForwardViewType() const = 0;

    /**
     * @brief getAdditionalNavigation Gets a list of buttons that add additional navigation possibilities apart from
     * the <i>back</i> and the <i>forward</i> widgets.
     * @return A <a href="http://doc.qt.io/qt-5/qlist.html">QList</a> of <a href="http://doc.qt.io/qt-4.8/qabstractbutton.html">QAbstractButton</a>s that represent
     * the possible additional navigation.
     *
     * <b>Note:</b> The method is only called iff hasAdditionalNavigation() returns true.
     */
    virtual QList<QAbstractButton*> * getAdditionalNavigation() const = 0;

    /**
     * @brief getInternalNavigation Gets the widget that provides functionality for internal navigation.
     * @return A <a href="http://doc.qt.io/qt-4.8/qwidget.html">QWidget</a> that represents the internal navigation of the NavigateableWidget.
     *
     * <b>Note:</b> The method is only called iff hasInternalNavigation() returns true.
     */
    virtual QWidget* getInternalNavigation() const = 0;

    /**
     * @brief canGoForward Returns true iff the NavigateableWidget has the option to go <i>forward</i>.
     * @return true iff the NavigateableWidget can go forward, false otherwise.
     */
    virtual bool canGoForward() const = 0;

    /**
     * @brief canGoBack Returns true iff the NavigateableWidget has the option to go <i>back</i>.
     * @return true iff the NavigateableWidget can go back, false otherwise.
     */
    virtual bool canGoBack() const = 0;

    /**
     * @brief hasInternalNavigation Returns true iff the NavigateableWidget has an internal navigation.
     * @return true iff the NavigateableWidget has internal navigation, false otherwise.
     *
     * @see getInternalNavigation()
     */
    virtual bool hasInternalNavigation() const = 0;

    /**
     * @brief hasAdditionalNavigation Returns true iff the NavigateableWidget has additional navigation.
     * @return true iff the NavigateableWidget has additional navigation, false otherwise.
     *
     * @see getAdditionalNavigation()
     */
    virtual bool hasAdditionalNavigation() const = 0;



};

#endif // NAVIGATABELWIDGET_H
