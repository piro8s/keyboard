/* Copyright 2018 Eucalyn
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* 
 * Tap Dance Configurarions
 */
#undef  TAPPING_TERM
#define TAPPING_TERM 100
#define RETRO_TAPPING
#define PERMISSVE_HOLD
/* Tap Dance Setting */

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

// #define MASTER_RIGHT

/*
 * Mouse Keys Configuration
 */
#undef  MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0
#undef  MOUSEKEY_TIME_TO_MAX
// #define MOUSEKEY_TIME_TO_MAX 0
#define MOUSEKEY_TIME_TO_MAX 100
#undef  MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 0
#undef  MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 1
#undef  MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 50
#undef  MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0
#undef  MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 5
