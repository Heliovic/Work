//wanfei@wind-mobi.com 20161205 begin
/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/

// Flash AWB tuning parameter
{
    9,  //foreground percentage
    95, //background percentage
     2, //FgPercentage_Th1
     5, //FgPercentage_Th2
    10, //FgPercentage_Th3
    15, //FgPercentage_Th4
   250, //FgPercentage_Th1_Val
   250, //FgPercentage_Th2_Val
   250, //FgPercentage_Th3_Val
   250, //FgPercentage_Th4_Val
    10, //location_map_th1
    20, //location_map_th2
    40, //location_map_th3
    50, //location_map_th4
   100, //location_map_val1
   100, //location_map_val2
   100, //location_map_val3
   100, //location_map_val4
     0, //SelfTuningFbBgWeightTbl
    100, //FgBgTbl_Y0
    100, //FgBgTbl_Y1
    100, //FgBgTbl_Y2
    100, //FgBgTbl_Y3
    100, //FgBgTbl_Y4
    100, //FgBgTbl_Y5
      5, //YPrimeWeightTh[0]
      9, //YPrimeWeightTh[1]
		 11, //YPrimeWeightTh[2]
		 13, //YPrimeWeightTh[3]
		 15, //YPrimeWeightTh[4]
			1, //YPrimeWeight[0]
			3, //YPrimeWeight[1]
			5, //YPrimeWeight[2]
			7, //YPrimeWeight[3]
	// FlashPreferenceGain
	{
		512,	// FlashPreferenceGain.i4R
		512,	// FlashPreferenceGain.i4G
		512	  // FlashPreferenceGain.i4B
	},
},

