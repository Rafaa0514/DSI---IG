#ifndef Road_h
#define Road_h

#include "GameObject.h"

class Road : public GameObject{
    
    vector<ofLight> lights;
    ofPlanePrimitive plane;
public:
    Road(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Road();
    
    void draw() override;
    void drawDebug() override;
    
    void setLights(float dimZ);
};

#endif /* Road_h */
