#include "feedbackpopup.h"
#include <QGridLayout>
#include "../../standardpaths.h"

FeedbackPopUp::FeedbackPopUp(QWidget *parent) : AbstractPopUpWidget(ConfirmMode::SEND, tr("Feedback"), parent),
    lblViewName(new QLabel(tr("View name:"))),
    txtBxViewName(new TextLineEdit()),
    chbxScreenshot(new QCheckBox()),
    lblDescription(new QLabel(tr("Description:"))),
    txtBxDescription(new TextEdit()),
    lblPriority(new QLabel(tr("Priority:"))),
    cmbBxPriority(new QComboBox()),
    lblCategory(new QLabel(tr("Category:"))),
    cmbBxCategory(new QComboBox()),
    ftpHandler(new FtpHandler(this))
{
    connect(this, SIGNAL(confirm()), this, SLOT(onConfirm()));

    txtBxViewName->setEnabled(false);

    chbxScreenshot->setText(tr("attach screenshot"));

    cmbBxPriority->addItem("1", QVariant(1));
    cmbBxPriority->addItem("2", QVariant(2));
    cmbBxPriority->addItem("3", QVariant(3));
    cmbBxPriority->addItem("4", QVariant(4));
    cmbBxPriority->addItem("5", QVariant(5));

    cmbBxCategory->addItem(tr("Bug"), QVariant("Bug"));
    cmbBxCategory->addItem(tr("Wish"), QVariant("Wish"));
    cmbBxCategory->addItem(tr("Missing function"), QVariant("Missing function"));
    cmbBxCategory->addItem(tr("Wrong implementation"), QVariant("Wrong implementation"));
    cmbBxCategory->addItem(tr("Usability comment"), QVariant("Usability comment"));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(lblPriority, 0, 0, 1, 1, 0);
    mainLayout->addWidget(cmbBxPriority, 0, 1, 1, 1, 0);
    mainLayout->addItem(new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Fixed), 0, 2, 1, 1, 0);
    mainLayout->addWidget(lblCategory, 0, 3, 1, 1, 0);
    mainLayout->addWidget(cmbBxCategory, 0, 4, 1, 1, 0);
    mainLayout->addItem(new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Fixed), 0, 5, 1, 1, 0);
    mainLayout->addWidget(chbxScreenshot, 0, 6, 1, 1, 0);
    mainLayout->addWidget(lblDescription, 1, 0, 1, 1, 0);
    mainLayout->addWidget(txtBxDescription, 1, 1, 1, 6, 0);

    setLayout(mainLayout);
}

FeedbackPopUp::~FeedbackPopUp()
{

}


void FeedbackPopUp::onEnter(){
    cmbBxCategory->setCurrentIndex(0);
    cmbBxPriority->setCurrentIndex(0);
    chbxScreenshot->setChecked(true);
    txtBxDescription->clear();
}

//PRIVATE SLOTS
void FeedbackPopUp::onConfirm(){

    ftpHandler = new FtpHandler(this);

    connect(ftpHandler, SIGNAL(error(QString)), this, SLOT(errorDurringUpload(QString)));
    connect(ftpHandler, SIGNAL(finished(QString)), this, SLOT(finishedUpload(QString)));

    ftpHandler->setUser("bp", "bp38");
    ftpHandler->setServer("da-frank.de/upload/");
    ftpHandler->setPort(21);

    uploadedFiles = 0;
    hasUploadError = false;

    if(chbxScreenshot->isChecked())
        ftpHandler->uploadFile(StandardPaths::screenshotPath());
    ftpHandler->uploadFile(StandardPaths::errorLog());
    ftpHandler->uploadFile(StandardPaths::sqlLog());
    ftpHandler->uploadFile(StandardPaths::databasePath());
    QFile file(FEEDBACK_FILE_PATH);
    if(file.open(QIODevice::WriteOnly | QFile::Text)){
        QString category = cmbBxCategory->currentText();
        QString priority = cmbBxPriority->currentText();
        QTextStream out(&file);
        out<<category<<"|"<<priority<<"|"<<txtBxDescription->toPlainText();
        file.close();
    }
    ftpHandler->uploadFile(FEEDBACK_FILE_PATH);

    emit closePopUp();
}

void FeedbackPopUp::errorDurringUpload(QString errorMessage){
    emit showMessage(errorMessage, NotificationMessage::ERROR, NotificationMessage::PERSISTENT);
    hasUploadError = true;
}

void FeedbackPopUp::finishedUpload(QString ){
    if((uploadedFiles == 5 && chbxScreenshot->isChecked()) || (uploadedFiles == 4 && !chbxScreenshot->isChecked())){
        ftpHandler->deleteLater();

        if(!hasUploadError){
            manager = new QNetworkAccessManager(this);
            QNetworkRequest request = QNetworkRequest(QUrl("www.da-frank.de/import.php"));

            connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(sentImportRequest(QNetworkReply*)));

            manager->get(request);
        }
    }
    else
        uploadedFiles++;
}

void FeedbackPopUp::sentImportRequest(QNetworkReply *reply){
    if(reply->error() == QNetworkReply::NoError)
        emit showMessage(tr("Feedback has successfully sent!"), NotificationMessage::ACCEPT);
    else
        emit showMessage(reply->errorString(), NotificationMessage::ERROR, NotificationMessage::PERSISTENT);
    reply->deleteLater();
    manager->deleteLater();
}

//Constants
const QString FeedbackPopUp::FEEDBACK_FILE_PATH = QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("feedback.txt");
