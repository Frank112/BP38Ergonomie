#ifndef IBRANCHOFINDUSTRY
#define IBRANCHOFINDUSTRY

#include <QtPlugin>

/**
 * @brief The IBranchOfIndustry class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a branch of industry is provided.
 *
 * @author Frank Loeffler
 */
class IBranchOfIndustry {

signals:
    /**
     * @brief saveBranchOfIndustry A signal that can be emitted to signal that a branch of industry with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveBranchOfIndustry(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setBranchOfIndustry Sets the branch of industry to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setBranchOfIndustry(QHash<QString, QVariant> values) = 0;
};


#define IBranchOfIndustry_iid "IBranchOfIndustry"
Q_DECLARE_INTERFACE(IBranchOfIndustry, IBranchOfIndustry_iid)

#endif // IBRANCHOFINDUSTRY

