#include "cow.h"

Cow::Cow(const std::string& id) : id(id), vaccinated(false) {}

std::string Cow::getId() const {
    return id;
}

bool Cow::isVaccinated() const {
    return vaccinated;
}

void Cow::vaccinate() {
    vaccinated = true;
}
