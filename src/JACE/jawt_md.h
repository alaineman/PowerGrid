/*
 * Modified version of the platform-dependant header file
 * based on #defines. This allows every platform to include the
 * same header file, reducing the complexity.
 */

#ifndef _JAVASOFT_JAWT_MD_H_
#define _JAVASOFT_JAWT_MD_H_

#ifdef JNI_WIN32
#  include <windows.h>
#else // X11 (also works for Mac)
#  include <X11/Xlib.h>
#  include <X11/Xutil.h>
#  include <X11/Intrinsic.h>
#endif

#include "jawt.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef JNI_WIN32
/*
 * Win32-specific declarations for AWT native interface.
 * See notes in jawt.h for an example of use.
 */
typedef struct jawt_Win32DrawingSurfaceInfo {
    /* Native window, DDB, or DIB handle */
    union {
        HWND hwnd;
        HBITMAP hbitmap;
        void* pbits;
    };
    /*
     * This HDC should always be used instead of the HDC returned from
     * BeginPaint() or any calls to GetDC().
     */
    HDC hdc;
    HPALETTE hpalette;
} JAWT_Win32DrawingSurfaceInfo;
#else
/*
 * X11-specific declarations for AWT native interface.
 * See notes in jawt.h for an example of use.
 */
typedef struct jawt_X11DrawingSurfaceInfo {
    Drawable drawable;
    Display* display;
    VisualID visualID;
    Colormap colormapID;
    int depth;
    /*
     * Since 1.4
     * Returns a pixel value from a set of RGB values.
     * This is useful for paletted color (256 color) modes.
     */
    int (JNICALL *GetAWTColor)(JAWT_DrawingSurface* ds,
        int r, int g, int b);
} JAWT_X11DrawingSurfaceInfo;
#endif

#ifdef __cplusplus
}
#endif

#endif /* !_JAVASOFT_JAWT_MD_H_ */
