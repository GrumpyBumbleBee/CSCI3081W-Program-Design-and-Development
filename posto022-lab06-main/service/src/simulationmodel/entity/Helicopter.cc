#define _USE_MATH_DEFINES
#include "Helicopter.h"

#include <cmath>
#include <limits>

#include "SimulationModel.h"


Helicopter::Helicopter(const JsonObject& obj) : IEntity(obj) {
    Vector3 destination = {((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400,
    550,
    ((static_cast<double>(rand())) / RAND_MAX) * (1600) - 800};
}

Helicopter::~Helicopter() {}


void Helicopter::update(double dt) {
    // set minimum distance to be considered "at" the destination
    const double MIN_DISTANCE = 0.1;
    if ((position - destination).magnitude() < MIN_DISTANCE) {
        // set a new random destion
        Vector3 newDestination = {((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400,
        550,
        ((static_cast<double>(rand())) / RAND_MAX) * (1600) - 800};

        // Keeping x in range
        if (newDestination.x < -1400) {
            newDestination.x = -1400;
        } else if (newDestination.x > 1500) {
            newDestination.x = 1500;
        }
        // newDestination.y = 550;
        // Keeping z in range
        if (newDestination.z < -800) {
            newDestination.z = -800;
        } else if (newDestination.z > 800) {
            newDestination.z = 800;
        }
        // Set newDestination as destination
        destination = newDestination;
    } else {
        Vector3 diff = destination - position;
        Vector3 diff_unit = diff.unit();
        Vector3 movement_vector = diff_unit * speed * dt;
        position = position + movement_vector;
    }
}
