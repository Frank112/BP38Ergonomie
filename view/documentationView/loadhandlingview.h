#ifndef LOADHANDLINGVIEW_H
#define LOADHANDLINGVIEW_H

#include <QLabel>
#include "../navigation/titledwidget.h"
#include <QPushButton>
#include "textcontrol.h"
#include "../valuecontrol.h"
#include "../interfaces/itransportationlist.h"
#include "../interfaces/iloadhandling.h"

/**
 * @brief A class providing a view for transporthandling. The class contains
 * different ValueControl for the type, of handling the weight to be handled,
 * the way to go and the hand used. Furthermore there is a TransportationListControl
 * with the list of transportations available.
 *
 * LoadHandlingView inherits TitledWidget and implements ITransportationList and ILoadHandling.
 *
 * @author Marius Gassen
 */
class LoadHandlingView : public TitledWidget, ITransportationList, ILoadHandling
{
    Q_OBJECT
    Q_INTERFACES(ITransportationList)
    Q_INTERFACES(ILoadHandling)

public:
    /**
     * @brief LoadHandlingView Creates a new LoadHandlingView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit LoadHandlingView(QWidget *parent = 0);
    ~LoadHandlingView();

signals:
    void saveLoadHandling(QHash<QString, QVariant> values);

    void createTransportation(QHash<QString, QVariant> values);
    void deleteTransportation(int id);
    void selectTransportation(int id);

    /**
     * @brief selectedTransportation Can be emitted to signal that the transportation with the
     * given id is the selected transportation.
     * @param id The id of the selected transportation.
     */
    void selectedTransportation(int id);

public slots:
    void setLoadHandling(QHash<QString, QVariant> values);

    void addTransportation(QHash<QString, QVariant> values);
    void removeTransportation(int id);
    void updateTransportation(QHash<QString, QVariant> values);
    void clearTransportations();

    void onLeaving();

private slots:
    void selectedTransportationChanged(int id);
    void deselectTransportation(int id);
    void typeChanged(QString newType);
    void btnAddTransportationClicked();

private:
    TextControl *vlcGraspType;
    TextControl *vlcHandlingType;
    ValueControl *vlcWeight;
    ValueControl *vlcDistance;
    QLabel *lblTransportation;
    QPushButton *btnAddTransportation;

    QWidget *main;
    QWidget *control;

    int selectedTransportationID;


    const QVector<QString> graspValues = QVector<QString>()<<tr("Thumbcontact grasp")<<tr("Indexcontact grasp")<<tr("Handcontact grasp")<<tr("Thumb to 2 Fingers")<<tr("Fingergrasp")<<tr("Thumbindex")<<tr("Wrench")<<tr("Fullgrasp");
    const QVector<int> weightValues = QVector<int>()<<2<<3<<5<<10<<20;
    const QVector<int> heavyWeightValues = QVector<int>()<<100<<500<<1000<<1500<<2000;
    const QVector<int> distanceValues = QVector<int>()<<2<<3<<5<<10<<20;
    const QVector<QString> HandlingTypeValues = QVector<QString>()<<tr("holding")<<tr("replacing")<<tr("carrying")<<tr("pulling and pushing");

    const QList<QStringList> transportationItemScheme = QList<QStringList>() << (QStringList() << tr("empty weight:") << tr("max. load:")) << (QStringList() << tr("fixed rollers:") << tr("brakes:"));

    QVBoxLayout *transportationListLayout;
};

#endif // LoadHandlingView_H
