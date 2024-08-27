/* Include files */

#include "blascompat32.h"
#include "demo_20210521_sfun.h"
#include "c2_demo_20210521.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "demo_20210521_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[5] = { "nargin", "nargout", "c",
  "image", "out" };

/* Function Declarations */
static void initialize_c2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance);
static void initialize_params_c2_demo_20210521(SFc2_demo_20210521InstanceStruct *
  chartInstance);
static void enable_c2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance);
static void disable_c2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_demo_20210521
  (SFc2_demo_20210521InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_demo_20210521
  (SFc2_demo_20210521InstanceStruct *chartInstance);
static void set_sim_state_c2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance);
static void sf_c2_demo_20210521(SFc2_demo_20210521InstanceStruct *chartInstance);
static void initSimStructsc2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct *chartInstance,
  const mxArray *c2_out, const char_T *c2_identifier, real_T c2_y[65536]);
static void c2_b_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[65536]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[128]);
static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[128]);
static void c2_eml_fft(SFc2_demo_20210521InstanceStruct *chartInstance, real_T
  c2_x[65536], creal_T c2_y[65536]);
static void c2_eml_assert_valid_dim(SFc2_demo_20210521InstanceStruct
  *chartInstance);
static void c2_eml_size_ispow2(SFc2_demo_20210521InstanceStruct *chartInstance);
static void c2_permute(SFc2_demo_20210521InstanceStruct *chartInstance, real_T
  c2_a[65536], real_T c2_b[65536]);
static void c2_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance);
static void c2_b_eml_fft(SFc2_demo_20210521InstanceStruct *chartInstance, real_T
  c2_x[65536], creal_T c2_y[65536]);
static void c2_b_eml_assert_valid_dim(SFc2_demo_20210521InstanceStruct
  *chartInstance);
static void c2_eml_scalar_eg(SFc2_demo_20210521InstanceStruct *chartInstance);
static void c2_b_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance);
static void c2_c_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance);
static void c2_d_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance, int32_T c2_a, int32_T c2_b);
static void c2_ipermute(SFc2_demo_20210521InstanceStruct *chartInstance, creal_T
  c2_b[65536], creal_T c2_a[65536]);
static void c2_c_eml_fft(SFc2_demo_20210521InstanceStruct *chartInstance,
  creal_T c2_x[65536], creal_T c2_y[65536]);
static void c2_eml_fftshift(SFc2_demo_20210521InstanceStruct *chartInstance,
  creal_T c2_x[65536], int32_T c2_dim, creal_T c2_b_x[65536]);
static void c2_e_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance, int32_T c2_b);
static void c2_f_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance, int32_T c2_a);
static void c2_eml_error(SFc2_demo_20210521InstanceStruct *chartInstance);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_demo_20210521, const char_T
  *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_eml_fftshift(SFc2_demo_20210521InstanceStruct *chartInstance,
  creal_T c2_x[65536], int32_T c2_dim);
static void init_dsm_address_info(SFc2_demo_20210521InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_demo_20210521 = 0U;
}

static void initialize_params_c2_demo_20210521(SFc2_demo_20210521InstanceStruct *
  chartInstance)
{
}

static void enable_c2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_demo_20210521
  (SFc2_demo_20210521InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_demo_20210521
  (SFc2_demo_20210521InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  static real_T c2_u[65536];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_out)[65536];
  c2_out = (real_T (*)[65536])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 65536; c2_i0++) {
    c2_u[c2_i0] = (*c2_out)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 256, 256),
                FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_demo_20210521;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  static real_T c2_dv0[65536];
  int32_T c2_i1;
  real_T (*c2_out)[65536];
  c2_out = (real_T (*)[65536])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "out",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 65536; c2_i1++) {
    (*c2_out)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_demo_20210521 = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_demo_20210521");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_demo_20210521(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance)
{
}

static void sf_c2_demo_20210521(SFc2_demo_20210521InstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  real_T c2_hoistedGlobal;
  real_T c2_c;
  int32_T c2_i4;
  static real32_T c2_image[65536];
  uint32_T c2_debug_family_var_map[5];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  static real_T c2_out[65536];
  int32_T c2_i5;
  static real_T c2_x[65536];
  int32_T c2_i6;
  static real_T c2_b_x[65536];
  static creal_T c2_y[65536];
  int32_T c2_i7;
  static creal_T c2_b_y[65536];
  int32_T c2_dim;
  int32_T c2_b_dim;
  int32_T c2_k;
  real_T c2_b_k;
  creal_T c2_c_x;
  real_T c2_x1;
  real_T c2_x2;
  real_T c2_a;
  real_T c2_b;
  real_T c2_c_y;
  int32_T c2_i8;
  int32_T c2_c_k;
  real_T c2_d_k;
  int32_T c2_e_k;
  real_T c2_d_x;
  real_T c2_e_x;
  int32_T c2_i9;
  real_T *c2_b_c;
  real_T (*c2_b_out)[65536];
  real32_T (*c2_b_image)[65536];
  c2_b_image = (real32_T (*)[65536])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_out = (real_T (*)[65536])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_c, 0U);
  for (c2_i2 = 0; c2_i2 < 65536; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_out)[c2_i2], 1U);
  }

  for (c2_i3 = 0; c2_i3 < 65536; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_image)[c2_i3], 2U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_c;
  c2_c = c2_hoistedGlobal;
  for (c2_i4 = 0; c2_i4 < 65536; c2_i4++) {
    c2_image[c2_i4] = (*c2_b_image)[c2_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_c, 2U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_image, 3U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_out, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  for (c2_i5 = 0; c2_i5 < 65536; c2_i5++) {
    c2_x[c2_i5] = c2_c + (real_T)c2_image[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 65536; c2_i6++) {
    c2_b_x[c2_i6] = c2_x[c2_i6];
  }

  c2_eml_fft(chartInstance, c2_b_x, c2_y);
  for (c2_i7 = 0; c2_i7 < 65536; c2_i7++) {
    c2_b_y[c2_i7] = c2_y[c2_i7];
  }

  c2_c_eml_fft(chartInstance, c2_b_y, c2_y);
  c2_eml_int_forloop_overflow_check(chartInstance);
  for (c2_dim = 1; c2_dim < 3; c2_dim++) {
    c2_b_dim = c2_dim;
    c2_b_eml_fftshift(chartInstance, c2_y, c2_b_dim);
  }

  for (c2_k = 0; c2_k < 65536; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_c_x = c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_k), 1, 65536, 1, 0) - 1];
    c2_x1 = c2_c_x.re;
    c2_x2 = c2_c_x.im;
    c2_a = muDoubleScalarAbs(c2_x1);
    c2_b = muDoubleScalarAbs(c2_x2);
    c2_c_y = muDoubleScalarHypot(c2_a, c2_b);
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_k),
      1, 65536, 1, 0) - 1] = c2_c_y;
  }

  for (c2_i8 = 0; c2_i8 < 65536; c2_i8++) {
    c2_out[c2_i8] = c2_x[c2_i8];
  }

  for (c2_c_k = 0; c2_c_k < 65536; c2_c_k++) {
    c2_d_k = 1.0 + (real_T)c2_c_k;
    if (c2_out[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c2_d_k), 1, 65536, 1, 0) - 1] < 0.0) {
      c2_eml_error(chartInstance);
    }
  }

  for (c2_e_k = 0; c2_e_k < 65536; c2_e_k++) {
    c2_d_k = 1.0 + (real_T)c2_e_k;
    c2_d_x = c2_out[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c2_d_k), 1, 65536, 1, 0) - 1];
    c2_e_x = c2_d_x;
    c2_e_x = muDoubleScalarLog(c2_e_x);
    c2_out[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_d_k), 1, 65536, 1, 0) - 1] = c2_e_x;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -2);
  sf_debug_symbol_scope_pop();
  for (c2_i9 = 0; c2_i9 < 65536; c2_i9++) {
    (*c2_b_out)[c2_i9] = c2_out[c2_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_demo_20210521MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_demo_20210521(SFc2_demo_20210521InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  static real_T c2_b_inData[65536];
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  static real_T c2_u[65536];
  const mxArray *c2_y = NULL;
  SFc2_demo_20210521InstanceStruct *chartInstance;
  chartInstance = (SFc2_demo_20210521InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i10 = 0;
  for (c2_i11 = 0; c2_i11 < 256; c2_i11++) {
    for (c2_i12 = 0; c2_i12 < 256; c2_i12++) {
      c2_b_inData[c2_i12 + c2_i10] = (*(real_T (*)[65536])c2_inData)[c2_i12 +
        c2_i10];
    }

    c2_i10 += 256;
  }

  c2_i13 = 0;
  for (c2_i14 = 0; c2_i14 < 256; c2_i14++) {
    for (c2_i15 = 0; c2_i15 < 256; c2_i15++) {
      c2_u[c2_i15 + c2_i13] = c2_b_inData[c2_i15 + c2_i13];
    }

    c2_i13 += 256;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 256, 256),
                FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct *chartInstance,
  const mxArray *c2_out, const char_T *c2_identifier, real_T c2_y[65536])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_out), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_out);
}

