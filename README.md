# An Example Using Ceedling and CMock to Mock Embedded Hardware

This is the companion to my blog available here:
http://www.electronvector.com/blog/mocking-embedded-hardware-interfaces-with-ceedling-and-cmock

It provides an example for using Ceedling and CMock to generate mocks for embedded hardware. This lets us compile and run our tests independently on our host machine.

## Requirements

Rake is required for executing the tests. It's generally installed as a part of a Ruby installation.

## Running the Tests

Run the tests with: `rake test:all`

## Source

The source files are in the `src` folder. There is one module named `tempSensor` which implements an interface to an I2C temperature sensor. There is an i2c.h file which is used to generate mocks for the processor I2C hardware.

## Tests

The tempSensor module is tested with the `test/test_tempSensor.c` file.

## Vagrant 

The included Vagrantfile can be used to launch an environment capable of building the tests. To launch the environment, run: `vagrant up`.
Once the evironment has loaded, connect to it with: `vagrant ssh`.