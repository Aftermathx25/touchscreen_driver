# touchscreen_driver
Touchscreen driver for 4 wire resistive touchscreen with touch sense and screen resolution mapping.
Program as a response outputs touch coordinates on console.

# touchscreen_mouse
Program based on the previous version of my code which just made it work as the mouse. 

There may be some adjustments needed for other platforms and touchscreen modules, which apply to both versions of code:

# Resolution setting

``` 
#define Xresolution 704
#define Yresolution 550
```
Needless to say that it's just a screen resolution of the devices you'd like to use a touchscreen with.

# Corrections setting

```
#define correctX 64
#define correctY 150
```
In some cases your ```rawX``` or ```rawY``` output may be off by couple of pixels, these consts are used for corrections.

# Resitance values setting

``` 
#define maxX 900
#define maxY 750 
```
All resistive touchscreens have their minimum and maximum resistance values, we can adjust that by utilizing these consts. 
Simplest way to measure them is to press on the furthest possible points of both vertical and horizontal touchscreen plane.

# Debounce time

```
delay(200);
```
Testing the touchscreen module with the oscilloscope proved that debouncing effect also appears on resistive touchscreen modules.
Last delay function (line 90 on touchscreen_driver.ino, line 105 on touchscreen_mouse.ino) is used to get rid of said effect.
