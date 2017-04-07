//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: odometryadaptor.cpp
//
// Code generated for Simulink model 'odometryadaptor'.
//
// Model version                  : 1.73
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Apr  7 13:59:26 2017
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "odometryadaptor.h"
#include "odometryadaptor_private.h"

// Named constants for Chart: '<Root>/Chart'
#define odometryadap_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define odometryadaptor_IN_Idle        ((uint8_T)1U)
#define odometryadaptor_IN_Moving      ((uint8_T)2U)
#define odometryadaptor_IN_Stopped     ((uint8_T)3U)
#define odometryadaptor_MessageQueueLen (1)

// Block signals (auto storage)
B_odometryadaptor_T odometryadaptor_B;

// Block states (auto storage)
DW_odometryadaptor_T odometryadaptor_DW;

// Real-time model
RT_MODEL_odometryadaptor_T odometryadaptor_M_;
RT_MODEL_odometryadaptor_T *const odometryadaptor_M = &odometryadaptor_M_;

// Model step function
void odometryadaptor_step(void)
{
  boolean_T varargout_1;
  SL_Bus_odometryadaptor_geometry_msgs_Twist varargout_2;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S7>/In1'
  //   MATLABSystem: '<S4>/SourceBlock'

  varargout_1 = Sub_odometryadaptor_88.getLatestMessage
    (&odometryadaptor_B.BusAssignment);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  if (varargout_1) {
    odometryadaptor_B.In1 = odometryadaptor_B.BusAssignment;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S6>/In1'
  //   MATLABSystem: '<S3>/SourceBlock'

  varargout_1 = Sub_odometryadaptor_1.getLatestMessage(&varargout_2);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (varargout_1) {
    odometryadaptor_B.In1_m = varargout_2;
  }

  // End of Start for MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Chart: '<Root>/Chart'
  // Gateway: Chart
  // During: Chart
  if (odometryadaptor_DW.is_active_c3_odometryadaptor == 0U) {
    // Entry: Chart
    odometryadaptor_DW.is_active_c3_odometryadaptor = 1U;

    // Entry Internal: Chart
    // Transition: '<S1>:5'
    odometryadaptor_DW.is_c3_odometryadaptor = odometryadaptor_IN_Idle;
  } else {
    switch (odometryadaptor_DW.is_c3_odometryadaptor) {
     case odometryadaptor_IN_Idle:
      // During 'Idle': '<S1>:4'
      // '<S1>:7:1' sf_internal_predicateOutput = ...
      // '<S1>:7:1' vel > 0.2;
      if (odometryadaptor_B.In1_m.Linear.X > 0.2) {
        // Transition: '<S1>:7'
        odometryadaptor_DW.is_c3_odometryadaptor = odometryadaptor_IN_Moving;
      } else {
        // '<S1>:4:1' stopped = true;
        odometryadaptor_B.stopped = true;
      }
      break;

     case odometryadaptor_IN_Moving:
      // During 'Moving': '<S1>:6'
      // '<S1>:9:1' sf_internal_predicateOutput = ...
      // '<S1>:9:1' vel < 0.1;
      if (odometryadaptor_B.In1_m.Linear.X < 0.1) {
        // Transition: '<S1>:9'
        odometryadaptor_DW.is_c3_odometryadaptor = odometryadaptor_IN_Stopped;
      } else {
        // '<S1>:6:1' stopped = false;
        odometryadaptor_B.stopped = false;
      }
      break;

     default:
      // During 'Stopped': '<S1>:8'
      // '<S1>:10:1' sf_internal_predicateOutput = ...
      // '<S1>:10:1' vel > 0.2;
      if (odometryadaptor_B.In1_m.Linear.X > 0.2) {
        // Transition: '<S1>:10'
        odometryadaptor_DW.is_c3_odometryadaptor = odometryadaptor_IN_Moving;
      } else {
        // '<S1>:8:1' stopped = true;
        odometryadaptor_B.stopped = true;
      }
      break;
    }
  }

  // End of Chart: '<Root>/Chart'

  // MATLAB Function: '<Root>/update' incorporates:
  //   SignalConversion: '<S5>/TmpSignal ConversionAt SFunction Inport2'
  //   SignalConversion: '<S5>/TmpSignal ConversionAt SFunction Inport3'

  // MATLAB Function 'update': '<S5>:1'
  // '<S5>:1:5' if( isempty(tmp) )
  if (!odometryadaptor_DW.tmp_not_empty) {
    // '<S5>:1:6' tmp = orientation;
    odometryadaptor_DW.tmp[0] = odometryadaptor_B.In1.Pose.Pose.Orientation.X;
    odometryadaptor_DW.tmp[1] = odometryadaptor_B.In1.Pose.Pose.Orientation.Y;
    odometryadaptor_DW.tmp[2] = odometryadaptor_B.In1.Pose.Pose.Orientation.Z;
    odometryadaptor_DW.tmp[3] = odometryadaptor_B.In1.Pose.Pose.Orientation.W;
    odometryadaptor_DW.tmp_not_empty = true;
  }

  // '<S5>:1:9' if( isempty(tmp_origin) )
  if (!odometryadaptor_DW.tmp_origin_not_empty) {
    // '<S5>:1:10' tmp_origin = position;
    odometryadaptor_DW.tmp_origin[0] =
      odometryadaptor_B.In1.Pose.Pose.Position.X;
    odometryadaptor_DW.tmp_origin[1] =
      odometryadaptor_B.In1.Pose.Pose.Position.Y;
    odometryadaptor_DW.tmp_origin[2] =
      odometryadaptor_B.In1.Pose.Pose.Position.Z;
    odometryadaptor_DW.tmp_origin_not_empty = true;
  }

  // '<S5>:1:13' if( stopped )
  if (!odometryadaptor_B.stopped) {
    // '<S5>:1:15' else
    // '<S5>:1:16' tmp = orientation;
    odometryadaptor_DW.tmp[0] = odometryadaptor_B.In1.Pose.Pose.Orientation.X;
    odometryadaptor_DW.tmp[1] = odometryadaptor_B.In1.Pose.Pose.Orientation.Y;
    odometryadaptor_DW.tmp[2] = odometryadaptor_B.In1.Pose.Pose.Orientation.Z;
    odometryadaptor_DW.tmp[3] = odometryadaptor_B.In1.Pose.Pose.Orientation.W;
  } else {
    // '<S5>:1:14' tmp = tmp;
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   MATLAB Function: '<Root>/update'
  //   SignalConversion: '<S5>/TmpSignal ConversionAt SFunction Inport2'

  // '<S5>:1:19' pose_out = zeros(3,1);
  // '<S5>:1:20' pose_out(1) = position(1) - tmp_origin(1);
  // '<S5>:1:21' pose_out(2) = position(2) - tmp_origin(2);
  // '<S5>:1:22' pose_out(3) = position(3) - tmp_origin(3);
  // '<S5>:1:24' q_out = tmp;
  odometryadaptor_B.BusAssignment = odometryadaptor_B.In1;
  odometryadaptor_B.BusAssignment.Pose.Pose.Position.X =
    odometryadaptor_B.In1.Pose.Pose.Position.X - odometryadaptor_DW.tmp_origin[0];
  odometryadaptor_B.BusAssignment.Pose.Pose.Position.Y =
    odometryadaptor_B.In1.Pose.Pose.Position.Y - odometryadaptor_DW.tmp_origin[1];
  odometryadaptor_B.BusAssignment.Pose.Pose.Position.Z =
    odometryadaptor_B.In1.Pose.Pose.Position.Z - odometryadaptor_DW.tmp_origin[2];
  odometryadaptor_B.BusAssignment.Pose.Pose.Orientation.X =
    odometryadaptor_DW.tmp[0];
  odometryadaptor_B.BusAssignment.Pose.Pose.Orientation.Y =
    odometryadaptor_DW.tmp[1];
  odometryadaptor_B.BusAssignment.Pose.Pose.Orientation.Z =
    odometryadaptor_DW.tmp[2];
  odometryadaptor_B.BusAssignment.Pose.Pose.Orientation.W =
    odometryadaptor_DW.tmp[3];

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S2>/SinkBlock' incorporates:
  //   MATLABSystem: '<S2>/SinkBlock'

  Pub_odometryadaptor_79.publish(&odometryadaptor_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void odometryadaptor_initialize(void)
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus(odometryadaptor_M, (NULL));

  // block I/O
  (void) memset(((void *) &odometryadaptor_B), 0,
                sizeof(B_odometryadaptor_T));

  // states (dwork)
  (void) memset((void *)&odometryadaptor_DW, 0,
                sizeof(DW_odometryadaptor_T));

  {
    static const char_T tmp[16] = { '/', 'c', 'a', 't', 'v', 'e', 'h', 'i', 'c',
      'l', 'e', '/', 'o', 'd', 'o', 'm' };

    static const char_T tmp_0[15] = { '/', 'c', 'a', 't', 'v', 'e', 'h', 'i',
      'c', 'l', 'e', '/', 'v', 'e', 'l' };

    static const char_T tmp_1[13] = { '/', 'o', 'd', 'o', 'm', '_', 'b', 'e',
      's', 't', 'u', 't', 'm' };

    char_T tmp_2[17];
    char_T tmp_3[16];
    char_T tmp_4[14];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    odometryadaptor_DW.obj_k.isInitialized = 0;
    odometryadaptor_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_4[i] = tmp_1[i];
    }

    tmp_4[13] = '\x00';
    Sub_odometryadaptor_88.createSubscriber(tmp_4,
      odometryadaptor_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe1'

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S3>/SourceBlock'
    odometryadaptor_DW.obj_n.isInitialized = 0;
    odometryadaptor_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[15] = '\x00';
    Sub_odometryadaptor_1.createSubscriber(tmp_3,
      odometryadaptor_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    odometryadaptor_DW.obj.isInitialized = 0;
    odometryadaptor_DW.obj.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      tmp_2[i] = tmp[i];
    }

    tmp_2[16] = '\x00';
    Pub_odometryadaptor_79.createPublisher(tmp_2,
      odometryadaptor_MessageQueueLen);

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S7>/Out1'
    odometryadaptor_B.In1 = odometryadaptor_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S6>/Out1'
    odometryadaptor_B.In1_m = odometryadaptor_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Chart: '<Root>/Chart'
    odometryadaptor_DW.is_active_c3_odometryadaptor = 0U;
    odometryadaptor_DW.is_c3_odometryadaptor = odometryadap_IN_NO_ACTIVE_CHILD;

    // SystemInitialize for MATLAB Function: '<Root>/update'
    odometryadaptor_DW.tmp_not_empty = false;
    odometryadaptor_DW.tmp_origin_not_empty = false;
  }
}

// Model terminate function
void odometryadaptor_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SourceBlock'

  if (odometryadaptor_DW.obj_k.isInitialized == 1) {
    odometryadaptor_DW.obj_k.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SourceBlock'

  if (odometryadaptor_DW.obj_n.isInitialized == 1) {
    odometryadaptor_DW.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S2>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S2>/SinkBlock'

  if (odometryadaptor_DW.obj.isInitialized == 1) {
    odometryadaptor_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S2>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
