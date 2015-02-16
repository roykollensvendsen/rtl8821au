/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __HAL_COMMON_LED_H_
#define __HAL_COMMON_LED_H_


#define MSECS(t)        (HZ * ((t) / 1000) + (HZ * ((t) % 1000)) / 1000)

//================================================================================
//	LED Behavior Constant.
//================================================================================
// Default LED behavior.
//
#define LED_BLINK_NORMAL_INTERVAL	100
#define LED_BLINK_SLOWLY_INTERVAL	200
#define LED_BLINK_LONG_INTERVAL	400
#define LED_INITIAL_INTERVAL		1800

// LED Customerization

//NETTRONIX
#define LED_BLINK_NORMAL_INTERVAL_NETTRONIX	100
#define LED_BLINK_SLOWLY_INTERVAL_NETTRONIX	2000

//PORNET
#define LED_BLINK_SLOWLY_INTERVAL_PORNET	1000
#define LED_BLINK_NORMAL_INTERVAL_PORNET	100
#define LED_BLINK_FAST_INTERVAL_BITLAND		30

//AzWave.
#define LED_CM2_BLINK_ON_INTERVAL		250
#define LED_CM2_BLINK_OFF_INTERVAL		4750
#define LED_CM8_BLINK_OFF_INTERVAL		3750	//for QMI

//RunTop
#define LED_RunTop_BLINK_INTERVAL		300

//ALPHA
#define LED_BLINK_NO_LINK_INTERVAL_ALPHA	1000
#define LED_BLINK_NO_LINK_INTERVAL_ALPHA_500MS 500 //add by ylb 20121012 for customer led for alpha
#define LED_BLINK_LINK_INTERVAL_ALPHA		500	//500
#define LED_BLINK_SCAN_INTERVAL_ALPHA		180 	//150
#define LED_BLINK_FASTER_INTERVAL_ALPHA		50
#define LED_BLINK_WPS_SUCESS_INTERVAL_ALPHA	5000

// 111122 by hpfan: Customized for Xavi
#define LED_CM11_BLINK_INTERVAL			300
#define LED_CM11_LINK_ON_INTERVEL		3000

//Netgear
#define LED_BLINK_LINK_INTERVAL_NETGEAR		500
#define LED_BLINK_LINK_SLOWLY_INTERVAL_NETGEAR		1000

#define LED_WPS_BLINK_OFF_INTERVAL_NETGEAR		100
#define LED_WPS_BLINK_ON_INTERVAL_NETGEAR		500

//Belkin AC950
#define LED_BLINK_LINK_INTERVAL_ON_BELKIN		200
#define LED_BLINK_LINK_INTERVAL_OFF_BELKIN		100
#define LED_BLINK_ERROR_INTERVAL_BELKIN		100

//by chiyokolin for Azurewave
#define LED_CM12_BLINK_INTERVAL_5Mbps		160
#define LED_CM12_BLINK_INTERVAL_10Mbps		80
#define LED_CM12_BLINK_INTERVAL_20Mbps		50
#define LED_CM12_BLINK_INTERVAL_40Mbps		40
#define LED_CM12_BLINK_INTERVAL_80Mbps		30
#define LED_CM12_BLINK_INTERVAL_MAXMbps		25

//================================================================================
// LED object.
//================================================================================

enum led_ctl_mode {
	LED_CTL_POWER_ON = 1,
	LED_CTL_LINK = 2,
	LED_CTL_NO_LINK = 3,
	LED_CTL_TX = 4,
	LED_CTL_RX = 5,
	LED_CTL_SITE_SURVEY = 6,
	LED_CTL_POWER_OFF = 7,
	LED_CTL_START_TO_LINK = 8,
	LED_CTL_START_WPS = 9,
	LED_CTL_STOP_WPS = 10,
	LED_CTL_START_WPS_BOTTON = 11, //added for runtop
	LED_CTL_STOP_WPS_FAIL = 12, //added for ALPHA
	LED_CTL_STOP_WPS_FAIL_OVERLAP = 13, //added for BELKIN
	LED_CTL_CONNECTION_NO_TRANSFER = 14,
};

typedef	enum _LED_STATE{
	LED_UNKNOWN = 0,
	RTW_LED_ON = 1,
	RTW_LED_OFF = 2,
	LED_BLINK_NORMAL = 3,
	LED_BLINK_SLOWLY = 4,
	LED_BLINK_POWER_ON = 5,
	LED_BLINK_SCAN = 6, 	// LED is blinking during scanning period, the # of times to blink is depend on time for scanning.
	LED_BLINK_NO_LINK = 7, // LED is blinking during no link state.
	LED_BLINK_StartToBlink = 8, // Customzied for Sercomm Printer Server case
	LED_BLINK_TXRX = 9,
	LED_BLINK_WPS = 10,	// LED is blinkg during WPS communication
	LED_BLINK_WPS_STOP = 11,	//for ALPHA
	LED_BLINK_WPS_STOP_OVERLAP = 12,	//for BELKIN
	LED_BLINK_RUNTOP = 13, 	// Customized for RunTop
	LED_BLINK_CAMEO = 14,
	LED_BLINK_XAVI = 15,
	LED_BLINK_ALWAYS_ON = 16,
	LED_BLINK_LINK_IN_PROCESS = 17,  //Customized for Belkin AC950
	LED_BLINK_AUTH_ERROR = 18,  //Customized for Belkin AC950
	LED_BLINK_Azurewave_5Mbps = 19,
	LED_BLINK_Azurewave_10Mbps = 20,
	LED_BLINK_Azurewave_20Mbps = 21,
	LED_BLINK_Azurewave_40Mbps = 22,
	LED_BLINK_Azurewave_80Mbps = 23,
	LED_BLINK_Azurewave_MAXMbps = 24,
}LED_STATE;

