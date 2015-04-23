#ifndef SLIDERCONTROL_H
#define SLIDERCONTROL_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QGridLayout>

/**
 * @brief The SliderControl class provides functionality to select a integer
 * value between given bounds with a slider. The bounds are shown on the left
 * side of the slider (Minimum) and the right side of the slider (Maximum).
 * Above the slider the currently selected value is shown.
 *
 * @author Frank Loeffler
 */
class SliderControl : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Creates a new SliderControl object. With minimum value 0 and
     * maximum value 10 and the interval 1.
     *
     * @param parent
     *      The parent widget of the new slider control object.
     */
    explicit SliderControl(QWidget *parent = 0);
    ~SliderControl();

    /**
     * @brief Sets the bounds of the slider control.
     *
     * @param min
     *          The minimum value of the selectable value.
     *          Has to be less than the given maximum.
     * @param max
     *          The maximum value of the selectable value.
     */
    void setMinMax(int min, int max);

    /**
     * @brief Sets the interval of the slider.
     * The interval of a slider is the absolute change of the value
     * per slider tick.
     *
     * @param interval
     *          The absolute change of the value per slider tick.
     */
    void setInterval(int interval);

    /**
     * @brief Returns the currently selected value with the slider control.
     *
     * @return
     *          The current value which is selected with the slider.
     */
    int getValue() const;

    /**
     * @brief Returns the minimum value of the selectable values.
     *
     * @return
     *          The minimum value.
     */
    int getMin() const;

    /**
     * @brief Returns the maximum value of the selectable values.
     *
     * @return
     *          The maximum value.
     */
    int getMax() const;

signals:
    /**
     * @brief Is emitted if the selected value of the slider changed.
     *
     * @param value
     *          The new selected value.
     */
    void valueChanged(int value);

public slots:
    /**
     * @brief Sets the given value as the selected value iff the
     * value is greater or equal the minimum and less or equal the
     * maximum value of the slider control.
     *
     * @param value
     *          The new selected value of the control.
     */
    void setValue(int value);

private slots:
    void sldrValueChanged(int value);

private:
    QLabel *lblMin;
    QLabel *lblMax;
    QLabel *lblValue;

    QSlider *sldrValue;
};

#endif // SLIDERCONTROL_H
