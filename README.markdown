# CoffeeBot

When you push the button, alerts that we are making coffee to Slack. Ten
minutes later, it says the coffee is done.

Installation / setup: follow [particle-cli instructions][particle-instructions]

particle-instructions: http://docs.particle.io/core/connect/#connecting-your-device-connect-over-usb


## Other instructions

[Useful resource](https://github.com/spark/particle-cli)


### Compiling

You can compile the firmware with:

    particle compile .


### Flashing

Assuming your spark core is named `spark-coffee`, upload the compiled firmware
with:

    particle flash spark-coffee coffee.ino


### Serial monitor

To see the serial monitor in your terminal (useful for debugging):

    particle serial monitor
    # lists some serial connections
    particle serial monitor 1
    # connect to the first serial connection


## HTTP client

See [HttpClient documentation](https://github.com/nmattisson/HttpClient).