static void c2_b_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[65536])
{
  static real_T c2_dv1[65536];
  int32_T c2_i16;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 256,
                256);
  for (c2_i16 = 0; c2_i16 < 65536; c2_i16++) {
    c2_y[c2_i16] = c2_dv1[c2_i16];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_out;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  static real_T c2_y[65536];
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  SFc2_demo_20210521InstanceStruct *chartInstance;
  chartInstance = (SFc2_demo_20210521InstanceStruct *)chartInstanceVoid;
  c2_out = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_out), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_out);
  c2_i17 = 0;
  for (c2_i18 = 0; c2_i18 < 256; c2_i18++) {
    for (c2_i19 = 0; c2_i19 < 256; c2_i19++) {
      (*(real_T (*)[65536])c2_outData)[c2_i19 + c2_i17] = c2_y[c2_i19 + c2_i17];
    }

    c2_i17 += 256;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  static real32_T c2_b_inData[65536];
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  static real32_T c2_u[65536];
  const mxArray *c2_y = NULL;
  SFc2_demo_20210521InstanceStruct *chartInstance;
  chartInstance = (SFc2_demo_20210521InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i20 = 0;
  for (c2_i21 = 0; c2_i21 < 256; c2_i21++) {
    for (c2_i22 = 0; c2_i22 < 256; c2_i22++) {
      c2_b_inData[c2_i22 + c2_i20] = (*(real32_T (*)[65536])c2_inData)[c2_i22 +
        c2_i20];
    }

    c2_i20 += 256;
  }

  c2_i23 = 0;
  for (c2_i24 = 0; c2_i24 < 256; c2_i24++) {
    for (c2_i25 = 0; c2_i25 < 256; c2_i25++) {
      c2_u[c2_i25 + c2_i23] = c2_b_inData[c2_i25 + c2_i23];
    }

    c2_i23 += 256;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 1, 0U, 1U, 0U, 2, 256, 256),
                FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_demo_20210521InstanceStruct *chartInstance;
  chartInstance = (SFc2_demo_20210521InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_demo_20210521InstanceStruct *chartInstance;
  chartInstance = (SFc2_demo_20210521InstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_demo_20210521_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[128];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i26;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  c2_b_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 128), FALSE);
  for (c2_i26 = 0; c2_i26 < 128; c2_i26++) {
    c2_r0 = &c2_info[c2_i26];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i26);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[128])
{
  c2_info[0].context = "";
  c2_info[0].name = "fft2";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/fft2.m";
  c2_info[0].fileTimeLo = 1286797088U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/fft2.m";
  c2_info[1].name = "fft";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/fft.m";
  c2_info[1].fileTimeLo = 1286797088U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/fft.m";
  c2_info[2].name = "eml_fft";
  c2_info[2].dominantType = "char";
  c2_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c2_info[2].fileTimeLo = 1286797174U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c2_info[3].name = "eml_assert_valid_dim";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c2_info[3].fileTimeLo = 1286797094U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c2_info[4].name = "eml_scalar_floor";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[4].fileTimeLo = 1286797126U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c2_info[5].name = "eml_index_class";
  c2_info[5].dominantType = "";
  c2_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[5].fileTimeLo = 1286797178U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c2_info[6].name = "intmax";
  c2_info[6].dominantType = "char";
  c2_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[6].fileTimeLo = 1311233716U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c2_info[7].name = "eml_index_class";
  c2_info[7].dominantType = "";
  c2_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[7].fileTimeLo = 1286797178U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c2_info[8].name = "eml_unsigned_class";
  c2_info[8].dominantType = "char";
  c2_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c2_info[8].fileTimeLo = 1286797200U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c2_info[9].name = "eml_size_ispow2";
  c2_info[9].dominantType = "uint32";
  c2_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  c2_info[9].fileTimeLo = 1286797198U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  c2_info[10].name = "eml_unsigned_class";
  c2_info[10].dominantType = "char";
  c2_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c2_info[10].fileTimeLo = 1286797200U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c2_info[11].name = "max";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[11].fileTimeLo = 1311233716U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[12].name = "eml_min_or_max";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[12].fileTimeLo = 1303124612U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[13].name = "eml_scalar_eg";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[13].fileTimeLo = 1286797196U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[14].name = "eml_scalexp_alloc";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[14].fileTimeLo = 1286797196U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[15].name = "eml_index_class";
  c2_info[15].dominantType = "";
  c2_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[15].fileTimeLo = 1286797178U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c2_info[16].name = "eml_scalar_eg";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[16].fileTimeLo = 1286797196U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c2_info[17].name = "eml_dim_to_fore_permutation";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c2_info[17].fileTimeLo = 1286797096U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c2_info[18].name = "eml_index_class";
  c2_info[18].dominantType = "";
  c2_info[18].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[18].fileTimeLo = 1286797178U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c2_info[19].name = "eml_index_plus";
  c2_info[19].dominantType = "int32";
  c2_info[19].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[19].fileTimeLo = 1286797178U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[20].name = "eml_index_class";
  c2_info[20].dominantType = "";
  c2_info[20].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[20].fileTimeLo = 1286797178U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c2_info[21].name = "min";
  c2_info[21].dominantType = "int32";
  c2_info[21].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[21].fileTimeLo = 1311233718U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[22].name = "eml_min_or_max";
  c2_info[22].dominantType = "int32";
  c2_info[22].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[22].fileTimeLo = 1303124612U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[23].name = "eml_scalar_eg";
  c2_info[23].dominantType = "int32";
  c2_info[23].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[23].fileTimeLo = 1286797196U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[24].name = "eml_scalexp_alloc";
  c2_info[24].dominantType = "int32";
  c2_info[24].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[24].fileTimeLo = 1286797196U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c2_info[25].name = "eml_scalar_eg";
  c2_info[25].dominantType = "int32";
  c2_info[25].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[25].fileTimeLo = 1286797196U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c2_info[26].name = "max";
  c2_info[26].dominantType = "int32";
  c2_info[26].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[26].fileTimeLo = 1311233716U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[27].name = "eml_min_or_max";
  c2_info[27].dominantType = "int32";
  c2_info[27].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[27].fileTimeLo = 1303124612U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c2_info[28].name = "colon";
  c2_info[28].dominantType = "int32";
  c2_info[28].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[28].fileTimeLo = 1311233718U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[29].name = "colon";
  c2_info[29].dominantType = "int32";
  c2_info[29].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[29].fileTimeLo = 1311233718U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[30].name = "floor";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[30].fileTimeLo = 1286797142U;
  c2_info[30].fileTimeHi = 0U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[31].name = "eml_scalar_floor";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[31].fileTimeLo = 1286797126U;
  c2_info[31].fileTimeHi = 0U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c2_info[32].name = "intmin";
  c2_info[32].dominantType = "char";
  c2_info[32].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[32].fileTimeLo = 1311233718U;
  c2_info[32].fileTimeHi = 0U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
  c2_info[33].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c2_info[33].name = "intmax";
  c2_info[33].dominantType = "char";
  c2_info[33].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[33].fileTimeLo = 1311233716U;
  c2_info[33].fileTimeHi = 0U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
  c2_info[34].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c2_info[34].name = "intmin";
  c2_info[34].dominantType = "char";
  c2_info[34].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[34].fileTimeLo = 1311233718U;
  c2_info[34].fileTimeHi = 0U;
  c2_info[34].mFileTimeLo = 0U;
  c2_info[34].mFileTimeHi = 0U;
  c2_info[35].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c2_info[35].name = "intmax";
  c2_info[35].dominantType = "char";
  c2_info[35].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[35].fileTimeLo = 1311233716U;
  c2_info[35].fileTimeHi = 0U;
  c2_info[35].mFileTimeLo = 0U;
  c2_info[35].mFileTimeHi = 0U;
  c2_info[36].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c2_info[36].name = "eml_isa_uint";
  c2_info[36].dominantType = "int32";
  c2_info[36].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[36].fileTimeLo = 1286797184U;
  c2_info[36].fileTimeHi = 0U;
  c2_info[36].mFileTimeLo = 0U;
  c2_info[36].mFileTimeHi = 0U;
  c2_info[37].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[37].name = "eml_unsigned_class";
  c2_info[37].dominantType = "char";
  c2_info[37].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c2_info[37].fileTimeLo = 1286797200U;
  c2_info[37].fileTimeHi = 0U;
  c2_info[37].mFileTimeLo = 0U;
  c2_info[37].mFileTimeHi = 0U;
  c2_info[38].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[38].name = "eml_index_class";
  c2_info[38].dominantType = "";
  c2_info[38].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[38].fileTimeLo = 1286797178U;
  c2_info[38].fileTimeHi = 0U;
  c2_info[38].mFileTimeLo = 0U;
  c2_info[38].mFileTimeHi = 0U;
  c2_info[39].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[39].name = "intmax";
  c2_info[39].dominantType = "char";
  c2_info[39].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[39].fileTimeLo = 1311233716U;
  c2_info[39].fileTimeHi = 0U;
  c2_info[39].mFileTimeLo = 0U;
  c2_info[39].mFileTimeHi = 0U;
  c2_info[40].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[40].name = "eml_isa_uint";
  c2_info[40].dominantType = "int32";
  c2_info[40].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[40].fileTimeLo = 1286797184U;
  c2_info[40].fileTimeHi = 0U;
  c2_info[40].mFileTimeLo = 0U;
  c2_info[40].mFileTimeHi = 0U;
  c2_info[41].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[41].name = "eml_index_plus";
  c2_info[41].dominantType = "int32";
  c2_info[41].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[41].fileTimeLo = 1286797178U;
  c2_info[41].fileTimeHi = 0U;
  c2_info[41].mFileTimeLo = 0U;
  c2_info[41].mFileTimeHi = 0U;
  c2_info[42].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c2_info[42].name = "eml_index_minus";
  c2_info[42].dominantType = "int32";
  c2_info[42].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[42].fileTimeLo = 1286797178U;
  c2_info[42].fileTimeHi = 0U;
  c2_info[42].mFileTimeLo = 0U;
  c2_info[42].mFileTimeHi = 0U;
  c2_info[43].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[43].name = "eml_index_class";
  c2_info[43].dominantType = "";
  c2_info[43].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[43].fileTimeLo = 1286797178U;
  c2_info[43].fileTimeHi = 0U;
  c2_info[43].mFileTimeLo = 0U;
  c2_info[43].mFileTimeHi = 0U;
  c2_info[44].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c2_info[44].name = "permute";
  c2_info[44].dominantType = "int32";
  c2_info[44].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/permute.m";
  c2_info[44].fileTimeLo = 1286797166U;
  c2_info[44].fileTimeHi = 0U;
  c2_info[44].mFileTimeLo = 0U;
  c2_info[44].mFileTimeHi = 0U;
  c2_info[45].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/permute.m";
  c2_info[45].name = "eml_index_class";
  c2_info[45].dominantType = "";
  c2_info[45].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[45].fileTimeLo = 1286797178U;
  c2_info[45].fileTimeHi = 0U;
  c2_info[45].mFileTimeLo = 0U;
  c2_info[45].mFileTimeHi = 0U;
  c2_info[46].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/permute.m";
  c2_info[46].name = "eml_is_permutation";
  c2_info[46].dominantType = "int32";
  c2_info[46].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_permutation.m";
  c2_info[46].fileTimeLo = 1286797182U;
  c2_info[46].fileTimeHi = 0U;
  c2_info[46].mFileTimeLo = 0U;
  c2_info[46].mFileTimeHi = 0U;
  c2_info[47].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_permutation.m";
  c2_info[47].name = "eml_index_class";
  c2_info[47].dominantType = "";
  c2_info[47].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[47].fileTimeLo = 1286797178U;
  c2_info[47].fileTimeHi = 0U;
  c2_info[47].mFileTimeLo = 0U;
  c2_info[47].mFileTimeHi = 0U;
  c2_info[48].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_permutation.m";
  c2_info[48].name = "eml_int_forloop_overflow_check";
  c2_info[48].dominantType = "";
  c2_info[48].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[48].fileTimeLo = 1311233716U;
  c2_info[48].fileTimeHi = 0U;
  c2_info[48].mFileTimeLo = 0U;
  c2_info[48].mFileTimeHi = 0U;
  c2_info[49].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[49].name = "intmax";
  c2_info[49].dominantType = "char";
  c2_info[49].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[49].fileTimeLo = 1311233716U;
  c2_info[49].fileTimeHi = 0U;
  c2_info[49].mFileTimeLo = 0U;
  c2_info[49].mFileTimeHi = 0U;
  c2_info[50].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_permutation.m";
  c2_info[50].name = "eml_scalar_floor";
  c2_info[50].dominantType = "int32";
  c2_info[50].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[50].fileTimeLo = 1286797126U;
  c2_info[50].fileTimeHi = 0U;
  c2_info[50].mFileTimeLo = 0U;
  c2_info[50].mFileTimeHi = 0U;
  c2_info[51].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_permutation.m";
  c2_info[51].name = "all";
  c2_info[51].dominantType = "logical";
  c2_info[51].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[51].fileTimeLo = 1286797234U;
  c2_info[51].fileTimeHi = 0U;
  c2_info[51].mFileTimeLo = 0U;
  c2_info[51].mFileTimeHi = 0U;
  c2_info[52].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[52].name = "eml_all_or_any";
  c2_info[52].dominantType = "char";
  c2_info[52].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[52].fileTimeLo = 1286797094U;
  c2_info[52].fileTimeHi = 0U;
  c2_info[52].mFileTimeLo = 0U;
  c2_info[52].mFileTimeHi = 0U;
  c2_info[53].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[53].name = "isequal";
  c2_info[53].dominantType = "double";
  c2_info[53].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[53].fileTimeLo = 1286797158U;
  c2_info[53].fileTimeHi = 0U;
  c2_info[53].mFileTimeLo = 0U;
  c2_info[53].mFileTimeHi = 0U;
  c2_info[54].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[54].name = "eml_isequal_core";
  c2_info[54].dominantType = "double";
  c2_info[54].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c2_info[54].fileTimeLo = 1286797186U;
  c2_info[54].fileTimeHi = 0U;
  c2_info[54].mFileTimeLo = 0U;
  c2_info[54].mFileTimeHi = 0U;
  c2_info[55].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[55].name = "eml_const_nonsingleton_dim";
  c2_info[55].dominantType = "logical";
  c2_info[55].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c2_info[55].fileTimeLo = 1286797096U;
  c2_info[55].fileTimeHi = 0U;
  c2_info[55].mFileTimeLo = 0U;
  c2_info[55].mFileTimeHi = 0U;
  c2_info[56].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c2_info[56].name = "eml_fft";
  c2_info[56].dominantType = "uint32";
  c2_info[56].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c2_info[56].fileTimeLo = 1286797174U;
  c2_info[56].fileTimeHi = 0U;
  c2_info[56].mFileTimeLo = 0U;
  c2_info[56].mFileTimeHi = 0U;
  c2_info[57].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[57].name = "eml_scalar_eg";
  c2_info[57].dominantType = "double";
  c2_info[57].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[57].fileTimeLo = 1286797196U;
  c2_info[57].fileTimeHi = 0U;
  c2_info[57].mFileTimeLo = 0U;
  c2_info[57].mFileTimeHi = 0U;
  c2_info[58].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[58].name = "eml_index_class";
  c2_info[58].dominantType = "";
  c2_info[58].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[58].fileTimeLo = 1286797178U;
  c2_info[58].fileTimeHi = 0U;
  c2_info[58].mFileTimeLo = 0U;
  c2_info[58].mFileTimeHi = 0U;
  c2_info[59].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[59].name = "min";
  c2_info[59].dominantType = "int32";
  c2_info[59].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[59].fileTimeLo = 1311233718U;
  c2_info[59].fileTimeHi = 0U;
  c2_info[59].mFileTimeLo = 0U;
  c2_info[59].mFileTimeHi = 0U;
  c2_info[60].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c2_info[60].name = "eml_relop";
  c2_info[60].dominantType = "function_handle";
  c2_info[60].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c2_info[60].fileTimeLo = 1292165310U;
  c2_info[60].fileTimeHi = 0U;
  c2_info[60].mFileTimeLo = 0U;
  c2_info[60].mFileTimeHi = 0U;
  c2_info[61].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c2_info[61].name = "isnan";
  c2_info[61].dominantType = "double";
  c2_info[61].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[61].fileTimeLo = 1286797160U;
  c2_info[61].fileTimeHi = 0U;
  c2_info[61].mFileTimeLo = 0U;
  c2_info[61].mFileTimeHi = 0U;
  c2_info[62].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[62].name = "eml_index_minus";
  c2_info[62].dominantType = "int32";
  c2_info[62].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[62].fileTimeLo = 1286797178U;
  c2_info[62].fileTimeHi = 0U;
  c2_info[62].mFileTimeLo = 0U;
  c2_info[62].mFileTimeHi = 0U;
  c2_info[63].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[63].name = "max";
  c2_info[63].dominantType = "int32";
  c2_info[63].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[63].fileTimeLo = 1311233716U;
  c2_info[63].fileTimeHi = 0U;
  c2_info[63].mFileTimeLo = 0U;
  c2_info[63].mFileTimeHi = 0U;
}

static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[128])
{
  c2_info[64].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[64].name = "eml_index_rdivide";
  c2_info[64].dominantType = "int32";
  c2_info[64].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c2_info[64].fileTimeLo = 1286797180U;
  c2_info[64].fileTimeHi = 0U;
  c2_info[64].mFileTimeLo = 0U;
  c2_info[64].mFileTimeHi = 0U;
  c2_info[65].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c2_info[65].name = "eml_index_class";
  c2_info[65].dominantType = "";
  c2_info[65].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[65].fileTimeLo = 1286797178U;
  c2_info[65].fileTimeHi = 0U;
  c2_info[65].mFileTimeLo = 0U;
  c2_info[65].mFileTimeHi = 0U;
  c2_info[66].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[66].name = "eml_index_rdivide";
  c2_info[66].dominantType = "double";
  c2_info[66].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c2_info[66].fileTimeLo = 1286797180U;
  c2_info[66].fileTimeHi = 0U;
  c2_info[66].mFileTimeLo = 0U;
  c2_info[66].mFileTimeHi = 0U;
  c2_info[67].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[67].name = "eml_index_times";
  c2_info[67].dominantType = "int32";
  c2_info[67].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[67].fileTimeLo = 1286797180U;
  c2_info[67].fileTimeHi = 0U;
  c2_info[67].mFileTimeLo = 0U;
  c2_info[67].mFileTimeHi = 0U;
  c2_info[68].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[68].name = "eml_index_class";
  c2_info[68].dominantType = "";
  c2_info[68].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[68].fileTimeLo = 1286797178U;
  c2_info[68].fileTimeHi = 0U;
  c2_info[68].mFileTimeLo = 0U;
  c2_info[68].mFileTimeHi = 0U;
  c2_info[69].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[69].name = "mtimes";
  c2_info[69].dominantType = "double";
  c2_info[69].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[69].fileTimeLo = 1289494492U;
  c2_info[69].fileTimeHi = 0U;
  c2_info[69].mFileTimeLo = 0U;
  c2_info[69].mFileTimeHi = 0U;
  c2_info[70].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[70].name = "mrdivide";
  c2_info[70].dominantType = "double";
  c2_info[70].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[70].fileTimeLo = 1325098938U;
  c2_info[70].fileTimeHi = 0U;
  c2_info[70].mFileTimeLo = 1319708366U;
  c2_info[70].mFileTimeHi = 0U;
  c2_info[71].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[71].name = "rdivide";
  c2_info[71].dominantType = "double";
  c2_info[71].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[71].fileTimeLo = 1286797244U;
  c2_info[71].fileTimeHi = 0U;
  c2_info[71].mFileTimeLo = 0U;
  c2_info[71].mFileTimeHi = 0U;
  c2_info[72].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[72].name = "eml_div";
  c2_info[72].dominantType = "double";
  c2_info[72].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[72].fileTimeLo = 1313326210U;
  c2_info[72].fileTimeHi = 0U;
  c2_info[72].mFileTimeLo = 0U;
  c2_info[72].mFileTimeHi = 0U;
  c2_info[73].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c2_info[73].name = "eml_index_plus";
  c2_info[73].dominantType = "int32";
  c2_info[73].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[73].fileTimeLo = 1286797178U;
  c2_info[73].fileTimeHi = 0U;
  c2_info[73].mFileTimeLo = 0U;
  c2_info[73].mFileTimeHi = 0U;
  c2_info[74].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c2_info[74].name = "eml_index_rdivide";
  c2_info[74].dominantType = "int32";
  c2_info[74].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c2_info[74].fileTimeLo = 1286797180U;
  c2_info[74].fileTimeHi = 0U;
  c2_info[74].mFileTimeLo = 0U;
  c2_info[74].mFileTimeHi = 0U;
  c2_info[75].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c2_info[75].name = "eml_int_forloop_overflow_check";
  c2_info[75].dominantType = "";
  c2_info[75].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[75].fileTimeLo = 1311233716U;
  c2_info[75].fileTimeHi = 0U;
  c2_info[75].mFileTimeLo = 0U;
  c2_info[75].mFileTimeHi = 0U;
  c2_info[76].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c2_info[76].name = "mtimes";
  c2_info[76].dominantType = "double";
  c2_info[76].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[76].fileTimeLo = 1289494492U;
  c2_info[76].fileTimeHi = 0U;
  c2_info[76].mFileTimeLo = 0U;
  c2_info[76].mFileTimeHi = 0U;
  c2_info[77].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c2_info[77].name = "cos";
  c2_info[77].dominantType = "double";
  c2_info[77].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[77].fileTimeLo = 1286797106U;
  c2_info[77].fileTimeHi = 0U;
  c2_info[77].mFileTimeLo = 0U;
  c2_info[77].mFileTimeHi = 0U;
  c2_info[78].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[78].name = "eml_scalar_cos";
  c2_info[78].dominantType = "double";
  c2_info[78].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[78].fileTimeLo = 1286797122U;
  c2_info[78].fileTimeHi = 0U;
  c2_info[78].mFileTimeLo = 0U;
  c2_info[78].mFileTimeHi = 0U;
  c2_info[79].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c2_info[79].name = "eml_index_minus";
  c2_info[79].dominantType = "int32";
  c2_info[79].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[79].fileTimeLo = 1286797178U;
  c2_info[79].fileTimeHi = 0U;
  c2_info[79].mFileTimeLo = 0U;
  c2_info[79].mFileTimeHi = 0U;
  c2_info[80].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c2_info[80].name = "sin";
  c2_info[80].dominantType = "double";
  c2_info[80].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[80].fileTimeLo = 1286797150U;
  c2_info[80].fileTimeHi = 0U;
  c2_info[80].mFileTimeLo = 0U;
  c2_info[80].mFileTimeHi = 0U;
  c2_info[81].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[81].name = "eml_scalar_sin";
  c2_info[81].dominantType = "double";
  c2_info[81].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[81].fileTimeLo = 1286797136U;
  c2_info[81].fileTimeHi = 0U;
  c2_info[81].mFileTimeLo = 0U;
  c2_info[81].mFileTimeHi = 0U;
  c2_info[82].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_twiddle_table";
  c2_info[82].name = "eml_index_class";
  c2_info[82].dominantType = "";
  c2_info[82].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[82].fileTimeLo = 1286797178U;
  c2_info[82].fileTimeHi = 0U;
  c2_info[82].mFileTimeLo = 0U;
  c2_info[82].mFileTimeHi = 0U;
  c2_info[83].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_twiddle_table";
  c2_info[83].name = "eml_index_times";
  c2_info[83].dominantType = "int32";
  c2_info[83].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[83].fileTimeLo = 1286797180U;
  c2_info[83].fileTimeHi = 0U;
  c2_info[83].mFileTimeLo = 0U;
  c2_info[83].mFileTimeHi = 0U;
  c2_info[84].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_twiddle_table";
  c2_info[84].name = "eml_index_plus";
  c2_info[84].dominantType = "int32";
  c2_info[84].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[84].fileTimeLo = 1286797178U;
  c2_info[84].fileTimeHi = 0U;
  c2_info[84].mFileTimeLo = 0U;
  c2_info[84].mFileTimeHi = 0U;
  c2_info[85].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_twiddle_table";
  c2_info[85].name = "eml_int_forloop_overflow_check";
  c2_info[85].dominantType = "";
  c2_info[85].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[85].fileTimeLo = 1311233716U;
  c2_info[85].fileTimeHi = 0U;
  c2_info[85].mFileTimeLo = 0U;
  c2_info[85].mFileTimeHi = 0U;
  c2_info[86].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!make_twiddle_table";
  c2_info[86].name = "eml_index_minus";
  c2_info[86].dominantType = "int32";
  c2_info[86].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[86].fileTimeLo = 1286797178U;
  c2_info[86].fileTimeHi = 0U;
  c2_info[86].mFileTimeLo = 0U;
  c2_info[86].mFileTimeHi = 0U;
  c2_info[87].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[87].name = "eml_int_forloop_overflow_check";
  c2_info[87].dominantType = "";
  c2_info[87].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[87].fileTimeLo = 1311233716U;
  c2_info[87].fileTimeHi = 0U;
  c2_info[87].mFileTimeLo = 0U;
  c2_info[87].mFileTimeHi = 0U;
  c2_info[88].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!ucls";
  c2_info[88].name = "eml_index_class";
  c2_info[88].dominantType = "";
  c2_info[88].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[88].fileTimeLo = 1286797178U;
  c2_info[88].fileTimeHi = 0U;
  c2_info[88].mFileTimeLo = 0U;
  c2_info[88].mFileTimeHi = 0U;
  c2_info[89].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!ucls";
  c2_info[89].name = "eml_unsigned_class";
  c2_info[89].dominantType = "char";
  c2_info[89].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c2_info[89].fileTimeLo = 1286797200U;
  c2_info[89].fileTimeHi = 0U;
  c2_info[89].mFileTimeLo = 0U;
  c2_info[89].mFileTimeHi = 0U;
  c2_info[90].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c2_info[90].name = "eml_index_plus";
  c2_info[90].dominantType = "int32";
  c2_info[90].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[90].fileTimeLo = 1286797178U;
  c2_info[90].fileTimeHi = 0U;
  c2_info[90].mFileTimeLo = 0U;
  c2_info[90].mFileTimeHi = 0U;
  c2_info[91].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m!eml_fft_bitrevidx";
  c2_info[91].name = "eml_index_class";
  c2_info[91].dominantType = "";
  c2_info[91].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[91].fileTimeLo = 1286797178U;
  c2_info[91].fileTimeHi = 0U;
  c2_info[91].mFileTimeLo = 0U;
  c2_info[91].mFileTimeHi = 0U;
  c2_info[92].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c2_info[92].name = "ipermute";
  c2_info[92].dominantType = "int32";
  c2_info[92].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/ipermute.m";
  c2_info[92].fileTimeLo = 1286797156U;
  c2_info[92].fileTimeHi = 0U;
  c2_info[92].mFileTimeLo = 0U;
  c2_info[92].mFileTimeHi = 0U;
  c2_info[93].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/ipermute.m";
  c2_info[93].name = "eml_is_permutation";
  c2_info[93].dominantType = "int32";
  c2_info[93].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_permutation.m";
  c2_info[93].fileTimeLo = 1286797182U;
  c2_info[93].fileTimeHi = 0U;
  c2_info[93].mFileTimeLo = 0U;
  c2_info[93].mFileTimeHi = 0U;
  c2_info[94].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/ipermute.m!invperm";
  c2_info[94].name = "eml_index_class";
  c2_info[94].dominantType = "";
  c2_info[94].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[94].fileTimeLo = 1286797178U;
  c2_info[94].fileTimeHi = 0U;
  c2_info[94].mFileTimeLo = 0U;
  c2_info[94].mFileTimeHi = 0U;
  c2_info[95].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/ipermute.m";
  c2_info[95].name = "permute";
  c2_info[95].dominantType = "int32";
  c2_info[95].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/permute.m";
  c2_info[95].fileTimeLo = 1286797166U;
  c2_info[95].fileTimeHi = 0U;
  c2_info[95].mFileTimeLo = 0U;
  c2_info[95].mFileTimeHi = 0U;
  c2_info[96].context = "";
  c2_info[96].name = "fftshift";
  c2_info[96].dominantType = "double";
  c2_info[96].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/fftshift.m";
  c2_info[96].fileTimeLo = 1286797090U;
  c2_info[96].fileTimeHi = 0U;
  c2_info[96].mFileTimeLo = 0U;
  c2_info[96].mFileTimeHi = 0U;
  c2_info[97].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/fftshift.m";
  c2_info[97].name = "eml_index_class";
  c2_info[97].dominantType = "";
  c2_info[97].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[97].fileTimeLo = 1286797178U;
  c2_info[97].fileTimeHi = 0U;
  c2_info[97].mFileTimeLo = 0U;
  c2_info[97].mFileTimeHi = 0U;
  c2_info[98].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/fftshift.m";
  c2_info[98].name = "eml_int_forloop_overflow_check";
  c2_info[98].dominantType = "";
  c2_info[98].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[98].fileTimeLo = 1311233716U;
  c2_info[98].fileTimeHi = 0U;
  c2_info[98].mFileTimeLo = 0U;
  c2_info[98].mFileTimeHi = 0U;
  c2_info[99].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/fftshift.m";
  c2_info[99].name = "eml_fftshift";
  c2_info[99].dominantType = "int32";
  c2_info[99].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fftshift.m";
  c2_info[99].fileTimeLo = 1286797176U;
  c2_info[99].fileTimeHi = 0U;
  c2_info[99].mFileTimeLo = 0U;
  c2_info[99].mFileTimeHi = 0U;
  c2_info[100].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fftshift.m";
  c2_info[100].name = "eml_index_rdivide";
  c2_info[100].dominantType = "double";
  c2_info[100].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c2_info[100].fileTimeLo = 1286797180U;
  c2_info[100].fileTimeHi = 0U;
  c2_info[100].mFileTimeLo = 0U;
  c2_info[100].mFileTimeHi = 0U;
  c2_info[101].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fftshift.m";
  c2_info[101].name = "eml_matrix_vstride";
  c2_info[101].dominantType = "int32";
  c2_info[101].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c2_info[101].fileTimeLo = 1286797188U;
  c2_info[101].fileTimeHi = 0U;
  c2_info[101].mFileTimeLo = 0U;
  c2_info[101].mFileTimeHi = 0U;
  c2_info[102].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c2_info[102].name = "eml_index_minus";
  c2_info[102].dominantType = "int32";
  c2_info[102].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[102].fileTimeLo = 1286797178U;
  c2_info[102].fileTimeHi = 0U;
  c2_info[102].mFileTimeLo = 0U;
  c2_info[102].mFileTimeHi = 0U;
  c2_info[103].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c2_info[103].name = "eml_index_class";
  c2_info[103].dominantType = "";
  c2_info[103].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[103].fileTimeLo = 1286797178U;
  c2_info[103].fileTimeHi = 0U;
  c2_info[103].mFileTimeLo = 0U;
  c2_info[103].mFileTimeHi = 0U;
  c2_info[104].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c2_info[104].name = "eml_size_prod";
  c2_info[104].dominantType = "int32";
  c2_info[104].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c2_info[104].fileTimeLo = 1286797198U;
  c2_info[104].fileTimeHi = 0U;
  c2_info[104].mFileTimeLo = 0U;
  c2_info[104].mFileTimeHi = 0U;
  c2_info[105].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c2_info[105].name = "eml_index_class";
  c2_info[105].dominantType = "";
  c2_info[105].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[105].fileTimeLo = 1286797178U;
  c2_info[105].fileTimeHi = 0U;
  c2_info[105].mFileTimeLo = 0U;
  c2_info[105].mFileTimeHi = 0U;
  c2_info[106].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c2_info[106].name = "eml_int_forloop_overflow_check";
  c2_info[106].dominantType = "";
  c2_info[106].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[106].fileTimeLo = 1311233716U;
  c2_info[106].fileTimeHi = 0U;
  c2_info[106].mFileTimeLo = 0U;
  c2_info[106].mFileTimeHi = 0U;
  c2_info[107].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c2_info[107].name = "eml_index_times";
  c2_info[107].dominantType = "int32";
  c2_info[107].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[107].fileTimeLo = 1286797180U;
  c2_info[107].fileTimeHi = 0U;
  c2_info[107].mFileTimeLo = 0U;
  c2_info[107].mFileTimeHi = 0U;
  c2_info[108].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fftshift.m";
  c2_info[108].name = "eml_matrix_npages";
  c2_info[108].dominantType = "int32";
  c2_info[108].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c2_info[108].fileTimeLo = 1286797186U;
  c2_info[108].fileTimeHi = 0U;
  c2_info[108].mFileTimeLo = 0U;
  c2_info[108].mFileTimeHi = 0U;
  c2_info[109].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c2_info[109].name = "eml_index_plus";
  c2_info[109].dominantType = "int32";
  c2_info[109].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[109].fileTimeLo = 1286797178U;
  c2_info[109].fileTimeHi = 0U;
  c2_info[109].mFileTimeLo = 0U;
  c2_info[109].mFileTimeHi = 0U;
  c2_info[110].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c2_info[110].name = "eml_index_class";
  c2_info[110].dominantType = "";
  c2_info[110].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[110].fileTimeLo = 1286797178U;
  c2_info[110].fileTimeHi = 0U;
  c2_info[110].mFileTimeLo = 0U;
  c2_info[110].mFileTimeHi = 0U;
  c2_info[111].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c2_info[111].name = "eml_size_prod";
  c2_info[111].dominantType = "int32";
  c2_info[111].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c2_info[111].fileTimeLo = 1286797198U;
  c2_info[111].fileTimeHi = 0U;
  c2_info[111].mFileTimeLo = 0U;
  c2_info[111].mFileTimeHi = 0U;
  c2_info[112].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fftshift.m";
  c2_info[112].name = "eml_index_minus";
  c2_info[112].dominantType = "double";
  c2_info[112].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[112].fileTimeLo = 1286797178U;
  c2_info[112].fileTimeHi = 0U;
  c2_info[112].mFileTimeLo = 0U;
  c2_info[112].mFileTimeHi = 0U;
  c2_info[113].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fftshift.m";
  c2_info[113].name = "eml_index_times";
  c2_info[113].dominantType = "int32";
  c2_info[113].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[113].fileTimeLo = 1286797180U;
  c2_info[113].fileTimeHi = 0U;
  c2_info[113].mFileTimeLo = 0U;
  c2_info[113].mFileTimeHi = 0U;
  c2_info[114].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fftshift.m";
  c2_info[114].name = "eml_index_class";
  c2_info[114].dominantType = "";
  c2_info[114].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[114].fileTimeLo = 1286797178U;
  c2_info[114].fileTimeHi = 0U;
  c2_info[114].mFileTimeLo = 0U;
  c2_info[114].mFileTimeHi = 0U;
  c2_info[115].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fftshift.m";
  c2_info[115].name = "eml_int_forloop_overflow_check";
  c2_info[115].dominantType = "";
  c2_info[115].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[115].fileTimeLo = 1311233716U;
  c2_info[115].fileTimeHi = 0U;
  c2_info[115].mFileTimeLo = 0U;
  c2_info[115].mFileTimeHi = 0U;
  c2_info[116].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_fftshift.m";
  c2_info[116].name = "eml_index_plus";
  c2_info[116].dominantType = "int32";
  c2_info[116].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[116].fileTimeLo = 1286797178U;
  c2_info[116].fileTimeHi = 0U;
  c2_info[116].mFileTimeLo = 0U;
  c2_info[116].mFileTimeHi = 0U;
  c2_info[117].context = "";
  c2_info[117].name = "abs";
  c2_info[117].dominantType = "double";
  c2_info[117].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[117].fileTimeLo = 1286797094U;
  c2_info[117].fileTimeHi = 0U;
  c2_info[117].mFileTimeLo = 0U;
  c2_info[117].mFileTimeHi = 0U;
  c2_info[118].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[118].name = "eml_scalar_abs";
  c2_info[118].dominantType = "double";
  c2_info[118].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[118].fileTimeLo = 1286797112U;
  c2_info[118].fileTimeHi = 0U;
  c2_info[118].mFileTimeLo = 0U;
  c2_info[118].mFileTimeHi = 0U;
  c2_info[119].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[119].name = "eml_dlapy2";
  c2_info[119].dominantType = "double";
  c2_info[119].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c2_info[119].fileTimeLo = 1307629640U;
  c2_info[119].fileTimeHi = 0U;
  c2_info[119].mFileTimeLo = 0U;
  c2_info[119].mFileTimeHi = 0U;
  c2_info[120].context = "";
  c2_info[120].name = "log";
  c2_info[120].dominantType = "double";
  c2_info[120].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/log.m";
  c2_info[120].fileTimeLo = 1286797142U;
  c2_info[120].fileTimeHi = 0U;
  c2_info[120].mFileTimeLo = 0U;
  c2_info[120].mFileTimeHi = 0U;
  c2_info[121].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/log.m";
  c2_info[121].name = "eml_error";
  c2_info[121].dominantType = "char";
  c2_info[121].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[121].fileTimeLo = 1305296400U;
  c2_info[121].fileTimeHi = 0U;
  c2_info[121].mFileTimeLo = 0U;
  c2_info[121].mFileTimeHi = 0U;
  c2_info[122].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/log.m";
  c2_info[122].name = "eml_scalar_log";
  c2_info[122].dominantType = "double";
  c2_info[122].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_log.m";
  c2_info[122].fileTimeLo = 1286797128U;
  c2_info[122].fileTimeHi = 0U;
  c2_info[122].mFileTimeLo = 0U;
  c2_info[122].mFileTimeHi = 0U;
  c2_info[123].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_log.m";
  c2_info[123].name = "realmax";
  c2_info[123].dominantType = "char";
  c2_info[123].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[123].fileTimeLo = 1307629642U;
  c2_info[123].fileTimeHi = 0U;
  c2_info[123].mFileTimeLo = 0U;
  c2_info[123].mFileTimeHi = 0U;
  c2_info[124].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[124].name = "eml_realmax";
  c2_info[124].dominantType = "char";
  c2_info[124].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[124].fileTimeLo = 1307629644U;
  c2_info[124].fileTimeHi = 0U;
  c2_info[124].mFileTimeLo = 0U;
  c2_info[124].mFileTimeHi = 0U;
  c2_info[125].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[125].name = "eml_float_model";
  c2_info[125].dominantType = "char";
  c2_info[125].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[125].fileTimeLo = 1307629642U;
  c2_info[125].fileTimeHi = 0U;
  c2_info[125].mFileTimeLo = 0U;
  c2_info[125].mFileTimeHi = 0U;
  c2_info[126].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[126].name = "mtimes";
  c2_info[126].dominantType = "double";
  c2_info[126].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[126].fileTimeLo = 1289494492U;
  c2_info[126].fileTimeHi = 0U;
  c2_info[126].mFileTimeLo = 0U;
  c2_info[126].mFileTimeHi = 0U;
  c2_info[127].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_log.m";
  c2_info[127].name = "mrdivide";
  c2_info[127].dominantType = "double";
  c2_info[127].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[127].fileTimeLo = 1325098938U;
  c2_info[127].fileTimeHi = 0U;
  c2_info[127].mFileTimeLo = 1319708366U;
  c2_info[127].mFileTimeHi = 0U;
}

