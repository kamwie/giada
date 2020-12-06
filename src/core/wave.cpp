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


#include <cassert>
#include "utils/fs.h"
#include "utils/log.h"
#include "utils/string.h"
#include "const.h"
#include "wave.h"


namespace giada {
namespace m 
{
Wave::Wave(ID id)
: id       (id),
  m_rate   (0),
  m_bits   (0),
  m_logical(false),
  m_edited (false) 
{
}


/* -------------------------------------------------------------------------- */


float* Wave::operator [](int offset) const
{
	return buffer[offset];
}


/* -------------------------------------------------------------------------- */


void Wave::alloc(int size, int channels, int rate, int bits, const std::string& path)
{
	buffer.alloc(size, channels);
	m_rate = rate;
	m_bits = bits;
	m_path = path;
}


/* -------------------------------------------------------------------------- */


std::string Wave::getBasename(bool ext) const
{
	return ext ? u::fs::basename(m_path) : u::fs::stripExt(u::fs::basename(m_path));
}


/* -------------------------------------------------------------------------- */


int Wave::getRate() const { return m_rate; }
int Wave::getChannels() const { return buffer.countChannels(); }
std::string Wave::getPath() const { return m_path; }
int Wave::getSize() const { return buffer.countFrames(); }
int Wave::getBits() const { return m_bits; }
bool Wave::isLogical() const { return m_logical; }
bool Wave::isEdited() const { return m_edited; }


/* -------------------------------------------------------------------------- */


int Wave::getDuration() const
{
	return buffer.countFrames() / m_rate;
}


/* -------------------------------------------------------------------------- */


std::string Wave::getExtension() const
{
	return u::fs::getExt(m_path);
}


/* -------------------------------------------------------------------------- */


float* Wave::getFrame(int f) const
{
	return buffer[f];
}


/* -------------------------------------------------------------------------- */


void Wave::setRate(int v)     { m_rate = v; }
void Wave::setLogical(bool l) { m_logical = l; }
void Wave::setEdited(bool e)  { m_edited = e; }


/* -------------------------------------------------------------------------- */


void Wave::setPath(const std::string& p, int wid) 
{ 
	if (wid == -1)
		m_path = p; 
	else 
		m_path = u::fs::stripExt(p) + "-" + std::to_string(wid) + u::fs::getExt(p);
}


/* -------------------------------------------------------------------------- */


void Wave::copyData(const float* data, int frames, int channels, int offset)
{
	buffer.copyData(data, frames, channels, offset);
}


void Wave::copyData(const AudioBuffer& b) { buffer.copyData(b); }
void Wave::addData(const AudioBuffer& b)  { buffer.addData(b); }


/* -------------------------------------------------------------------------- */


void Wave::moveData(AudioBuffer&& b)
{
	buffer = std::move(b);
}
}} // giada::m::
