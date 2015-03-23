#ifndef LANGUAGEPOPUP_H
#define LANGUAGEPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include "../detailedlistitem.h"
#include <QList>

class LanguagePopUp : public AbstractPopUpWidget
{
    Q_OBJECT
public:
    explicit LanguagePopUp(QWidget *parent = 0);
    ~LanguagePopUp();

    int getSelectedLanguage() const;

signals:
    void languageSelected(int id);
    void languageChanged();

public slots:
    void onEnter();

private slots:
    void onConfirm();
    void setSelectedLanguage(int id);

private:
    int selectedLanguageID;
    DetailedListItem *german;
    DetailedListItem *english;
    QList<DetailedListItem*> *languages;

};

#endif // LANGUAGEPOPUP_H
