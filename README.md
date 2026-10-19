# Line Follower Robot

A simple line following robot I built with an Arduino Uno. It follows a black line on the floor using two IR sensors.

## What I used
- Arduino Uno
- L293D motor driver
- 2 IR sensors
- 2 DC motors
- 2 x 3.7V batteries in series, in a battery holder

## How it works
The two IR sensors sit on either side of the black line. On a straight line both sensors see white, so the robot goes forward.

When the line turns, the sensor on that side sees black. The motor on that side runs backward and the other runs forward, so the robot turns toward the line.

At first, I only stopped the inside motor during a turn. Running it in reverse instead made the turning radius smaller.

## Pins
- Left motor: 9, 7, 8
- Right motor: 10, 5, 4
- Left IR sensor: 3
- Right IR sensor: 6
