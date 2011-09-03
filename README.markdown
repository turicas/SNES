SNES for Arduino
================

Introduction
------------

This simple library just gets buttons' state information from a SNES controller.

The code was based on a function I've created for explaining how a SNES
controller works for a talk I (Álvaro Justen) gave at the
[Latino-american Free/Libre Software Conference - Latinoware](http://www.latinoware.org/),
in 2010.
There is a
[blog post about this function](http://blog.justen.eng.br/2010/12/controle-do-super-nintendo-snes-no.html)
(in Portuguese).


<div align="center">
    <img src="https://github.com/turicas/SNES/blob/images/images/SNES_controller.jpg?raw=true" alt="SNES controller" />
</div>


Usage
-----

For now, look at the pins' connections below and upload one example from the
Arduino IDE. Enjoy!


Pins' Connections
-----------------

When you call `SNES.begin()` you need to pass as parameters the pins you
connected the clock, strobe and data pins (in this order).

See the pins of the connector in the SNES controller below, connected to
whatever digital port you want and enjoy!


<div align="center">
    <img src"https://github.com/turicas/SNES/blob/images/images/SNES_pinout.png?raw=true" alt="SNES connector pinout" />
</div>


Why Not NESpad/SNESpad?
-----------------------

There is a library called [NESpad/SNESpad](http://code.google.com/p/nespad/),
but it does not work with my controller, so I've searched and found a [detailed
specification](http://www.gamesx.com/controldata/snesdat.htm) about how the
SNES controller sends data to the SNES console and implemented it.
