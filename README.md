# LCD Keypad Shield library for Arduino
[![Build Status](https://travis-ci.org/Erriez/ErriezLCDKeypadShield.svg?branch=master)](https://travis-ci.org/Erriez/ErriezLCDKeypadShield)

This is a LCD Keypad Shield library for Arduino which supports the following features:

* 2x16 LCD using ```LiquidCrystal.h```.
* 5 pushbuttons connected to analog pin A0.
* Button debouncing.
* Backlight control (on/off).

## Hardware
Any Arduino board, tested on Arduino UNO.

![LCD Keypad Shield](https://raw.githubusercontent.com/Erriez/ErriezLCDKeypadShield/master/extras/LCDKeypadShield_board.png)

## Example

Examples | Erriez LCDKeypadShield:

* [Demo](https://github.com/Erriez/ErriezLCDKeypadShield/blob/master/examples/Demo/Demo.ino)  

## Usage

**Initialization**

```c++
#include <Arduino.h>
#include <LCDKeypadShield.h>

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

## Library dependencies

- Arduino's build-in ```LiquidCrystal``` library.

## Documentation

- [Doxygen online HTML](https://Erriez.github.io/ErriezLCDKeypadShield/)
- [Doxygen PDF](https://github.com/Erriez/ErriezLCDKeypadShield/raw/master/docs/latex/refman.pdf)

## Library installation

Please refer to the [Wiki](https://github.com/Erriez/ErriezArduinoLibrariesAndSketches/wiki) page.