static void c2_eml_fft(SFc2_demo_20210521InstanceStruct *chartInstance, real_T
  c2_x[65536], creal_T c2_y[65536])
{
  int32_T c2_i27;
  static real_T c2_b_x[65536];
  static real_T c2_dv2[65536];
  int32_T c2_i28;
  static real_T c2_dv3[65536];
  static creal_T c2_y1[65536];
  int32_T c2_i29;
  static creal_T c2_b_y1[65536];
  c2_eml_assert_valid_dim(chartInstance);
  c2_eml_size_ispow2(chartInstance);
  for (c2_i27 = 0; c2_i27 < 65536; c2_i27++) {
    c2_b_x[c2_i27] = c2_x[c2_i27];
  }

  c2_permute(chartInstance, c2_b_x, c2_dv2);
  for (c2_i28 = 0; c2_i28 < 65536; c2_i28++) {
    c2_dv3[c2_i28] = c2_dv2[c2_i28];
  }

  c2_b_eml_fft(chartInstance, c2_dv3, c2_y1);
  for (c2_i29 = 0; c2_i29 < 65536; c2_i29++) {
    c2_b_y1[c2_i29] = c2_y1[c2_i29];
  }

  c2_ipermute(chartInstance, c2_b_y1, c2_y);
}

static void c2_eml_assert_valid_dim(SFc2_demo_20210521InstanceStruct
  *chartInstance)
{
}

