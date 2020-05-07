#ifndef asynMotorControllerParamSet_H
#define asynMotorControllerParamSet_H


#define motorMoveRelString              "MOTOR_MOVE_REL"
#define motorMoveAbsString              "MOTOR_MOVE_ABS"
#define motorMoveVelString              "MOTOR_MOVE_VEL"
#define motorHomeString                 "MOTOR_HOME"
#define motorStopString                 "MOTOR_STOP_AXIS"
#define motorVelocityString             "MOTOR_VELOCITY"
#define motorVelBaseString              "MOTOR_VEL_BASE"
#define motorAccelString                "MOTOR_ACCEL"
#define motorPositionString             "MOTOR_POSITION"
#define motorEncoderPositionString      "MOTOR_ENCODER_POSITION"
#define motorDeferMovesString           "MOTOR_DEFER_MOVES"
#define motorMoveToHomeString           "MOTOR_MOVE_HOME"
#define motorResolutionString           "MOTOR_RESOLUTION"
#define motorEncoderRatioString         "MOTOR_ENCODER_RATIO"
#define motorPGainString                "MOTOR_PGAIN"
#define motorIGainString                "MOTOR_IGAIN"
#define motorDGainString                "MOTOR_DGAIN"
#define motorHighLimitString            "MOTOR_HIGH_LIMIT"
#define motorLowLimitString             "MOTOR_LOW_LIMIT"
#define motorClosedLoopString           "MOTOR_CLOSED_LOOP"
#define motorPowerAutoOnOffString       "MOTOR_POWER_AUTO_ONOFF"
#define motorPowerOnDelayString         "MOTOR_POWER_ON_DELAY"
#define motorPowerOffDelayString        "MOTOR_POWER_OFF_DELAY"
#define motorPowerOffFractionString     "MOTOR_POWER_OFF_FRACTION"
#define motorPostMoveDelayString        "MOTOR_POST_MOVE_DELAY"
#define motorStatusString               "MOTOR_STATUS"
#define motorUpdateStatusString         "MOTOR_UPDATE_STATUS"
#define motorStatusDirectionString      "MOTOR_STATUS_DIRECTION"
#define motorStatusDoneString           "MOTOR_STATUS_DONE"
#define motorStatusHighLimitString      "MOTOR_STATUS_HIGH_LIMIT"
#define motorStatusAtHomeString         "MOTOR_STATUS_AT_HOME"
#define motorStatusSlipString           "MOTOR_STATUS_SLIP"
#define motorStatusPowerOnString        "MOTOR_STATUS_POWERED"
#define motorStatusFollowingErrorString "MOTOR_STATUS_FOLLOWING_ERROR"
#define motorStatusHomeString           "MOTOR_STATUS_HOME"
#define motorStatusHasEncoderString     "MOTOR_STATUS_HAS_ENCODER"
#define motorStatusProblemString        "MOTOR_STATUS_PROBLEM"
#define motorStatusMovingString         "MOTOR_STATUS_MOVING"
#define motorStatusGainSupportString    "MOTOR_STATUS_GAIN_SUPPORT"
#define motorStatusCommsErrorString     "MOTOR_STATUS_COMMS_ERROR"
#define motorStatusLowLimitString       "MOTOR_STATUS_LOW_LIMIT"
#define motorStatusHomedString          "MOTOR_STATUS_HOMED"
#define motorRecResolutionString        "MOTOR_REC_RESOLUTION"
#define motorRecDirectionString         "MOTOR_REC_DIRECTION"
#define motorRecOffsetString            "MOTOR_REC_OFFSET"
#define profileNumAxesString            "PROFILE_NUM_AXES"
#define profileNumPointsString          "PROFILE_NUM_POINTS"
#define profileCurrentPointString       "PROFILE_CURRENT_POINT"
#define profileNumPulsesString          "PROFILE_NUM_PULSES"
#define profileStartPulsesString        "PROFILE_START_PULSES"
#define profileEndPulsesString          "PROFILE_END_PULSES"
#define profileActualPulsesString       "PROFILE_ACTUAL_PULSES"
#define profileNumReadbacksString       "PROFILE_NUM_READBACKS"
#define profileTimeModeString           "PROFILE_TIME_MODE"
#define profileFixedTimeString          "PROFILE_FIXED_TIME"
#define profileTimeArrayString          "PROFILE_TIME_ARRAY"
#define profileAccelerationString       "PROFILE_ACCELERATION"
#define profileMoveModeString           "PROFILE_MOVE_MODE"
#define profileBuildString              "PROFILE_BUILD"
#define profileBuildStateString         "PROFILE_BUILD_STATE"
#define profileBuildStatusString        "PROFILE_BUILD_STATUS"
#define profileBuildMessageString       "PROFILE_BUILD_MESSAGE"
#define profileExecuteString            "PROFILE_EXECUTE"
#define profileExecuteStateString       "PROFILE_EXECUTE_STATE"
#define profileExecuteStatusString      "PROFILE_EXECUTE_STATUS"
#define profileExecuteMessageString     "PROFILE_EXECUTE_MESSAGE"
#define profileAbortString              "PROFILE_ABORT"
#define profileReadbackString           "PROFILE_READBACK"
#define profileReadbackStateString      "PROFILE_READBACK_STATE"
#define profileReadbackStatusString     "PROFILE_READBACK_STATUS"
#define profileReadbackMessageString    "PROFILE_READBACK_MESSAGE"
#define profileUseAxisString            "PROFILE_USE_AXIS"
#define profilePositionsString          "PROFILE_POSITIONS"
#define profileReadbacksString          "PROFILE_READBACKS"
#define profileFollowingErrorsString    "PROFILE_FOLLOWING_ERRORS"


