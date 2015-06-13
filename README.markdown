# CoffeeBot

Installation / setup: follow [particle-cli instructions][particle-instructions]

particle-instructions: http://docs.particle.io/core/connect/#connecting-your-device-connect-over-usb

## Other instructions

[Useful resource](https://github.com/spark/particle-cli)

Assuming your USB connected device is called `spark-coffee`, here are some
useful commands.

Compiling:

    particle compile coffee.ino

Flashing:

    particle flash spark-coffee coffee.ino

Get serial monitor (debugging):

    particle serial monitor
    # lists some serial connections
    particle serial monitor 1
    # connect to the first serial connection

## HTTP calls

See [HttpClient documentation](https://github.com/nmattisson/HttpClient).
