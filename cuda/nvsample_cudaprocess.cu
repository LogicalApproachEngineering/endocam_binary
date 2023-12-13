/*
 * Copyright (c) 2016-2018, NVIDIA CORPORATION. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of NVIDIA CORPORATION nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>

#include <cuda.h>

#include <cairo.h>
#include <pango/pango.h>
#include <pango/pango-layout.h>
#include <pango/pangocairo.h>


#include "customer_functions.h"
#include "cudaEGL.h"
#include "iva_metadata.h"

#define BOX_W 32
#define BOX_H 32

#define CORD_X 64
#define CORD_Y 64
#define MAX_BUFFERS 30
// static BBOX rect_data[MAX_BUFFERS];

/**
  * Dummy custom pre-process API implematation.
  * It just access mapped surface userspace pointer &
  * memset with specific pattern modifying pixel-data in-place.
  *
  * @param sBaseAddr  : Mapped Surfaces pointers
  * @param smemsize   : surfaces size array
  * @param swidth     : surfaces width array
  * @param sheight    : surfaces height array
  * @param spitch     : surfaces pitch array
  * @param nsurfcount : surfaces count
  */
static void
pre_process (void **sBaseAddr,
                unsigned int *smemsize,
                unsigned int *swidth,
                unsigned int *sheight,
                unsigned int *spitch,
                ColorFormat  *sformat,
                unsigned int nsurfcount,
                void ** usrptr)
{ 
  static cairo_surface_t *mask_surface = cairo_image_surface_create_from_png("Square_Mask_v2p00.png");
  static cairo_surface_t *surface;
  static cairo_t *cairo_context;
  if (sformat[0] == COLOR_FORMAT_RGBA) {
    // unsigned char xoffset = 100;
    // unsigned char yoffset = 100;
    // unsigned char* rgba = (unsigned char *)sBaseAddr[0];
    // rgba += ((spitch[0] * yoffset) + xoffset);
    // cairo_surface_t *surface, *mask_surface;
    // cairo_t *cairo_context;

    surface = cairo_image_surface_create_for_data
            ((unsigned char *)sBaseAddr[0], CAIRO_FORMAT_ARGB32, swidth[0],
             sheight[0], spitch[0]);
    cairo_context = cairo_create (surface);

    // mask_surface = cairo_image_surface_create_from_png("Square_Mask_v2p00.png");
    cairo_set_source_surface(cairo_context, mask_surface, 0.0, 0.0);
    cairo_paint(cairo_context);

    cairo_destroy (cairo_context);
    cairo_surface_destroy (surface);
  }
}

/**
  * Dummy custom post-process API implematation.
  * It just access mapped surface userspace pointer &
  * memset with specific pattern modifying pixel-data in-place.
  *
  * @param sBaseAddr  : Mapped Surfaces pointers
  * @param smemsize   : surfaces size array
  * @param swidth     : surfaces width array
  * @param sheight    : surfaces height array
  * @param spitch     : surfaces pitch array
  * @param nsurfcount : surfaces count
  */
static void
post_process (void **sBaseAddr,
                unsigned int *smemsize,
                unsigned int *swidth,
                unsigned int *sheight,
                unsigned int *spitch,
                ColorFormat  *sformat,
                unsigned int nsurfcount,
                void ** usrptr)
{
  static cairo_surface_t *mask_surface = cairo_image_surface_create_from_png("Round_Mask_v2p00.png");
  static cairo_surface_t *surface;
  static cairo_t *cairo_context;
  if (sformat[0] == COLOR_FORMAT_RGBA) {
    // unsigned char xoffset = 100;
    // unsigned char yoffset = 100;
    // unsigned char* rgba = (unsigned char *)sBaseAddr[0];
    // rgba += ((spitch[0] * yoffset) + xoffset);
    // cairo_surface_t *surface;
    // cairo_t *cairo_context;

    surface = cairo_image_surface_create_for_data
            ((unsigned char *)sBaseAddr[0], CAIRO_FORMAT_ARGB32, swidth[0],
             sheight[0], spitch[0]);
    cairo_context = cairo_create (surface);

    // mask_surface = cairo_image_surface_create_from_png("Round_Mask_v2p00.png");
    cairo_set_source_surface(cairo_context, mask_surface, 0.0, 0.0);
    cairo_paint(cairo_context);
    // layout = pango_cairo_create_layout (cairo_context);
    // snprintf(font_size_buffer, 256, "%s %d",
    //     "Arial", 18);
    // desc = pango_font_description_from_string (font_size_buffer);
    // pango_layout_set_font_description (layout, desc);
    // snprintf(display_text, 256, "%s",
    //     "Hello, world.");
    // pango_layout_set_text (layout, display_text, -1);
    // cairo_set_source_rgba (cairo_context, 1.0, 0, 1.0, 1.0);
    // pango_cairo_update_layout (cairo_context, layout);
    // cairo_move_to(cairo_context, 256, 256);
    // pango_cairo_show_layout (cairo_context, layout);
    // pango_font_description_free (desc);
    // g_object_unref(layout);

    cairo_destroy (cairo_context);
    cairo_surface_destroy (surface);
  }

}



static void add_metadata(void ** usrptr)
{}

/**
  * Performs CUDA Operations on egl image.
  *
  * @param image : EGL image
  */
static void
gpu_process (EGLImageKHR image, void ** usrptr)
{
  CUresult status;
  CUeglFrame eglFrame;
  CUgraphicsResource pResource = NULL;

  cudaFree(0);
  status = cuGraphicsEGLRegisterImage(&pResource, image, CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE);
  if (status != CUDA_SUCCESS) {
    printf("cuGraphicsEGLRegisterImage failed : %d \n", status);
    return;
  }

  status = cuGraphicsResourceGetMappedEglFrame( &eglFrame, pResource, 0, 0);
  if (status != CUDA_SUCCESS) {
    printf ("cuGraphicsSubResourceGetMappedArray failed\n");
  }

  status = cuCtxSynchronize();
  if (status != CUDA_SUCCESS) {
    printf ("cuCtxSynchronize failed \n");
  }

  if (eglFrame.frameType == CU_EGL_FRAME_TYPE_PITCH) {
    if (eglFrame.eglColorFormat == CU_EGL_COLOR_FORMAT_ABGR) {
    /* Rectangle label in plane RGBA, you can replace this with any cuda algorithms */
      //addLabels((CUdeviceptr) eglFrame.frame.pPitch[0], eglFrame.pitch);
    } else if (eglFrame.eglColorFormat == CU_EGL_COLOR_FORMAT_YUV420_SEMIPLANAR) {
    /* Rectangle label in plan UV , you can replace this with any cuda algorithms */
      //addLabels((CUdeviceptr) eglFrame.frame.pPitch[1], eglFrame.pitch);
    } else
      printf ("Invalid eglcolorformat\n");
  }

  add_metadata(usrptr);

  status = cuCtxSynchronize();
  if (status != CUDA_SUCCESS) {
    printf ("cuCtxSynchronize failed after memcpy \n");
  }

  status = cuGraphicsUnregisterResource(pResource);
  if (status != CUDA_SUCCESS) {
    printf("cuGraphicsEGLUnRegisterResource failed: %d \n", status);
  }
}

extern "C" void
init (CustomerFunction * pFuncs)
{
  pFuncs->fPreProcess = pre_process;
  pFuncs->fGPUProcess = gpu_process;
  pFuncs->fPostProcess = post_process;
}

extern "C" void
deinit (void)
{
  /* deinitialization */
}
