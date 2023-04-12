#pragma once

#include "ofMain.h"
#include "ecs/Manager.h"
#include "controllers/ObstacleController.h"
#include "controllers/PowerUpController.h"
#include "controllers/CollisionSystem.h"

#include "components/DeAcceleration.h"
#include "components/InputComponent.h"
#include "components/Shape.h"
#include "components/DisableOnExit.h"
#include "components/ShowAtOppositeSide.h"
#include "components/LifeComponent.h"
#include "components/PlayerAnimator.h"
#include "components/AbilityComponent.h"
#include "components/ScoreComponent.h"
#include "components/TextComponent.h"
#include "components/ButtonComponent.h"


class ofApp : public ofBaseApp {
	enum state {
		mainmenu,
		play,
		endmenu,
		size
	};

	bool muelto[2];
	state currentState;
	Manager* managers[state::size];
	Controller* controllers[maxControllerId];
	CollisionSystem* collisionSystem;
	hdlrId_type winner;

	public:
		virtual ~ofApp();

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// Inicializa el MainMenu Manager
		void initMainMenuManager();
		// Inicializa el Play Manager
		void initPlayManager();
		// Inicializa el EndMenu Manager
		void initEndMenuManager();
		// Crea y devuelve una entidad player en el manager recibido
		Entity* createPlayer(Manager* m, hdlrId_type hdlr);
		// Cambia de estado
		void changeState(state newState);
};
