# CoffeeBot

When you push the button, alerts that we are making coffee to Slack. Ten
minutes later, it says the coffee is done.

Installation / setup: follow [particle-cli instructions][particle-instructions]

particle-instructions: http://docs.particle.io/core/connect/#connecting-your-device-connect-over-usb

Also, you need to copy `env_vars.example.h` and change the constants to be where
the coffee server is located (see HTTP client information below).


## Other instructions

[Useful resource](https://github.com/spark/particle-cli)


### Compiling

You can compile the firmware with:

    particle compile .


### Flashing

Assuming your spark core is named `spark-coffee`, upload the compiled firmware
with:

    particle flash spark-coffee <firmware path>

I'd like to make a script to automate compiling and flashing.


### Serial monitor

To see the serial monitor in your terminal (useful for debugging):

    particle serial monitor    # lists some serial connections, can call by name
    particle serial monitor 1  # connect to the first serial connection


## HTTP client

See [HttpClient documentation](https://github.com/nmattisson/HttpClient).

I'm not doing posts in JSON because the Slack endpoint is over HTTPS and the
HttpClient library doesn't handle HTTPS requests at this point. Instead, we hit
an intermediate server where all of the posting logic lives.

To prevent random people from posting to our Slack channel and fooling us that
coffee is ready and thereby greatly disappointing us, we never put the locations
of our Slack endpoint or the intermediate server in source control (especially
since this will likely be open-sourced.)
