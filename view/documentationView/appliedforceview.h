#ifndef ACTIONFORCEVIEW_H
#define ACTIONFORCEVIEW_H

#include "../navigation/titledwidget.h"
#include <QScrollArea>
#include <QVector>
#include <QString>
#include "../valuecontrol.h"
#include "../textcontrol.h"
#include "../interfaces/iappliedforce.h"

/**
 * @brief The AppliedForceView class provides functionality to display and document
 * the applied forces of a workprocess via value controls.
 *
 * AppliedForceView inherits TitledWidget and implements IAppliedForce.
 *
 * @author Frank Loeffler
 */
class AppliedForceView : public TitledWidget, IAppliedForce
{
    Q_OBJECT
    Q_INTERFACES(IAppliedForce)
public:
    /**
     * @brief AppliedForceView Creates a new AppliedForceView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit AppliedForceView(QWidget *parent = 0);

signals:
    void saveAppliedForce(QHash<QString, QVariant> values);

public slots:
    void setAppliedForce(QHash<QString, QVariant> values);

    void onLeaving();

private:
    const QVector<QString> ORGAN_TEXTS = QVector<QString>()<<tr("finger")<<tr("hand")<<tr("arm")<<tr("foot/leg")<<tr("full body");
    const QVector<QString> DIRECTION_TEXTS = QVector<QString>()<<tr("above")<<tr("below")<<tr("front")<<tr("back")<<tr("right")<<tr("left");
    const QVector<QString> DIRECTION_VALUES = QVector<QString>()<<tr("+A")<<tr("-A")<<tr("+B")<<tr("-B")<<tr("+C")<<tr("-C");
    static const QVector<int> INTENSITY_VALUES;

    ValueControl* valConIntensity;
    TextControl* txtConDirection;
    TextControl* txtConOrgan;

};

#endif // ACTIONFORCEVIEW_H