// Flash AWB calibration
{{
    { 512, 512, 512},  //duty=-1, dutyLt=-1  
   {1031, 512, 888},  //duty=0, dutyLt=-1  
   {1028, 512, 879},  //duty=1, dutyLt=-1  
   {1022, 512, 866},  //duty=2, dutyLt=-1  
   {1020, 512, 856},  //duty=3, dutyLt=-1  
   {1018, 512, 847},  //duty=4, dutyLt=-1  
   {1017, 512, 838},  //duty=5, dutyLt=-1  
   {1016, 512, 831},  //duty=6, dutyLt=-1  
   {1015, 512, 824},  //duty=7, dutyLt=-1  
   {1014, 512, 817},  //duty=8, dutyLt=-1  
   {1014, 512, 811},  //duty=9, dutyLt=-1  
   {1013, 512, 805},  //duty=10, dutyLt=-1  
   {1013, 512, 800},  //duty=11, dutyLt=-1  
   {1013, 512, 794},  //duty=12, dutyLt=-1  
   {1013, 512, 791},  //duty=13, dutyLt=-1  
   {1014, 512, 786},  //duty=14, dutyLt=-1  
   {1012, 512, 786},  //duty=15, dutyLt=-1  
   { 515, 512,2112},  //duty=-1, dutyLt=0  
   { 887, 512, 987},  //duty=0, dutyLt=0  
   { 911, 512, 948},  //duty=1, dutyLt=0  
   { 936, 512, 918},  //duty=2, dutyLt=0  
   { 950, 512, 897},  //duty=3, dutyLt=0  
   { 958, 512, 881},  //duty=4, dutyLt=0  
   { 964, 512, 868},  //duty=5, dutyLt=0  
   { 968, 512, 857},  //duty=6, dutyLt=0  
   { 971, 512, 848},  //duty=7, dutyLt=0  
   { 974, 512, 839},  //duty=8, dutyLt=0  
   { 976, 512, 833},  //duty=9, dutyLt=0  
   { 977, 512, 825},  //duty=10, dutyLt=0  
   { 979, 512, 819},  //duty=11, dutyLt=0  
   { 980, 512, 813},  //duty=12, dutyLt=0  
   { 981, 512, 808},  //duty=13, dutyLt=0  
   { 982, 512, 805},  //duty=14, dutyLt=0  
   { 984, 512, 798},  //duty=15, dutyLt=0  
   { 515, 512,2128},  //duty=-1, dutyLt=1  
   { 829, 512,1042},  //duty=0, dutyLt=1  
   { 861, 512, 991},  //duty=1, dutyLt=1  
   { 894, 512, 948},  //duty=2, dutyLt=1  
   { 914, 512, 923},  //duty=3, dutyLt=1  
   { 927, 512, 903},  //duty=4, dutyLt=1  
   { 936, 512, 888},  //duty=5, dutyLt=1  
   { 942, 512, 875},  //duty=6, dutyLt=1  
   { 947, 512, 864},  //duty=7, dutyLt=1  
   { 951, 512, 855},  //duty=8, dutyLt=1  
   { 954, 512, 845},  //duty=9, dutyLt=1  
   { 957, 512, 838},  //duty=10, dutyLt=1  
   { 959, 512, 831},  //duty=11, dutyLt=1  
   { 961, 512, 826},  //duty=12, dutyLt=1  
   { 963, 512, 819},  //duty=13, dutyLt=1  
   { 964, 512, 813},  //duty=14, dutyLt=1  
   { 966, 512, 808},  //duty=15, dutyLt=1  
   { 516, 512,2106},  //duty=-1, dutyLt=2  
   { 789, 512,1089},  //duty=0, dutyLt=2  
   { 824, 512,1027},  //duty=1, dutyLt=2  
   { 862, 512, 977},  //duty=2, dutyLt=2  
   { 885, 512, 945},  //duty=3, dutyLt=2  
   { 900, 512, 922},  //duty=4, dutyLt=2  
   { 911, 512, 903},  //duty=5, dutyLt=2  
   { 919, 512, 889},  //duty=6, dutyLt=2  
   { 926, 512, 878},  //duty=7, dutyLt=2  
   { 931, 512, 866},  //duty=8, dutyLt=2  
   { 935, 512, 857},  //duty=9, dutyLt=2  
   { 939, 512, 850},  //duty=10, dutyLt=2  
   { 942, 512, 842},  //duty=11, dutyLt=2  
   { 944, 512, 835},  //duty=12, dutyLt=2  
   { 947, 512, 830},  //duty=13, dutyLt=2  
   { 948, 512, 823},  //duty=14, dutyLt=2  
   { 951, 512, 817},  //duty=15, dutyLt=2  
   { 516, 512,2109},  //duty=-1, dutyLt=3  
   { 755, 512,1126},  //duty=0, dutyLt=3  
   { 795, 512,1061},  //duty=1, dutyLt=3  
   { 836, 512,1002},  //duty=2, dutyLt=3  
   { 861, 512, 966},  //duty=3, dutyLt=3  
   { 878, 512, 940},  //duty=4, dutyLt=3  
   { 890, 512, 920},  //duty=5, dutyLt=3  
   { 900, 512, 905},  //duty=6, dutyLt=3  
   { 907, 512, 891},  //duty=7, dutyLt=3  
   { 914, 512, 879},  //duty=8, dutyLt=3  
   { 919, 512, 869},  //duty=9, dutyLt=3  
   { 923, 512, 860},  //duty=10, dutyLt=3  
   { 926, 512, 849},  //duty=11, dutyLt=3  
   { 929, 512, 844},  //duty=12, dutyLt=3  
   { 932, 512, 839},  //duty=13, dutyLt=3  
   { 934, 512, 832},  //duty=14, dutyLt=3  
   { 935, 512, 826},  //duty=15, dutyLt=3  
   { 516, 512,2111},  //duty=-1, dutyLt=4  
   { 732, 512,1163},  //duty=0, dutyLt=4  
   { 772, 512,1091},  //duty=1, dutyLt=4  
   { 813, 512,1026},  //duty=2, dutyLt=4  
   { 840, 512, 985},  //duty=3, dutyLt=4  
   { 859, 512, 958},  //duty=4, dutyLt=4  
   { 872, 512, 936},  //duty=5, dutyLt=4  
   { 883, 512, 918},  //duty=6, dutyLt=4  
   { 891, 512, 903},  //duty=7, dutyLt=4  
   { 898, 512, 890},  //duty=8, dutyLt=4  
   { 902, 512, 875},  //duty=9, dutyLt=4  
   { 907, 512, 866},  //duty=10, dutyLt=4  
   { 912, 512, 861},  //duty=11, dutyLt=4  
   { 916, 512, 854},  //duty=12, dutyLt=4  
   { 918, 512, 847},  //duty=13, dutyLt=4  
   { 921, 512, 841},  //duty=14, dutyLt=4  
   { 923, 512, 833},  //duty=15, dutyLt=4  
   { 515, 512,2107},  //duty=-1, dutyLt=5  
   { 713, 512,1196},  //duty=0, dutyLt=5  
   { 753, 512,1115},  //duty=1, dutyLt=5  
   { 795, 512,1047},  //duty=2, dutyLt=5  
   { 822, 512,1004},  //duty=3, dutyLt=5  
   { 841, 512, 973},  //duty=4, dutyLt=5  
   { 856, 512, 950},  //duty=5, dutyLt=5  
   { 867, 512, 931},  //duty=6, dutyLt=5  
   { 876, 512, 915},  //duty=7, dutyLt=5  
   { 884, 512, 901},  //duty=8, dutyLt=5  
   { 891, 512, 891},  //duty=9, dutyLt=5  
   { 895, 512, 880},  //duty=10, dutyLt=5  
   { 900, 512, 872},  //duty=11, dutyLt=5  
   { 903, 512, 862},  //duty=12, dutyLt=5  
   { 907, 512, 856},  //duty=13, dutyLt=5  
   { 909, 512, 848},  //duty=14, dutyLt=5  
   { 909, 512, 840},  //duty=15, dutyLt=5  
   { 516, 512,2104},  //duty=-1, dutyLt=6  
   { 697, 512,1225},  //duty=0, dutyLt=6  
   { 736, 512,1143},  //duty=1, dutyLt=6  
   { 778, 512,1068},  //duty=2, dutyLt=6  
   { 806, 512,1020},  //duty=3, dutyLt=6  
   { 826, 512, 988},  //duty=4, dutyLt=6  
   { 842, 512, 964},  //duty=5, dutyLt=6  
   { 854, 512, 943},  //duty=6, dutyLt=6  
   { 863, 512, 926},  //duty=7, dutyLt=6  
   { 872, 512, 912},  //duty=8, dutyLt=6  
   { 877, 512, 899},  //duty=9, dutyLt=6  
   { 883, 512, 889},  //duty=10, dutyLt=6  
   { 888, 512, 880},  //duty=11, dutyLt=6  
   { 892, 512, 872},  //duty=12, dutyLt=6  
   { 895, 512, 863},  //duty=13, dutyLt=6  
   { 895, 512, 854},  //duty=14, dutyLt=6  
   { 895, 512, 845},  //duty=15, dutyLt=6  
   { 516, 512,2101},  //duty=-1, dutyLt=7  
   { 685, 512,1252},  //duty=0, dutyLt=7  
   { 723, 512,1167},  //duty=1, dutyLt=7  
   { 764, 512,1087},  //duty=2, dutyLt=7  
   { 792, 512,1037},  //duty=3, dutyLt=7  
   { 813, 512,1002},  //duty=4, dutyLt=7  
   { 828, 512, 975},  //duty=5, dutyLt=7  
   { 841, 512, 955},  //duty=6, dutyLt=7  
   { 851, 512, 937},  //duty=7, dutyLt=7  
   { 861, 512, 923},  //duty=8, dutyLt=7  
   { 866, 512, 909},  //duty=9, dutyLt=7  
   { 873, 512, 899},  //duty=10, dutyLt=7  
   { 877, 512, 888},  //duty=11, dutyLt=7  
   { 881, 512, 879},  //duty=12, dutyLt=7  
   { 885, 512, 871},  //duty=13, dutyLt=7  
   { 885, 512, 861},  //duty=14, dutyLt=7  
   { 879, 512, 847},  //duty=15, dutyLt=7  
   { 516, 512,2097},  //duty=-1, dutyLt=8  
   { 674, 512,1277},  //duty=0, dutyLt=8  
   { 711, 512,1189},  //duty=1, dutyLt=8  
   { 752, 512,1105},  //duty=2, dutyLt=8  
   { 783, 512,1051},  //duty=3, dutyLt=8  
   { 801, 512,1016},  //duty=4, dutyLt=8  
   { 818, 512, 989},  //duty=5, dutyLt=8  
   { 830, 512, 966},  //duty=6, dutyLt=8  
   { 840, 512, 948},  //duty=7, dutyLt=8  
   { 849, 512, 931},  //duty=8, dutyLt=8  
   { 857, 512, 918},  //duty=9, dutyLt=8  
   { 862, 512, 906},  //duty=10, dutyLt=8  
   { 868, 512, 897},  //duty=11, dutyLt=8  
   { 872, 512, 887},  //duty=12, dutyLt=8  
   { 874, 512, 877},  //duty=13, dutyLt=8  
   { 868, 512, 861},  //duty=14, dutyLt=8  
   { 866, 512, 849},  //duty=15, dutyLt=8  
   { 516, 512,2094},  //duty=-1, dutyLt=9  
   { 665, 512,1300},  //duty=0, dutyLt=9  
   { 701, 512,1208},  //duty=1, dutyLt=9  
   { 741, 512,1122},  //duty=2, dutyLt=9  
   { 769, 512,1067},  //duty=3, dutyLt=9  
   { 790, 512,1028},  //duty=4, dutyLt=9  
   { 806, 512, 999},  //duty=5, dutyLt=9  
   { 820, 512, 977},  //duty=6, dutyLt=9  
   { 830, 512, 958},  //duty=7, dutyLt=9  
   { 840, 512, 940},  //duty=8, dutyLt=9  
   { 847, 512, 926},  //duty=9, dutyLt=9  
   { 853, 512, 914},  //duty=10, dutyLt=9  
   { 858, 512, 904},  //duty=11, dutyLt=9  
   { 863, 512, 894},  //duty=12, dutyLt=9  
   { 862, 512, 881},  //duty=13, dutyLt=9  
   { 859, 512, 867},  //duty=14, dutyLt=9  
   { 855, 512, 854},  //duty=15, dutyLt=9  
   { 516, 512,2091},  //duty=-1, dutyLt=10  
   { 657, 512,1320},  //duty=0, dutyLt=10  
   { 692, 512,1227},  //duty=1, dutyLt=10  
   { 731, 512,1137},  //duty=2, dutyLt=10  
   { 759, 512,1080},  //duty=3, dutyLt=10  
   { 781, 512,1040},  //duty=4, dutyLt=10  
   { 797, 512,1010},  //duty=5, dutyLt=10  
   { 810, 512, 985},  //duty=6, dutyLt=10  
   { 821, 512, 967},  //duty=7, dutyLt=10  
   { 831, 512, 948},  //duty=8, dutyLt=10  
   { 838, 512, 934},  //duty=9, dutyLt=10  
   { 844, 512, 922},  //duty=10, dutyLt=10  
   { 850, 512, 911},  //duty=11, dutyLt=10  
   { 853, 512, 901},  //duty=12, dutyLt=10  
   { 852, 512, 886},  //duty=13, dutyLt=10  
   { 844, 512, 866},  //duty=14, dutyLt=10  
   { 839, 512, 851},  //duty=15, dutyLt=10  
   { 516, 512,2086},  //duty=-1, dutyLt=11  
   { 650, 512,1338},  //duty=0, dutyLt=11  
   { 684, 512,1243},  //duty=1, dutyLt=11  
   { 723, 512,1151},  //duty=2, dutyLt=11  
   { 751, 512,1093},  //duty=3, dutyLt=11  
   { 772, 512,1052},  //duty=4, dutyLt=11  
   { 788, 512,1020},  //duty=5, dutyLt=11  
   { 802, 512, 995},  //duty=6, dutyLt=11  
   { 813, 512, 975},  //duty=7, dutyLt=11  
   { 822, 512, 957},  //duty=8, dutyLt=11  
   { 830, 512, 942},  //duty=9, dutyLt=11  
   { 837, 512, 930},  //duty=10, dutyLt=11  
   { 842, 512, 918},  //duty=11, dutyLt=11  
   { 845, 512, 906},  //duty=12, dutyLt=11  
   { 839, 512, 887},  //duty=13, dutyLt=11  
   { 838, 512, 873},  //duty=14, dutyLt=11  
   { 827, 512, 853},  //duty=15, dutyLt=11  
   { 516, 512,2056},  //duty=-1, dutyLt=12  
   { 638, 512,1372},  //duty=0, dutyLt=12  
   { 670, 512,1274},  //duty=1, dutyLt=12  
   { 708, 512,1177},  //duty=2, dutyLt=12  
   { 735, 512,1116},  //duty=3, dutyLt=12  
   { 756, 512,1073},  //duty=4, dutyLt=12  
   { 773, 512,1040},  //duty=5, dutyLt=12  
   { 787, 512,1014},  //duty=6, dutyLt=12  
   { 798, 512, 992},  //duty=7, dutyLt=12  
   { 808, 512, 973},  //duty=8, dutyLt=12  
   { 815, 512, 957},  //duty=9, dutyLt=12  
   { 822, 512, 943},  //duty=10, dutyLt=12  
   { 827, 512, 930},  //duty=11, dutyLt=12  
   { 827, 512, 915},  //duty=12, dutyLt=12  
   { 821, 512, 894},  //duty=13, dutyLt=12  
   { 808, 512, 867},  //duty=14, dutyLt=12  
   { 805, 512, 854},  //duty=15, dutyLt=12  
   { 516, 512,2063},  //duty=-1, dutyLt=13  
   { 633, 512,1387},  //duty=0, dutyLt=13  
   { 664, 512,1287},  //duty=1, dutyLt=13  
   { 702, 512,1191},  //duty=2, dutyLt=13  
   { 729, 512,1128},  //duty=3, dutyLt=13  
   { 750, 512,1082},  //duty=4, dutyLt=13  
   { 766, 512,1049},  //duty=5, dutyLt=13  
   { 780, 512,1022},  //duty=6, dutyLt=13  
   { 791, 512, 999},  //duty=7, dutyLt=13  
   { 802, 512, 981},  //duty=8, dutyLt=13  
   { 809, 512, 964},  //duty=9, dutyLt=13  
   { 815, 512, 950},  //duty=10, dutyLt=13  
   { 819, 512, 935},  //duty=11, dutyLt=13  
   { 818, 512, 918},  //duty=12, dutyLt=13  
   { 809, 512, 894},  //duty=13, dutyLt=13  
   { 798, 512, 869},  //duty=14, dutyLt=13  
   { 796, 512, 856},  //duty=15, dutyLt=13  
   { 516, 512,2066},  //duty=-1, dutyLt=14  
   { 629, 512,1400},  //duty=0, dutyLt=14  
   { 659, 512,1301},  //duty=1, dutyLt=14  
   { 695, 512,1203},  //duty=2, dutyLt=14  
   { 722, 512,1137},  //duty=3, dutyLt=14  
   { 743, 512,1092},  //duty=4, dutyLt=14  
   { 760, 512,1057},  //duty=5, dutyLt=14  
   { 773, 512,1030},  //duty=6, dutyLt=14  
   { 785, 512,1007},  //duty=7, dutyLt=14  
   { 795, 512, 987},  //duty=8, dutyLt=14  
   { 803, 512, 971},  //duty=9, dutyLt=14  
   { 809, 512, 956},  //duty=10, dutyLt=14  
   { 811, 512, 940},  //duty=11, dutyLt=14  
   { 804, 512, 915},  //duty=12, dutyLt=14  
   { 802, 512, 898},  //duty=13, dutyLt=14  
   { 776, 512, 855},  //duty=14, dutyLt=14  
   { 778, 512, 847},  //duty=15, dutyLt=14  
   { 516, 512,2059},  //duty=-1, dutyLt=15  
   { 625, 512,1412},  //duty=0, dutyLt=15  
   { 654, 512,1313},  //duty=1, dutyLt=15  
   { 690, 512,1213},  //duty=2, dutyLt=15  
   { 716, 512,1148},  //duty=3, dutyLt=15  
   { 737, 512,1101},  //duty=4, dutyLt=15  
   { 754, 512,1067},  //duty=5, dutyLt=15  
   { 768, 512,1038},  //duty=6, dutyLt=15  
   { 779, 512,1016},  //duty=7, dutyLt=15  
   { 789, 512, 994},  //duty=8, dutyLt=15  
   { 797, 512, 977},  //duty=9, dutyLt=15  
   { 804, 512, 961},  //duty=10, dutyLt=15  
   { 804, 512, 944},  //duty=11, dutyLt=15  
   { 792, 512, 911},  //duty=12, dutyLt=15  
   { 786, 512, 891},  //duty=13, dutyLt=15  
   { 775, 512, 865},  //duty=14, dutyLt=15  
   { 770, 512, 849},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512}
/*
    {1117, 512,1024},
    {1120, 512,1054},  
    {1097, 512,1047},  
    {1075, 512,1008}, 
    {1093, 512,1011}, 
    {1082, 512, 992},  
    {1097, 512, 960}, 
    {1099, 512, 957}, 
    {1091, 512, 978}, 
    {1096, 512, 935},


   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0}
   */
}}


// zhaozhensen@wind-mobi.com 20161012 end
