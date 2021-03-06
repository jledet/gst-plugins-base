/* Video conversion api function
 * Copyright (C) 2014 Wim Taymans <wim.taymans@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_VIDEO_CONVERTER_H__
#define __GST_VIDEO_CONVERTER_H__

#include <gst/video/video.h>

G_BEGIN_DECLS

/**
 * GstVideoDitherMethod:
 * @GST_VIDEO_DITHER_NONE: no dithering
 * @GST_VIDEO_DITHER_VERTERR: propagate rounding errors downwards
 * @GST_VIDEO_DITHER_HALFTONE: Dither with halftone pattern
 * @GST_VIDEO_DITHER_HORIZERR: propagate rounding errors right
 *
 * Different dithering methods to use.
 */
typedef enum {
  GST_VIDEO_DITHER_NONE,
  GST_VIDEO_DITHER_VERTERR,
  GST_VIDEO_DITHER_HALFTONE,
  GST_VIDEO_DITHER_HORIZERR
} GstVideoDitherMethod;

/**
 * GST_VIDEO_CONVERTER_OPT_RESAMPLER_METHOD:
 *
 * #GST_TYPE_RESAMPLER_METHOD, The resampler method to use for
 * resampling. Other options for the resampler can be used, see
 * the #GstResampler. Default is #GST_RESAMPLER_METHOD_CUBIC
 */
#define GST_VIDEO_CONVERTER_OPT_RESAMPLER_METHOD   "GstVideoConverter.resampler-method"
/**
 * GST_VIDEO_CONVERTER_OPT_RESAMPLER_TAPS:
 *
 * #G_TYPE_UINT, The number of taps for the resampler.
 * Default is 0: let the resampler choose a good value.
 */
#define GST_VIDEO_CONVERTER_OPT_RESAMPLER_TAPS   "GstVideoConverter.resampler-taps"

/**
 * GST_VIDEO_CONVERTER_OPT_DITHER_METHOD:
 *
 * #GST_TYPE_VIDEO_DITHER_METHOD, The dither method to use when
 * changing bit depth.
 */
#define GST_VIDEO_CONVERTER_OPT_DITHER_METHOD   "GstVideoConverter.dither-method"

/**
 * GST_VIDEO_CONVERTER_OPT_SRC_X:
 *
 * #G_TYPE_INT, source x position to start conversion, default 0
 */
#define GST_VIDEO_CONVERTER_OPT_SRC_X   "GstVideoConverter.src-x"
/**
 * GST_VIDEO_CONVERTER_OPT_SRC_Y:
 *
 * #G_TYPE_INT, source y position to start conversion, default 0
 */
#define GST_VIDEO_CONVERTER_OPT_SRC_Y   "GstVideoConverter.src-y"
/**
 * GST_VIDEO_CONVERTER_OPT_SRC_WIDTH:
 *
 * #G_TYPE_INT, source width to convert, default source width
 */
#define GST_VIDEO_CONVERTER_OPT_SRC_WIDTH   "GstVideoConverter.src-width"
/**
 * GST_VIDEO_CONVERTER_OPT_SRC_HEIGHT:
 *
 * #G_TYPE_INT, source height to convert, default source height
 */
#define GST_VIDEO_CONVERTER_OPT_SRC_HEIGHT   "GstVideoConverter.src-height"

/**
 * GST_VIDEO_CONVERTER_OPT_DEST_X:
 *
 * #G_TYPE_INT, x position in the destination frame, default 0
 */
#define GST_VIDEO_CONVERTER_OPT_DEST_X   "GstVideoConverter.dest-x"
/**
 * GST_VIDEO_CONVERTER_OPT_DEST_Y:
 *
 * #G_TYPE_INT, y position in the destination frame, default 0
 */
#define GST_VIDEO_CONVERTER_OPT_DEST_Y   "GstVideoConverter.dest-y"
/**
 * GST_VIDEO_CONVERTER_OPT_DEST_WIDTH:
 *
 * #G_TYPE_INT, width in the destination frame, default destination width
 */
#define GST_VIDEO_CONVERTER_OPT_DEST_WIDTH   "GstVideoConverter.dest-width"
/**
 * GST_VIDEO_CONVERTER_OPT_DEST_HEIGHT:
 *
 * #G_TYPE_INT, height in the destination frame, default destination height
 */
#define GST_VIDEO_CONVERTER_OPT_DEST_HEIGHT   "GstVideoConverter.dest-height"

/**
 * GST_VIDEO_CONVERTER_OPT_FILL_BORDER:
 *
 * #G_TYPE_BOOLEAN, if the destination rectangle does not fill the complete
 * destination image, render a border with
 * #GST_VIDEO_CONVERTER_OPT_BORDER_ARGB. Otherwise the unusded pixels in the
 * destination are untouched. Default %TRUE.
 */
#define GST_VIDEO_CONVERTER_OPT_FILL_BORDER   "GstVideoConverter.fill-border"
/**
 * GST_VIDEO_CONVERTER_OPT_BORDER_ARGB:
 *
 * #G_TYPE_UINT, the border color to use if #GST_VIDEO_CONVERTER_OPT_FILL_BORDER
 * is set to %TRUE. Default 0x00000000
 */
#define GST_VIDEO_CONVERTER_OPT_BORDER_ARGB   "GstVideoConverter.border-argb"


typedef struct _GstVideoConverter GstVideoConverter;

GstVideoConverter *  gst_video_converter_new            (GstVideoInfo *in_info,
                                                         GstVideoInfo *out_info,
                                                         GstStructure *config);
void                 gst_video_converter_free           (GstVideoConverter * convert);

gboolean             gst_video_converter_set_config     (GstVideoConverter * convert, GstStructure *config);
const GstStructure * gst_video_converter_get_config     (GstVideoConverter * convert);

void                 gst_video_converter_frame          (GstVideoConverter * convert,
                                                         const GstVideoFrame *src, GstVideoFrame *dest);


G_END_DECLS

#endif /* __GST_VIDEO_CONVERTER_H__ */
