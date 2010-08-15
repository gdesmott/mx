/*
 * mx-settings-none.c: Global settings (None backend)
 *
 * Copyright 2010 Intel Corporation.
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
 */

#include "mx-settings.h"

G_DEFINE_TYPE (MxSettings, mx_settings, MX_TYPE_SETTINGS_BASE)

#define SETTINGS_PRIVATE(o) \
  (G_TYPE_INSTANCE_GET_PRIVATE ((o), MX_TYPE_SETTINGS, MxSettingsPrivate))

enum
{
  PROP_0,

  PROP_ICON_THEME,
  PROP_FONT_NAME,
  PROP_LONG_PRESS_TIMEOUT,
  PROP_SMALL_SCREEN
};

struct _MxSettingsPrivate
{
  gchar *icon_theme;
  gchar *font_name;
  guint  long_press_timeout;
  guint  small_screen : 1;
};


static void
mx_settings_get_property (GObject    *object,
                               guint       property_id,
                               GValue     *value,
                               GParamSpec *pspec)
{
  MxSettingsPrivate *priv = MX_SETTINGS (object)->priv;

  switch (property_id)
    {
    case PROP_ICON_THEME:
      g_value_set_string (value, priv->icon_theme);
      break;

    case PROP_FONT_NAME:
      g_value_set_string (value, priv->font_name);
      break;

    case PROP_LONG_PRESS_TIMEOUT:
      g_value_set_uint (value, priv->long_press_timeout);
      break;

    case PROP_SMALL_SCREEN:
      g_value_set_boolean (value, priv->small_screen);
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    }
}

static void
mx_settings_set_property (GObject      *object,
                               guint         property_id,
                               const GValue *value,
                               GParamSpec   *pspec)
{
  MxSettingsPrivate *priv = MX_SETTINGS (object)->priv;

  switch (property_id)
    {
    case PROP_ICON_THEME:
      g_free (priv->icon_theme);
      priv->icon_theme = g_value_dup_string (value);
      break;

    case PROP_FONT_NAME:
      g_free (priv->font_name);
      priv->font_name = g_value_dup_string (value);
      break;

    case PROP_LONG_PRESS_TIMEOUT:
      priv->long_press_timeout = g_value_get_uint (value);
      break;

    case PROP_SMALL_SCREEN:
      priv->small_screen = g_value_get_boolean (value);
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    }
}

static void
mx_settings_finalize (GObject *object)
{
  MxSettingsPrivate *priv = MX_SETTINGS (object)->priv;

  g_free (priv->icon_theme);
  g_free (priv->font_name);

  G_OBJECT_CLASS (mx_settings_parent_class)->finalize (object);
}

static void
mx_settings_class_init (MxSettingsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  g_type_class_add_private (klass, sizeof (MxSettingsPrivate));

  object_class->get_property = mx_settings_get_property;
  object_class->set_property = mx_settings_set_property;
  object_class->finalize = mx_settings_finalize;

  g_object_class_override_property (object_class,
                                    PROP_ICON_THEME,
                                    "icon-theme");
  g_object_class_override_property (object_class,
                                    PROP_FONT_NAME,
                                    "font-name");
  g_object_class_override_property (object_class,
                                    PROP_LONG_PRESS_TIMEOUT,
                                    "long-press-timeout");
  g_object_class_override_property (object_class,
                                    PROP_SMALL_SCREEN,
                                    "small-screen");
}

static void
mx_settings_init (MxSettings *self)
{
  self->priv = SETTINGS_PRIVATE (self);

  /* setup defaults */
  self->priv->long_press_timeout = 500;
  self->priv->icon_theme = g_strdup ("hicolor");
  self->priv->font_name = g_strdup ("Sans 10");
}

MxSettings *
mx_settings_get_default (void)
{
  return g_object_new (MX_TYPE_SETTINGS, NULL);
}
