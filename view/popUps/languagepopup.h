#ifndef LANGUAGEPOPUP_H
#define LANGUAGEPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include "../detailedlistitem.h"
#include <QList>

/**
 * @brief The LanguagePopUp class provides functionality to choose the language of the application from a
 * list of languages displayed in a popup.
 *
 * ProductPopUp inherits AbstractPopUpWidget..
 *
 * @author Markus Danz
 */
class LanguagePopUp : public AbstractPopUpWidget
{
    Q_OBJECT
public:
    /**
     * @brief LanguagePopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit LanguagePopUp(QWidget *parent = 0);
    ~LanguagePopUp();

    /**
     * @brief getSelectedLanguage Returns the id of the currently selected language.
     * @return The id of the selected language.
     */
    int getSelectedLanguage() const;

signals:
    /**
     * @brief languageSelected A signal to indicate that the language with <i>id</i> is selected.
     * @param id The id of the language selected.
     */
    void languageSelected(int id);

    /**
     * @brief languageChanged A signal to indicate that the selected language changed.
     */
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
