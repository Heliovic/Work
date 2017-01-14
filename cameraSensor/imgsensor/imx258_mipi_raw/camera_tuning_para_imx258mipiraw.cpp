//wanfei@wind-mobi.com 20161229 begin
#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>

#include "camera_custom_nvram.h"
#include "camera_custom_sensor.h"
#include "image_sensor.h"
#include "kd_imgsensor_define.h"
#include "camera_AE_PLineTable_imx258mipiraw.h"
#include "camera_info_imx258mipiraw.h"
#include "camera_custom_AEPlinetable.h"
#include "camera_custom_tsf_tbl.h"


const NVRAM_CAMERA_ISP_PARAM_STRUCT CAMERA_ISP_DEFAULT_VALUE =
{{
    //Version
    Version: NVRAM_CAMERA_PARA_FILE_VERSION,

    //SensorId
    SensorId: SENSOR_ID,
    ISPComm:{
      {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1819238756, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      }
    },
    ISPPca: {
#include INCLUDE_FILENAME_ISP_PCA_PARAM
    },
    ISPRegs:{
#include INCLUDE_FILENAME_ISP_REGS_PARAM
    },
    ISPMfbMixer:{{
      0x00000000, // MIX3_CTRL_0
      0x00000000, // MIX3_CTRL_1
      0x00000000  // MIX3_SPARE
    }},
    ISPMulitCCM:{
      Poly22:{
        89375,      // i4R_AVG
        21258,      // i4R_STD
        98525,      // i4B_AVG
        24341,      // i4B_STD
        0,      // i4R_MAX
        0,      // i4R_MIN
        0,      // i4G_MAX
        0,      // i4G_MIN
        0,      // i4B_MAX
        0,      // i4B_MIN
                { // i4P00[9]
            10237500, -4740000, -372500, -1522500, 7177500, -537500, -100000, -4060000, 9290000
                },
                { // i4P10[9]
            4074605, -4178915, 124768, -975995, 231408, 716890, 17762, 2131721, -2149483
                },
                { // i4P01[9]
            3197983, -3275362, 100923, -1346905, 325962, 997284, -212622, 1246447, -1033825
                },
                { // i4P20[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
                },
                { // i4P11[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
                },
                { // i4P02[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
                }

      },
      AWBGain:{
        // Strobe
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // A
        {
          955,    // i4R
            512,    // i4G
          1010    // i4B
        },
        // TL84
        {
          875,    // i4R
            512,    // i4G
          1016    // i4B
        },
        // CWF
        {
          617,    // i4R
          512,    // i4G
          1253    // i4B
        },
        // D65
        {
          1128,    // i4R
          512,    // i4G
          662    // i4B
        },
        // Reserved 1
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 2
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 3
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        }
      },
      Weight:{
        0, // Strobe
        0, // A
        0, // TL84
        0, // CWF
        0, // D65
        0, // Reserved 1
        0, // Reserved 2
        0  // Reserved 3
      }
    },
    
          MDPMulitCCM:{
                Poly22:{
        0,      // i4R_AVG
        0,      // i4R_STD
        0,      // i4B_AVG
        0,      // i4B_STD
        0,      // i4R_MAX
        0,      // i4R_MIN
        0,      // i4G_MAX
        0,      // i4G_MIN
        0,      // i4B_MAX
        0,      // i4B_MIN
                  {  // i4P00[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
                  },
                  {  // i4P10[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
                  },
                  {  // i4P01[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
                  },
                  {  // i4P20[9]
                      0, 0, 0, 0, 0, 0, 0, 0, 0
                          },
                          { // i4P11[9]
                      0, 0, 0, 0, 0, 0, 0, 0, 0
                          },
                          { // i4P02[9]
                      0, 0, 0, 0, 0, 0, 0, 0, 0
                          }
          
                },
                AWBGain:{
                  // Strobe
                  {
          0,    // i4R
          0,    // i4G
          0    // i4B
                  },
                  // A
                  {
          955,    // i4R
                      512,    // i4G
          1010    // i4B
                  },
                  // TL84
                  {
          875,    // i4R
                      512,    // i4G
          1015    // i4B
                  },
                  // CWF
                  {
          617,    // i4R
                      512,    // i4G
          1253    // i4B
                  },
                  // D65
                  {
          1127,    // i4R
                      512,    // i4G
          662    // i4B
                  },
                  // Reserved 1
                  {
          0,    // i4R
          0,    // i4G
          0    // i4B
                  },
                  // Reserved 2
                  {
          0,    // i4R
          0,    // i4G
          0    // i4B
                  },
                  // Reserved 3
                  {
          0,    // i4R
          0,    // i4G
          0    // i4B
                  }
                },
                Weight:{
        0, // Strobe
        0, // A
        0, // TL84
        0, // CWF
        0, // D65
        0, // Reserved 1
        0, // Reserved 2
        0  // Reserved 3
                }
              },
    isp_ccm_ratio: 0.000000,
    //bInvokeSmoothCCM
    bInvokeSmoothCCM: MTRUE,
    DngMetadata:
    {
        0,  //i4RefereceIlluminant1
        3,  //i4RefereceIlluminant2
        {
            // rNoiseProfile[4]
            {
                {3.530980e-6, 3.357493e-4},
                {8.098436e-8, -2.336529e-4},
            },
            {
                {3.530980e-6, 3.357493e-4},
                {8.098436e-8, -2.336529e-4},
            },
            {
                {3.530980e-6, 3.357493e-4},
                {8.098436e-8, -2.336529e-4},
            },
            {
                {3.530980e-6, 3.357493e-4},
                {8.098436e-8, -2.336529e-4},
            },
        },
    },
    ANR_TBL:
    {0}
}};

