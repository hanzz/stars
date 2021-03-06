/**
 * Stars client
 *
 * Copyright (C) 2012, Jan Kaluza <hanzz.k@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */

#include "Button.h"
#include "Base/Surface.h"
#include "Widgets/Widget.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <sstream>
#include <iostream>
#include "math.h"

Button::Button(const std::string &name, int x, int y, int width, int height) : Widget(x, y, width, height) {
	m_name = name;
	m_clicked = false;
}

Button::~Button() {
}

void Button::render(Surface *screen) {
	screen->box(getX(), getY(), getW(), getH(), 255, 255, 255);
	screen->renderCenteredText(getX() + getW()/2, getY() + 1, m_name.c_str());
}

void Button::handleEvent(SDL_Event &event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		m_clicked = true;
	}
}

