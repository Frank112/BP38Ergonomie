#ifndef GANTTTIMERVIEW_H
#define GANTTTIMERVIEW_H

#include "../navigation/titledwidget.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QStringList>
#include "workprocessbutton.h"
#include "../numberlineedit.h"
#include "spaceritemtimer.h"
#include "../interfaces/igantt.h"
#include "../../databaseHandler/dbconstants.h"

/**
 * @brief The GanttTimerView class provides functionality to display all workprocesses of a
 * workplace in a GANTT diagram.
 */
class GanttTimerView : public TitledWidget, IGantt
{
    Q_OBJECT
    Q_INTERFACES(IGantt)
public:
    /**
     * @brief GanttTimerView Creates a new GanttTimerView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit GanttTimerView(QWidget *parent = 0);
    ~GanttTimerView();

signals:
    void saveWorkProcessFrequence(int frequence);

    void selectWorkProcess(int id, AVType type);

    /**
     * @brief left Can be emitted to signal that the GANTT view was left.
     */
    void left();

    /**
     * @brief entered Can be emitted to signal that the GANTT view was entered.
     */
    void entered();

public slots:
    void initiliazeWorkProcesses(QList<QHash<QString, QVariant>> values);

    void setSelectedWorkProcess(QHash<QString, QVariant> values);

    void addWorkProcess(QHash<QString, QVariant> values);

    void resetWorkProcesses();

    void onEnter();

    void onLeaving();

private slots:
    void btnZoomInClicked();
    void btnZoomOutClicked();
    void btnPlus();
    void btnMinus();
    void btnWPLeftClicked(int id);
    void btnWPRightClicked(int id);
    void btnWPBasicClicked(int id);

private:
    int secPixel;
    int selWP_ID;
    AVType selWP_Type;

    NumberLineEdit *numBxFrequenz;

    QPushButton *btnZoomIn;
    QPushButton *btnZoomOut;
    QPushButton *btnFrequenzPlus;
    QPushButton *btnFrequenzMinus;

    QHBoxLayout *leftWP;
    QHBoxLayout *rightWP;
    QHBoxLayout *basicWP;

    QVector<QVariant> *leftWorkProcesses;
    QVector<QVariant> *rightWorkProcesses;
    QVector<QVariant> *basicWorkProcesses;

    QHBoxLayout* getLayout(int type);

    void workProcessClicked(int id, AVType type);
    void resizeClear();
    void update();
};

#endif // GANTTTIMERVIEW_H
