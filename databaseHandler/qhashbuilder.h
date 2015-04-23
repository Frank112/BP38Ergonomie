#ifndef QHASHBUILDER_H
#define QHASHBUILDER_H

#include <QHash>
#include <QStringList>
#include <QList>


template <class T, class U>
/**
 * @brief The QHashBuilder class is for building generic static QHash
 * objects.
 *
 * @author Frank Loeffler
 */
class QHashBuilder
{
public:
    /**
     * @brief Creates a new QHashBuilder object.
     */
    QHashBuilder(){

    }

    /**
     * @brief Adds a new entry to the hash map.
     *
     * @param key
     *          The key of the new entry.
     * @param value
     *          The value of the key for the new entry.
     * @return
     *          The current object.
     */
    QHashBuilder& add(const T &key, const U &value){
        hash.insert(key, value);
        return *this;
    }

    /**
     * @brief Returns the constructed generic QHash object.
     *
     * @return
     *      The constructed QHash object with the QHashBuilder.
     */
    QHash<T, U> build(){
        return hash;
    }

private:
    QHash<T, U> hash;
};

#endif // QHASHBUILDER_H
