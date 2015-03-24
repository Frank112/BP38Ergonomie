#ifndef QUICKSELECTIONCONTROL_H
#define QUICKSELECTIONCONTROL_H

#include <QWidget>
#include <QStringList>
#include <QPushButton>
#include <QString>
#include "verticaloptionselectioncontrol.h"
#include "quickarmposturecontrol.h"
#include "quicklegposturecontrol.h"
#include <QPixmap>
#include <QLabel>
#include <QHash>
class QuickSelectionControl : public QWidget
{ Q_OBJECT
public:
    explicit QuickSelectionControl(QWidget *parent=0);

    QString getName() const;

    QuickLegPostureControl *qlpcQuickLegPosture;
    QuickArmPostureControl *voscQuickArmPosture;
    VerticalOptionSelectionControl *voscQuickTrunkPosture;

signals:
    void QuickSelectionChanged(int id);
    void requestShowContent(const QString &name);
    void quickTrunkPostureChanged(int id);
    void quickArmPostureChanged(int id, int sel);
    void quickLegPostureChanged(int id, int sel);
    void quickLegPostureSpecificationChanged(int sel);

public slots:

    void hideContent();
    void showContent();
    void setName(const QString &name);
    void setButtonIcon(const QString &objectName, const QSize &size);
    void setExclusiveDisplayByName(const QString &name);
    void voscQuickTrunkPostureChanged(int id);
    void voscQuickArmPostureChanged(int id, int sel);
    void qlpcQuickLegPostureChanged(int id, int sel);
    void qlpcQuickLegPostureSpecificationChagend(int sel);

private slots:

    void btnNameClicked();
    void updateDummyPosture();

private:
    QString name;
    QVBoxLayout *mainLayout;
    QHBoxLayout *verticalLayout;
    QWidget *mainContent;

    QPushButton *btnName;
    const QStringList QUICK_LEG_POSTURE_TEXTS = QStringList()<<tr("Standing")<<"false"<<tr("Sitting")<<"false"<<tr("Kneeling")<<"true"<<tr("Running")<<"false"<<tr("Walking")<<"false";
    const QStringList QUICK_ARM_POSTURE_TEXTS = QStringList()<<tr("At Elbow height")<<tr("At Shoulder height")<<tr("At Head height");
    const QStringList QUICK_TRUNK_POSTURE_TEXTS = QStringList()<<tr("strong bending to the front")<<tr("light bending to the front")<<tr("no bending at all")<<tr("light bending to behind")<<tr("strong bending to behind");
    const QStringList LEFT_RIGHT_TEXTS = QStringList()<<tr("left")<<tr("right");

    QLabel *dummyHolder;
    const QPixmap dummy_standing_bothArms_atElbowHeight_strongBendingFront = QPixmap(":/icons/QuickBodyPosture/standing_bothArms_atElbowHeight_strongBendingFront.png");
    bool shown;

    int key;

    QHash<int, QString> dummyHash;
};

#endif // QUICKSELECTIONCONTROL_H
