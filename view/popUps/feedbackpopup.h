#ifndef FEEDBACKPOPUP_H
#define FEEDBACKPOPUP_H

#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include "../navigation/abstractpopupwidget.h"
#include "../textlineedit.h"
#include "../textedit.h"
#include "../../ftpHandler/ftphandler.h"

class FeedbackPopUp : public AbstractPopUpWidget
{
    Q_OBJECT
public:
    explicit FeedbackPopUp(QWidget *parent = 0);
    ~FeedbackPopUp();

    int getPriority() const{
        return cmbBxPriority->currentData().toInt();
    }

    QString getCategory() const{
        return cmbBxCategory->currentData().toString();
    }

    QString getDescription() const{
        return txtBxDescription->toPlainText();
    }

    bool getAttachScreenshot() const{
        return chbxScreenshot->isChecked();
    }

public slots:
    void onEnter();

private slots:
    void onConfirm();

    void errorDurringUpload(QString errorMessage);
    void finishedUpload(QString);

    void sentImportRequest(QNetworkReply *reply);

private:
    static const QString FEEDBACK_FILE_PATH;

    QLabel *lblViewName;
    TextLineEdit *txtBxViewName;
    QLabel *lblScreenshot;
    QCheckBox *chbxScreenshot;
    QLabel *lblDescription;
    TextEdit *txtBxDescription;
    QLabel *lblPriority;
    QComboBox *cmbBxPriority;
    QLabel *lblCategory;
    QComboBox *cmbBxCategory;

    FtpHandler *ftpHandler;
    int uploadedFiles;
    bool hasUploadError;
    QNetworkAccessManager *manager;
};

#endif // FEEDBACKPOPUP_H