#ifdef __cplusplus
#include "asynParamSet.h"

class asynMotorControllerParamSet : virtual public asynParamSet {

  public:
  asynMotorControllerParamSet() {
    std::cout << "motorControllerParamSet" << std::endl;
    this->add(motorMoveRelString, asynParamFloat64, &motorMoveRel_);
    this->add(motorMoveAbsString, asynParamFloat64, &motorMoveAbs_);
    this->add(motorMoveVelString, asynParamFloat64, &motorMoveVel_);
    this->add(motorHomeString, asynParamFloat64, &motorHome_);
    this->add(motorStopString, asynParamInt32, &motorStop_);
    this->add(motorVelocityString, asynParamFloat64, &motorVelocity_);
    this->add(motorVelBaseString, asynParamFloat64, &motorVelBase_);
    this->add(motorAccelString, asynParamFloat64, &motorAccel_);
    this->add(motorPositionString, asynParamFloat64, &motorPosition_);
    this->add(motorEncoderPositionString, asynParamFloat64, &motorEncoderPosition_);
    this->add(motorDeferMovesString, asynParamInt32, &motorDeferMoves_);
    this->add(motorMoveToHomeString, asynParamInt32, &motorMoveToHome_);
    this->add(motorResolutionString, asynParamFloat64, &motorResolution_);
    this->add(motorEncoderRatioString, asynParamFloat64, &motorEncoderRatio_);
    this->add(motorPGainString, asynParamFloat64, &motorPGain_);
    this->add(motorIGainString, asynParamFloat64, &motorIGain_);
    this->add(motorDGainString, asynParamFloat64, &motorDGain_);
    this->add(motorHighLimitString, asynParamFloat64, &motorHighLimit_);
    this->add(motorLowLimitString, asynParamFloat64, &motorLowLimit_);
    this->add(motorClosedLoopString, asynParamInt32, &motorClosedLoop_);
    this->add(motorPowerAutoOnOffString, asynParamInt32, &motorPowerAutoOnOff_);
    this->add(motorPowerOnDelayString, asynParamFloat64, &motorPowerOnDelay_);
    this->add(motorPowerOffDelayString, asynParamFloat64, &motorPowerOffDelay_);
    this->add(motorPowerOffFractionString, asynParamInt32, &motorPowerOffFraction_);
    this->add(motorPostMoveDelayString, asynParamFloat64, &motorPostMoveDelay_);
    this->add(motorStatusString, asynParamInt32, &motorStatus_);
    this->add(motorUpdateStatusString, asynParamInt32, &motorUpdateStatus_);
    this->add(motorStatusDirectionString, asynParamInt32, &motorStatusDirection_);
    this->add(motorStatusDoneString, asynParamInt32, &motorStatusDone_);
    this->add(motorStatusHighLimitString, asynParamInt32, &motorStatusHighLimit_);
    this->add(motorStatusAtHomeString, asynParamInt32, &motorStatusAtHome_);
    this->add(motorStatusSlipString, asynParamInt32, &motorStatusSlip_);
    this->add(motorStatusPowerOnString, asynParamInt32, &motorStatusPowerOn_);
    this->add(motorStatusFollowingErrorString, asynParamInt32, &motorStatusFollowingError_);
    this->add(motorStatusHomeString, asynParamInt32, &motorStatusHome_);
    this->add(motorStatusHasEncoderString, asynParamInt32, &motorStatusHasEncoder_);
    this->add(motorStatusProblemString, asynParamInt32, &motorStatusProblem_);
    this->add(motorStatusMovingString, asynParamInt32, &motorStatusMoving_);
    this->add(motorStatusGainSupportString, asynParamInt32, &motorStatusGainSupport_);
    this->add(motorStatusCommsErrorString, asynParamInt32, &motorStatusCommsError_);
    this->add(motorStatusLowLimitString, asynParamInt32, &motorStatusLowLimit_);
    this->add(motorStatusHomedString, asynParamInt32, &motorStatusHomed_);
    this->add(motorRecResolutionString, asynParamFloat64, &motorRecResolution_);
    this->add(motorRecDirectionString, asynParamInt32, &motorRecDirection_);
    this->add(motorRecOffsetString, asynParamFloat64, &motorRecOffset_);
    this->add(profileNumAxesString, asynParamInt32, &profileNumAxes_);
    this->add(profileNumPointsString, asynParamInt32, &profileNumPoints_);
    this->add(profileCurrentPointString, asynParamInt32, &profileCurrentPoint_);
    this->add(profileNumPulsesString, asynParamInt32, &profileNumPulses_);
    this->add(profileStartPulsesString, asynParamInt32, &profileStartPulses_);
    this->add(profileEndPulsesString, asynParamInt32, &profileEndPulses_);
    this->add(profileActualPulsesString, asynParamInt32, &profileActualPulses_);
    this->add(profileNumReadbacksString, asynParamInt32, &profileNumReadbacks_);
    this->add(profileTimeModeString, asynParamInt32, &profileTimeMode_);
    this->add(profileFixedTimeString, asynParamFloat64, &profileFixedTime_);
    this->add(profileTimeArrayString, asynParamFloat64Array, &profileTimeArray_);
    this->add(profileAccelerationString, asynParamFloat64, &profileAcceleration_);
    this->add(profileMoveModeString, asynParamInt32, &profileMoveMode_);
    this->add(profileBuildString, asynParamInt32, &profileBuild_);
    this->add(profileBuildStateString, asynParamInt32, &profileBuildState_);
    this->add(profileBuildStatusString, asynParamInt32, &profileBuildStatus_);
    this->add(profileBuildMessageString, asynParamOctet, &profileBuildMessage_);
    this->add(profileExecuteString, asynParamInt32, &profileExecute_);
    this->add(profileExecuteStateString, asynParamInt32, &profileExecuteState_);
    this->add(profileExecuteStatusString, asynParamInt32, &profileExecuteStatus_);
    this->add(profileExecuteMessageString, asynParamOctet, &profileExecuteMessage_);
    this->add(profileAbortString, asynParamInt32, &profileAbort_);
    this->add(profileReadbackString, asynParamInt32, &profileReadback_);
    this->add(profileReadbackStateString, asynParamInt32, &profileReadbackState_);
    this->add(profileReadbackStatusString, asynParamInt32, &profileReadbackStatus_);
    this->add(profileReadbackMessageString, asynParamOctet, &profileReadbackMessage_);
    this->add(profileUseAxisString, asynParamInt32, &profileUseAxis_);
    this->add(profilePositionsString, asynParamFloat64Array, &profilePositions_);
    this->add(profileReadbacksString, asynParamFloat64Array, &profileReadbacks_);
    this->add(profileFollowingErrorsString, asynParamFloat64Array, &profileFollowingErrors_);
  }

