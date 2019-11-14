#ifndef _awlcTypes_H_
#define _awlcTypes_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 *====================
 * Includes
 *====================
 */

/*
 *====================
 * Defines
 *====================
 */

/*
 *==========================
 * Typedefs
 *==========================
 */
/* ASM admission restricted from here. */
typedef char                            SINT8;
/**< Character type                             : 8 bits                    */
typedef float                           FLOAT32;
/**< Floating type                                                          */
typedef unsigned char                   UINT8;
typedef unsigned char                   uchar;
/**< Unsigned char type                         : 8 bits                    */
typedef unsigned char                   MDC_BOOL;
/**< Boolean type                               : 8 bits                    */
typedef signed long                     SLONG;
/**< Signed long integer type                   : 32 bits                   */
typedef unsigned long                   ULONG;
/**< Unsigned long integer type                 : 32 bits                   */
typedef void                            VOID;
/**< void type                                  : 32 bits                   */

#if defined(_EXT_INT_IS_2BYTES_)
    typedef int                         SINT16;
    /**< Signed integer type                        : 16 bits               */
    typedef unsigned int                UINT16;
    /**< Unsigned integer type                      : 16 bits               */
    typedef signed long                 SINT32;
    /**< Signed long integer type                   : 32 bits               */
    typedef unsigned long               UINT32;
    /**< Unsigned long integer type                 : 32 bits               */
#else
    typedef short                       SINT16;
    /**< Signed short integer type                  : 16 bits               */
    typedef unsigned short              UINT16;
    typedef unsigned short              ushort;
    /**< Unsigned short integer type                : 16 bits               */
    typedef int                         SINT32;
    /**< Signed integer type                        : 32 bits               */
    typedef unsigned int                UINT32;
    /**< Unsigned integer type                      : 32 bits               */
    typedef long int                    SINT64;
    /**< Signed long integer type                   : 64 bits               */
    typedef unsigned long int           UINT64;
    /**< Unsigned long integer type                 : 64 bits               */
#endif  /* end of defined(_EXT_INT_IS_2BYTES_) */

#ifdef __cplusplus
}
#endif

#endif  /* _awlcTypes_H_ */

/* End of file awlcTypes.h */
