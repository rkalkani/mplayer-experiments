
/* Defines that AFMT_ stuff */

#ifdef	HAVE_SYS_SOUNDCARD_H
#include <sys/soundcard.h>	/* For AFMT_* on linux */
#else 
#ifdef HAVE_SOUNDCARD_H
#include <soundcard.h> /* OpenBSD have this instead of <sys/soundcard> */
#endif
#endif

#include "../config.h" /* for native endianness */

/* standard, old OSS audio formats */
#ifndef AFMT_MU_LAW
#	define AFMT_MU_LAW		0x00000001
#	define AFMT_A_LAW		0x00000002
#	define AFMT_IMA_ADPCM		0x00000004
#	define AFMT_U8			0x00000008
#	define AFMT_S16_LE		0x00000010	/* Little endian signed 16*/
#	define AFMT_S16_BE		0x00000020	/* Big endian signed 16 */
#	define AFMT_S8			0x00000040
#	define AFMT_U16_LE		0x00000080	/* Little endian U16 */
#	define AFMT_U16_BE		0x00000100	/* Big endian U16 */
#endif

#ifndef AFMT_MPEG
#	define AFMT_MPEG		0x00000200	/* MPEG (2) audio */
#endif

#ifndef AFMT_AC3
#	define AFMT_AC3			0x00000400	/* Dolby Digital AC3 */
#endif

/* 24 bit formats from the linux kernel */
#ifndef AFMT_S24_LE

// FreeBSD fix...
#if AFMT_S32_LE == 0x1000

#define AFMT_S24_LE		0x00010000
#define AFMT_S24_BE		0x00020000
#define AFMT_U24_LE		0x00040000
#define AFMT_U24_BE		0x00080000

#else

#define AFMT_S24_LE		0x00000800
#define AFMT_S24_BE		0x00001000
#define AFMT_U24_LE		0x00002000
#define AFMT_U24_BE		0x00004000

#endif

#endif

/* 32 bit formats from the linux kernel */
#ifndef AFMT_S32_LE
#define AFMT_S32_LE		0x00008000
#define AFMT_S32_BE		0x00010000
#define AFMT_U32_LE		0x00020000
#define AFMT_U32_BE		0x00040000
#endif

/* native endian formats */
#ifndef	AFMT_S16_NE
# if WORDS_BIGENDIAN
#  define AFMT_S16_NE	AFMT_S16_BE
#  define AFMT_S24_NE	AFMT_S24_BE
#  define AFMT_S32_NE	AFMT_S32_BE
# else
#  define AFMT_S16_NE	AFMT_S16_LE
#  define AFMT_S24_NE	AFMT_S24_LE
#  define AFMT_S32_NE	AFMT_S32_LE
# endif
#endif

#ifndef AFMT_FLOAT
# define AFMT_FLOAT               0x00100000
#endif

/* for formats that don't have a corresponding AFMT_* type,
 * use the flags from libaf/af_format.h or'ed with this */
#define AFMT_AF_FLAGS             0x70000000
