#ifndef ICONBUTTON_H
#define ICONBUTTON_H

#include <QAbstractButton>
#include <QGridLayout>
#include <QIcon>
#include <QPushButton>
#include <QLabel>

/**
 * @brief The IconButton class provides functionality for displaying an icon and a text on a button.
 */
class IconButton : public QAbstractButton
{
    Q_OBJECT
public:
    /**
     * @brief IconButton Creates a new icon button with the given icon and text.
     * @param parent The parent widget.
     * @param objectName The object name in the stylesheet for how the icon displayed should look like.
     * @param text The text to display on the button.
     */
    explicit IconButton(QWidget *parent = 0, const QString &objectName = "", const QString &text = "");

    /**
     * @brief setIcon Sets the icon to the what is specified for the given object name in the stylesheet.
     * @param objectName The object name to set on the icon.
     */
    void setIcon(const QString &objectName);

    /**
     * @brief setText Sets the displayed text on the button.
     * @param text The new text to set.
     */
    void setText(const QString &text);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);
    QSize sizeHint() const;

private:
    QGridLayout *layout;
    QIcon icon;
    QPushButton *lblIcon;
    QLabel *lblText;
    QLabel *lblSpacer;
};

#endif // ICONBUTTON_H
