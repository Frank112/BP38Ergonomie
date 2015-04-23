#ifndef GRAPHTIMELINEVIEW_H
#define GRAPHTIMELINEVIEW_H

#include <QLabel>
#include <QPainter>
#include <QPicture>
#include <QScrollArea>
#include <QMainWindow>

/**
 * @brief The GraphTimelineView class provides functionality to display all workprocesses of a workplace
 * in a graph.
 *
 * @author Markus Danz
 */
class GraphTimelineView : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief GraphTimelineView Creates a GraphTimelineView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit GraphTimelineView(QWidget *parent = 0);

public slots:
    /**
     * @brief leftStarted Registers the start time in the list of left workprocesses.
     * @param startTime The start time to register.
     */
    void leftStarted(const QTime &startTime);

    /**
     * @brief leftEnded Registers the end time in the list of left workprocesses.
     * @param endTime The end time to register.
     */
    void leftEnded(const QTime &endTime);

    /**
     * @brief rightStarted Registers the start time in the list of right workprocesses.
     * @param startTime The start time to register.
     */
    void rightStarted(const QTime &startTime);

    /**
     * @brief rightEnded Registers the end time in the list of right workprocesses.
     * @param endTime The end time to register.
     */
    void rightEnded(const QTime &endTime);

    /**
     * @brief basicStarted Registers the start time in the list of basic workprocesses.
     * @param startTime The start time to register.
     */
    void basicStarted(const QTime &startTime);

    /**
     * @brief basicEnded Registers the end time in the list of basic workprocesses.
     * @param endTime The end time to register.
     */
    void basicEnded(const QTime &endTime);

    /**
     * @brief initialize Initializes the lists of workprocesses with the given workprocesses.
     * @param leftWPs The left workprocesses to initialize.
     * @param rightWPs The right workprocesses to initialize.
     * @param basicWPs The basic workprocesses to initialize.
     */
    void initialize(QVector<QVariant> *leftWPs, QVector<QVariant> *rightWPs, QVector<QVariant> *basicWPs);

    /**
     * @brief updateGraphTimeLine Draws the workprocesses from the lists in a graph up until the given time.
     * @param currentTime The time to which to draw the graph.
     */
    void updateGraphTimeLine(const QTime &currentTime);

private:
    int paintX;

    QLabel *graph;
    QPicture picture;
    QPainter painter;
    QScrollArea *graphArea;

    QVector<QVariant> *leftWPs;
    QVector<QVariant> *rightWPs;
    QVector<QVariant> *basicWPs;
};

#endif // GRAPHTIMELINEVIEW_H
