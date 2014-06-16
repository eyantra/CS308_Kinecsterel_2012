#include "firebird_winavr.h"
#ifndef STRLEN
#  define STRLEN 81
#endif
#define _true 1
#define _false 0
typedef unsigned char boolean;
typedef int integer;
typedef char* string;
void Obstacle_Avoidance_I_KINECT(integer);
int Obstacle_Avoidance(void);
int Obstacle_Avoidance_reset(void);
#ifndef _NO_EXTERN_DEFINITIONS
#  ifndef _NO_CONSTANT_DEFINITIONS
#  endif /* _NO_CONSTANT_DEFINITIONS */
#  ifndef _NO_FUNCTION_DEFINITIONS
#  endif /* _NO_FUNCTION_DEFINITIONS */
#  ifndef _NO_PROCEDURE_DEFINITIONS
#  endif /* _NO_PROCEDURE_DEFINITIONS */
#endif /* _NO_EXTERN_DEFINITIONS */

static struct {
  unsigned int KINECT : 1;
  unsigned int MOVE_FWD : 1;
  unsigned int MOVE_REV : 1;
  unsigned int MOTOR_LEFT_SPEED : 1;
  unsigned int MOTOR_RIGHT_SPEED : 1;
} _s = {  0,  0,  0,  0,  0 };
#define tick tick_timer()
static integer KINECT_v;
static integer MOTOR_LEFT_SPEED_v;
static integer MOTOR_RIGHT_SPEED_v;
static integer fir;
static unsigned char _state_1 = 1;
void Obstacle_Avoidance_I_KINECT(integer _v) {
  _s.KINECT = 1;
  KINECT_v = _v;
}

int Obstacle_Avoidance(void)
{
  /* Vacuous terminate */;
  if (_state_1) {
    _s.MOTOR_RIGHT_SPEED = 0;;
    _s.MOTOR_LEFT_SPEED = 0;;
    _s.MOVE_REV = 0;;
    _s.MOVE_FWD = 0;;
    _state_1 = 0;
  } else {
    if (_s.KINECT) {
      _state_1 = 0;
      fir = KINECT_v;
      if ((fir == 1)) {
        _s.MOVE_FWD = 1;
        (MOTOR_LEFT_SPEED_v = 150), (_s.MOTOR_LEFT_SPEED = 1);
        (MOTOR_RIGHT_SPEED_v = 150), (_s.MOTOR_RIGHT_SPEED = 1);
      } else {
        if ((fir == 2)) {
          _s.MOVE_FWD = 1;
          (MOTOR_LEFT_SPEED_v = 130), (_s.MOTOR_LEFT_SPEED = 1);
          (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
        } else {
          if ((fir == 3)) {
            _s.MOVE_FWD = 1;
            (MOTOR_LEFT_SPEED_v = 0), (_s.MOTOR_LEFT_SPEED = 1);
            (MOTOR_RIGHT_SPEED_v = 130), (_s.MOTOR_RIGHT_SPEED = 1);
          } else {
            if ((fir == 4)) {
              _s.MOVE_REV = 1;
              (MOTOR_LEFT_SPEED_v = 150), (_s.MOTOR_LEFT_SPEED = 1);
              (MOTOR_RIGHT_SPEED_v = 150), (_s.MOTOR_RIGHT_SPEED = 1);
            } else {
              if ((fir == 5)) {
                _s.MOVE_FWD = 1;
                (MOTOR_LEFT_SPEED_v = 150), (_s.MOTOR_LEFT_SPEED = 1);
                (MOTOR_RIGHT_SPEED_v = 70), (_s.MOTOR_RIGHT_SPEED = 1);
              } else {
                if ((fir == 6)) {
                  _s.MOVE_FWD = 1;
                  (MOTOR_LEFT_SPEED_v = 70), (_s.MOTOR_LEFT_SPEED = 1);
                  (MOTOR_RIGHT_SPEED_v = 150), (_s.MOTOR_RIGHT_SPEED = 1);
                } else {
                  if ((fir == 7)) {
                    _s.MOVE_FWD = 1;
                    (MOTOR_LEFT_SPEED_v = 0), (_s.MOTOR_LEFT_SPEED = 1);
                    (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
                  }
                }
              }
            }
          }
        }
      }
    } else {
      _state_1 = 0;
    }
  }
  if (_s.MOVE_FWD) { Obstacle_Avoidance_O_MOVE_FWD(); _s.MOVE_FWD = 0; }
  if (_s.MOVE_REV) { Obstacle_Avoidance_O_MOVE_REV(); _s.MOVE_REV = 0; }
  if (_s.MOTOR_LEFT_SPEED) { Obstacle_Avoidance_O_MOTOR_LEFT_SPEED(MOTOR_LEFT_SPEED_v); _s.MOTOR_LEFT_SPEED = 0; }
  if (_s.MOTOR_RIGHT_SPEED) { Obstacle_Avoidance_O_MOTOR_RIGHT_SPEED(MOTOR_RIGHT_SPEED_v); _s.MOTOR_RIGHT_SPEED = 0; }
  _s.KINECT = 0;
  return 1;
}

int Obstacle_Avoidance_reset(void)
{
  _s.KINECT = 0;
  return 0;
}
/****************************** Fire Bird Specific part ***************************/
static int  IR_THRESHHOLD[3] = {50, 50, 50};
Obstacle_Avoidance_O_MOTOR_RIGHT_SPEED(int val)
{
	MOTOR_RIGHT_SPEED(val);
}
Obstacle_Avoidance_O_MOTOR_LEFT_SPEED(int val)
{
	MOTOR_LEFT_SPEED(val);
}
 Obstacle_Avoidance_O_MOVE_REV(void)
{
	MOVE_REV();
}
Obstacle_Avoidance_O_MOVE_FWD(void)
{
	MOVE_FWD();
}

/****************************** Main function ***************************/
void main()
{
 init_devices();
 Obstacle_Avoidance_reset();
 Obstacle_Avoidance();
 while(1)
 {
  Obstacle_Avoidance_I_KINECT(GESTURE_VALUE);
    Obstacle_Avoidance();
 }
}
