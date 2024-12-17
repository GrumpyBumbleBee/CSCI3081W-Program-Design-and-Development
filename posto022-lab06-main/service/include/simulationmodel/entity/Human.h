#ifndef HUMAN_H_
#define HUMAN_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"


/**
 * @class Human
 * @brief Represents a Human in a physical system. 
 */
class Human : public IEntity {
 public:
   /**
   * @brief Humans are created 
   * @param obj JSON object containing the human's information
   */
    Human(const JsonObject& obj);
  /**
   * @brief Destructor
   */
    ~Human();

  /**
   * @brief Updates the human's position
   * @param dt Delta time
   */
    void update(double dt);

    bool movingTowardsDestination1 = true;
};


#endif  // HUMAN_H
