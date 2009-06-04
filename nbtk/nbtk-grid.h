/*
 * nbtk-grid.h: Reflowing grid layout container for nbtk.
 *
 * Copyright 2008, 2009 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 * Boston, MA 02111-1307, USA.
 *
 * Written by: Øyvind Kolås <pippin@linux.intel.com>
 * Ported to nbtk by: Robert Staudinger <robsta@openedhand.com>
 *
 */

#if !defined(NBTK_H_INSIDE) && !defined(NBTK_COMPILATION)
#error "Only <nbtk/nbtk.h> can be included directly.h"
#endif

#ifndef __NBTK_GRID_H__
#define __NBTK_GRID_H__

#include <clutter/clutter.h>
#include <nbtk/nbtk-widget.h>

G_BEGIN_DECLS

#define NBTK_TYPE_GRID               (nbtk_grid_get_type())
#define NBTK_GRID(obj)                                       \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj),                        \
                               NBTK_TYPE_GRID,               \
                               NbtkGrid))
#define NBTK_GRID_CLASS(klass)                               \
  (G_TYPE_CHECK_CLASS_CAST ((klass),                         \
                            NBTK_TYPE_GRID,                  \
                            NbtkGridClass))
#define NBTK_IS_GRID(obj)                                    \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj),                        \
                               NBTK_TYPE_GRID))
#define NBTK_IS_GRID_CLASS(klass)                            \
  (G_TYPE_CHECK_CLASS_TYPE ((klass),                         \
                            NBTK_TYPE_GRID))
#define NBTK_GRID_GET_CLASS(obj)                             \
  (G_TYPE_INSTANCE_GET_CLASS ((obj),                         \
                              NBTK_TYPE_GRID,                \
                              NbtkGridClass))

typedef struct _NbtkGrid        NbtkGrid;
typedef struct _NbtkGridClass   NbtkGridClass;
typedef struct _NbtkGridPrivate NbtkGridPrivate;

struct _NbtkGridClass
{
  NbtkWidgetClass parent_class;
};

/**
 * NbtkGrid:
 *
 * The contents of the this structure are private and should only be accessed
 * through the public API.
 */
struct _NbtkGrid
{
  /*< private >*/
  NbtkWidget parent;

  NbtkGridPrivate *priv;
};

GType nbtk_grid_get_type (void) G_GNUC_CONST;

NbtkWidget   *nbtk_grid_new                    (void);
void          nbtk_grid_set_end_align          (NbtkGrid    *self,
                                                gboolean     value);
gboolean      nbtk_grid_get_end_align          (NbtkGrid    *self);
void          nbtk_grid_set_homogenous_rows    (NbtkGrid    *self,
                                                gboolean     value);
gboolean      nbtk_grid_get_homogenous_rows    (NbtkGrid    *self);
void          nbtk_grid_set_homogenous_columns (NbtkGrid    *self,
                                                gboolean     value);
gboolean      nbtk_grid_get_homogenous_columns (NbtkGrid    *self);
void          nbtk_grid_set_column_major       (NbtkGrid    *self,
                                                gboolean     value);
gboolean      nbtk_grid_get_column_major       (NbtkGrid    *self);
void          nbtk_grid_set_row_gap            (NbtkGrid    *self,
                                                gfloat  value);
gfloat        nbtk_grid_get_row_gap            (NbtkGrid    *self);
void          nbtk_grid_set_column_gap         (NbtkGrid    *self,
                                                gfloat  value);
gfloat        nbtk_grid_get_column_gap         (NbtkGrid    *self);
void          nbtk_grid_set_valign             (NbtkGrid    *self,
                                                gdouble      value);
gdouble       nbtk_grid_get_valign             (NbtkGrid    *self);
void          nbtk_grid_set_halign             (NbtkGrid    *self,
                                                gdouble      value);
gdouble       nbtk_grid_get_halign             (NbtkGrid    *self);

void nbtk_grid_set_max_stride (NbtkGrid *self,
                               gint      value);
gint nbtk_grid_get_max_stride (NbtkGrid *self);

G_END_DECLS

#endif /* __NBTK_GRID_H__ */
