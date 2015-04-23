#ifndef SPACERITEMTIMER_H
#define SPACERITEMTIMER_H

#include <QSpacerItem>

/**
 * @brief The SpacerItemTimer class provides functionality to set a spacer item for the GANTT view.
 */
class SpacerItemTimer : public QSpacerItem
{
public:
    /**
     * @brief SpacerItemTimer Creates a new SpacerItemTimer object with the given parameters.
     * @param duration The duration to be set on the object.
     * @param width The width of the object.
     * @param height The height of the object.
     * @param horPol The horizontal size policy of the object.
     * @param verPol The vertical size policy of the object.
     */
    explicit SpacerItemTimer(int duration, int width, int height, QSizePolicy::Policy horPol, QSizePolicy::Policy verPol);
    ~SpacerItemTimer();

    /**
     * @brief getDuration Returns the duration of the object.
     * @return The duration of the object.
     */
    int getDuration() const;

    /**
     * @brief setDuration Sets the given value as duration on the object.
     * @param value The duration to set.
     */
    void setDuration(int value);

private:
    int duration;
};

#endif // SPACERITEMTIMER_H
