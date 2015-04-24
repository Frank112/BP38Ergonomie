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
/**
 * @brief The QuickSelectionControl class provides Functionality to quickly change arm, leg and body posture.
 *
 * @author Johannes Pfannmueller
 */
class QuickSelectionControl : public QWidget
{ Q_OBJECT
public:
    /**
     * @brief QuickSelectionControl Creates a new QuickSelectionControl
     * @param parent Parent widget which holds the value control or if 0 then a standalone window
     */
    explicit QuickSelectionControl(QWidget *parent=0);

    /**
     * @brief getName Returns The Name of the QuickSelectionControl as a String
     * @return The Name of the QuickSelectionControl as a String
     */
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

    /**
     * @brief hideContent hides everything but the Name of the QuickSelectionControl
     */
    void hideContent();
    /**
     * @brief showContent shows the Content
     */
    void showContent();
    /**
     * @brief setName sets the Name of the QuickSelectionControl
     * @param name a String
     */
    void setName(const QString &name);
    /**
     * @brief setButtonIcon seths an icon to be displayed on a button
     * @param objectName the name of the object which is a path to the image
     * @param size a QSize which sets the size of the Image
     */
    void setButtonIcon(const QString &objectName, const QSize &size);
    /**
     * @brief setExclusiveDisplayByName sets the content to be only displayed by the given name
     * @param name the name
     */
    void setExclusiveDisplayByName(const QString &name);
    /**
     * @brief voscQuickTrunkPostureChanged indicates that the QuickTrunkPosture has changed
     * @param id the id of the newly selected button
     */
    void voscQuickTrunkPostureChanged(int id);
    /**
     * @brief voscQuickArmPostureChanged indicates that the QuickTrunkPosture has changed
     * @param id the id of the newly selected Button
     * @param sel the id of the newly selected Specification Button
     */
    void voscQuickArmPostureChanged(int id, int sel);
    /**
     * @brief qlpcQuickLegPostureChanged indicates that the QuickArmPosture has changed
     * @param id the id of the newly selected Button
     * @param sel the id of the newly selected Specification Button
     */
    void qlpcQuickLegPostureChanged(int id, int sel);
    /**
     * @brief qlpcQuickLegPostureSpecificationChagend indicates that the QuickLetPostureSpecification has changed
     * @param sel the id of the Specificationi Button
     */
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