typedef enum _LED_PIN{
	LED_PIN_GPIO0,
	LED_PIN_LED0,
	LED_PIN_LED1,
	LED_PIN_LED2
}LED_PIN;


//================================================================================
// PCIE LED Definition.
//================================================================================

#define IS_LED_WPS_BLINKING(_LED_USB)	(((PLED_USB)_LED_USB)->CurrLedState==LED_BLINK_WPS \
					|| ((PLED_USB)_LED_USB)->CurrLedState==LED_BLINK_WPS_STOP \
					|| ((PLED_USB)_LED_USB)->bLedWPSBlinkInProgress)

#define IS_LED_BLINKING(_LED_USB) 	(((PLED_USB)_LED_USB)->bLedWPSBlinkInProgress \
					||((PLED_USB)_LED_USB)->bLedScanBlinkInProgress)


typedef	enum _LED_STRATEGY_USB{
	SW_LED_MODE0, // SW control 1 LED via GPIO0. It is default option.
	SW_LED_MODE1, // 2 LEDs, through LED0 and LED1. For ALPHA.
	SW_LED_MODE2, // SW control 1 LED via GPIO0, customized for AzWave 8187 minicard.
	SW_LED_MODE3, // SW control 1 LED via GPIO0, customized for Sercomm Printer Server case.
	SW_LED_MODE4, //for Edimax / Belkin
	SW_LED_MODE5, //for Sercomm / Belkin
	SW_LED_MODE6,	//for 88CU minicard, porting from ce SW_LED_MODE7
	SW_LED_MODE7,	//for Netgear special requirement
	SW_LED_MODE8, //for LC
	SW_LED_MODE9, //for Belkin AC950
	SW_LED_MODE10, //for Netgear A6200V2
	SW_LED_MODE11, //for Edimax / ASUS
	SW_LED_MODE12, //for WNC/NEC
	SW_LED_MODE13, //for Netgear A6100, 8811Au
	HW_LED, // HW control 2 LEDs, LED0 and LED1 (there are 4 different control modes, see MAC.CONFIG1 for details.)
}LED_STRATEGY_USB, *PLED_STRATEGY_USB;


typedef struct _LED_USB{
	struct rtl_priv *		padapter;

	LED_PIN				LedPin;	// Identify how to implement this SW led.

	LED_STATE			CurrLedState; // Current LED state.
	BOOLEAN				bLedOn; // TRUE if LED is ON, FALSE if LED is OFF.

	BOOLEAN				bSWLedCtrl;

	BOOLEAN				bLedBlinkInProgress; // TRUE if it is blinking, FALSE o.w..
	// ALPHA, added by chiyoko, 20090106
	BOOLEAN				bLedNoLinkBlinkInProgress;
	BOOLEAN				bLedLinkBlinkInProgress;
	BOOLEAN				bLedStartToLinkBlinkInProgress;
	BOOLEAN				bLedScanBlinkInProgress;
	BOOLEAN				bLedWPSBlinkInProgress;

	u32					BlinkTimes; // Number of times to toggle led state for blinking.
	uint8_t					BlinkCounter; //Added for turn off overlap led after blinking a while, by page, 20120821
	LED_STATE			BlinkingLedState; // Next state for blinking, either LED_ON or LED_OFF are.

	_timer				BlinkTimer; // Timer object for led blinking.

	_workitem			BlinkWorkItem; // Workitem used by BlinkTimer to manipulate H/W to blink LED.
} LED_USB, *PLED_USB;

typedef struct _LED_USB	LED_DATA, *PLED_DATA;
typedef enum _LED_STRATEGY_USB	LED_STRATEGY, *PLED_STRATEGY;

void LedControlUSB(struct rtl_priv *Adapter, enum led_ctl_mode LedAction
	);

struct led_priv{
	/* add for led controll */
	LED_DATA			SwLed0;
	LED_DATA			SwLed1;
	LED_DATA			SwLed2;
	LED_STRATEGY		LedStrategy;
	uint8_t					bRegUseLed;
	void (*LedControlHandler)(struct rtl_priv *padapter, enum led_ctl_mode LedAction);
	void (*SwLedOn)(struct rtl_priv *padapter, PLED_DATA pLed);
	void (*SwLedOff)(struct rtl_priv *padapter, PLED_DATA pLed);
	/* add for led controll */
};

#define rtw_led_control(adapter, LedAction) \
	do { \
		if((adapter)->ledpriv.LedControlHandler) \
			(adapter)->ledpriv.LedControlHandler((adapter), (LedAction)); \
	} while(0)

#define SwLedOn(adapter, pLed) \
	do { \
		if((adapter)->ledpriv.SwLedOn) \
			(adapter)->ledpriv.SwLedOn((adapter), (pLed)); \
	} while(0)

#define SwLedOff(adapter, pLed) \
	do { \
		if((adapter)->ledpriv.SwLedOff) \
			(adapter)->ledpriv.SwLedOff((adapter), (pLed)); \
	} while(0)

void BlinkTimerCallback(void *data);
void BlinkWorkItemCallback(_workitem *work);

void ResetLedStatus(PLED_DATA pLed);

void
InitLed(
	struct rtl_priv			*padapter,
	PLED_DATA		pLed,
	LED_PIN			LedPin
	);

void
DeInitLed(
	PLED_DATA		pLed
	);

//hal...
extern void BlinkHandler(PLED_DATA	pLed);

#endif //__RTW_LED_H_

