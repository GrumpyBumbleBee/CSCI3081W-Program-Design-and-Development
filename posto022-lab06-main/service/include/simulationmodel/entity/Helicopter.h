#ifndef HELICOPTER_H_
#define HELICOPTER_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"

// class Package;

// // Represents a drone in a physical system.
// // Drones move using euler integration based on a specified
// // velocity and direction.

/**
 * @class Helicopter 
 * @brief Represents a Helicopter in a physical system. 
 */
class Helicopter : public IEntity {
 public:
   /**
   * @brief Helicoptors are created
   * @param obj JSON object containing the Helicopter's information
   */
    Helicopter(const JsonObject& obj);
  /**
   * @brief Destructor
   */
    ~Helicopter();

  /**
   * @brief Updates the Helicopter's position
   * @param dt Delta time
   */
    void update(double dt);

    Vector3 destination;  // Current destination
};

#endif  // HELICOPTER_H
