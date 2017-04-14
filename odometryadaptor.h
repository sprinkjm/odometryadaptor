//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: odometryadaptor.h
//
// Code generated for Simulink model 'odometryadaptor'.
//
// Model version                  : 1.110
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Apr 14 15:39:59 2017
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_odometryadaptor_h_
#define RTW_HEADER_odometryadaptor_h_
#include <stddef.h>
#include <string.h>
#ifndef odometryadaptor_COMMON_INCLUDES_
# define odometryadaptor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // odometryadaptor_COMMON_INCLUDES_

#include "odometryadaptor_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_odometryadaptor_nav_msgs_Odometry In1;// '<S10>/In1'
  SL_Bus_odometryadaptor_nav_msgs_Odometry BusAssignment;// '<Root>/Bus Assignment' 
  SL_Bus_odometryadaptor_geometry_msgs_Twist In1_m;// '<S9>/In1'
  char_T cv0[23];
  SL_Bus_odometryadaptor_std_msgs_Bool In1_k;// '<S11>/In1'
  boolean_T stopped;                   // '<Root>/Chart'
} B_odometryadaptor_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T tmp[4];                       // '<Root>/update'
  real_T tmp_origin[3];                // '<Root>/update'
  void *SourceBlock_PWORK;             // '<S6>/SourceBlock'
  void *SourceBlock_PWORK_l;           // '<S5>/SourceBlock'
  void *SourceBlock_PWORK_f;           // '<S4>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S2>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S2>/SinkBlock'
  robotics_slros_internal_blo_i_T obj_f;// '<S6>/SourceBlock'
  robotics_slros_internal_blo_i_T obj_k;// '<S5>/SourceBlock'
  robotics_slros_internal_blo_i_T obj_n;// '<S4>/SourceBlock'
  uint8_T is_active_c3_odometryadaptor;// '<Root>/Chart'
  uint8_T is_c3_odometryadaptor;       // '<Root>/Chart'
  boolean_T tmp_not_empty;             // '<Root>/update'
  boolean_T tmp_origin_not_empty;      // '<Root>/update'
} DW_odometryadaptor_T;

// Parameters (auto storage)
struct P_odometryadaptor_T_ {
  SL_Bus_odometryadaptor_nav_msgs_Odometry Out1_Y0;// Computed Parameter: Out1_Y0
                                                   //  Referenced by: '<S10>/Out1'

  SL_Bus_odometryadaptor_nav_msgs_Odometry Constant_Value;// Computed Parameter: Constant_Value
                                                          //  Referenced by: '<S5>/Constant'

  SL_Bus_odometryadaptor_geometry_msgs_Twist Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                                       //  Referenced by: '<S9>/Out1'

  SL_Bus_odometryadaptor_geometry_msgs_Twist Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                              //  Referenced by: '<S4>/Constant'

  SL_Bus_odometryadaptor_std_msgs_Bool Out1_Y0_g;// Computed Parameter: Out1_Y0_g
                                                 //  Referenced by: '<S11>/Out1'

  SL_Bus_odometryadaptor_std_msgs_Bool Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                        //  Referenced by: '<S6>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_odometryadaptor_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_odometryadaptor_T odometryadaptor_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_odometryadaptor_T odometryadaptor_B;

// Block states (auto storage)
extern DW_odometryadaptor_T odometryadaptor_DW;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void odometryadaptor_initialize(void);
  extern void odometryadaptor_step(void);
  extern void odometryadaptor_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_odometryadaptor_T *const odometryadaptor_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'odometryadaptor'
//  '<S1>'   : 'odometryadaptor/Chart'
//  '<S2>'   : 'odometryadaptor/Publish'
//  '<S3>'   : 'odometryadaptor/Rotation Angles to Quaternions'
//  '<S4>'   : 'odometryadaptor/Subscribe'
//  '<S5>'   : 'odometryadaptor/Subscribe1'
//  '<S6>'   : 'odometryadaptor/Subscribe2'
//  '<S7>'   : 'odometryadaptor/Subscribe3'
//  '<S8>'   : 'odometryadaptor/update'
//  '<S9>'   : 'odometryadaptor/Subscribe/Enabled Subsystem'
//  '<S10>'  : 'odometryadaptor/Subscribe1/Enabled Subsystem'
//  '<S11>'  : 'odometryadaptor/Subscribe2/Enabled Subsystem'
//  '<S12>'  : 'odometryadaptor/Subscribe3/Enabled Subsystem'

#endif                                 // RTW_HEADER_odometryadaptor_h_

//
// File trailer for generated code.
//
// [EOF]
//
