/*
 * MIT License
 *
 * Copyright (c) 2018 Erriez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*!
 * \file
 *     LCDKeypadShield.h
 * \brief
 *     LCD Keypad Shield library for Arduino
 * \details
 *     Source: https://github.com/Erriez/ErriezLCDKeypadShield
 */

#ifndef LCD_KEYPAD_SHIELD_H__
#define LCD_KEYPAD_SHIELD_H__

#include <Arduino.h>
#include <LiquidCrystal.h>

// Hard-wired LCD pins in 4-bit mode:
#define LCD_PIN_RS          8
#define LCD_PIN_EN          9
#define LCD_PIN_D0          4
#define LCD_PIN_D1          5
#define LCD_PIN_D2          6
#define LCD_PIN_D3          7

// Backlight pin
#define LCD_BACK_LIGHT_PIN  10

typedef enum {
  ButtonNone = 0,
  ButtonRight = 1,
  ButtonUp = 2,
  ButtonDown = 3,
  ButtonLeft = 4,
  ButtonSelect = 5
} LCDButton;

/*!
 * \brief LCD Keypad Shield class
 */
class LCDKeypadShield : public LiquidCrystal
{
public:
  LCDKeypadShield();
  LCDButton getButtons();

  void backlightOn();
  void backlightOff();
};

#endif // LCD_KEYPAD_SHIELD_H__