static void c2_eml_size_ispow2(SFc2_demo_20210521InstanceStruct *chartInstance)
{
}

static void c2_permute(SFc2_demo_20210521InstanceStruct *chartInstance, real_T
  c2_a[65536], real_T c2_b[65536])
{
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  c2_i30 = 0;
  for (c2_i31 = 0; c2_i31 < 256; c2_i31++) {
    c2_i32 = 0;
    for (c2_i33 = 0; c2_i33 < 256; c2_i33++) {
      c2_b[c2_i33 + c2_i30] = c2_a[c2_i32 + c2_i31];
      c2_i32 += 256;
    }

    c2_i30 += 256;
  }
}

static void c2_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance)
{
}

static void c2_b_eml_fft(SFc2_demo_20210521InstanceStruct *chartInstance, real_T
  c2_x[65536], creal_T c2_y[65536])
{
  int32_T c2_ix;
  int32_T c2_chanStart;
  int32_T c2_b_chanStart;
  uint32_T c2_ju;
  int32_T c2_iy;
  int32_T c2_i;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b_a;
  int32_T c2_b_c;
  uint32_T c2_n;
  boolean_T c2_tst;
  int32_T c2_c_a;
  int32_T c2_b;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_c_c;
  int32_T c2_f_a;
  int32_T c2_d_c;
  int32_T c2_g_a;
  int32_T c2_i1;
  int32_T c2_h_a;
  int32_T c2_i2;
  int32_T c2_b_i1;
  int32_T c2_b_i;
  int32_T c2_c_i;
  int32_T c2_i_a;
  int32_T c2_e_c;
  creal_T c2_temp;
  int32_T c2_j_a;
  int32_T c2_f_c;
  int32_T c2_k_a;
  int32_T c2_g_c;
  int32_T c2_l_a;
  int32_T c2_h_c;
  int32_T c2_m_a;
  int32_T c2_i_c;
  int32_T c2_iDelta;
  int32_T c2_iDelta2;
  int32_T c2_k;
  int32_T c2_iheight;
  int32_T c2_istart;
  int32_T c2_n_a;
  int32_T c2_b_b;
  int32_T c2_ihi;
  int32_T c2_o_a;
  int32_T c2_c_b;
  int32_T c2_j_c;
  int32_T c2_p_a;
  int32_T c2_k_c;
  int32_T c2_q_a;
  int32_T c2_d_b;
  int32_T c2_l_c;
  int32_T c2_r_a;
  int32_T c2_m_c;
  int32_T c2_s_a;
  int32_T c2_n_c;
  int32_T c2_t_a;
  int32_T c2_o_c;
  int32_T c2_u_a;
  int32_T c2_p_c;
  int32_T c2_v_a;
  int32_T c2_e_b;
  int32_T c2_w_a;
  int32_T c2_f_b;
  int32_T c2_j;
  int32_T c2_x_a;
  int32_T c2_q_c;
  int32_T c2_y_a;
  int32_T c2_r_c;
  static real_T c2_dv4[129] = { 1.0, 0.99969881869620425, 0.99879545620517241,
    0.99729045667869021, 0.99518472667219693, 0.99247953459871,
    0.989176509964781, 0.98527764238894122, 0.98078528040323043,
    0.97570213003852857, 0.970031253194544, 0.96377606579543984,
    0.95694033573220882, 0.94952818059303667, 0.94154406518302081,
    0.932992798834739, 0.92387953251128674, 0.91420975570353069,
    0.90398929312344334, 0.89322430119551532, 0.881921264348355,
    0.87008699110871146, 0.85772861000027212, 0.84485356524970712,
    0.83146961230254524, 0.81758481315158371, 0.80320753148064494,
    0.78834642762660634, 0.773010453362737, 0.75720884650648457,
    0.74095112535495922, 0.724247082951467, 0.70710678118654757,
    0.68954054473706683, 0.67155895484701833, 0.65317284295377676,
    0.63439328416364549, 0.61523159058062682, 0.59569930449243336,
    0.57580819141784534, 0.55557023301960218, 0.53499761988709715,
    0.51410274419322166, 0.49289819222978404, 0.47139673682599764,
    0.44961132965460654, 0.42755509343028208, 0.40524131400498986,
    0.38268343236508978, 0.35989503653498811, 0.33688985339222005,
    0.31368174039889152, 0.29028467725446233, 0.26671275747489837,
    0.24298017990326387, 0.2191012401568698, 0.19509032201612825,
    0.17096188876030122, 0.14673047445536175, 0.1224106751992162,
    0.0980171403295606, 0.073564563599667426, 0.049067674327418015,
    0.024541228522912288, 0.0, -0.024541228522912288, -0.049067674327418015,
    -0.073564563599667426, -0.0980171403295606, -0.1224106751992162,
    -0.14673047445536175, -0.17096188876030122, -0.19509032201612825,
    -0.2191012401568698, -0.24298017990326387, -0.26671275747489837,
    -0.29028467725446233, -0.31368174039889152, -0.33688985339222005,
    -0.35989503653498811, -0.38268343236508978, -0.40524131400498986,
    -0.42755509343028208, -0.44961132965460654, -0.47139673682599764,
    -0.49289819222978404, -0.51410274419322166, -0.53499761988709715,
    -0.55557023301960218, -0.57580819141784534, -0.59569930449243336,
    -0.61523159058062682, -0.63439328416364549, -0.65317284295377676,
    -0.67155895484701833, -0.68954054473706683, -0.70710678118654757,
    -0.724247082951467, -0.74095112535495922, -0.75720884650648457,
    -0.773010453362737, -0.78834642762660634, -0.80320753148064494,
    -0.81758481315158371, -0.83146961230254524, -0.84485356524970712,
    -0.85772861000027212, -0.87008699110871146, -0.881921264348355,
    -0.89322430119551532, -0.90398929312344334, -0.91420975570353069,
    -0.92387953251128674, -0.932992798834739, -0.94154406518302081,
    -0.94952818059303667, -0.95694033573220882, -0.96377606579543984,
    -0.970031253194544, -0.97570213003852857, -0.98078528040323043,
    -0.98527764238894122, -0.989176509964781, -0.99247953459871,
    -0.99518472667219693, -0.99729045667869021, -0.99879545620517241,
    -0.99969881869620425, -1.0 };

  creal_T c2_twid;
  static real_T c2_dv5[129] = { 0.0, -0.024541228522912288,
    -0.049067674327418015, -0.073564563599667426, -0.0980171403295606,
    -0.1224106751992162, -0.14673047445536175, -0.17096188876030122,
    -0.19509032201612825, -0.2191012401568698, -0.24298017990326387,
    -0.26671275747489837, -0.29028467725446233, -0.31368174039889152,
    -0.33688985339222005, -0.35989503653498811, -0.38268343236508978,
    -0.40524131400498986, -0.42755509343028208, -0.44961132965460654,
    -0.47139673682599764, -0.49289819222978404, -0.51410274419322166,
    -0.53499761988709715, -0.55557023301960218, -0.57580819141784534,
    -0.59569930449243336, -0.61523159058062682, -0.63439328416364549,
    -0.65317284295377676, -0.67155895484701833, -0.68954054473706683,
    -0.70710678118654757, -0.724247082951467, -0.74095112535495922,
    -0.75720884650648457, -0.773010453362737, -0.78834642762660634,
    -0.80320753148064494, -0.81758481315158371, -0.83146961230254524,
    -0.84485356524970712, -0.85772861000027212, -0.87008699110871146,
    -0.881921264348355, -0.89322430119551532, -0.90398929312344334,
    -0.91420975570353069, -0.92387953251128674, -0.932992798834739,
    -0.94154406518302081, -0.94952818059303667, -0.95694033573220882,
    -0.96377606579543984, -0.970031253194544, -0.97570213003852857,
    -0.98078528040323043, -0.98527764238894122, -0.989176509964781,
    -0.99247953459871, -0.99518472667219693, -0.99729045667869021,
    -0.99879545620517241, -0.99969881869620425, -1.0, -0.99969881869620425,
    -0.99879545620517241, -0.99729045667869021, -0.99518472667219693,
    -0.99247953459871, -0.989176509964781, -0.98527764238894122,
    -0.98078528040323043, -0.97570213003852857, -0.970031253194544,
    -0.96377606579543984, -0.95694033573220882, -0.94952818059303667,
    -0.94154406518302081, -0.932992798834739, -0.92387953251128674,
    -0.91420975570353069, -0.90398929312344334, -0.89322430119551532,
    -0.881921264348355, -0.87008699110871146, -0.85772861000027212,
    -0.84485356524970712, -0.83146961230254524, -0.81758481315158371,
    -0.80320753148064494, -0.78834642762660634, -0.773010453362737,
    -0.75720884650648457, -0.74095112535495922, -0.724247082951467,
    -0.70710678118654757, -0.68954054473706683, -0.67155895484701833,
    -0.65317284295377676, -0.63439328416364549, -0.61523159058062682,
    -0.59569930449243336, -0.57580819141784534, -0.55557023301960218,
    -0.53499761988709715, -0.51410274419322166, -0.49289819222978404,
    -0.47139673682599764, -0.44961132965460654, -0.42755509343028208,
    -0.40524131400498986, -0.38268343236508978, -0.35989503653498811,
    -0.33688985339222005, -0.31368174039889152, -0.29028467725446233,
    -0.26671275747489837, -0.24298017990326387, -0.2191012401568698,
    -0.19509032201612825, -0.17096188876030122, -0.14673047445536175,
    -0.1224106751992162, -0.0980171403295606, -0.073564563599667426,
    -0.049067674327418015, -0.024541228522912288, -0.0 };

  int32_T c2_ab_a;
  int32_T c2_g_b;
  int32_T c2_bb_a;
  int32_T c2_h_b;
  int32_T c2_s_c;
  int32_T c2_cb_a;
  int32_T c2_t_c;
  creal_T c2_b_temp;
  int32_T c2_db_a;
  int32_T c2_i_b;
  int32_T c2_u_c;
  int32_T c2_eb_a;
  int32_T c2_v_c;
  int32_T c2_fb_a;
  int32_T c2_w_c;
  int32_T c2_gb_a;
  int32_T c2_x_c;
  int32_T c2_hb_a;
  int32_T c2_y_c;
  int32_T c2_ib_a;
  int32_T c2_j_b;
  int32_T c2_jb_a;
  int32_T c2_kb_a;
  int32_T c2_k_b;
  int32_T c2_lb_a;
  int32_T c2_i34;
  int32_T c2_mb_a;
  int32_T c2_nb_a;
  int32_T c2_l_b;
  c2_b_eml_assert_valid_dim(chartInstance);
  c2_eml_size_ispow2(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  c2_ix = 0;
  c2_b_eml_int_forloop_overflow_check(chartInstance);
  for (c2_chanStart = 0; c2_chanStart < 65281; c2_chanStart += 256) {
    c2_b_chanStart = c2_chanStart;
    c2_ju = 0U;
    c2_iy = c2_b_chanStart;
    c2_c_eml_int_forloop_overflow_check(chartInstance);
    for (c2_i = 1; c2_i < 256; c2_i++) {
      c2_a = c2_iy;
      c2_c = c2_a;
      c2_b_a = c2_ix;
      c2_b_c = c2_b_a;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c + 1)), 1, 65536, 1, 0) - 1].re =
        c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_b_c + 1)), 1, 65536, 1, 0) - 1];
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c + 1)), 1, 65536, 1, 0) - 1].im = 0.0;
      c2_n = 256U;
      c2_tst = TRUE;
      while (c2_tst) {
        c2_n >>= 1U;
        c2_ju ^= c2_n;
        c2_tst = ((real_T)(c2_ju & c2_n) == 0.0);
      }

      c2_c_a = c2_b_chanStart;
      c2_b = (int32_T)c2_ju;
      c2_iy = c2_c_a + c2_b;
      c2_d_a = c2_ix + 1;
      c2_ix = c2_d_a;
    }

    c2_e_a = c2_iy;
    c2_c_c = c2_e_a;
    c2_f_a = c2_ix;
    c2_d_c = c2_f_a;
    c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
                                      (c2_c_c + 1)), 1, 65536, 1, 0) - 1].re =
      c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)(c2_d_c + 1)), 1, 65536, 1, 0) - 1];
    c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
                                      (c2_c_c + 1)), 1, 65536, 1, 0) - 1].im =
      0.0;
    c2_g_a = c2_ix + 1;
    c2_ix = c2_g_a;
    c2_i1 = c2_b_chanStart;
    c2_h_a = c2_i1 + 254;
    c2_i2 = c2_h_a;
    c2_b_i1 = c2_i1;
    c2_d_eml_int_forloop_overflow_check(chartInstance, c2_b_i1, c2_i2);
    for (c2_b_i = c2_b_i1; c2_b_i <= c2_i2; c2_b_i += 2) {
      c2_c_i = c2_b_i;
      c2_i_a = c2_c_i;
      c2_e_c = c2_i_a;
      c2_temp = c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)(c2_e_c + 2)), 1, 65536, 1, 0) - 1];
      c2_j_a = c2_c_i;
      c2_f_c = c2_j_a;
      c2_k_a = c2_c_i;
      c2_g_c = c2_k_a;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_f_c + 2)), 1, 65536, 1, 0) - 1].re =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_g_c + 1)), 1, 65536, 1, 0) - 1].re - c2_temp.re;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_f_c + 2)), 1, 65536, 1, 0) - 1].im =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_g_c + 1)), 1, 65536, 1, 0) - 1].im - c2_temp.im;
      c2_l_a = c2_c_i;
      c2_h_c = c2_l_a;
      c2_m_a = c2_c_i;
      c2_i_c = c2_m_a;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_h_c + 1)), 1, 65536, 1, 0) - 1].re =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_i_c + 1)), 1, 65536, 1, 0) - 1].re + c2_temp.re;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_h_c + 1)), 1, 65536, 1, 0) - 1].im =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_i_c + 1)), 1, 65536, 1, 0) - 1].im + c2_temp.im;
    }

    c2_iDelta = 2;
    c2_iDelta2 = 4;
    c2_k = 64;
    c2_iheight = 253;
    while ((real_T)c2_k > 0.0) {
      c2_istart = c2_b_chanStart;
      c2_c_i = c2_istart;
      c2_n_a = c2_c_i;
      c2_b_b = c2_iheight;
      c2_ihi = c2_n_a + c2_b_b;
      while (c2_c_i < c2_ihi) {
        c2_o_a = c2_c_i;
        c2_c_b = c2_iDelta;
        c2_j_c = c2_o_a + c2_c_b;
        c2_p_a = c2_j_c;
        c2_k_c = c2_p_a;
        c2_temp = c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c2_k_c + 1)), 1, 65536, 1, 0) - 1];
        c2_q_a = c2_c_i;
        c2_d_b = c2_iDelta;
        c2_l_c = c2_q_a + c2_d_b;
        c2_r_a = c2_l_c;
        c2_m_c = c2_r_a;
        c2_s_a = c2_c_i;
        c2_n_c = c2_s_a;
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_m_c + 1)), 1, 65536, 1, 0) - 1].re =
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_n_c + 1)), 1, 65536, 1, 0) - 1].re - c2_temp.re;
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_m_c + 1)), 1, 65536, 1, 0) - 1].im =
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_n_c + 1)), 1, 65536, 1, 0) - 1].im - c2_temp.im;
        c2_t_a = c2_c_i;
        c2_o_c = c2_t_a;
        c2_u_a = c2_c_i;
        c2_p_c = c2_u_a;
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_o_c + 1)), 1, 65536, 1, 0) - 1].re =
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_p_c + 1)), 1, 65536, 1, 0) - 1].re + c2_temp.re;
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_o_c + 1)), 1, 65536, 1, 0) - 1].im =
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_p_c + 1)), 1, 65536, 1, 0) - 1].im + c2_temp.im;
        c2_v_a = c2_c_i;
        c2_e_b = c2_iDelta2;
        c2_c_i = c2_v_a + c2_e_b;
      }

      c2_w_a = c2_istart;
      c2_istart = c2_w_a;
      c2_f_b = c2_k;
      for (c2_j = c2_f_b; c2_j < 128; c2_j = c2_kb_a + c2_k_b) {
        c2_x_a = c2_j;
        c2_q_c = c2_x_a;
        c2_y_a = c2_j;
        c2_r_c = c2_y_a;
        c2_twid.re = c2_dv4[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c2_q_c + 1)), 1, 129, 1, 0) - 1];
        c2_twid.im = c2_dv5[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c2_r_c + 1)), 1, 129, 1, 0) - 1];
        c2_c_i = c2_istart + 1;
        c2_ab_a = c2_c_i;
        c2_g_b = c2_iheight;
        c2_ihi = c2_ab_a + c2_g_b;
        while (c2_c_i < c2_ihi) {
          c2_bb_a = c2_c_i;
          c2_h_b = c2_iDelta;
          c2_s_c = c2_bb_a + c2_h_b;
          c2_cb_a = c2_s_c;
          c2_t_c = c2_cb_a;
          c2_temp = c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)(c2_t_c + 1)), 1, 65536, 1, 0) - 1];
          c2_b_temp = c2_temp;
          c2_temp.re = c2_twid.re * c2_b_temp.re - c2_twid.im * c2_b_temp.im;
          c2_temp.im = c2_twid.re * c2_b_temp.im + c2_twid.im * c2_b_temp.re;
          c2_db_a = c2_c_i;
          c2_i_b = c2_iDelta;
          c2_u_c = c2_db_a + c2_i_b;
          c2_eb_a = c2_u_c;
          c2_v_c = c2_eb_a;
          c2_fb_a = c2_c_i;
          c2_w_c = c2_fb_a;
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_v_c + 1)), 1, 65536, 1, 0) - 1].re =
            c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_w_c + 1)), 1, 65536, 1, 0) - 1].re - c2_temp.re;
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_v_c + 1)), 1, 65536, 1, 0) - 1].im =
            c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_w_c + 1)), 1, 65536, 1, 0) - 1].im - c2_temp.im;
          c2_gb_a = c2_c_i;
          c2_x_c = c2_gb_a;
          c2_hb_a = c2_c_i;
          c2_y_c = c2_hb_a;
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_x_c + 1)), 1, 65536, 1, 0) - 1].re =
            c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_y_c + 1)), 1, 65536, 1, 0) - 1].re + c2_temp.re;
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_x_c + 1)), 1, 65536, 1, 0) - 1].im =
            c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_y_c + 1)), 1, 65536, 1, 0) - 1].im + c2_temp.im;
          c2_ib_a = c2_c_i;
          c2_j_b = c2_iDelta2;
          c2_c_i = c2_ib_a + c2_j_b;
        }

        c2_jb_a = c2_istart + 1;
        c2_istart = c2_jb_a;
        c2_kb_a = c2_j;
        c2_k_b = c2_k;
      }

      c2_lb_a = c2_k;
      c2_i34 = c2_lb_a;
      c2_k = (c2_i34 + (c2_i34 < 0)) >> 1;
      c2_iDelta = c2_iDelta2;
      c2_mb_a = c2_iDelta;
      c2_iDelta2 = c2_mb_a << 1;
      c2_nb_a = c2_iheight;
      c2_l_b = c2_iDelta;
      c2_iheight = c2_nb_a - c2_l_b;
    }
  }
}