const NVRAM_CAMERA_3A_STRUCT CAMERA_3A_NVRAM_DEFAULT_VALUE =
{
    NVRAM_CAMERA_3A_FILE_VERSION, // u4Version
    SENSOR_ID, // SensorId

    // AE NVRAM
    {
        // rDevicesInfo
        {
            1144,    // u4MinGain, 1024 base = 1x
            16384,    // u4MaxGain, 16x
            100,    // u4MiniISOGain, ISOxx  
            128,    // u4GainStepUnit, 1x/8
            20649,    // u4PreExpUnit 
            30,     // u4PreMaxFrameRate
            10325,    // u4VideoExpUnit  
            30,     // u4VideoMaxFrameRate
            1024,   // u4Video2PreRatio, 1024 base = 1x
            10325,    // u4CapExpUnit 
            30,    // u4CapMaxFrameRate
            1024,   // u4Cap2PreRatio, 1024 base = 1x
            10325,    // u4Video1ExpUnit
            119,    // u4Video1MaxFrameRate
            1024,   // u4Video12PreRatio, 1024 base = 1x
            20649,    // u4Video2ExpUnit
            30,     // u4Video2MaxFrameRate
            1024,   // u4Video22PreRatio, 1024 base = 1x
            20649,    // u4Custom1ExpUnit
            30,     // u4Custom1MaxFrameRate
            1024,   // u4Custom12PreRatio, 1024 base = 1x
            20649,    // u4Custom2ExpUnit
            30,     // u4Custom2MaxFrameRate
            1024,   // u4Custom22PreRatio, 1024 base = 1x
            20649,    // u4Custom3ExpUnit
            30,     // u4Custom3MaxFrameRate
            1024,   // u4Custom32PreRatio, 1024 base = 1x
            20649,    // u4Custom4ExpUnit
            30,     // u4Custom4MaxFrameRate
            1024,   // u4Custom42PreRatio, 1024 base = 1x
            20649,    // u4Custom5ExpUnit
            30,     // u4Custom5MaxFrameRate
            1024,   // u4Custom52PreRatio, 1024 base = 1x
            20,      // u4LensFno, Fno = 2.8
            350     // u4FocusLength_100x
        },
        // rHistConfig
        {
            4, // 2,   // u4HistHighThres
            40,  // u4HistLowThres
            2,   // u4MostBrightRatio
            1,   // u4MostDarkRatio
            160, // u4CentralHighBound
            20,  // u4CentralLowBound
            {240, 230, 220, 210, 200}, // u4OverExpThres[AE_CCT_STRENGTH_NUM]
            {62, 70, 82, 108, 141},  // u4HistStretchThres[AE_CCT_STRENGTH_NUM]
            {18, 22, 26, 30, 34}       // u4BlackLightThres[AE_CCT_STRENGTH_NUM]
        },
        // rCCTConfig
        {
            TRUE,            // bEnableBlackLight
            TRUE,            // bEnableHistStretch
            TRUE,           // bEnableAntiOverExposure
            TRUE,            // bEnableTimeLPF
            TRUE,    // bEnableCaptureThres//TRUE
            TRUE,            // bEnableVideoThres
            TRUE,            // bEnableVideo1Thres
            TRUE,            // bEnableVideo2Thres
            TRUE,            // bEnableCustom1Thres
            TRUE,            // bEnableCustom2Thres
            TRUE,            // bEnableCustom3Thres
            TRUE,            // bEnableCustom4Thres
            TRUE,            // bEnableCustom5Thres
            TRUE,            // bEnableStrobeThres
            53,    // u4AETarget
            47,    // u4StrobeAETarget
            50,                // u4InitIndex
            4,                 // u4BackLightWeight
            32,                // u4HistStretchWeight
            4,                 // u4AntiOverExpWeight
            2,                 // u4BlackLightStrengthIndex
            2,                 // u4HistStretchStrengthIndex
            2,                 // u4AntiOverExpStrengthIndex
            2,                 // u4TimeLPFStrengthIndex
            {1, 3, 5, 7, 8}, // u4LPFConvergeTable[AE_CCT_STRENGTH_NUM]
            90,                // u4InDoorEV = 9.0, 10 base
            -17,    // i4BVOffset delta BV = value/10 
            64,                 // u4PreviewFlareOffset
            64,    // u4CaptureFlareOffset
            3,                 // u4CaptureFlareThres
            64,                 // u4VideoFlareOffset
            3,                 // u4VideoFlareThres
            64,               // u4CustomFlareOffset
            3,                 //  u4CustomFlareThres
            64,                 // u4StrobeFlareOffset //12 bits
            3,                 // u4StrobeFlareThres // 0.5%
            160,                 // u4PrvMaxFlareThres //12 bit
            2,                 // u4PrvMinFlareThres
            160,                 // u4VideoMaxFlareThres // 12 bit
            2,                 // u4VideoMinFlareThres
            18,                // u4FlatnessThres              // 10 base for flatness condition.
            75,    // u4FlatnessStrength
            //rMeteringSpec
            {
                //rHS_Spec
                {
                    TRUE,//bEnableHistStretch           // enable histogram stretch
                    1024,//u4HistStretchWeight          // Histogram weighting value
                    40,//u4Pcent                      // 
                    126,//u4Thd                        // 0~255  146 wanfei20161222
                    64, //74,//u4FlatThd                    // 0~255

                    120,//u4FlatBrightPcent
                    120,//u4FlatDarkPcent
                    //sFlatRatio
                    {
                        1000,  //i4X1
                        1024,  //i4Y1
                        2600,  //i4X2
                        0     //i4Y2
                    },
                    FALSE, //bEnableGreyTextEnhance
                    1800, //u4GreyTextFlatStart, > sFlatRatio.i4X1, < sFlatRatio.i4X2
                    {
                        10,     //i4X1
                        1024,   //i4Y1
                        80,     //i4X2
                        0       //i4Y2
                    }
                },
                //rAOE_Spec
                {
                    TRUE, //bEnableAntiOverExposure
                    1024, //u4AntiOverExpWeight
                    10,    //u4Pcent
                    240, //u4Thd
                    FALSE, //bEnableCOEP
                    1,    //u4COEPcent
                    160, //u4COEThd//150
                    0,  // u4BVCompRatio
                    //sCOEYRatio;     // the outer y ratio
                    {
                        23,   //i4X1
                        1024,  //i4Y1
                        47,   //i4X2
                        0     //i4Y2
                    },
                    //sCOEDiffRatio;  // inner/outer y difference ratio
                    {
                        1500, //i4X1
                        0,    //i4Y1
                        2100, //i4X2
                        1024   //i4Y2
                    }
                },
                //rABL_Spec
                {
                    TRUE,//bEnableBlackLigh
                    1024,//u4BackLightWeigh
                    400,//u4Pcent
                    22,//u4Thd,
                    255, // center luminance
                    242, // final target limitation, 256/128 = 2x
                    //sFgBgEVRatio
                    {
                        2200, //i4X1
                        0,    //i4Y1
                        4000, //i4X2
                        1024   //i4Y2
                    },
                    //sBVRatio
                    {
                        3800,//i4X1
                        0,   //i4Y1
                        5000,//i4X2
                        1024  //i4Y2
                    }
                },
                //rNS_Spec
                {
                    TRUE, // bEnableNightScene
                    5,    //u4Pcent
                    160,//u4Thd
                    62,//u4FlatThd

                    150,//u4BrightTonePcent
                    60,//u4BrightToneThd//68

                    500,  //u4LowBndPcent
                    5,    //u4LowBndThd
                    40,//u4LowBndThdLimit

                    50,  //u4FlatBrightPcent;
                    300,   //u4FlatDarkPcent;
                    //sFlatRatio
                    {
                        1200, //i4X1
                        1024, //i4Y1
                        2400, //i4X2
                        0    //i4Y2
                    },
                    //sBVRatio
                    {
                        -500, //i4X1
                        1024,  //i4Y1
                        3000,  //i4X2
                        0     //i4Y2
                    },
                    TRUE, // bEnableNightSkySuppresion
                    //sSkyBVRatio
                    {
                        -4000, //i4X1
                        1024, //i4X2
                        -2000,  //i4Y1
                        0     //i4Y2
                    }
                },
                // rTOUCHFD_Spec
                {
                    35, //uMeteringYLowBound;
                    45, //uMeteringYHighBound;
                    35, //uFaceYLowBound;
                    45, //uFaceYHighBound;
                    3,  //uFaceCentralWeight;
                    120,//u4MeteringStableMax;
                    80, //u4MeteringStableMin;
                }
            }, //End rMeteringSpec
            // rFlareSpec
            {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //uPrvFlareWeightArr[16];
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //uVideoFlareWeightArr[16];
                96,                                               //u4FlareStdThrHigh;
                48,                                               //u4FlareStdThrLow;
                0,                                                //u4PrvCapFlareDiff;
                4,                                                //u4FlareMaxStepGap_Fast;
                0,                                                //u4FlareMaxStepGap_Slow;
                1800,                                             //u4FlarMaxStepGapLimitBV;
                1,                                               //u4FlareAEStableCount;
            },
            //rAEMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                190, //u4Bright2TargetEnd
                10, //u4Dark2TargetStart
                100, //u4B2TEnd
                100, //u4B2TStart
                100, //u4D2TEnd
                100, //u4D2TStart
            },

            //rAEVideoMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40, //u4B2TStart
                30, //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEVideo1MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40, //u4B2TStart
                30, //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEVideo2MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40, //u4B2TStart
                30, //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom1MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40, //u4B2TStart
                30, //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom2MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40, //u4B2TStart
                30, //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom3MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40, //u4B2TStart
                30, //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom4MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40, //u4B2TStart
                30, //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom5MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40, //u4B2TStart
                30, //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEFaceMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                190,  //u4Bright2TargetEnd
                10,    //u4Dark2TargetStart
                80, //u4B2TEnd
                30,  //u4B2TStart
                20,  //u4D2TEnd
                60,  //u4D2TStart
            },

            //rAETrackingMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                190,  //u4Bright2TargetEnd
                10,    //u4Dark2TargetStart
                80, //u4B2TEnd
                30,  //u4B2TStart
                20,  //u4D2TEnd
                60,  //u4D2TStart
            },
            //rAEAOENVRAMParam =
            {
                1,      // i4AOEStrengthIdx: 0 / 1 / 2
                128,      // u4BVCompRatio
                {
                    {
                        47,  //u4Y_Target
                        10,  //u4AOE_OE_percent
                        160,  //u4AOE_OEBound
                        15,  //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                        5,  //u4AOE_LowlightBound
                        100,  //u4AOESceneLV_L
                        150,  //u4AOESceneLV_H
                        40,    //u4AOE_SWHdrLE_Bound
                    },
                    {
                        47,  //u4Y_Target
                        10,  //u4AOE_OE_percent
                        180,  //u4AOE_OEBound
                        20,  //u4AOE_OE_percent
                        950,    //u4AOE_LowlightPrecent
                        10,  //u4AOE_LowlightBound
                        100,  //u4AOESceneLV_L
                        150,  //u4AOESceneLV_H
                        40,    //u4AOE_SWHdrLE_Bound
                    },
                    {
                        47,  //u4Y_Target
                        10,  //u4AOE_OE_percent
                        200,  //u4AOE_OEBound
                        25,    //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                        15,  //u4AOE_LowlightBound
                        100,  //u4AOESceneLV_L
                        150,  //u4AOESceneLV_H
                        40,    //u4AOE_SWHdrLE_Bound
                    }
                }
            }
        }
    },

        // AWB NVRAM
    AWB_NVRAM_START
    {
        {
        {
                // AWB calibration data
                {
                        // rUnitGain (unit gain: 1.0 = 512)
                        {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                        },
                        // rGoldenGain (golden sample gain: 1.0 = 512)
                        {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                        },
                            // rUnitGain TL84 (unit gain: 1.0 = 512)
                            {
                                0,    // i4R
                                0,    // i4G
                                0     // i4B
                            },
                            // rGoldenGain TL84 (golden sample gain: 1.0 = 512)
                            {
                                0,    // i4R
                                0,    // i4G
                                0     // i4B
                            },
                             // rUnitGain Alight (unit gain: 1.0 = 512)
                            {
                                0,    // i4R
                                0,    // i4G
                                0     // i4B
                            },
                            // rGoldenGain Alight (golden sample gain: 1.0 = 512)
                            {
                                0,    // i4R
                                0,    // i4G
                                0     // i4B
                            },
                        // rTuningUnitGain (Tuning sample unit gain: 1.0 = 512)
                        {
                                0,    // i4R
                                0,    // i4G
                                0    // i4B
                        },
                        // rD65Gain (D65 WB gain: 1.0 = 512)
                        {
                    1158,    // D65Gain_R
                                512,    // i4G
                    643    // D65Gain_B
                        }
                },
                // Original XY coordinate of AWB light source
                {
                        // Strobe
                        {
                    218,    // i4X
                    -385    // i4Y
                        },
                        // Horizon
                        {
                    -385,    // OriX_Hor
                    -428    // OriY_Hor
                        },
                        // A
                        {
                    -244,    // OriX_A
                    -426    // OriY_A
                        },
                        // TL84
                        {
                    -61,    // OriX_TL84
                    -438    // OriY_TL84
                        },
                        // CWF
                        {
                    -26,    // OriX_CWF
                    -471    // OriY_CWF
                        },
                        // DNP
                        {
                    58,    // OriX_DNP
                    -416    // OriY_DNP
                        },
                        // D65
                        {
                    217,    // OriX_D65
                    -385    // OriY_D65
                        },
                        // DF
                        {
                    99,    // OriX_DF
                    -456    // OriY_DF
                        }
                },
                // Rotated XY coordinate of AWB light source
                {
                        // Strobe
                {
                    184,    // i4X
                    -402    // i4Y
                },
                // Horizon
                {
                    -420,    // RotX_Hor
                    -393    // RotY_Hor
                },
                // A
                {
                    -280,    // RotX_A
                    -403    // RotY_A
                },
                // TL84
                {
                    -98,    // RotX_TL84
                    -431    // RotY_TL84
                },
                // CWF
                {
                    -66,    // RotX_CWF
                    -467    // RotY_CWF
                },
                // DNP
                {
                    22,    // RotX_DNP
                    -419    // RotY_DNP
                },
                // D65
                {
                    183,    // RotX_D65
                    -402    // RotY_D65
                },
                // DF
                {
                    59,    // RotX_DF
                    -463    // RotY_DF
                }
            },
            // AWB gain of AWB light source
            {
                // Strobe 
                {
                    1159,    // i4R
                    512,    // i4G
                    642    // i4B
                },
                // Horizon 
                {
                    542,    // AWBGAIN_HOR_R
                    512,    // AWBGAIN_HOR_G
                    1539    // AWBGAIN_HOR_B
                },
                // A 
                {
                    655,    // AWBGAIN_A_R
                    512,    // AWBGAIN_A_G
                    1269    // AWBGAIN_A_B
                },
                // TL84 
                {
                    853,    // AWBGAIN_TL84_R
                    512,    // AWBGAIN_TL84_G
                    1006    // AWBGAIN_TL84_B
                },
                // CWF 
                {
                    935,    // AWBGAIN_CWF_R
                    512,    // AWBGAIN_CWF_G
                    1003    // AWBGAIN_CWF_B
                        },
                        // DNP
                        {
                    973,    // AWBGAIN_DNP_R
                                512,    // i4G
                    832    // AWBGAIN_DNP_B
                        },
                        // D65
                        {
                    1158,    // AWBGAIN_D65_R
                                512,    // i4G
                    643    // AWBGAIN_D65_B
                        },
                        // DF
                        {
                    1085,    // AWBGAIN_DF_R
                                512,    // i4G
                    830    // AWBGAIN_DF_B
                        }
                },
                // Rotation matrix parameter
            {
                5,    // RotationAngle
                255,    // Cos
                22    // Sin
            },
            // Daylight locus parameter
            {
                -153,    // i4SlopeNumerator
                128    // i4SlopeDenominator
            },
            // Predictor gain
            {
                101, // i4PrefRatio100
                // DaylightLocus_L
                {
                    1128,    // i4R
                    530,    // i4G
                    663    // i4B
                },
                // DaylightLocus_H
                {
                    844,    // i4R
                    512,    // i4G
                    930    // i4B
                },
                // Temporal General
                {
                    1158,    // i4R
                    512,    // i4G
                    643    // i4B
                },
                // AWB LSC Gain
                {
                    922,        // i4R
                    512,        // i4G
                    842        // i4B
                }
            },
            // AWB light area
            {
                // Strobe:FIXME
                        {
                    234,    // i4RightBound
                    134,    // i4LeftBound
                    -352,    // i4UpperBound
                    -452    // i4LowerBound
                },
                // Tungsten
                {
                    -187,    // TungRightBound
                    -820,    // TungLeftBound
                    -308,    // TungUpperBound
                    -377    // TungLowerBound
                },
                // Warm fluorescent
                {
                    -187,    // WFluoRightBound
                    -820,    // WFluoLeftBound
                    -377,    // WFluoUpperBound
                    -557    // WFluoLowerBound
                },
                // Fluorescent
                {
                    -17,    // FluoRightBound
                    -187,    // FluoLeftBound
                    -342,    // FluoUpperBound
                    -449    // FluoLowerBound
                },
                // CWF
                {
                -11,    // CWFRightBound
                -187,    // CWFLeftBound
                -449,    // CWFUpperBound
                -552    // CWFLowerBound
                },
                // Daylight
                {
                    180,    // DayRightBound
                    -17,    // DayLeftBound
                    -332,    // DayUpperBound
                    -449    // DayLowerBound
                },
                // Shade
                {
                    543,    // ShadeRightBound
                    180,    // ShadeLeftBound
                    -332,    // ShadeUpperBound
                    -428    // ShadeLowerBound
                },
                // Daylight Fluorescent
                {
                    190,    // DFRightBound
                    -11,    // DFLeftBound
                    -449,    // DFUpperBound
                    -542    // DFLowerBound
                }
            },
            // PWB light area
            {
                // Reference area
                {
                    543,    // PRefRightBound
                    -820,    // PRefLeftBound
                    -308,    // PRefUpperBound
                    -557    // PRefLowerBound
                },
                // Daylight
                {
                    205,    // PDayRightBound
                    -17,    // PDayLeftBound
                    -332,    // PDayUpperBound
                    -449    // PDayLowerBound
                },
                // Cloudy daylight
                {
                    305,    // PCloudyRightBound
                    130,    // PCloudyLeftBound
                    -332,    // PCloudyUpperBound
                    -449    // PCloudyLowerBound
                },
                // Shade
                {
                    405,    // PShadeRightBound
                    130,    // PShadeLeftBound
                    -332,    // PShadeUpperBound
                    -449    // PShadeLowerBound
                },
                // Twilight
                {
                    -17,    // PTwiRightBound
                    -177,    // PTwiLeftBound
                    -332,    // PTwiUpperBound
                    -449    // PTwiLowerBound
                },
                // Fluorescent
                {
                    233,    // PFluoRightBound
                    -198,    // PFluoLeftBound
                    -352,    // PFluoUpperBound
                    -517    // PFluoLowerBound
                },
                // Warm fluorescent
                {
                    -180,    // PWFluoRightBound
                    -380,    // PWFluoLeftBound
                    -352,    // PWFluoUpperBound
                    -517    // PWFluoLowerBound
                },
                // Incandescent
                {
                    -180,    // PIncaRightBound
                    -380,    // PIncaLeftBound
                    -332,    // PIncaUpperBound
                    -449    // PIncaLowerBound
                },
                // Gray World
                {
                    5000,    // PGWRightBound
                    -5000,    // PGWLeftBound
                    5000,    // PGWUpperBound
                    -5000    // PGWLowerBound
                }
            },
            // PWB default gain	
            {
                // Daylight
                {
                    1019,    // PWB_Day_R
                    512,    // PWB_Day_G
                    722    // PWB_Day_B
                },
                // Cloudy daylight
                {
                    1186,    // PWB_Cloudy_R
                    512,    // PWB_Cloudy_G
                    602    // PWB_Cloudy_B
                },
                // Shade
                {
                    1262,    // PWB_Shade_R
                    512,    // PWB_Shade_G
                    560    // PWB_Shade_B
                },
                // Twilight
                {
                    805,    // PWB_Twi_R
                    512,    // PWB_Twi_G
                    955    // PWB_Twi_B
                },
                // Fluorescent
                {
                    989,    // PWB_Fluo_R
                    512,    // PWB_Fluo_G
                    853    // PWB_Fluo_B
                },
                // Warm fluorescent
                {
                    685,    // PWB_WFluo_R
                    512,    // PWB_WFluo_G
                    1319    // PWB_WFluo_B
                },
                // Incandescent
                {
                    643,    // PWB_Inca_R
                    512,    // PWB_Inca_G
                    1249    // PWB_Inca_B
                },
                // Gray World
                {
                    512,    // PWB_GW_R
                    512,    // PWB_GW_G
                    512    // PWB_GW_B
                }
            },
            // AWB preference color	
            {
                // Tungsten
                {
                    40,    // TUNG_SLIDER
                    4500    // TUNG_OFFS
                },
                // Warm fluorescent	
                {
                    40,    // WFluo_SLIDER
                    5043    // WFluo_OFFS
                },
                // Shade
                {
                    50,    // Shade_SLIDER
                    410    // Shade_OFFS
                },
                // Sunset Area
                {
                    52,   // i4Sunset_BoundXr_Thr
                    -419    // i4Sunset_BoundYr_Thr
                },
                // Shade F Area
                {
                    -171,   // i4BoundXrThr
                    -435    // i4BoundYrThr
                },
                // Shade F Vertex
                {
                    -94,   // i4BoundXrThr
                    -442    // i4BoundYrThr
                },
                // Shade CWF Area
                {
                    -187,   // i4BoundXrThr
                    -495    // i4BoundYrThr
                },
                // Shade CWF Vertex
                {
                    -91,   // i4BoundXrThr
                    -497    // i4BoundYrThr
                },
            },
            // CCT estimation
            {
                // CCT
                {
                    2300,    // i4CCT[0]
                    2850,    // i4CCT[1]
                    3750,    // i4CCT[2]
                    5100,    // i4CCT[3]
                    6500     // i4CCT[4]
                },
                // Rotated X coordinate
                {
                -603,    // i4RotatedXCoordinate[0]
                -463,    // i4RotatedXCoordinate[1]
                -281,    // i4RotatedXCoordinate[2]
                -161,    // i4RotatedXCoordinate[3]
                0    // i4RotatedXCoordinate[4]
                }
	            }
            },

                // Algorithm Tuning Paramter
                {
                    // AWB Backup Enable
                    0,

                     // Daylight locus offset LUTs for tungsten
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                    {0, 350,  800, 1222, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778,  5000} // i4LUTOut
                    //{0, 500, 1000, 1333, 1667, 2000, 2333, 2667, 3000, 3333, 3667, 4000, 4333, 4667, 5000, 5333, 5667, 6000, 6333, 6667,  7000} // i4LUTOut
                    //{0, 500, 1000, 1500, 2000, 2313, 2625, 2938, 3250, 3563, 3875, 4188, 4500, 4813, 5125, 5438, 5750, 6063, 6375, 6688,  7000} // i4LUTOut
                },

                // Daylight locus offset LUTs for WF
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 700, 1000, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
                },

                // Daylight locus offset LUTs for shade
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000} // i4LUTOut
                },
                // Preference gain for each light source
                {
                    //        LV0              LV1              LV2              LV3              LV4              LV5              LV6              LV7              LV8              LV9
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                    //        LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17             LV18
          	            {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // STROBE
                {
                    {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // TUNGSTEN
                {
                    {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {506, 512, 496}, {500, 512, 525}, {500, 512, 525}, 
                    {500, 512, 525}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // WARM F
                {
                    {512, 512, 496}, {512, 512, 496}, {512, 512, 496}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {480, 512, 512}, {480, 512, 512}, {480, 512, 512}, {480, 512, 512}, {480, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // F
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 517}, {480, 512, 517}, 
                    {480, 512, 517}, {480, 512, 512}, {480, 512, 512}, {480, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // CWF
                {
                    {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {495, 512, 512}, 
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}
                }, // DAYLIGHT
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}
                    }, // SHADE
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                    } // DAYLIGHT F
                },
                    // Parent block weight parameter
                    {
                        1,      // bEnable
                        6           // i4ScalingFactor: [6] 1~12, [7] 1~6, [8] 1~3, [9] 1~2, [>=10]: 1
                    },
                    // AWB LV threshold for predictor
                    {
                115,    // i4InitLVThr_L
                155,    // i4InitLVThr_H
                100      // i4EnqueueLVThr
                    },
                    // AWB number threshold for temporal predictor
                    {
                            65,     // i4Neutral_ParentBlk_Thr
                        //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   2,   2,   2,   2,   2,   2,   2}  // (%) i4CWFDF_LUTThr
                    },
                    // AWB light neutral noise reduction for outdoor
                    {
                        //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                        // Non neutral
                    {   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // Flurescent
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // CWF
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // Daylight
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   2,   2,   2,   2,   2,   2,   2},  // (%)
                    // DF
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    },
                    // AWB feature detection
                    {
                        // Sunset Prop
                        {
                            1,          // i4Enable
                        120,        // i4LVThr_L
                        130,        // i4LVThr_H
                            10,         // i4SunsetCountThr
                            0,          // i4SunsetCountRatio_L
                            171         // i4SunsetCountRatio_H
                        },

                        // Shade F Detection
                        {
                            1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                            128         // i4DaylightProb
                        },

                        // Shade CWF Detection
                        {
                            1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                        150         // i4DaylightProb
                    },
                    },

                    // AWB non-neutral probability for spatial and temporal weighting look-up table (Max: 100; Min: 0)
                    {
                        //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    {   0,  33,  66, 100, 100, 100, 100, 100, 100, 100, 100,  70,  30,  20,  10,   0,   0,   0,   0}
                    },

                {   //LV0    1     2     3      4     5     6     7     8      9      10     11    12   13     14    15   16    17    18
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   0,   0,   0,   0}, // Strobe
                    {  80,  80,  80,  80, 100, 100, 100,  80,  80,  80, 100, 100, 100,  75,  50,  25,   0,   0,   0}, // Tungsten
                    {  80,  80,  80,  80,  80, 100,  80,  80,  80,  80, 100,  75,  50,  25,  25,  25,   0,   0,   0}, // Warm fluorescent
                    {  80,  80,  80,  80,  65,  65,  65, 100, 100, 100,  95,  75,  50,  25,  25,  25,   0,   0,   0}, // Fluorescent
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0}, // CWF
                    {  80,  80,  80,  80, 100, 100, 100, 100, 100, 100,  75,  75,  75,  75,  75,  50,  40,  30,  20}, // Daylight
                    {  85,  85,  85,  85, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0,   0}, // Shade
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0} // Daylight fluorescent
                },

                // AWB tuning information
                {
                    0,		// project code
                    0,		// model
                    0,		// date
                    0,		// reserved 0
                    0,		// reserved 1
                    0,		// reserved 2
                    0,		// reserved 3
                    0,          // reserved 0 
                }
            }
                
        },
                {
                {
                       // AWB calibration data
                {
                        // rUnitGain (unit gain: 1.0 = 512)
                        {
                                0,    // i4R
                                0,    // i4G
                                0    // i4B
                        },
                        // rGoldenGain (golden sample gain: 1.0 = 512)
                        {
                                0,    // i4R
                                0,    // i4G
                                0    // i4B
                        },
                            // rUnitGain TL84 (unit gain: 1.0 = 512)
                            {
                                0,    // i4R
                                0,    // i4G
                                0     // i4B
                            },
                            // rGoldenGain TL84 (golden sample gain: 1.0 = 512)
                            {
                                0,    // i4R
                                0,    // i4G
                                0     // i4B
                            },
                             // rUnitGain Alight (unit gain: 1.0 = 512)
                            {
                                0,    // i4R
                                0,    // i4G
                                0     // i4B
                            },
                            // rGoldenGain Alight (golden sample gain: 1.0 = 512)
                            {
                                0,    // i4R
                                0,    // i4G
                                0     // i4B
                            },
                        // rTuningUnitGain (Tuning sample unit gain: 1.0 = 512)
                        {
                                0,    // i4R
                                0,    // i4G
                                0    // i4B
                        },
                        // rD65Gain (D65 WB gain: 1.0 = 512)
                        {
                                1095,    // i4R
                                512,    // i4G
                                736    // i4B
                        }
                },
                // Original XY coordinate of AWB light source
                {
                        // Strobe
                        {
                                0,    // i4X
                                0    // i4Y
                        },
                        // Horizon
                        {
		-425,	// i4X
		-449	// i4Y	
                        },
                        // A
                        {
			-278,	// i4X	
			-462	    // i4Y	
                        },
                        // TL84
                        {
			-78,	// i4X		
			-493	// i4Y		
                        },
                        // CWF
                        {
			-37,	// i4X	
			-530	// i4Y	
                        },
                        // DNP
                        {
			23,	// i4X		
			-487	// i4Y		
                        },
                        // D65
                        {
			188,	// i4X			
			-442	// i4Y			
                        },
                        // DF
                        {
			168,    // i4X
			-527	// i4Y	
                        }
                },
                // Rotated XY coordinate of AWB light source
                {
                        // Strobe
                        {
                                0,    // i4X
                                0    // i4Y
                        },
                        // Horizon
                        {
			-441,	// i4X				                  
			-434	// i4Y				                  
                        },
                        // A
                        {
			-294,	// i4X				                    
			-452	// i4Y				                    
                        },
                        // TL84
                        {
			-95,	// i4X				                
			-490	// i4Y				                
                        },
                        // CWF
                        {
			-56,	// i4X				                  
			-529	// i4Y				                  
                        },
                        // DNP
                        {
			6,	// i4X				                  
			-488	// i4Y				                  
                        },
                        // D65
                        {
			172,	// i4X				                    
			-449	// i4Y				                  
                        },
                        // DF
                        {
			149,	// i4X				                    
			-533	// i4Y				                      
                        }
                },
                // AWB gain of AWB light source
                {
                        // Strobe
                        {
                                512,    // i4R
                                512,    // i4G
                                512    // i4B
                        },
                        // Horizon
                        {
			529,	// i4R				            
                                512,    // i4G
			1671	// i4B				            
                        },
                        // A
                        {
			656,	// i4R				              
                                512,    // i4G
			1394	// i4B				              
                        },
                        // TL84
                        {
			898,	// i4R				            
                                512,    // i4G
			1109	// i4B				            
                        },
                        // CWF
                        {
			998,	// i4R				            
                                512,    // i4G
			1103	// i4B				            
                        },
                        // DNP
                        {
			1022,	// i4R				            
                                512,    // i4G
			959	// i4B				              
                        },
                        // D65
                        {
			1202,	// i4R				            
                                512,    // i4G
			722	// i4B				              
                        },
                        // DF
                        {
			1312,	// i4R				              
                                512,    // i4G
			833	// i4B				                
                        }
                },
                // Rotation matrix parameter
                {
		2,	// i4RotationAngle					              
                        256,    // i4Cos
		9	// i4Sin					                        
                },
                // Daylight locus parameter
                {
		-138,	// i4SlopeNumerator		
                        128    // i4SlopeDenominator
                },
	            // Predictor gain
                {
                        // i4PrefRatio100
                        101,

                        // DaylightLocus_L
                        {
                            1233,    // i4R
                            512, // i4G
                            703     // i4B
                        },
                        // DaylightLocus_H
                        {
                    899,    // i4R
                            512, // i4G
                    986    // i4B
                        },
                        // Temporal General
                        {
                            1233,    // i4R
                            512, // i4G
                            703     // i4B
                        },
                        // AWB LSC Gain
                        {
                            938,    // i4R
                            512, // i4G
                            943     // i4B
                        }
                },
                // AWB light area
                {
                        // Strobe
                        {
			0,	// StrobeRightBound				            
			0,	// StrobeLeftBound				          
			0,	// StrobeUpperBound				          
			0	// StrobeLowerBound				          
                        },
                        // Tungsten
                        {
			-195,	// TungRightBound				            
			-841,	// TungLeftBound				            
			-399,	// TungUpperBound				            
			-471	// TungLowerBound				            
                        },
                        // Warm fluorescent
                        {
			-195,	// WFluoRightBound				          
			-841,	// WFluoLeftBound				            
			-471,	// WFluoUpperBound				          
			-529	// WFluoLowerBound				          
                        },
                        // Fluorescent
                        {
			-19,	// FluoRightBound				            
			-195,	// FluoLeftBound				            
			-417,	// FluoUpperBound				            
			-514	// FluoLowerBound				            
                        },
                        // CWF
                        {
			26,	// CWFRightBound				            
			-170,	// CWFLeftBound				              
			-514,	// CWFUpperBound				            
			-574	// CWFLowerBound				            
                        },
                        // Daylight
                        {
			202,	// DayRightBound				              
			-19,	// DayLeftBound				              
			-417,	// DayUpperBound				            
			-514	// DayLowerBound				            
                        },
                        // Shade
                        {
			532,	// ShadeRightBound				          
			202,	// ShadeLeftBound				              
			-417,	// ShadeUpperBound				          
			-481	// ShadeLowerBound				          
                        },
                        // Daylight Fluorescent
                        {
			202,	// DFRightBound				                
			26,	// DFLeftBound				                
			-514,	// DFUpperBound				                
			-574	// DFLowerBound				                  
                        }
                },
                // PWB light area
                {
                        // Reference area
                        {
			532,	// PRefRightBound				            
			-841,	// PRefLeftBound				            
			-374,	// PRefUpperBound				            
			-574	// PRefLowerBound				            
                        },
                        // Daylight
                        {
			227,	// PDayRightBound				            
			-19,	// PDayLeftBound				            
			-417,	// PDayUpperBound				            
			-514	// PDayLowerBound				            
                        },
                        // Cloudy daylight
                        {
			327,	// PCloudyRightBound				        
			152,	// PCloudyLeftBound				            
			-417,	// PCloudyUpperBound				        
			-514	// PCloudyLowerBound				        
                        },
                        // Shade
                        {
			427,	// PShadeRightBound				          
			152,	// PShadeLeftBound				          
			-417,	// PShadeUpperBound				          
			-514	// PShadeLowerBound				          
                        },
                        // Twilight
                        {
			-19,	// PTwiRightBound				            
			-179,	// PTwiLeftBound				            
			-417,	// PTwiUpperBound				            
			-514	// PTwiLowerBound				            
                        },
                        // Fluorescent
                        {
			222,	// PFluoRightBound				          
			-195,	// PFluoLeftBound				            
			-399,	// PFluoUpperBound				          
			-579	// PFluoLowerBound				          
                        },
                        // Warm fluorescent
                        {
			-194,	// PWFluoRightBound				          
			-394,	// PWFluoLeftBound				          
			-399,	// PWFluoUpperBound				          
			-579	// PWFluoLowerBound				          
                        },
                        // Incandescent
                        {
			-194,	// PIncaRightBound				          
			-394,	// PIncaLeftBound				            
			-417,	// PIncaUpperBound				          
			-514	// PIncaLowerBound				          
                        },
                        // Gray World
                        {
			5000,	// PGWRightBound				            
			-5000,	// PGWLeftBound				            
			5000,	// PGWUpperBound				            
			-5000	// PGWLowerBound				            
                        }
                },
                // PWB default gain
                {
                        // Daylight
                        {
			1125,	// PWB_Day_R				                
			512,	// PWB_Day_G				                
			812	// PWB_Day_B				                  
                        },
                        // Cloudy daylight
                        {
			1343,	// PWB_Cloudy_R				              
			512,	// PWB_Cloudy_G				              
			672	// PWB_Cloudy_B				                
                        },
                        // Shade
                        {
			1433,	// PWB_Shade_R				              
			512,	// PWB_Shade_G				              
			627	// PWB_Shade_B				                
                        },
                        // Twilight
                        {
			863,	// PWB_Twi_R				                
			512,	// PWB_Twi_G				                
			1079	// PWB_Twi_B				                
                        },
                        // Fluorescent
                        {
			1033,	// PWB_Fluo_R				                
			512,	// PWB_Fluo_G				                
			951	// PWB_Fluo_B				                  
                        },
                        // Warm fluorescent
                        {
			692,	// PWB_WFluo_R				              
			512,	// PWB_WFluo_G				              
			1462	// PWB_WFluo_B				              
                        },
                        // Incandescent
                        {
			669,	// PWB_Inca_R				                
			512,	// PWB_Inca_G				                
			1418	// PWB_Inca_B				                
                        },
                        // Gray World
                        {
			512,	// PWB_GW_R				                  
			512,	// PWB_GW_G				                  
			512	// PWB_GW_B				                    
                        }
                },
                // AWB preference color
                {
                        // Tungsten
                        {
			100,	// TUNG_SLIDER				                
			4004	// TUNG_OFFS				                
                        },
                        // Warm fluorescent
                        {
			100,	// WFluo_SLIDER				                
			4004	// WFluo_OFFS				                
                        },
                        // Shade
                        {
			50,	// Shade_SLIDER				                
			909	// Shade_OFFS				                  
                        },
            // Sunset Area
                                {
                                19,   // i4Sunset_BoundXr_Thr
                                -488     // i4Sunset_BoundYr_Thr
                            },
                                // Shade F Area
                                {
                                -70,   // i4BoundXrThr
                                -449    // i4BoundYrThr
                            },
                                // Shade F Vertex
                                {
                                -70,   // i4BoundXrThr
                                -449    // i4BoundYrThr
                            },
                                // Shade CWF Area
                                {
                                -56,   // i4BoundXrThr
                                -529    // i4BoundYrThr
                            },
                                // Shade CWF Vertex
                                {
                                -56,   // i4BoundXrThr
                                -529    // i4BoundYrThr
                            }
                },
// CCT estimation
                {
                        // CCT
                        {
			                2300,	// i4CCT[0]
			                2850,	// i4CCT[1]
			                3750,	// i4CCT[2]
			                5100,	// i4CCT[3]
			                6500 	// i4CCT[4]
		            },
					{						                                
			                -547,	// i4RotatedXCoordinate[0]
			                -423,	// i4RotatedXCoordinate[1]
			                -271,	// i4RotatedXCoordinate[2]
			                -104,	// i4RotatedXCoordinate[3]
			                0 	    // i4RotatedXCoordinate[4]
		            }
	            }
            },

                // Algorithm Tuning Paramter
                {
                    // AWB Backup Enable
                    0,

                     // Daylight locus offset LUTs for tungsten
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                    {0, 350,  800, 1222, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778,  5000} // i4LUTOut
                    //{0, 500, 1000, 1333, 1667, 2000, 2333, 2667, 3000, 3333, 3667, 4000, 4333, 4667, 5000, 5333, 5667, 6000, 6333, 6667,  7000} // i4LUTOut
                    //{0, 500, 1000, 1500, 2000, 2313, 2625, 2938, 3250, 3563, 3875, 4188, 4500, 4813, 5125, 5438, 5750, 6063, 6375, 6688,  7000} // i4LUTOut
                },

                // Daylight locus offset LUTs for WF
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                    {0, 350,  700,  850, 1200, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778,  5000} // i4LUTOut
                },

                // Daylight locus offset LUTs for shade
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                    {0, 500, 1000, 1500, 2500, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8000, 8000, 8500, 9000, 9500, 10000}  // i4LUTOut
                },
                // Preference gain for each light source
                {
                    //        LV0              LV1              LV2              LV3              LV4              LV5              LV6              LV7              LV8              LV9
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                    //        LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17             LV18
          	            {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
        	        }, // STROBE
        	        {
          	            {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {520, 520, 496}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
           	            {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
        	        }, // TUNGSTEN
        	        {
                        {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508},
           	            {512, 512, 508}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
        	        }, // WARM F
        	        {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}
                    }, // F
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                    }, // CWF
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}
                    }, // DAYLIGHT
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                    }, // SHADE
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                    } // DAYLIGHT F
                },
                    // Parent block weight parameter
                    {
                        1,      // bEnable
                        6           // i4ScalingFactor: [6] 1~12, [7] 1~6, [8] 1~3, [9] 1~2, [>=10]: 1
                    },
                    // AWB LV threshold for predictor
                    {
				   115, //100,	  // i4InitLVThr_L
				   155, //140,	  // i4InitLVThr_H
				   100 //80 	 // i4EnqueueLVThr
                    },
                    // AWB number threshold for temporal predictor
                    {
                            65,     // i4Neutral_ParentBlk_Thr
                        //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
				   { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,	50,  25,   2,	2,	 2,   2,   2,	2,	 2}  // (%) i4CWFDF_LUTThr
                    },
                    // AWB light neutral noise reduction for outdoor
                    {
                        //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                        // Non neutral
				   { 3,   3,   3,	3,	 3,   3,   3,	3,	  3,   3,	5,	10,  10,  10,  10,	10,  10,  10,  10},  // (%)
		                // Flurescent
				   { 0,   0,   0,	0,	 0,   0,   0,	0,	  0,   0,	5,	10,  10,  10,  10,	10,  10,  10,  10},  // (%)
		                // CWF
				   { 0,   0,   0,	0,	 0,   0,   0,	0,	  0,   0,	5,	10,  10,  10,  10,	10,  10,  10,  10},  // (%)
		                // Daylight
				   { 0,   0,   0,	0,	 0,   0,   0,	0,	  0,   0,	0,	 2,   2,   2,	2,	 2,   2,   2,	2},  // (%)
		                // DF
				   { 0,   0,   0,	0,	 0,   0,   0,	0,	  0,   0,	5,	10,  10,  10,  10,	10,  10,  10,  10},  // (%)
                    },
                    // AWB feature detection
                    {
                        // Sunset Prop
                        {
                            1,          // i4Enable
                            120,        // i4LVThr_L
                        	130,        // i4LVThr_H                            
                            10,         // i4SunsetCountThr
                            0,          // i4SunsetCountRatio_L
                            171         // i4SunsetCountRatio_H
                        },

                        // Shade F Detection
                        {
                            1,          // i4Enable
                            90,        // i4LVThr
                        	105,        // i4LVThr                            
					   96 //10		   // i4DaylightProb
                        },

                        // Shade CWF Detection
                        {
                            1,          // i4Enable
                            90,        // i4LVThr
                        	105,        // i4LVThr                            
					   208 //224 //128 //35 		// i4DaylightProb
                        }
                    },

                    // AWB non-neutral probability for spatial and temporal weighting look-up table (Max: 100; Min: 0)
                    {
                        //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
				   {  90, 90,  90,	90,  90,  90,  90,	90,  90,  90,	90,  50,  30,  20,	10,   0,   0,	0,	 0}
                    },

                    // AWB daylight locus probability look-up table (Max: 100; Min: 0)
                    {   //LV0    1     2     3      4     5     6     7     8      9      10     11    12   13     14    15   16    17    18
				   //LV0  1    2	3	 4	  5    6	7	 8	  9 	10	  11   12	13	 14   15  16   17	18
				   {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100, 100,	50,  25,   0,  0,	0,	 0}, // Strobe
				   {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,   75,  50,	25,  25,  25,  0,	0,	 0}, // Tungsten
				   {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,   75,  50,	25,  25,  25,  0,	0,	 0}, // Warm fluorescent
				   {100, 100, 100, 100, 100, 100, 100, 100, 100,  95,	95,   70,  50,	25,  25,  25,  0,	0,	 0}, // Fluorescent
				   { 90,  90,  90,	90,  90,  90,  90,	90,  90,  90,	80,   55,  30,	30,  30,  30,  0,	0,	 0}, // CWF
				   {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100, 100, 100,  75,  50, 40,  30,	20}, // Daylight
				   {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100,  75,	50,  25,   0,  0,	0,	 0}, // Shade
				   { 90,  90,  90,	90,  90,  90,  90,	90,  90,  90,	80,   55,  30,	30,  30,  30,  0,	0,	 0}  // Daylight fluorescent
                },

                // AWB tuning information
                {
                    6735,       // project code
                    5588,       // model   
                    20150624,   // date
                    0,          // reserved 0 
                    1,          // reserved 1  
                    2,          // reserved 2  
                    3,          // reserved 3 
                    4,          // reserved 4
                }
            }
        }
        },



    // Flash AWB NVRAM
    {
#include INCLUDE_FILENAME_FLASH_AWB_PARA
    },

    {0}
};

