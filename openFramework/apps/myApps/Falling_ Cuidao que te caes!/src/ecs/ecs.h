#pragma once
#ifndef ECS_H_
#define ECS_H_
#define Version_2_0
#include "../ofMain.h"

class Entity;
class Manager;

using uint8_t = unsigned char;

using cmpId_type = int;
enum cmpId : cmpId_type {
	_TRANSFORM = 0,
	_INPUT,
	_PLAYER_ANIMATOR,
	_SCORE,
	_LIFE,
	_SHOW_AT_OPPOSITE_SIDE,
	_PLAYER_POWERUP_COMP,
	_COLLIDER,
	_DEACCELERATION,
	_POWERUP_ANIMATOR,
	_DISABLE_ON_EXIT,
	_POWERUP_COMP,
	_OBSTACLE_ANIMATOR,
	// ... (compoment ids)

	// do not remove this
	_LAST_CMP_ID
};
constexpr cmpId_type maxComponentId = _LAST_CMP_ID;

using hdlrId_type = int;
enum hdlrId : hdlrId_type { 
	_hdlr_DIESTRO,
	_hdlr_SINIESTRO,
	
	// do not remove this
	_LAST_HDLR_ID };
constexpr hdlrId_type maxHdlrId = _LAST_HDLR_ID;

using grpId_type = int;
enum grpId : grpId_type {
	_grp_GENERAL,
	_grp_OBSTACLE,
	_grp_POWERUP,
	_grp_UI,
	
	// do not remove this
	_LAST_GRP_ID
};
constexpr grpId_type maxGroupId = _LAST_GRP_ID;
#ifdef Version_2_0
using contId_type = uint8_t;
enum contId : contId_type {
	_cont_OBSTACLE = 0,
	_cont_POWERUP,

	// do not remove this
	_LAST_CONT_ID
};
constexpr contId_type maxControllerId = _LAST_CONT_ID;

#endif
#endif // !ECS_H_