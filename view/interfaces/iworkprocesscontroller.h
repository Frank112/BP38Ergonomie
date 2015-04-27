#ifndef IWORKPROCESSCONTROLLER
#define IWORKPROCESSCONTROLLER

#include <QtPlugin>
#include "../../enum.h"

/**
 * @brief The IWorkProcessController class is an interface that can be implemented to indicate, that
 * functionality for displaying and changing workprocesses is provided.
 */
class IWorkProcessController {

signals:

    /**
     * @brief selectNextWorkProcess A signal that can be emitted to signal that ne next workprocess should be selected.
     */
    virtual void selectNextWorkProcess() = 0;

    /**
     * @brief selectPreviousWorkProcess A signal that can be emitted to signal that ne previous workprocess should be selected.
     */
    virtual void selectPreviousWorkProcess() = 0;

    /**
     * @brief workProcessTypeChanged A signal that can be emitted to signal that a different workprocess type has been selected.
     * @param type The new type of workprocesses.
     */
    virtual void workProcessTypeChanged(AVType type) = 0;

    /**
     * @brief workProcessDurationChanged A signal that can be emitted to signal that the duration of the currently
     * selected work process has changed.
     * @param duration The new duration of the work process.
     */
    virtual void workProcessDurationChanged(QTime duration) = 0;

    /**
     * @brief createWorkProcess A signal that can be emitted to signal that a new work process should be created.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createWorkProcess(QHash<QString, QVariant> values) = 0;

    /**
     * @brief resetWorkProcesses A signal that can be emitted to signal that all workprocesses should be deleted.
     */
    virtual void resetWorkProcesses() = 0;

public slots:

    /**
     * @brief setSelectedWorkProcess Sets the selected workprocess to the one specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setSelectedWorkProcess(QHash<QString, QVariant> values) = 0;

    /**
     * @brief setHasPreviousWorkProcess Sets if the currently selected work process has a
     * previous work process.
     * @param hasPrevious True, iff the currently selected process should have a predecessor.
     */
    virtual void setHasPreviousWorkProcess(bool hasPrevious) = 0;

    /**
     * @brief setHasNextWorkProcess Sets if the currently selected work process has a
     * next work process
     * @param hasNext True, iff the currently selected process should have a successor.
     */
    virtual void setHasNextWorkProcess(bool hasNext) = 0;

    /**
     * @brief setSelectedWorkProcessType Sets the selected work process type to the given one.
     * @param type The new work process type to select.
     */
    virtual void setSelectedWorkProcessType(AVType type) = 0;

    /**
     * @brief initializedWorkProcesses Initializes all work process types with the work process
     * for each type specified in <i>values</i>
     * @param values A list of hashmaps of values with each the column name and the corresponding value to this column.
     */
    virtual void initializedWorkProcesses(QList<QHash<QString, QVariant>> values) = 0;

};

#define IWorkProcessController_iid "IWorkProcessController"
Q_DECLARE_INTERFACE(IWorkProcessController, IWorkProcessController_iid)

#endif // IWORKPROCESSCONTROLLER

