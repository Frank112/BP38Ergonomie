#include "documentationview.h"
#include <QVBoxLayout>
#include "../separator.h"

DocumentationView::DocumentationView(QWidget *parent) :
    SimpleNavigateableWidget(tr("Documentation"), parent),
    indexBeforeTimeLineView(0),
    registeredTimerViewController(false),
    views(new QComboBox(this)),
    mainContent(new QStackedWidget(this)),
    mainLayout(new QVBoxLayout),
    viewTypeToWidget(new QHash<Types::ViewType, TitledWidget*>()),
    viewTypeToIndex(new QHash<Types::ViewType, int>()),
    currentView(Types::ViewType::UNKNOWN)
{
    views->setMinimumSize(280, 40);
    connect(views, SIGNAL(currentIndexChanged(int)), this, SLOT(changeView(int)));

    mainLayout->addWidget(mainContent);

    setLayout(mainLayout);
}

// PUBLIC
void DocumentationView::showStartView(Types::ViewType type){
    if(viewTypeToIndex->contains(type)){
        currentView = Types::ViewType::UNKNOWN;
        views->setCurrentIndex(viewTypeToIndex->value(type));
    }
}

void DocumentationView::registerView(TitledWidget *widget, Types::ViewType type){
    if(!viewTypeToIndex->contains(type) && widget != 0){
        viewTypeToWidget->insert(type, widget);
        viewTypeToIndex->insert(type, mainContent->addWidget(widget));
        views->addItem(widget->getTitle(), type);
        connect(widget, SIGNAL(showView(Types::ViewType)), this, SLOT(changeView(Types::ViewType)));
        connect(widget, SIGNAL(showView(Types::ViewType)), this, SIGNAL(showView(Types::ViewType)));
        connect(widget, SIGNAL(showPopUp(Types::PopUpType)), this, SIGNAL(showPopUp(Types::PopUpType)));
    }
}

void DocumentationView::setTimerViewController(TimerViewController *timerViewController){
    if(!registeredTimerViewController && timerViewController != 0){
        this->timerViewController = timerViewController;

        connect(timerViewController, SIGNAL(showGantView()), this, SLOT(showGant()));
        connect(timerViewController, SIGNAL(hideGantView()), this, SLOT(hideGant()));
        connect(timerViewController, SIGNAL(changingWorkProcess()), this, SLOT(saveCurrentView()));

        mainLayout->addWidget(new Separator(Qt::Horizontal, 14, this));
        mainLayout->addWidget(timerViewController);

        registeredTimerViewController = true;
    }
}

// PUBLIC SLOTS
void DocumentationView::onLeaving(){
    viewTypeToWidget->value((Types::ViewType) views->currentData().toInt())->onLeaving();
    timerViewController->closeTimerView();
}

void DocumentationView::onEnter(){
    showStartView(Types::ViewType::BODY_POSTURE_VIEW);
}


// PRIVATE SLOTS
void DocumentationView::showGant(){
    indexBeforeTimeLineView = mainContent->currentIndex();
    views->setCurrentIndex(viewTypeToIndex->value(Types::ViewType::GANTT_VIEW));
}

void DocumentationView::hideGant(){
    if(currentView == Types::ViewType::GANTT_VIEW)
        views->setCurrentIndex(indexBeforeTimeLineView);
}

void DocumentationView::saveCurrentView(){
    viewTypeToWidget->value((Types::ViewType) views->currentData().toInt())->onLeaving();
}

void DocumentationView::changeView(int index){
    if(viewTypeToIndex->contains(currentView)){
        viewTypeToWidget->value(currentView)->onLeaving();
        if(currentView == Types::ViewType::GANTT_VIEW)
            timerViewController->gantViewHidden();
    }
    Types::ViewType nextView = (Types::ViewType) views->currentData().toInt();
    if(viewTypeToIndex->contains(nextView)){
        mainContent->setCurrentIndex(index);
        currentView = nextView;
        viewTypeToWidget->value(nextView)->onEnter();
    }

}

void DocumentationView::changeView(Types::ViewType type){
    if(viewTypeToWidget->contains(type)){
        views->setCurrentIndex(viewTypeToIndex->value(type));
    }
}
