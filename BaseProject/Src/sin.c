// =====================================================================
//	  Look-Up Tables
//		SIN: sin(x*pi/180)
//
//	Exported by Cearn's excellut v1.0
//	(comments, kudos, flames to daytshen@hotmail.com)
//
// =====================================================================

#include "sin.h"
// -----------------------------------------------------------------------
// SIN: a 360 long LUT of 16bit values in 2.14 format
// sin(x*pi/180)
const signed short SIN[360]=
{
	0x0000,0x011E,0x023C,0x0359,0x0477,0x0594,0x06B1,0x07CD,
	0x08E8,0x0A03,0x0B1D,0x0C36,0x0D4E,0x0E66,0x0F7C,0x1090,
	0x11A4,0x12B6,0x13C7,0x14D6,0x15E4,0x16F0,0x17FA,0x1902,
	0x1A08,0x1B0C,0x1C0E,0x1D0E,0x1E0C,0x1F07,0x2000,0x20F6,
	0x21EA,0x22DB,0x23CA,0x24B5,0x259E,0x2684,0x2767,0x2847,
	0x2923,0x29FD,0x2AD3,0x2BA6,0x2C75,0x2D41,0x2E0A,0x2ECE,
	0x2F90,0x304D,0x3107,0x31BD,0x326F,0x331D,0x33C7,0x346D,
	0x350F,0x35AD,0x3646,0x36DC,0x376D,0x37FA,0x3882,0x3906,

	0x3986,0x3A01,0x3A78,0x3AEA,0x3B57,0x3BC0,0x3C24,0x3C83,
	0x3CDE,0x3D34,0x3D85,0x3DD2,0x3E19,0x3E5C,0x3E9A,0x3ED3,
	0x3F07,0x3F36,0x3F61,0x3F86,0x3FA6,0x3FC2,0x3FD8,0x3FEA,
	0x3FF6,0x3FFE,0x4000,0x3FFE,0x3FF6,0x3FEA,0x3FD8,0x3FC2,
	0x3FA6,0x3F86,0x3F61,0x3F36,0x3F07,0x3ED3,0x3E9A,0x3E5C,
	0x3E19,0x3DD2,0x3D85,0x3D34,0x3CDE,0x3C83,0x3C24,0x3BC0,
	0x3B57,0x3AEA,0x3A78,0x3A01,0x3986,0x3906,0x3882,0x37FA,
	0x376D,0x36DC,0x3646,0x35AD,0x350F,0x346D,0x33C7,0x331D,

	0x326F,0x31BD,0x3107,0x304D,0x2F90,0x2ECE,0x2E0A,0x2D41,
	0x2C75,0x2BA6,0x2AD3,0x29FD,0x2923,0x2847,0x2767,0x2684,
	0x259E,0x24B5,0x23CA,0x22DB,0x21EA,0x20F6,0x2000,0x1F07,
	0x1E0C,0x1D0E,0x1C0E,0x1B0C,0x1A08,0x1902,0x17FA,0x16F0,
	0x15E4,0x14D6,0x13C7,0x12B6,0x11A4,0x1090,0x0F7C,0x0E66,
	0x0D4E,0x0C36,0x0B1D,0x0A03,0x08E8,0x07CD,0x06B1,0x0594,
	0x0477,0x0359,0x023C,0x011E,0x0000,0xFEE2,0xFDC4,0xFCA7,
	0xFB89,0xFA6C,0xF94F,0xF833,0xF718,0xF5FD,0xF4E3,0xF3CA,

	0xF2B2,0xF19A,0xF084,0xEF70,0xEE5C,0xED4A,0xEC39,0xEB2A,
	0xEA1C,0xE910,0xE806,0xE6FE,0xE5F8,0xE4F4,0xE3F2,0xE2F2,
	0xE1F4,0xE0F9,0xE000,0xDF0A,0xDE16,0xDD25,0xDC36,0xDB4B,
	0xDA62,0xD97C,0xD899,0xD7B9,0xD6DD,0xD603,0xD52D,0xD45A,
	0xD38B,0xD2BF,0xD1F6,0xD132,0xD070,0xCFB3,0xCEF9,0xCE43,
	0xCD91,0xCCE3,0xCC39,0xCB93,0xCAF1,0xCA53,0xC9BA,0xC924,
	0xC893,0xC806,0xC77E,0xC6FA,0xC67A,0xC5FF,0xC588,0xC516,
	0xC4A9,0xC440,0xC3DC,0xC37D,0xC322,0xC2CC,0xC27B,0xC22E,

	0xC1E7,0xC1A4,0xC166,0xC12D,0xC0F9,0xC0CA,0xC09F,0xC07A,
	0xC05A,0xC03E,0xC028,0xC016,0xC00A,0xC002,0xC000,0xC002,
	0xC00A,0xC016,0xC028,0xC03E,0xC05A,0xC07A,0xC09F,0xC0CA,
	0xC0F9,0xC12D,0xC166,0xC1A4,0xC1E7,0xC22E,0xC27B,0xC2CC,
	0xC322,0xC37D,0xC3DC,0xC440,0xC4A9,0xC516,0xC588,0xC5FF,
	0xC67A,0xC6FA,0xC77E,0xC806,0xC893,0xC924,0xC9BA,0xCA53,
	0xCAF1,0xCB93,0xCC39,0xCCE3,0xCD91,0xCE43,0xCEF9,0xCFB3,
	0xD070,0xD132,0xD1F6,0xD2BF,0xD38B,0xD45A,0xD52D,0xD603,

	0xD6DD,0xD7B9,0xD899,0xD97C,0xDA62,0xDB4B,0xDC36,0xDD25,
	0xDE16,0xDF0A,0xE000,0xE0F9,0xE1F4,0xE2F2,0xE3F2,0xE4F4,
	0xE5F8,0xE6FE,0xE806,0xE910,0xEA1C,0xEB2A,0xEC39,0xED4A,
	0xEE5C,0xEF70,0xF084,0xF19A,0xF2B2,0xF3CA,0xF4E3,0xF5FD,
	0xF718,0xF833,0xF94F,0xFA6C,0xFB89,0xFCA7,0xFDC4,0xFEE2,
};
signed short COS(int angle){//This is a function that calculates cosine based on the sine LUT
	signed short x=0;
	if((0<=angle)&&(angle<269)){x=SIN[angle+90];}
	else if((270<=angle)&&(angle<360)){x=SIN[angle-270];}
	return x;
}