static void c2_b_eml_assert_valid_dim(SFc2_demo_20210521InstanceStruct
  *chartInstance)
{
}

static void c2_eml_scalar_eg(SFc2_demo_20210521InstanceStruct *chartInstance)
{
}

static void c2_b_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance)
{
}

static void c2_c_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance)
{
}

static void c2_d_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance, int32_T c2_a, int32_T c2_b)
{
  int32_T c2_b_a;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  boolean_T c2_safe;
  int32_T c2_i35;
  static char_T c2_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i36;
  static char_T c2_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  c2_b_a = c2_a;
  c2_b_b = c2_b;
  if (c2_b_a > c2_b_b) {
    c2_overflow = FALSE;
  } else {
    c2_overflow = (c2_b_b > 2147483645);
  }

  c2_safe = !c2_overflow;
  if (c2_safe) {
  } else {
    for (c2_i35 = 0; c2_i35 < 34; c2_i35++) {
      c2_u[c2_i35] = c2_cv0[c2_i35];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c2_i36 = 0; c2_i36 < 5; c2_i36++) {
      c2_b_u[c2_i36] = c2_cv1[c2_i36];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c2_y, 14, c2_b_y));
  }
}

static void c2_ipermute(SFc2_demo_20210521InstanceStruct *chartInstance, creal_T
  c2_b[65536], creal_T c2_a[65536])
{
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  c2_i37 = 0;
  for (c2_i38 = 0; c2_i38 < 256; c2_i38++) {
    c2_i39 = 0;
    for (c2_i40 = 0; c2_i40 < 256; c2_i40++) {
      c2_a[c2_i40 + c2_i37] = c2_b[c2_i39 + c2_i38];
      c2_i39 += 256;
    }

    c2_i37 += 256;
  }
}

