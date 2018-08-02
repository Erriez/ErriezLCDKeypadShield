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
 * \file LCDKeypadShield.cpp
 * \brief LCD Keypad Shield library for Arduino
 * \details
 *      Source:         https://github.com/Erriez/ErriezLCDKeypadShield
 *      Documentation:  https://erriez.github.io/ErriezLCDKeypadShield
 */

#if (defined(__AVR__))
#include <avr/pgmspace.h>
#else
#include <pgmspace.h>
#endif

#include "LCDKeypadShield.h"

/*!
 * \brief Constructor LCDKeypadShield class
 * \details
 *      This initializes the built-in LiquidCrystal library in 4-bit mode:
 *      - RS, EN, D0, D1, D2 and D3 pins
 */
LCDKeypadShield::LCDKeypadShield() :
    LiquidCrystal(LCD_PIN_RS, LCD_PIN_EN, 
                  LCD_PIN_D0, LCD_PIN_D1, LCD_PIN_D2, LCD_PIN_D3)
{
    // Initialize backlight pin
    pinMode(LCD_BACK_LIGHT_PIN, OUTPUT);

    // Turn backlight on
    backlightOn();

    // Initialize LCD
    begin(16, 2);
    setCursor(0, 0);
}

/*!
 * \brief Read buttons from one analog pin
 * \return LCDButton enum
 */
LCDButton LCDKeypadShield::getButtons()
{
    static LCDButton keyLast = ButtonNone;
    static unsigned long keyTimeLast = 0;
    int analogKey;
    LCDButton key;

    analogKey = analogRead(0);

    if ((millis() - keyTimeLast) < 100) {
        return keyLast;
    }

    keyTimeLast = millis();

    if (analogKey < 50) {
        key = ButtonRight;
    } else if (analogKey < 200) {
        key = ButtonUp;
    } else if (analogKey < 300) {
        key = ButtonDown;
    } else if (analogKey < 500) {
        key = ButtonLeft;
    } else if (analogKey < 700) {
        key = ButtonSelect;
    } else {
        key = ButtonNone;
    }

    if (key == keyLast) {
        return key;
    } else {
        keyLast = key;
        return ButtonNone;
    }
}

/*!
 * \brief Turn backlight LED on
 */
void LCDKeypadShield::backlightOn()
{
    digitalWrite(LCD_BACK_LIGHT_PIN, HIGH);
}

/*!
 * \brief Turn backlight LED off
 */
void LCDKeypadShield::backlightOff()
{
    digitalWrite(LCD_BACK_LIGHT_PIN, LOW);
}
