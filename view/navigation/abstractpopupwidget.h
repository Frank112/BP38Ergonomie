#ifndef ABSTRACTPOPUPWIDGET_H
#define ABSTRACTPOPUPWIDGET_H

#include "titledwidget.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

/**
 * @brief The AbstractPopUpWidget class is an abstract class, providing functionality common to popups.
 *
 * The class inherits the functionality of the TitledWidget class and extends it by adding signals common to popups.
 * Furthermore a ConfirmMode is defined, giving <i>visual</i> information about the confirm type of the popup.
 *
 * AbstractPopUpWidget provides three signals:
 *
 * 1. closePopUp() is emitted when the popup should be closed.
 * 2. cancel() is emitted when the cancel button of the popup is clicked.
 * 3. confirm() is emitted when the confirm button of the popup is clicked.
 *
 * <b>Note:</b> The ConfirmMode has no effect on the functionality of the popup.
 *
 * @author Frank Loeffler
 */
class AbstractPopUpWidget : public TitledWidget
{
    Q_OBJECT
public:

    /**
     * @brief The ConfirmMode enum describes the visual representation of the confirm button.
     */
    enum ConfirmMode{
        ACCEPT, ///< The confirm button is displayed as a <i>save</i> symbol.
        SEND ///< The confirm button is displayed as a <i>send</i> symbol.
    };

    /**
     * @brief AbstractPopUpWidget Constructs an abstract widget with a <i>confirm mode<i>, a <i>title</i> and a <i>parent</i>.
     * @param mode The <i>confirm mode</i> of the widget.
     * @param title The <i>title</i> of the widget as a <a href="http://doc.qt.io/qt-5/QString.html">QString</a>.
     * @param parent The <i>parent</i> widget of the abstract widget.
     */
    explicit AbstractPopUpWidget(ConfirmMode mode, const QString &title, QWidget *parent = 0);
    ~AbstractPopUpWidget();

    /**
     * @brief setLayout Sets the content's layout of the popup.
     * @param layout The layout to be set for the content.
     *
     * <b>Note:</b> Setting the layout does <b>not</b> affect the title bar of the popup.
     */
    void setLayout(QLayout *layout);

signals:
    /**
     * @brief closePopUp A signal that is emitted when the either the cancel or the confirm button is clicked.
     * It signals the ViewController to close the popup.
     */
    void closePopUp();

    /**
     * @brief cancel A signal that is emitted when the cancel button is clicked.
     */
    void cancel();

    /**
     * @brief confirm A signal that is emitted when the confirm button is clicked.
     */
    void confirm();

private:
    QGridLayout *mainContentLayout;

    QPushButton *btnClose;
    QPushButton *btnConfirm;
    QLabel *lblTitle;

    void paintEvent(QPaintEvent *);
};

#endif // ABSTRACTPOPUPWIDGET_H