static void c2_c_eml_fft(SFc2_demo_20210521InstanceStruct *chartInstance,
  creal_T c2_x[65536], creal_T c2_y[65536])
{
  int32_T c2_ix;
  int32_T c2_chanStart;
  int32_T c2_b_chanStart;
  uint32_T c2_ju;
  int32_T c2_iy;
  int32_T c2_i;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b_a;
  int32_T c2_b_c;
  uint32_T c2_n;
  boolean_T c2_tst;
  int32_T c2_c_a;
  int32_T c2_b;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_c_c;
  int32_T c2_f_a;
  int32_T c2_d_c;
  int32_T c2_g_a;
  int32_T c2_i1;
  int32_T c2_h_a;
  int32_T c2_i2;
  int32_T c2_b_i1;
  int32_T c2_b_i;
  int32_T c2_c_i;
  int32_T c2_i_a;
  int32_T c2_e_c;
  creal_T c2_temp;
  int32_T c2_j_a;
  int32_T c2_f_c;
  int32_T c2_k_a;
  int32_T c2_g_c;
  int32_T c2_l_a;
  int32_T c2_h_c;
  int32_T c2_m_a;
  int32_T c2_i_c;
  int32_T c2_iDelta;
  int32_T c2_iDelta2;
  int32_T c2_k;
  int32_T c2_iheight;
  int32_T c2_istart;
  int32_T c2_n_a;
  int32_T c2_b_b;
  int32_T c2_ihi;
  int32_T c2_o_a;
  int32_T c2_c_b;
  int32_T c2_j_c;
  int32_T c2_p_a;
  int32_T c2_k_c;
  int32_T c2_q_a;
  int32_T c2_d_b;
  int32_T c2_l_c;
  int32_T c2_r_a;
  int32_T c2_m_c;
  int32_T c2_s_a;
  int32_T c2_n_c;
  int32_T c2_t_a;
  int32_T c2_o_c;
  int32_T c2_u_a;
  int32_T c2_p_c;
  int32_T c2_v_a;
  int32_T c2_e_b;
  int32_T c2_w_a;
  int32_T c2_f_b;
  int32_T c2_j;
  int32_T c2_x_a;
  int32_T c2_q_c;
  int32_T c2_y_a;
  int32_T c2_r_c;
  static real_T c2_dv6[129] = { 1.0, 0.99969881869620425, 0.99879545620517241,
    0.99729045667869021, 0.99518472667219693, 0.99247953459871,
    0.989176509964781, 0.98527764238894122, 0.98078528040323043,
    0.97570213003852857, 0.970031253194544, 0.96377606579543984,
    0.95694033573220882, 0.94952818059303667, 0.94154406518302081,
    0.932992798834739, 0.92387953251128674, 0.91420975570353069,
    0.90398929312344334, 0.89322430119551532, 0.881921264348355,
    0.87008699110871146, 0.85772861000027212, 0.84485356524970712,
    0.83146961230254524, 0.81758481315158371, 0.80320753148064494,
    0.78834642762660634, 0.773010453362737, 0.75720884650648457,
    0.74095112535495922, 0.724247082951467, 0.70710678118654757,
    0.68954054473706683, 0.67155895484701833, 0.65317284295377676,
    0.63439328416364549, 0.61523159058062682, 0.59569930449243336,
    0.57580819141784534, 0.55557023301960218, 0.53499761988709715,
    0.51410274419322166, 0.49289819222978404, 0.47139673682599764,
    0.44961132965460654, 0.42755509343028208, 0.40524131400498986,
    0.38268343236508978, 0.35989503653498811, 0.33688985339222005,
    0.31368174039889152, 0.29028467725446233, 0.26671275747489837,
    0.24298017990326387, 0.2191012401568698, 0.19509032201612825,
    0.17096188876030122, 0.14673047445536175, 0.1224106751992162,
    0.0980171403295606, 0.073564563599667426, 0.049067674327418015,
    0.024541228522912288, 0.0, -0.024541228522912288, -0.049067674327418015,
    -0.073564563599667426, -0.0980171403295606, -0.1224106751992162,
    -0.14673047445536175, -0.17096188876030122, -0.19509032201612825,
    -0.2191012401568698, -0.24298017990326387, -0.26671275747489837,
    -0.29028467725446233, -0.31368174039889152, -0.33688985339222005,
    -0.35989503653498811, -0.38268343236508978, -0.40524131400498986,
    -0.42755509343028208, -0.44961132965460654, -0.47139673682599764,
    -0.49289819222978404, -0.51410274419322166, -0.53499761988709715,
    -0.55557023301960218, -0.57580819141784534, -0.59569930449243336,
    -0.61523159058062682, -0.63439328416364549, -0.65317284295377676,
    -0.67155895484701833, -0.68954054473706683, -0.70710678118654757,
    -0.724247082951467, -0.74095112535495922, -0.75720884650648457,
    -0.773010453362737, -0.78834642762660634, -0.80320753148064494,
    -0.81758481315158371, -0.83146961230254524, -0.84485356524970712,
    -0.85772861000027212, -0.87008699110871146, -0.881921264348355,
    -0.89322430119551532, -0.90398929312344334, -0.91420975570353069,
    -0.92387953251128674, -0.932992798834739, -0.94154406518302081,
    -0.94952818059303667, -0.95694033573220882, -0.96377606579543984,
    -0.970031253194544, -0.97570213003852857, -0.98078528040323043,
    -0.98527764238894122, -0.989176509964781, -0.99247953459871,
    -0.99518472667219693, -0.99729045667869021, -0.99879545620517241,
    -0.99969881869620425, -1.0 };

  creal_T c2_twid;
  static real_T c2_dv7[129] = { 0.0, -0.024541228522912288,
    -0.049067674327418015, -0.073564563599667426, -0.0980171403295606,
    -0.1224106751992162, -0.14673047445536175, -0.17096188876030122,
    -0.19509032201612825, -0.2191012401568698, -0.24298017990326387,
    -0.26671275747489837, -0.29028467725446233, -0.31368174039889152,
    -0.33688985339222005, -0.35989503653498811, -0.38268343236508978,
    -0.40524131400498986, -0.42755509343028208, -0.44961132965460654,
    -0.47139673682599764, -0.49289819222978404, -0.51410274419322166,
    -0.53499761988709715, -0.55557023301960218, -0.57580819141784534,
    -0.59569930449243336, -0.61523159058062682, -0.63439328416364549,
    -0.65317284295377676, -0.67155895484701833, -0.68954054473706683,
    -0.70710678118654757, -0.724247082951467, -0.74095112535495922,
    -0.75720884650648457, -0.773010453362737, -0.78834642762660634,
    -0.80320753148064494, -0.81758481315158371, -0.83146961230254524,
    -0.84485356524970712, -0.85772861000027212, -0.87008699110871146,
    -0.881921264348355, -0.89322430119551532, -0.90398929312344334,
    -0.91420975570353069, -0.92387953251128674, -0.932992798834739,
    -0.94154406518302081, -0.94952818059303667, -0.95694033573220882,
    -0.96377606579543984, -0.970031253194544, -0.97570213003852857,
    -0.98078528040323043, -0.98527764238894122, -0.989176509964781,
    -0.99247953459871, -0.99518472667219693, -0.99729045667869021,
    -0.99879545620517241, -0.99969881869620425, -1.0, -0.99969881869620425,
    -0.99879545620517241, -0.99729045667869021, -0.99518472667219693,
    -0.99247953459871, -0.989176509964781, -0.98527764238894122,
    -0.98078528040323043, -0.97570213003852857, -0.970031253194544,
    -0.96377606579543984, -0.95694033573220882, -0.94952818059303667,
    -0.94154406518302081, -0.932992798834739, -0.92387953251128674,
    -0.91420975570353069, -0.90398929312344334, -0.89322430119551532,
    -0.881921264348355, -0.87008699110871146, -0.85772861000027212,
    -0.84485356524970712, -0.83146961230254524, -0.81758481315158371,
    -0.80320753148064494, -0.78834642762660634, -0.773010453362737,
    -0.75720884650648457, -0.74095112535495922, -0.724247082951467,
    -0.70710678118654757, -0.68954054473706683, -0.67155895484701833,
    -0.65317284295377676, -0.63439328416364549, -0.61523159058062682,
    -0.59569930449243336, -0.57580819141784534, -0.55557023301960218,
    -0.53499761988709715, -0.51410274419322166, -0.49289819222978404,
    -0.47139673682599764, -0.44961132965460654, -0.42755509343028208,
    -0.40524131400498986, -0.38268343236508978, -0.35989503653498811,
    -0.33688985339222005, -0.31368174039889152, -0.29028467725446233,
    -0.26671275747489837, -0.24298017990326387, -0.2191012401568698,
    -0.19509032201612825, -0.17096188876030122, -0.14673047445536175,
    -0.1224106751992162, -0.0980171403295606, -0.073564563599667426,
    -0.049067674327418015, -0.024541228522912288, -0.0 };

  int32_T c2_ab_a;
  int32_T c2_g_b;
  int32_T c2_bb_a;
  int32_T c2_h_b;
  int32_T c2_s_c;
  int32_T c2_cb_a;
  int32_T c2_t_c;
  creal_T c2_b_temp;
  int32_T c2_db_a;
  int32_T c2_i_b;
  int32_T c2_u_c;
  int32_T c2_eb_a;
  int32_T c2_v_c;
  int32_T c2_fb_a;
  int32_T c2_w_c;
  int32_T c2_gb_a;
  int32_T c2_x_c;
  int32_T c2_hb_a;
  int32_T c2_y_c;
  int32_T c2_ib_a;
  int32_T c2_j_b;
  int32_T c2_jb_a;
  int32_T c2_kb_a;
  int32_T c2_k_b;
  int32_T c2_lb_a;
  int32_T c2_i41;
  int32_T c2_mb_a;
  int32_T c2_nb_a;
  int32_T c2_l_b;
  c2_b_eml_assert_valid_dim(chartInstance);
  c2_eml_size_ispow2(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  c2_ix = 0;
  c2_b_eml_int_forloop_overflow_check(chartInstance);
  for (c2_chanStart = 0; c2_chanStart < 65281; c2_chanStart += 256) {
    c2_b_chanStart = c2_chanStart;
    c2_ju = 0U;
    c2_iy = c2_b_chanStart;
    c2_c_eml_int_forloop_overflow_check(chartInstance);
    for (c2_i = 1; c2_i < 256; c2_i++) {
      c2_a = c2_iy;
      c2_c = c2_a;
      c2_b_a = c2_ix;
      c2_b_c = c2_b_a;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c + 1)), 1, 65536, 1, 0) - 1] =
        c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_b_c + 1)), 1, 65536, 1, 0) - 1];
      c2_n = 256U;
      c2_tst = TRUE;
      while (c2_tst) {
        c2_n >>= 1U;
        c2_ju ^= c2_n;
        c2_tst = ((real_T)(c2_ju & c2_n) == 0.0);
      }

      c2_c_a = c2_b_chanStart;
      c2_b = (int32_T)c2_ju;
      c2_iy = c2_c_a + c2_b;
      c2_d_a = c2_ix + 1;
      c2_ix = c2_d_a;
    }

    c2_e_a = c2_iy;
    c2_c_c = c2_e_a;
    c2_f_a = c2_ix;
    c2_d_c = c2_f_a;
    c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
                                      (c2_c_c + 1)), 1, 65536, 1, 0) - 1] =
      c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)(c2_d_c + 1)), 1, 65536, 1, 0) - 1];
    c2_g_a = c2_ix + 1;
    c2_ix = c2_g_a;
    c2_i1 = c2_b_chanStart;
    c2_h_a = c2_i1 + 254;
    c2_i2 = c2_h_a;
    c2_b_i1 = c2_i1;
    c2_d_eml_int_forloop_overflow_check(chartInstance, c2_b_i1, c2_i2);
    for (c2_b_i = c2_b_i1; c2_b_i <= c2_i2; c2_b_i += 2) {
      c2_c_i = c2_b_i;
      c2_i_a = c2_c_i;
      c2_e_c = c2_i_a;
      c2_temp = c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)(c2_e_c + 2)), 1, 65536, 1, 0) - 1];
      c2_j_a = c2_c_i;
      c2_f_c = c2_j_a;
      c2_k_a = c2_c_i;
      c2_g_c = c2_k_a;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_f_c + 2)), 1, 65536, 1, 0) - 1].re =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_g_c + 1)), 1, 65536, 1, 0) - 1].re - c2_temp.re;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_f_c + 2)), 1, 65536, 1, 0) - 1].im =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_g_c + 1)), 1, 65536, 1, 0) - 1].im - c2_temp.im;
      c2_l_a = c2_c_i;
      c2_h_c = c2_l_a;
      c2_m_a = c2_c_i;
      c2_i_c = c2_m_a;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_h_c + 1)), 1, 65536, 1, 0) - 1].re =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_i_c + 1)), 1, 65536, 1, 0) - 1].re + c2_temp.re;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_h_c + 1)), 1, 65536, 1, 0) - 1].im =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_i_c + 1)), 1, 65536, 1, 0) - 1].im + c2_temp.im;
    }

    c2_iDelta = 2;
    c2_iDelta2 = 4;
    c2_k = 64;
    c2_iheight = 253;
    while ((real_T)c2_k > 0.0) {
      c2_istart = c2_b_chanStart;
      c2_c_i = c2_istart;
      c2_n_a = c2_c_i;
      c2_b_b = c2_iheight;
      c2_ihi = c2_n_a + c2_b_b;
      while (c2_c_i < c2_ihi) {
        c2_o_a = c2_c_i;
        c2_c_b = c2_iDelta;
        c2_j_c = c2_o_a + c2_c_b;
        c2_p_a = c2_j_c;
        c2_k_c = c2_p_a;
        c2_temp = c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c2_k_c + 1)), 1, 65536, 1, 0) - 1];
        c2_q_a = c2_c_i;
        c2_d_b = c2_iDelta;
        c2_l_c = c2_q_a + c2_d_b;
        c2_r_a = c2_l_c;
        c2_m_c = c2_r_a;
        c2_s_a = c2_c_i;
        c2_n_c = c2_s_a;
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_m_c + 1)), 1, 65536, 1, 0) - 1].re =
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_n_c + 1)), 1, 65536, 1, 0) - 1].re - c2_temp.re;
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_m_c + 1)), 1, 65536, 1, 0) - 1].im =
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_n_c + 1)), 1, 65536, 1, 0) - 1].im - c2_temp.im;
        c2_t_a = c2_c_i;
        c2_o_c = c2_t_a;
        c2_u_a = c2_c_i;
        c2_p_c = c2_u_a;
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_o_c + 1)), 1, 65536, 1, 0) - 1].re =
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_p_c + 1)), 1, 65536, 1, 0) - 1].re + c2_temp.re;
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_o_c + 1)), 1, 65536, 1, 0) - 1].im =
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_p_c + 1)), 1, 65536, 1, 0) - 1].im + c2_temp.im;
        c2_v_a = c2_c_i;
        c2_e_b = c2_iDelta2;
        c2_c_i = c2_v_a + c2_e_b;
      }

      c2_w_a = c2_istart;
      c2_istart = c2_w_a;
      c2_f_b = c2_k;
      for (c2_j = c2_f_b; c2_j < 128; c2_j = c2_kb_a + c2_k_b) {
        c2_x_a = c2_j;
        c2_q_c = c2_x_a;
        c2_y_a = c2_j;
        c2_r_c = c2_y_a;
        c2_twid.re = c2_dv6[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c2_q_c + 1)), 1, 129, 1, 0) - 1];
        c2_twid.im = c2_dv7[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c2_r_c + 1)), 1, 129, 1, 0) - 1];
        c2_c_i = c2_istart + 1;
        c2_ab_a = c2_c_i;
        c2_g_b = c2_iheight;
        c2_ihi = c2_ab_a + c2_g_b;
        while (c2_c_i < c2_ihi) {
          c2_bb_a = c2_c_i;
          c2_h_b = c2_iDelta;
          c2_s_c = c2_bb_a + c2_h_b;
          c2_cb_a = c2_s_c;
          c2_t_c = c2_cb_a;
          c2_temp = c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)(c2_t_c + 1)), 1, 65536, 1, 0) - 1];
          c2_b_temp = c2_temp;
          c2_temp.re = c2_twid.re * c2_b_temp.re - c2_twid.im * c2_b_temp.im;
          c2_temp.im = c2_twid.re * c2_b_temp.im + c2_twid.im * c2_b_temp.re;
          c2_db_a = c2_c_i;
          c2_i_b = c2_iDelta;
          c2_u_c = c2_db_a + c2_i_b;
          c2_eb_a = c2_u_c;
          c2_v_c = c2_eb_a;
          c2_fb_a = c2_c_i;
          c2_w_c = c2_fb_a;
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_v_c + 1)), 1, 65536, 1, 0) - 1].re =
            c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_w_c + 1)), 1, 65536, 1, 0) - 1].re - c2_temp.re;
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_v_c + 1)), 1, 65536, 1, 0) - 1].im =
            c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_w_c + 1)), 1, 65536, 1, 0) - 1].im - c2_temp.im;
          c2_gb_a = c2_c_i;
          c2_x_c = c2_gb_a;
          c2_hb_a = c2_c_i;
          c2_y_c = c2_hb_a;
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_x_c + 1)), 1, 65536, 1, 0) - 1].re =
            c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_y_c + 1)), 1, 65536, 1, 0) - 1].re + c2_temp.re;
          c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_x_c + 1)), 1, 65536, 1, 0) - 1].im =
            c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_y_c + 1)), 1, 65536, 1, 0) - 1].im + c2_temp.im;
          c2_ib_a = c2_c_i;
          c2_j_b = c2_iDelta2;
          c2_c_i = c2_ib_a + c2_j_b;
        }

        c2_jb_a = c2_istart + 1;
        c2_istart = c2_jb_a;
        c2_kb_a = c2_j;
        c2_k_b = c2_k;
      }

      c2_lb_a = c2_k;
      c2_i41 = c2_lb_a;
      c2_k = (c2_i41 + (c2_i41 < 0)) >> 1;
      c2_iDelta = c2_iDelta2;
      c2_mb_a = c2_iDelta;
      c2_iDelta2 = c2_mb_a << 1;
      c2_nb_a = c2_iheight;
      c2_l_b = c2_iDelta;
      c2_iheight = c2_nb_a - c2_l_b;
    }
  }
}

