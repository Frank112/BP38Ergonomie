#ifndef TEXTLINEEDIT_H
#define TEXTLINEEDIT_H

#include <QLineEdit>

/**
 * @brief The TextLineEdit class provides functionality for displaying and editing single lined text.
 * @see QLineEdit
 */
class TextLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit TextLineEdit(QWidget *parent = 0);

signals:

public slots:

};

#endif // TEXTLINEEDIT_H
