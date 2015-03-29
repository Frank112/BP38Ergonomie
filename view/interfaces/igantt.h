#ifndef IGANTT
#define IGANTT

#include <QtPlugin>
#include "../../enum.h"

/**
 * @brief The IGantt class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a gantt diagramm is provided.
 *
 * @author Frank Loeffler
 */
class IGantt{

signals:
    /**
     * @brief saveWorkProcessFrequence A signal that can be emitted to signal that the
     * frequency value of a work process should be saved.
     * @param frequence The frequence to be saved.
     */
    virtual void saveWorkProcessFrequence(int frequence) = 0;

    /**
     * @brief selectWorkProcess A signal that can be emitted to signal that a work process
     * identified by its id and its AVType should be selected.
     * @param id The id of the work process.
     * @param type The type of the work process.
     */
    virtual void selectWorkProcess(int id, AVType type) = 0;

public slots:
    /**
     * @brief initiliazeWorkProcesses Initializes the gantt diagramm with a list of values, where
     * each value is a <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a> mapping a column names
     * with the corresponding values.
     * @param values A list of hashmaps containing to values to initialize.
     */
    virtual void initiliazeWorkProcesses(QList<QHash<QString, QVariant>> values) = 0;

    /**
     * @brief setSelectedWorkProcess Selects the work process identified by the
     * provided <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a> containing the work process' values.
     * @param values A hashmap containing values of the work process to be selected.
     */
    virtual void setSelectedWorkProcess(QHash<QString, QVariant> values) = 0;

    /**
     * @brief addWorkProcess Adds a work process to the gantt diagramm, displaying it depending on
     * the provided <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a> containing its values.
     * @param values A hashmap containing values of the work process to be added.
     */
    virtual void addWorkProcess(QHash<QString, QVariant> values) = 0;

    /**
     * @brief resetWorkProcesses
     */
    virtual void resetWorkProcesses() = 0;
};

#define IGantt_iid "IGantt"
Q_DECLARE_INTERFACE(IGantt, IGantt_iid)

#endif // IGANTT