static void c2_eml_fftshift(SFc2_demo_20210521InstanceStruct *chartInstance,
  creal_T c2_x[65536], int32_T c2_dim, creal_T c2_b_x[65536])
{
  int32_T c2_i42;
  for (c2_i42 = 0; c2_i42 < 65536; c2_i42++) {
    c2_b_x[c2_i42] = c2_x[c2_i42];
  }

  c2_b_eml_fftshift(chartInstance, c2_b_x, c2_dim);
}

static void c2_e_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance, int32_T c2_b)
{
  int32_T c2_b_b;
  boolean_T c2_overflow;
  boolean_T c2_safe;
  int32_T c2_i43;
  static char_T c2_cv2[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i44;
  static char_T c2_cv3[5] = { 'i', 'n', 't', '3', '2' };

  char_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = FALSE;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  c2_safe = !c2_overflow;
  if (c2_safe) {
  } else {
    for (c2_i43 = 0; c2_i43 < 34; c2_i43++) {
      c2_u[c2_i43] = c2_cv2[c2_i43];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c2_i44 = 0; c2_i44 < 5; c2_i44++) {
      c2_b_u[c2_i44] = c2_cv3[c2_i44];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c2_y, 14, c2_b_y));
  }
}

static void c2_f_eml_int_forloop_overflow_check(SFc2_demo_20210521InstanceStruct
  *chartInstance, int32_T c2_a)
{
  boolean_T c2_overflow;
  boolean_T c2_safe;
  int32_T c2_i45;
  static char_T c2_cv4[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i46;
  static char_T c2_cv5[5] = { 'i', 'n', 't', '3', '2' };

  char_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  c2_overflow = FALSE;
  c2_safe = !c2_overflow;
  if (c2_safe) {
  } else {
    for (c2_i45 = 0; c2_i45 < 34; c2_i45++) {
      c2_u[c2_i45] = c2_cv4[c2_i45];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c2_i46 = 0; c2_i46 < 5; c2_i46++) {
      c2_b_u[c2_i46] = c2_cv5[c2_i46];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c2_y, 14, c2_b_y));
  }
}

