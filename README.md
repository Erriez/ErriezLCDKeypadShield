# Erriez LCD Keypad Shield library for Arduino
[![Build Status](https://travis-ci.org/Erriez/ErriezLCDKeypadShield.svg?branch=master)](https://travis-ci.org/Erriez/ErriezLCDKeypadShield)

This is a LCD Keypad Shield library for Arduino which supports the following features:

* 2x16 LCD using ```LiquidCrystal.h```.
* 5 pushbuttons connected to analog pin A0.
* Button debouncing.
* Backlight control (on/off).


## Hardware
Any Arduino board, tested on Arduino UNO.

![LCD Keypad Shield](https://raw.githubusercontent.com/Erriez/ErriezLCDKeypadShield/master/extras/LCDKeypadShield_board.png)

### Pins

| 2x16 LCD pins | UNO/Leonardo/Mega2560 |
| ------------- | --------------------- |
| RS            | 8                     |
| EN            | 9                     |
| D0            | 4                     |
| D1            | 5                     |
| D2            | 6                     |
| D3            | 7                     |
| Backlight     | 10                    |

## Example

Arduion IDE | Examples | Erriez LCDKeypadShield:

* [LCDKeypadShield](https://github.com/Erriez/ErriezLCDKeypadShield/blob/master/examples/LCDKeypadShield/LCDKeypadShield.ino)


## Documentation

- [Online HTML](https://Erriez.github.io/ErriezLCDKeypadShield)
- [Download PDF](https://github.com/Erriez/ErriezLCDKeypadShield/raw/master/ErriezLCDKeypadShield.pdf)


## Usage

**Initialization**

```c++
#include <ErriezLCDKeypadShield.h>

LCDKeypadShield shield;
```

### Backlight control

**Backlight on**

```c++
shield.backlightOn();
```

**Backlight off**

```c++
shield.backlightOff();
```

### Display control 

All ```LCDKeypadShield.h``` functions can be used.

**Clear display**

```c++
shield.clear();
```

**Set cursor**

```c++
// First character first line
shield.setCursor(0, 0);

// First character second line
shield.setCursor(0, 1);

// Last character second line
shield.setCursor(15, 1);
```

**Print text**

```c++
shield.print(F("Push the buttons"));
```

### Button control

**Get buttons**

```c++
LCDButtons button = shield.getButtons();
// Returned button enum:
//   ButtonNone
//   ButtonRight
//   ButtonUp
//   ButtonDown
//   ButtonLeft
//   ButtonSelect
```

**Improve response**

The resistors may be different for each board to read the analog key value. To improve response, experiment by updating the analogKey values in: `src\ErriezLCDKeypadShield.cpp`:

```c++
if (analogKey < 50) { /* <= Incread/decrease value 50 */
    key = ButtonRight;
} else if (analogKey < 200) { /* <= Incread/decrease value 200 */
    key = ButtonUp;
} else if (analogKey < 350) { /* <= Incread/decrease value 350 */
    key = ButtonDown;
} else if (analogKey < 500) { /* <= Incread/decrease value 500 */
    key = ButtonLeft;
} else if (analogKey < 750) { /* <= Incread/decrease value 750 */
    key = ButtonSelect;
} else {
    key = ButtonNone;
}
```

## Library dependencies

- Arduino's build-in ```LiquidCrystal``` library.


## Library installation

Please refer to the [Wiki](https://github.com/Erriez/ErriezArduinoLibrariesAndSketches/wiki) page.


## Other Arduino Libraries and Sketches from Erriez

* [Erriez Libraries and Sketches](https://github.com/Erriez/ErriezArduinoLibrariesAndSketches)
