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


#ifndef G_CHANNEL_MANAGER_H
#define G_CHANNEL_MANAGER_H


#include <memory>
#include "core/types.h"


namespace giada {
namespace m 
{
namespace conf
{
struct Conf;
}
namespace patch
{
struct Channel;
}
class  Channel;
struct ChannelState;
namespace channelManager
{
/* init
Initializes internal data. */
	
void init();

/* create (1)
Creates a new Channel from scratch. */

Channel create(ChannelType type, ID columnId, const conf::Conf& conf);

/* create (2)
Creates a new Channel given an existing one (i.e. clone). */

Channel create(const Channel& ch);

/* (de)serializeWave
Creates a new Channel given the patch raw data and vice versa. */

Channel deserializeChannel(const patch::Channel& c, int bufferSize);
const patch::Channel serializeChannel(const Channel& c);
}}} // giada::m::channelManager


#endif