static void c2_eml_error(SFc2_demo_20210521InstanceStruct *chartInstance)
{
  int32_T c2_i47;
  static char_T c2_varargin_1[29] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'l', 'o', 'g', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[29];
  const mxArray *c2_y = NULL;
  for (c2_i47 = 0; c2_i47 < 29; c2_i47++) {
    c2_u[c2_i47] = c2_varargin_1[c2_i47];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 29), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_demo_20210521InstanceStruct *chartInstance;
  chartInstance = (SFc2_demo_20210521InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i48;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i48, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i48;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_demo_20210521InstanceStruct *chartInstance;
  chartInstance = (SFc2_demo_20210521InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_demo_20210521, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_demo_20210521), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_demo_20210521);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_demo_20210521InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_eml_fftshift(SFc2_demo_20210521InstanceStruct *chartInstance,
  creal_T c2_x[65536], int32_T c2_dim)
{
  int32_T c2_i49;
  real_T c2_d1;
  real_T c2_vlen;
  real_T c2_a;
  real_T c2_d2;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_vlend2;
  int32_T c2_b_dim;
  int32_T c2_b_a;
  int32_T c2_n;
  int32_T c2_j;
  int32_T c2_vstride;
  int32_T c2_loop_ub;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_i52;
  real_T c2_d3;
  int32_T c2_c_a;
  real_T c2_b;
  real_T c2_d4;
  int32_T c2_i53;
  int32_T c2_c_dim;
  int32_T c2_d_a;
  int32_T c2_c;
  int32_T c2_i;
  int32_T c2_npages;
  int32_T c2_b_i;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_i54;
  real_T c2_d5;
  int32_T c2_e_a;
  real_T c2_b_b;
  real_T c2_d6;
  int32_T c2_i55;
  real_T c2_f_a;
  real_T c2_d7;
  int32_T c2_i56;
  int32_T c2_b_c;
  int32_T c2_g_a;
  int32_T c2_c_b;
  int32_T c2_vspread;
  int32_T c2_h_a;
  int32_T c2_d_b;
  int32_T c2_midoffset;
  int32_T c2_i_a;
  int32_T c2_c_c;
  int32_T c2_i2;
  int32_T c2_c_i;
  int32_T c2_i1;
  int32_T c2_j_a;
  int32_T c2_e_b;
  int32_T c2_b_j;
  int32_T c2_k_a;
  int32_T c2_l_a;
  int32_T c2_ia;
  int32_T c2_m_a;
  int32_T c2_f_b;
  int32_T c2_ib;
  int32_T c2_e_k;
  creal_T c2_xtmp;
  int32_T c2_n_a;
  int32_T c2_g_b;
  int32_T c2_o_a;
  int32_T c2_h_b;
  int32_T c2_d_i;
  int32_T c2_p_a;
  int32_T c2_i_b;
  int32_T c2_c_j;
  int32_T c2_q_a;
  int32_T c2_r_a;
  int32_T c2_s_a;
  int32_T c2_j_b;
  int32_T c2_f_k;
  int32_T c2_t_a;
  int32_T c2_k_b;
  int32_T c2_ic;
  int32_T c2_u_a;
  int32_T c2_l_b;
  if ((real_T)c2_dim > 2.0) {
  } else {
    c2_i49 = (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_dim);
    if (c2_i49 <= 2) {
      c2_d1 = 256.0;
    } else {
      c2_d1 = 1.0;
    }

    c2_vlen = c2_d1;
    if (c2_vlen <= 1.0) {
    } else {
      c2_a = c2_vlen;
      c2_d2 = muDoubleScalarRound(c2_a);
      if (c2_d2 < 2.147483648E+9) {
        if (c2_d2 >= -2.147483648E+9) {
          c2_i50 = (int32_T)c2_d2;
        } else {
          c2_i50 = MIN_int32_T;
        }
      } else if (c2_d2 >= 2.147483648E+9) {
        c2_i50 = MAX_int32_T;
      } else {
        c2_i50 = 0;
      }

      c2_i51 = c2_i50;
      c2_vlend2 = (c2_i51 + (c2_i51 < 0)) >> 1;
      c2_b_dim = c2_dim;
      if ((real_T)c2_b_dim <= 2.0) {
        c2_b_a = c2_b_dim;
        c2_n = c2_b_a;
      } else {
        c2_n = 3;
      }

      c2_j = c2_n - 1;
      c2_vstride = 1;
      c2_e_eml_int_forloop_overflow_check(chartInstance, c2_j);
      c2_loop_ub = c2_j;
      for (c2_k = 1; c2_k <= c2_loop_ub; c2_k++) {
        c2_b_k = c2_k;
        c2_i52 = (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k);
        if (c2_i52 <= 2) {
          c2_d3 = 256.0;
        } else {
          c2_d3 = 1.0;
        }

        c2_c_a = c2_vstride;
        c2_b = c2_d3;
        c2_d4 = muDoubleScalarRound(c2_b);
        if (c2_d4 < 2.147483648E+9) {
          if (c2_d4 >= -2.147483648E+9) {
            c2_i53 = (int32_T)c2_d4;
          } else {
            c2_i53 = MIN_int32_T;
          }
        } else if (c2_d4 >= 2.147483648E+9) {
          c2_i53 = MAX_int32_T;
        } else {
          c2_i53 = 0;
        }

        c2_vstride = c2_c_a * c2_i53;
      }

      c2_c_dim = c2_dim;
      c2_d_a = c2_c_dim;
      c2_c = c2_d_a;
      c2_i = c2_c + 1;
      c2_npages = 1;
      c2_b_i = c2_i;
      c2_f_eml_int_forloop_overflow_check(chartInstance, c2_b_i);
      for (c2_c_k = c2_b_i; c2_c_k < 3; c2_c_k++) {
        c2_d_k = c2_c_k;
        c2_i54 = (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_d_k);
        if (c2_i54 <= 2) {
          c2_d5 = 256.0;
        } else {
          c2_d5 = 1.0;
        }

        c2_e_a = c2_npages;
        c2_b_b = c2_d5;
        c2_d6 = muDoubleScalarRound(c2_b_b);
        if (c2_d6 < 2.147483648E+9) {
          if (c2_d6 >= -2.147483648E+9) {
            c2_i55 = (int32_T)c2_d6;
          } else {
            c2_i55 = MIN_int32_T;
          }
        } else if (c2_d6 >= 2.147483648E+9) {
          c2_i55 = MAX_int32_T;
        } else {
          c2_i55 = 0;
        }

        c2_npages = c2_e_a * c2_i55;
      }

      c2_f_a = c2_vlen;
      c2_d7 = muDoubleScalarRound(c2_f_a);
      if (c2_d7 < 2.147483648E+9) {
        if (c2_d7 >= -2.147483648E+9) {
          c2_i56 = (int32_T)c2_d7;
        } else {
          c2_i56 = MIN_int32_T;
        }
      } else if (c2_d7 >= 2.147483648E+9) {
        c2_i56 = MAX_int32_T;
      } else {
        c2_i56 = 0;
      }

      c2_b_c = c2_i56;
      c2_g_a = c2_b_c - 1;
      c2_c_b = c2_vstride;
      c2_vspread = c2_g_a * c2_c_b;
      c2_h_a = c2_vlend2;
      c2_d_b = c2_vstride;
      c2_midoffset = c2_h_a * c2_d_b;
      c2_i_a = c2_vlend2;
      c2_c_c = c2_i_a << 1;
      if ((real_T)c2_c_c == c2_vlen) {
        c2_i2 = 0;
        c2_e_eml_int_forloop_overflow_check(chartInstance, c2_npages);
        for (c2_c_i = 1; c2_c_i <= c2_npages; c2_c_i++) {
          c2_i1 = c2_i2;
          c2_j_a = c2_i2;
          c2_e_b = c2_vspread;
          c2_i2 = c2_j_a + c2_e_b;
          c2_e_eml_int_forloop_overflow_check(chartInstance, c2_vstride);
          for (c2_b_j = 1; c2_b_j <= c2_vstride; c2_b_j++) {
            c2_k_a = c2_i1 + 1;
            c2_i1 = c2_k_a;
            c2_l_a = c2_i2 + 1;
            c2_i2 = c2_l_a;
            c2_ia = c2_i1;
            c2_m_a = c2_i1;
            c2_f_b = c2_midoffset;
            c2_ib = c2_m_a + c2_f_b;
            c2_e_eml_int_forloop_overflow_check(chartInstance, c2_vlend2);
            for (c2_e_k = 1; c2_e_k <= c2_vlend2; c2_e_k++) {
              c2_xtmp = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c2_ia), 1, 65536, 1, 0) - 1];
              c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_ia), 1, 65536, 1, 0) - 1] =
                c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_ib), 1, 65536, 1, 0) - 1];
              c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_ib), 1, 65536, 1, 0) - 1] = c2_xtmp;
              c2_n_a = c2_ia;
              c2_g_b = c2_vstride;
              c2_ia = c2_n_a + c2_g_b;
              c2_o_a = c2_ib;
              c2_h_b = c2_vstride;
              c2_ib = c2_o_a + c2_h_b;
            }
          }
        }
      } else {
        c2_i2 = 0;
        c2_e_eml_int_forloop_overflow_check(chartInstance, c2_npages);
        for (c2_d_i = 1; c2_d_i <= c2_npages; c2_d_i++) {
          c2_i1 = c2_i2;
          c2_p_a = c2_i2;
          c2_i_b = c2_vspread;
          c2_i2 = c2_p_a + c2_i_b;
          c2_e_eml_int_forloop_overflow_check(chartInstance, c2_vstride);
          for (c2_c_j = 1; c2_c_j <= c2_vstride; c2_c_j++) {
            c2_q_a = c2_i1 + 1;
            c2_i1 = c2_q_a;
            c2_r_a = c2_i2 + 1;
            c2_i2 = c2_r_a;
            c2_ia = c2_i1;
            c2_s_a = c2_i1;
            c2_j_b = c2_midoffset;
            c2_ib = c2_s_a + c2_j_b;
            c2_xtmp = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c2_ib), 1, 65536, 1, 0) - 1];
            c2_e_eml_int_forloop_overflow_check(chartInstance, c2_vlend2);
            for (c2_f_k = 1; c2_f_k <= c2_vlend2; c2_f_k++) {
              c2_t_a = c2_ib;
              c2_k_b = c2_vstride;
              c2_ic = c2_t_a + c2_k_b;
              c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_ib), 1, 65536, 1, 0) - 1] =
                c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_ia), 1, 65536, 1, 0) - 1];
              c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_ia), 1, 65536, 1, 0) - 1] =
                c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_ic), 1, 65536, 1, 0) - 1];
              c2_u_a = c2_ia;
              c2_l_b = c2_vstride;
              c2_ia = c2_u_a + c2_l_b;
              c2_ib = c2_ic;
            }

            c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_ib), 1, 65536, 1, 0) - 1] = c2_xtmp;
          }
        }
      }
    }
  }
}

static void init_dsm_address_info(SFc2_demo_20210521InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_demo_20210521_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1808457114U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2680815946U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(868795968U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1822123274U);
}

mxArray *sf_c2_demo_20210521_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("QKZuReyucYB1Qxw4kdj5GE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(256);
      pr[1] = (double)(256);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(256);
      pr[1] = (double)(256);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_demo_20210521(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"out\",},{M[8],M[0],T\"is_active_c2_demo_20210521\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_demo_20210521_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_demo_20210521InstanceStruct *chartInstance;
    chartInstance = (SFc2_demo_20210521InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_demo_20210521MachineNumber_,
           2,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_demo_20210521MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_demo_20210521MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_demo_20210521MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"c");
          _SFD_SET_DATA_PROPS(1,2,0,1,"out");
          _SFD_SET_DATA_PROPS(2,1,1,0,"image");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,80);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c2_c;
          real_T (*c2_out)[65536];
          real32_T (*c2_image)[65536];
          c2_image = (real32_T (*)[65536])ssGetInputPortSignal(chartInstance->S,
            1);
          c2_out = (real_T (*)[65536])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_c);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_out);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_image);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_demo_20210521MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "U9CLzexW0Reagb6pcY6UoE";
}

static void sf_opaque_initialize_c2_demo_20210521(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_demo_20210521InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_demo_20210521((SFc2_demo_20210521InstanceStruct*)
    chartInstanceVar);
  initialize_c2_demo_20210521((SFc2_demo_20210521InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_demo_20210521(void *chartInstanceVar)
{
  enable_c2_demo_20210521((SFc2_demo_20210521InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_demo_20210521(void *chartInstanceVar)
{
  disable_c2_demo_20210521((SFc2_demo_20210521InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_demo_20210521(void *chartInstanceVar)
{
  sf_c2_demo_20210521((SFc2_demo_20210521InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_demo_20210521(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_demo_20210521
    ((SFc2_demo_20210521InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_demo_20210521();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_demo_20210521(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_demo_20210521();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_demo_20210521((SFc2_demo_20210521InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_demo_20210521(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_demo_20210521(S);
}

static void sf_opaque_set_sim_state_c2_demo_20210521(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_demo_20210521(S, st);
}

static void sf_opaque_terminate_c2_demo_20210521(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_demo_20210521InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_demo_20210521((SFc2_demo_20210521InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_demo_20210521_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_demo_20210521((SFc2_demo_20210521InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_demo_20210521(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_demo_20210521((SFc2_demo_20210521InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_demo_20210521(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_demo_20210521_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2750200856U));
  ssSetChecksum1(S,(3436619358U));
  ssSetChecksum2(S,(1086846925U));
  ssSetChecksum3(S,(1692322509U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_demo_20210521(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_demo_20210521(SimStruct *S)
{
  SFc2_demo_20210521InstanceStruct *chartInstance;
  chartInstance = (SFc2_demo_20210521InstanceStruct *)malloc(sizeof
    (SFc2_demo_20210521InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_demo_20210521InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_demo_20210521;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_demo_20210521;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_demo_20210521;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_demo_20210521;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_demo_20210521;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_demo_20210521;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_demo_20210521;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_demo_20210521;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_demo_20210521;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_demo_20210521;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_demo_20210521;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_demo_20210521_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_demo_20210521(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_demo_20210521(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_demo_20210521(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_demo_20210521_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
