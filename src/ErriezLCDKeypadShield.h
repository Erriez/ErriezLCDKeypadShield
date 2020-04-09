/*
 * MIT License
 *
 * Copyright (c) 2018-2020 Erriez
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
 * \file ErriezLCDKeypadShield.h
 * \brief LCD Keypad Shield library for Arduino
 * \details
 *      Source:         https://github.com/Erriez/ErriezLCDKeypadShield
 *      Documentation:  https://erriez.github.io/ErriezLCDKeypadShield
 */

#ifndef ERRIEZ_LCD_KEYPAD_SHIELD_H_
#define ERRIEZ_LCD_KEYPAD_SHIELD_H_

#include <Arduino.h>
#include <LiquidCrystal.h>

#if !defined(ARDUINO_AVR_UNO) && \
    !defined(ARDUINO_AVR_LEONARDO) && \
    !defined(ARDUINO_AVR_MEGA2560)
#warning "The library ErriezLCDKeypadShield has not been tested with this MCU"
#endif

// Hard-wired LCD pins in 4-bit mode:
#define LCD_PIN_RS          8   //!< LCD RS pin
#define LCD_PIN_EN          9   //!< LCD EN pin
#define LCD_PIN_D0          4   //!< LCD D0 pin
#define LCD_PIN_D1          5   //!< LCD D1 pin
#define LCD_PIN_D2          6   //!< LCD D2 pin
#define LCD_PIN_D3          7   //!< LCD D3 pin

// Backlight pin
#define LCD_BACK_LIGHT_PIN  10  //!< LCD backlight pin

/*!
 * \brief LCD buttons
 */
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

#endif // ERRIEZ_LCD_KEYPAD_SHIELD_H_
