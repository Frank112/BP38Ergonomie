#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>

/**
 * @brief The TextEdit class provides functionality for displayed and editing multiline text.
 * @see QTextEdit
 */
class TextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit TextEdit(QWidget *parent = 0);
    ~TextEdit();
};

#endif // TEXTEDIT_H
