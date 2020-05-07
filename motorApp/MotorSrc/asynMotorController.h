/* asynMotorController.h
 *
 * Mark Rivers
 *
 * This file defines the base class for an asynMotorController.  It is the class
 * from which real motor controllers are derived.  It derives from asynPortDriver.
 */
#ifndef asynMotorController_H
#define asynMotorController_H

#include <epicsEvent.h>
#include <epicsTypes.h>

#include "asynMotorControllerParamSet.h"

#define MAX_CONTROLLER_STRING_SIZE 256
#define DEFAULT_CONTROLLER_TIMEOUT 2.0


/** The structure that is passed back to devMotorAsyn when the status changes. */
typedef struct MotorStatus {
  double position;           /**< Commanded motor position */
  double encoderPosition;    /**< Actual encoder position */
  double velocity;           /**< Actual velocity */
  epicsUInt32 status;        /**< Word containing status bits (motion done, limits, etc.) */
} MotorStatus;

enum ProfileTimeMode{
  PROFILE_TIME_MODE_FIXED,
  PROFILE_TIME_MODE_ARRAY
};

enum ProfileMoveMode{
  PROFILE_MOVE_MODE_ABSOLUTE,
  PROFILE_MOVE_MODE_RELATIVE
};

/* State codes for Build, Read and Execute. Careful, these must match the
 * corresponding MBBI records, but there is no way to check this */
enum ProfileBuildState{
  PROFILE_BUILD_DONE,
  PROFILE_BUILD_BUSY
};

enum ProfileExecuteState{
  PROFILE_EXECUTE_DONE,
  PROFILE_EXECUTE_MOVE_START,
  PROFILE_EXECUTE_EXECUTING,
  PROFILE_EXECUTE_FLYBACK
};

enum ProfileReadbackState{
  PROFILE_READBACK_DONE,
  PROFILE_READBACK_BUSY
};


/* Status codes for Build, Execute and Read */
enum ProfileStatus {
  PROFILE_STATUS_UNDEFINED,
  PROFILE_STATUS_SUCCESS,
  PROFILE_STATUS_FAILURE,
  PROFILE_STATUS_ABORT,
  PROFILE_STATUS_TIMEOUT
};

#ifdef __cplusplus
#include <asynPortDriver.h>

class asynMotorAxis;

class epicsShareClass asynMotorController : public asynPortDriver {

  public:
  /* This is the constructor for the class. */
  asynMotorController(
    asynMotorControllerParamSet* paramSet,
    const char *portName,
    int numAxes,
    int interfaceMask,
    int interruptMask,
    int asynFlags,
    int autoConnect,
    int priority,
    int stackSize
  );

  virtual ~asynMotorController();

  /* These are the methods that we override from asynPortDriver */
  virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);
  virtual asynStatus writeFloat64(asynUser *pasynUser, epicsFloat64 value);
  virtual asynStatus writeFloat64Array(asynUser *pasynUser, epicsFloat64 *value, size_t nElements);
  virtual asynStatus readFloat64Array(asynUser *pasynUser, epicsFloat64 *value, size_t nElements, size_t *nRead);
  virtual asynStatus readGenericPointer(asynUser *pasynUser, void *pointer);
  virtual void report(FILE *fp, int details);

  /* These are the methods that are new to this class */
  virtual asynMotorAxis* getAxis(asynUser *pasynUser);
  virtual asynMotorAxis* getAxis(int axisNo);
  virtual asynStatus startPoller(double movingPollPeriod, double idlePollPeriod, int forcedFastPolls);
  virtual asynStatus wakeupPoller();
  virtual asynStatus poll();
  virtual asynStatus setDeferredMoves(bool defer);
  void asynMotorPoller();  // This should be private but is called from C function

  /* Functions to deal with moveToHome.*/
  virtual asynStatus startMoveToHomeThread();
  void asynMotorMoveToHome();

  /* These are the functions for profile moves */
  virtual asynStatus initializeProfile(size_t maxPoints);
  virtual asynStatus buildProfile();
  virtual asynStatus executeProfile();
  virtual asynStatus abortProfile();
  virtual asynStatus readbackProfile();

  virtual asynStatus setMovingPollPeriod(double movingPollPeriod);
  virtual asynStatus setIdlePollPeriod(double idlePollPeriod);

  int shuttingDown_;   /**< Flag indicating that IOC is shutting down.  Stops poller */

  protected:
  asynMotorControllerParamSet* paramSet;
  int numAxes_;                 /**< Number of axes this controller supports */
  asynMotorAxis **pAxes_;       /**< Array of pointers to axis objects */
  epicsEventId pollEventId_;    /**< Event ID to wake up poller */
  epicsEventId moveToHomeId_;    /**< Event ID to wake up move to home thread */
  double idlePollPeriod_;       /**< The time between polls when no axes are moving */
  double movingPollPeriod_;     /**< The time between polls when any axis is moving */
  int    forcedFastPolls_;      /**< The number of forced fast polls when the poller wakes up */

  size_t maxProfilePoints_;     /**< Maximum number of profile points */
  double *profileTimes_;        /**< Array of times per profile point */

  int moveToHomeAxis_;

  /* These are convenience functions for controllers that use asynOctet interfaces to the hardware */
  asynStatus writeController();
  asynStatus writeController(const char *output, double timeout);
  asynStatus writeReadController();
  asynStatus writeReadController(const char *output, char *response, size_t maxResponseLen, size_t *responseLen, double timeout);
  asynUser *pasynUserController_;
  char outString_[MAX_CONTROLLER_STRING_SIZE];
  char inString_[MAX_CONTROLLER_STRING_SIZE];

  friend class asynMotorAxis;
};

#endif /* _cplusplus */
#endif /* asynMotorController_H */
