#ifndef API_BRIDGE_GRANDEXCHANGEOFFER_H
#define API_BRIDGE_GRANDEXCHANGEOFFER_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

/*!
 * \brief Represents an offer put in the Grand Exchange.
 *
 * Besides standard peer-to-peer trading Runescape offers the
 * option to trade with others through a service called
 * the Grand Exchange.
 *
 * Offers consists of selling or buying of Items and hence
 * contain a set of information about the offer.
 *
 * \internal the ID is the Item ID (most likely)
 */

class GrandExchangeOffer : public Object {
public:
    RS_OBJECT(GrandExchangeOffer)

    /*!
     * \brief Returns the ID corresponding with the Item(s) bought/sold.
     * \return The ID of the corresponding Item
     */
    JACE_PROXY_API JLong getID();

    /*!
     * \brief Returns the price forwhich the Item(s) is being bought/sold.
     * \return The buy/sell price.
     */
    JACE_PROXY_API JInt getPrice();

    /*!
     * \brief Returns the amount of money put in to buy the Item(s).
     * \return The buy/sell price.
     */
    JACE_PROXY_API JInt getSpent();

    /*!
     * \brief Returns the state the offer.
     *
     * The state of an offer is one of three which provide key information.
     * \li \c Pending waiting for Item(s) to sell/buy for the given price.
     * \li \c Finished all Item(s) have been sold/bought for their given price or better.
     * \li \c Cancelled the offer was cancelled.
     *
     * \return The state of the offer.
     * \internal which byte corresponds with which type?
     */
    JACE_PROXY_API JByte getState();

    /*!
     * \brief Returns the ??? of the Item is being bought/sold.
     * \return The buy/sell price.
     * \internal the amount of items being bought/sold???
     */
    JACE_PROXY_API JInt getTotal();

    /*!
     * \brief Returns the amount Item(s) already bought/sold.
     * \return The number of Item(s) already bought/sold.
     */
    JACE_PROXY_API JInt getTransferred();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_GRANDEXCHANGEOFFER_H
