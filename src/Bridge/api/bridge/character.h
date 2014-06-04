#ifndef API_BRIDGE_CHARACTER_H
#define API_BRIDGE_CHARACTER_H

#include "MethodHelper.h"
#include "animable.h"

namespace api {
namespace bridge {

class Animator;
class LinkedList;
class AbstractModel;
class OverheadMessage;
class PassiveAnimator;

/*!
 * \brief Represents a Character in the Runescape world
 *
 * Player and NPC objects qualify as Characters. Such objects
 * have specific properties that are unique to characters, such as
 * an OverheadMessage and movement speed.
 */
class Character : public Animable {
public:
    RS_OBJECT(Character)

    /*!
     * \brief The active Animator for this Character
     *
     * The active animator describes the animation currently in progress.
     */
    JACE_PROXY_API Animator getActiveAnimator();
    /*!
     * @brief Returns the current Animation ID
     * @return the current Animation ID
     */
    JACE_PROXY_API JInt getAnimationID();
    JACE_PROXY_API QList<JInt> getAnimationQueue();
    JACE_PROXY_API LinkedList getCombatList();
    /*!
     * \brief The height of the Character's model
     */
    JACE_PROXY_API JInt getHeight();    
    JACE_PROXY_API JInt getInteracting();
    /*!
     * \brief The number local X-axis coordinate
     *
     * The local X coordinate is based on the loaded BaseTile corresponding with that area (relative).
     */
    JACE_PROXY_API JInt getLocalX();
    /*!
     * \brief The number local Y-axis coordinate
     *
     * The local Y coordinate is based on the loaded BaseTile corresponding with that area (relative).
     */
    JACE_PROXY_API JInt getLocalY();
    /*!
     * \brief The X-axis coordinate
     *
     * The X coordinate based on the Runescape World grid (absolute).
     */
    JACE_PROXY_API JInt getLocationX();
    /*!
     * \brief The Y-axis coordinate
     *
     * The Y coordinate based on the Runescape World grid (absolute).
     */
    JACE_PROXY_API JInt getLocationY();
    /*!
     * \brief The list of available models for this Character
     *
     * This includes the DirectX, OpenGL and LD models for the
     * Character.
     */
    JACE_PROXY_API QList<AbstractModel> getModels();
    /*!
     * \brief the movement speed of the Character
     */
    JACE_PROXY_API JInt getMovementSpeed();
    /*!
     * \brief Returns the orientation of the Character
     * \return the Character's orientation
     */
    JACE_PROXY_API JInt getOrientation();
    /*!
     * \brief the OverheadMessage for this Character
     *
     * This indicates the message displayed over the head of the character in the world.
     */
    JACE_PROXY_API OverheadMessage getOverheadMessage();
    /*!
     * \brief The passive Animator for this Character
     *
     * The passive animator performs the idle animation which is displayed if
     * no active Animator is present.
     */
    JACE_PROXY_API PassiveAnimator getPassiveAnimator();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_CHARACTER_H
