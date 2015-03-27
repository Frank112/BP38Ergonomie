#ifndef BODYPOSTUREVIEW_H
#define BODYPOSTUREVIEW_H

#include "../../navigation/titledwidget.h"
#include <QVector>
#include "variantspecification.h"
#include "variantcontrol.h"
#include "enum.h"
#include <QPushButton>
#include <QLabel>
#include <QSqlRecord>
#include "../../../databaseHandler/dbconstants.h"
#include "quickselectioncontrol.h"


class BodyPostureView : public TitledWidget
{

    Q_OBJECT
public:
    explicit BodyPostureView(QWidget *parent = 0);

public slots:
    void setSelectedType(const AVType &type);
    void setBodyPosture(QHash<QString, QVariant> values);
    void onLeaving();

signals:
    void showExclusiveContentByName(const QString &name);
    void saveBodyPosture(QHash<QString, QVariant> values);


private slots:
    void varConRequestShowContent(const QString &name);
    void armSpeciChanged(int type);
    void legSpeciChanged(int type);

    void voscQuickTrunkPostureChanged(int id);
    void voscQuickArmPostureChanged(int id, int sel);
    void qlpcQuickLegPostureChanged(int id, int sel);
    void qlpcQuickLegPostureSpecificationChagend(int sel);

    void vcTrunkTiltValueChanged(int value);
    void vcTrunkTiltSidewaysValueChanged(int value);
    void vcTrunkTwistValueChanged(int value);

    void vcUpperArmAngleValueChanged(int value);
    void vcForearmAngleValueChanged(int value);
    void vcUpperArmTwistValueChanged(int value);
    void vcForearmTwistValueChanged(int value);
    void vcArmOpeningValueChanged(int value);
    void vcWristAngleValueChanged(int value);
    void vcWristAngleSidewaysValueChanged(int value);
    void vcWristMovementValueChanged(int value);

    void vcHipAngleValueChanged(int value);
    void vcHipAngleSidewaysValueChanged(int value);
    void vcHipTwistValueChanged(int value);
    void vcKneeAngleValueChanged(int value);
    void vcAnkleAngleValueChanged(int value);
    void vcAnkleAngleSidewaysValueChanged(int value);

    void vcHeadTiltValueChanged(int value);
    void vcHeadTiltSidewaysValueChanged(int value);
    void vcHeadTwistValueChanged(int value);


private:

    static const QVector<int> TRUNK_TILT_VALUES;
    static const QVector<int> TRUNK_TILT_SIDEWAYS_VALUES;
    static const QVector<int> TRUNK_TWIST_VALUES;

    static const QVector<int> HEAD_TILT_VALUES;
    static const QVector<int> HEAD_TILT_SIDEWAYS_VALUES;
    static const QVector<int> HEAD_TWIST_VALUES;

    static const QVector<int> UPPER_ARM_ANGLE_VALUES;
    static const QVector<int> FOREARM_ANGLE_VALUES;
    static const QVector<int> UPPER_ARM_TWIST_VALUES;
    static const QVector<int> FOREARM_TWIST_VALUES;
    static const QVector<int> ARM_OPENING_VALUES;
    static const QVector<int> WRIST_ANGLE_VALUES;
    static const QVector<int> WRIST_ANGLE_SIDEWAYS_VALUES;
    static const QVector<int> WRIST_MOVEMENT_VALUES;

    static const QVector<int> HIP_ANGLE_VALUES;
    static const QVector<int> HIP_ANGLE_SIDEWAYS_VALUES;
    static const QVector<int> HIP_TWIST_VALUES;
    static const QVector<int> KNEE_ANGLE_VALUES;
    static const QVector<int> ANKLE_ANGLE_VALUES;
    static const QVector<int> ANKLE_ANGLE_SIDEWAYS_VALUES;

    QuickSelectionControl *quickSelectionLayout;
    VariantControl *varConTrunk;
    VariantControl *varConArms;
    VariantControl *varConLegs;
    VariantControl *varConHead;

    ValueControl *vcTrunkTilt;
    ValueControl *vcTrunkSidewaysTilt;
    ValueControl *vcTrunkTwist;

    ValueControl *vcUpperArmAngle;
    ValueControl *vcForearmAngle;
    ValueControl *vcUpperArmTwist;
    ValueControl *vcForearmTwist;
    ValueControl *vcArmOpening;
    ValueControl *vcWristAngle;
    ValueControl *vcWristAngleSideways;
    ValueControl *vcWristMovement;

    ValueControl *vcHipAngle;
    ValueControl *vcHipAngleSideways;
    ValueControl *vcHipTwist;
    ValueControl *vcKneeAngle;
    ValueControl *vcAnkleAngle;
    ValueControl *vcAnkleAngleSideways;

    ValueControl *vcHeadTilt;
    ValueControl *vcHeadTiltSideways;
    ValueControl *vcHeadTwist;

    VariantSpecification* varSpeciArms;
    VariantSpecification* varSpeciLegs;

    int armSpeci_Type;
    int legSpeci_Type;
    int hipAngleLeft;
    int hipAngleRight;
    int kneeAngleLeft;
    int kneeAngleRight;
    int ankleAngleLeft;
    int ankleAngleRight;
    int trunkPosture;
    QHash<QString, QVariant> values;
};

#endif // BODYPOSTUREVIEW_H
