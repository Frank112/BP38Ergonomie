#ifndef LINEVIEW_H
#define LINEVIEW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QList>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QScrollArea>
#include "../detailedlistitem.h"
#include "../numberlineedit.h"
#include "../textedit.h"
#include "../interfaces/ilinelist.h"
#include "../navigation/simplenavigateablewidget.h"

/**
 * @brief The LineView class provides functionality to display, create, edit and select lines.
 *
 * LineView inherits SimpleNavigateableWidget and implements ILineList.
 *
 * @author Frank Loeffler
 */
class LineView : public SimpleNavigateableWidget, ILineList
{
    Q_OBJECT
    Q_INTERFACES(ILineList)
public:
    /**
     * @brief LineView Creates a new LineView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit LineView(QWidget *parent = 0);
    ~LineView();

signals:
    void createLine(QHash<QString, QVariant> values);
    void deleteLine(int id);
    void selectLine(int id);
    void editLine(int id);

    /**
     * @brief lineSelected Can be emitted to indicate that the line with the given id is selected.
     * @param id The id of the selected line.
     */
    void lineSelected(int id);

public slots:
    void addLine(QHash<QString, QVariant> values);
    void updateLine(QHash<QString, QVariant> values);
    void removeLine(int id);
    void selectedLine(QHash<QString, QVariant> values);
    void clearLines();
    void onLeaving();

private slots:
    void btnAddClicked();
    void selectedLineChanged(int id);
    void editLineClicked(int id);

private:
    int selectedLineID;
    QVBoxLayout *listContentLayout;
    QScrollArea *scLines;

    QLabel *lblSelectLine;
    QLabel *lblAddLine;
    QLabel *lblName;
    QLabel *lblWorkplaceCount;
    QLabel *lblDescription;

    TextLineEdit *txtBxName;
    NumberLineEdit *numBxWorkplaceCount;
    TextEdit *txtBxDescription;

    QPushButton *btnAdd;
};

#endif // LINEVIEW_H