  #define FIRST_MOTOR_PARAM_INDEX motorMoveRel_
  int motorMoveRel_;
  int motorMoveAbs_;
  int motorMoveVel_;
  int motorHome_;
  int motorStop_;
  int motorVelocity_;
  int motorVelBase_;
  int motorAccel_;
  int motorPosition_;
  int motorEncoderPosition_;
  int motorDeferMoves_;
  int motorMoveToHome_;
  int motorResolution_;
  int motorEncoderRatio_;
  int motorPGain_;
  int motorIGain_;
  int motorDGain_;
  int motorHighLimit_;
  int motorLowLimit_;
  int motorClosedLoop_;
  int motorPowerAutoOnOff_;
  int motorPowerOnDelay_;
  int motorPowerOffDelay_;
  int motorPowerOffFraction_;
  int motorPostMoveDelay_;
  int motorStatus_;
  int motorUpdateStatus_;
  int motorStatusDirection_;
  int motorStatusDone_;
  int motorStatusHighLimit_;
  int motorStatusAtHome_;
  int motorStatusSlip_;
  int motorStatusPowerOn_;
  int motorStatusFollowingError_;
  int motorStatusHome_;
  int motorStatusHasEncoder_;
  int motorStatusProblem_;
  int motorStatusMoving_;
  int motorStatusGainSupport_;
  int motorStatusCommsError_;
  int motorStatusLowLimit_;
  int motorStatusHomed_;
  int motorRecResolution_;
  int motorRecDirection_;
  int motorRecOffset_;
  int profileNumAxes_;
  int profileNumPoints_;
  int profileCurrentPoint_;
  int profileNumPulses_;
  int profileStartPulses_;
  int profileEndPulses_;
  int profileActualPulses_;
  int profileNumReadbacks_;
  int profileTimeMode_;
  int profileFixedTime_;
  int profileTimeArray_;
  int profileAcceleration_;
  int profileMoveMode_;
  int profileBuild_;
  int profileBuildState_;
  int profileBuildStatus_;
  int profileBuildMessage_;
  int profileExecute_;
  int profileExecuteState_;
  int profileExecuteStatus_;
  int profileExecuteMessage_;
  int profileAbort_;
  int profileReadback_;
  int profileReadbackState_;
  int profileReadbackStatus_;
  int profileReadbackMessage_;
  int profileUseAxis_;
  int profilePositions_;
  int profileReadbacks_;
  int profileFollowingErrors_;
  #define LAST_MOTOR_PARAM_INDEX profileFollowingErrors_
};

#define NUM_MOTOR_DRIVER_PARAMS (&LAST_MOTOR_PARAM_INDEX - &FIRST_MOTOR_PARAM_INDEX + 1)

#endif /* __cplusplus */

#endif /* asynMotorControllerParamSet_H */
