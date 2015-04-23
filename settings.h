#ifndef SETTINGS
#define SETTINGS

#include <QString>
#include <QHash>
#include <QVariant>
#include <QFile>
#include <QTextStream>

/**
 * @brief The Settings class handles all settings of the application.
 *
 * @author Frank Loeffler
 */
class Settings{

public:
    /**
     * @brief Creates a new setting with the given identifier and
     * the given value of this setting.
     *
     * @param key
     *          The identifier of the setting. Iff this identifier is
     *          already uses the value gets replaced by the new given
     *          value.
     * @param value
     *          The value of the setting with the given identifier.
     */
    static void insert(const QString &key, const QVariant &value);

    /**
     * @brief Returns the value of the setting with the given
     * identifier. Iff the given identifier was never inserted than
     * you get a default-constructed value.
     *
     * @param key
     *          The identifier of the setting.
     * @return
     *          The value of the setting with the given identifier.
     */
    static QVariant value(const QString &key);

    /**
     * @brief Indicates whether the given identifier is already inserted
     * as a setting or not.
     *
     * @param key
     *          The identifier to check.
     * @return
     *          true iff the identifier was already inserted.
     */
    static bool contains(const QString &key);

    /**
     * @brief Loads all settings from the file with the given absolute file path.
     * A setting in the file has the following syntax:
     * [identifier]=[value]
     *
     * <b>Note:</b> All other settings iff their identifier
     * is not containd as a setting in the file are not affected.
     *
     * @param path
     *      The absolute path to the file with the settings.
     */
    static void loadSettings(const QString &path);

    /**
     * @brief Saves all the settings which are inserted as a
     * setting as a file at the given absolute file path.
     *
     * A setting in the file has the following syntax:
     * [identifier]=[value]
     *
     * @param path
     *      The absolute file path to save the file with the settings.
     */
    static void saveSettings(const QString &path);

    /**
     * @brief Constant identifier for the theme setting.
     */
    static const QString SETTING_THEME;

    /**
     * @brief Constant identifier for the selected theme blue
     */
    static const QString THEME_BLUE;

    /**
     * @brief Constant identifier for the selected theme green
     */
    static const QString THEME_GREEN;

    /**
     * @brief Constant identifier for the language setting.
     */
    static const QString SETTING_LANGUAGE;

    /**
     * @brief Constant identifier for the selected language german
     */
    static const QString LANGUAGE_GERMAN;

    /**
     * @brief Constant identifier for the selected language english
     */
    static const QString LANGUAGE_ENGLISH;

    /**
     * @brief Constant identifier for the notification setting.
     */
    static const QString SETTING_SHOW_NOTIFICATIONS;

    /**
     * @brief Constant identifier for the navigation title setting.
     */
    static const QString SETTING_SHOW_NAVIGATION_TITLE;

private:
    static QHash<QString, QVariant> settings;

};

#endif // SETTINGS

