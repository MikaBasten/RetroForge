#ifndef ISYSTEM_H
#define ISYSTEM_H

class ISystem {
public:
    virtual void Update(float deltaTime) = 0;
    virtual void Initialize() = 0;
    virtual void Shutdown() = 0;
    // Add other methods as needed
};

#endif // ISYSTEM_H