#include INCLUDE_FILENAME_ISP_LSC_PARAM
//};  //  namespace

const CAMERA_TSF_TBL_STRUCT CAMERA_TSF_DEFAULT_VALUE =
{
    {
        1,  // isTsfEn
        2,  // tsfCtIdx
        {20, 2000, -110, -110, 512, 512, 512, 0}    // rAWBInput[8]
    },

#include INCLUDE_FILENAME_TSF_PARA
#include INCLUDE_FILENAME_TSF_DATA
};

const NVRAM_CAMERA_FEATURE_STRUCT CAMERA_FEATURE_DEFAULT_VALUE =
{
#include INCLUDE_FILENAME_FEATURE_PARA
};

typedef NSFeature::RAWSensorInfo<SENSOR_ID> SensorInfoSingleton_T;


namespace NSFeature {
  template <>
  UINT32
  SensorInfoSingleton_T::
  impGetDefaultData(CAMERA_DATA_TYPE_ENUM const CameraDataType, VOID*const pDataBuf, UINT32 const size) const
  {
    UINT32 dataSize[CAMERA_DATA_TYPE_NUM] = {sizeof(NVRAM_CAMERA_ISP_PARAM_STRUCT),
        sizeof(NVRAM_CAMERA_3A_STRUCT),
        sizeof(NVRAM_CAMERA_SHADING_STRUCT),
        sizeof(NVRAM_LENS_PARA_STRUCT),
        sizeof(AE_PLINETABLE_T),
        0,
        sizeof(CAMERA_TSF_TBL_STRUCT),
        0,
        sizeof(NVRAM_CAMERA_FEATURE_STRUCT)
    };

    if (CameraDataType > CAMERA_NVRAM_DATA_FEATURE || NULL == pDataBuf || (size < dataSize[CameraDataType]))
    {
      return 1;
    }

    switch(CameraDataType)
    {
      case CAMERA_NVRAM_DATA_ISP:
        memcpy(pDataBuf,&CAMERA_ISP_DEFAULT_VALUE,sizeof(NVRAM_CAMERA_ISP_PARAM_STRUCT));
        break;
      case CAMERA_NVRAM_DATA_3A:
        memcpy(pDataBuf,&CAMERA_3A_NVRAM_DEFAULT_VALUE,sizeof(NVRAM_CAMERA_3A_STRUCT));
        break;
      case CAMERA_NVRAM_DATA_SHADING:
        memcpy(pDataBuf,&CAMERA_SHADING_DEFAULT_VALUE,sizeof(NVRAM_CAMERA_SHADING_STRUCT));
        break;
      case CAMERA_DATA_AE_PLINETABLE:
        memcpy(pDataBuf,&g_PlineTableMapping,sizeof(AE_PLINETABLE_T));
        break;
      case CAMERA_DATA_TSF_TABLE:
        memcpy(pDataBuf,&CAMERA_TSF_DEFAULT_VALUE,sizeof(CAMERA_TSF_TBL_STRUCT));
        break;
      case CAMERA_NVRAM_DATA_FEATURE:
        memcpy(pDataBuf,&CAMERA_FEATURE_DEFAULT_VALUE,sizeof(NVRAM_CAMERA_FEATURE_STRUCT));
        break;
      default:
        break;
    }
    return 0;
  }};  //  NSFeature


// zhaozhensen@wind-mobi.com 20161012 end