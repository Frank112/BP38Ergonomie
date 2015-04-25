#ifndef DOCUMENTATIONVIEW_H
#define DOCUMENTATIONVIEW_H

#include "../navigation/simplenavigateablewidget.h"
#include <QStackedWidget>
#include <QComboBox>
#include <QHash>
#include <QStack>
#include "../timerView/timerviewcontroller.h"

/**
 * @brief The DocumentationView class provides functionality to manage the documentation views.
 *
 * DocumentationView inherits SimpleNavigateableWidget.
 *
 * @author Frank Loeffler
 */
class DocumentationView : public SimpleNavigateableWidget
{
    Q_OBJECT
public:
    /**
     * @brief DocumentationView Creates a new DocumentationView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit DocumentationView(QWidget *parent = 0);

    bool hasInternalNavigation() const{
        return true;
    }

    QWidget * getInternalNavigation() const{
        return views;
    }

    /**
     * @brief showStartView Shows the start view and selects the given type in the combo box.
     * @param type The type to select.
     */
    void showStartView(Types::ViewType type);

    /**
     * @brief registerView Registers and connects the given view, iff it
     * has not yet been registered.
     * @param widget
     * @param type
     */
    void registerView(TitledWidget *widget, Types::ViewType type);

    /**
     * @brief setTimerViewController Registers and connects the given timerViewController, iff
     * no timerViewController has been registered yet.
     * @param timerViewController The timerViewController to set.
     */
    void setTimerViewController(TimerViewController *timerViewController);

public slots:
    void onLeaving();
    void onEnter();

private slots:
    void showGant();
    void hideGant();

    void saveCurrentView();
    void changeView(int index);
    void changeView(Types::ViewType type);

private:
    int indexBeforeTimeLineView;
    bool registeredTimerViewController;

    QComboBox *views;
    QStackedWidget *mainContent;
    QVBoxLayout *mainLayout;

    TimerViewController *timerViewController;

    QHash<Types::ViewType, TitledWidget*> *viewTypeToWidget;
    QHash<Types::ViewType, int> *viewTypeToIndex;
    Types::ViewType currentView;
};

#endif // DOCUMENTATIONVIEW_H
