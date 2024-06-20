#ifndef COW_H
#define COW_H

#include <string>

class Cow {
public:
    Cow(const std::string& id);
    std::string getId() const;
    bool isVaccinated() const;
    void vaccinate();
    
private:
    std::string id;
    bool vaccinated;
};

#endif // COW_H


