#define _USE_MATH_DEFINES
#include "Human.h"

#include <cmath>
#include <limits>

#include "SimulationModel.h"


Human::Human(const JsonObject& obj) : IEntity(obj) {
    movingTowardsDestination1 = true;
}

Human::~Human() {}


void Human::update(double dt) {
    Vector3 dest1(146, 265, -121);
    Vector3 dest2(-191, 265, -112);

    Vector3 delta;
    if (movingTowardsDestination1) {
        delta = dest1 - position;
    } else {
        delta = dest2 - position;
    }

    Vector3 direction = delta.unit();

    position += speed * dt * direction;

    if (movingTowardsDestination1 && delta.magnitude() < 0.1) {
        movingTowardsDestination1 = false;
    } else if (!movingTowardsDestination1 && delta.magnitude() < 0.1) {
        movingTowardsDestination1 = true;
    }
}
