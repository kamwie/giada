/* -----------------------------------------------------------------------------
 *
 * Giada - Your Hardcore Loopmachine
 *
 * -----------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2020 Giovanni A. Zuliani | Monocasual
 *
 * This file is part of Giada - Your Hardcore Loopmachine.
 *
 * Giada - Your Hardcore Loopmachine is free software: you can
 * redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * Giada - Your Hardcore Loopmachine is distributed in the hope that it
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Giada - Your Hardcore Loopmachine. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------- */


#ifndef G_MODEL_TRAITS_H
#define G_MODEL_TRAITS_H


#include <type_traits>
#include "core/wave.h"
#include "core/plugins/plugin.h"
#include "core/channels/channel.h"


namespace giada {
namespace m {
namespace model
{
template <typename T> struct has_id : std::false_type {};
template <> struct has_id<Channel>  : std::true_type {};
template <> struct has_id<Wave>     : std::true_type {};
#ifdef WITH_VST
template <> struct has_id<Plugin>   : std::true_type {};
#endif
}}} // giada::m::model::


#endif
