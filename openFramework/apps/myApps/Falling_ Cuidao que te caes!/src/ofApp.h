#pragma once
#include <array>

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

enum state {
	mainmenu,
	play,
	endmenu,
	size
};

class ofApp : public ofBaseApp {
	array<ofSoundPlayer*, maxSound> sounds;

	bool muelto[2];
	int scoreD, scoreS;
	hdlrId_type winner;

	state currentState, futureState;
	Manager* mngr;
	Controller* controllers[maxControllerId];
	CollisionSystem* collisionSystem;

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

		// Carga los sonidos del juego
		void loadSounds();
		// Inicializa el MainMenu Manager
		void initMainMenuManager();
		// Inicializa el Play Manager
		void initPlayManager();
		// Inicializa el EndMenu Manager
		void initEndMenuManager();
		// Crea y devuelve una entidad player en el manager recibido
		Entity* createPlayer(Manager* m, hdlrId_type hdlr);
		// Setea el estado destino al deseado
		inline void setFutureState(state newState) { futureState = newState; }
		// Cambia de estado
		void changeState();
};